#include <string.h>

#include "duh_ptmod.h"

#include <playptmod.h>

#define SIGTYPE_PTMOD DUMB_ID('P', 'T', ' ', ' ')

static sigrenderer_t *playptmod_start_sigrenderer(
	DUH *duh,
	sigdata_t *vsigdata,
	int n_channels,
	long pos
);

static void playptmod_set_sigparam(
	sigrenderer_t *sigrenderer,
	unsigned char id, long value
);

static long playptmod_sigrenderer_get_samples(
	sigrenderer_t *vsigrenderer,
	float volume, float delta,
	long size, sample_t **samples
);

static void playptmod_sigrenderer_get_current_sample(
	sigrenderer_t *vsigrenderer,
	float volume,
	sample_t *samples
);

static void playptmod_end_sigrenderer(sigrenderer_t *vsigrenderer);

static void playptmod_unload_sigdata(sigdata_t *vsigdata);

static DUH_SIGTYPE_DESC _dumb_sigtype_playptmod = {
	SIGTYPE_PTMOD,
	NULL,
	&playptmod_start_sigrenderer,
	&playptmod_set_sigparam,
	&playptmod_sigrenderer_get_samples,
	&playptmod_sigrenderer_get_current_sample,
	&playptmod_end_sigrenderer,
	&playptmod_unload_sigdata
};

int duh_read_playptmod( DUH *duh, const unsigned char *data, size_t size )
{
	if ( !duh || !data || !size ) return -1;

	unsigned char *sigdata = ( unsigned char *) malloc( size + sizeof( size_t ) );
	if ( !sigdata ) return -1;

	* ( size_t * ) sigdata = size;
	memcpy( sigdata + sizeof( size_t ), data, size );

	return duh_add_signal( duh, &_dumb_sigtype_playptmod, sigdata );
}

DUH_SIGRENDERER *duh_encapsulate_playptmod_sigrenderer(void *playptmod_sigrenderer)
{
	return duh_encapsulate_raw_sigrenderer( playptmod_sigrenderer, &_dumb_sigtype_playptmod, 2, 0 );
}

void *duh_get_playptmod_sigdata(DUH *duh)
{
	return duh_get_raw_sigdata(duh, 0, SIGTYPE_PTMOD);
}

void *duh_get_playptmod_sigrenderer(DUH_SIGRENDERER *sigrenderer)
{
	return duh_get_raw_sigrenderer(sigrenderer, SIGTYPE_PTMOD);
}

DUH_SIGRENDERER * playptmod_start_at_order( DUH *duh, int startorder, int sample_rate, int pattern_counting )
{
	void * vsigdata = duh_get_playptmod_sigdata( duh );
	if ( !vsigdata ) return NULL;

	size_t size = *( size_t * ) vsigdata;
	unsigned char * data = (( unsigned char * ) vsigdata ) + sizeof( size_t );

	void * sigrenderer = playptmod_Create( sample_rate );
	if ( !sigrenderer ) return NULL;

	playptmod_Config( sigrenderer, PTMOD_OPTION_PATTERN_COUNT, pattern_counting );

	if ( !playptmod_LoadMem( sigrenderer, data, size ) )
	{
		playptmod_Free( sigrenderer );
		return NULL;
	}

	playptmod_Play( sigrenderer, startorder );

	return duh_encapsulate_playptmod_sigrenderer( sigrenderer );
}

sigrenderer_t *playptmod_start_sigrenderer(
	DUH *duh,
	sigdata_t *vsigdata,
	int n_channels,
	long pos
)
{
	if ( n_channels != 2 || pos != 0 ) return NULL;

	return playptmod_start_at_order( duh, 0, 44100, 0 );
}

void playptmod_set_sigparam(
	sigrenderer_t *sigrenderer,
	unsigned char id, long value
)
{
	playptmod_Config( sigrenderer, id, value );
}

long playptmod_sigrenderer_get_samples(
	sigrenderer_t *vsigrenderer,
	float volume, float delta,
	long size, sample_t **samples
)
{
	signed short * buffer = ( signed short * ) malloc( size * sizeof( signed short ) * 2 );

	playptmod_Render( vsigrenderer, buffer, size );

	if ( samples && samples[ 0 ] )
		for ( unsigned i = 0; i < size; i++ )
		{
			samples[ 0 ][ i * 2 + 0 ] = buffer[ i * 2 + 0 ] << 8;
			samples[ 0 ][ i * 2 + 1 ] = buffer[ i * 2 + 1 ] << 8;
		}

	free( buffer );

	return size;
}

void playptmod_sigrenderer_get_current_sample(
	sigrenderer_t *vsigrenderer,
	float volume,
	sample_t *samples
)
{
	(void) vsigrenderer;
	(void) volume;

	samples[ 0 ] = 0;
	samples[ 1 ] = 0;
}

void playptmod_end_sigrenderer(sigrenderer_t *vsigrenderer)
{
	playptmod_Free( vsigrenderer );
}

void playptmod_unload_sigdata(sigdata_t *vsigdata)
{
	free( vsigdata );
}
