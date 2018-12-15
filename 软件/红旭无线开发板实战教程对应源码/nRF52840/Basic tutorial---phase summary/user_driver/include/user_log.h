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
#include "app_uart.h"

/* 
=============
宏定义
=============
*/
#define UART_RX_BUFFER         16               ///< 串口接收缓冲区大小，单位字节
#define UART_TX_BUFFER         1024             ///< 串口发送缓冲区大小，单位字节。注意应该4字节对齐
/* 
=============
函数声明
=============
*/

/**
 * uart初始化函数 
 * @param[in]   app_uart_event_handler:uart事件回调处理函数  
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/11/28, 全面放弃使用官方的log模块，直接怼串口
*               Ver0.0.3:
                  Helon_Chan, 2018/12/15, 因为使用driver的uart会出现丢包的情况故放弃,直接使用官方的app_uart
 */

void user_log_init(app_uart_event_handler_t app_uart_event_handler);

#endif  //USER_LOG_H