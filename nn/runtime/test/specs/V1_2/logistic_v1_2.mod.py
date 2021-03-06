#
# Copyright (C) 2019 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

import math

# TEST 1
i1 = Input("op1", "TENSOR_FLOAT16", "{1, 2, 2, 1}")
i3 = Output("op3", "TENSOR_FLOAT16", "{1, 2, 2, 1}")
model = Model().Operation("LOGISTIC", i1).To(i3)

# Example 1. Input in operand 0,
input0 = {i1: # input 0
          [1.0, 2.0, 4.0, 8.0]}

output0 = {i3: # output 0
           [0.73105859756469727,
            0.88079702854156494,
            0.9820137619972229,
            0.99966466426849365]}

# Instantiate an example
Example((input0, output0))


# TEST 2
d0 = 2
d1 = 32
d2 = 40
d3 = 2

i0 = Input("input", "TENSOR_FLOAT16", "{%d, %d, %d, %d}" % (d0, d1, d2, d3))
output = Output("output", "TENSOR_FLOAT16", "{%d, %d, %d, %d}" % (d0, d1, d2, d3))
model = Model().Operation("LOGISTIC", i0).To(output)

# Example 1. Input in operand 0,
rng = d0 * d1 * d2 * d3
input_values = (lambda r = rng: [x * (x % 2 - .5) * 2 % 512 for x in range(r)])()
input0 = {i0: input_values}
output_values = [1. / (1. + math.exp(-x)) for x in input_values]
output0 = {output: output_values}

# Instantiate an example
Example((input0, output0))


# TEST 3: zero-sized input

# Use BOX_WITH_NMS_LIMIT op to generate a zero-sized internal tensor for box cooridnates.
p1 = Parameter("scores", "TENSOR_FLOAT32", "{1, 2}", [0.90, 0.10]) # scores
p2 = Parameter("roi", "TENSOR_FLOAT32", "{1, 8}", [1, 1, 10, 10, 0, 0, 10, 10]) # roi
o1 = Output("scoresOut", "TENSOR_FLOAT32", "{0}") # scores out
o2 = Output("classesOut", "TENSOR_INT32", "{0}") # classes out
tmp1 = Internal("roiOut", "TENSOR_FLOAT32", "{0, 4}") # roi out
tmp2 = Internal("batchSplitOut", "TENSOR_INT32", "{0}") # batch split out
model = Model("zero_sized").Operation("BOX_WITH_NMS_LIMIT", p1, p2, [0], 0.3,  -1, 0, 0.4, 1.0, 0.3).To(o1, tmp1, o2, tmp2)

# Use ROI_ALIGN op to convert into zero-sized feature map.
layout = BoolScalar("layout", False) # NHWC
i1 = Input("in", "TENSOR_FLOAT32", "{1, 1, 1, 1}")
zero_sized = Internal("featureMap", "TENSOR_FLOAT32", "{0, 2, 2, 1}")
model = model.Operation("ROI_ALIGN", i1, tmp1, tmp2, 2, 2, 2.0, 2.0, 4, 4, layout).To(zero_sized)

# LOGISTIC op with numBatches = 0.
o3 = Output("out", "TENSOR_FLOAT32", "{0, 2, 2, 1}") # out
model = model.Operation("LOGISTIC", zero_sized).To(o3)

quant8 = DataTypeConverter().Identify({
    p1: ("TENSOR_QUANT8_ASYMM", 0.1, 128),
    p2: ("TENSOR_QUANT16_ASYMM", 0.125, 0),
    o1: ("TENSOR_QUANT8_ASYMM", 0.1, 128),
    tmp1: ("TENSOR_QUANT16_ASYMM", 0.125, 0),
    i1: ("TENSOR_QUANT8_ASYMM", 0.1, 128),
    zero_sized: ("TENSOR_QUANT8_ASYMM", 0.1, 128),
    o3: ("TENSOR_QUANT8_ASYMM", 1.0 / 256, 0)
})

Example({
    i1: [1],
    o1: [],
    o2: [],
    o3: [],
}).AddVariations("relaxed", quant8, "float16")
