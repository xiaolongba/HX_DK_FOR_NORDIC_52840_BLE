/**
* @file         user_application.h
* @brief        pwm相关函数的声明以及宏定义
* @author       Helon_Chan
* @website      http://bbs.wireless-tech.cn/
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                    Helon_Chan, 2018/09/08, 初始化版本\n
*/
#ifndef USER_APPLICATION_H
#define USER_APPLICATION_H

/*
===========================
头文件包含
=========================== 
*/
#include "nrf_drv_ppi.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include "nrf_gpio.h"
#include "nrfx_timer.h"
#include "drivers/nrfx_common.h"
/*
===========================
宏定义
=========================== 
*/

#define KEY_NUMBER          13                        ///< 按键的引脚为P0.13
#define LED_NUMBER          26                        ///< LED的引脚为P0.26


/**
 * 初始化使用到的外设
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
void user_app_init(void);



#endif /* USER_APPLICATION_H */