#ifndef _DUH_PTMOD_H_
#define _DUH_PTMOD_H_

#include "dumb.h"

int duh_read_playptmod( DUH *duh, const unsigned char *data, size_t size );

void *duh_get_playptmod_sigdata(DUH *duh);
void *duh_get_playptmod_sigrenderer(DUH_SIGRENDERER *sigrenderer);

DUH_SIGRENDERER * playptmod_start_at_order( DUH *duh, int startorder, int sample_rate );

#endif
