// vfncvt.f.x.w vd, vs2, vm
VI_VFP_NCVT_INT_TO_FP(
  { vd = i16_to_f8_1(vs2); },       // BODY8_1
  { vd = i16_to_f8_2(vs2); },       // BODY8_2
  { vd = i32_to_f16(vs2); },        // BODY32
  { vd = i64_to_f32(vs2); },        // BODY64
  { require_extension(EXT_ZVFH); }, // CHECK32
  { require_extension('F'); },      // CHECK64
  int                               // sign
)
