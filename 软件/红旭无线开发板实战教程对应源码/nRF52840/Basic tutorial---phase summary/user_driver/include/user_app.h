/**
* @file         user_app.h
* @brief        应用层函数的相关声明  
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/12/02, 初始化版本\n
*/
#ifndef USER_APP_H
#define USER_APP_H

/* 
=============
头文件包含
=============
*/
#include "user_log.h"

/* 
=============
条件编译
=============
*/
#if HX_LOG_UART_ENABLED
#define HX_PRINTF(format, ...) user_customer_printf(format, ##__VA_ARGS__)
#else
#define HX_PRINTF(...)
#endif
/* 
=============
函数声明
=============
*/
/**
 * 应用层初始化
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/2, 初始化版本\n
 */
void user_app_init(void);

/**
 * 重新映射串口
 * @param[in]   format：输出的格式
 * @retval      ...：可变长度的参数
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/2, 初始化版本\n
 */
void user_customer_printf(char *format, ...);


/**
 * 串口接收处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/5, 初始化版本\n
 */
void user_uart_recevice_process(void);
#endif