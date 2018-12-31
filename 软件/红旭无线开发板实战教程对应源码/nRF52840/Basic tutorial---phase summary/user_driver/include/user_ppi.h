/**
* @file         user_ppi.h
* @brief        ppi相关函数的声明以及宏定义
* @author       Helon_Chan
* @website      http://bbs.wireless-tech.cn/
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                    Helon_Chan, 2018/12/26, 初始化版本\n
*/
#ifndef USER_PPI_H
#define USER_PPI_H

/*
===========================
头文件包含
=========================== 
*/

#include "nrfx_ppi.h"
#include "nrfx_gpiote.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_gpiote.h"
#include "user_log.h"
#include "nrf_drv_timer.h"
#include "nrf_gpio.h"
#include "nrfx_timer.h"
#include "user_common.h"
/*
===========================
宏定义
=========================== 
*/

#define KEY_NUMBER          13                        ///< 按键对应的GPIO为P0.13
#define R_LED_NUMBER        26                        ///< LED对应的GPIO为P0.26
#define G_LED_NUMBER        13+P0_PIN_NUM             ///< LED对应的GPIO为P1.13
#define B_LED_NUMBER        15+P0_PIN_NUM             ///< LED对应的GPIO为P1.15

#if HX_LOG_UART_ENABLED
#define NRF_LOG_INFO(...)
#endif

/*
===========================
外部变量声明
=========================== 
*/



/**
 * 初始化gpiote+timer0+ppi,用于LED菜单之子菜单PPI
 * @param[in]   led_color         :选择LED的颜色,详情参考user_common.h文头件
 * @param[in]   blink_interval_ms :选择LED的闪烁的频率，单位为ms
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/26, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/12/31, 不再将各功能的函数分开独立了，直接集成在该函数\n              
 */

void user_gpiote_timer0_ppi_init(uint8_t color, uint32_t blink_interval_ms);


/**
 * 取消初始化gpiote+timer0+ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/31, 初始化版本\n          
 */

void user_gpiote_timer0_ppi_uninit(void);

#endif /* USER_PPI_H */