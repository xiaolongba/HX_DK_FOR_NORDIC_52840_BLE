/**
* @file         user_pwm.h
* @brief        pwm相关函数的声明以及宏定义
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/07/28, 初始化版本\n
*/
#ifndef USER_PWM_H
#define USER_PWM_H

/* 
=============
头文件包含
=============
*/
#include "app_pwm.h"
#include "user_log.h"
#include "nrf_drv_clock.h"
#include "user_common.h"
/* 
=============
宏定义
=============
*/
#if HX_LOG_UART_ENABLED
#define NRF_LOG_INFO(...)
#endif

/* 
=============
函数声明
=============
*/

/**
 * pwm初始化函数,通过Timer1生成PWM波形,默认的PWM占空比为百分之5
 * @param[in]   color:指定LED的颜色，详情请参考user_common.h头文件
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/12/30, 屏蔽了硬件PWM和硬件定时器生成PWM的初始化函数\n            
 *              Ver0.0.3:
                  Helon_Chan, 2018/12/31, 使能硬件PWM,屏蔽了RTC以及硬件PWM\n
 */
void user_pwm_init(uint32_t color,app_pwm_duty_t duty);

/**
 * 取消初始化app_pwm
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/31, 初始化版本\n           
*/
void user_pwm_uninit(void);

/**
 * 设置PWM的占空比
 * @param[in]   duty:想要设置的占空比，单位为百分比（%）
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/31, 初始化版本\n           
*/
void user_set_pwm_duty_cycle(app_pwm_duty_t duty);

#endif  //USER_PWM_H