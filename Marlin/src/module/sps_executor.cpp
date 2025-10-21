#include "sps/sps_config.h"
#ifdef SPS_INPUT
#include "sps/sps_eval.h"
#include "sps/sps_retimer.h"
#include "sps/sps_ik.h"
#include "sps/sps_ringbuf.h"
#include "sps/sps_process.h"
namespace sps{extern RingBuf<Segment,SPS_SEG_RING_CAP> g_segments;static IK3T2R ik;static Retimer rt;static Mat mat;extern "C" void planner_enqueue_joints(const float*,int,float,float);void sps_tick(float dt){static bool has=false;static Segment cur;static float u=0; if(!has){ if(!g_segments.pop(cur)) return; u=cur.u0; has=true; } float du=rt.step_du(cur,u,dt); u+=du; if(u>cur.u1){has=false;return;} auto pose=eval_pose(cur,u); JointState js; if(!ik.IK(pose,js)){has=false;return;} float Q=(float)eval3(cur.Qflow,u); float dE=(float)Q_to_E(Q,dt,mat); float feed=cur.v_path_max_mm_s>0?cur.v_path_max_mm_s:150.0f; planner_enqueue_joints((const float*)js.j,js.n,dE,feed);} }
#endif
