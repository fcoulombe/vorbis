/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS SOURCE IS GOVERNED BY *
 * THE GNU LESSER/LIBRARY PUBLIC LICENSE, WHICH IS INCLUDED WITH    *
 * THIS SOURCE. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.        *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2001             *
 * by the XIPHOPHORUS Company http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: stdio-based convenience library for opening/seeking/decoding
 last mod: $Id: vorbisfile.h,v 1.12 2001/02/02 03:51:54 xiphmont Exp $

 ********************************************************************/

#ifndef _OV_FILE_H_
#define _OV_FILE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdio.h>
#include "codec.h"

/* The function prototypes for the callbacks are basically the same as for
 * the stdio functions fread, fseek, fclose, ftell. 
 * The one difference is that the FILE * arguments have been replaced with
 * a void * - this is to be used as a pointer to whatever internal data these
 * functions might need. In the stdio case, it's just a FILE * cast to a void *
 * 
 * If you use other functions, check the docs for these functions and return
 * the right values. For seek_func(), you *MUST* return -1 if the stream is
 * unseekable
 */
typedef struct {
  size_t (*read_func)  (void *ptr, size_t size, size_t nmemb, void *datasource);
  int    (*seek_func)  (void *datasource, ogg_int64_t offset, int whence);
  int    (*close_func) (void *datasource);
  long   (*tell_func)  (void *datasource);
} ov_callbacks;


typedef struct OggVorbis_File {
  void             *datasource; /* Pointer to a FILE *, etc. */
  int              seekable;
  ogg_int64_t          offset;
  ogg_int64_t          end;
  ogg_sync_state   oy; 

  /* If the FILE handle isn't seekable (eg, a pipe), only the current
     stream appears */
  int              links;
  ogg_int64_t          *offsets;
  ogg_int64_t          *dataoffsets;
  long             *serialnos;
  ogg_int64_t          *pcmlengths;
  vorbis_info      *vi;
  vorbis_comment   *vc;

  /* Decoding working state local storage */
  ogg_int64_t          pcm_offset;
  int              decode_ready;
  long             current_serialno;
  int              current_link;

  double           bittrack;
  double           samptrack;

  ogg_stream_state os; /* take physical pages, weld into a logical
                          stream of packets */
  vorbis_dsp_state vd; /* central working state for the packet->PCM decoder */
  vorbis_block     vb; /* local working space for packet->PCM decode */

  ov_callbacks callbacks;

} OggVorbis_File;

extern int ov_clear(OggVorbis_File *vf);
extern int ov_open(FILE *f,OggVorbis_File *vf,char *initial,long ibytes);
extern int ov_open_callbacks(void *datasource, OggVorbis_File *vf,
		char *initial, long ibytes, ov_callbacks callbacks);

extern long ov_bitrate(OggVorbis_File *vf,int i);
extern long ov_bitrate_instant(OggVorbis_File *vf);
extern long ov_streams(OggVorbis_File *vf);
extern long ov_seekable(OggVorbis_File *vf);
extern long ov_serialnumber(OggVorbis_File *vf,int i);

extern ogg_int64_t ov_raw_total(OggVorbis_File *vf,int i);
extern ogg_int64_t ov_pcm_total(OggVorbis_File *vf,int i);
extern double ov_time_total(OggVorbis_File *vf,int i);

extern int ov_raw_seek(OggVorbis_File *vf,long pos);
extern int ov_pcm_seek(OggVorbis_File *vf,ogg_int64_t pos);
extern int ov_pcm_seek_page(OggVorbis_File *vf,ogg_int64_t pos);
extern int ov_time_seek(OggVorbis_File *vf,double pos);
extern int ov_time_seek_page(OggVorbis_File *vf,double pos);

extern ogg_int64_t ov_raw_tell(OggVorbis_File *vf);
extern ogg_int64_t ov_pcm_tell(OggVorbis_File *vf);
extern double ov_time_tell(OggVorbis_File *vf);

extern vorbis_info *ov_info(OggVorbis_File *vf,int link);
extern vorbis_comment *ov_comment(OggVorbis_File *vf,int link);

extern long ov_read(OggVorbis_File *vf,char *buffer,int length,
		    int bigendianp,int word,int sgned,int *bitstream);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif


