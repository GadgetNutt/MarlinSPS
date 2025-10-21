#include "sps/sps_config.h"
#ifdef SPS_INPUT
#include "sps/sps_types.h"
#include "sps/sps_ringbuf.h"
namespace sps{RingBuf<Segment,SPS_SEG_RING_CAP> g_segments;}
#endif
