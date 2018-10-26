/**
* @file         user_application.c
* @brief        实现用户逻辑功能相关的函数定义
* @details      用户调用自己写的驱动或者Nordic的外设驱动实现自定义的功能
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/07/28, 初始化版本\n
*/

/* 
=============
头文件包含
=============
*/

#include "user_application.h"

/* 
=============
函数定义
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
 void user_app_init(void)
 {
   user_log_init();
   user_pwm_init();
 }