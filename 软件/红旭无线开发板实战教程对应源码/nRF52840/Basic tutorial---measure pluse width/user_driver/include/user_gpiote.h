/**
* @file         user_gpiote.h
* @brief        gpiote的相关函数声明
* @details      使用gpiote来计算脉冲宽度的相关函数声明以及相关的宏定义
* @author       Helon_Chan
* @QQ Group     671139854
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/10/27, 初始化版本\n
*/

#ifndef USER_GPIOTE_H
#define USER_GPIOTE_H

/* 
=============
头文件包含
=============
*/

#include "nrf_drv_gpiote.h"

/* 
=============
宏定义
=============
*/
#define GPIOTE_IN_PIN         31        ///<这个PIN脚用于接收PWM的输入，从而产生GPIO的IN_EVENT

/* 
=============
函数声明
=============
*/

/**
 * gpiote初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
 */
void user_gpiote_init(nrf_drv_gpiote_evt_handler_t evt_handler);

#endif