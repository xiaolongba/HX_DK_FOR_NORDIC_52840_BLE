/**
* @file         user_log.h
* @brief        log函数的相关声明  
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/06/09, 初始化版本\n
*/
#ifndef USER_LOG_H
#define USER_LOG_H

/* 
=============
头文件包含
=============
*/
#include "nrf_drv_uart.h"
#include "app_error.h"
#include <stdio.h>
#include <stdarg.h>

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
 * uart初始化函数
 * @param[in]   nrf_drv_uart:串口实例
 * @param[in]   nrf_uart_event_handler:uart事件回调处理函数
  * @param[in]   rx_buffer:uart的rx缓冲区
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/11/28, 全面放弃使用官方的log模块，直接怼串口
 */
void user_uart_init(nrf_drv_uart_t *nrf_drv_uart,
										nrf_uart_event_handler_t nrf_uart_event_handler,										
										uint8_t *rx_buffer);


#endif  //USER_LOG_H