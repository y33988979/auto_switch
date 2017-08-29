/************************************************************/
/* file name : memmap.c                                     */
/* linux /dev/mem mmap support func                            */
/*                                                             */
/*                                                             */
/* Copyright 2005 huawei com.                               */
/* Author :zhouaidi(42136)                                    */
/* Create date: 2005-04-07                                    */
/* Modify history                                            */
/* 2005-06-12:	create manage link for successful mapped memory to avoid remap*/
/*				CNcomment:对映射成功空间建立管理链表，可以防止对重叠空间的重复映射   */
/* 2005-12-21:	add memunmap function                           */
/************************************************************/

#ifndef __MEMMAP_H__
#define __MEMMAP_H__

void * memmap(unsigned int phy_addr, unsigned int size);
int memunmap(void * addr_mapped);

#endif /* __MEMMAP_H__ */
