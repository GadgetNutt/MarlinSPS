#pragma once
#include <stdint.h>
namespace sps{#if SPS_USE_DOUBLE
using real=double;#else
using real=float;#endif
struct Vec3{real x,y,z;};struct Quat{real w,x,y,z;};struct Poly5{real c[6];};struct Poly3{real c[4];};struct Pose{Vec3 p;Quat q;};struct Segment{real u0,u1;Poly5 px,py,pz;Quat q0,q1,qa,qb;Poly3 Qflow;real arc_length_mm;real v_path_max_mm_s;real ori_rate_max_rad_s;};}
