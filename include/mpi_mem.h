/******************************************************************************

Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : mpi_mem.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2006-07-18
Last Modified :
Description   :
Function List :
History       :
******************************************************************************/

#ifndef __MPI_MEM_H__
#define __MPI_MEM_H__

#include "hi_type.h"
#include "hi_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */



/******************************* MPI declaration *****************************/

/*malloc memory for mmz and map to user-state address, bufname and bufsize used to input,
	physic address and user-state used to output*/
/*CNcomment: 申请mmz内存，并映射用户态地址,bufname和bufsize作为输入, 物理地址和用户态虚拟地址作为输出 */
HI_S32 HI_MPI_MMZ_Malloc(HI_MMZ_BUF_S *pBuf);

/*free user-state map, release mmz memory, make sure that physic address, user-state address and lengh is right*/
/*CNcomment: 解除用户态地址的映射，并释放mmz内存,保证传入的物理地址、用户态虚拟地址和长度正确*/
HI_S32 HI_MPI_MMZ_Free(HI_MMZ_BUF_S *pBuf);

/*malloc mmz memory for appointed mmz name, return physic address*/
/*CNcomment: 指定mmz的名字申请mmz内存，返回物理地址*/
HI_VOID *HI_MPI_MMZ_New(HI_U32 size , HI_U32 align, HI_CHAR *mmz_name, HI_CHAR *mmb_name);

/*delete mmz memory*/
/*CNcomment: 释放mmz内存 */
HI_S32 HI_MPI_MMZ_Delete(HI_U32 phys_addr);

/*get physic address accordint to virtual address*/
/**CNcomment:  根据虚拟地址，获取对应的物理地址 */
HI_S32 HI_MPI_MMZ_GetPhyAddr(HI_VOID *refaddr, HI_U32 *phyaddr, HI_U32 *size);

/*map physic address of mmz memory to user-state virtual address, can appoint whether cached*/
/**CNcomment:  将mmz申请的物理地址映射成用户态虚拟地址，可以指定是否cached*/
HI_VOID *HI_MPI_MMZ_Map(HI_U32 phys_addr, HI_U32 cached);

/*unmap user-state address of mmz memory*/
/**CNcomment:  解除mmz内存用户态地址的映射 */
HI_S32 HI_MPI_MMZ_Unmap(HI_U32 phys_addr);

/*for cached memory, flush cache to memory*/
/**CNcomment:  对于cached内存，刷Dcache到内存 */
HI_S32 HI_MPI_MMZ_Flush(HI_U32 phys_addr);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __MPI_MEM_H__ */
