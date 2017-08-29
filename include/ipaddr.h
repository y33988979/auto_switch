/*********************************************************************
    Copyright (c) 2008 by iPanel Technologies, Ltd.
    All rights reserved. You are not allowed to copy or distribute
    the code without permission.
    Description: IP address的原型/数据类型文件. 有疑问找开发4组.
*********************************************************************/

/*
** 任何struct/union体, 如果是模块私有的(不是用来在模块间按约定传递数据的), 严禁放在公共header里! 如, 可以放类型
** 定义: typedef struct tagMyStruct MyStruct; 但struct tagMyStruct的实体定义一定要放在模块内部的.c文件中!
*/

#ifndef __IPADDR_H__
#define __IPADDR_H__

/* IP address definition */
#ifdef __cplusplus
extern "C"
{
#endif

#include "ipanel_typedef.h"

        /* version definitions for IPANEL_IPADDR */
#define IPANEL_IP_VERSION_4       ((BYTE_T)4)
#define IPANEL_IP_VERSION_6       ((BYTE_T)6)

        /* raw IP data definitions */
        typedef UINT32_T    IPANEL_IPV4;
        typedef struct
        {
                UINT16_T ip[8];
        } IPANEL_IPV6;

        /* basic IP struct definition(HAVE_IPV6_SUPPORT is always defined) */
        typedef struct
        {
                BYTE_T  version;
                BYTE_T  padding1;
                BYTE_T  padding2;
                BYTE_T  padding3;
                union
                {
                        IPANEL_IPV4 ipv4;
                        IPANEL_IPV6 ipv6;
                } addr;
        } IPAddr0;

        /* IPANEL_IPADDR is for our own IPAddr type definition. */
        typedef IPAddr0 IPANEL_IPADDR;

        /* macros for assigning raw IP data to an IPAddr0 struct pointer */
#define IPAddr_setIPV4(ipaddr, ip4) \
            do{\
                IPAddr0 a={0};\
                *(ipaddr) = a;\
                (ipaddr)->version = IPANEL_IP_VERSION_4;\
                (ipaddr)->addr.ipv4 = (ip4);\
            } while(0)
#define IPAddr_setIPV6(ipaddr, p_ip6) \
            do{\
                  IPAddr0 a={0};\
                  *(ipaddr) = a;\
                  (ipaddr)->version = IPANEL_IP_VERSION_6;\
                  (ipaddr)->addr.ipv6 = *(IPANEL_IPV6*)(p_ip6);\
            } while(0)

        /* IP uitilities */
        int IPAddr_equal(IPANEL_IPADDR *ip1, IPANEL_IPADDR *ip2);

#define IPADDR_getFamilyFromVersion(addr) \
    ((addr)->version==IPANEL_IP_VERSION_4 ? IPANEL_AF_INET : ((addr)->version==IPANEL_IP_VERSION_6 ? IPANEL_AF_INET6 : 0))

#ifdef __cplusplus
}
#endif

#endif // __IPADDR_H__



