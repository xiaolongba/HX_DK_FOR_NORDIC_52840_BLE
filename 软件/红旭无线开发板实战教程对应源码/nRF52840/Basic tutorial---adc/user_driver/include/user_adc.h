/**
* @file         user_adc.h
* @brief        adc相关的函数声明或者宏定义
* @details      adc相关的函数声明或者宏定义
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/11/10, 初始化版本\n
*/
#ifndef USER_ADC_H
#define USER_ADC_H
/*
===========================
头文件包含
=========================== 
*/
#include "nrf_drv_saadc.h"
#include "user_log.h"
/*
===========================
函数声明
=========================== 
*/

/**
 * adc初始化函数
 * @param[in]   nrf_drv_saadc_event_handler:adc事件回调处理函数
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/10, 初始化版本\n
 */
void user_adc_init(nrfx_saadc_event_handler_t nrf_drv_saadc_event_handler,
                   nrf_saadc_value_t *m_nrf_saadc_value);

/**
 * 开始adc采样
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/11, 初始化版本\n
 */
void user_adc_sample_start(void);

#endif
