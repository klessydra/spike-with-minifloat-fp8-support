// vfclass.v vd, vs2, vm
VI_VFP_V_LOOP
({
  vd = f8_1_rsqrte7(vs2);
},
{
  vd = f8_2_rsqrte7(vs2);
},
{
  vd = f16_rsqrte7(vs2);
},
{
  vd = f32_rsqrte7(vs2);
},
{
  vd = f64_rsqrte7(vs2);
})
