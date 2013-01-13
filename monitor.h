#ifndef MONITOR_H
#define MONITOR_H

struct DUMB_IT_SIGDATA;
struct DUH_SIGRENDERER;

void monitor_start( DUMB_IT_SIGDATA *, DUH_SIGRENDERER *, const char *, bool playback );
void monitor_update( DUH_SIGRENDERER * );
void monitor_stop( const DUH_SIGRENDERER * );

#endif