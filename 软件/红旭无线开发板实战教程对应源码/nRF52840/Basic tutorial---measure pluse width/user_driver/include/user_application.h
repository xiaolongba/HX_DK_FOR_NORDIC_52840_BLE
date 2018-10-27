/**
* @file         user_application.h
* @brief        pwm相关函数的声明以及宏定义
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/07/28, 初始化版本\n
*/
#ifndef USER_APPLICATION_H
#define USER_APPLICATION_H

/* 
=============
头文件包含
=============
*/
#include "user_log.h"
#include "user_pwm.h"
#include "user_timer.h"
#include "user_gpiote.h"
#include "user_ppi.h"
#include "nrf_gpio.h"
/* 
=============
宏定义
=============
*/



/*
=============
函数声明
=============
*/
/**
 * app初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/26, 初始化版本\n
 */
 void user_app_init(void);
 
#endif