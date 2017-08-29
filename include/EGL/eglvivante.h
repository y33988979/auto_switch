/****************************************************************************
*  
*    Copyright (c) 2005 - 2012 by Vivante Corp.  All rights reserved.
*  
*    The material in this file is confidential and contains trade secrets
*    of Vivante Corporation. This is proprietary information owned by
*    Vivante Corporation. No part of this work may be disclosed, 
*    reproduced, copied, transmitted, or used in any way for any purpose, 
*    without the express written permission of Vivante Corporation.
*  
*****************************************************************************/




/*
 * Vivante specific definitions and declarations for EGL library.
 */

#ifndef __eglvivante_h_
#define __eglvivante_h_

/*
    USE VDK

    This define enables the VDK linkage for EGL.
*/
#ifndef USE_VDK
# define USE_VDK    1
#endif


#define EGLAPIENTRY

#if USE_VDK
#if defined(_WIN32) || defined(__VC32__) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#include <windows.h>
#endif
/* VDK platform independent. */
#include <gc_vdk_types.h>
typedef vdkDisplay  EGLNativeDisplayType;
typedef vdkWindow   EGLNativeWindowType;
typedef vdkPixmap   EGLNativePixmapType;

#elif defined(_WIN32) || defined(__VC32__) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
/* Win32 and Windows CE platforms. */
#include <windows.h>
typedef HDC             EGLNativeDisplayType;
typedef HWND            EGLNativeWindowType;
typedef HBITMAP         EGLNativePixmapType;

#elif defined(LINUX) && defined(EGL_API_FB)
/* Linux platform for FBDEV. */
typedef struct _FBDisplay * EGLNativeDisplayType;
typedef struct _FBWindow *  EGLNativeWindowType;
typedef struct _FBPixmap *  EGLNativePixmapType;

#ifdef __cplusplus
extern "C" {
#endif

EGLNativeDisplayType
fbGetDisplay(
    void
    );

void
fbGetDisplayGeometry(
    EGLNativeDisplayType Display,
    int * Width,
    int * Height
    );

void
fbDestroyDisplay(
    EGLNativeDisplayType Display
    );

EGLNativeWindowType
fbCreateWindow(
    EGLNativeDisplayType Display,
    int X,
    int Y,
    int Width,
    int Height
    );

void
fbGetWindowGeometry(
    EGLNativeWindowType Window,
    int * X,
    int * Y,
    int * Width,
    int * Height
    );

void
fbDestroyWindow(
    EGLNativeWindowType Window
    );

EGLNativePixmapType
fbCreatePixmap(
    EGLNativeDisplayType Display,
    int Width,
    int Height
    );

void
fbGetPixmapGeometry(
    EGLNativePixmapType Pixmap,
    int * Width,
    int * Height
    );

void
fbDestroyPixmap(
    EGLNativePixmapType Pixmap
    );

#ifdef __cplusplus
}
#endif

#elif defined(ANDROID)

#if ANDROID_SDK_VERSION >= 7

#if ANDROID_SDK_VERSION >= 14
#   define ANDROID_NATIVE_WINDOW_H 1
#endif

#include <ui/egl/android_natives.h>

#ifdef __cplusplus
typedef android_native_window_t*        EGLNativeWindowType;
typedef egl_native_pixmap_t*            EGLNativePixmapType;
typedef void*                           EGLNativeDisplayType;
#else
typedef struct android_native_window_t* EGLNativeWindowType;
typedef struct egl_native_pixmap_t*     EGLNativePixmapType;
typedef void*                           EGLNativeDisplayType;
#endif

#else
#include <EGL/eglnatives.h>

typedef struct egl_native_window_t*     EGLNativeWindowType;
typedef struct egl_native_pixmap_t*     EGLNativePixmapType;
typedef void*                           EGLNativeDisplayType;
#endif
/** check by yanjianqing **/
#elif defined(EGL_API_HIGO)
#include <hi_go.h>
typedef HI_HANDLE   HLAYER;
typedef HI_HANDLE   HWINDOW;
typedef HI_HANDLE   HSURFACE;

typedef HLAYER      EGLNativeDisplayType;
typedef HWINDOW     EGLNativeWindowType;
typedef HSURFACE    EGLNativePixmapType;

#elif defined(EGL_API_DIRECTFB)
#include <directfb.h>

typedef IDirectFBDisplayLayer *EGLNativeDisplayType;
typedef IDirectFBSurface      *EGLNativeWindowType;
typedef IDirectFBSurface      *EGLNativePixmapType;
/************************************************************************/
#elif defined(LINUX)
/* X11 platform. */
#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef Display *   EGLNativeDisplayType;
typedef Window      EGLNativeWindowType;

#ifdef CUSTOM_PIXMAP
typedef void *      EGLNativePixmapType;
#else
typedef Pixmap      EGLNativePixmapType;
#endif /* CUSTOM_PIXMAP */

/* Rename some badly named X defines. */
#ifdef Status
#   define XStatus      int
#   undef Status
#endif
#ifdef Always
#   define XAlways      2
#   undef Always
#endif

#else

#error "Platform not recognized"

/* VOID */
typedef void *  EGLNativeDisplayType;
typedef void *  EGLNativeWindowType;
typedef void *  EGLNativePixmapType;

#endif

#ifdef __EGL_EXPORTS
#if defined(_WIN32) && !defined(__SCITECH_SNAP__)
#  define EGLAPI    __declspec(dllexport)
# else
#  define EGLAPI
# endif
#endif

#endif /* __eglvivante_h_ */
