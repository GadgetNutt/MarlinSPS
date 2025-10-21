#pragma once
#include "sps_eval.h"
namespace sps{struct Retimer{real vmax=150;real step_du(const Segment&s,real u,real dt){real du=0.005;real u2=u+du; if(u2>s.u1) u2=s.u1;auto p1=eval_pose(s,u);auto p2=eval_pose(s,u2);real dx=p2.p.x-p1.p.x,dy=p2.p.y-p1.p.y,dz=p2.p.z-p1.p.z;real ds=sqrt(dx*dx+dy*dy+dz*dz);real v=ds/(u2-u+1e-9);real dut=(vmax*dt)/(v+1e-9);return dut<1e-5?1e-5:dut;}};}
