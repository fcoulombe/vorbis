/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2001             *
 * by the XIPHOPHORUS Company http://www.xiph.org/                  *

 ********************************************************************

 function: predefined encoding modes; masking adjustments for low bitrate
 last mod: $Id $

 ********************************************************************/

#ifndef _V_MASKADJ_A_H_
#define _V_MASKADJ_A_H_

#include <stdio.h>
#include "vorbis/codec.h"
#include "backends.h"

static vp_attenblock _vp_tonemask_consbass_A={
  {{-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*63*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*88*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*125*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*175*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*250*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*350*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*500*/
  {-40.f,-40.f,-40.f,-45.f,-55.f,-65.f,-75.f,-85.f,-95.f,-105.f,-115.f}, /*700*/
  
  {-35.f,-35.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*1000*/
  {-35.f,-35.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*1400*/
  {-40.f,-40.f,-40.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*2000*/
  {-40.f,-40.f,-40.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*2800*/
  {-35.f,-35.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*4000*/
  {-35.f,-35.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*5600*/
  
  {-30.f,-30.f,-33.f,-35.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*8000*/
  {-30.f,-30.f,-33.f,-35.f,-35.f,-45.f,-50.f,-60.f,-70.f,-90.f,-100.f}, /*11500*/
  {-24.f,-24.f,-26.f,-32.f,-32.f,-42.f,-50.f,-60.f,-70.f,-90.f,-100.f}, /*16000*/
}};

static vp_attenblock _vp_tonemask_A={

  {{-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*63*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*88*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*125*/
  
  
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*175*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*250*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*350*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*500*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*700*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*1000*/
  {-30.f,-30.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*1400*/
  {-40.f,-40.f,-40.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*2000*/
  {-40.f,-40.f,-40.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*2800*/
  {-40.f,-40.f,-40.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*4000*/
  
  {-30.f,-35.f,-35.f,-40.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*5600*/
  
  {-30.f,-30.f,-33.f,-35.f,-40.f,-50.f,-60.f,-70.f,-80.f,-90.f,-100.f}, /*8000*/
  {-30.f,-30.f,-33.f,-35.f,-40.f,-45.f,-50.f,-60.f,-70.f,-85.f,-100.f}, /*11500*/
  {-24.f,-24.f,-26.f,-32.f,-32.f,-42.f,-50.f,-60.f,-70.f,-85.f,-100.f}, /*16000*/
}};

static vp_attenblock _vp_peakatt_A={
  {{-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*63*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*88*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*125*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*175*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*250*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*350*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*500*/
  {-10.f,-10.f,-10.f,-10.f,-14.f,-14.f,-14.f,-20.f,-26.f,-32.f,-40.f},/*700*/
  {-10.f,-10.f,-10.f,-10.f,-14.f,-14.f,-14.f,-20.f,-22.f,-32.f,-40.f},/*1000*/
  {-10.f,-10.f,-10.f,-10.f,-14.f,-14.f,-16.f,-20.f,-22.f,-32.f,-40.f},/*1400*/
  {-10.f,-10.f,-10.f,-10.f,-14.f,-14.f,-16.f,-20.f,-22.f,-32.f,-40.f},/*2000*/
  {-10.f,-10.f,-10.f,-10.f,-14.f,-14.f,-16.f,-20.f,-22.f,-32.f,-40.f},/*2400*/
  {-10.f,-10.f,-10.f,-10.f,-14.f,-14.f,-16.f,-20.f,-22.f,-32.f,-40.f},/*4000*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-11.f,-12.f,-13.f,-22.f,-32.f,-40.f},/*5600*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-11.f,-12.f,-13.f,-22.f,-32.f,-40.f},/*8000*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-11.f,-22.f,-32.f,-40.f},/*11500*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-20.f,-32.f,-40.f},/*16000*/
}};

static vp_attenblock _vp_peakatt_B={
  {{-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*63*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*88*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*125*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*175*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*250*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*350*/
  {-14.f,-20.f,-20.f,-20.f,-26.f,-32.f,-32.f,-32.f,-32.f,-32.f,-40.f},/*500*/
  {-10.f,-10.f,-10.f,-14.f,-20.f,-20.f,-20.f,-24.f,-26.f,-32.f,-40.f},/*700*/
  {-10.f,-10.f,-10.f,-14.f,-20.f,-20.f,-20.f,-24.f,-26.f,-32.f,-40.f},/*1000*/
  {-10.f,-10.f,-10.f,-14.f,-20.f,-20.f,-20.f,-24.f,-26.f,-32.f,-40.f},/*1400*/
  {-10.f,-10.f,-10.f,-14.f,-20.f,-20.f,-20.f,-24.f,-26.f,-32.f,-40.f},/*2000*/
  {-10.f,-10.f,-10.f,-14.f,-20.f,-20.f,-20.f,-24.f,-26.f,-32.f,-40.f},/*2800*/
  {-10.f,-10.f,-10.f,-10.f,-18.f,-20.f,-20.f,-22.f,-24.f,-32.f,-40.f},/*4000*/
  {-10.f,-10.f,-10.f,-10.f,-12.f,-14.f,-16.f,-18.f,-22.f,-32.f,-40.f},/*5600*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-11.f,-12.f,-13.f,-22.f,-32.f,-40.f},/*8000*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-11.f,-22.f,-32.f,-40.f},/*11500*/
  {-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-10.f,-20.f,-32.f,-40.f},/*16000*/
}};

static vp_attenblock _vp_peakatt_D={
  {{-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*63*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*88*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*125*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*170*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*250*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*350*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*500*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*700*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*1000*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*1400*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*2000*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*2800*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*4000*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*5600*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*8000*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*11500*/
   {-14.f,-20.f,-24.f,-26.f,-32.f,-34.f,-36.f,-38.f,-40.f,-40.f,-40.f},/*16600*/
  }};


#endif
