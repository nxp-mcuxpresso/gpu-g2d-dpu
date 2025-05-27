/*
 *  Copyright (C) 2013-2016 Freescale Semiconductor, Inc.
 *  Copyright 2017-2025 NXP
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  'Software'), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sub license, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject
 *  to the following conditions:

 *  The above copyright notice and this permission notice (including the
 *  next paragraph) shall be included in all copies or substantial
 *  portions of the Software.

 *  THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 *  IN NO EVENT SHALL NXP AND/OR ITS SUPPLIERS BE LIABLE FOR ANY
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */


#ifndef __G2D_H__
#define __G2D_H__

/*******************************************************************************
* Definitions
******************************************************************************/
enum g2d_format
{
    G2D_RGB565               = 0,
    G2D_RGBA8888             = 1,
    G2D_RGBX8888             = 2,
    G2D_BGRA8888             = 3,
    G2D_BGRX8888             = 4,
    G2D_BGR565               = 5,

    G2D_ARGB8888             = 6,
    G2D_ABGR8888             = 7,
    G2D_XRGB8888             = 8,
    G2D_XBGR8888             = 9,
    G2D_RGB888               = 10,
    G2D_BGR888               = 11,

    G2D_RGBA5551             = 12,
    G2D_RGBX5551             = 13,
    G2D_BGRA5551             = 14,
    G2D_BGRX5551             = 15,

    G2D_RGBA1010102          = 16,

    G2D_GRAY8                = 19,

    G2D_NV12                 = 20,
    G2D_I420                 = 21,
    G2D_YV12                 = 22,
    G2D_NV21                 = 23,
    G2D_YUYV                 = 24,
    G2D_YVYU                 = 25,
    G2D_UYVY                 = 26,
    G2D_VYUY                 = 27,
    G2D_NV16                 = 28,
    G2D_NV61                 = 29,
};

enum g2d_blend_func
{
    G2D_ZERO                  = 0,
    G2D_ONE                   = 1,
    G2D_SRC_ALPHA             = 2,
    G2D_ONE_MINUS_SRC_ALPHA   = 3,
    G2D_DST_ALPHA             = 4,
    G2D_ONE_MINUS_DST_ALPHA   = 5,
    G2D_PRE_MULTIPLIED_ALPHA  = 0x10,
    G2D_DEMULTIPLY_OUT_ALPHA  = 0x20,
};

enum g2d_cap_mode
{
    G2D_BLEND                 = 0,
    G2D_DITHER                = 1,
    G2D_GLOBAL_ALPHA          = 2,
    G2D_BLEND_DIM             = 3,
    G2D_BLUR                  = 4,
    G2D_YUV_BT_601            = 5,
    G2D_YUV_BT_709            = 6,
    G2D_YUV_BT_601FR          = 7,
    G2D_YUV_BT_709FR          = 8,
    G2D_WARPING               = 9,
};

enum g2d_feature
{
    G2D_SCALING               = 0,
    G2D_ROTATION,
    G2D_SRC_YUV,
    G2D_DST_YUV,
    G2D_MULTI_SOURCE_BLT,
    G2D_FAST_CLEAR,
    G2D_WARP_DEWARP,
};

enum g2d_rotation
{
    G2D_ROTATION_0            = 0,
    G2D_ROTATION_90           = 1,
    G2D_ROTATION_180          = 2,
    G2D_ROTATION_270          = 3,
    G2D_FLIP_H                = 4,
    G2D_FLIP_V                = 5,
};

enum g2d_cache_mode
{
    G2D_CACHE_CLEAN           = 0,
    G2D_CACHE_FLUSH           = 1,
    G2D_CACHE_INVALIDATE      = 2,
};

enum g2d_status
{
    G2D_STATUS_FAIL           =-1,
    G2D_STATUS_OK             = 0,
    G2D_STATUS_NOT_SUPPORTED  = 1,
};

typedef unsigned int g2d_phys_addr_t;

struct g2d_surface
{
    enum g2d_format format;
    g2d_phys_addr_t planes[3];
    int left;
    int top;
    int right;
    int bottom;
    int stride;
    int width;
    int height;
    enum g2d_blend_func blendfunc;
    int global_alpha;
    int clrcolor;
    enum g2d_rotation rot;
};

struct g2d_buf
{
    void *buf_handle;
    void *buf_vaddr;
    g2d_phys_addr_t buf_paddr;
    int  buf_size;
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
int g2d_open(void **handle);
int g2d_close(void *handle);
int g2d_clear(void *handle, struct g2d_surface *area);
int g2d_blit(void *handle, struct g2d_surface *src, struct g2d_surface *dst);
int g2d_copy(void *handle, struct g2d_buf *d, struct g2d_buf* s, int size);
int g2d_enable(void *handle, enum g2d_cap_mode cap);
int g2d_disable(void *handle, enum g2d_cap_mode cap);
int g2d_cache_op(struct g2d_buf *buf, enum g2d_cache_mode op);
struct g2d_buf *g2d_alloc(int size, int cacheable);
int g2d_free(struct g2d_buf *buf);
int g2d_flush(void *handle);
int g2d_finish(void *handle);
int g2d_query_feature(void *handle, enum g2d_feature feature, int *available);

#endif
