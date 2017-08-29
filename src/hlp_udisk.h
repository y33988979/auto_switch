/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_UDISK_H__
#define __HLP_UDISK_H__

#include <common.h>
#include <config.h>
#include <hlp_core.h>


S8* hlp_get_udisk_path();
S32 hlp_udisk_mount_ok();
S32 hlp_udisk_init();

#endif /* __HLP_UDISK_H__ */

