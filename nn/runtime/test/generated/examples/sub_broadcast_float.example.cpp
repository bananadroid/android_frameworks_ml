// clang-format off
// Generated file (from: sub_broadcast_float.mod.py). Do not edit
std::vector<MixedTypedExample> examples = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {{0, {1.0f, 2.0f}}, {1, {1.0f, 2.0f, 3.0f, 4.0f}}},
  // int -> INT32 map
  {},
  // int -> QUANT8_ASYMM map
  {}
},
//Output(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {{0, {0.0f, 0.0f, -2.0f, -2.0f}}},
  // int -> INT32 map
  {},
  // int -> QUANT8_ASYMM map
  {}
}
},
}, // End of an example
};

