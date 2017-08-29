
/* png.h - header file for PNG reference library
 *
 * libpng version 1.4.0 - January 3, 2010
 * Copyright (c) 1998-2010 Glenn Randers-Pehrson
 * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)
 * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)
 *
 * This code is released under the libpng license (See LICENSE, below)
 *
 * Authors and maintainers:
 *  libpng versions 0.71, May 1995, through 0.88, January 1996: Guy Schalnat
 *  libpng versions 0.89c, June 1996, through 0.96, May 1997: Andreas Dilger
 *  libpng versions 0.97, January 1998, through 1.4.0 - January 3, 2010: Glenn
 *  See also "Contributing Authors", below.
 *
 * Note about libpng version numbers:
 *
 *    Due to various miscommunications, unforeseen code incompatibilities
 *    and occasional factors outside the authors' control, version numbering
 *    on the library has not always been consistent and straightforward.
 *    The following table summarizes matters since version 0.89c, which was
 *    the first widely used release:
 *
 *    source                 png.h  png.h  shared-lib
 *    version                string   int  version
 *    -------                ------ -----  ----------
 *    0.89c "1.0 beta 3"     0.89      89  1.0.89
 *    0.90  "1.0 beta 4"     0.90      90  0.90  [should have been 2.0.90]
 *    0.95  "1.0 beta 5"     0.95      95  0.95  [should have been 2.0.95]
 *    0.96  "1.0 beta 6"     0.96      96  0.96  [should have been 2.0.96]
 *    0.97b "1.00.97 beta 7" 1.00.97   97  1.0.1 [should have been 2.0.97]
 *    0.97c                  0.97      97  2.0.97
 *    0.98                   0.98      98  2.0.98
 *    0.99                   0.99      98  2.0.99
 *    0.99a-m                0.99      99  2.0.99
 *    1.00                   1.00     100  2.1.0 [100 should be 10000]
 *    1.0.0      (from here on, the   100  2.1.0 [100 should be 10000]
 *    1.0.1       png.h string is   10001  2.1.0
 *    1.0.1a-e    identical to the  10002  from here on, the shared library
 *    1.0.2       source version)   10002  is 2.V where V is the source code
 *    1.0.2a-b                      10003  version, except as noted.
 *    1.0.3                         10003
 *    1.0.3a-d                      10004
 *    1.0.4                         10004
 *    1.0.4a-f                      10005
 *    1.0.5 (+ 2 patches)           10005
 *    1.0.5a-d                      10006
 *    1.0.5e-r                      10100 (not source compatible)
 *    1.0.5s-v                      10006 (not binary compatible)
 *    1.0.6 (+ 3 patches)           10006 (still binary incompatible)
 *    1.0.6d-f                      10007 (still binary incompatible)
 *    1.0.6g                        10007
 *    1.0.6h                        10007  10.6h (testing xy.z so-numbering)
 *    1.0.6i                        10007  10.6i
 *    1.0.6j                        10007  2.1.0.6j (incompatible with 1.0.0)
 *    1.0.7beta11-14        DLLNUM  10007  2.1.0.7beta11-14 (binary compatible)
 *    1.0.7beta15-18           1    10007  2.1.0.7beta15-18 (binary compatible)
 *    1.0.7rc1-2               1    10007  2.1.0.7rc1-2 (binary compatible)
 *    1.0.7                    1    10007  (still compatible)
 *    1.0.8beta1-4             1    10008  2.1.0.8beta1-4
 *    1.0.8rc1                 1    10008  2.1.0.8rc1
 *    1.0.8                    1    10008  2.1.0.8
 *    1.0.9beta1-6             1    10009  2.1.0.9beta1-6
 *    1.0.9rc1                 1    10009  2.1.0.9rc1
 *    1.0.9beta7-10            1    10009  2.1.0.9beta7-10
 *    1.0.9rc2                 1    10009  2.1.0.9rc2
 *    1.0.9                    1    10009  2.1.0.9
 *    1.0.10beta1              1    10010  2.1.0.10beta1
 *    1.0.10rc1                1    10010  2.1.0.10rc1
 *    1.0.10                   1    10010  2.1.0.10
 *    1.0.11beta1-3            1    10011  2.1.0.11beta1-3
 *    1.0.11rc1                1    10011  2.1.0.11rc1
 *    1.0.11                   1    10011  2.1.0.11
 *    1.0.12beta1-2            2    10012  2.1.0.12beta1-2
 *    1.0.12rc1                2    10012  2.1.0.12rc1
 *    1.0.12                   2    10012  2.1.0.12
 *    1.1.0a-f                 -    10100  2.1.1.0a-f (branch abandoned)
 *    1.2.0beta1-2             2    10200  2.1.2.0beta1-2
 *    1.2.0beta3-5             3    10200  3.1.2.0beta3-5
 *    1.2.0rc1                 3    10200  3.1.2.0rc1
 *    1.2.0                    3    10200  3.1.2.0
 *    1.2.1beta1-4             3    10201  3.1.2.1beta1-4
 *    1.2.1rc1-2               3    10201  3.1.2.1rc1-2
 *    1.2.1                    3    10201  3.1.2.1
 *    1.2.2beta1-6            12    10202  12.so.0.1.2.2beta1-6
 *    1.0.13beta1             10    10013  10.so.0.1.0.13beta1
 *    1.0.13rc1               10    10013  10.so.0.1.0.13rc1
 *    1.2.2rc1                12    10202  12.so.0.1.2.2rc1
 *    1.0.13                  10    10013  10.so.0.1.0.13
 *    1.2.2                   12    10202  12.so.0.1.2.2
 *    1.2.3rc1-6              12    10203  12.so.0.1.2.3rc1-6
 *    1.2.3                   12    10203  12.so.0.1.2.3
 *    1.2.4beta1-3            13    10204  12.so.0.1.2.4beta1-3
 *    1.0.14rc1               13    10014  10.so.0.1.0.14rc1
 *    1.2.4rc1                13    10204  12.so.0.1.2.4rc1
 *    1.0.14                  10    10014  10.so.0.1.0.14
 *    1.2.4                   13    10204  12.so.0.1.2.4
 *    1.2.5beta1-2            13    10205  12.so.0.1.2.5beta1-2
 *    1.0.15rc1-3             10    10015  10.so.0.1.0.15rc1-3
 *    1.2.5rc1-3              13    10205  12.so.0.1.2.5rc1-3
 *    1.0.15                  10    10015  10.so.0.1.0.15
 *    1.2.5                   13    10205  12.so.0.1.2.5
 *    1.2.6beta1-4            13    10206  12.so.0.1.2.6beta1-4
 *    1.0.16                  10    10016  10.so.0.1.0.16
 *    1.2.6                   13    10206  12.so.0.1.2.6
 *    1.2.7beta1-2            13    10207  12.so.0.1.2.7beta1-2
 *    1.0.17rc1               10    10017  12.so.0.1.0.17rc1
 *    1.2.7rc1                13    10207  12.so.0.1.2.7rc1
 *    1.0.17                  10    10017  12.so.0.1.0.17
 *    1.2.7                   13    10207  12.so.0.1.2.7
 *    1.2.8beta1-5            13    10208  12.so.0.1.2.8beta1-5
 *    1.0.18rc1-5             10    10018  12.so.0.1.0.18rc1-5
 *    1.2.8rc1-5              13    10208  12.so.0.1.2.8rc1-5
 *    1.0.18                  10    10018  12.so.0.1.0.18
 *    1.2.8                   13    10208  12.so.0.1.2.8
 *    1.2.9beta1-3            13    10209  12.so.0.1.2.9beta1-3
 *    1.2.9beta4-11           13    10209  12.so.0.9[.0]
 *    1.2.9rc1                13    10209  12.so.0.9[.0]
 *    1.2.9                   13    10209  12.so.0.9[.0]
 *    1.2.10beta1-7           13    10210  12.so.0.10[.0]
 *    1.2.10rc1-2             13    10210  12.so.0.10[.0]
 *    1.2.10                  13    10210  12.so.0.10[.0]
 *    1.4.0beta1-5            14    10400  14.so.0.0[.0]
 *    1.2.11beta1-4           13    10211  12.so.0.11[.0]
 *    1.4.0beta7-8            14    10400  14.so.0.0[.0]
 *    1.2.11                  13    10211  12.so.0.11[.0]
 *    1.2.12                  13    10212  12.so.0.12[.0]
 *    1.4.0beta9-14           14    10400  14.so.0.0[.0]
 *    1.2.13                  13    10213  12.so.0.13[.0]
 *    1.4.0beta15-36          14    10400  14.so.0.0[.0]
 *    1.4.0beta37-87          14    10400  14.so.14.0[.0]
 *    1.4.0rc01               14    10400  14.so.14.0[.0]
 *    1.4.0beta88-109         14    10400  14.so.14.0[.0]
 *    1.4.0rc02-08            14    10400  14.so.14.0[.0]
 *    1.4.0                   14    10400  14.so.14.0[.0]
 *
 *    Henceforth the source version will match the shared-library major
 *    and minor numbers; the shared-library major version number will be
 *    used for changes in backward compatibility, as it is intended.  The
 *    HIPNG_LIBHIPNG_VER macro, which is not used within libpng but is available
 *    for applications, is an unsigned integer of the form xyyzz corresponding
 *    to the source version x.y.z (leading zeros in y and z).  Beta versions
 *    were given the previous public release number plus a letter, until
 *    version 1.0.6j; from then on they were given the upcoming public
 *    release number plus "betaNN" or "rcN".
 *
 *    Binary incompatibility exists only when applications make direct access
 *    to the info_ptr or hipng_ptr members through png.h, and the compiled
 *    application is loaded with a different version of the library.
 *
 *    DLLNUM will change each time there are forward or backward changes
 *    in binary compatibility (e.g., when a new feature is added).
 *
 * See libpng.txt or libpng.3 for more information.  The PNG specification
 * is available as a W3C Recommendation and as an ISO Specification,
 * <http://www.w3.org/TR/2003/REC-PNG-20031110/
 */

/*
 * COPYRIGHT NOTICE, DISCLAIMER, and LICENSE:
 *
 * If you modify libpng you may insert additional notices immediately following
 * this sentence.
 *
 * This code is released under the libpng license.
 *
 * libpng versions 1.2.6, August 15, 2004, through 1.4.0, January 3, 2010, are
 * Copyright (c) 2004, 2006-2010 Glenn Randers-Pehrson, and are
 * distributed according to the same disclaimer and license as libpng-1.2.5
 * with the following individual added to the list of Contributing Authors:
 *
 *    Cosmin Truta
 *
 * libpng versions 1.0.7, July 1, 2000, through 1.2.5, October 3, 2002, are
 * Copyright (c) 2000-2002 Glenn Randers-Pehrson, and are
 * distributed according to the same disclaimer and license as libpng-1.0.6
 * with the following individuals added to the list of Contributing Authors:
 *
 *    Simon-Pierre Cadieux
 *    Eric S. Raymond
 *    Gilles Vollant
 *
 * and with the following additions to the disclaimer:
 *
 *    There is no warranty against interference with your enjoyment of the
 *    library or against infringement.  There is no warranty that our
 *    efforts or the library will fulfill any of your particular purposes
 *    or needs.  This library is provided with all faults, and the entire
 *    risk of satisfactory quality, performance, accuracy, and effort is with
 *    the user.
 *
 * libpng versions 0.97, January 1998, through 1.0.6, March 20, 2000, are
 * Copyright (c) 1998, 1999, 2000 Glenn Randers-Pehrson, and are
 * distributed according to the same disclaimer and license as libpng-0.96,
 * with the following individuals added to the list of Contributing Authors:
 *
 *    Tom Lane
 *    Glenn Randers-Pehrson
 *    Willem van Schaik
 *
 * libpng versions 0.89, June 1996, through 0.96, May 1997, are
 * Copyright (c) 1996, 1997 Andreas Dilger
 * Distributed according to the same disclaimer and license as libpng-0.88,
 * with the following individuals added to the list of Contributing Authors:
 *
 *    John Bowler
 *    Kevin Bracey
 *    Sam Bushell
 *    Magnus Holmgren
 *    Greg Roelofs
 *    Tom Tanner
 *
 * libpng versions 0.5, May 1995, through 0.88, January 1996, are
 * Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.
 *
 * For the purposes of this copyright and license, "Contributing Authors"
 * is defined as the following set of individuals:
 *
 *    Andreas Dilger
 *    Dave Martindale
 *    Guy Eric Schalnat
 *    Paul Schmidt
 *    Tim Wegner
 *
 * The PNG Reference Library is supplied "AS IS".  The Contributing Authors
 * and Group 42, Inc. disclaim all warranties, expressed or implied,
 * including, without limitation, the warranties of merchantability and of
 * fitness for any purpose.  The Contributing Authors and Group 42, Inc.
 * assume no liability for direct, indirect, incidental, special, exemplary,
 * or consequential damages, which may result from the use of the PNG
 * Reference Library, even if advised of the possibility of such damage.
 *
 * Permission is hereby granted to use, copy, modify, and distribute this
 * source code, or portions hereof, for any purpose, without fee, subject
 * to the following restrictions:
 *
 * 1. The origin of this source code must not be misrepresented.
 *
 * 2. Altered versions must be plainly marked as such and
 * must not be misrepresented as being the original source.
 *
 * 3. This Copyright notice may not be removed or altered from
 *    any source or altered source distribution.
 *
 * The Contributing Authors and Group 42, Inc. specifically permit, without
 * fee, and encourage the use of this source code as a component to
 * supporting the PNG file format in commercial products.  If you use this
 * source code in a product, acknowledgment is not required but would be
 * appreciated.
 */

/*
 * A "hipng_get_copyright" function is available, for convenient use in "about"
 * boxes and the like:
 *
 *     printf("%s",hipng_get_copyright(NULL));
 *
 * Also, the PNG logo (in PNG format, of course) is supplied in the
 * files "pngbar.png" and "pngbar.jpg (88x31) and "pngnow.png" (98x31).
 */

/*
 * Libpng is OSI Certified Open Source Software.  OSI Certified is a
 * certification mark of the Open Source Initiative.
 */

/*
 * The contributing authors would like to thank all those who helped
 * with testing, bug fixes, and patience.  This wouldn't have been
 * possible without all of you.
 *
 * Thanks to Frank J. T. Wojcik for helping with the documentation.
 */

/*
 * Y2K compliance in libpng:
 * =========================
 *
 *    January 3, 2010
 *
 *    Since the PNG Development group is an ad-hoc body, we can't make
 *    an official declaration.
 *
 *    This is your unofficial assurance that libpng from version 0.71 and
 *    upward through 1.4.0 are Y2K compliant.  It is my belief that earlier
 *    versions were also Y2K compliant.
 *
 *    Libpng only has three year fields.  One is a 2-byte unsigned integer
 *    that will hold years up to 65535.  The other two hold the date in text
 *    format, and will hold years up to 9999.
 *
 *    The integer is
 *        "hipng_uint_16 year" in hipng_time_struct.
 *
 *    The strings are
 *        "hipng_charp time_buffer" in hipng_struct and
 *        "near_time_buffer", which is a local character string in png.c.
 *
 *    There are seven time-related functions:
 *        png.c: hipng_convert_to_rfc_1123() in png.c
 *          (formerly hipng_convert_to_rfc_1152() in error)
 *        hipng_convert_from_struct_tm() in pngwrite.c, called in pngwrite.c
 *        hipng_convert_from_time_t() in pngwrite.c
 *        hipng_get_tIME() in pngget.c
 *        hipng_handle_tIME() in pngrutil.c, called in pngread.c
 *        hipng_set_tIME() in pngset.c
 *        hipng_write_tIME() in pngwutil.c, called in pngwrite.c
 *
 *    All handle dates properly in a Y2K environment.  The
 *    hipng_convert_from_time_t() function calls gmtime() to convert from system
 *    clock time, which returns (year - 1900), which we properly convert to
 *    the full 4-digit year.  There is a possibility that applications using
 *    libpng are not passing 4-digit years into the hipng_convert_to_rfc_1123()
 *    function, or that they are incorrectly passing only a 2-digit year
 *    instead of "year - 1900" into the hipng_convert_from_struct_tm() function,
 *    but this is not under our control.  The libpng documentation has always
 *    stated that it works with 4-digit years, and the APIs have been
 *    documented as such.
 *
 *    The tIME chunk itself is also Y2K compliant.  It uses a 2-byte unsigned
 *    integer to hold the year, and can hold years as large as 65535.
 *
 *    zlib, upon which libpng depends, is also Y2K compliant.  It contains
 *    no date-related code.
 *
 *       Glenn Randers-Pehrson
 *       libpng maintainer
 *       PNG Development Group
 */

#ifndef HIPNG_H
#define HIPNG_H

/* This is not the place to learn how to use libpng.  The file libpng.txt
 * describes how to use libpng, and the file example.c summarizes it
 * with some code on which to build.  This file is useful for looking
 * at the actual function definitions and structure components.
 */

/* Version information for png.h - this should match the version in png.c */
#define HIPNG_LIBPNG_VER_STRING "1.4.0"
#define HIPNG_HEADER_VERSION_STRING \
   " libpng version 1.4.0 - January 3, 2010\n"

#define HIPNG_LIBPNG_VER_SONUM   14
#define HIPNG_LIBPNG_VER_DLLNUM  14

/* These should match the first 3 components of HIPNG_LIBHIPNG_VER_STRING: */
#define HIPNG_LIBPNG_VER_MAJOR   1
#define HIPNG_LIBPNG_VER_MINOR   4
#define HIPNG_LIBPNG_VER_RELEASE 0
/* This should match the numeric part of the final component of
 * HIPNG_LIBHIPNG_VER_STRING, omitting any leading zero:
 */

#define HIPNG_LIBPNG_VER_BUILD  0

/* Release Status */
#define HIPNG_LIBPNG_BUILD_ALPHA    1
#define HIPNG_LIBPNG_BUILD_BETA     2
#define HIPNG_LIBPNG_BUILD_RC       3
#define HIPNG_LIBPNG_BUILD_STABLE   4
#define HIPNG_LIBPNG_BUILD_RELEASE_STATUS_MASK 7

/* Release-Specific Flags */
#define HIPNG_LIBPNG_BUILD_PATCH    8 /* Can be OR'ed with
                                       HIPNG_LIBHIPNG_BUILD_STABLE only */
#define HIPNG_LIBPNG_BUILD_PRIVATE 16 /* Cannot be OR'ed with
                                       HIPNG_LIBHIPNG_BUILD_SPECIAL */
#define HIPNG_LIBPNG_BUILD_SPECIAL 32 /* Cannot be OR'ed with
                                       HIPNG_LIBHIPNG_BUILD_PRIVATE */

#define HIPNG_LIBPNG_BUILD_BASE_TYPE HIPNG_LIBHIPNG_BUILD_BETA

/* Careful here.  At one time, Guy wanted to use 082, but that would be octal.
 * We must not include leading zeros.
 * Versions 0.7 through 1.0.0 were in the range 0 to 100 here (only
 * version 1.0.0 was mis-numbered 100 instead of 10000).  From
 * version 1.0.1 it's    xxyyzz, where x=major, y=minor, z=release
 */
#define HIPNG_LIBPNG_VER 10400 /* 1.4.0 */

#ifndef HIPNG_VERSION_INFO_ONLY
/* Include the compression library's header */
#include "zlib.h"
#endif

#ifdef AIX
#define jmpbuf __jmpbuf
#endif

/* Include all user configurable info, including optional assembler routines */
#include "hipngconf.h"

/*
 * Added at libpng-1.2.8
 *
 * Ref MSDN: Private as priority over Special
 * VS_FF_PRIVATEBUILD File *was not* built using standard release
 * procedures. If this value is given, the StringFileInfo block must
 * contain a PrivateBuild string.
 *
 * VS_FF_SPECIALBUILD File *was* built by the original company using
 * standard release procedures but is a variation of the standard
 * file of the same version number. If this value is given, the
 * StringFileInfo block must contain a SpecialBuild string.
 */

#ifdef HIPNG_USER_PRIVATEBUILD
#  define HIPNG_LIBPNG_BUILD_TYPE \
          (HIPNG_LIBHIPNG_BUILD_BASE_TYPE | HIPNG_LIBHIPNG_BUILD_PRIVATE)
#else
#  ifdef HIPNG_LIBHIPNG_SPECIALBUILD
#    define HIPNG_LIBPNG_BUILD_TYPE \
            (HIPNG_LIBHIPNG_BUILD_BASE_TYPE | HIPNG_LIBHIPNG_BUILD_SPECIAL)
#  else
#    define HIPNG_LIBPNG_BUILD_TYPE (HIPNG_LIBHIPNG_BUILD_BASE_TYPE)
#  endif
#endif

#ifndef HIPNG_VERSION_INFO_ONLY

/* Inhibit C++ name-mangling for libpng functions but not for system calls. */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* This file is arranged in several sections.  The first section contains
 * structure and type definitions.  The second section contains the external
 * library functions, while the third has the internal library functions,
 * which applications aren't expected to use directly.
 */

/* Variables declared in png.c - only it needs to define HIPNG_NO_EXTERN */
#if !defined(HIPNG_NO_EXTERN) || defined(HIPNG_ALWAYS_EXTERN)
/* Version information for C files, stored in png.c.  This had better match
 * the version above.
 */
#define hipng_libpng_ver hipng_get_header_ver(NULL)

#endif /* HIPNG_NO_EXTERN */

/* Three color definitions.  The order of the red, green, and blue, (and the
 * exact size) is not important, although the size of the fields need to
 * be hipng_byte or hipng_uint_16 (as defined below).
 */
typedef struct hipng_color_struct
{
   hipng_byte red;
   hipng_byte green;
   hipng_byte blue;
} hipng_color;
typedef hipng_color FAR * hipng_colorp;
typedef hipng_color FAR * FAR * hipng_colorpp;

typedef struct hipng_color_16_struct
{
   hipng_byte index;    /* used for palette files */
   hipng_uint_16 red;   /* for use in red green blue files */
   hipng_uint_16 green;
   hipng_uint_16 blue;
   hipng_uint_16 gray;  /* for use in grayscale files */
} hipng_color_16;
typedef hipng_color_16 FAR * hipng_color_16p;
typedef hipng_color_16 FAR * FAR * hipng_color_16pp;

typedef struct hipng_color_8_struct
{
   hipng_byte red;   /* for use in red green blue files */
   hipng_byte green;
   hipng_byte blue;
   hipng_byte gray;  /* for use in grayscale files */
   hipng_byte alpha; /* for alpha channel files */
} hipng_color_8;
typedef hipng_color_8 FAR * hipng_color_8p;
typedef hipng_color_8 FAR * FAR * hipng_color_8pp;

/*
 * The following two structures are used for the in-core representation
 * of sPLT chunks.
 */
typedef struct hipng_sPLT_entry_struct
{
   hipng_uint_16 red;
   hipng_uint_16 green;
   hipng_uint_16 blue;
   hipng_uint_16 alpha;
   hipng_uint_16 frequency;
} hipng_sPLT_entry;
typedef hipng_sPLT_entry FAR * hipng_sPLT_entryp;
typedef hipng_sPLT_entry FAR * FAR * hipng_sPLT_entrypp;

/*  When the depth of the sPLT palette is 8 bits, the color and alpha samples
 *  occupy the LSB of their respective members, and the MSB of each member
 *  is zero-filled.  The frequency member always occupies the full 16 bits.
 */

typedef struct hipng_sPLT_struct
{
   hipng_charp name;           /* palette name */
   hipng_byte depth;           /* depth of palette samples */
   hipng_sPLT_entryp entries;  /* palette entries */
   hipng_int_32 nentries;      /* number of palette entries */
} hipng_sPLT_t;
typedef hipng_sPLT_t FAR * hipng_sPLT_tp;
typedef hipng_sPLT_t FAR * FAR * hipng_sPLT_tpp;

#ifdef HIPNG_TEXT_SUPPORTED
/* hipng_text holds the contents of a text/ztxt/itxt chunk in a PNG file,
 * and whether that contents is compressed or not.  The "key" field
 * points to a regular zero-terminated C string.  The "text", "lang", and
 * "lang_key" fields can be regular C strings, empty strings, or NULL pointers.
 * However, the * structure returned by hipng_get_text() will always contain
 * regular zero-terminated C strings (possibly empty), never NULL pointers,
 * so they can be safely used in printf() and other string-handling functions.
 */
typedef struct hipng_text_struct
{
   int  compression;       /* compression value:
                             -1: tEXt, none
                              0: zTXt, deflate
                              1: iTXt, none
                              2: iTXt, deflate  */
   hipng_charp key;          /* keyword, 1-79 character description of "text" */
   hipng_charp text;         /* comment, may be an empty string (ie "")
                              or a NULL pointer */
   hipng_size_t text_length; /* length of the text string */
#ifdef HIPNG_iTXt_SUPPORTED
   hipng_size_t itxt_length; /* length of the itxt string */
   hipng_charp lang;         /* language code, 0-79 characters
                              or a NULL pointer */
   hipng_charp lang_key;     /* keyword translated UTF-8 string, 0 or more
                              chars or a NULL pointer */
#endif
} hipng_text;
typedef hipng_text FAR * hipng_textp;
typedef hipng_text FAR * FAR * hipng_textpp;
#endif

/* Supported compression types for text in PNG files (tEXt, and zTXt).
 * The values of the HIPNG_TEXT_COMPRESSION_ defines should NOT be changed. */
#define HIPNG_TEXT_COMPRESSION_NONE_WR -3
#define HIPNG_TEXT_COMPRESSION_zTXt_WR -2
#define HIPNG_TEXT_COMPRESSION_NONE    -1
#define HIPNG_TEXT_COMPRESSION_zTXt     0
#define HIPNG_ITXT_COMPRESSION_NONE     1
#define HIPNG_ITXT_COMPRESSION_zTXt     2
#define HIPNG_TEXT_COMPRESSION_LAST     3  /* Not a valid value */

/* hipng_time is a way to hold the time in an machine independent way.
 * Two conversions are provided, both from time_t and struct tm.  There
 * is no portable way to convert to either of these structures, as far
 * as I know.  If you know of a portable way, send it to me.  As a side
 * note - PNG has always been Year 2000 compliant!
 */
typedef struct hipng_time_struct
{
   hipng_uint_16 year; /* full year, as in, 1995 */
   hipng_byte month;   /* month of year, 1 - 12 */
   hipng_byte day;     /* day of month, 1 - 31 */
   hipng_byte hour;    /* hour of day, 0 - 23 */
   hipng_byte minute;  /* minute of hour, 0 - 59 */
   hipng_byte second;  /* second of minute, 0 - 60 (for leap seconds) */
} hipng_time;
typedef hipng_time FAR * hipng_timep;
typedef hipng_time FAR * FAR * hipng_timepp;

#if defined(HIPNG_UNKNOWN_CHUNKS_SUPPORTED) || \
 defined(HIPNG_HANDLE_AS_UNKNOWN_SUPPORTED)
/* hipng_unknown_chunk is a structure to hold queued chunks for which there is
 * no specific support.  The idea is that we can use this to queue
 * up private chunks for output even though the library doesn't actually
 * know about their semantics.
 */
typedef struct hipng_unknown_chunk_t
{
    hipng_byte name[5];
    hipng_byte *data;
    hipng_size_t size;

    /* libpng-using applications should NOT directly modify this byte. */
    hipng_byte location; /* mode of operation at read time */
}
hipng_unknown_chunk;
typedef hipng_unknown_chunk FAR * hipng_unknown_chunkp;
typedef hipng_unknown_chunk FAR * FAR * hipng_unknown_chunkpp;
#endif

/* hipng_info is a structure that holds the information in a PNG file so
 * that the application can find out the characteristics of the image.
 * If you are reading the file, this structure will tell you what is
 * in the PNG file.  If you are writing the file, fill in the information
 * you want to put into the PNG file, then call hipng_write_info().
 * The names chosen should be very close to the PNG specification, so
 * consult that document for information about the meaning of each field.
 *
 * With libpng < 0.95, it was only possible to directly set and read the
 * the values in the hipng_info_struct, which meant that the contents and
 * order of the values had to remain fixed.  With libpng 0.95 and later,
 * however, there are now functions that abstract the contents of
 * hipng_info_struct from the application, so this makes it easier to use
 * libpng with dynamic libraries, and even makes it possible to use
 * libraries that don't have all of the libpng ancillary chunk-handing
 * functionality.
 *
 * In any case, the order of the parameters in hipng_info_struct should NOT
 * be changed for as long as possible to keep compatibility with applications
 * that use the old direct-access method with hipng_info_struct.
 *
 * The following members may have allocated storage attached that should be
 * cleaned up before the structure is discarded: palette, trans, text,
 * pcal_purpose, pcal_units, pcal_params, hist, iccp_name, iccp_profile,
 * splt_palettes, scal_unit, row_pointers, and unknowns.   By default, these
 * are automatically freed when the info structure is deallocated, if they were
 * allocated internally by libpng.  This behavior can be changed by means
 * of the hipng_data_freer() function.
 *
 * More allocation details: all the chunk-reading functions that
 * change these members go through the corresponding hipng_set_*
 * functions.  A function to clear these members is available: see
 * hipng_free_data().  The hipng_set_* functions do not depend on being
 * able to point info structure members to any of the storage they are
 * passed (they make their own copies), EXCEPT that the hipng_set_text
 * functions use the same storage passed to them in the text_ptr or
 * itxt_ptr structure argument, and the hipng_set_rows and hipng_set_unknowns
 * functions do not make their own copies.
 */
typedef struct hipng_info_struct
{
   /* the following are necessary for every PNG file */
   hipng_uint_32 width HIPNG_DEPSTRUCT;       /* width of image in pixels (from IHDR) */
   hipng_uint_32 height HIPNG_DEPSTRUCT;      /* height of image in pixels (from IHDR) */
   hipng_uint_32 valid HIPNG_DEPSTRUCT;       /* valid chunk data (see HIPNG_INFO_ below) */
   hipng_size_t rowbytes HIPNG_DEPSTRUCT;     /* bytes needed to hold an untransformed row */
   hipng_colorp palette HIPNG_DEPSTRUCT;      /* array of color values (valid & HIPNG_INFO_PLTE) */
   hipng_uint_16 num_palette HIPNG_DEPSTRUCT; /* number of color entries in "palette" (PLTE) */
   hipng_uint_16 num_trans HIPNG_DEPSTRUCT;   /* number of transparent palette color (tRNS) */
   hipng_byte bit_depth HIPNG_DEPSTRUCT;      /* 1, 2, 4, 8, or 16 bits/channel (from IHDR) */
   hipng_byte color_type HIPNG_DEPSTRUCT;     /* see HIPNG_COLOR_TYPE_ below (from IHDR) */
   /* The following three should have been named *_method not *_type */
   hipng_byte compression_type HIPNG_DEPSTRUCT; /* must be HIPNG_COMPRESSION_TYPE_BASE (IHDR) */
   hipng_byte filter_type HIPNG_DEPSTRUCT;    /* must be HIPNG_FILTER_TYPE_BASE (from IHDR) */
   hipng_byte interlace_type HIPNG_DEPSTRUCT; /* One of HIPNG_INTERLACE_NONE, HIPNG_INTERLACE_ADAM7 */

   /* The following is informational only on read, and not used on writes. */
   hipng_byte channels HIPNG_DEPSTRUCT;       /* number of data channels per pixel (1, 2, 3, 4) */
   hipng_byte pixel_depth HIPNG_DEPSTRUCT;    /* number of bits per pixel */
   hipng_byte spare_byte HIPNG_DEPSTRUCT;     /* to align the data, and for future use */
   hipng_byte signature[8] HIPNG_DEPSTRUCT;   /* magic bytes read by libpng from start of file */

   /* The rest of the data is optional.  If you are reading, check the
    * valid field to see if the information in these are valid.  If you
    * are writing, set the valid field to those chunks you want written,
    * and initialize the appropriate fields below.
    */

#if defined(HIPNG_gAMA_SUPPORTED) && defined(HIPNG_FLOATING_POINT_SUPPORTED)
   /* The gAMA chunk describes the gamma characteristics of the system
    * on which the image was created, normally in the range [1.0, 2.5].
    * Data is valid if (valid & HIPNG_INFO_gAMA) is non-zero.
    */
   float gamma HIPNG_DEPSTRUCT; /* gamma value of image, if (valid & HIPNG_INFO_gAMA) */
#endif

#ifdef HIPNG_sRGB_SUPPORTED
    /* GR-P, 0.96a */
    /* Data valid if (valid & HIPNG_INFO_sRGB) non-zero. */
   hipng_byte srgb_intent HIPNG_DEPSTRUCT; /* sRGB rendering intent [0, 1, 2, or 3] */
#endif

#ifdef HIPNG_TEXT_SUPPORTED
   /* The tEXt, and zTXt chunks contain human-readable textual data in
    * uncompressed, compressed, and optionally compressed forms, respectively.
    * The data in "text" is an array of pointers to uncompressed,
    * null-terminated C strings. Each chunk has a keyword that describes the
    * textual data contained in that chunk.  Keywords are not required to be
    * unique, and the text string may be empty.  Any number of text chunks may
    * be in an image.
    */
   int num_text HIPNG_DEPSTRUCT; /* number of comments read/to write */
   int max_text HIPNG_DEPSTRUCT; /* current size of text array */
   hipng_textp text HIPNG_DEPSTRUCT; /* array of comments read/to write */
#endif /* HIPNG_TEXT_SUPPORTED */

#ifdef HIPNG_tIME_SUPPORTED
   /* The tIME chunk holds the last time the displayed image data was
    * modified.  See the hipng_time struct for the contents of this struct.
    */
   hipng_time mod_time HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_sBIT_SUPPORTED
   /* The sBIT chunk specifies the number of significant high-order bits
    * in the pixel data.  Values are in the range [1, bit_depth], and are
    * only specified for the channels in the pixel data.  The contents of
    * the low-order bits is not specified.  Data is valid if
    * (valid & HIPNG_INFO_sBIT) is non-zero.
    */
   hipng_color_8 sig_bit HIPNG_DEPSTRUCT; /* significant bits in color channels */
#endif

#if defined(HIPNG_tRNS_SUPPORTED) || defined(HIPNG_READ_EXPAND_SUPPORTED) || \
defined(HIPNG_READ_BACKGROUND_SUPPORTED)
   /* The tRNS chunk supplies transparency data for paletted images and
    * other image types that don't need a full alpha channel.  There are
    * "num_trans" transparency values for a paletted image, stored in the
    * same order as the palette colors, starting from index 0.  Values
    * for the data are in the range [0, 255], ranging from fully transparent
    * to fully opaque, respectively.  For non-paletted images, there is a
    * single color specified that should be treated as fully transparent.
    * Data is valid if (valid & HIPNG_INFO_tRNS) is non-zero.
    */
   hipng_bytep trans_alpha HIPNG_DEPSTRUCT;    /* alpha values for paletted image */
   hipng_color_16 trans_color HIPNG_DEPSTRUCT; /* transparent color for non-palette image */
#endif

#if defined(HIPNG_bKGD_SUPPORTED) || defined(HIPNG_READ_BACKGROUND_SUPPORTED)
   /* The bKGD chunk gives the suggested image background color if the
    * display program does not have its own background color and the image
    * is needs to composited onto a background before display.  The colors
    * in "background" are normally in the same color space/depth as the
    * pixel data.  Data is valid if (valid & HIPNG_INFO_bKGD) is non-zero.
    */
   hipng_color_16 background HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_oFFs_SUPPORTED
   /* The oFFs chunk gives the offset in "offset_unit_type" units rightwards
    * and downwards from the top-left corner of the display, page, or other
    * application-specific co-ordinate space.  See the HIPNG_OFFSET_ defines
    * below for the unit types.  Valid if (valid & HIPNG_INFO_oFFs) non-zero.
    */
   hipng_int_32 x_offset HIPNG_DEPSTRUCT; /* x offset on page */
   hipng_int_32 y_offset HIPNG_DEPSTRUCT; /* y offset on page */
   hipng_byte offset_unit_type HIPNG_DEPSTRUCT; /* offset units type */
#endif

#ifdef HIPNG_pHYs_SUPPORTED
   /* The pHYs chunk gives the physical pixel density of the image for
    * display or printing in "phys_unit_type" units (see HIPNG_RESOLUTION_
    * defines below).  Data is valid if (valid & HIPNG_INFO_pHYs) is non-zero.
    */
   hipng_uint_32 x_pixels_per_unit HIPNG_DEPSTRUCT; /* horizontal pixel density */
   hipng_uint_32 y_pixels_per_unit HIPNG_DEPSTRUCT; /* vertical pixel density */
   hipng_byte phys_unit_type HIPNG_DEPSTRUCT; /* resolution type (see HIPNG_RESOLUTION_ below) */
#endif

#ifdef HIPNG_hIST_SUPPORTED
   /* The hIST chunk contains the relative frequency or importance of the
    * various palette entries, so that a viewer can intelligently select a
    * reduced-color palette, if required.  Data is an array of "num_palette"
    * values in the range [0,65535]. Data valid if (valid & HIPNG_INFO_hIST)
    * is non-zero.
    */
   hipng_uint_16p hist HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_cHRM_SUPPORTED
   /* The cHRM chunk describes the CIE color characteristics of the monitor
    * on which the PNG was created.  This data allows the viewer to do gamut
    * mapping of the input image to ensure that the viewer sees the same
    * colors in the image as the creator.  Values are in the range
    * [0.0, 0.8].  Data valid if (valid & HIPNG_INFO_cHRM) non-zero.
    */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
   float x_white HIPNG_DEPSTRUCT;
   float y_white HIPNG_DEPSTRUCT;
   float x_red HIPNG_DEPSTRUCT;
   float y_red HIPNG_DEPSTRUCT;
   float x_green HIPNG_DEPSTRUCT;
   float y_green HIPNG_DEPSTRUCT;
   float x_blue HIPNG_DEPSTRUCT;
   float y_blue HIPNG_DEPSTRUCT;
#endif
#endif

#ifdef HIPNG_pCAL_SUPPORTED
   /* The pCAL chunk describes a transformation between the stored pixel
    * values and original physical data values used to create the image.
    * The integer range [0, 2^bit_depth - 1] maps to the floating-point
    * range given by [pcal_X0, pcal_X1], and are further transformed by a
    * (possibly non-linear) transformation function given by "pcal_type"
    * and "pcal_params" into "pcal_units".  Please see the HIPNG_EQUATION_
    * defines below, and the PNG-Group's PNG extensions document for a
    * complete description of the transformations and how they should be
    * implemented, and for a description of the ASCII parameter strings.
    * Data values are valid if (valid & HIPNG_INFO_pCAL) non-zero.
    */
   hipng_charp pcal_purpose HIPNG_DEPSTRUCT;  /* pCAL chunk description string */
   hipng_int_32 pcal_X0 HIPNG_DEPSTRUCT;      /* minimum value */
   hipng_int_32 pcal_X1 HIPNG_DEPSTRUCT;      /* maximum value */
   hipng_charp pcal_units HIPNG_DEPSTRUCT;    /* Latin-1 string giving physical units */
   hipng_charpp pcal_params HIPNG_DEPSTRUCT;  /* ASCII strings containing parameter values */
   hipng_byte pcal_type HIPNG_DEPSTRUCT;      /* equation type (see HIPNG_EQUATION_ below) */
   hipng_byte pcal_nparams HIPNG_DEPSTRUCT;   /* number of parameters given in pcal_params */
#endif

/* New members added in libpng-1.0.6 */
   hipng_uint_32 free_me HIPNG_DEPSTRUCT;     /* flags items libpng is responsible for freeing */

#if defined(HIPNG_UNKNOWN_CHUNKS_SUPPORTED) || \
 defined(HIPNG_HANDLE_AS_UNKNOWN_SUPPORTED)
   /* Storage for unknown chunks that the library doesn't recognize. */
   hipng_unknown_chunkp unknown_chunks HIPNG_DEPSTRUCT;
   hipng_size_t unknown_chunks_num HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_iCCP_SUPPORTED
   /* iCCP chunk data. */
   hipng_charp iccp_name HIPNG_DEPSTRUCT;     /* profile name */
   hipng_charp iccp_profile HIPNG_DEPSTRUCT;  /* International Color Consortium profile data */
                            /* Note to maintainer: should be hipng_bytep */
   hipng_uint_32 iccp_proflen HIPNG_DEPSTRUCT;  /* ICC profile data length */
   hipng_byte iccp_compression HIPNG_DEPSTRUCT; /* Always zero */
#endif

#ifdef HIPNG_sPLT_SUPPORTED
   /* Data on sPLT chunks (there may be more than one). */
   hipng_sPLT_tp splt_palettes HIPNG_DEPSTRUCT;
   hipng_uint_32 splt_palettes_num HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_sCAL_SUPPORTED
   /* The sCAL chunk describes the actual physical dimensions of the
    * subject matter of the graphic.  The chunk contains a unit specification
    * a byte value, and two ASCII strings representing floating-point
    * values.  The values are width and height corresponsing to one pixel
    * in the image.  This external representation is converted to double
    * here.  Data values are valid if (valid & HIPNG_INFO_sCAL) is non-zero.
    */
   hipng_byte scal_unit HIPNG_DEPSTRUCT;         /* unit of physical scale */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
   double scal_pixel_width HIPNG_DEPSTRUCT;    /* width of one pixel */
   double scal_pixel_height HIPNG_DEPSTRUCT;   /* height of one pixel */
#endif
#ifdef HIPNG_FIXED_POINT_SUPPORTED
   hipng_charp scal_s_width HIPNG_DEPSTRUCT;     /* string containing height */
   hipng_charp scal_s_height HIPNG_DEPSTRUCT;    /* string containing width */
#endif
#endif

#ifdef HIPNG_INFO_IMAGE_SUPPORTED
   /* Memory has been allocated if (valid & HIPNG_ALLOCATED_INFO_ROWS) non-zero */
   /* Data valid if (valid & HIPNG_INFO_IDAT) non-zero */
   hipng_bytepp row_pointers HIPNG_DEPSTRUCT;        /* the image bits */
#endif

#if defined(HIPNG_FIXED_POINT_SUPPORTED) && defined(HIPNG_gAMA_SUPPORTED)
   hipng_fixed_point int_gamma HIPNG_DEPSTRUCT; /* gamma of image, if (valid & HIPNG_INFO_gAMA) */
#endif

#if defined(HIPNG_cHRM_SUPPORTED) && defined(HIPNG_FIXED_POINT_SUPPORTED)
   hipng_fixed_point int_x_white HIPNG_DEPSTRUCT;
   hipng_fixed_point int_y_white HIPNG_DEPSTRUCT;
   hipng_fixed_point int_x_red HIPNG_DEPSTRUCT;
   hipng_fixed_point int_y_red HIPNG_DEPSTRUCT;
   hipng_fixed_point int_x_green HIPNG_DEPSTRUCT;
   hipng_fixed_point int_y_green HIPNG_DEPSTRUCT;
   hipng_fixed_point int_x_blue HIPNG_DEPSTRUCT;
   hipng_fixed_point int_y_blue HIPNG_DEPSTRUCT;
#endif

} hipng_info;

typedef hipng_info FAR * hipng_infop;
typedef hipng_info FAR * FAR * hipng_infopp;

/* Maximum positive integer used in PNG is (2^31)-1 */
#define HIPNG_UINT_31_MAX ((hipng_uint_32)0x7fffffffL)
#define HIPNG_UINT_32_MAX ((hipng_uint_32)(-1))
#define HIPNG_SIZE_MAX ((hipng_size_t)(-1))

/* These describe the color_type field in hipng_info. */
/* color type masks */
#define HIPNG_COLOR_MASK_PALETTE    1
#define HIPNG_COLOR_MASK_COLOR      2
#define HIPNG_COLOR_MASK_ALPHA      4

/* color types.  Note that not all combinations are legal */
#define HIPNG_COLOR_TYPE_GRAY 0
#define HIPNG_COLOR_TYPE_PALETTE  (HIPNG_COLOR_MASK_COLOR | HIPNG_COLOR_MASK_PALETTE)
#define HIPNG_COLOR_TYPE_RGB        (HIPNG_COLOR_MASK_COLOR)
#define HIPNG_COLOR_TYPE_RGB_ALPHA  (HIPNG_COLOR_MASK_COLOR | HIPNG_COLOR_MASK_ALPHA)
#define HIPNG_COLOR_TYPE_GRAY_ALPHA (HIPNG_COLOR_MASK_ALPHA)
/* aliases */
#define HIPNG_COLOR_TYPE_RGBA  HIPNG_COLOR_TYPE_RGB_ALPHA
#define HIPNG_COLOR_TYPE_GA  HIPNG_COLOR_TYPE_GRAY_ALPHA

/* This is for compression type. PNG 1.0-1.2 only define the single type. */
#define HIPNG_COMPRESSION_TYPE_BASE 0 /* Deflate method 8, 32K window */
#define HIPNG_COMPRESSION_TYPE_DEFAULT HIPNG_COMPRESSION_TYPE_BASE

/* This is for filter type. PNG 1.0-1.2 only define the single type. */
#define HIPNG_FILTER_TYPE_BASE      0 /* Single row per-byte filtering */
#define HIPNG_INTRAPIXEL_DIFFERENCING 64 /* Used only in MNG datastreams */
#define HIPNG_FILTER_TYPE_DEFAULT   HIPNG_FILTER_TYPE_BASE

/* These are for the interlacing type.  These values should NOT be changed. */
#define HIPNG_INTERLACE_NONE        0 /* Non-interlaced image */
#define HIPNG_INTERLACE_ADAM7       1 /* Adam7 interlacing */
#define HIPNG_INTERLACE_LAST        2 /* Not a valid value */

/* These are for the oFFs chunk.  These values should NOT be changed. */
#define HIPNG_OFFSET_PIXEL          0 /* Offset in pixels */
#define HIPNG_OFFSET_MICROMETER     1 /* Offset in micrometers (1/10^6 meter) */
#define HIPNG_OFFSET_LAST           2 /* Not a valid value */

/* These are for the pCAL chunk.  These values should NOT be changed. */
#define HIPNG_EQUATION_LINEAR       0 /* Linear transformation */
#define HIPNG_EQUATION_BASE_E       1 /* Exponential base e transform */
#define HIPNG_EQUATION_ARBITRARY    2 /* Arbitrary base exponential transform */
#define HIPNG_EQUATION_HYPERBOLIC   3 /* Hyperbolic sine transformation */
#define HIPNG_EQUATION_LAST         4 /* Not a valid value */

/* These are for the sCAL chunk.  These values should NOT be changed. */
#define HIPNG_SCALE_UNKNOWN         0 /* unknown unit (image scale) */
#define HIPNG_SCALE_METER           1 /* meters per pixel */
#define HIPNG_SCALE_RADIAN          2 /* radians per pixel */
#define HIPNG_SCALE_LAST            3 /* Not a valid value */

/* These are for the pHYs chunk.  These values should NOT be changed. */
#define HIPNG_RESOLUTION_UNKNOWN    0 /* pixels/unknown unit (aspect ratio) */
#define HIPNG_RESOLUTION_METER      1 /* pixels/meter */
#define HIPNG_RESOLUTION_LAST       2 /* Not a valid value */

/* These are for the sRGB chunk.  These values should NOT be changed. */
#define HIPNG_sRGB_INTENT_PERCEPTUAL 0
#define HIPNG_sRGB_INTENT_RELATIVE   1
#define HIPNG_sRGB_INTENT_SATURATION 2
#define HIPNG_sRGB_INTENT_ABSOLUTE   3
#define HIPNG_sRGB_INTENT_LAST       4 /* Not a valid value */

/* This is for text chunks */
#define HIPNG_KEYWORD_MAX_LENGTH     79

/* Maximum number of entries in PLTE/sPLT/tRNS arrays */
#define HIPNG_MAX_PALETTE_LENGTH    256

/* These determine if an ancillary chunk's data has been successfully read
 * from the PNG header, or if the application has filled in the corresponding
 * data in the info_struct to be written into the output file.  The values
 * of the HIPNG_INFO_<chunk> defines should NOT be changed.
 */
#define HIPNG_INFO_gAMA 0x0001
#define HIPNG_INFO_sBIT 0x0002
#define HIPNG_INFO_cHRM 0x0004
#define HIPNG_INFO_PLTE 0x0008
#define HIPNG_INFO_tRNS 0x0010
#define HIPNG_INFO_bKGD 0x0020
#define HIPNG_INFO_hIST 0x0040
#define HIPNG_INFO_pHYs 0x0080
#define HIPNG_INFO_oFFs 0x0100
#define HIPNG_INFO_tIME 0x0200
#define HIPNG_INFO_pCAL 0x0400
#define HIPNG_INFO_sRGB 0x0800   /* GR-P, 0.96a */
#define HIPNG_INFO_iCCP 0x1000   /* ESR, 1.0.6 */
#define HIPNG_INFO_sPLT 0x2000   /* ESR, 1.0.6 */
#define HIPNG_INFO_sCAL 0x4000   /* ESR, 1.0.6 */
#define HIPNG_INFO_IDAT 0x8000L  /* ESR, 1.0.6 */

/* This is used for the transformation routines, as some of them
 * change these values for the row.  It also should enable using
 * the routines for other purposes.
 */
typedef struct hipng_row_info_struct
{
   hipng_uint_32 width; /* width of row */
   hipng_size_t rowbytes; /* number of bytes in row */
   hipng_byte color_type; /* color type of row */
   hipng_byte bit_depth; /* bit depth of row */
   hipng_byte channels; /* number of channels (1, 2, 3, or 4) */
   hipng_byte pixel_depth; /* bits per pixel (depth * channels) */
} hipng_row_info;

typedef hipng_row_info FAR * hipng_row_infop;
typedef hipng_row_info FAR * FAR * hipng_row_infopp;

/* These are the function types for the I/O functions and for the functions
 * that allow the user to override the default I/O functions with his or her
 * own.  The hipng_error_ptr type should match that of user-supplied warning
 * and error functions, while the hipng_rw_ptr type should match that of the
 * user read/write data functions.
 */
typedef struct hipng_struct_def hipng_struct;
typedef hipng_struct FAR * hipng_structp;

typedef void (PNGAPI *hipng_error_ptr) HIPNGARG((hipng_structp, hipng_const_charp));
typedef void (PNGAPI *hipng_rw_ptr) HIPNGARG((hipng_structp, hipng_bytep, hipng_size_t));
typedef void (PNGAPI *hipng_flush_ptr) HIPNGARG((hipng_structp));
typedef void (PNGAPI *hipng_read_status_ptr) HIPNGARG((hipng_structp, hipng_uint_32,
   int));
typedef void (PNGAPI *hipng_write_status_ptr) HIPNGARG((hipng_structp, hipng_uint_32,
   int));

#ifdef HIPNG_PROGRESSIVE_READ_SUPPORTED
typedef void (PNGAPI *hipng_progressive_info_ptr) HIPNGARG((hipng_structp, hipng_infop));
typedef void (PNGAPI *hipng_progressive_end_ptr) HIPNGARG((hipng_structp, hipng_infop));
typedef void (PNGAPI *hipng_progressive_row_ptr) HIPNGARG((hipng_structp, hipng_bytep,
   hipng_uint_32, int));
#endif

#if defined(HIPNG_READ_USER_TRANSFORM_SUPPORTED) || \
    defined(HIPNG_WRITE_USER_TRANSFORM_SUPPORTED)
typedef void (PNGAPI *hipng_user_transform_ptr) HIPNGARG((hipng_structp,
    hipng_row_infop, hipng_bytep));
#endif

#ifdef HIPNG_USER_CHUNKS_SUPPORTED
typedef int (PNGAPI *hipng_user_chunk_ptr) HIPNGARG((hipng_structp, hipng_unknown_chunkp));
#endif
#ifdef HIPNG_UNKNOWN_CHUNKS_SUPPORTED
typedef void (PNGAPI *hipng_unknown_chunk_ptr) HIPNGARG((hipng_structp));
#endif
#ifdef HIPNG_SETJMP_SUPPORTED
/* This must match the function definition in <setjmp.h>, and the
 * application must include this before png.h to obtain the definition
 * of jmp_buf.
 */
typedef void (PNGAPI *hipng_longjmp_ptr) HIPNGARG((jmp_buf, int));
#endif

/* Transform masks for the high-level interface */
#define HIPNG_TRANSFORM_IDENTITY       0x0000    /* read and write */
#define HIPNG_TRANSFORM_STRIP_16       0x0001    /* read only */
#define HIPNG_TRANSFORM_STRIP_ALPHA    0x0002    /* read only */
#define HIPNG_TRANSFORM_PACKING        0x0004    /* read and write */
#define HIPNG_TRANSFORM_PACKSWAP       0x0008    /* read and write */
#define HIPNG_TRANSFORM_EXPAND         0x0010    /* read only */
#define HIPNG_TRANSFORM_INVERT_MONO    0x0020    /* read and write */
#define HIPNG_TRANSFORM_SHIFT          0x0040    /* read and write */
#define HIPNG_TRANSFORM_BGR            0x0080    /* read and write */
#define HIPNG_TRANSFORM_SWAP_ALPHA     0x0100    /* read and write */
#define HIPNG_TRANSFORM_SWAP_ENDIAN    0x0200    /* read and write */
#define HIPNG_TRANSFORM_INVERT_ALPHA   0x0400    /* read and write */
#define HIPNG_TRANSFORM_STRIP_FILLER   0x0800    /* write only */
/* Added to libpng-1.2.34 */
#define HIPNG_TRANSFORM_STRIP_FILLER_BEFORE HIPNG_TRANSFORM_STRIP_FILLER
#define HIPNG_TRANSFORM_STRIP_FILLER_AFTER 0x1000 /* write only */
/* Added to libpng-1.4.0 */
#define HIPNG_TRANSFORM_GRAY_TO_RGB   0x2000      /* read only */

#ifdef HIPNG_ACCELERATE
#define HIPNG_TRANSFORM_ARGB1555 0x10000
#define HIPNG_TRANSFORM_ARGB4444 0x20000
#define HIPNG_TRANSFORM_RGB565 0x40000
#define HIPNG_TRANSFORM_RGB555 0x80000
#define HIPNG_TRANSFORM_RGB444 0x100000
#endif

/* Flags for MNG supported features */
#define HIPNG_FLAG_MNG_EMPTY_PLTE     0x01
#define HIPNG_FLAG_MNG_FILTER_64      0x04
#define HIPNG_ALL_MNG_FEATURES        0x05

typedef hipng_voidp (*hipng_malloc_ptr) HIPNGARG((hipng_structp, hipng_alloc_size_t));
typedef void (*hipng_free_ptr) HIPNGARG((hipng_structp, hipng_voidp));

/* The structure that holds the information to read and write PNG files.
 * The only people who need to care about what is inside of this are the
 * people who will be modifying the library for their own special needs.
 * It should NOT be accessed directly by an application, except to store
 * the jmp_buf.
 */

struct hipng_struct_def
{
#ifdef HIPNG_SETJMP_SUPPORTED
   jmp_buf jmpbuf HIPNG_DEPSTRUCT;            /* used in hipng_error */
   hipng_longjmp_ptr longjmp_fn HIPNG_DEPSTRUCT;/* setjmp non-local goto function. */
#endif
   hipng_error_ptr error_fn HIPNG_DEPSTRUCT;    /* function for printing errors and aborting */
   hipng_error_ptr warning_fn HIPNG_DEPSTRUCT;  /* function for printing warnings */
   hipng_voidp error_ptr HIPNG_DEPSTRUCT;       /* user supplied struct for error functions */
   hipng_rw_ptr write_data_fn HIPNG_DEPSTRUCT;  /* function for writing output data */
   hipng_rw_ptr read_data_fn HIPNG_DEPSTRUCT;   /* function for reading input data */
   hipng_voidp io_ptr HIPNG_DEPSTRUCT;          /* ptr to application struct for I/O functions */

#ifdef HIPNG_READ_USER_TRANSFORM_SUPPORTED
   hipng_user_transform_ptr read_user_transform_fn HIPNG_DEPSTRUCT; /* user read transform */
#endif

#ifdef HIPNG_WRITE_USER_TRANSFORM_SUPPORTED
   hipng_user_transform_ptr write_user_transform_fn HIPNG_DEPSTRUCT; /* user write transform */
#endif

/* These were added in libpng-1.0.2 */
#ifdef HIPNG_USER_TRANSFORM_PTR_SUPPORTED
#if defined(HIPNG_READ_USER_TRANSFORM_SUPPORTED) || \
    defined(HIPNG_WRITE_USER_TRANSFORM_SUPPORTED)
   hipng_voidp user_transform_ptr HIPNG_DEPSTRUCT; /* user supplied struct for user transform */
   hipng_byte user_transform_depth HIPNG_DEPSTRUCT;    /* bit depth of user transformed pixels */
   hipng_byte user_transform_channels HIPNG_DEPSTRUCT; /* channels in user transformed pixels */
#endif
#endif

   hipng_uint_32 mode HIPNG_DEPSTRUCT;          /* tells us where we are in the PNG file */
   hipng_uint_32 flags HIPNG_DEPSTRUCT;         /* flags indicating various things to libpng */
   hipng_uint_32 transformations HIPNG_DEPSTRUCT; /* which transformations to perform */

   z_stream zstream HIPNG_DEPSTRUCT;          /* pointer to decompression structure (below) */
   hipng_bytep zbuf HIPNG_DEPSTRUCT;            /* buffer for zlib */
   hipng_size_t zbuf_size HIPNG_DEPSTRUCT;      /* size of zbuf */
   int zlib_level HIPNG_DEPSTRUCT;            /* holds zlib compression level */
   int zlib_method HIPNG_DEPSTRUCT;           /* holds zlib compression method */
   int zlib_window_bits HIPNG_DEPSTRUCT;      /* holds zlib compression window bits */
   int zlib_mem_level HIPNG_DEPSTRUCT;        /* holds zlib compression memory level */
   int zlib_strategy HIPNG_DEPSTRUCT;         /* holds zlib compression strategy */

   hipng_uint_32 width HIPNG_DEPSTRUCT;         /* width of image in pixels */
   hipng_uint_32 height HIPNG_DEPSTRUCT;        /* height of image in pixels */
   hipng_uint_32 num_rows HIPNG_DEPSTRUCT;      /* number of rows in current pass */
   hipng_uint_32 usr_width HIPNG_DEPSTRUCT;     /* width of row at start of write */
   hipng_size_t rowbytes HIPNG_DEPSTRUCT;       /* size of row in bytes */
   hipng_size_t irowbytes HIPNG_DEPSTRUCT;      /* size of current interlaced row in bytes */
   hipng_uint_32 iwidth HIPNG_DEPSTRUCT;        /* width of current interlaced row in pixels */
   hipng_uint_32 row_number HIPNG_DEPSTRUCT;    /* current row in interlace pass */
   hipng_bytep prev_row HIPNG_DEPSTRUCT;        /* buffer to save previous (unfiltered) row */
   hipng_bytep row_buf HIPNG_DEPSTRUCT;         /* buffer to save current (unfiltered) row */
   hipng_bytep sub_row HIPNG_DEPSTRUCT;         /* buffer to save "sub" row when filtering */
   hipng_bytep up_row HIPNG_DEPSTRUCT;          /* buffer to save "up" row when filtering */
   hipng_bytep avg_row HIPNG_DEPSTRUCT;         /* buffer to save "avg" row when filtering */
   hipng_bytep paeth_row HIPNG_DEPSTRUCT;       /* buffer to save "Paeth" row when filtering */
   hipng_row_info row_info HIPNG_DEPSTRUCT;     /* used for transformation routines */

   hipng_uint_32 idat_size HIPNG_DEPSTRUCT;     /* current IDAT size for read */
   hipng_uint_32 crc HIPNG_DEPSTRUCT;           /* current chunk CRC value */
   hipng_colorp palette HIPNG_DEPSTRUCT;        /* palette from the input file */
   hipng_uint_16 num_palette HIPNG_DEPSTRUCT;   /* number of color entries in palette */
   hipng_uint_16 num_trans HIPNG_DEPSTRUCT;     /* number of transparency values */
   hipng_byte chunk_name[5] HIPNG_DEPSTRUCT;    /* null-terminated name of current chunk */
   hipng_byte compression HIPNG_DEPSTRUCT;      /* file compression type (always 0) */
   hipng_byte filter HIPNG_DEPSTRUCT;           /* file filter type (always 0) */
   hipng_byte interlaced HIPNG_DEPSTRUCT;       /* HIPNG_INTERLACE_NONE, HIPNG_INTERLACE_ADAM7 */
   hipng_byte pass HIPNG_DEPSTRUCT;             /* current interlace pass (0 - 6) */
   hipng_byte do_filter HIPNG_DEPSTRUCT;        /* row filter flags (see HIPNG_FILTER_ below ) */
   hipng_byte color_type HIPNG_DEPSTRUCT;       /* color type of file */
   hipng_byte bit_depth HIPNG_DEPSTRUCT;        /* bit depth of file */
   hipng_byte usr_bit_depth HIPNG_DEPSTRUCT;    /* bit depth of users row */
   hipng_byte pixel_depth HIPNG_DEPSTRUCT;      /* number of bits per pixel */
   hipng_byte channels HIPNG_DEPSTRUCT;         /* number of channels in file */
   hipng_byte usr_channels HIPNG_DEPSTRUCT;     /* channels at start of write */
   hipng_byte sig_bytes HIPNG_DEPSTRUCT;        /* magic bytes read/written from start of file */

#if defined(HIPNG_READ_FILLER_SUPPORTED) || defined(HIPNG_WRITE_FILLER_SUPPORTED)
   hipng_uint_16 filler HIPNG_DEPSTRUCT;           /* filler bytes for pixel expansion */
#endif

#ifdef HIPNG_bKGD_SUPPORTED
   hipng_byte background_gamma_type HIPNG_DEPSTRUCT;
#  ifdef HIPNG_FLOATING_POINT_SUPPORTED
   float background_gamma HIPNG_DEPSTRUCT;
#  endif
   hipng_color_16 background HIPNG_DEPSTRUCT;   /* background color in screen gamma space */
#ifdef HIPNG_READ_GAMMA_SUPPORTED
   hipng_color_16 background_1 HIPNG_DEPSTRUCT; /* background normalized to gamma 1.0 */
#endif
#endif /* HIPNG_bKGD_SUPPORTED */

#ifdef HIPNG_WRITE_FLUSH_SUPPORTED
   hipng_flush_ptr output_flush_fn HIPNG_DEPSTRUCT; /* Function for flushing output */
   hipng_uint_32 flush_dist HIPNG_DEPSTRUCT;    /* how many rows apart to flush, 0 - no flush */
   hipng_uint_32 flush_rows HIPNG_DEPSTRUCT;    /* number of rows written since last flush */
#endif

#if defined(HIPNG_READ_GAMMA_SUPPORTED) || defined(HIPNG_READ_BACKGROUND_SUPPORTED)
   int gamma_shift HIPNG_DEPSTRUCT;      /* number of "insignificant" bits 16-bit gamma */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
   float gamma HIPNG_DEPSTRUCT;          /* file gamma value */
   float screen_gamma HIPNG_DEPSTRUCT;   /* screen gamma value (display_exponent) */
#endif
#endif

#if defined(HIPNG_READ_GAMMA_SUPPORTED) || defined(HIPNG_READ_BACKGROUND_SUPPORTED)
   hipng_bytep gamma_table HIPNG_DEPSTRUCT;     /* gamma table for 8-bit depth files */
   hipng_bytep gamma_from_1 HIPNG_DEPSTRUCT;    /* converts from 1.0 to screen */
   hipng_bytep gamma_to_1 HIPNG_DEPSTRUCT;      /* converts from file to 1.0 */
   hipng_uint_16pp gamma_16_table HIPNG_DEPSTRUCT; /* gamma table for 16-bit depth files */
   hipng_uint_16pp gamma_16_from_1 HIPNG_DEPSTRUCT; /* converts from 1.0 to screen */
   hipng_uint_16pp gamma_16_to_1 HIPNG_DEPSTRUCT; /* converts from file to 1.0 */
#endif

#if defined(HIPNG_READ_GAMMA_SUPPORTED) || defined(HIPNG_sBIT_SUPPORTED)
   hipng_color_8 sig_bit HIPNG_DEPSTRUCT;       /* significant bits in each available channel */
#endif

#if defined(HIPNG_READ_SHIFT_SUPPORTED) || defined(HIPNG_WRITE_SHIFT_SUPPORTED)
   hipng_color_8 shift HIPNG_DEPSTRUCT;         /* shift for significant bit tranformation */
#endif

#if defined(HIPNG_tRNS_SUPPORTED) || defined(HIPNG_READ_BACKGROUND_SUPPORTED) \
 || defined(HIPNG_READ_EXPAND_SUPPORTED) || defined(HIPNG_READ_BACKGROUND_SUPPORTED)
   hipng_bytep trans_alpha HIPNG_DEPSTRUCT;           /* alpha values for paletted files */
   hipng_color_16 trans_color HIPNG_DEPSTRUCT;  /* transparent color for non-paletted files */
#endif

   hipng_read_status_ptr read_row_fn HIPNG_DEPSTRUCT;   /* called after each row is decoded */
   hipng_write_status_ptr write_row_fn HIPNG_DEPSTRUCT; /* called after each row is encoded */
#ifdef HIPNG_PROGRESSIVE_READ_SUPPORTED
   hipng_progressive_info_ptr info_fn HIPNG_DEPSTRUCT; /* called after header data fully read */
   hipng_progressive_row_ptr row_fn HIPNG_DEPSTRUCT;   /* called after each prog. row is decoded */
   hipng_progressive_end_ptr end_fn HIPNG_DEPSTRUCT;   /* called after image is complete */
   hipng_bytep save_buffer_ptr HIPNG_DEPSTRUCT;        /* current location in save_buffer */
   hipng_bytep save_buffer HIPNG_DEPSTRUCT;            /* buffer for previously read data */
   hipng_bytep current_buffer_ptr HIPNG_DEPSTRUCT;     /* current location in current_buffer */
   hipng_bytep current_buffer HIPNG_DEPSTRUCT;         /* buffer for recently used data */
   hipng_uint_32 push_length HIPNG_DEPSTRUCT;          /* size of current input chunk */
   hipng_uint_32 skip_length HIPNG_DEPSTRUCT;          /* bytes to skip in input data */
   hipng_size_t save_buffer_size HIPNG_DEPSTRUCT;      /* amount of data now in save_buffer */
   hipng_size_t save_buffer_max HIPNG_DEPSTRUCT;       /* total size of save_buffer */
   hipng_size_t buffer_size HIPNG_DEPSTRUCT;           /* total amount of available input data */
   hipng_size_t current_buffer_size HIPNG_DEPSTRUCT;   /* amount of data now in current_buffer */
   int process_mode HIPNG_DEPSTRUCT;                 /* what push library is currently doing */
   int cur_palette HIPNG_DEPSTRUCT;                  /* current push library palette index */

#  ifdef HIPNG_TEXT_SUPPORTED
     hipng_size_t current_text_size HIPNG_DEPSTRUCT;   /* current size of text input data */
     hipng_size_t current_text_left HIPNG_DEPSTRUCT;   /* how much text left to read in input */
     hipng_charp current_text HIPNG_DEPSTRUCT;         /* current text chunk buffer */
     hipng_charp current_text_ptr HIPNG_DEPSTRUCT;     /* current location in current_text */
#  endif /* HIPNG_PROGRESSIVE_READ_SUPPORTED && HIPNG_TEXT_SUPPORTED */

#endif /* HIPNG_PROGRESSIVE_READ_SUPPORTED */

#if defined(__TURBOC__) && !defined(_Windows) && !defined(__FLAT__)
/* For the Borland special 64K segment handler */
   hipng_bytepp offset_table_ptr HIPNG_DEPSTRUCT;
   hipng_bytep offset_table HIPNG_DEPSTRUCT;
   hipng_uint_16 offset_table_number HIPNG_DEPSTRUCT;
   hipng_uint_16 offset_table_count HIPNG_DEPSTRUCT;
   hipng_uint_16 offset_table_count_free HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_READ_DITHER_SUPPORTED
   hipng_bytep palette_lookup HIPNG_DEPSTRUCT;         /* lookup table for dithering */
   hipng_bytep dither_index HIPNG_DEPSTRUCT;           /* index translation for palette files */
#endif

#if defined(HIPNG_READ_DITHER_SUPPORTED) || defined(HIPNG_hIST_SUPPORTED)
   hipng_uint_16p hist HIPNG_DEPSTRUCT;                /* histogram */
#endif

#ifdef HIPNG_WRITE_WEIGHTED_FILTER_SUPPORTED
   hipng_byte heuristic_method HIPNG_DEPSTRUCT;        /* heuristic for row filter selection */
   hipng_byte num_prev_filters HIPNG_DEPSTRUCT;        /* number of weights for previous rows */
   hipng_bytep prev_filters HIPNG_DEPSTRUCT;           /* filter type(s) of previous row(s) */
   hipng_uint_16p filter_weights HIPNG_DEPSTRUCT;      /* weight(s) for previous line(s) */
   hipng_uint_16p inv_filter_weights HIPNG_DEPSTRUCT;  /* 1/weight(s) for previous line(s) */
   hipng_uint_16p filter_costs HIPNG_DEPSTRUCT;        /* relative filter calculation cost */
   hipng_uint_16p inv_filter_costs HIPNG_DEPSTRUCT;    /* 1/relative filter calculation cost */
#endif

#ifdef HIPNG_TIME_RFC1123_SUPPORTED
   hipng_charp time_buffer HIPNG_DEPSTRUCT;            /* String to hold RFC 1123 time text */
#endif

/* New members added in libpng-1.0.6 */

   hipng_uint_32 free_me HIPNG_DEPSTRUCT;     /* flags items libpng is responsible for freeing */

#ifdef HIPNG_USER_CHUNKS_SUPPORTED
   hipng_voidp user_chunk_ptr HIPNG_DEPSTRUCT;
   hipng_user_chunk_ptr read_user_chunk_fn HIPNG_DEPSTRUCT; /* user read chunk handler */
#endif

#ifdef HIPNG_HANDLE_AS_UNKNOWN_SUPPORTED
   int num_chunk_list HIPNG_DEPSTRUCT;
   hipng_bytep chunk_list HIPNG_DEPSTRUCT;
#endif

/* New members added in libpng-1.0.3 */
#ifdef HIPNG_READ_RGB_TO_GRAY_SUPPORTED
   hipng_byte rgb_to_gray_status HIPNG_DEPSTRUCT;
   /* These were changed from hipng_byte in libpng-1.0.6 */
   hipng_uint_16 rgb_to_gray_red_coeff HIPNG_DEPSTRUCT;
   hipng_uint_16 rgb_to_gray_green_coeff HIPNG_DEPSTRUCT;
   hipng_uint_16 rgb_to_gray_blue_coeff HIPNG_DEPSTRUCT;
#endif

/* New member added in libpng-1.0.4 (renamed in 1.0.9) */
#if defined(HIPNG_MNG_FEATURES_SUPPORTED) || \
    defined(HIPNG_READ_EMPTY_PLTE_SUPPORTED) || \
    defined(HIPNG_WRITE_EMPTY_PLTE_SUPPORTED)
/* Changed from hipng_byte to hipng_uint_32 at version 1.2.0 */
   hipng_uint_32 mng_features_permitted HIPNG_DEPSTRUCT;
#endif

/* New member added in libpng-1.0.7 */
#if defined(HIPNG_READ_GAMMA_SUPPORTED) || defined(HIPNG_READ_BACKGROUND_SUPPORTED)
   hipng_fixed_point int_gamma HIPNG_DEPSTRUCT;
#endif

/* New member added in libpng-1.0.9, ifdef'ed out in 1.0.12, enabled in 1.2.0 */
#ifdef HIPNG_MNG_FEATURES_SUPPORTED
   hipng_byte filter_type HIPNG_DEPSTRUCT;
#endif

/* New members added in libpng-1.2.0 */

/* New members added in libpng-1.0.2 but first enabled by default in 1.2.0 */
#ifdef HIPNG_USER_MEM_SUPPORTED
   hipng_voidp mem_ptr HIPNG_DEPSTRUCT;                /* user supplied struct for mem functions */
   hipng_malloc_ptr malloc_fn HIPNG_DEPSTRUCT;         /* function for allocating memory */
   hipng_free_ptr free_fn HIPNG_DEPSTRUCT;             /* function for freeing memory */
#endif

/* New member added in libpng-1.0.13 and 1.2.0 */
   hipng_bytep big_row_buf HIPNG_DEPSTRUCT;         /* buffer to save current (unfiltered) row */

#ifdef HIPNG_READ_DITHER_SUPPORTED
/* The following three members were added at version 1.0.14 and 1.2.4 */
   hipng_bytep dither_sort HIPNG_DEPSTRUCT;            /* working sort array */
   hipng_bytep index_to_palette HIPNG_DEPSTRUCT;       /* where the original index currently is */
                                     /* in the palette */
   hipng_bytep palette_to_index HIPNG_DEPSTRUCT;       /* which original index points to this */
                                     /* palette color */
#endif

/* New members added in libpng-1.0.16 and 1.2.6 */
   hipng_byte compression_type HIPNG_DEPSTRUCT;

#ifdef HIPNG_SET_USER_LIMITS_SUPPORTED
   hipng_uint_32 user_width_max HIPNG_DEPSTRUCT;
   hipng_uint_32 user_height_max HIPNG_DEPSTRUCT;
   /* Added in libpng-1.4.0: Total number of sPLT, text, and unknown
    * chunks that can be stored (0x7fffffff means unlimited).
    */
   hipng_uint_32 user_chunk_cache_max HIPNG_DEPSTRUCT;
#endif

/* New member added in libpng-1.0.25 and 1.2.17 */
#ifdef HIPNG_UNKNOWN_CHUNKS_SUPPORTED
   /* Storage for unknown chunk that the library doesn't recognize. */
   hipng_unknown_chunk unknown_chunk HIPNG_DEPSTRUCT;
#endif

/* New members added in libpng-1.2.26 */
  hipng_uint_32 old_big_row_buf_size HIPNG_DEPSTRUCT;
  hipng_uint_32 old_prev_row_size HIPNG_DEPSTRUCT;

/* New member added in libpng-1.2.30 */
  hipng_charp chunkdata HIPNG_DEPSTRUCT;  /* buffer for reading chunk data */

/* New member added in libpng-1.4.0 */
#ifdef HIPNG_IO_STATE_SUPPORTED
   hipng_uint_32 io_state HIPNG_DEPSTRUCT;
#endif

#ifdef HIPNG_ACCELERATE
   hipng_voidp private_ptr HIPNG_DEPSTRUCT;  
#endif
};


/* This triggers a compiler error in png.c, if png.c and png.h
 * do not agree upon the version number.
 */
typedef hipng_structp version_1_4_0;

typedef hipng_struct FAR * FAR * hipng_structpp;

/* Here are the function definitions most commonly used.  This is not
 * the place to find out how to use libpng.  See libpng.txt for the
 * full explanation, see example.c for the summary.  This just provides
 * a simple one line description of the use of each function.
 */

/* Returns the version number of the library */
extern HIPNG_EXPORT(hipng_uint_32,hipng_access_version_number) HIPNGARG((void));

/* Tell lib we have already handled the first <num_bytes> magic bytes.
 * Handling more than 8 bytes from the beginning of the file is an error.
 */
extern HIPNG_EXPORT(void,hipng_set_sig_bytes) HIPNGARG((hipng_structp hipng_ptr,
   int num_bytes));

/* Check sig[start] through sig[start + num_to_check - 1] to see if it's a
 * PNG file.  Returns zero if the supplied bytes match the 8-byte PNG
 * signature, and non-zero otherwise.  Having num_to_check == 0 or
 * start > 7 will always fail (ie return non-zero).
 */
extern HIPNG_EXPORT(int,hipng_sig_cmp) HIPNGARG((hipng_bytep sig, hipng_size_t start,
   hipng_size_t num_to_check));

/* Allocate and initialize hipng_ptr struct for reading, and any other memory. */
extern HIPNG_EXPORT(hipng_structp,hipng_create_read_struct)
   HIPNGARG((hipng_const_charp user_hipng_ver, hipng_voidp error_ptr,
   hipng_error_ptr error_fn, hipng_error_ptr warn_fn)) HIPNG_ALLOCATED;

/* Allocate and initialize hipng_ptr struct for writing, and any other memory */
extern HIPNG_EXPORT(hipng_structp,hipng_create_write_struct)
   HIPNGARG((hipng_const_charp user_hipng_ver, hipng_voidp error_ptr,
   hipng_error_ptr error_fn, hipng_error_ptr warn_fn)) HIPNG_ALLOCATED;

#ifdef HIPNG_WRITE_SUPPORTED
extern HIPNG_EXPORT(hipng_size_t,hipng_get_compression_buffer_size)
   HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_WRITE_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_compression_buffer_size)
   HIPNGARG((hipng_structp hipng_ptr, hipng_size_t size));
#endif

/* Moved from pngconf.h in 1.4.0 and modified to ensure setjmp/longjmp
 * match up.
 */
#ifdef HIPNG_SETJMP_SUPPORTED
/* This function returns the jmp_buf built in to *hipng_ptr.  It must be
 * supplied with an appropriate 'longjmp' function to use on that jmp_buf
 * unless the default error function is overridden in which case NULL is
 * acceptable.  The size of the jmp_buf is checked against the actual size
 * allocated by the library - the call will return NULL on a mismatch
 * indicating an ABI mismatch.
 */
extern HIPNG_EXPORT(jmp_buf*, hipng_set_longjmp_fn)
   HIPNGARG((hipng_structp hipng_ptr, hipng_longjmp_ptr longjmp_fn, size_t jmp_buf_size));
#  define hipng_jmpbuf(hipng_ptr) \
   (*hipng_set_longjmp_fn((hipng_ptr), longjmp, sizeof (jmp_buf)))
#else
#  define hipng_jmpbuf(hipng_ptr) \
   (LIBHIPNG_WAS_COMPILED_WITH__HIPNG_NO_SETJMP)
#endif

/* Reset the compression stream */
extern HIPNG_EXPORT(int,hipng_reset_zstream) HIPNGARG((hipng_structp hipng_ptr));

/* New functions added in libpng-1.0.2 (not enabled by default until 1.2.0) */
#ifdef HIPNG_USER_MEM_SUPPORTED
extern HIPNG_EXPORT(hipng_structp,hipng_create_read_struct_2)
   HIPNGARG((hipng_const_charp user_hipng_ver, hipng_voidp error_ptr,
   hipng_error_ptr error_fn, hipng_error_ptr warn_fn, hipng_voidp mem_ptr,
   hipng_malloc_ptr malloc_fn, hipng_free_ptr free_fn)) HIPNG_ALLOCATED;
extern HIPNG_EXPORT(hipng_structp,hipng_create_write_struct_2)
   HIPNGARG((hipng_const_charp user_hipng_ver, hipng_voidp error_ptr,
   hipng_error_ptr error_fn, hipng_error_ptr warn_fn, hipng_voidp mem_ptr,
   hipng_malloc_ptr malloc_fn, hipng_free_ptr free_fn)) HIPNG_ALLOCATED;
#endif

/* Write the PNG file signature. */
extern HIPNG_EXPORT(void,hipng_write_sig) HIPNGARG((hipng_structp hipng_ptr));

/* Write a PNG chunk - size, type, (optional) data, CRC. */
extern HIPNG_EXPORT(void,hipng_write_chunk) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytep chunk_name, hipng_bytep data, hipng_size_t length));

/* Write the start of a PNG chunk - length and chunk name. */
extern HIPNG_EXPORT(void,hipng_write_chunk_start) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytep chunk_name, hipng_uint_32 length));

/* Write the data of a PNG chunk started with hipng_write_chunk_start(). */
extern HIPNG_EXPORT(void,hipng_write_chunk_data) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytep data, hipng_size_t length));

/* Finish a chunk started with hipng_write_chunk_start() (includes CRC). */
extern HIPNG_EXPORT(void,hipng_write_chunk_end) HIPNGARG((hipng_structp hipng_ptr));

/* Allocate and initialize the info structure */
extern HIPNG_EXPORT(hipng_infop,hipng_create_info_struct)
   HIPNGARG((hipng_structp hipng_ptr)) HIPNG_ALLOCATED;

extern HIPNG_EXPORT(void,hipng_info_init_3) HIPNGARG((hipng_infopp info_ptr,
    hipng_size_t hipng_info_struct_size));

/* Writes all the PNG information before the image. */
extern HIPNG_EXPORT(void,hipng_write_info_before_PLTE) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr));
extern HIPNG_EXPORT(void,hipng_write_info) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr));

#ifdef HIPNG_SEQUENTIAL_READ_SUPPORTED
/* Read the information before the actual image data. */
extern HIPNG_EXPORT(void,hipng_read_info) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr));
#endif

#ifdef HIPNG_TIME_RFC1123_SUPPORTED
extern HIPNG_EXPORT(hipng_charp,hipng_convert_to_rfc1123)
   HIPNGARG((hipng_structp hipng_ptr, hipng_timep ptime));
#endif

#ifdef HIPNG_CONVERT_tIME_SUPPORTED
/* Convert from a struct tm to hipng_time */
extern HIPNG_EXPORT(void,hipng_convert_from_struct_tm) HIPNGARG((hipng_timep ptime,
   struct tm FAR * ttime));

/* Convert from time_t to hipng_time.  Uses gmtime() */
extern HIPNG_EXPORT(void,hipng_convert_from_time_t) HIPNGARG((hipng_timep ptime,
   time_t ttime));
#endif /* HIPNG_CONVERT_tIME_SUPPORTED */

#ifdef HIPNG_READ_EXPAND_SUPPORTED
/* Expand data to 24-bit RGB, or 8-bit grayscale, with alpha if available. */
extern HIPNG_EXPORT(void,hipng_set_expand) HIPNGARG((hipng_structp hipng_ptr));
extern HIPNG_EXPORT(void,hipng_set_expand_gray_1_2_4_to_8) HIPNGARG((hipng_structp
  hipng_ptr));
extern HIPNG_EXPORT(void,hipng_set_palette_to_rgb) HIPNGARG((hipng_structp hipng_ptr));
extern HIPNG_EXPORT(void,hipng_set_tRNS_to_alpha) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_BGR_SUPPORTED) || defined(HIPNG_WRITE_BGR_SUPPORTED)
/* Use blue, green, red order for pixels. */
extern HIPNG_EXPORT(void,hipng_set_bgr) HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_READ_GRAY_TO_RGB_SUPPORTED
/* Expand the grayscale to 24-bit RGB if necessary. */
extern HIPNG_EXPORT(void,hipng_set_gray_to_rgb) HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_READ_RGB_TO_GRAY_SUPPORTED
/* Reduce RGB to grayscale. */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_rgb_to_gray) HIPNGARG((hipng_structp hipng_ptr,
   int error_action, double red, double green ));
#endif
extern HIPNG_EXPORT(void,hipng_set_rgb_to_gray_fixed) HIPNGARG((hipng_structp hipng_ptr,
   int error_action, hipng_fixed_point red, hipng_fixed_point green ));
extern HIPNG_EXPORT(hipng_byte,hipng_get_rgb_to_gray_status) HIPNGARG((hipng_structp
   hipng_ptr));
#endif

extern HIPNG_EXPORT(void,hipng_build_grayscale_palette) HIPNGARG((int bit_depth,
   hipng_colorp palette));

#ifdef HIPNG_READ_STRIP_ALPHA_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_strip_alpha) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_SWAP_ALPHA_SUPPORTED) || \
    defined(HIPNG_WRITE_SWAP_ALPHA_SUPPORTED)
extern HIPNG_EXPORT(void,hipng_set_swap_alpha) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_INVERT_ALPHA_SUPPORTED) || \
    defined(HIPNG_WRITE_INVERT_ALPHA_SUPPORTED)
extern HIPNG_EXPORT(void,hipng_set_invert_alpha) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_FILLER_SUPPORTED) || defined(HIPNG_WRITE_FILLER_SUPPORTED)
/* Add a filler byte to 8-bit Gray or 24-bit RGB images. */
extern HIPNG_EXPORT(void,hipng_set_filler) HIPNGARG((hipng_structp hipng_ptr,
   hipng_uint_32 filler, int flags));
/* The values of the HIPNG_FILLER_ defines should NOT be changed */
#define HIPNG_FILLER_BEFORE 0
#define HIPNG_FILLER_AFTER 1
/* Add an alpha byte to 8-bit Gray or 24-bit RGB images. */
extern HIPNG_EXPORT(void,hipng_set_add_alpha) HIPNGARG((hipng_structp hipng_ptr,
   hipng_uint_32 filler, int flags));
#endif /* HIPNG_READ_FILLER_SUPPORTED || HIPNG_WRITE_FILLER_SUPPORTED */

#if defined(HIPNG_READ_SWAP_SUPPORTED) || defined(HIPNG_WRITE_SWAP_SUPPORTED)
/* Swap bytes in 16-bit depth files. */
extern HIPNG_EXPORT(void,hipng_set_swap) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_PACK_SUPPORTED) || defined(HIPNG_WRITE_PACK_SUPPORTED)
/* Use 1 byte per pixel in 1, 2, or 4-bit depth files. */
extern HIPNG_EXPORT(void,hipng_set_packing) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_PACKSWAP_SUPPORTED) || defined(HIPNG_WRITE_PACKSWAP_SUPPORTED)
/* Swap packing order of pixels in bytes. */
extern HIPNG_EXPORT(void,hipng_set_packswap) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_SHIFT_SUPPORTED) || defined(HIPNG_WRITE_SHIFT_SUPPORTED)
/* Converts files to legal bit depths. */
extern HIPNG_EXPORT(void,hipng_set_shift) HIPNGARG((hipng_structp hipng_ptr,
   hipng_color_8p true_bits));
#endif

#if defined(HIPNG_READ_INTERLACING_SUPPORTED) || \
    defined(HIPNG_WRITE_INTERLACING_SUPPORTED)
/* Have the code handle the interlacing.  Returns the number of passes. */
extern HIPNG_EXPORT(int,hipng_set_interlace_handling) HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_READ_INVERT_SUPPORTED) || defined(HIPNG_WRITE_INVERT_SUPPORTED)
/* Invert monochrome files */
extern HIPNG_EXPORT(void,hipng_set_invert_mono) HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_READ_BACKGROUND_SUPPORTED
/* Handle alpha and tRNS by replacing with a background color. */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_background) HIPNGARG((hipng_structp hipng_ptr,
   hipng_color_16p background_color, int background_gamma_code,
   int need_expand, double background_gamma));
#endif
#define HIPNG_BACKGROUND_GAMMA_UNKNOWN 0
#define HIPNG_BACKGROUND_GAMMA_SCREEN  1
#define HIPNG_BACKGROUND_GAMMA_FILE    2
#define HIPNG_BACKGROUND_GAMMA_UNIQUE  3
#endif

#ifdef HIPNG_READ_16_TO_8_SUPPORTED
/* Strip the second byte of information from a 16-bit depth file. */
extern HIPNG_EXPORT(void,hipng_set_strip_16) HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_READ_DITHER_SUPPORTED
/* Turn on dithering, and reduce the palette to the number of colors available. */
extern HIPNG_EXPORT(void,hipng_set_dither) HIPNGARG((hipng_structp hipng_ptr,
   hipng_colorp palette, int num_palette, int maximum_colors,
   hipng_uint_16p histogram, int full_dither));
#endif

#ifdef HIPNG_READ_GAMMA_SUPPORTED
/* Handle gamma correction. Screen_gamma=(display_exponent) */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_gamma) HIPNGARG((hipng_structp hipng_ptr,
   double screen_gamma, double default_file_gamma));
#endif
#endif

#ifdef HIPNG_ACCELERATE
typedef enum tag_HIPNG_FMT_E
{
    HIPNG_FMT_ARGB1555,
    HIPNG_FMT_ARGB4444,
    HIPNG_FMT_RGB565,
    HIPNG_FMT_RGB555,
    HIPNG_FMT_RGB444,
    HIPNG_FMT_BUTT
}HIPNG_FMT_E;

extern HIPNG_EXPORT(void, hipng_set_outfmt) HIPNGARG((hipng_structp hipng_ptr, HIPNG_FMT_E eOutFmt));
#endif


#ifdef HIPNG_WRITE_FLUSH_SUPPORTED
/* Set how many lines between output flushes - 0 for no flushing */
extern HIPNG_EXPORT(void,hipng_set_flush) HIPNGARG((hipng_structp hipng_ptr, int nrows));
/* Flush the current PNG output buffer */
extern HIPNG_EXPORT(void,hipng_write_flush) HIPNGARG((hipng_structp hipng_ptr));
#endif

/* Optional update palette with requested transformations */
extern HIPNG_EXPORT(void,hipng_start_read_image) HIPNGARG((hipng_structp hipng_ptr));

/* Optional call to update the users info structure */
extern HIPNG_EXPORT(void,hipng_read_update_info) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr));

#ifdef HIPNG_SEQUENTIAL_READ_SUPPORTED
/* Read one or more rows of image data. */
extern HIPNG_EXPORT(void,hipng_read_rows) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytepp row, hipng_bytepp display_row, hipng_uint_32 num_rows));
#endif

#ifdef HIPNG_SEQUENTIAL_READ_SUPPORTED
/* Read a row of data. */
extern HIPNG_EXPORT(void,hipng_read_row) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytep row,
   hipng_bytep display_row));
#endif

#ifdef HIPNG_ACCELERATE
/* enumeraton of status for png decoding */
typedef enum tagPNG_STATE_E
{
    PNG_STATE_NOSTART = 0x0,  /* no start decod or abort,such as destroying decoder when decoding */
    PNG_STATE_DECING,         /* decoding */
    PNG_STATE_FINISH,         /* finish decoding */
    PNG_STATE_ERR,            /* failed for decoding */
    PNG_STATE_BUTT
}PNG_STATE_E;

typedef enum {
    PNG_FALSE    = 0,
    PNG_TRUE     = 1,
}PNG_BOOL;
extern HIPNG_EXPORT(void, hipng_set_swdec) HIPNGARG((hipng_structp hipng_ptr));

extern HIPNG_EXPORT(void, hipng_get_state) HIPNGARG((hipng_structp hipng_ptr, PNG_BOOL bBlock,PNG_STATE_E *pState));

extern HIPNG_EXPORT(void, hipng_set_inflexion) HIPNGARG((hipng_structp hipng_ptr, 
    hipng_uint_32 u32InflexionSize));
#endif

#ifdef HIPNG_SEQUENTIAL_READ_SUPPORTED
/* Read the whole image into memory at once. */
extern HIPNG_EXPORT(void,hipng_read_image) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytepp image));

#ifdef HIPNG_ACCELERATE
extern HIPNG_EXPORT(void, hipng_read_image_async) HIPNGARG((hipng_structp hipng_ptr, 
    hipng_bytepp image));
#endif

#endif

/* Write a row of image data */
extern HIPNG_EXPORT(void,hipng_write_row) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytep row));

/* Write a few rows of image data */
extern HIPNG_EXPORT(void,hipng_write_rows) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytepp row, hipng_uint_32 num_rows));

/* Write the image data */
extern HIPNG_EXPORT(void,hipng_write_image) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytepp image));

/* Write the end of the PNG file. */
extern HIPNG_EXPORT(void,hipng_write_end) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr));

#ifdef HIPNG_SEQUENTIAL_READ_SUPPORTED
/* Read the end of the PNG file. */
extern HIPNG_EXPORT(void,hipng_read_end) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr));
#endif

/* Free any memory associated with the hipng_info_struct */
extern HIPNG_EXPORT(void,hipng_destroy_info_struct) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infopp info_ptr_ptr));

/* Free any memory associated with the hipng_struct and the hipng_info_structs */
extern HIPNG_EXPORT(void,hipng_destroy_read_struct) HIPNGARG((hipng_structpp
   hipng_ptr_ptr, hipng_infopp info_ptr_ptr, hipng_infopp end_info_ptr_ptr));

/* Free any memory associated with the hipng_struct and the hipng_info_structs */
extern HIPNG_EXPORT(void,hipng_destroy_write_struct)
   HIPNGARG((hipng_structpp hipng_ptr_ptr, hipng_infopp info_ptr_ptr));

/* Set the libpng method of handling chunk CRC errors */
extern HIPNG_EXPORT(void,hipng_set_crc_action) HIPNGARG((hipng_structp hipng_ptr,
   int crit_action, int ancil_action));

/* Values for hipng_set_crc_action() to say how to handle CRC errors in
 * ancillary and critical chunks, and whether to use the data contained
 * therein.  Note that it is impossible to "discard" data in a critical
 * chunk.  For versions prior to 0.90, the action was always error/quit,
 * whereas in version 0.90 and later, the action for CRC errors in ancillary
 * chunks is warn/discard.  These values should NOT be changed.
 *
 *      value                       action:critical     action:ancillary
 */
#define HIPNG_CRC_DEFAULT       0  /* error/quit          warn/discard data */
#define HIPNG_CRC_ERROR_QUIT    1  /* error/quit          error/quit        */
#define HIPNG_CRC_WARN_DISCARD  2  /* (INVALID)           warn/discard data */
#define HIPNG_CRC_WARN_USE      3  /* warn/use data       warn/use data     */
#define HIPNG_CRC_QUIET_USE     4  /* quiet/use data      quiet/use data    */
#define HIPNG_CRC_NO_CHANGE     5  /* use current value   use current value */

/* These functions give the user control over the scan-line filtering in
 * libpng and the compression methods used by zlib.  These functions are
 * mainly useful for testing, as the defaults should work with most users.
 * Those users who are tight on memory or want faster performance at the
 * expense of compression can modify them.  See the compression library
 * header file (zlib.h) for an explination of the compression functions.
 */

/* Set the filtering method(s) used by libpng.  Currently, the only valid
 * value for "method" is 0.
 */
extern HIPNG_EXPORT(void,hipng_set_filter) HIPNGARG((hipng_structp hipng_ptr, int method,
   int filters));

/* Flags for hipng_set_filter() to say which filters to use.  The flags
 * are chosen so that they don't conflict with real filter types
 * below, in case they are supplied instead of the #defined constants.
 * These values should NOT be changed.
 */
#define HIPNG_NO_FILTERS     0x00
#define HIPNG_FILTER_NONE    0x08
#define HIPNG_FILTER_SUB     0x10
#define HIPNG_FILTER_UP      0x20
#define HIPNG_FILTER_AVG     0x40
#define HIPNG_FILTER_PAETH   0x80
#define HIPNG_ALL_FILTERS (HIPNG_FILTER_NONE | HIPNG_FILTER_SUB | HIPNG_FILTER_UP | \
                         HIPNG_FILTER_AVG | HIPNG_FILTER_PAETH)

/* Filter values (not flags) - used in pngwrite.c, pngwutil.c for now.
 * These defines should NOT be changed.
 */
#define HIPNG_FILTER_VALUE_NONE  0
#define HIPNG_FILTER_VALUE_SUB   1
#define HIPNG_FILTER_VALUE_UP    2
#define HIPNG_FILTER_VALUE_AVG   3
#define HIPNG_FILTER_VALUE_PAETH 4
#define HIPNG_FILTER_VALUE_LAST  5

#ifdef HIPNG_WRITE_WEIGHTED_FILTER_SUPPORTED /* EXPERIMENTAL */
/* The "heuristic_method" is given by one of the HIPNG_FILTER_HEURISTIC_
 * defines, either the default (minimum-sum-of-absolute-differences), or
 * the experimental method (weighted-minimum-sum-of-absolute-differences).
 *
 * Weights are factors >= 1.0, indicating how important it is to keep the
 * filter type consistent between rows.  Larger numbers mean the current
 * filter is that many times as likely to be the same as the "num_weights"
 * previous filters.  This is cumulative for each previous row with a weight.
 * There needs to be "num_weights" values in "filter_weights", or it can be
 * NULL if the weights aren't being specified.  Weights have no influence on
 * the selection of the first row filter.  Well chosen weights can (in theory)
 * improve the compression for a given image.
 *
 * Costs are factors >= 1.0 indicating the relative decoding costs of a
 * filter type.  Higher costs indicate more decoding expense, and are
 * therefore less likely to be selected over a filter with lower computational
 * costs.  There needs to be a value in "filter_costs" for each valid filter
 * type (given by HIPNG_FILTER_VALUE_LAST), or it can be NULL if you aren't
 * setting the costs.  Costs try to improve the speed of decompression without
 * unduly increasing the compressed image size.
 *
 * A negative weight or cost indicates the default value is to be used, and
 * values in the range [0.0, 1.0) indicate the value is to remain unchanged.
 * The default values for both weights and costs are currently 1.0, but may
 * change if good general weighting/cost heuristics can be found.  If both
 * the weights and costs are set to 1.0, this degenerates the WEIGHTED method
 * to the UNWEIGHTED method, but with added encoding time/computation.
 */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_filter_heuristics) HIPNGARG((hipng_structp hipng_ptr,
   int heuristic_method, int num_weights, hipng_doublep filter_weights,
   hipng_doublep filter_costs));
#endif
#endif /*  HIPNG_WRITE_WEIGHTED_FILTER_SUPPORTED */

/* Heuristic used for row filter selection.  These defines should NOT be
 * changed.
 */
#define HIPNG_FILTER_HEURISTIC_DEFAULT    0  /* Currently "UNWEIGHTED" */
#define HIPNG_FILTER_HEURISTIC_UNWEIGHTED 1  /* Used by libpng < 0.95 */
#define HIPNG_FILTER_HEURISTIC_WEIGHTED   2  /* Experimental feature */
#define HIPNG_FILTER_HEURISTIC_LAST       3  /* Not a valid value */

/* Set the library compression level.  Currently, valid values range from
 * 0 - 9, corresponding directly to the zlib compression levels 0 - 9
 * (0 - no compression, 9 - "maximal" compression).  Note that tests have
 * shown that zlib compression levels 3-6 usually perform as well as level 9
 * for PNG images, and do considerably fewer caclulations.  In the future,
 * these values may not correspond directly to the zlib compression levels.
 */
extern HIPNG_EXPORT(void,hipng_set_compression_level) HIPNGARG((hipng_structp hipng_ptr,
   int level));

extern HIPNG_EXPORT(void,hipng_set_compression_mem_level)
   HIPNGARG((hipng_structp hipng_ptr, int mem_level));

extern HIPNG_EXPORT(void,hipng_set_compression_strategy)
   HIPNGARG((hipng_structp hipng_ptr, int strategy));

extern HIPNG_EXPORT(void,hipng_set_compression_window_bits)
   HIPNGARG((hipng_structp hipng_ptr, int window_bits));

extern HIPNG_EXPORT(void,hipng_set_compression_method) HIPNGARG((hipng_structp hipng_ptr,
   int method));

/* These next functions are called for input/output, memory, and error
 * handling.  They are in the file pngrio.c, pngwio.c, and pngerror.c,
 * and call standard C I/O routines such as fread(), fwrite(), and
 * fprintf().  These functions can be made to use other I/O routines
 * at run time for those applications that need to handle I/O in a
 * different manner by calling hipng_set_???_fn().  See libpng.txt for
 * more information.
 */

#ifdef HIPNG_STDIO_SUPPORTED
/* Initialize the input/output for the PNG file to the default functions. */
extern HIPNG_EXPORT(void,hipng_init_io) HIPNGARG((hipng_structp hipng_ptr, hipng_FILE_p fp));
#endif

/* Replace the (error and abort), and warning functions with user
 * supplied functions.  If no messages are to be printed you must still
 * write and use replacement functions. The replacement error_fn should
 * still do a longjmp to the last setjmp location if you are using this
 * method of error handling.  If error_fn or warning_fn is NULL, the
 * default function will be used.
 */

extern HIPNG_EXPORT(void,hipng_set_error_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp error_ptr, hipng_error_ptr error_fn, hipng_error_ptr warning_fn));

/* Return the user pointer associated with the error functions */
extern HIPNG_EXPORT(hipng_voidp,hipng_get_error_ptr) HIPNGARG((hipng_structp hipng_ptr));

/* Replace the default data output functions with a user supplied one(s).
 * If buffered output is not used, then output_flush_fn can be set to NULL.
 * If HIPNG_WRITE_FLUSH_SUPPORTED is not defined at libpng compile time
 * output_flush_fn will be ignored (and thus can be NULL).
 * It is probably a mistake to use NULL for output_flush_fn if
 * write_data_fn is not also NULL unless you have built libpng with
 * HIPNG_WRITE_FLUSH_SUPPORTED undefined, because in this case libpng's
 * default flush function, which uses the standard *FILE structure, will
 * be used.
 */
extern HIPNG_EXPORT(void,hipng_set_write_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp io_ptr, hipng_rw_ptr write_data_fn, hipng_flush_ptr output_flush_fn));

/* Replace the default data input function with a user supplied one. */
extern HIPNG_EXPORT(void,hipng_set_read_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp io_ptr, hipng_rw_ptr read_data_fn));

/* Return the user pointer associated with the I/O functions */
extern HIPNG_EXPORT(hipng_voidp,hipng_get_io_ptr) HIPNGARG((hipng_structp hipng_ptr));

extern HIPNG_EXPORT(void,hipng_set_read_status_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_read_status_ptr read_row_fn));

extern HIPNG_EXPORT(void,hipng_set_write_status_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_write_status_ptr write_row_fn));

#ifdef HIPNG_USER_MEM_SUPPORTED
/* Replace the default memory allocation functions with user supplied one(s). */
extern HIPNG_EXPORT(void,hipng_set_mem_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp mem_ptr, hipng_malloc_ptr malloc_fn, hipng_free_ptr free_fn));
/* Return the user pointer associated with the memory functions */
extern HIPNG_EXPORT(hipng_voidp,hipng_get_mem_ptr) HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_READ_USER_TRANSFORM_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_read_user_transform_fn) HIPNGARG((hipng_structp
   hipng_ptr, hipng_user_transform_ptr read_user_transform_fn));
#endif

#ifdef HIPNG_WRITE_USER_TRANSFORM_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_write_user_transform_fn) HIPNGARG((hipng_structp
   hipng_ptr, hipng_user_transform_ptr write_user_transform_fn));
#endif

#if defined(HIPNG_READ_USER_TRANSFORM_SUPPORTED) || \
    defined(HIPNG_WRITE_USER_TRANSFORM_SUPPORTED)
extern HIPNG_EXPORT(void,hipng_set_user_transform_info) HIPNGARG((hipng_structp
   hipng_ptr, hipng_voidp user_transform_ptr, int user_transform_depth,
   int user_transform_channels));
/* Return the user pointer associated with the user transform functions */
extern HIPNG_EXPORT(hipng_voidp,hipng_get_user_transform_ptr)
   HIPNGARG((hipng_structp hipng_ptr));
#endif

#ifdef HIPNG_USER_CHUNKS_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_read_user_chunk_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp user_chunk_ptr, hipng_user_chunk_ptr read_user_chunk_fn));
extern HIPNG_EXPORT(hipng_voidp,hipng_get_user_chunk_ptr) HIPNGARG((hipng_structp
   hipng_ptr));
#endif

#ifdef HIPNG_PROGRESSIVE_READ_SUPPORTED
/* Sets the function callbacks for the push reader, and a pointer to a
 * user-defined structure available to the callback functions.
 */
extern HIPNG_EXPORT(void,hipng_set_progressive_read_fn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp progressive_ptr,
   hipng_progressive_info_ptr info_fn, hipng_progressive_row_ptr row_fn,
   hipng_progressive_end_ptr end_fn));

/* Returns the user pointer associated with the push read functions */
extern HIPNG_EXPORT(hipng_voidp,hipng_get_progressive_ptr)
   HIPNGARG((hipng_structp hipng_ptr));

/* Function to be called when data becomes available */
extern HIPNG_EXPORT(void,hipng_process_data) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_bytep buffer, hipng_size_t buffer_size));

/* Function that combines rows.  Not very much different than the
 * hipng_combine_row() call.  Is this even used?????
 */
extern HIPNG_EXPORT(void,hipng_progressive_combine_row) HIPNGARG((hipng_structp hipng_ptr,
   hipng_bytep old_row, hipng_bytep new_row));
#endif /* HIPNG_PROGRESSIVE_READ_SUPPORTED */

extern HIPNG_EXPORT(hipng_voidp,hipng_malloc) HIPNGARG((hipng_structp hipng_ptr,
   hipng_alloc_size_t size)) HIPNG_ALLOCATED;
/* Added at libpng version 1.4.0 */
extern HIPNG_EXPORT(hipng_voidp,hipng_calloc) HIPNGARG((hipng_structp hipng_ptr,
   hipng_alloc_size_t size)) HIPNG_ALLOCATED;

/* Added at libpng version 1.2.4 */
extern HIPNG_EXPORT(hipng_voidp,hipng_malloc_warn) HIPNGARG((hipng_structp hipng_ptr,
   hipng_alloc_size_t size)) HIPNG_ALLOCATED;

/* Frees a pointer allocated by hipng_malloc() */
extern HIPNG_EXPORT(void,hipng_free) HIPNGARG((hipng_structp hipng_ptr, hipng_voidp ptr));

/* Free data that was allocated internally */
extern HIPNG_EXPORT(void,hipng_free_data) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_32 free_me, int num));
/* Reassign responsibility for freeing existing data, whether allocated
 * by libpng or by the application */
extern HIPNG_EXPORT(void,hipng_data_freer) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int freer, hipng_uint_32 mask));
/* Assignments for hipng_data_freer */
#define HIPNG_DESTROY_WILL_FREE_DATA 1
#define HIPNG_SET_WILL_FREE_DATA 1
#define HIPNG_USER_WILL_FREE_DATA 2
/* Flags for hipng_ptr->free_me and info_ptr->free_me */
#define HIPNG_FREE_HIST 0x0008
#define HIPNG_FREE_ICCP 0x0010
#define HIPNG_FREE_SPLT 0x0020
#define HIPNG_FREE_ROWS 0x0040
#define HIPNG_FREE_PCAL 0x0080
#define HIPNG_FREE_SCAL 0x0100
#define HIPNG_FREE_UNKN 0x0200
#define HIPNG_FREE_LIST 0x0400
#define HIPNG_FREE_PLTE 0x1000
#define HIPNG_FREE_TRNS 0x2000
#define HIPNG_FREE_TEXT 0x4000
#define HIPNG_FREE_ALL  0x7fff
#define HIPNG_FREE_MUL  0x4220 /* HIPNG_FREE_SPLT|HIPNG_FREE_TEXT|HIPNG_FREE_UNKN */

#ifdef HIPNG_USER_MEM_SUPPORTED
extern HIPNG_EXPORT(hipng_voidp,hipng_malloc_default) HIPNGARG((hipng_structp hipng_ptr,
   hipng_alloc_size_t size)) HIPNG_ALLOCATED;
extern HIPNG_EXPORT(void,hipng_free_default) HIPNGARG((hipng_structp hipng_ptr,
   hipng_voidp ptr));
#endif

#ifndef HIPNG_NO_ERROR_TEXT
/* Fatal error in PNG image of libpng - can't continue */
extern HIPNG_EXPORT(void,hipng_error) HIPNGARG((hipng_structp hipng_ptr,
   hipng_const_charp error_message)) HIPNG_NORETURN;

/* The same, but the chunk name is prepended to the error string. */
extern HIPNG_EXPORT(void,hipng_chunk_error) HIPNGARG((hipng_structp hipng_ptr,
   hipng_const_charp error_message)) HIPNG_NORETURN;

#else
/* Fatal error in PNG image of libpng - can't continue */
extern HIPNG_EXPORT(void,hipng_err) HIPNGARG((hipng_structp hipng_ptr)) HIPNG_NORETURN;
#endif

/* Non-fatal error in libpng.  Can continue, but may have a problem. */
extern HIPNG_EXPORT(void,hipng_warning) HIPNGARG((hipng_structp hipng_ptr,
   hipng_const_charp warning_message));

/* Non-fatal error in libpng, chunk name is prepended to message. */
extern HIPNG_EXPORT(void,hipng_chunk_warning) HIPNGARG((hipng_structp hipng_ptr,
   hipng_const_charp warning_message));

#ifdef HIPNG_BENIGN_ERRORS_SUPPORTED
/* Benign error in libpng.  Can continue, but may have a problem.
 * User can choose whether to handle as a fatal error or as a warning. */
extern HIPNG_EXPORT(void,hipng_benign_error) HIPNGARG((hipng_structp hipng_ptr,
   hipng_const_charp warning_message));

/* Same, chunk name is prepended to message. */
extern HIPNG_EXPORT(void,hipng_chunk_benign_error) HIPNGARG((hipng_structp hipng_ptr,
   hipng_const_charp warning_message));

extern HIPNG_EXPORT(void,hipng_set_benign_errors) HIPNGARG((hipng_structp
   hipng_ptr, int allowed));
#endif

/* The hipng_set_<chunk> functions are for storing values in the hipng_info_struct.
 * Similarly, the hipng_get_<chunk> calls are used to read values from the
 * hipng_info_struct, either storing the parameters in the passed variables, or
 * setting pointers into the hipng_info_struct where the data is stored.  The
 * hipng_get_<chunk> functions return a non-zero value if the data was available
 * in info_ptr, or return zero and do not change any of the parameters if the
 * data was not available.
 *
 * These functions should be used instead of directly accessing hipng_info
 * to avoid problems with future changes in the size and internal layout of
 * hipng_info_struct.
 */
/* Returns "flag" if chunk data is valid in info_ptr. */
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_valid) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr, hipng_uint_32 flag));

/* Returns number of bytes needed to hold a transformed row. */
extern HIPNG_EXPORT(hipng_size_t,hipng_get_rowbytes) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

#ifdef HIPNG_INFO_IMAGE_SUPPORTED
/* Returns row_pointers, which is an array of pointers to scanlines that was
 * returned from hipng_read_png().
 */
extern HIPNG_EXPORT(hipng_bytepp,hipng_get_rows) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));
/* Set row_pointers, which is an array of pointers to scanlines for use
 * by hipng_write_png().
 */
extern HIPNG_EXPORT(void,hipng_set_rows) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_bytepp row_pointers));
#endif

/* Returns number of color channels in image. */
extern HIPNG_EXPORT(hipng_byte,hipng_get_channels) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

#ifdef HIPNG_EASY_ACCESS_SUPPORTED
/* Returns image width in pixels. */
extern HIPNG_EXPORT(hipng_uint_32, hipng_get_image_width) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image height in pixels. */
extern HIPNG_EXPORT(hipng_uint_32, hipng_get_image_height) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image bit_depth. */
extern HIPNG_EXPORT(hipng_byte, hipng_get_bit_depth) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image color_type. */
extern HIPNG_EXPORT(hipng_byte, hipng_get_color_type) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image filter_type. */
extern HIPNG_EXPORT(hipng_byte, hipng_get_filter_type) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image interlace_type. */
extern HIPNG_EXPORT(hipng_byte, hipng_get_interlace_type) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image compression_type. */
extern HIPNG_EXPORT(hipng_byte, hipng_get_compression_type) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns image resolution in pixels per meter, from pHYs chunk data. */
extern HIPNG_EXPORT(hipng_uint_32, hipng_get_pixels_per_meter) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));
extern HIPNG_EXPORT(hipng_uint_32, hipng_get_x_pixels_per_meter) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));
extern HIPNG_EXPORT(hipng_uint_32, hipng_get_y_pixels_per_meter) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

/* Returns pixel aspect ratio, computed from pHYs chunk data.  */
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(float, hipng_get_pixel_aspect_ratio) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));
#endif

/* Returns image x, y offset in pixels or microns, from oFFs chunk data. */
extern HIPNG_EXPORT(hipng_int_32, hipng_get_x_offset_pixels) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));
extern HIPNG_EXPORT(hipng_int_32, hipng_get_y_offset_pixels) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));
extern HIPNG_EXPORT(hipng_int_32, hipng_get_x_offset_microns) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));
extern HIPNG_EXPORT(hipng_int_32, hipng_get_y_offset_microns) HIPNGARG((hipng_structp
hipng_ptr, hipng_infop info_ptr));

#endif /* HIPNG_EASY_ACCESS_SUPPORTED */

/* Returns pointer to signature string read from PNG header */
extern HIPNG_EXPORT(hipng_bytep,hipng_get_signature) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

#ifdef HIPNG_bKGD_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_bKGD) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_color_16p *background));
#endif

#ifdef HIPNG_bKGD_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_bKGD) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_color_16p background));
#endif

#ifdef HIPNG_cHRM_SUPPORTED
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_cHRM) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, double *white_x, double *white_y, double *red_x,
   double *red_y, double *green_x, double *green_y, double *blue_x,
   double *blue_y));
#endif
#ifdef HIPNG_FIXED_POINT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_cHRM_fixed) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_fixed_point *int_white_x, hipng_fixed_point
   *int_white_y, hipng_fixed_point *int_red_x, hipng_fixed_point *int_red_y,
   hipng_fixed_point *int_green_x, hipng_fixed_point *int_green_y, hipng_fixed_point
   *int_blue_x, hipng_fixed_point *int_blue_y));
#endif
#endif

#ifdef HIPNG_cHRM_SUPPORTED
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_cHRM) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, double white_x, double white_y, double red_x,
   double red_y, double green_x, double green_y, double blue_x, double blue_y));
#endif
#ifdef HIPNG_FIXED_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_cHRM_fixed) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_fixed_point int_white_x, hipng_fixed_point int_white_y,
   hipng_fixed_point int_red_x, hipng_fixed_point int_red_y, hipng_fixed_point
   int_green_x, hipng_fixed_point int_green_y, hipng_fixed_point int_blue_x,
   hipng_fixed_point int_blue_y));
#endif
#endif

#ifdef HIPNG_gAMA_SUPPORTED
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_gAMA) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, double *file_gamma));
#endif
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_gAMA_fixed) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_fixed_point *int_file_gamma));
#endif

#ifdef HIPNG_gAMA_SUPPORTED
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_gAMA) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, double file_gamma));
#endif
extern HIPNG_EXPORT(void,hipng_set_gAMA_fixed) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_fixed_point int_file_gamma));
#endif

#ifdef HIPNG_hIST_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_hIST) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_16p *hist));
#endif

#ifdef HIPNG_hIST_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_hIST) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_16p hist));
#endif

extern HIPNG_EXPORT(hipng_uint_32,hipng_get_IHDR) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_32 *width, hipng_uint_32 *height,
   int *bit_depth, int *color_type, int *interlace_method,
   int *compression_method, int *filter_method));

extern HIPNG_EXPORT(void,hipng_set_IHDR) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_32 width, hipng_uint_32 height, int bit_depth,
   int color_type, int interlace_method, int compression_method,
   int filter_method));

#ifdef HIPNG_oFFs_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_oFFs) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_int_32 *offset_x, hipng_int_32 *offset_y,
   int *unit_type));
#endif

#ifdef HIPNG_oFFs_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_oFFs) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_int_32 offset_x, hipng_int_32 offset_y,
   int unit_type));
#endif

#ifdef HIPNG_pCAL_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_pCAL) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_charp *purpose, hipng_int_32 *X0, hipng_int_32 *X1,
   int *type, int *nparams, hipng_charp *units, hipng_charpp *params));
#endif

#ifdef HIPNG_pCAL_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_pCAL) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_charp purpose, hipng_int_32 X0, hipng_int_32 X1,
   int type, int nparams, hipng_charp units, hipng_charpp params));
#endif

#ifdef HIPNG_pHYs_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_pHYs) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_32 *res_x, hipng_uint_32 *res_y, int *unit_type));
#endif

#ifdef HIPNG_pHYs_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_pHYs) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_uint_32 res_x, hipng_uint_32 res_y, int unit_type));
#endif

extern HIPNG_EXPORT(hipng_uint_32,hipng_get_PLTE) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_colorp *palette, int *num_palette));

extern HIPNG_EXPORT(void,hipng_set_PLTE) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_colorp palette, int num_palette));

#ifdef HIPNG_sBIT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_sBIT) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_color_8p *sig_bit));
#endif

#ifdef HIPNG_sBIT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_sBIT) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_color_8p sig_bit));
#endif

#ifdef HIPNG_sRGB_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_sRGB) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int *intent));
#endif

#ifdef HIPNG_sRGB_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_sRGB) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int intent));
extern HIPNG_EXPORT(void,hipng_set_sRGB_gAMA_and_cHRM) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int intent));
#endif

#ifdef HIPNG_iCCP_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_iCCP) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_charpp name, int *compression_type,
   hipng_charpp profile, hipng_uint_32 *proflen));
   /* Note to maintainer: profile should be hipng_bytepp */
#endif

#ifdef HIPNG_iCCP_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_iCCP) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_charp name, int compression_type,
   hipng_charp profile, hipng_uint_32 proflen));
   /* Note to maintainer: profile should be hipng_bytep */
#endif

#ifdef HIPNG_sPLT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_sPLT) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_sPLT_tpp entries));
#endif

#ifdef HIPNG_sPLT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_sPLT) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_sPLT_tp entries, int nentries));
#endif

#ifdef HIPNG_TEXT_SUPPORTED
/* hipng_get_text also returns the number of text chunks in *num_text */
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_text) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_textp *text_ptr, int *num_text));
#endif

/* Note while hipng_set_text() will accept a structure whose text,
 * language, and  translated keywords are NULL pointers, the structure
 * returned by hipng_get_text will always contain regular
 * zero-terminated C strings.  They might be empty strings but
 * they will never be NULL pointers.
 */

#ifdef HIPNG_TEXT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_text) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_textp text_ptr, int num_text));
#endif

#ifdef HIPNG_tIME_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_tIME) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_timep *mod_time));
#endif

#ifdef HIPNG_tIME_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_tIME) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_timep mod_time));
#endif

#ifdef HIPNG_tRNS_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_tRNS) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_bytep *trans_alpha, int *num_trans,
   hipng_color_16p *trans_color));
#endif

#ifdef HIPNG_tRNS_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_tRNS) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_bytep trans_alpha, int num_trans,
   hipng_color_16p trans_color));
#endif

#ifdef HIPNG_tRNS_SUPPORTED
#endif

#ifdef HIPNG_sCAL_SUPPORTED
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_sCAL) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int *unit, double *width, double *height));
#else
#ifdef HIPNG_FIXED_POINT_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_sCAL_s) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int *unit, hipng_charpp swidth, hipng_charpp sheight));
#endif
#endif
#endif /* HIPNG_sCAL_SUPPORTED */

#ifdef HIPNG_sCAL_SUPPORTED
#ifdef HIPNG_FLOATING_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_sCAL) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int unit, double width, double height));
#else
#ifdef HIPNG_FIXED_POINT_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_sCAL_s) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int unit, hipng_charp swidth, hipng_charp sheight));
#endif
#endif
#endif /* HIPNG_sCAL_SUPPORTED || HIPNG_WRITE_sCAL_SUPPORTED */

#ifdef HIPNG_HANDLE_AS_UNKNOWN_SUPPORTED
/* Provide a list of chunks and how they are to be handled, if the built-in
   handling or default unknown chunk handling is not desired.  Any chunks not
   listed will be handled in the default manner.  The IHDR and IEND chunks
   must not be listed.
      keep = 0: follow default behaviour
           = 1: do not keep
           = 2: keep only if safe-to-copy
           = 3: keep even if unsafe-to-copy
*/
extern HIPNG_EXPORT(void, hipng_set_keep_unknown_chunks) HIPNGARG((hipng_structp
   hipng_ptr, int keep, hipng_bytep chunk_list, int num_chunks));
HIPNG_EXPORT(int,hipng_handle_as_unknown) HIPNGARG((hipng_structp hipng_ptr, hipng_bytep
   chunk_name));
#endif
#ifdef HIPNG_UNKNOWN_CHUNKS_SUPPORTED
extern HIPNG_EXPORT(void, hipng_set_unknown_chunks) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, hipng_unknown_chunkp unknowns, int num_unknowns));
extern HIPNG_EXPORT(void, hipng_set_unknown_chunk_location)
   HIPNGARG((hipng_structp hipng_ptr, hipng_infop info_ptr, int chunk, int location));
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_unknown_chunks) HIPNGARG((hipng_structp
   hipng_ptr, hipng_infop info_ptr, hipng_unknown_chunkpp entries));
#endif

/* Png_free_data() will turn off the "valid" flag for anything it frees.
 * If you need to turn it off for a chunk that your application has freed,
 * you can use hipng_set_invalid(hipng_ptr, info_ptr, HIPNG_INFO_CHNK);
 */
extern HIPNG_EXPORT(void, hipng_set_invalid) HIPNGARG((hipng_structp hipng_ptr,
   hipng_infop info_ptr, int mask));

#ifdef HIPNG_INFO_IMAGE_SUPPORTED
/* The "params" pointer is currently not used and is for future expansion. */
extern HIPNG_EXPORT(void, hipng_read_png) HIPNGARG((hipng_structp hipng_ptr,
                        hipng_infop info_ptr,
                        int transforms,
                        hipng_voidp params));
extern HIPNG_EXPORT(void, hipng_write_png) HIPNGARG((hipng_structp hipng_ptr,
                        hipng_infop info_ptr,
                        int transforms,
                        hipng_voidp params));

#ifdef HIPNG_ACCELERATE
extern HIPNG_EXPORT(void, hipng_read_hipng_async) HIPNGARG((hipng_structp hipng_ptr,
                        hipng_infop info_ptr,
                        int transforms,
                        hipng_voidp params));
#endif

#endif

extern HIPNG_EXPORT(hipng_charp,hipng_get_copyright) HIPNGARG((hipng_structp hipng_ptr));
extern HIPNG_EXPORT(hipng_charp,hipng_get_header_ver) HIPNGARG((hipng_structp hipng_ptr));
extern HIPNG_EXPORT(hipng_charp,hipng_get_header_version) HIPNGARG((hipng_structp hipng_ptr));
extern HIPNG_EXPORT(hipng_charp,hipng_get_libhipng_ver) HIPNGARG((hipng_structp hipng_ptr));

#ifdef HIPNG_MNG_FEATURES_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_permit_mng_features) HIPNGARG((hipng_structp
   hipng_ptr, hipng_uint_32 mng_features_permitted));
#endif

/* For use in hipng_set_keep_unknown, added to version 1.2.6 */
#define HIPNG_HANDLE_CHUNK_AS_DEFAULT   0
#define HIPNG_HANDLE_CHUNK_NEVER        1
#define HIPNG_HANDLE_CHUNK_IF_SAFE      2
#define HIPNG_HANDLE_CHUNK_ALWAYS       3

/* Strip the prepended error numbers ("#nnn ") from error and warning
 * messages before passing them to the error or warning handler.
 */
#ifdef HIPNG_ERROR_NUMBERS_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_strip_error_numbers) HIPNGARG((hipng_structp
   hipng_ptr, hipng_uint_32 strip_mode));
#endif

/* Added in libpng-1.2.6 */
#ifdef HIPNG_SET_USER_LIMITS_SUPPORTED
extern HIPNG_EXPORT(void,hipng_set_user_limits) HIPNGARG((hipng_structp
   hipng_ptr, hipng_uint_32 user_width_max, hipng_uint_32 user_height_max));
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_user_width_max) HIPNGARG((hipng_structp
   hipng_ptr));
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_user_height_max) HIPNGARG((hipng_structp
   hipng_ptr));
/* Added in libpng-1.4.0 */
extern HIPNG_EXPORT(void,hipng_set_chunk_cache_max) HIPNGARG((hipng_structp
   hipng_ptr, hipng_uint_32 user_chunk_cache_max));
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_chunk_cache_max)
   HIPNGARG((hipng_structp hipng_ptr));
#endif

#if defined(HIPNG_INCH_CONVERSIONS) && defined(HIPNG_FLOATING_POINT_SUPPORTED)
HIPNG_EXPORT(hipng_uint_32,hipng_get_pixels_per_inch) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

HIPNG_EXPORT(hipng_uint_32,hipng_get_x_pixels_per_inch) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

HIPNG_EXPORT(hipng_uint_32,hipng_get_y_pixels_per_inch) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

HIPNG_EXPORT(float,hipng_get_x_offset_inches) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

HIPNG_EXPORT(float,hipng_get_y_offset_inches) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr));

#ifdef HIPNG_pHYs_SUPPORTED
HIPNG_EXPORT(hipng_uint_32,hipng_get_pHYs_dpi) HIPNGARG((hipng_structp hipng_ptr,
hipng_infop info_ptr, hipng_uint_32 *res_x, hipng_uint_32 *res_y, int *unit_type));
#endif /* HIPNG_pHYs_SUPPORTED */
#endif  /* HIPNG_INCH_CONVERSIONS && HIPNG_FLOATING_POINT_SUPPORTED */

/* Added in libpng-1.4.0 */
#ifdef HIPNG_IO_STATE_SUPPORTED
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_io_state) HIPNGARG((hipng_structp hipng_ptr));

extern HIPNG_EXPORT(hipng_bytep,hipng_get_io_chunk_name)
   HIPNGARG((hipng_structp hipng_ptr));

/* The flags returned by hipng_get_io_state() are the following: */
#define HIPNG_IO_NONE        0x0000   /* no I/O at this moment */
#define HIPNG_IO_READING     0x0001   /* currently reading */
#define HIPNG_IO_WRITING     0x0002   /* currently writing */
#define HIPNG_IO_SIGNATURE   0x0010   /* currently at the file signature */
#define HIPNG_IO_CHUNK_HDR   0x0020   /* currently at the chunk header */
#define HIPNG_IO_CHUNK_DATA  0x0040   /* currently at the chunk data */
#define HIPNG_IO_CHUNK_CRC   0x0080   /* currently at the chunk crc */
#define HIPNG_IO_MASK_OP     0x000f   /* current operation: reading/writing */
#define HIPNG_IO_MASK_LOC    0x00f0   /* current location: sig/hdr/data/crc */
#endif /* ?HIPNG_IO_STATE_SUPPORTED */

/* Maintainer: Put new public prototypes here ^, in libpng.3, and project
 * defs
 */

#ifdef HIPNG_READ_COMPOSITE_NODIV_SUPPORTED
/* With these routines we avoid an integer divide, which will be slower on
 * most machines.  However, it does take more operations than the corresponding
 * divide method, so it may be slower on a few RISC systems.  There are two
 * shifts (by 8 or 16 bits) and an addition, versus a single integer divide.
 *
 * Note that the rounding factors are NOT supposed to be the same!  128 and
 * 32768 are correct for the NODIV code; 127 and 32767 are correct for the
 * standard method.
 *
 * [Optimized code by Greg Roelofs and Mark Adler...blame us for bugs. :-) ]
 */

 /* fg and bg should be in `gamma 1.0' space; alpha is the opacity          */

#  define hipng_composite(composite, fg, alpha, bg)                            \
     { hipng_uint_16 temp = (hipng_uint_16)((hipng_uint_16)(fg) * (hipng_uint_16)(alpha) \
                        +        (hipng_uint_16)(bg)*(hipng_uint_16)(255 -       \
                        (hipng_uint_16)(alpha)) + (hipng_uint_16)128);           \
       (composite) = (hipng_byte)((temp + (temp >> 8)) >> 8); }

#  define hipng_composite_16(composite, fg, alpha, bg)                         \
     { hipng_uint_32 temp = (hipng_uint_32)((hipng_uint_32)(fg) * (hipng_uint_32)(alpha) \
                        + (hipng_uint_32)(bg)*(hipng_uint_32)(65535L -           \
                        (hipng_uint_32)(alpha)) + (hipng_uint_32)32768L);        \
       (composite) = (hipng_uint_16)((temp + (temp >> 16)) >> 16); }

#else  /* Standard method using integer division */

#  define hipng_composite(composite, fg, alpha, bg)                            \
     (composite) = (hipng_byte)(((hipng_uint_16)(fg) * (hipng_uint_16)(alpha) +    \
       (hipng_uint_16)(bg) * (hipng_uint_16)(255 - (hipng_uint_16)(alpha)) +       \
       (hipng_uint_16)127) / 255)

#  define hipng_composite_16(composite, fg, alpha, bg)                         \
     (composite) = (hipng_uint_16)(((hipng_uint_32)(fg) * (hipng_uint_32)(alpha) + \
       (hipng_uint_32)(bg)*(hipng_uint_32)(65535L - (hipng_uint_32)(alpha)) +      \
       (hipng_uint_32)32767) / (hipng_uint_32)65535L)
#endif /* HIPNG_READ_COMPOSITE_NODIV_SUPPORTED */

#ifdef HIPNG_USE_READ_MACROS
/* Inline macros to do direct reads of bytes from the input buffer.
 * The hipng_get_int_32() routine assumes we are using two's complement
 * format for negative values, which is almost certainly true.
 */
/* We could make special-case BIG_ENDIAN macros that do direct reads here */
#  define hipng_get_uint_32(buf) \
     (((hipng_uint_32)(*(buf)) << 24) + \
      ((hipng_uint_32)(*((buf) + 1)) << 16) + \
      ((hipng_uint_32)(*((buf) + 2)) << 8) + \
      ((hipng_uint_32)(*((buf) + 3))))
#  define hipng_get_uint_16(buf) \
     (((hipng_uint_32)(*(buf)) << 8) + \
      ((hipng_uint_32)(*((buf) + 1))))
#ifdef HIPNG_GET_INT_32_SUPPORTED
#  define hipng_get_int_32(buf) \
     (((hipng_int_32)(*(buf)) << 24) + \
      ((hipng_int_32)(*((buf) + 1)) << 16) + \
      ((hipng_int_32)(*((buf) + 2)) << 8) + \
      ((hipng_int_32)(*((buf) + 3))))
#endif
#else
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_uint_32) HIPNGARG((hipng_bytep buf));
extern HIPNG_EXPORT(hipng_uint_16,hipng_get_uint_16) HIPNGARG((hipng_bytep buf));
#ifdef HIPNG_GET_INT_32_SUPPORTED
extern HIPNG_EXPORT(hipng_int_32,hipng_get_int_32) HIPNGARG((hipng_bytep buf));
#endif
#endif
extern HIPNG_EXPORT(hipng_uint_32,hipng_get_uint_31)
  HIPNGARG((hipng_structp hipng_ptr, hipng_bytep buf));
/* No hipng_get_int_16 -- may be added if there's a real need for it. */

/* Place a 32-bit number into a buffer in PNG byte order (big-endian). */
extern HIPNG_EXPORT(void,hipng_save_uint_32)
   HIPNGARG((hipng_bytep buf, hipng_uint_32 i));
extern HIPNG_EXPORT(void,hipng_save_int_32)
   HIPNGARG((hipng_bytep buf, hipng_int_32 i));

/* Place a 16-bit number into a buffer in PNG byte order.
 * The parameter is declared unsigned int, not hipng_uint_16,
 * just to avoid potential problems on pre-ANSI C compilers.
 */
extern HIPNG_EXPORT(void,hipng_save_uint_16)
   HIPNGARG((hipng_bytep buf, unsigned int i));
/* No hipng_save_int_16 -- may be added if there's a real need for it. */

/* ************************************************************************* */

/* Various modes of operation.  Note that after an init, mode is set to
 * zero automatically when the structure is created.
 */
#define HIPNG_HAVE_IHDR               0x01
#define HIPNG_HAVE_PLTE               0x02
#define HIPNG_HAVE_IDAT               0x04
#define HIPNG_AFTER_IDAT              0x08 /* Have complete zlib datastream */
#define HIPNG_HAVE_IEND               0x10
#define HIPNG_HAVE_gAMA               0x20
#define HIPNG_HAVE_cHRM               0x40

#ifdef __cplusplus
}
#endif

#endif /* HIPNG_VERSION_INFO_ONLY */
/* Do not put anything past this line */
#endif /* HIPNG_H */
