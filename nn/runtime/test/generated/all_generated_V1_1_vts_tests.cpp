// DO NOT EDIT;
// Generated by ml/nn/runtime/test/specs/generate_vts_test.sh

namespace batch_to_space_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated batch_to_space_float_1 test
#include "examples/batch_to_space_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/batch_to_space_float_1.model.cpp"
} // namespace batch_to_space_float_1
TEST_F(NeuralnetworksHidlTest, batch_to_space_float_1) {
    generated_tests::Execute(device,
                             batch_to_space_float_1::createTestModel,
                             batch_to_space_float_1::is_ignored,
                             batch_to_space_float_1::examples);
}

namespace batch_to_space {
std::vector<MixedTypedExample> examples = {
// Generated batch_to_space test
#include "examples/batch_to_space.example.cpp"
};
// Generated model constructor
#include "vts_models/batch_to_space.model.cpp"
} // namespace batch_to_space
TEST_F(NeuralnetworksHidlTest, batch_to_space) {
    generated_tests::Execute(device,
                             batch_to_space::createTestModel,
                             batch_to_space::is_ignored,
                             batch_to_space::examples);
}

namespace batch_to_space_quant8_1 {
std::vector<MixedTypedExample> examples = {
// Generated batch_to_space_quant8_1 test
#include "examples/batch_to_space_quant8_1.example.cpp"
};
// Generated model constructor
#include "vts_models/batch_to_space_quant8_1.model.cpp"
} // namespace batch_to_space_quant8_1
TEST_F(NeuralnetworksHidlTest, batch_to_space_quant8_1) {
    generated_tests::Execute(device,
                             batch_to_space_quant8_1::createTestModel,
                             batch_to_space_quant8_1::is_ignored,
                             batch_to_space_quant8_1::examples);
}

namespace div {
std::vector<MixedTypedExample> examples = {
// Generated div test
#include "examples/div.example.cpp"
};
// Generated model constructor
#include "vts_models/div.model.cpp"
} // namespace div
TEST_F(NeuralnetworksHidlTest, div) {
    generated_tests::Execute(device,
                             div::createTestModel,
                             div::is_ignored,
                             div::examples);
}

namespace mean_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated mean_float_1 test
#include "examples/mean_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/mean_float_1.model.cpp"
} // namespace mean_float_1
TEST_F(NeuralnetworksHidlTest, mean_float_1) {
    generated_tests::Execute(device,
                             mean_float_1::createTestModel,
                             mean_float_1::is_ignored,
                             mean_float_1::examples);
}

namespace mean_float_2 {
std::vector<MixedTypedExample> examples = {
// Generated mean_float_2 test
#include "examples/mean_float_2.example.cpp"
};
// Generated model constructor
#include "vts_models/mean_float_2.model.cpp"
} // namespace mean_float_2
TEST_F(NeuralnetworksHidlTest, mean_float_2) {
    generated_tests::Execute(device,
                             mean_float_2::createTestModel,
                             mean_float_2::is_ignored,
                             mean_float_2::examples);
}

namespace mean {
std::vector<MixedTypedExample> examples = {
// Generated mean test
#include "examples/mean.example.cpp"
};
// Generated model constructor
#include "vts_models/mean.model.cpp"
} // namespace mean
TEST_F(NeuralnetworksHidlTest, mean) {
    generated_tests::Execute(device,
                             mean::createTestModel,
                             mean::is_ignored,
                             mean::examples);
}

namespace pad_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated pad_float_1 test
#include "examples/pad_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/pad_float_1.model.cpp"
} // namespace pad_float_1
TEST_F(NeuralnetworksHidlTest, pad_float_1) {
    generated_tests::Execute(device,
                             pad_float_1::createTestModel,
                             pad_float_1::is_ignored,
                             pad_float_1::examples);
}

namespace pad {
std::vector<MixedTypedExample> examples = {
// Generated pad test
#include "examples/pad.example.cpp"
};
// Generated model constructor
#include "vts_models/pad.model.cpp"
} // namespace pad
TEST_F(NeuralnetworksHidlTest, pad) {
    generated_tests::Execute(device,
                             pad::createTestModel,
                             pad::is_ignored,
                             pad::examples);
}

namespace space_to_batch_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch_float_1 test
#include "examples/space_to_batch_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch_float_1.model.cpp"
} // namespace space_to_batch_float_1
TEST_F(NeuralnetworksHidlTest, space_to_batch_float_1) {
    generated_tests::Execute(device,
                             space_to_batch_float_1::createTestModel,
                             space_to_batch_float_1::is_ignored,
                             space_to_batch_float_1::examples);
}

namespace space_to_batch_float_2 {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch_float_2 test
#include "examples/space_to_batch_float_2.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch_float_2.model.cpp"
} // namespace space_to_batch_float_2
TEST_F(NeuralnetworksHidlTest, space_to_batch_float_2) {
    generated_tests::Execute(device,
                             space_to_batch_float_2::createTestModel,
                             space_to_batch_float_2::is_ignored,
                             space_to_batch_float_2::examples);
}

namespace space_to_batch_float_3 {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch_float_3 test
#include "examples/space_to_batch_float_3.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch_float_3.model.cpp"
} // namespace space_to_batch_float_3
TEST_F(NeuralnetworksHidlTest, space_to_batch_float_3) {
    generated_tests::Execute(device,
                             space_to_batch_float_3::createTestModel,
                             space_to_batch_float_3::is_ignored,
                             space_to_batch_float_3::examples);
}

namespace space_to_batch {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch test
#include "examples/space_to_batch.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch.model.cpp"
} // namespace space_to_batch
TEST_F(NeuralnetworksHidlTest, space_to_batch) {
    generated_tests::Execute(device,
                             space_to_batch::createTestModel,
                             space_to_batch::is_ignored,
                             space_to_batch::examples);
}

namespace space_to_batch_quant8_1 {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch_quant8_1 test
#include "examples/space_to_batch_quant8_1.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch_quant8_1.model.cpp"
} // namespace space_to_batch_quant8_1
TEST_F(NeuralnetworksHidlTest, space_to_batch_quant8_1) {
    generated_tests::Execute(device,
                             space_to_batch_quant8_1::createTestModel,
                             space_to_batch_quant8_1::is_ignored,
                             space_to_batch_quant8_1::examples);
}

namespace space_to_batch_quant8_2 {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch_quant8_2 test
#include "examples/space_to_batch_quant8_2.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch_quant8_2.model.cpp"
} // namespace space_to_batch_quant8_2
TEST_F(NeuralnetworksHidlTest, space_to_batch_quant8_2) {
    generated_tests::Execute(device,
                             space_to_batch_quant8_2::createTestModel,
                             space_to_batch_quant8_2::is_ignored,
                             space_to_batch_quant8_2::examples);
}

namespace space_to_batch_quant8_3 {
std::vector<MixedTypedExample> examples = {
// Generated space_to_batch_quant8_3 test
#include "examples/space_to_batch_quant8_3.example.cpp"
};
// Generated model constructor
#include "vts_models/space_to_batch_quant8_3.model.cpp"
} // namespace space_to_batch_quant8_3
TEST_F(NeuralnetworksHidlTest, space_to_batch_quant8_3) {
    generated_tests::Execute(device,
                             space_to_batch_quant8_3::createTestModel,
                             space_to_batch_quant8_3::is_ignored,
                             space_to_batch_quant8_3::examples);
}

namespace squeeze_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated squeeze_float_1 test
#include "examples/squeeze_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/squeeze_float_1.model.cpp"
} // namespace squeeze_float_1
TEST_F(NeuralnetworksHidlTest, squeeze_float_1) {
    generated_tests::Execute(device,
                             squeeze_float_1::createTestModel,
                             squeeze_float_1::is_ignored,
                             squeeze_float_1::examples);
}

namespace squeeze {
std::vector<MixedTypedExample> examples = {
// Generated squeeze test
#include "examples/squeeze.example.cpp"
};
// Generated model constructor
#include "vts_models/squeeze.model.cpp"
} // namespace squeeze
TEST_F(NeuralnetworksHidlTest, squeeze) {
    generated_tests::Execute(device,
                             squeeze::createTestModel,
                             squeeze::is_ignored,
                             squeeze::examples);
}

namespace squeeze_quant8_1 {
std::vector<MixedTypedExample> examples = {
// Generated squeeze_quant8_1 test
#include "examples/squeeze_quant8_1.example.cpp"
};
// Generated model constructor
#include "vts_models/squeeze_quant8_1.model.cpp"
} // namespace squeeze_quant8_1
TEST_F(NeuralnetworksHidlTest, squeeze_quant8_1) {
    generated_tests::Execute(device,
                             squeeze_quant8_1::createTestModel,
                             squeeze_quant8_1::is_ignored,
                             squeeze_quant8_1::examples);
}

namespace strided_slice_float_10 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_10 test
#include "examples/strided_slice_float_10.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_10.model.cpp"
} // namespace strided_slice_float_10
TEST_F(NeuralnetworksHidlTest, strided_slice_float_10) {
    generated_tests::Execute(device,
                             strided_slice_float_10::createTestModel,
                             strided_slice_float_10::is_ignored,
                             strided_slice_float_10::examples);
}

namespace strided_slice_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_1 test
#include "examples/strided_slice_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_1.model.cpp"
} // namespace strided_slice_float_1
TEST_F(NeuralnetworksHidlTest, strided_slice_float_1) {
    generated_tests::Execute(device,
                             strided_slice_float_1::createTestModel,
                             strided_slice_float_1::is_ignored,
                             strided_slice_float_1::examples);
}

namespace strided_slice_float_2 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_2 test
#include "examples/strided_slice_float_2.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_2.model.cpp"
} // namespace strided_slice_float_2
TEST_F(NeuralnetworksHidlTest, strided_slice_float_2) {
    generated_tests::Execute(device,
                             strided_slice_float_2::createTestModel,
                             strided_slice_float_2::is_ignored,
                             strided_slice_float_2::examples);
}

namespace strided_slice_float_3 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_3 test
#include "examples/strided_slice_float_3.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_3.model.cpp"
} // namespace strided_slice_float_3
TEST_F(NeuralnetworksHidlTest, strided_slice_float_3) {
    generated_tests::Execute(device,
                             strided_slice_float_3::createTestModel,
                             strided_slice_float_3::is_ignored,
                             strided_slice_float_3::examples);
}

namespace strided_slice_float_4 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_4 test
#include "examples/strided_slice_float_4.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_4.model.cpp"
} // namespace strided_slice_float_4
TEST_F(NeuralnetworksHidlTest, strided_slice_float_4) {
    generated_tests::Execute(device,
                             strided_slice_float_4::createTestModel,
                             strided_slice_float_4::is_ignored,
                             strided_slice_float_4::examples);
}

namespace strided_slice_float_5 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_5 test
#include "examples/strided_slice_float_5.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_5.model.cpp"
} // namespace strided_slice_float_5
TEST_F(NeuralnetworksHidlTest, strided_slice_float_5) {
    generated_tests::Execute(device,
                             strided_slice_float_5::createTestModel,
                             strided_slice_float_5::is_ignored,
                             strided_slice_float_5::examples);
}

namespace strided_slice_float_6 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_6 test
#include "examples/strided_slice_float_6.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_6.model.cpp"
} // namespace strided_slice_float_6
TEST_F(NeuralnetworksHidlTest, strided_slice_float_6) {
    generated_tests::Execute(device,
                             strided_slice_float_6::createTestModel,
                             strided_slice_float_6::is_ignored,
                             strided_slice_float_6::examples);
}

namespace strided_slice_float_7 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_7 test
#include "examples/strided_slice_float_7.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_7.model.cpp"
} // namespace strided_slice_float_7
TEST_F(NeuralnetworksHidlTest, strided_slice_float_7) {
    generated_tests::Execute(device,
                             strided_slice_float_7::createTestModel,
                             strided_slice_float_7::is_ignored,
                             strided_slice_float_7::examples);
}

namespace strided_slice_float_8 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_8 test
#include "examples/strided_slice_float_8.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_8.model.cpp"
} // namespace strided_slice_float_8
TEST_F(NeuralnetworksHidlTest, strided_slice_float_8) {
    generated_tests::Execute(device,
                             strided_slice_float_8::createTestModel,
                             strided_slice_float_8::is_ignored,
                             strided_slice_float_8::examples);
}

namespace strided_slice_float_9 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_float_9 test
#include "examples/strided_slice_float_9.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_float_9.model.cpp"
} // namespace strided_slice_float_9
TEST_F(NeuralnetworksHidlTest, strided_slice_float_9) {
    generated_tests::Execute(device,
                             strided_slice_float_9::createTestModel,
                             strided_slice_float_9::is_ignored,
                             strided_slice_float_9::examples);
}

namespace strided_slice {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice test
#include "examples/strided_slice.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice.model.cpp"
} // namespace strided_slice
TEST_F(NeuralnetworksHidlTest, strided_slice) {
    generated_tests::Execute(device,
                             strided_slice::createTestModel,
                             strided_slice::is_ignored,
                             strided_slice::examples);
}

namespace strided_slice_qaunt8_10 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_qaunt8_10 test
#include "examples/strided_slice_qaunt8_10.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_qaunt8_10.model.cpp"
} // namespace strided_slice_qaunt8_10
TEST_F(NeuralnetworksHidlTest, strided_slice_qaunt8_10) {
    generated_tests::Execute(device,
                             strided_slice_qaunt8_10::createTestModel,
                             strided_slice_qaunt8_10::is_ignored,
                             strided_slice_qaunt8_10::examples);
}

namespace strided_slice_quant8_1 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_1 test
#include "examples/strided_slice_quant8_1.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_1.model.cpp"
} // namespace strided_slice_quant8_1
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_1) {
    generated_tests::Execute(device,
                             strided_slice_quant8_1::createTestModel,
                             strided_slice_quant8_1::is_ignored,
                             strided_slice_quant8_1::examples);
}

namespace strided_slice_quant8_2 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_2 test
#include "examples/strided_slice_quant8_2.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_2.model.cpp"
} // namespace strided_slice_quant8_2
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_2) {
    generated_tests::Execute(device,
                             strided_slice_quant8_2::createTestModel,
                             strided_slice_quant8_2::is_ignored,
                             strided_slice_quant8_2::examples);
}

namespace strided_slice_quant8_3 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_3 test
#include "examples/strided_slice_quant8_3.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_3.model.cpp"
} // namespace strided_slice_quant8_3
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_3) {
    generated_tests::Execute(device,
                             strided_slice_quant8_3::createTestModel,
                             strided_slice_quant8_3::is_ignored,
                             strided_slice_quant8_3::examples);
}

namespace strided_slice_quant8_4 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_4 test
#include "examples/strided_slice_quant8_4.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_4.model.cpp"
} // namespace strided_slice_quant8_4
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_4) {
    generated_tests::Execute(device,
                             strided_slice_quant8_4::createTestModel,
                             strided_slice_quant8_4::is_ignored,
                             strided_slice_quant8_4::examples);
}

namespace strided_slice_quant8_5 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_5 test
#include "examples/strided_slice_quant8_5.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_5.model.cpp"
} // namespace strided_slice_quant8_5
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_5) {
    generated_tests::Execute(device,
                             strided_slice_quant8_5::createTestModel,
                             strided_slice_quant8_5::is_ignored,
                             strided_slice_quant8_5::examples);
}

namespace strided_slice_quant8_6 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_6 test
#include "examples/strided_slice_quant8_6.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_6.model.cpp"
} // namespace strided_slice_quant8_6
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_6) {
    generated_tests::Execute(device,
                             strided_slice_quant8_6::createTestModel,
                             strided_slice_quant8_6::is_ignored,
                             strided_slice_quant8_6::examples);
}

namespace strided_slice_quant8_7 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_7 test
#include "examples/strided_slice_quant8_7.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_7.model.cpp"
} // namespace strided_slice_quant8_7
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_7) {
    generated_tests::Execute(device,
                             strided_slice_quant8_7::createTestModel,
                             strided_slice_quant8_7::is_ignored,
                             strided_slice_quant8_7::examples);
}

namespace strided_slice_quant8_8 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_8 test
#include "examples/strided_slice_quant8_8.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_8.model.cpp"
} // namespace strided_slice_quant8_8
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_8) {
    generated_tests::Execute(device,
                             strided_slice_quant8_8::createTestModel,
                             strided_slice_quant8_8::is_ignored,
                             strided_slice_quant8_8::examples);
}

namespace strided_slice_quant8_9 {
std::vector<MixedTypedExample> examples = {
// Generated strided_slice_quant8_9 test
#include "examples/strided_slice_quant8_9.example.cpp"
};
// Generated model constructor
#include "vts_models/strided_slice_quant8_9.model.cpp"
} // namespace strided_slice_quant8_9
TEST_F(NeuralnetworksHidlTest, strided_slice_quant8_9) {
    generated_tests::Execute(device,
                             strided_slice_quant8_9::createTestModel,
                             strided_slice_quant8_9::is_ignored,
                             strided_slice_quant8_9::examples);
}

namespace sub {
std::vector<MixedTypedExample> examples = {
// Generated sub test
#include "examples/sub.example.cpp"
};
// Generated model constructor
#include "vts_models/sub.model.cpp"
} // namespace sub
TEST_F(NeuralnetworksHidlTest, sub) {
    generated_tests::Execute(device,
                             sub::createTestModel,
                             sub::is_ignored,
                             sub::examples);
}

namespace transpose_float_1 {
std::vector<MixedTypedExample> examples = {
// Generated transpose_float_1 test
#include "examples/transpose_float_1.example.cpp"
};
// Generated model constructor
#include "vts_models/transpose_float_1.model.cpp"
} // namespace transpose_float_1
TEST_F(NeuralnetworksHidlTest, transpose_float_1) {
    generated_tests::Execute(device,
                             transpose_float_1::createTestModel,
                             transpose_float_1::is_ignored,
                             transpose_float_1::examples);
}

namespace transpose {
std::vector<MixedTypedExample> examples = {
// Generated transpose test
#include "examples/transpose.example.cpp"
};
// Generated model constructor
#include "vts_models/transpose.model.cpp"
} // namespace transpose
TEST_F(NeuralnetworksHidlTest, transpose) {
    generated_tests::Execute(device,
                             transpose::createTestModel,
                             transpose::is_ignored,
                             transpose::examples);
}

namespace transpose_quant8_1 {
std::vector<MixedTypedExample> examples = {
// Generated transpose_quant8_1 test
#include "examples/transpose_quant8_1.example.cpp"
};
// Generated model constructor
#include "vts_models/transpose_quant8_1.model.cpp"
} // namespace transpose_quant8_1
TEST_F(NeuralnetworksHidlTest, transpose_quant8_1) {
    generated_tests::Execute(device,
                             transpose_quant8_1::createTestModel,
                             transpose_quant8_1::is_ignored,
                             transpose_quant8_1::examples);
}