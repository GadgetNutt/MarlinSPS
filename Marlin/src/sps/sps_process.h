#pragma once
#include "sps_types.h"
namespace sps{struct Mat{real dia=1.75,scale=1.0;};inline real Q_to_E(real Q,real dt,const Mat&m){real area=3.141592653589793*(m.dia*0.5)*(m.dia*0.5);return (Q*dt)/(area+1e-12)*m.scale;}}
