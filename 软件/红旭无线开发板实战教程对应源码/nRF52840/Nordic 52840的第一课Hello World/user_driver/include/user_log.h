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

/* =============
头文件包含
 =============*/
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
/**
 * log打印输出初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 */
 void log_init(void);


#endif  //USER_LOG_H