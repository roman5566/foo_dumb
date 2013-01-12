#include <intrin.h>
#include <math.h>
#include <xmmintrin.h>

#include "dumb.h"

extern "C" {
#include "internal/it.h"
}

#ifdef _M_IX86
enum {
	CPU_HAVE_3DNOW		= 1 << 0,
	CPU_HAVE_3DNOW_EX	= 1 << 1,
	CPU_HAVE_SSE		= 1 << 2,
	CPU_HAVE_SSE2		= 1 << 3,
	CPU_HAVE_SSE3		= 1 << 4,
};

static bool query_cpu_feature_set(/*unsigned p_value*/) {
	__try {
		/*if (p_value & (CPU_HAVE_SSE | CPU_HAVE_SSE2 | CPU_HAVE_SSE2))*/ {
			int buffer[4];
			__cpuid(buffer,1);
			/*if (p_value & CPU_HAVE_SSE)*/ {
				if ((buffer[3]&(1<<25)) == 0) return false;
			}
			/*if (p_value & CPU_HAVE_SSE2) {
				if ((buffer[3]&(1<<26)) == 0) return false;
			}
			if (p_value & CPU_HAVE_SSE3) {
				if ((buffer[2]&(1<<0)) == 0) return false;
			}*/
		}

#ifdef _M_IX86
		/*if (p_value & (CPU_HAVE_3DNOW_EX | CPU_HAVE_3DNOW)) {
			int buffer_amd[4];
			__cpuid(buffer_amd,0x80000000);
			if ((unsigned)buffer_amd[0] < 0x80000001) return false;
			__cpuid(buffer_amd,0x80000001);
			
			if (p_value & CPU_HAVE_3DNOW) {
				if ((buffer_amd[3]&(1<<22)) == 0) return false;
			}
			if (p_value & CPU_HAVE_3DNOW_EX) {
				if ((buffer_amd[3]&(1<<30)) == 0) return false;
			}
		}*/
#endif
		return true;
	} __except(1) {
		return false;
	}
}

static const bool g_have_sse = query_cpu_feature_set(/*CPU_HAVE_SSE*/);
#elif defined(_M_X64)

enum {g_have_sse2 = true, g_have_sse = true, g_have_3dnow = false};

#else

enum {g_have_sse2 = false, g_have_sse = false, g_have_3dnow = false};

#endif

extern "C" { extern int _dumb_it_use_sse; }

void init_sse()
{
	_dumb_it_use_sse = g_have_sse;
}
