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

/* =============
头文件包含
 =============*/
#include "nrf_drv_pwm.h"
#include "nrfx_pwm.h"
#include "user_log.h"
#include "nrf52840.h"
/* =============
宏定义
 =============*/

#define BROAD_LED               26
#define BROAD_LED_MASK          1<<26
/* =============
函数声明
 =============*/


/**
 * pwm初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
 */

void user_pwm_init(void);


#endif  //USER_PWM_H