#define MYVERSION "0.9.7.5"

/*
	changelog

2006-06-03 02:13 UTC - kode54
- Implemented ASYLUM Music Format support.

2006-06-02 22:06 UTC - kode54
- Fixed finite looping for speed 0 and global volume 0 triggers.
- Reset loop count when seeking backwards.

2006-06-02 21:20 UTC - kode54
- IT renderer now supports pattern jump and break to row on the same row.
  (coffee-blues 3.mod)
- Version is now 0.9.7.5

2006-06-02 20:25 UTC - kode54
- Empty pattern scanner now returns the correct value for completely empty
  pattern structures, and also checks for lists of empty rows.

2006-06-01 00:47 UTC - kode54
- STM reader reads effects properly now.

2006-05-31 23:15 UTC - kode54
- Implemented STM support.
- Version is now 0.9.7.4

2006-05-31 20:12 UTC - kode54
- Finished implementing working fading support.

2006-05-31 19:09 UTC - kode54
- Implemented fading support.

2006-05-31 18:31 UTC - kode54
- Removed context dialog from resources.

2006-05-30 03:57 UTC - kode54
- IT reader works around a broken file that has several of the instruments
  offset by two bytes from their indicated file offsets. Since the hack
  only checks for offset by two null bytes, it also assumes that the two
  bytes it can't read from the end are also zero. (bz_ult9.it)
- IT reader treats null instrument/sample/pattern offsets as empty items.
  (flight2.it, sherri.it)

2006-05-30 00:04 UTC - kode54
- XM reader now truncates instrument envelope lengths to 12, and performs
  some basic envelope loop checking, similar to Open ModPlug Tracker.
  (revive_nimnone.xm)

2006-05-27 22:40 UTC - kode54
- S3M reader defaults to maximum (128) global volume when the header value is
  either zero or greater than 64. (darkness2.s3m)

2006-05-23 00:06 UTC - kode54
- Changed module format load order priority to check all signatures before
  attempting MOD now, and then only 15 sample module for MOD/MDZ. This should
  hopefully cut back on problems with N formats renamed to MOD.
- Version is now 0.9.7.4

2006-05-22 21:44 UTC - kode54
- XM reader now supports up to 256 instruments, even though FT2 only
  supports up to 128. ModPlug Tracker again. (no_utndgs2.xm)
- g_open_module now supports other files misnamed as .MOD (hilse.mod .it)

2006-05-22 18:43 UTC - kode54
- XM reader now ignores when instrument header contains a sample header size
  of 0, when it should be 0x28. (neptune_*.xm)
- S3M reader was using the incorrect index into component for sample packing
  when reading sample data. Was using n, should have been m.

2006-05-22 17:26 UTC - kode54
- IT renderer may have a bug with its time_lost / loop handling. Switchover
  from sustain loop would compound time_lost onto itself for every note-off.
  I'm not sure if this crap is even doing the right thing, especially in the
  case of a sample with a sustain loop, but no main loop. Working around for
  now by zeroing time_lost after note-off. (hall8.it)
- S3M reader ignores effects outside of 1-25 range so nothing can hit
  internal effects which are XM or PTM only. (N4.S3M)
- IT reader now supports ModPlug Tracker extensions for up to 4000 samples
  and mapping them with instruments. (hallowe.it.it)
- XM reader now supports instrument vibrato 4, random. Yet another ModPlug
  extension. (hcw-st.xm)

2006-05-21 02:11 UTC - kode54
- S3M reader correctly reads all 24 bits of the sample memory segment
  offset, fixing at least one file with >1MB of sample data (d-t-x_x.s3m)
- XM reader stops reading instruments when it has at least one valid
  instrument and encounters an error, fixing at least one file with
  too high instrument count in the header (drx-chri.xm)
- IT reader ignores instrument header signatures, since there seem to
  be files with bad signatures on unused/filler instruments (dsouls.it)
- MOD reader can now be restricted to handling 31 sample files with
  legal/known signatures only, so frontend can fall back on restricted
  MOD loading for files with incorrect extensions (dreamer_0g.s3m)
- Version is now 0.9.7.2

2006-05-20 xx:xx UTC - kode54
- Modified silence skipping to hack around some "S L O W" effects crap
  and a misused break to row effect

2006-03-27 07:51 UTC - kode54
- Changed RIFF AMFF loader to ignore one unknown sample flag and
  be a little more flexible with the INST chunk handler
- Version is now 0.9.7.1

2005-11-07 05:00 UTC - kode54
- Added generic RIFF module handler and AM/AMFF format readers
- Added J2B unpacker
- Version is now 0.9.7

2005-10-13 09:02 UTC - kode54
- Implemented XM format v1.02 and v1.03 support
- Arpeggio fix for FastTracker 2 bug, I think

2005-06-04 00:59 UTC - kode54
- Implemented ADPCM4 in S3M reader
- Moved ADPCM4 unpacking code to its own function in itread.c, declared in internal/it.h
- Version is now 0.9.6.3

2005-06-01 00:23 UTC - kode54
- Added safety check to MOD ADPCM4 unpacking code, in case of odd lengths
- Implemented ADPCM4 in XM reader
- Implemented ADPCM4 in IT reader
- Version is now 0.9.6.2

2005-05-29 16:49 UTC - kode54
- Implemented support for modplug packed samples in MOD reader (meh)
- Version is now 0.9.6.1

2005-05-20 06:08 UTC - kode54
- UMX handler now ignores file type (SpaceMarines.umx, Starseek.umx report "s3m" but contain IT)
- UMX stops at the first matching resource (Kran32.umx, contains two Music entries for the same block of data)
- Version is now 0.9.6

2005-01-27 21:02 UTC - kode54
- Quick bug fix for Repeat One, seek() should be clearing eof flag
- Version is now 0.9.5.8

2005-01-17 16:25 UTC - kode54
- XM pattern loader is now more lenient with truncated pattern data
- Version is now 0.9.5.7

2005-01-12 20:19 UTC - kode54
- Added .mod/.mdz check to track indexer in case of MOD with "PSM " in song name :)
- Version is now 0.9.5.6

2005-01-12 19:11 UTC - kode54
- Fixed a bug in 669 loader
- Moved .mod/.mdz loading ahead of header checks, in case of song titles which trick one of the loader conditions

2004-10-29 02:47 UTC - kode54
- Touched up .mod sample truncation handling again
- Version is now 0.9.5.5

2004-10-21 06:02 UTC - kode54
- Fixed a division by zero case in dumb_resample, which resulted from a sample with zero C5 speed
- Version is now 0.9.5.4

2004-10-18 04:50 UTC - kode54
- Corrected 669 tempo and speed handling, although the tone portamento still seems to be a bit off
- Reenabled down ramping, always using 1/512s logarithmic decay
- Version is now 0.9.5.3

2004-10-17 06:25 UTC - kode54
- Disabled the down ramping code, as the old click remover seems to behave better in more places

2004-10-17 00:26 UTC - kode54
- Added file remaining hack to skip remaining but unused patterns in Iguana's demo MODs
- Modified MOD buffered reader and sample data loader to avoid unnecessary dumbfile calls when size of operation is zero
- Version is now 0.9.5.2

2004-10-16 23:22 UTC - kode54
- Changed sample truncation behavior in MOD and 669 to be consistent
- Added support for a couple of obscure MOD signatures used by some PC demo, just to support their delta samples natively
- Version is now 0.9.5.1

2004-10-16 19:44 UTC - kode54
- 669 loader is lenient with truncated sample data
- MTM reader is lenient with track numbers which are out of range
- Version is now 0.9.5

2004-10-16 18:50 UTC - kode54
- Overhauled volume ramping to an acceptable state
- Tweaked XM amiga vibrato a bit, should be more correct now

2004-10-14 21:58 UTC - kode54
- Set sample offset has memory even in MOD
- Version is now 0.9.4

2004-10-12 06:14 UTC - kode54
- Tweaked around with volume ramping crap some more. Still a mess, still nowhere near perfect. Bleh.
- Added per-sample resampling quality limits
- Added auto chip sample detection

2004-10-10 07:23 UTC - kode54
- Implemented volume change ramping as well... Holy shit, what a fucking mess.

2004-10-09 23:50 UTC - kode54
- Implemented volume ramping
- XM channel volume/envelopes/panning should not be reset when instrument change is paired with note-off

2004-10-06 22:08 UTC - kode54
- Fixed volume swing
- Fixed logarithmic vibrato so it only activates on XM w/ Amiga frequency table
- Version is now 0.9.3.6

2004-10-06 06:21 UTC - kode54
- Added NSMS signature for 4ch 31s module
- Changed MOD sample change behavior again, in a way that doesn't break Intro-Music.mod
- Version is now 0.9.3.5

2004-10-06 01:23 UTC - kode54
- Sample offset is no longer reapplied during pattern breaks
- Version is now 0.9.3.4

2004-10-05 23:57 UTC - kode54
- MOD/XM pattern break effect >63 breaks to row 0

2004-10-05 23:34 UTC - kode54
- Implemented FastTracker 2 logarithmic vibrato
- Implemented FastTracker 2 ramp up/down and square wave forms... Maybe it would be faster if I calculated that crap
  instead of using tables.

2004-10-05 19:38 UTC - kode54
- Implemented instrument random volume and panning variation, but maybe the offset should be a member of IT_CHANNEL
  instead of IT_PLAYING...

2004-10-05 19:03 UTC - kode54
- Panbrello position persists for the life of the voice, depth is the same, but is reset to zero
  if channel panning is changed

2004-10-05 18:49 UTC - kode54
- Fixed pitch-pan with negative separation level
- Changed instrument envelope control

2004-10-04 14:25 UTC - kode54
- Damn, glissando control was broken, couldn't turn it off
- Wow, hole in the MTM comment reader. It's still ugly, though.
- Version is now 0.9.3.3

2004-10-04 13:27 UTC - kode54
- Undid last NNA changes, the real problem was with NNA control effects carrying when they shouldn't
- Version is now 0.9.3.2

2004-10-04 11:09 UTC - kode54
- Fixed a possible bug with finetune, which should not be applied twice
- Implemented glissando
- Implemented PTM note slides, what a bitch, and just for two files!
- Version is now 0.9.3.1

2004-10-04 05:36 UTC - kode54
- Old PSM support
- MTM support
- MOD/XM S8x effect support, if it's supposed to be there
- Changed several readers to use stack buffers for dynamic strings, instead of malloc
- Fixed reading IT info from UMX archives. Whoops.
- Initialized counter variable properly in get_tracks() function. Whoops again.
- Removed length probe from dumb_read_it(). Jeez, what a slowdown even when not mixing and resampling...
- Version is now 0.9.3

2004-10-02 17:09 UTC - kode54
- Added dynamic speed, tempo, channels, and channels_max info
- Version is now 0.9.2.14

2004-10-02 16:49 UTC - kode54
- Added hack around XM speed zero to set its row played bit, for crap which scans it later outside of renderer...

2004-10-02 16:15 UTC - kode54
- Increased global volume silence check to 12 seconds
- Forced restart position to match start order, for a few annoying files, so they stop. Gee.

2004-10-02 15:04 UTC - kode54
- Meh, extended some NNA behavior so channel volume settings affect NNA voices correctly
- This appears to be the limit of channel effects on NNA voices, I hope

2004-10-02 14:28 UTC - kode54
- Added pattern delay/loop checking to pattern silence checker
- Silent pattern trimmer now trims only patterns which also contain delays/loops
- Trimmer also produces a single-row empty pattern instead of a 0-row pattern, which would hang
- Amended XM effect translation to support mod parameter, currently only affects Fxx speed effect

2004-10-01 16:20 UTC - kode54
- Added dynamic info junk
- Version is now 0.9.2.13

2004-10-01 15:50 UTC - kode54
- Fixed played bit setting on completing a pattern loop
- Removed insane level of loop bit checking because combined with the above breaks Jos-Dr4k.xm
- Fixed S3M sample length/loop fields for stereo/16-bit samples in files created by IMAGO Orpheus

2004-10-01 12:38 UTC - kode54
- Extended subsong scanner to check every row in each order

2004-09-30 14:39 UTC - kode54
- Removed most checkpoint list building for a speedup
- Added note off to silence allowance list
- Version is now 0.9.2.12.2

2004-09-29 18:10 UTC - kode54
- Removed ID3v1 from tag checks
- Blarg, bug fix in track_indexer for PSMs with APE tags, VC is retarded
- Version is now 0.9.2.12.1

2004-09-27 11:36 UTC - kode54
- Added configuration for subsong scanning
- Added finite looping options, will trigger either on global volume, speed zero, or just plain looping
- Fixed note portamento in the same row as note off
- Changed S3M reader to truncate loops that end past the length of the sample instead of disabling the loop
- Changed S3M reader to eliminate duplicate patterns which reference the same file offset
- Version is now 0.9.2.12

2004-09-27 08:21 UTC - kode54
- Extended PSM reader to support multiple subsongs
- Added a playable orders scanner
- Changed context menu system to indicate initial pattern or subsong depending on format

2004-09-22 22:13 UTC - kode54
- CRAP! My quick signature check broke PSM support
- Added extension check to MOD reader so no unknown types hit it
- Version is now 0.9.2.11.1

2004-09-22 01:41 UTC - kode54
- Changed S3M loader to ignore samples with zero length before checking for signature
- Added top-level signature checks for all formats other than MOD so invalid files don't become 15s MOD
- Version is now 0.9.2.11

2004-09-21 21:44 UTC - kode54
- Fixed MOD 8xx effect scale

2004-09-21 18:16 UTC - kode54
- Holy fucking shit, PSM support!
- Fixed instrument w/o note so it always resets 

2004-09-21 00:55 UTC - kode54
- Initialize sample variables to zero for MOD/XM files with retrigger commands before any actual note data
- Changed global volume cutoff to try the callback every 5 seconds of global silence
- Changed resampler to assume todo values less than zero are actually integer overflow, which works fine for
  portamento to really low pitch levels. It should never be negative anyway.
- Version is now 0.9.2.10.1

2004-09-19 15:31 UTC - kode54
- S3M reader now disposes of effects unsupported by Scream Tracker 3. Some people are just too l33t to
  use the effects column only for effects.
- Swapped PTM portamento effect directions. Whoever wrote PTMFORM.DOC must have been on drugs or something.
- Corrected MOD/S3M (PTM?) behavior when the sample is changed on a playing channel without a new note
- Version is now 0.9.2.10

2004-09-18 01:10 UTC - kode54
- Corrected speed change command so it only calls speed zero callback on XM files and not MOD files
- Version is now 0.9.2.9

2004-09-17 23:43 UTC - kode54
- Corrected finetune effect, allowed for future finetune tweaking

2004-09-17 20:57 UTC - kode54
- Fixed panbrello, now it really is correct
- Implemented finetune effect
- Fixed 669 effect 3, I think

2004-09-17 18:29 UTC - kode54
- Fixed song message handler in ReadDUH

2004-09-17 17:41 UTC - kode54
- Spoony 669 support

2004-09-17 10:45 UTC - kode54
- Implemented IT panbrello effect, hopefully

2004-09-17 09:18 UTC - kode54
- Implemented S3M Xxx panning bug for surround modes
- Added OKT extension, since it is handled by the MOD reader

2004-09-16 11:54 UTC - kode54
- Fixed S3M panning command. Others probably need proper translation as well.
- Version is now 0.9.2.8.2

2004-09-16 11:34 UTC - kode54
- Lovely, had to fix loop checking behavior when parsing through an empty pattern with no event list
- Fixed seek() to invoke open2() properly, whoops.

2004-09-16 09:46 UTC - kode54
- CRIKEY! Broke pattern loops on formats other than XM! Fixed now.
- Version is now 0.9.2.8.1

2004-09-16 06:26 UTC - kode54
- Changed pattern trimmer to report when there's nothing left after trimming
- BLAH! Fixed another reference to the global quality level in resample.inc
- Version is now 0.9.2.8

2004-09-16 04:52 UTC - kode54
- Really fixed stupid smart loop checking this time

2004-09-16 02:39 UTC - kode54
- Fixed some static veriable crap in IT compressed sample loaders
- Consolidated sigrenderer creation and configuration
- Previous loop checking could potentially leak memory
- Now compiled with ICL 8 for a decent speed boost

2004-09-15 20:46 UTC - kode54
- Added optional silence trimming

2004-09-15 20:41 UTC - kode54
- The loop checking is now more ludicrous, to fix some annoying modules
- Added a zero global volume callback for other annoying modules

2004-09-14 04:57 UTC - kode54
- Added change starting order context menu item
- Version is now 0.9.2.7

2004-09-14 01:56 UTC - kode54
- Fixed 16-bit samples clipping when resampling is set to aliasing
- Version is now 0.9.2.6

2004-09-13 23:17 UTC - kode54
- Fixed PTM note cut command (which behaves like XM)

2004-09-13 22:14 UTC - kode54
- Fixed loop end point for PTM files

2004-09-13 19:53 UTC - kode54
- Fixed sample offset effect for PTM files

2004-09-13 15:30 UTC - kode54
- Fixed an envelope carry related crash by changing the it_retrigger_note portion to handle it in a safer way
- Version is now 0.9.2.5

2004-09-13 15:10 UTC - kode54
- Almost complete PTM support

2004-09-13 09:26 UTC - kode54
- Fixed retriggering when sample finished playing within the retrigger interval, restricted to XM for now
- Version is now 0.9.2.4

2004-09-13 07:36 UTC - kode54
- Quick bugfix to envelope carry, shouldn't be messing with instruments table if not in IT instruments mode

2004-09-13 05:03 UTC - kode54
- Added support for envelope carry. I hope it's correct.
- Version is now 0.9.2.3

2004-09-12 02:51 UTC - kode54
- Added DUH FORMAT tag for all readers except for IT, and TRACKERVERSION for S3M

2004-09-12 02:27 UTC - kode54
- Fixed MOD channel count, wasn't being set properly in readmod.c

2004-09-12 02:16 UTC - kode54
- Fixed translation of XM panning slide effect after reversing IT panning slide

2004-09-11 23:35 UTC - kode54
- Implemented S3M mono/stereo control, but maybe I should also add a flag and disable panning
- Implemented IT vibrato/tremolo waveform control

2004-09-10 13:37 UTC - kode54
- Fixed resetting from surround to centered on panning slide/shift
- Clipped IT panning shift effect
- Version is now 0.9.2.2

2004-09-10 09:15 UTC - kode54
- Implemented IT S7x effect for NNA commands and per-note envelope toggles
- Implemented IT NNA duplicate note checks
- Corrected direction of panning slide effect
- Version is now 0.9.2.1

2004-09-10 03:57 UTC - kode54
- Fixed pattern break replaying with a bit array
- Fixed F0x-test.xm, sort of

2004-09-09 18:49 UTC - kode54
- Centralized info gathering for mod/s3m/xm

2004-09-08 00:57 UTC - kode54
- Fixed sample quality settings, and resetting settings/callbacks on backwards seeking

2004-09-06 16:23 UTC - kode54
- Changed default rate to 44100Hz, the "standard" default. Hell with AC'97

2004-09-06 13:11 UTC - kode54
- Transferred foo_mod codebase over and modified to use DUMB
- Modified DUMB slightly to allow for the as-yet unused start order functionality
- What a coincidence, the original latest version number was so similar to DUMB's
- Version is now 0.9.2

2004-06-15 18:51 UTC - kode54
- Should now retrieve basic module info even when a tag is present
- Version is now 0.92

2004-05-24 15:12 UTC - kode54
- No longer allows seeking past the end of the file
- Version is now 0.91

2004-03-14 00:00 UTC - kode54
- Now it will no longer accept zero-length files
- Version is now 0.90

2004-02-18 01:18 UTC - kode54
- Added detection for MO3, so it won't hit the MOD info loader
- Completed IT info loader
- Corrected IT info loader version information (BCD, not decimal)
- Version is now 0.89

2003-11-11 04:19 UTC - kode54
- Changed BASS_ERROR_FORMAT to new BASS_ERROR_FILEFORM
- Version is now 0.88a

2003-11-09 12:29 UTC - kode54
- Updated to BASS 2.0 final
- Version is now 0.88

2003-10-10 21:54 UTC - kode54
- Added sample/comment info parsing for MOD/S3M/MTM
- Version is now 0.87

2003-10-06 18:29 UTC - kode54
- Moved BASS_Free() call to global destructor
- Version is now 0.86g

2003-10-05 04:42 UTC - kode54
- Blah, forgot to set r to the new unpacking reader after unpacker::g_open()
- Version is now 0.86ffs

2003-10-02 19:25 UTC - kode54
- Forgot to fucking initialize played to 0. when not looping
- Version is now 0.86e

2003-10-01 17:32 UTC - kode54
- Even more console info!
- Version is now 0.86d

2003-10-01 16:14 UTC - kode54
- Added more error info
- Changed error handling on BASS_MusicGetLength()
- Version is now 0.86c

2003-10-01 14:02 UTC - kode54
- Changed critical section crap around BASS init stuff
- Changed extension check in 15/31 sample converter
- Inserted reader_disposer because there were several returns that didn't release bloody unpacking reader
- Version is now 0.86b

2003-09-21 14:18 UTC - kode54
- Looping is now disabled by default
- Single-play behavior amended to loop internally and cut playback at the detected length
- Version is now 0.86

2003-07-20 02:18 - kode54
- Amended seeking function
- Version is now 0.85

2003-06-28 08:04 - kode54
- Aww, fuck. Windows 2000 ignoring (lack of) integral height attribute on
  combo boxes, so the MOD playback box which was sized too small failed to
  open. Meh.
- Version is now 0.81

2003-06-26 07:02 - kode54
- Updated to 0.7 API
- Changed BASS version error string slightly
- Version is now 0.8

2003-04-30 10:36 - kode54
- Fixed lame bug with tag reading and compressed archives
- Added compressed module check to tag writer

2003-04-30 10:09 - kode54
- Added tag reading and optional writing
- Version is now 0.7

2003-04-22 08:44 - kode54
- Init BASS like normal, but don't shut it down until player closes.
  Unfortunately, this locks sample rate changes until the next startup.
- Version is now 0.666

2003-04-09 16:25 - kode54
- Added bitspersample info
- File name is no longer hard coded
- Changed about dialog string slightly
- Version is now 0.65

*/

#ifndef NDEBUG
#include <crtdbg.h>
#endif

#include "../SDK/foobar2000.h"
#include "../helpers/dropdown_helper.h"

#include "resource.h"
#include <stdio.h>
#include <commctrl.h>

#include "dumb.h"

extern "C" {
#include "internal/it.h"
}

#include "umr.h"

#include <zlib.h>
//#include <zutil.h>

// #define DBG(a) OutputDebugString(a)
#define DBG(a)

static const char * exts[]=
{
	// Original set copied from foo_mod, perhaps most frequently used types
	"MOD","MDZ",
	"S3M","S3Z",
	"STM","STZ",
	"IT","ITZ",
	"XM","XMZ",
	"PTM","PTZ",
	"MTM","MTZ",
	"669",
	"PSM",
	"UMX",
	"AM","J2B",
	"DSM",
	"AMF",
};

// {0E54B9FA-05DB-46b2-A3A4-C6C3201D57C0}
static const GUID guid_cfg_samplerate = 
{ 0xe54b9fa, 0x5db, 0x46b2, { 0xa3, 0xa4, 0xc6, 0xc3, 0x20, 0x1d, 0x57, 0xc0 } };
// {1DE1F6F7-CC39-460c-AD77-4BBABE54CA2B}
static const GUID guid_cfg_interp = 
{ 0x1de1f6f7, 0xcc39, 0x460c, { 0xad, 0x77, 0x4b, 0xba, 0xbe, 0x54, 0xca, 0x2b } };
// {4E0FBCA2-4A2B-4f65-9E50-C89C0255E851}
static const GUID guid_cfg_volramp = 
{ 0x4e0fbca2, 0x4a2b, 0x4f65, { 0x9e, 0x50, 0xc8, 0x9c, 0x2, 0x55, 0xe8, 0x51 } };
// {34FD0B9E-AD85-4958-B458-2B4C876EF4D3}
static const GUID guid_cfg_autochip = 
{ 0x34fd0b9e, 0xad85, 0x4958, { 0xb4, 0x58, 0x2b, 0x4c, 0x87, 0x6e, 0xf4, 0xd3 } };
// {39D973B2-4669-4747-8B21-EBF39E6A71EC}
static const GUID guid_cfg_autochip_size_force = 
{ 0x39d973b2, 0x4669, 0x4747, { 0x8b, 0x21, 0xeb, 0xf3, 0x9e, 0x6a, 0x71, 0xec } };
// {0937FFBF-03D5-4499-8223-4A680668A6FB}
static const GUID guid_cfg_autochip_size_scan = 
{ 0x937ffbf, 0x3d5, 0x4499, { 0x82, 0x23, 0x4a, 0x68, 0x6, 0x68, 0xa6, 0xfb } };
// {067B74F0-38B9-44c4-B517-8BD05B4E1B7F}
static const GUID guid_cfg_autochip_scan_threshold = 
{ 0x67b74f0, 0x38b9, 0x44c4, { 0xb5, 0x17, 0x8b, 0xd0, 0x5b, 0x4e, 0x1b, 0x7f } };
// {7C7EAEA1-ACFE-4f64-BDC7-5FF416273D3B}
static const GUID guid_cfg_loop = 
{ 0x7c7eaea1, 0xacfe, 0x4f64, { 0xbd, 0xc7, 0x5f, 0xf4, 0x16, 0x27, 0x3d, 0x3b } };
// {05916BA0-F8CE-4d84-BEAA-52A341FE82B7}
static const GUID guid_cfg_tag = 
{ 0x5916ba0, 0xf8ce, 0x4d84, { 0xbe, 0xaa, 0x52, 0xa3, 0x41, 0xfe, 0x82, 0xb7 } };
// {74D22B5A-E03C-48da-9A63-53323B8C23A5}
static const GUID guid_cfg_trim = 
{ 0x74d22b5a, 0xe03c, 0x48da, { 0x9a, 0x63, 0x53, 0x32, 0x3b, 0x8c, 0x23, 0xa5 } };
// {27D7CCC6-2FCC-4147-9284-4B99BC0C4A5D}
/*static const GUID guid_cfg_scan_subsongs = 
{ 0x27d7ccc6, 0x2fcc, 0x4147, { 0x92, 0x84, 0x4b, 0x99, 0xbc, 0xc, 0x4a, 0x5d } };*/
// {C70E9B32-2A88-43ea-B393-A3B4D644BE18}
static const GUID guid_cfg_dynamic_info = 
{ 0xc70e9b32, 0x2a88, 0x43ea, { 0xb3, 0x93, 0xa3, 0xb4, 0xd6, 0x44, 0xbe, 0x18 } };
// {44C7D5DE-A1E3-413e-945A-05BA9C8DECD9}
static const GUID guid_cfg_history_rate = 
{ 0x44c7d5de, 0xa1e3, 0x413e, { 0x94, 0x5a, 0x5, 0xba, 0x9c, 0x8d, 0xec, 0xd9 } };
// {7309341C-A28C-4b7e-85F3-EEF04BE93AF6}
static const GUID guid_cfg_fade = 
{ 0x7309341c, 0xa28c, 0x4b7e, { 0x85, 0xf3, 0xee, 0xf0, 0x4b, 0xe9, 0x3a, 0xf6 } };
// {43242592-6ED4-4983-968B-39B09DCC464D}
static const GUID guid_cfg_fade_time = 
{ 0x43242592, 0x6ed4, 0x4983, { 0x96, 0x8b, 0x39, 0xb0, 0x9d, 0xcc, 0x46, 0x4d } };


static cfg_int cfg_samplerate(guid_cfg_samplerate,44100);
static cfg_int cfg_interp(guid_cfg_interp,2);
static cfg_int cfg_fade(guid_cfg_fade,0);
static cfg_int cfg_fade_time(guid_cfg_fade_time,10000);
static cfg_int cfg_volramp(guid_cfg_volramp, 0);

static cfg_int cfg_autochip(guid_cfg_autochip, 0);
static cfg_int cfg_autochip_size_force(guid_cfg_autochip_size_force, 100);
static cfg_int cfg_autochip_size_scan(guid_cfg_autochip_size_scan, 500);
static cfg_int cfg_autochip_scan_threshold(guid_cfg_autochip_scan_threshold, 12);

static cfg_int cfg_loop(guid_cfg_loop,0);

static cfg_int cfg_tag(guid_cfg_tag, 0);

static cfg_int cfg_trim(guid_cfg_trim, 0);

/*static cfg_int cfg_scan_subsongs(guid_cfg_scan_subsongs, 0);*/

static cfg_int cfg_dynamic_info(guid_cfg_dynamic_info, 0);

extern "C" void init_cubic(void);

class init_stuff
{
public:
	init_stuff()
	{
		dumb_it_max_to_mix = DUMB_IT_TOTAL_CHANNELS;
		init_cubic();
#ifndef NDEBUG
		_CrtSetDbgFlag( _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG ) );
#endif
	}

	~init_stuff() {}
};

static init_stuff asdf;

//#pragma pack(push)
//#pragma pack(1)

static const char field_patterns[] = "mod_patterns";
static const char field_orders[] = "mod_orders";
static const char field_channels[] = "mod_channels";
static const char field_samples[] = "mod_samples";
static const char field_instruments[] = "mod_instruments";
static const char field_trackerver[] = "mod_ver_tracker";
static const char field_formatver[] = "mod_ver_format";
static const char field_sample[] = "smpl";
static const char field_instrument[] = "inst";
static const char field_pattern[] = "patt";
static const char field_channel[] = "chan";
static const char field_comment[] = "comment";
static const char field_title[] = "title";

static const char field_dyn_order[] = "mod_dyn_order";
static const char field_dyn_pattern[] = "mod_dyn_pattern";
static const char field_dyn_row[] = "mod_dyn_row";
static const char field_dyn_speed[] = "mod_dyn_speed";
static const char field_dyn_tempo[] = "mod_dyn_tempo";
static const char field_dyn_channels[] = "mod_dyn_channels";
static const char field_dyn_channels_max[] = "mod_dyn_channels_max";

/*
// 80 - FF only
static const unsigned short cp852_to_utf16[128] = {
	0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x016f, 0x0107, 0x00e7,
	0x0142, 0x00eb, 0x0150, 0x0151, 0x00ee, 0x0179, 0x00c4, 0x0106,
	0x00c9, 0x0139, 0x013a, 0x00f4, 0x00f6, 0x013d, 0x013e, 0x015a,
	0x015b, 0x00d6, 0x00dc, 0x0164, 0x0165, 0x0141, 0x00d7, 0x010d,
	0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x0104, 0x0105, 0x017d, 0x017e,
	0x0118, 0x0119, 0x00ac, 0x017a, 0x010c, 0x015f, 0x00ab, 0x00bb,
	0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00c1, 0x00c2, 0x011a,
	0x015e, 0x2563, 0x2551, 0x2557, 0x255d, 0x017b, 0x017c, 0x2510,
	0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x0102, 0x0103,
	0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x00a4,
	0x0111, 0x0110, 0x010e, 0x00cb, 0x010f, 0x0147, 0x00cd, 0x00ce,
	0x011b, 0x2518, 0x250c, 0x2588, 0x2584, 0x0162, 0x016e, 0x2580,
	0x00d3, 0x00df, 0x00d4, 0x0143, 0x0144, 0x0148, 0x0160, 0x0161,
	0x0154, 0x00da, 0x0155, 0x0170, 0x00fd, 0x00dd, 0x0163, 0x00b4,
	0x00ad, 0x02dd, 0x02db, 0x02c7, 0x02d8, 0x00a7, 0x00f7, 0x00b8,
	0x00b0, 0x00a8, 0x02d9, 0x0171, 0x0158, 0x0159, 0x25a0, 0x00a0
};

unsigned convert_oem_to_utf16(const char * src,WCHAR * dst,unsigned len)
{
	len = strlen_max(src,len);
	unsigned rv;
	for (rv = 0; rv < len; rv++)
	{
		if (!*src) break;
		if (*src > 0) *dst = *src;
		else *dst = cp852_to_utf16[*src + 128];
		src++;
		dst++;
	}
	*dst=0;
	return rv;
}
*/

static void ReadDUH(DUH * duh, file_info & info, bool meta, bool dos)
{
	if (!duh) return;

	DUMB_IT_SIGDATA * itsd = duh_get_it_sigdata(duh);

	if (!itsd) return;

	if (itsd->n_pchannels) info.info_set_int(field_channels, itsd->n_pchannels);
	if (itsd->n_patterns) info.info_set_int(field_patterns, itsd->n_patterns);
	if (itsd->n_orders) info.info_set_int(field_orders, itsd->n_orders);

	if (meta)
	{
		if (itsd->name[0])
		{
			if (dos) info.meta_add(field_title, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(char*)&itsd->name, sizeof(itsd->name)));
			else info.meta_add(field_title, pfc::stringcvt::string_utf8_from_ansi((char *)&itsd->name, sizeof(itsd->name)));
		}
		if (itsd->song_message && *itsd->song_message)
		{
			if (dos) info.meta_add(field_comment, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(char*)itsd->song_message));
			else info.meta_add(field_comment, pfc::stringcvt::string_utf8_from_ansi((char *)itsd->song_message));
		}
	}

	const char * tag = duh_get_tag(duh, "FORMAT");
	if (tag && *tag) info.info_set("codec", tag);
	tag = duh_get_tag(duh, "TRACKERVERSION");
	if (tag && *tag) info.info_set(field_trackerver, tag);
	tag = duh_get_tag(duh, "FORMATVERSION");
	if (tag && *tag) info.info_set(field_formatver, tag);

	int i, n;
	pfc::string8_fastalloc name;

	if (itsd->n_samples)
	{
		info.info_set_int(field_samples, itsd->n_samples);

		if (meta && itsd->sample)
		{
			for (i = 0, n = itsd->n_samples; i < n; i++)
			{
				if (itsd->sample[i].name[0])
				{
					name = field_sample;
					if (i < 10) name.add_byte('0');
					name << i;
					if (dos) info.meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(char*)&itsd->sample[i].name, sizeof(itsd->sample[i].name)));
					else info.meta_add(name, pfc::stringcvt::string_utf8_from_ansi((char *)&itsd->sample[i].name, sizeof(itsd->sample[i].name)));
				}
			}
		}
	}

	if (itsd->n_instruments)
	{
		info.info_set_int(field_instruments, itsd->n_instruments);

		if (meta && itsd->instrument)
		{
			for (i = 0, n = itsd->n_instruments; i < n; i++)
			{
				if (itsd->instrument[i].name[0])
				{
					name = field_instrument;
					if (i < 10) name.add_byte('0');
					name << i;
					if (dos) info.meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(char*)&itsd->instrument[i].name, sizeof(itsd->instrument[i].name)));
					else info.meta_add(name, pfc::stringcvt::string_utf8_from_ansi((char *)&itsd->instrument[i].name, sizeof(itsd->instrument[i].name)));
				}
			}
		}
	}
}

#pragma pack(push)
#pragma pack(1)

typedef struct tagITFILEHEADER
{
	t_uint32 id;			// 0x4D504D49
	char songname[26];
	t_uint16 reserved1;		// 0x1004
	t_uint16 ordnum;
	t_uint16 insnum;
	t_uint16 smpnum;
	t_uint16 patnum;
	t_uint16 cwtv;
	t_uint16 cmwt;
	t_uint16 flags;
	t_uint16 special;
	t_uint8 globalvol;
	t_uint8 mv;
	t_uint8 speed;
	t_uint8 tempo;
	t_uint8 sep;
	t_uint8 zero;
	t_uint16 msglength;
	t_uint32 msgoffset;
	t_uint32 reserved2;
	t_uint8 chnpan[64];
	t_uint8 chnvol[64];
} ITFILEHEADER, *PITFILEHEADER;

typedef struct MODMIDICFG
{
	char szMidiGlb[9*32];      // changed from CHAR
	char szMidiSFXExt[16*32];  // changed from CHAR
	char szMidiZXXExt[128*32]; // changed from CHAR
} MODMIDICFG, *LPMODMIDICFG;

#pragma pack(pop)

static bool ReadIT(const BYTE * ptr, unsigned size, file_info & info, bool meta)
{
	PITFILEHEADER pifh = (PITFILEHEADER) ptr;
	if ((!ptr) || (size < 0x100)) return false;
	if ((pfc::byteswap_if_be_t(pifh->id) != 0x4D504D49) ||
		(pfc::byteswap_if_be_t(pifh->insnum) >= 256) ||
		(!pifh->smpnum) || (pfc::byteswap_if_be_t(pifh->smpnum) > 4000) || // XXX
		(!pifh->ordnum)) return false;
	if (sizeof(ITFILEHEADER) + pfc::byteswap_if_be_t(pifh->ordnum) +
		pfc::byteswap_if_be_t(pifh->insnum)*4 +
		pfc::byteswap_if_be_t(pifh->smpnum)*4 +
		pfc::byteswap_if_be_t(pifh->patnum)*4 > size) return false;

	pfc::string8_fastalloc ver;

	ver = "IT v";
	ver << pfc::format_int( pfc::byteswap_if_be_t(pifh->cmwt) >> 8 );
	ver.add_byte('.');
	ver << pfc::format_int( pfc::byteswap_if_be_t(pifh->cmwt) & 255, 2, 16 );
	info.info_set( "codec", ver );

	ver = pfc::format_int( pfc::byteswap_if_be_t(pifh->cwtv) >> 8 );
	ver.add_byte('.');
	ver << pfc::format_int( pfc::byteswap_if_be_t(pifh->cwtv) & 255, 2, 16 );
	info.info_set( field_trackerver, ver );

	if ( pifh->smpnum ) info.info_set_int( field_samples, pfc::byteswap_if_be_t(pifh->smpnum) );
	if ( pifh->insnum ) info.info_set_int( field_instruments, pfc::byteswap_if_be_t(pifh->insnum) );

	if ( meta && pifh->songname[0] ) info.meta_add( field_title, pfc::stringcvt::string_utf8_from_codepage( CP_OEMCP,(char*)&pifh->songname, 26 ) );

	unsigned n, l, m_nChannels = 0;

	if ( meta && ( pfc::byteswap_if_be_t(pifh->special) & 1 ) && ( pifh->msglength ) && ( pfc::byteswap_if_be_t(pifh->msgoffset) + pfc::byteswap_if_be_t(pifh->msglength) < size ) )
	{
		pfc::string8 msg;
		const char * str = (const char *) ptr + pfc::byteswap_if_be_t(pifh->msgoffset);
		for (n = 0, l = pfc::byteswap_if_be_t(pifh->msglength); n < l; n++, str++)
		{
			if (*str == 13)
			{
				if ((n + 1 >= l) || (str[1] != 10))
				{
					msg.add_byte(13);
					msg.add_byte(10);
					continue;
				}
			}
			else if (*str == 10)
			{
				if ((!n) || (str[-1] != 13))
				{
					msg.add_byte(13);
					msg.add_byte(10);
					continue;
				}
			}
			msg.add_byte(*str);
		}
		info.meta_add( field_comment, pfc::stringcvt::string_utf8_from_codepage( CP_OEMCP, msg ) );
	}

	t_uint32 * offset;
	pfc::string8_fastalloc name;
	
	if (meta)
	{
		offset = (t_uint32 *)(ptr + 0xC0 + pfc::byteswap_if_be_t(pifh->ordnum) + pfc::byteswap_if_be_t(pifh->insnum) * 4);

		for (n = 0, l = pfc::byteswap_if_be_t(pifh->smpnum); n < l; n++, offset++)
		{
			t_uint32 offset_n = pfc::byteswap_if_be_t( *offset );
			if ((!offset_n) || (offset_n + 0x14 + 26 + 2 >= size)) continue;
			// XXX
			if (ptr[offset_n] == 0 && ptr[offset_n + 1] == 0 &&
				ptr[offset_n + 2] == 'I' && ptr[offset_n + 3] == 'M' &&
				ptr[offset_n + 4] == 'P' && ptr[offset_n + 5] == 'S')
			{
				offset_n += 2;
			}
			if (*(ptr + offset_n + 0x14))
			{
				name = field_sample;
				if (n < 10) name.add_byte('0');
				name << n;
				info.meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(const char *) ptr + offset_n + 0x14, 26));
			}
		}

		offset = (t_uint32 *)(ptr + 0xC0 + pfc::byteswap_if_be_t(pifh->ordnum));

		for (n = 0, l = pfc::byteswap_if_be_t(pifh->insnum); n < l; n++, offset++)
		{
			t_uint32 offset_n = pfc::byteswap_if_be_t( *offset );
			if ((!offset_n) || (offset_n + 0x20 + 26 >= size)) continue;
			if (*(ptr + offset_n + 0x20))
			{
				name = field_instrument;
				if (n < 10) name.add_byte('0');
				name << n;
				info.meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(const char *) ptr + offset_n + 0x20, 26));
			}
		}
	}

	unsigned pos = 0xC0 + pfc::byteswap_if_be_t(pifh->ordnum) + pfc::byteswap_if_be_t(pifh->insnum) * 4 + pfc::byteswap_if_be_t(pifh->smpnum) * 4 + pfc::byteswap_if_be_t(pifh->patnum) * 4;

	if (pos < size)
	{
		t_uint16 val16 = pfc::byteswap_if_be_t( *(t_uint16 *)(ptr + pos) );
		pos += 2;
		if (pos + val16 * 8 < size) pos += val16 * 8;
	}

	if (pfc::byteswap_if_be_t(pifh->flags) & 0x80)
	{
		if (pos + sizeof(MODMIDICFG) < size)
		{
			pos += sizeof(MODMIDICFG);
		}
	}

	if ((pos + 8 < size) && (pfc::byteswap_if_be_t(*(t_uint32 *)(ptr + pos)) == 0x4d414e50)) // "PNAM"
	{
		unsigned len = pfc::byteswap_if_be_t(*(t_uint32 *)(ptr + pos + 4));
		pos += 8;
		if ((pos + len <= size) && (len <= 240 * 32) && (len >= 32))
		{
			if (meta)
			{
				l = len / 32;
				for (n = 0; n < l; n++)
				{
					if (*(ptr + pos + n * 32))
					{
						name = field_pattern;
						if (n < 10) name.add_byte('0');
						name << n;
						info.meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(const char *) ptr + pos + n * 32, 32));
					}
				}
			}
			pos += len;
		}
	}

	if ((pos + 8 < size) && (pfc::byteswap_if_be_t(*(t_uint32 *)(ptr + pos)) == 0x4d414e43)) // "CNAM"
	{
		unsigned len = pfc::byteswap_if_be_t(*(t_uint32 *)(ptr + pos + 4));
		pos += 8;
		if ((pos + len <= size) && (len <= 64 * 20) && (len >= 20))
		{
			l = len / 20;
			m_nChannels = l;
			if (meta)
			{
				for (n = 0; n < l; n++)
				{
					if (*(ptr + pos + n * 20))
					{
						name = field_channel;
						if (n < 10) name.add_byte('0');
						name << n;
						info.meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,(const char *) ptr + pos + n * 20, 20));
					}
				}
			}
			pos += len;
		}
	}

	offset = (t_uint32 *)(ptr + 0xC0 + pfc::byteswap_if_be_t(pifh->ordnum) + pfc::byteswap_if_be_t(pifh->insnum) * 4 + pfc::byteswap_if_be_t(pifh->smpnum) * 4);

	BYTE chnmask[64];

	for (n = 0, l = pifh->patnum; n < l; n++)
	{
		memset(chnmask, 0, sizeof(chnmask));
		t_uint32 offset_n = pfc::byteswap_if_be_t( offset[n] );
		if ((!offset_n) || (offset_n + 4 >= size)) continue;
		unsigned len = pfc::byteswap_if_be_t(*(t_uint16 *)(ptr + offset_n));
		unsigned rows = pfc::byteswap_if_be_t(*(t_uint16 *)(ptr + offset_n + 2));
		if ((rows < 4) || (rows > 256)) continue;
		if (offset_n + 8 + len > size) continue;
		unsigned i = 0;
		const t_uint8 * p = ptr + offset_n + 8;
		unsigned nrow = 0;
		while (nrow < rows)
		{
			if (i >= len) break;
			t_uint8 b = p[i++];
			if (!b)
			{
				nrow++;
				continue;
			}
			unsigned ch = b & 0x7F;
			if (ch) ch = (ch - 1) & 0x3F;
			if (b & 0x80)
			{
				if (i >= len) break;
				chnmask[ch] = p[i++];
			}
			// Channel used
			if (chnmask[ch] & 0x0F)
			{
				if ((ch >= m_nChannels) && (ch < 64)) m_nChannels = ch+1;
			}
			// Note
			if (chnmask[ch] & 1) i++;
			// Instrument
			if (chnmask[ch] & 2) i++;
			// Volume
			if (chnmask[ch] & 4) i++;
			// Effect
			if (chnmask[ch] & 8) i += 2;
			if (i >= len) break;
		}
	}

	if (m_nChannels) info.info_set_int(field_channels, m_nChannels);
	if (pifh->patnum) info.info_set_int(field_patterns, pifh->patnum);
	if (pifh->ordnum) info.info_set_int(field_orders, pifh->ordnum);

	return true;
}

/*
#pragma pack(push)
#pragma pack(1)

typedef struct tagMTMSAMPLE
{
        char samplename[22];      // changed from CHAR
	DWORD length;
	DWORD reppos;
	DWORD repend;
	CHAR finetune;
	BYTE volume;
	BYTE attribute;
} MTMSAMPLE;


typedef struct tagMTMHEADER
{
	char id[4];	        // MTM file marker + version // changed from CHAR
	char songname[20];	// ASCIIZ songname  // changed from CHAR
	WORD numtracks;		// number of tracks saved
	BYTE lastpattern;	// last pattern number saved
	BYTE lastorder;		// last order number to play (songlength-1)
	WORD commentsize;	// length of comment field
	BYTE numsamples;	// number of samples saved
	BYTE attribute;		// attribute byte (unused)
	BYTE beatspertrack;
	BYTE numchannels;	// number of channels used
	BYTE panpos[32];	// voice pan positions
} MTMHEADER;

#pragma pack(pop)

static bool ReadMTM(const BYTE * ptr, unsigned size, file_info * info, bool meta)
{
	MTMHEADER *pmh = (MTMHEADER *)ptr;
	DWORD dwMemPos = 66;
	DWORD nSamples, nChannels;

	if ((!ptr) || (size < 0x100)) return false;
	if ((strncmp(pmh->id, "MTM", 3)) || (pmh->numchannels > 32)
	 || (pmh->numsamples >= 256) || (!pmh->numsamples)
	 || (!pmh->numtracks) || (!pmh->numchannels)
	 || (!pmh->lastpattern) || (pmh->lastpattern > 256)) return false;
	if (dwMemPos + 37*pmh->numsamples + 128 + 192*pmh->numtracks
	 + 64 * (pmh->lastpattern+1) + pmh->commentsize >= size) return false;
	nSamples = pmh->numsamples;
	nChannels = pmh->numchannels;
	// Reading instruments

	info->info_set("codec", "MTM");
	info->info_set_int(field_channels, nChannels);
	info->info_set_int(field_samples, nSamples);

	if (meta)
	{
		pfc::string8_fastalloc name;
		for	(UINT i=0; i<nSamples; i++)
		{
			MTMSAMPLE *pms = (MTMSAMPLE *)(ptr + dwMemPos);
			if (*pms->samplename)
			{
				name = field_sample;
				if (i < 10) name.add_byte('0');
				name.add_int(i);
				info->meta_add(name, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,pms->samplename, 22));
			}
			dwMemPos += 37;
		}
		dwMemPos += 128;
		dwMemPos += 192 * pmh->numtracks;
		dwMemPos += 64*(pmh->lastpattern+1);
		if ((pmh->commentsize) && (dwMemPos + pmh->commentsize < size))
		{
			name.reset();
			for (UINT i = pmh->commentsize / 40; i--;)
			{
				if (*(ptr + dwMemPos))
				{
					if (name.length())
					{
						name.add_byte(13);
						name.add_byte(10);
					}
					name.add_string((const char *) ptr + dwMemPos, 40);
				}
				dwMemPos += 40;
			}
			info->meta_add(field_comment, pfc::stringcvt::string_utf8_from_codepage(CP_OEMCP,name));
		}
	}

	return true;
}
*/

class umr_mem_reader : public umr::file_reader
{
	const t_uint8 * ptr;
	unsigned offset, size;
public:
	umr_mem_reader(const t_uint8 * buf, unsigned p_size) : ptr(buf), size(p_size), offset(0) {}

	long read( void * buf, long howmany )
	{
		unsigned max = size - offset;
		if ( max > howmany ) max = howmany;
		if ( max )
		{
			memcpy( buf, ptr + offset, max );
			offset += max;
		}
		return max;
	}

	void seek( long where )
	{
		if ( where > size ) offset = size;
		else offset = where;
	}
};

typedef struct tdumbfile_mem_status
{
	const t_uint8 * ptr;
	unsigned offset, size;
} dumbfile_mem_status;

static int dumbfile_mem_skip(void * f, long n)
{
	dumbfile_mem_status * s = (dumbfile_mem_status *) f;
	s->offset += n;
	if (s->offset > s->size)
	{
		s->offset = s->size;
		return 1;
	}

	return 0;
}

static int dumbfile_mem_getc(void * f)
{
	dumbfile_mem_status * s = (dumbfile_mem_status *) f;
	if (s->offset < s->size)
	{
		return *(s->ptr + s->offset++);
	}
	return -1;
}

static long dumbfile_mem_getnc(char * ptr, long n, void * f)
{
	dumbfile_mem_status * s = (dumbfile_mem_status *) f;
	long max = s->size - s->offset;
	if (max > n) max = n;
	if (max)
	{
		memcpy(ptr, s->ptr + s->offset, max);
		s->offset += max;
	}
	return max;
}

static DUMBFILE_SYSTEM mem_dfs = {
	NULL, // open
	&dumbfile_mem_skip,
	&dumbfile_mem_getc,
	&dumbfile_mem_getnc,
	NULL // close
};

struct DUMBFILE
{
	DUMBFILE_SYSTEM *dfs;
	void *file;
	long pos;
};

static bool g_test_extension(const char * ext)
{
	int n;
	for(n=0;n<tabsize(exts);n++)
	{
		if (!stricmp(ext,exts[n])) return true;
	}
	return false;
}

static DUH * g_open_module(const t_uint8 * & ptr, unsigned & size, const char * ext, int & start_order, bool & is_it, bool & is_dos)
{
	DUH * duh = 0;

	dumbfile_mem_status memdata;

	memdata.ptr = ptr;
	memdata.offset = 0;
	memdata.size = size;

	DUMBFILE * f = dumbfile_open_ex(&memdata, &mem_dfs);
	if ( ! f ) throw std::bad_alloc();

	is_it = false;
	is_dos = true;

	if (size >= 4 &&
		ptr[0] == 0xC1 && ptr[1] == 0x83 &&
		ptr[2] == 0x2A && ptr[3] == 0x9E)
	{
		umr_mem_reader memreader(ptr, size);
		umr::upkg pkg;
		if (pkg.open(&memreader))
		{
			for (int i = 1, j = pkg.ocount(); i <= j; i++)
			{
				char * classname = pkg.oclassname(i);
				if (classname && !strcmp(pkg.oclassname(i), "Music"))
				{
					char * type = pkg.otype(i);
					if (!type) continue;
					/*
					if (!stricmp(type, "it"))
					{
					is_it = true;
					ptr += memdata.offset = pkg.object_offset(i);
					size = memdata.size = memdata.offset + pkg.object_size(i);
					duh = dumb_read_it(f);
					break;
					}
					else if (!stricmp(type, "s3m"))
					{
					memdata.offset = pkg.object_offset(i);
					memdata.size = memdata.offset + pkg.object_size(i);
					duh = dumb_read_s3m(f);
					break;
					}
					else if (!stricmp(type, "xm"))
					{
					memdata.offset = pkg.object_offset(i);
					memdata.size = memdata.offset + pkg.object_size(i);
					duh = dumb_read_xm(f);
					break;
					}
					*/
					// blah, type can't be trusted
					if (!stricmp(type, "it") || !stricmp(type, "s3m") || !stricmp(type, "xm"))
					{
						ptr += memdata.offset = pkg.object_offset(i);
						size = memdata.size = memdata.offset + pkg.object_size(i);
						if (size >= 4 && ptr[0] == 'I' && ptr[1] == 'M' && ptr[2] == 'P' && ptr[3] == 'M')
						{
							is_it = true;
							duh = dumb_read_it(f);
						}
						else if (size >= 42 && ptr[38] == 'F' && ptr[39] == 'a' && ptr[40] == 's' && ptr[41] == 't')
						{
							duh = dumb_read_xm(f);
						}
						else if (size >= 48 && ptr[44] == 'S' && ptr[45] == 'C' && ptr[46] == 'R' && ptr[47] == 'M')
						{
							duh = dumb_read_s3m(f);
						}

						break;
					}
				}
			}
		}
	}
	else if (size >= 4 &&
		ptr[0] == 'I' && ptr[1] == 'M' &&
		ptr[2] == 'P' && ptr[3] == 'M')
	{
		is_it = true;
		duh = dumb_read_it(f);
	}
	else if (size >= 17 && !memcmp(ptr, "Extended Module: ", 17))
	{
		duh = dumb_read_xm(f);
	}
	else if (size >= 0x30 &&
		ptr[0x2C] == 'S' && ptr[0x2D] == 'C' &&
		ptr[0x2E] == 'R' && ptr[0x2F] == 'M')
	{
		duh = dumb_read_s3m(f);
	}
	else if (size >= 1168 &&
		ptr[28] == 0x1A && ptr[29] == 2 &&
		( ! strnicmp( ( const char * ) ptr + 20, "!Scream!", 8 ) ||
		! strnicmp( ( const char * ) ptr + 20, "BMOD2STM", 8 ) ||
		! strnicmp( ( const char * ) ptr + 20, "WUZAMOD!", 8 ) ) )
	{
		duh = dumb_read_stm(f);
	}
	else if (size >= 2 &&
		((ptr[0] == 0x69 && ptr[1] == 0x66) ||
		(ptr[0] == 0x4A && ptr[1] == 0x4E)))
	{
		duh = dumb_read_669(f);
	}
	else if (size >= 0x30 &&
		ptr[0x2C] == 'P' && ptr[0x2D] == 'T' &&
		ptr[0x2E] == 'M' && ptr[0x2F] == 'F')
	{
		duh = dumb_read_ptm(f);
	}
	else if (size >= 4 &&
		ptr[0] == 'P' && ptr[1] == 'S' &&
		ptr[2] == 'M' && ptr[3] == ' ')
	{
		duh = dumb_read_psm(f, start_order);
		start_order = 0;
	}
	else if (size >= 4 &&
		ptr[0] == 'P' && ptr[1] == 'S' &&
		ptr[2] == 'M' && ptr[3] == 254)
	{
		duh = dumb_read_old_psm(f);
	}
	else if (size >= 3 &&
		ptr[0] == 'M' && ptr[1] == 'T' &&
		ptr[2] == 'M')
	{
		duh = dumb_read_mtm(f);
	}
	else if ( size >= 4 &&
		ptr[0] == 'R' && ptr[1] == 'I' &&
		ptr[2] == 'F' && ptr[3] == 'F')
	{
		duh = dumb_read_riff(f);
	}
	else if ( size >= 32 &&
		!memcmp( ptr, "ASYLUM Music Format", 19 ) &&
		!memcmp( ptr + 19, " V1.0", 5 ) )
	{
		duh = dumb_read_asy(f);
	}

	if ( ! duh )
	{
		is_dos = false;
		duh = dumb_read_mod(f, ( ! stricmp( ext, exts[ 0 ] ) || ! stricmp( ext, exts[ 1 ] ) ) ? 0 : 1 );
	}

	dumbfile_close(f);

	if (duh && cfg_autochip)
	{
		int size_force = cfg_autochip_size_force;
		int size_scan = cfg_autochip_size_scan;
		int scan_threshold_8 = ((cfg_autochip_scan_threshold * 0x100) + 50) / 100;
		int scan_threshold_16 = ((cfg_autochip_scan_threshold * 0x10000) + 50) / 100;
		DUMB_IT_SIGDATA * itsd = duh_get_it_sigdata(duh);

		if (itsd)
		{
			for (int i = 0, j = itsd->n_samples; i < j; i++)
			{
				IT_SAMPLE * sample = &itsd->sample[i];
				if (sample->flags & IT_SAMPLE_EXISTS)
				{
					if (sample->length < size_force) sample->max_resampling_quality = 0;
					else if (sample->length < size_scan)
					{
						if ((sample->flags & (IT_SAMPLE_LOOP|IT_SAMPLE_PINGPONG_LOOP)) == IT_SAMPLE_LOOP)
						{
							int s1, s2;
							if (sample->flags & IT_SAMPLE_16BIT)
							{
								s1 = ((signed short *)sample->left)[sample->loop_start];
								s2 = ((signed short *)sample->left)[sample->loop_end-1];
								if (abs(s1 - s2) > scan_threshold_16)
								{
									sample->max_resampling_quality = 0;
									continue;
								}
								if (sample->flags & IT_SAMPLE_STEREO)
								{
									s1 = ((signed short *)sample->right)[sample->loop_start];
									s2 = ((signed short *)sample->right)[sample->loop_end-1];
									if (abs(s1 - s2) > scan_threshold_16)
									{
										sample->max_resampling_quality = 0;
										continue;
									}
								}
							}
							else
							{
								s1 = ((signed char *)sample->left)[sample->loop_start];
								s2 = ((signed char *)sample->left)[sample->loop_end-1];
								if (abs(s1 - s2) > scan_threshold_8)
								{
									sample->max_resampling_quality = 0;
									continue;
								}
								if (sample->flags & IT_SAMPLE_STEREO)
								{
									s1 = ((signed char *)sample->right)[sample->loop_start];
									s2 = ((signed char *)sample->right)[sample->loop_end-1];
									if (abs(s1 - s2) > scan_threshold_8)
									{
										sample->max_resampling_quality = 0;
										continue;
									}
								}
							}
						}
						if ((sample->flags & (IT_SAMPLE_SUS_LOOP|IT_SAMPLE_PINGPONG_SUS_LOOP)) == IT_SAMPLE_SUS_LOOP)
						{
							int s1, s2;
							if (sample->flags & IT_SAMPLE_16BIT)
							{
								s1 = ((signed short *)sample->left)[sample->sus_loop_start];
								s2 = ((signed short *)sample->left)[sample->sus_loop_end-1];
								if (abs(s1 - s2) > scan_threshold_16)
								{
									sample->max_resampling_quality = 0;
									continue;
								}
								if (sample->flags & IT_SAMPLE_STEREO)
								{
									s1 = ((signed short *)sample->right)[sample->sus_loop_start];
									s2 = ((signed short *)sample->right)[sample->sus_loop_end-1];
									if (abs(s1 - s2) > scan_threshold_16)
									{
										sample->max_resampling_quality = 0;
										continue;
									}
								}
							}
							else
							{
								s1 = ((signed char *)sample->left)[sample->sus_loop_start];
								s2 = ((signed char *)sample->left)[sample->sus_loop_end-1];
								if (abs(s1 - s2) > scan_threshold_8)
								{
									sample->max_resampling_quality = 0;
									continue;
								}
								if (sample->flags & IT_SAMPLE_STEREO)
								{
									s1 = ((signed char *)sample->right)[sample->sus_loop_start];
									s2 = ((signed char *)sample->right)[sample->sus_loop_end-1];
									if (abs(s1 - s2) > scan_threshold_8)
									{
										sample->max_resampling_quality = 0;
										continue;
									}
								}
							}
						}

						int k, l = sample->length;
						if (sample->flags & IT_SAMPLE_LOOP) l = sample->loop_end;
						if (sample->flags & IT_SAMPLE_16BIT)
						{
							for (k = 1; k < l; k++)
							{
								if (abs(((signed short *)sample->left)[k-1] - ((signed short *)sample->left)[k]) > scan_threshold_16)
								{
									break;
								}
							}
							if (k < l)
							{
								sample->max_resampling_quality = 0;
								continue;
							}
							if (sample->flags & IT_SAMPLE_STEREO)
							{
								for (k = 1; k < l; k++)
								{
									if (abs(((signed short *)sample->right)[k-1] - ((signed short *)sample->right)[k]) > scan_threshold_16)
									{
										break;
									}
								}
							}
							if (k < l)
							{
								sample->max_resampling_quality = 0;
								continue;
							}
						}
						else
						{
							for (k = 1; k < l; k++)
							{
								if (abs(((signed char *)sample->left)[k-1] - ((signed char *)sample->left)[k]) > scan_threshold_8)
								{
									break;
								}
							}
							if (k < l)
							{
								sample->max_resampling_quality = 0;
								continue;
							}
							if (sample->flags & IT_SAMPLE_STEREO)
							{
								for (k = 1; k < l; k++)
								{
									if (abs(((signed char *)sample->right)[k-1] - ((signed char *)sample->right)[k]) > scan_threshold_8)
									{
										break;
									}
								}
							}
							if (k < l)
							{
								sample->max_resampling_quality = 0;
								continue;
							}
						}
					}
				}
			}
		}
	}

	if ( duh && cfg_trim )
	{
		if ( dumb_it_trim_silent_patterns( duh ) < 0 )
		{
			unload_duh( duh );
			duh = 0;
		}
	}

	if ( ! duh ) throw exception_io_data();

	return duh;
}

struct callback_limit_info
{
	bool fade, fading;
	int loop_count;
};

static int dumb_it_callback_limit_int(void * data)
{
	callback_limit_info * info = ( callback_limit_info * ) data;
	if ( info->fade )
	{
		if ( info->fading ) return 0;
		if ( info->loop_count < 0 )
		{
			info->fading = true;
			return 0;
		}
	}
	if ( -- info->loop_count == 0 )
	{
		if ( info->fade )
		{
			info->fading = true;
			return 0;
		}
		else return 1;
	}
	return 1;
}

struct dumb_subsong_info
{
	long start_order;
	long length;
};

class dumb_info_scanner
{
	pfc::ptr_list_t< dumb_subsong_info > m_info;

	DUH * duh;

	struct callback_info
	{
		pfc::ptr_list_t< dumb_subsong_info > & m_info;
		abort_callback & m_abort;
	};

	static int scan_callback( void * context, int order, long length )
	{
		callback_info * info = ( callback_info * ) context;
		if ( info->m_abort.is_aborting() ) return -1;

		dumb_subsong_info * song = new dumb_subsong_info;
		song->start_order = order;
		song->length = length;

		info->m_info.add_item( song );

		return 0;
	}

public:
	dumb_info_scanner() : duh( 0 ) {}
	~dumb_info_scanner()
	{
		m_info.delete_all();
		if ( duh ) unload_duh( duh );
	}

	void run( const t_uint8 * ptr, unsigned size, const char * ext, abort_callback & p_abort )
	{
		dumbfile_mem_status memdata;

		memdata.ptr = ptr;
		memdata.offset = 0;
		memdata.size = size;

		DUMBFILE * f = dumbfile_open_ex( & memdata, & mem_dfs );
		if ( ! f ) throw std::bad_alloc();

		int subsongs = dumb_get_psm_subsong_count(f);

		dumbfile_close(f);

		bool is_it, is_dos;
		int start_order;

		if ( subsongs )
		{
			// new PSM stuffs

			for ( int i = 0; i < subsongs; ++i )
			{
				p_abort.check();

				start_order = i;
				duh = g_open_module( ptr, size, "PSM", start_order, is_it, is_dos );

				dumb_subsong_info * song = new dumb_subsong_info;

				song->start_order = i;
				song->length = _dumb_it_build_checkpoints( duh_get_it_sigdata( duh ), 0 );

				unload_duh( duh );
				duh = 0;

				m_info.add_item( song );
			}
		}
		else
		{
			start_order = 0;
			duh = g_open_module(ptr, size, ext, start_order, is_it, is_dos);

			callback_info cdata = { m_info, p_abort };

			start_order = dumb_it_scan_for_playable_orders( duh_get_it_sigdata( duh ), scan_callback, & cdata );

			unload_duh( duh );
			duh = 0;

			if ( start_order ) throw exception_io_data();
		}

		p_abort.check();
	}

	void get_info( pfc::ptr_list_t< dumb_subsong_info > & out )
	{
		for ( unsigned i = 0, j = m_info.get_count(); i < j; ++i )
		{
			dumb_subsong_info * in = m_info[ i ];
			dumb_subsong_info * out_item = new dumb_subsong_info;
			memcpy( out_item, in, sizeof( * in ) );
			out.add_item( out_item );
		}
	}
};

class dumb_info_cache
{
	struct t_info
	{
		pfc::string_simple                   path;
		t_filetimestamp                 timestamp;
		pfc::ptr_list_t< dumb_subsong_info > info;

		~t_info()
		{
			info.delete_all();
		}
	};

	pfc::ptr_list_t< t_info > m_cache;

	critical_section sync;

public:
	~dumb_info_cache()
	{
		m_cache.delete_all();
	}

	void run( const t_uint8 * ptr, unsigned size, const char * p_path, t_filetimestamp p_timestamp, pfc::ptr_list_t< dumb_subsong_info > & p_out, abort_callback & p_abort )
	{
		insync( sync );

		for ( unsigned i = 0, j = m_cache.get_count(); i < j; ++i )
		{
			t_info * item = m_cache[ i ];
			if ( ! stricmp_utf8( p_path, item->path ) && p_timestamp == item->timestamp )
			{
				for ( unsigned k = 0, l = item->info.get_count(); k < l; ++k )
				{
					dumb_subsong_info * in = item->info[ k ];
					dumb_subsong_info * out_item = new dumb_subsong_info;
					memcpy( out_item, in, sizeof( *in ) );
					p_out.add_item( out_item );
				}

				if ( i != m_cache.get_count() - 1 )
					m_cache.swap_items( i, m_cache.get_count() - 1 );

				return;
			}
		}

		t_info * item = new t_info;
		dumb_info_scanner scanner;
		try
		{
			scanner.run( ptr, size, pfc::string_extension( p_path ), p_abort );
		}
		catch (...)
		{
			delete item;
			throw;
		}

		{
			scanner.get_info( item->info );
			for ( unsigned i = 0, j = item->info.get_count(); i < j; ++i )
			{
				dumb_subsong_info * in = item->info[ i ];
				dumb_subsong_info * out_item = new dumb_subsong_info;
				memcpy( out_item, in, sizeof( *in ) );
				p_out.add_item( out_item );
			}

			while ( m_cache.get_count() >= 10 )
			{
				m_cache.delete_by_idx( 0 );
			}

			item->path = p_path;
			item->timestamp = p_timestamp;

			m_cache.add_item( item );
		}
	}
};

static dumb_info_cache g_cache;

class reader_membuffer : public reader_membuffer_base
{
	t_filetimestamp m_timestamp;
	void * m_buffer;
	unsigned m_size;

	const void * get_buffer() {return m_buffer;}
	unsigned get_buffer_size() {return m_size;}

	void init( void * p_buffer, unsigned p_size, t_filetimestamp p_timestamp )
	{
		m_buffer = p_buffer;
		m_size = p_size;
		m_timestamp = p_timestamp;
	}

public:
	reader_membuffer() : m_buffer( 0 ) {}
	~reader_membuffer()
	{
		if ( m_buffer ) free( m_buffer );
	}

	t_filetimestamp get_timestamp( abort_callback & p_abort ) { return m_timestamp; }
	bool is_remote() {return false;}

	static void g_create( service_ptr_t<file> & p_out, void * p_buffer, unsigned p_size, t_filetimestamp p_timestamp )
	{
		service_ptr_t<reader_membuffer> ptr = new service_impl_t<reader_membuffer>();
		ptr->init( p_buffer, p_size, p_timestamp );
		p_out = ptr.get_ptr();
	}
};

void unpack_j2b( service_ptr_t<file> & p_out, const service_ptr_t<file> & p_source, abort_callback & p_abort )
{
	unsigned char * uncompressed = 0;

	try
	{
		p_source->seek( 0, p_abort );

		unsigned char header[ 8 ];
		p_source->read_object( header, 8, p_abort );
		if ( header[ 0 ] != 'M' || header[ 1 ] != 'U' ||
			header[ 2 ] != 'S' || header[ 3 ] != 'E' ||
			header[ 4 ] != 0xDE || header[ 5 ] != 0xAD ||
			( ( header[ 6 ] != 0xBE || header[ 7 ] != 0xAF ) &&
			( header[ 6 ] != 0xBA || header[ 7 ] != 0xBE ) ) )
			throw exception_io_data();

		t_uint32 file_length;
		p_source->read_lendian_t( file_length, p_abort );

		if ( file_length < 12 ) throw exception_io_data();

		t_uint32 checksum;
		t_uint32 len_compressed;
		t_uint32 len_uncompressed;

		p_source->read_lendian_t( checksum, p_abort );
		p_source->read_lendian_t( len_compressed, p_abort );
		p_source->read_lendian_t( len_uncompressed, p_abort );

		if ( len_compressed + 8 > file_length ) throw exception_io_data();

		pfc::array_t< t_uint8 > compressed;
		compressed.set_size( len_compressed );

		p_source->read_object( compressed.get_ptr(), len_compressed, p_abort );

		if ( crc32( 0, compressed.get_ptr(), len_compressed ) != checksum )
			throw exception_io_data();

		uncompressed = ( unsigned char * ) malloc( len_uncompressed );
		if ( ! uncompressed ) throw std::bad_alloc();

		uLong data_uncompressed = len_uncompressed;

		int z_err = uncompress( uncompressed, & data_uncompressed, compressed.get_ptr(), len_compressed );
		if ( z_err != Z_OK )
		{
			if ( z_err == Z_MEM_ERROR ) throw std::bad_alloc();
			else throw exception_io_data();
		}

		reader_membuffer::g_create( p_out, uncompressed, data_uncompressed, p_source->get_timestamp( p_abort ) );
	}
	catch(...)
	{
		if ( uncompressed ) free( uncompressed );
		throw;
	}
}

class input_mod
{
	int srate, interp, volramp;
	int start_order;
	float delta;
	bool no_loop, eof, dynamic_info;
	int dyn_order, dyn_row, dyn_speed, dyn_tempo, dyn_channels, dyn_max_channels;
	int written;
	int loop_count;
	callback_limit_info limit_info;
	int fade_time, fade_time_left;
	DUH *duh;
	DUH_SIGRENDERER *sr;
	sample_t **buf;

	//pfc::array_t< sample_t > dbuf;

	pfc::string_simple extension;
	service_ptr_t< file > m_file;
	pfc::array_t< t_uint8 > buffer;

	t_filestats m_stats;

	bool is_dos, is_it;
	file_info_impl * m_info;

	pfc::ptr_list_t< dumb_subsong_info > m_subsong_info;

public:
	input_mod()
	{
		duh = 0;
		sr = 0;
		buf = 0;
		start_order = 0;
		written = 0;

		m_info = 0;
	}

	~input_mod()
	{
		if (buf) destroy_sample_buffer(buf);
		if (sr) duh_end_sigrenderer(sr);
		if (duh) unload_duh(duh);
		if (m_info) delete m_info;

		m_subsong_info.delete_all();
	}

	void open( service_ptr_t<file> m_file, const char * p_path, t_input_open_reason p_reason, abort_callback & p_abort )
	{
		if ( m_file.is_empty() )
		{
			filesystem::g_open( m_file, p_path, ( p_reason == input_open_info_write ) ? filesystem::open_mode_write_existing : filesystem::open_mode_read, p_abort );
		}

		t_uint8            * ptr;
		unsigned             size;

		extension = pfc::string_extension( p_path );

		bool read_tag;

		{
			service_ptr_t<file> m_unpack;

			m_info = new file_info_impl;

			try
			{
				unpacker::g_open( m_unpack, m_file, p_abort );

				m_file = m_unpack;
				read_tag = false;
			}
			catch ( const exception_io_data & )
			{
				try
				{
					unpack_j2b( m_unpack, m_file, p_abort );

					m_file = m_unpack;
					read_tag = false;
				}
				catch ( const exception_io_data & )
				{
					m_file->seek( 0, p_abort );
					read_tag = true;
				}
			}

			if ( !read_tag && p_reason == input_open_info_write ) throw exception_io_unsupported_format();

			m_stats = m_file->get_stats( p_abort );
			if ( m_stats.m_size < 1 || m_stats.m_size > ( 1UL << 30 ) )
			{
				throw exception_io_data();
			}

			size = unsigned( m_stats.m_size );

			// OutputDebugString("allocating buffer");
			buffer.set_size( size );
			ptr = buffer.get_ptr();

			// OutputDebugString("reading file");
			m_file->read_object( ptr, size, p_abort );
		}
		//catch(exception_io const & e) {return e.get_code();}

		srate = cfg_samplerate;
		delta = 65536.f / float( srate );

		m_info->info_set_int( "samplerate", srate );
		m_info->info_set_int( "channels", 2 );

		// OutputDebugString("loading module");

		start_order = 0;
		duh = g_open_module( ( const t_uint8 *& ) ptr, size, extension, start_order, is_it, is_dos );

		if ( read_tag )
		{
			try
			{
				tag_processor::read_trailing( m_file, *m_info, p_abort );
			}
			catch ( const exception_tag_not_found & ) { read_tag = false; }
			catch ( const exception_io_data & )       { read_tag = false; }
		}

		if (is_it) ReadIT(ptr, size, *m_info, !read_tag);
		else ReadDUH(duh, *m_info, !read_tag, is_dos);

		// subsong magic time
		g_cache.run( ptr, size, p_path, m_file->get_timestamp( p_abort ), m_subsong_info, p_abort );

		if ( p_reason == input_open_info_write ) this->m_file = m_file;
	}

	unsigned get_subsong_count()
	{
		return m_subsong_info.get_count();
	}

	t_uint32 get_subsong(unsigned p_index)
	{
		assert ( p_index < m_subsong_info.get_count() );
		return m_subsong_info[ p_index ]->start_order;
	}

	void get_info( t_uint32 p_subsong, file_info & p_info, abort_callback & p_abort )
	{
		p_info.copy( * m_info );

		dumb_subsong_info * info = 0;

		for ( unsigned i = 0, j = m_subsong_info.get_count(); i < j; ++i )
		{
			dumb_subsong_info * si = m_subsong_info[ i ];
			if ( si->start_order == p_subsong )
			{
				info = si;
				break;
			}
		}

		if ( ! info )
		{
			int length = _dumb_it_build_checkpoints( duh_get_it_sigdata( duh ), p_subsong );
			if ( length >= 0 ) p_info.set_length( double( length ) / 65536. );
		}
		else
		{
			if ( info->length >= 0 ) p_info.set_length( double( info->length ) / 65536. );
		}
	}

	t_filestats get_file_stats( abort_callback & p_abort )
	{
		return m_stats;
	}

	void decode_initialize( t_uint32 p_subsong, unsigned p_flags, abort_callback & p_abort )
	{
		if ( sr )
		{
			duh_end_sigrenderer( sr );
			sr = NULL;
		}

		if ( duh )
		{
			unload_duh( duh );
			duh = NULL;
		}

		interp = cfg_interp;
		volramp = cfg_volramp;
		limit_info.loop_count = loop_count = cfg_loop - 1;
		limit_info.fade = cfg_fade && limit_info.loop_count != 0;
		limit_info.fading = false;
		fade_time = MulDiv( cfg_fade_time, srate, 1000 );
		fade_time_left = fade_time;
		no_loop = ( p_flags & input_flag_no_looping ) || ( limit_info.loop_count < 0 );
		start_order = p_subsong;

		{
			const t_uint8 * ptr = buffer.get_ptr();
			unsigned size = buffer.get_size();
			duh = g_open_module( ptr, size, extension, start_order, is_it, is_dos );
		}

		if ( ! open2() ) throw exception_io_data();

		eof = false;
		dynamic_info = !!cfg_dynamic_info;
		written = 0;
		dyn_order = dyn_row = dyn_speed = dyn_tempo = dyn_channels = -1;
		dyn_max_channels = 0;
	}

private:
	bool open2( long pos = 0 )
	{
		if ( start_order )
		{
			sr = dumb_it_start_at_order( duh, 2, start_order );
			if ( sr && pos ) duh_sigrenderer_get_samples( sr, 0., 1.f, pos, 0 );
		}
		else
			sr = duh_start_sigrenderer( duh, 0, 2, pos );

		if (!sr)
			return false;

		DUMB_IT_SIGRENDERER * itsr = duh_get_it_sigrenderer( sr );
		dumb_it_set_resampling_quality( itsr, interp );
		dumb_it_set_ramp_style( itsr, volramp );
		if ( no_loop && ! limit_info.fade )
			dumb_it_set_loop_callback( itsr, & dumb_it_callback_terminate, NULL );
		else if ( loop_count != 0 )
			dumb_it_set_loop_callback( itsr, & dumb_it_callback_limit_int, & limit_info );
		dumb_it_set_xm_speed_zero_callback( itsr, & dumb_it_callback_terminate, NULL );
		dumb_it_set_global_volume_zero_callback( itsr, & dumb_it_callback_terminate, NULL );

		return true;
	}

public:
	bool decode_run(audio_chunk & p_chunk,abort_callback & p_abort)
	{
		if (eof) return false;

		if ( limit_info.fading && fade_time_left == 0 ) return false;

		/*int*/ written=0;

		DUMB_IT_SIGRENDERER * itsr = duh_get_it_sigrenderer( sr );
		int dt = int( delta * 65536.0f + 0.5f );
		long samples = long( ( ( (LONG_LONG)itsr->time_left << 16 ) | itsr->sub_time_left ) / dt );
		if ( ! samples || samples > 2048 ) samples = 2048;

		if ( ! buf )
		{
			buf = create_sample_buffer( 2, 2048 );
			if ( ! buf ) throw std::bad_alloc();
		}

		pfc::static_assert_t< sizeof( audio_sample ) == sizeof( sample_t ) >();
		//dbuf.grow_size( 2048 * 2 );
retry:
		p_abort.check();

		dumb_silence( buf[0], 2048 * 2 );
		written = duh_sigrenderer_get_samples( sr, 1.f, delta, samples, buf );

		if (written < samples)
		{
			if (no_loop)
				eof = true;
			else
			{
				if ( limit_info.loop_count <= 0 && loop_count != 0 )
				{
					eof = true;
				}
				else
				{
					if ( loop_count == 0 || --limit_info.loop_count == 0 )
					{
						duh_end_sigrenderer( sr );
						sr = NULL;
						if ( open2() )
						{
							if ( limit_info.fade )
							{
								fade_time_left = fade_time + written;
								dumb_it_set_loop_callback( itsr, 0, 0 );
								limit_info.fading = true;
							}
							if ( ! written )
								goto retry;
						}
						else
						{
							eof = true;
						}
					}
				}
			}
		}

		if      ( written == 0 )  return false;
		else if ( written == -1 ) throw exception_io_data();

		if ( limit_info.fading )
		{
			fade_time_left -= written;
			if ( fade_time_left < 0 )
			{
				written += fade_time_left;
				fade_time_left = 0;
			}
		}

		p_chunk.set_data_size( written * 2 );

		sample_t * in_l = buf[0];
		sample_t * in_r = buf[1];
		sample_t * out = ( sample_t * ) p_chunk.get_data(); //dbuf.get_ptr();
		if ( limit_info.fading && fade_time_left < fade_time )
		{
			for ( unsigned i = 0; i < written; ++i )
			{
				*out++ = MulDiv( *in_l++, fade_time_left + written - i, fade_time );
				*out++ = MulDiv( *in_r++, fade_time_left + written - i, fade_time );
			}
		}
		else
		{
			for ( unsigned i = 0; i < written; ++i )
			{
				*out++ = *in_l++;
				*out++ = *in_r++;
			}
		}
		//p_chunk.check_data_size( written * 2 );
		audio_math::convert_from_int32( ( const t_int32 * ) p_chunk.get_data() /*dbuf.get_ptr()*/, written * 2, p_chunk.get_data(), 1 << 8 );
		p_chunk.set_srate( srate );
		p_chunk.set_channels( 2 );
		p_chunk.set_sample_count( written );

		return true;
	}

	void decode_seek( double p_seconds, abort_callback & p_abort )
	{
		long from_pos = duh_sigrenderer_get_position( sr );
		eof = false;

		if ( from_pos < 0 ) throw exception_io();

		long to_pos = long( audio_math::time_to_samples( p_seconds, 65536 ) );

		if ( to_pos < from_pos )
		{
			duh_end_sigrenderer( sr );
			sr = NULL;
			limit_info.loop_count = loop_count;
			if ( ! open2( to_pos ) ) throw exception_io_data();
		}
		else if ( to_pos > from_pos )
		{
			duh_sigrenderer_get_samples( sr, 0., 1.f, to_pos - from_pos, 0 );
		}
	}

	bool decode_can_seek()
	{
		return true;
	}

	bool decode_get_dynamic_info(file_info & p_out, double & p_timestamp_delta)
	{
		bool ret = false;
		if (dynamic_info && duh && sr)
		{
			DUMB_IT_SIGDATA * itsd = duh_get_it_sigdata(duh);
			DUMB_IT_SIGRENDERER * itsr = duh_get_it_sigrenderer(sr);
			if (itsd && itsr)
			{
				if (dyn_order != itsr->order)
				{
					dyn_order = itsr->order;
					p_out.info_set_int(field_dyn_order, dyn_order);
					if (itsd->order && dyn_order < itsd->n_orders)
						p_out.info_set_int(field_dyn_pattern, itsd->order[dyn_order]);
					ret = true;
				}
				if (dyn_row != itsr->row)
				{
					dyn_row = itsr->row;
					p_out.info_set_int(field_dyn_row, dyn_row);
					ret = true;
				}
				if (dyn_speed != itsr->speed)
				{
					dyn_speed = itsr->speed;
					p_out.info_set_int(field_dyn_speed, dyn_speed);
					ret = true;
				}
				if (dyn_tempo != itsr->tempo)
				{
					dyn_tempo = itsr->tempo;
					p_out.info_set_int(field_dyn_tempo, dyn_tempo);
					ret = true;
				}
				int channels = 0;
				for (int i = 0; i < DUMB_IT_N_CHANNELS; i++)
				{
					IT_PLAYING * playing = itsr->channel[i].playing;
					if (playing && !(playing->flags & IT_PLAYING_DEAD)) channels++;
				}
				for (int i = 0; i < DUMB_IT_N_NNA_CHANNELS; i++)
				{
					if (itsr->playing[i]) channels++;
				}
				if (channels != dyn_channels)
				{
					dyn_channels = channels;
					p_out.info_set_int(field_dyn_channels, dyn_channels);
					ret = true;
				}
				if (channels > dyn_max_channels)
				{
					dyn_max_channels = channels;
					p_out.info_set_int(field_dyn_channels_max, dyn_max_channels);
					ret = true;
				}
				if (ret) p_timestamp_delta = written / double( srate );
			}
		}
		return ret;
	}

	bool decode_get_dynamic_info_track( file_info & p_out, double & p_timestamp_delta )
	{
		return false;
	}

	void decode_on_idle( abort_callback & p_abort )
	{
	}

	void retag_set_info( t_uint32 p_subsong, const file_info & p_info, abort_callback & p_abort )
	{
		if ( cfg_tag )
		{
			if ( p_subsong > 0 || m_subsong_info.get_count() > 1 ) throw exception_io_unsupported_format();

			m_info->copy( p_info );

			tag_processor::write_apev2( m_file, p_info, p_abort );

			m_stats = m_file->get_stats( p_abort );
		}
		else
		{
			throw exception_io_unsupported_format();
		}
	}

	void retag_commit( abort_callback & p_abort )
	{
	}

	static bool g_is_our_content_type( const char * p_content_type )
	{
		return ! strcmp( p_content_type, "audio/x-mod" );
	}

	static bool g_is_our_path( const char * p_path, const char * p_extension )
	{
		return g_test_extension( p_extension );
	}
};

static cfg_dropdown_history cfg_history_rate(guid_cfg_history_rate,16);

static const int srate_tab[]={8000,11025,16000,22050,24000,32000,44100,48000,64000,88200,96000};

static const long BORK_TIME = 0xC0CAC01A;

unsigned long parse_time_crap(const char *input)
{
	if (!input) return BORK_TIME;
	int len = strlen(input);
	if (!len) return BORK_TIME;
	int value = 0;
	{
		int i;
		for (i = len - 1; i >= 0; i--)
		{
			if ((input[i] < '0' || input[i] > '9') && input[i] != ':' && input[i] != ',' && input[i] != '.')
			{
				return BORK_TIME;
			}
		}
	}
	pfc::string8 foo = input;
	char *bar = (char *)foo.get_ptr();
	char *strs = bar + foo.length() - 1;
	while (strs > bar && (*strs >= '0' && *strs <= '9'))
	{
		strs--;
	}
	if (*strs == '.' || *strs == ',')
	{
		// fraction of a second
		strs++;
		if (strlen(strs) > 3) strs[3] = 0;
		value = atoi(strs);
		switch (strlen(strs))
		{
		case 1:
			value *= 100;
			break;
		case 2:
			value *= 10;
			break;
		}
		strs--;
		*strs = 0;
		strs--;
	}
	while (strs > bar && (*strs >= '0' && *strs <= '9'))
	{
		strs--;
	}
	// seconds
	if (*strs < '0' || *strs > '9') strs++;
	value += atoi(strs) * 1000;
	if (strs > bar)
	{
		strs--;
		*strs = 0;
		strs--;
		while (strs > bar && (*strs >= '0' && *strs <= '9'))
		{
			strs--;
		}
		if (*strs < '0' || *strs > '9') strs++;
		value += atoi(strs) * 60000;
		if (strs > bar)
		{
			strs--;
			*strs = 0;
			strs--;
			while (strs > bar && (*strs >= '0' && *strs <= '9'))
			{
				strs--;
			}
			value += atoi(strs) * 3600000;
		}
	}
	return value;
}

void print_time_crap(int ms, char *out)
{
	char frac[8];
	int i,h,m,s;
	if (ms % 1000)
	{
		sprintf(frac, ".%3.3d", ms % 1000);
		for (i = 3; i > 0; i--)
			if (frac[i] == '0') frac[i] = 0;
		if (!frac[1]) frac[0] = 0;
	}
	else
		frac[0] = 0;
	h = ms / (60*60*1000);
	m = (ms % (60*60*1000)) / (60*1000);
	s = (ms % (60*1000)) / 1000;
	if (h) sprintf(out, "%d:%2.2d:%2.2d%s",h,m,s,frac);
	else if (m) sprintf(out, "%d:%2.2d%s",m,s,frac);
	else sprintf(out, "%d%s",s,frac);
}

class preferences_page_mod : public preferences_page
{
	static void enable_chip(HWND wnd, bool status)
	{
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_BOX), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_FORCE), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_SCAN), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_SCAN_THRESHOLD), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_TEXT_0), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_TEXT_1), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_TEXT_2), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_TEXT_3), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_TEXT_4), status);
		EnableWindow(GetDlgItem(wnd, IDC_CHIP_TEXT_5), status);
	}

	static void enable_fade(HWND wnd, bool status)
	{
		EnableWindow(GetDlgItem(wnd, IDC_FADE), status);
		EnableWindow(GetDlgItem(wnd, IDC_FADE_TIME), status);
		EnableWindow(GetDlgItem(wnd, IDC_FADE_TEXT), status);
	}

	static BOOL CALLBACK ConfigProc(HWND wnd,UINT msg,WPARAM wp,LPARAM lp)
	{
		switch(msg)
		{
		case WM_INITDIALOG:
			{
				HWND w;
				char temp[16];
				int n;
				for(n=tabsize(srate_tab);n--;)
				{
					if (srate_tab[n] != cfg_samplerate)
					{
						itoa(srate_tab[n], temp, 10);
						cfg_history_rate.add_item(temp);
					}
				}
				itoa(cfg_samplerate, temp, 10);
				cfg_history_rate.add_item(temp);
				cfg_history_rate.setup_dropdown(w = GetDlgItem(wnd,IDC_SAMPLERATE));
				uSendMessage(w, CB_SETCURSEL, 0, 0);

				w = GetDlgItem(wnd, IDC_INTERPOLATION);
				uSendMessageText(w, CB_ADDSTRING, 0, "none");
				uSendMessageText(w, CB_ADDSTRING, 0, "linear");
				uSendMessageText(w, CB_ADDSTRING, 0, "cubic");
				uSendMessage(w, CB_SETCURSEL, cfg_interp, 0);

				w = GetDlgItem(wnd, IDC_LOOPS);
				uSendMessageText(w, CB_ADDSTRING, 0, "none");
				uSendMessageText(w, CB_ADDSTRING, 0, "infinite");
				for (n = 1; n <= 16; n++)
				{
					itoa(n, temp, 10);
					uSendMessageText(w, CB_ADDSTRING, 0, temp);
				}
				uSendMessage(w, CB_SETCURSEL, cfg_loop, 0);

				enable_fade( wnd, cfg_loop != 1 );
				uSendDlgItemMessage( wnd, IDC_FADE, BM_SETCHECK, cfg_fade, 0 );
				print_time_crap( cfg_fade_time, ( char * ) &temp );
				uSetDlgItemText( wnd, IDC_FADE_TIME, ( char * ) &temp );

				w = GetDlgItem(wnd, IDC_VOLRAMP);
				uSendMessageText(w, CB_ADDSTRING, 0, "none");
				uSendMessageText(w, CB_ADDSTRING, 0, "logarithmic");
				uSendMessageText(w, CB_ADDSTRING, 0, "linear");
				uSendMessageText(w, CB_ADDSTRING, 0, "XM=lin, else none");
				uSendMessageText(w, CB_ADDSTRING, 0, "XM=lin, else log");
				uSendMessage(w, CB_SETCURSEL, cfg_volramp, 0);

				uSendDlgItemMessage(wnd, IDC_TAG, BM_SETCHECK, cfg_tag, 0);
				uSendDlgItemMessage(wnd, IDC_TRIM, BM_SETCHECK, cfg_trim, 0);
				/*uSendDlgItemMessage(wnd, IDC_SCAN, BM_SETCHECK, cfg_scan_subsongs, 0);*/
				uSendDlgItemMessage(wnd, IDC_DYNAMIC_INFO, BM_SETCHECK, cfg_dynamic_info, 0);

				enable_chip(wnd, cfg_interp > 0);
				uSendDlgItemMessage(wnd, IDC_CHIP, BM_SETCHECK, cfg_autochip, 0);
				uSetDlgItemText(wnd, IDC_CHIP_FORCE, uStringPrintf("%u", (int)cfg_autochip_size_force));
				uSetDlgItemText(wnd, IDC_CHIP_SCAN, uStringPrintf("%u", (int)cfg_autochip_size_scan));
				uSetDlgItemText(wnd, IDC_CHIP_SCAN_THRESHOLD, uStringPrintf("%u", (int)cfg_autochip_scan_threshold));

				uSetWindowLong(wnd, DWL_USER, 1);
			}
			return 1;
		case WM_COMMAND:
			switch(wp)
			{
				/*
				case (CBN_SELCHANGE<<16)|IDC_SAMPLERATE:
				{
				pfc::string8 meh;
				cfg_history_rate.get_item(meh, SendMessage((HWND)lp,CB_GETCURSEL,0,0));
				cfg_samplerate = atoi(meh);
				}			
				break;
				case (CBN_EDITCHANGE<<16)|IDC_SAMPLERATE:
				*/
			case (CBN_KILLFOCUS<<16)|IDC_SAMPLERATE:
				{
					int t = GetDlgItemInt(wnd,IDC_SAMPLERATE,0,0);
					if (t<6000) t=6000;
					else if (t>192000) t=192000;
					cfg_samplerate = t;
				}
				break;
			case (CBN_SELCHANGE<<16)|IDC_INTERPOLATION:
				cfg_interp = uSendMessage((HWND)lp,CB_GETCURSEL,0,0);
				enable_chip(wnd, cfg_interp > 0);
				break;
			case (CBN_SELCHANGE<<16)|IDC_LOOPS:
				cfg_loop = uSendMessage((HWND)lp,CB_GETCURSEL,0,0);
				enable_fade( wnd, cfg_loop != 1 );
				break;
			case (CBN_SELCHANGE<<16)|IDC_VOLRAMP:
				cfg_volramp = uSendMessage((HWND)lp,CB_GETCURSEL,0,0);
				break;
			case IDC_TAG:
				cfg_tag = uSendMessage((HWND)lp,BM_GETCHECK,0,0);
				break;
			case IDC_TRIM:
				cfg_trim = uSendMessage((HWND)lp,BM_GETCHECK,0,0);
				break;
			/*case IDC_SCAN:
				cfg_scan_subsongs = uSendMessage((HWND)lp,BM_GETCHECK,0,0);
				break;*/
			case IDC_DYNAMIC_INFO:
				cfg_dynamic_info = uSendMessage((HWND)lp,BM_GETCHECK,0,0);
				break;

			case IDC_CHIP:
				cfg_autochip = uSendMessage((HWND)lp,BM_GETCHECK,0,0);
				break;

			case IDC_FADE:
				cfg_fade = uSendMessage( ( HWND ) lp, BM_GETCHECK, 0, 0 );
				break;

			case ( EN_CHANGE << 16 ) | IDC_FADE_TIME:
				{
					int meh = parse_time_crap( string_utf8_from_window( ( HWND ) lp ) );
					if ( meh != BORK_TIME ) cfg_fade_time = meh;
				}
				break;
			case ( EN_KILLFOCUS << 16 ) | IDC_FADE_TIME:
				{
					char temp[16];
					print_time_crap( cfg_fade_time, ( char * ) &temp );
					uSetWindowText( ( HWND ) lp, temp );
				}
				break;

			case (EN_CHANGE<<16)|IDC_CHIP_FORCE:
				if (uGetWindowLong(wnd,DWL_USER))
				{
					int t = atoi(string_utf8_from_window((HWND)lp));
					int scan = cfg_autochip_size_scan;
					if (t < 1) t = 1;
					if (t > scan) t = scan;
					if (t > 10000) t = 10000;
					cfg_autochip_size_force = t;
				}
				break;
			case (EN_KILLFOCUS<<16)|IDC_CHIP_FORCE:
				{
					uSetWindowText((HWND)lp, uStringPrintf("%u", (int)cfg_autochip_size_force));
				}
				break;

			case (EN_CHANGE<<16)|IDC_CHIP_SCAN:
				if (uGetWindowLong(wnd,DWL_USER))
				{
					int t = atoi(string_utf8_from_window((HWND)lp));
					int force = cfg_autochip_size_force;
					if (t < 1) t = 1;
					if (t <= force) t = force + 1;
					if (t > 20000) t = 20000;
					cfg_autochip_size_scan = t;
				}
				break;
			case (EN_KILLFOCUS<<16)|IDC_CHIP_SCAN:
				{
					uSetWindowText((HWND)lp, uStringPrintf("%u", (int)cfg_autochip_size_scan));
				}
				break;

			case (EN_CHANGE<<16)|IDC_CHIP_SCAN_THRESHOLD:
				if (uGetWindowLong(wnd,DWL_USER))
				{
					int t = atoi(string_utf8_from_window((HWND)lp));
					if (t < 1) t = 1;
					if (t > 100) t = 100;
					cfg_autochip_scan_threshold = t;
				}
				break;
			case (EN_KILLFOCUS<<16)|IDC_CHIP_SCAN_THRESHOLD:
				{
					uSetWindowText((HWND)lp, uStringPrintf("%u", (int)cfg_autochip_scan_threshold));
				}
				break;

			}
			break;
		case WM_DESTROY:
			char temp[16];
			itoa(cfg_samplerate, temp, 10);
			cfg_history_rate.add_item(temp);
			break;
		}
		return 0;
	}

public:
	virtual HWND create(HWND parent)
	{
		return uCreateDialog(IDD_MOD_CONFIG,parent,ConfigProc);
	}
	GUID get_guid()
	{
		// {2FB4FC78-D302-46ce-9F19-47368EE8ED08}
		static const GUID guid = 
		{ 0x2fb4fc78, 0xd302, 0x46ce, { 0x9f, 0x19, 0x47, 0x36, 0x8e, 0xe8, 0xed, 0x8 } };
		return guid;
	}
	virtual const char * get_name() {return "DUMB module decoder";}
	GUID get_parent_guid() {return guid_input;}

	bool reset_query() {return true;}
	void reset()
	{
		cfg_samplerate = 44100;
		cfg_interp = 2;
		cfg_fade = 0;
		cfg_fade_time = 10000;
		cfg_volramp = 0;

		cfg_autochip = 0;
		cfg_autochip_size_force = 100;
		cfg_autochip_size_scan = 500;
		cfg_autochip_scan_threshold = 12;

		cfg_loop = 0;

		cfg_tag = 0;

		cfg_trim = 0;

		/*cfg_scan_subsongs = 0;*/

		cfg_dynamic_info = 0;
	}
};

class mod_file_types : public input_file_type
{
	virtual unsigned get_count()
	{
		return 1;
	}

	virtual bool get_name(unsigned idx, pfc::string_base & out)
	{
		if (idx > 0) return false;
		out = "Module files";
		return true;
	}

	virtual bool get_mask(unsigned idx, pfc::string_base & out)
	{
		if (idx > 0) return false;
		out.reset();
		for (int n = 0; n < tabsize(exts); n++)
		{
			if (n) out.add_byte(';');
			out << "*." << exts[n];
		}
		return true;
	}

	virtual bool is_associatable(unsigned idx)
	{
		return true;
	}
};

#if 0
struct context_data
{
	HGLOBAL title;
	unsigned start;
	unsigned limit;
	bool dupe;
};

static BOOL CALLBACK context_proc(HWND wnd,UINT msg,WPARAM wp,LPARAM lp)
{
	context_data cd;

	if (msg == WM_INITDIALOG)
	{
		SetProp(wnd, _T("mod_dat"), (HANDLE)lp);
		{
			cd = *(context_data *) GlobalLock((HGLOBAL)lp);
			GlobalUnlock((HGLOBAL)lp);

			if (cd.title)
			{
				pfc::string8 title = (const char *) GlobalLock(cd.title);
				GlobalUnlock(cd.title);
				uSetWindowText(wnd, title);
			}

			uSetDlgItemText(wnd, IDC_RANGE, uStringPrintf("(0-%u)", cd.limit));
			uSetDlgItemInt(wnd, IDC_ORDER, cd.start, FALSE);
			uSendDlgItemMessage(wnd, IDC_REPLACE, BM_SETCHECK, !cd.dupe, 0);
		}
		return 1;
	}

	switch (msg)
	{
	case WM_COMMAND:
		switch (wp)
		{
		case IDOK:
			{
				HGLOBAL data = GetProp(wnd, _T("mod_dat"));
				if (data)
				{
					cd = *(context_data *) GlobalLock(data);
					GlobalUnlock(data);

					char * feh;
					unsigned foo = strtoul(string_utf8_from_window(wnd, IDC_ORDER), &feh, 10);
					if (foo > cd.limit) cd.start = cd.limit;
					else cd.start = foo;

					foo = uSendDlgItemMessage(wnd, IDC_REPLACE, BM_GETCHECK, 0, 0);
					cd.dupe = !foo;

					*(context_data *) GlobalLock(data) = cd;
					GlobalUnlock(data);

					EndDialog(wnd, 1);
					break;
				}
			}
		case IDCANCEL:
			EndDialog(wnd, 0);
			break;
		}
		break;

	case WM_DESTROY:
		RemoveProp(wnd, _T("mod_dat"));
		break;
	}

	return 0;
}


class context_popup
{
	HGLOBAL data;

public:
	context_popup() : data(NULL) {}
	context_popup(const char * p_title, unsigned p_start, unsigned p_limit)
	{
		size_t len = strlen(p_title) + 1;
		data = GlobalAlloc(GMEM_MOVEABLE,sizeof(context_data));
		if (data)
		{
			context_data * ctx = (context_data *) GlobalLock(data);
			ctx->title = GlobalAlloc(GMEM_MOVEABLE, len);
			if (!ctx->title)
			{
				GlobalUnlock(data);
				GlobalFree(data);
				return;
			}
			memcpy(GlobalLock(ctx->title), p_title, len);
			GlobalUnlock(ctx->title);
			ctx->start = p_start;
			ctx->limit = p_limit;
			ctx->dupe = false;
			GlobalUnlock(data);
		}
	}

	~context_popup()
	{
		if (data)
		{
			context_data * ctx = (context_data *) GlobalLock(data);
			if (ctx->title) GlobalFree(ctx->title);
			GlobalUnlock(data);
			GlobalFree(data);
		}
	}

	bool allocate()
	{
		if (!data)
		{
			data = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, sizeof(context_data));
			if (!data) return false;
		}
		return true;
	}

	bool do_modal()
	{
		if (allocate())
		{
			HWND hwnd = core_api::get_main_window();
			return !!uDialogBox(IDD_CONTEXT, hwnd, context_proc, (long)data);
		}
		return false;
	}

	void set_title(const char * p_title)
	{
		if (allocate())
		{
			size_t len = strlen(p_title) + 1;
			context_data * ctx = (context_data *) GlobalLock(data);
			if (ctx->title) GlobalFree(ctx->title);
			ctx->title = GlobalAlloc(GMEM_MOVEABLE, len);
			if (!ctx->title) return;
			memcpy(GlobalLock(ctx->title), p_title, len);
			GlobalUnlock(ctx->title);
			GlobalUnlock(data);
		}
	}

	void set_start(unsigned p_start)
	{
		if (allocate())
		{
			context_data * ctx = (context_data *) GlobalLock(data);
			if (p_start <= ctx->limit) ctx->start = p_start;
			else ctx->start = ctx->limit;
			GlobalUnlock(data);
		}
	}

	unsigned get_start()
	{
		unsigned ret;
		if (allocate())
		{
			context_data * ctx = (context_data *) GlobalLock(data);
			ret = ctx->start;
			GlobalUnlock(data);
			return ret;
		}
		return 0;
	}

	void set_limit(unsigned p_limit)
	{
		if (allocate())
		{
			context_data * ctx = (context_data *) GlobalLock(data);
			if (p_limit < ctx->start) ctx->start = p_limit;
			ctx->limit = p_limit;
			GlobalUnlock(data);
		}
	}

	bool get_dupe()
	{
		bool ret;
		if (allocate())
		{
			context_data * ctx = (context_data *) GlobalLock(data);
			ret = ctx->dupe;
			GlobalUnlock(data);
			return ret;
		}
		return false;
	}
};

class context_mod : public menu_item_legacy
{
public:
	type get_type()
	{
		return TYPE_CONTEXT;
	}

	unsigned get_num_items()
	{
		return 1;
	}

	void get_item_name(unsigned n, string_base & out)
	{
		out = "Change starting order or subsong";
	}

	void get_item_default_path(unsigned n, string_base & out)
	{
		out.reset();
	}

	bool get_item_description(unsigned n, string_base & out)
	{
		return false;
	}

	virtual GUID get_item_guid(unsigned p_index)
	{
		// {EB34F868-791F-40ad-B74B-CF70DD8D3CD1}
		static const GUID guid = 
		{ 0xeb34f868, 0x791f, 0x40ad, { 0xb7, 0x4b, 0xcf, 0x70, 0xdd, 0x8d, 0x3c, 0xd1 } };
		return guid;
	}

	bool get_display_data(unsigned n,const list_base_const_t<metadb_handle_ptr> & data,string_base & out,unsigned & displayflags,const GUID & caller)
	{
		if (n != 0) return false;
		if (data.get_count() != 1) return false;

		const playable_location & foo = data[0]->get_location();
		string_extension ext(foo.get_path());
		if (!g_test_extension(ext)) return false;

		out = "Change subsong or initial order";

		return true;
	}

	void perform_command(unsigned n,const list_base_const_t<metadb_handle_ptr> & data,const GUID & caller)
	{
		if (n != 0) return;
		if (data.get_count() != 1) return;

		const metadb_handle_ptr handle = data[0];

		const playable_location & item = handle->get_location();
		string_filename_ext name(item.get_path());
		int start = item.get_subsong();
		int orders = -1;
		bool psm;

		service_ptr_t<file> r;
		abort_callback_impl p_abort;
		if (io_result_failed(filesystem::g_open(r,item.get_path(),filesystem::open_mode_read,p_abort))) return;

		t_filesize size64;
		
		if (io_result_failed(r->get_size(size64, p_abort))) return;

		if (size64 < 4 || size64 > (1UL << 30)) return;

		int size = (int)size64;

		mem_block_t<BYTE> buffer;

		BYTE * ptr = buffer.set_size(4);

		if (io_result_failed(r->read_object(ptr, 4, p_abort))) return;

		if (ptr[0] != 'P' || ptr[1] != 'S' || ptr[2] != 'M' || ptr[3] != ' ')
		{
			psm = false;
			handle->metadb_lock();
			const file_info * info;
			if (handle->get_info_locked(info) && info)
			{
				const char * ptr = info->info_get(field_orders);
				if (ptr)
				{
					char * feh;
					orders = strtoul(ptr, &feh, 10);
					if (feh == ptr) orders = -1;
				}
			}
			handle->metadb_unlock();
		}
		else
		{
			psm = true;

			ptr = buffer.check_size(size);

			if (io_result_failed(r->read_object(ptr + 4, size - 4, p_abort))) return;

			dumbfile_mem_status memdata;

			memdata.ptr = ptr;
			memdata.offset = 0;
			memdata.size = size;

			DUMBFILE * f = dumbfile_open_ex(&memdata, &mem_dfs);

			if (!f) return;

			orders = dumb_get_psm_subsong_count(f);

			dumbfile_close(f);
		}

		if (orders <= 0) return;

		pfc::string8 title = "Set ";
		if (psm) title += "subsong";
		else title += "initial order";
		title += " for ";
		title += name;
		title += "...";

		context_popup popup(title, start, orders - 1);

		if (popup.do_modal())
		{
			service_ptr_t<playlist_manager> pm;
			if (!playlist_manager::g_get(pm)) return;
			int position = pm->activeplaylist_get_focus_item();

			service_ptr_t<metadb> p_metadb;
			if (!metadb::g_get(p_metadb)) return;

			metadb_handle_ptr new_handle;
			if (!p_metadb->handle_create(new_handle, make_playable_location(item.get_path(), popup.get_start()))) return;

			if (popup.get_dupe())
			{
				list_single_ref_t<metadb_handle_ptr> items(new_handle);
				pm->activeplaylist_insert_items(position + 1, items, bit_array_one(position + 1));
			}
			else
			{
				pm->activeplaylist_replace_item(position, new_handle);
			}
		}
	}
};
#endif

static input_factory_t           <input_mod>                      g_input_mod_factory;
static preferences_page_factory_t<preferences_page_mod>           g_config_mod_factory;
static service_factory_single_t  <mod_file_types> g_input_file_type_mod_factory;
//static menu_item_factory_t       <context_mod>                    g_menu_item_mod_factory;

DECLARE_COMPONENT_VERSION( "DUMB module decoder", MYVERSION, "Using DUMB v" DUMB_VERSION_STR "-cvs-" DUMB_YEAR_STR4 DUMB_MONTH_STR2 DUMB_DAY_STR2 ",\nwith several modifications.\n\nhttp://dumb.sourceforge.net/");
