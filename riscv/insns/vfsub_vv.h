// vfsub.vv vd, vs2, vs1
VI_VFP_VV_LOOP
({
  vd = f8_1_sub(vs2, vs1);
},
{
  vd = f8_2_sub(vs2, vs1);
},
{
  vd = f16_sub(vs2, vs1);
},
{
  vd = f32_sub(vs2, vs1);
},
{
  vd = f64_sub(vs2, vs1);
})
