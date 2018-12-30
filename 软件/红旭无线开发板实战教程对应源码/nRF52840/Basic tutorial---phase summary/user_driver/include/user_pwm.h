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
#include "low_power_pwm.h"
#include "user_log.h"

/* 
=============
宏定义
=============
*/

#define SOFTWARE_PWM            0                               ///< 使用硬件定时器产生PWM波形
#define HARDWARE_PWM            0                               ///< 使用硬件的PWM产生PWM波形
#define LOW_POWER_PWM           1                               ///< 使用RTC(32768Hz)产生PWM波形

#if HX_LOG_UART_ENABLED
#define NRF_LOG_INFO(...)
#endif

#define BROAD_LED               26
#define BROAD_LED_MASK          1<<BROAD_LED
/* 
=============
函数声明
=============
*/

/**
 * pwm初始化函数,通过硬件Timer1生成PWM波形，默认不使能APP_PWM
 * @param[in]   p_instance:指向app_pwm_t的实例指针
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
*               Ver0.0.2:
                  Helon_Chan, 2018/12/30, 屏蔽了硬件PWM和RTC定时器生成PWM的初始化函数\n            
 */

void user_pwm_init(void);


#endif  //USER_PWM_H