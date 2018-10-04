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

#include "nrfx_ppi.h"
#include "nrfx_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_gpiote.h"


/*
===========================
宏定义
=========================== 
*/

#define KEY_NUMBER          13                        ///< 锟斤拷锟斤拷锟斤拷应锟斤拷GPIO锟斤拷为P0.13
#define LED_NUMBER          26                        ///< LED锟斤拷应锟斤拷GPIO锟斤拷为P0.26


/**
 * 初始化gpiote和ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/09/08, 初始化版本\n
 */

void user_app_gpiote_ppi_init(void);
#endif /* USER_APPLICATION_H */