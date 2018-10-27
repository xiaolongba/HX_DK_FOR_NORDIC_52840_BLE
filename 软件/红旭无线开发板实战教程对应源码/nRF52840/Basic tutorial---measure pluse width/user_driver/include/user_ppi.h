/**
* @file         user_ppi.h
* @brief        PPI的相关函数声明
* @details      使用PPI来计算脉冲宽度的相关函数声明以及相关的宏定义
* @author       Helon_Chan
* @QQ Group     671139854
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/10/27, 初始化版本\n
*/

#ifndef USER_PPI_H
#define USER_PPI_H

/* 
=============
头文件包含
=============
*/

#include "nrf_drv_ppi.h"

/* 
=============
函数声明
=============
*/

/**
 * ppi初始化函数
 * @param[in]   eep:event的地址
 * @param[in]   tep:task的地址
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
void user_ppi_init(uint32_t eep, uint32_t tep);

#endif