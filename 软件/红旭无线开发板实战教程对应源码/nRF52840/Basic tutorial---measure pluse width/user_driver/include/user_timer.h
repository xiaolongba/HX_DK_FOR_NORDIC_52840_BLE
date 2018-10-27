/**
* @file         user_timer.h
* @brief        PPI+定时器1的相关函数的声明以及相关的宏定义
* @QQ Group     671139854
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/10/27, 初始化版本\n
*/
#ifndef USER_TIMER_H
#define USER_TIMER_H


/* 
=============
头文件包含
=============
*/
#include "nrf_drv_timer.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_gpiote.h"

/* 
=============
函数声明
=============
*/
/**
 * timer1初始化函数
 * @param[in]   p_instance:表示定时器的ID
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
void user_timer_init(nrfx_timer_t const * const  p_instance);


/**
 * 关掉Timer1
 * @param[in]   p_instance:表示定时器的ID
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
void user_timer_stop(nrfx_timer_t const * const  p_instance);


#endif
