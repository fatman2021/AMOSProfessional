#ifndef WRAP_MPEGA_H
#define WRAP_MPEGA_H

#include <proto/exec.h>
#include <libraries/mpega.h>

#include "compiler.h"

#ifdef BUILD_POWERUP
#define PPCLVO_MPEGA_open 0
#define PPCLVO_MPEGA_close 1
#define PPCLVO_MPEGA_decode_frame 2
#define PPCLVO_MPEGA_seek 3
#define PPCLVO_MPEGA_time 4
#define PPCLVO_MPEGA_find_sync 5
#define PPCLVO_MPEGA_scale 6
#else
MPEGA_STREAM * LIBPPC WRAP_MPEGA_open(char *stream_name, MPEGA_CTRL *ctrl, APTR a4base);
void LIBPPC WRAP_MPEGA_close(MPEGA_STREAM *mpega_stream, APTR a4base);
LONG LIBPPC WRAP_MPEGA_decode_frame(MPEGA_STREAM *mpega_stream, WORD *pcm[MPEGA_MAX_CHANNELS], APTR a4base);
LONG LIBPPC WRAP_MPEGA_seek(MPEGA_STREAM *mpega_stream, ULONG ms_time_position, APTR a4base);
LONG LIBPPC WRAP_MPEGA_time(MPEGA_STREAM *mpega_stream, ULONG *ms_time_position);
LONG LIBPPC WRAP_MPEGA_find_sync(const UBYTE *buffer, LONG buffer_size);
LONG LIBPPC WRAP_MPEGA_scale(MPEGA_STREAM *mpega_stream, LONG scale_percent);
#endif

#endif
