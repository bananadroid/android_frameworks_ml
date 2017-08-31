/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FRAMEWORKS_ML_NN_SVDF_H
#define FRAMEWORKS_ML_NN_SVDF_H

#include "Operations.h"

#include <algorithm>
#include <cmath>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_0 {
struct Operation;
}
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android

namespace android {
namespace nn {

struct SVDFParams {
    int rank_;
    ActivationFn activation_;
};

struct RunTimeOperandInfo;

class SVDF {
public:
    SVDF(const android::hardware::neuralnetworks::V1_0::Operation &operation,
         std::vector<RunTimeOperandInfo>& operands);

    bool Eval();

    static constexpr int kInputTensor = 0;
    static constexpr int kWeightsFeatureTensor = 1;
    static constexpr int kWeightsTimeTensor = 2;
    static constexpr int kBiasTensor = 3;

    static constexpr int kRankParam = 4;
    static constexpr int kActivationParam = 5;

    static constexpr int kStateTensor = 0;
    static constexpr int kOutputTensor = 1;

private:
    SVDFParams params_;

    const RunTimeOperandInfo *input_;
    const RunTimeOperandInfo *weights_feature_;
    const RunTimeOperandInfo *weights_time_;
    RunTimeOperandInfo *state_;
    RunTimeOperandInfo *output_;

    const RunTimeOperandInfo *bias_;
};

}  // namespace nn
}  // namespace android

#endif