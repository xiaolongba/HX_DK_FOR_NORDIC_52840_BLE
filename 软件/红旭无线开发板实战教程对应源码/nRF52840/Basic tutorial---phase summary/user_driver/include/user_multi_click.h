/**
* @file         user_multi_click.h
* @brief        按键相关的函数声明以及宏定义
* @details      按键相关的函数声明以及一些结构体变量声明
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                    Helon_Chan, 2018/08/19, 初始化版本\n
*/
#ifndef USER_MULTI_CLICK_H
#define USER_MULTI_CLICK_H

/*
===========================
头文件包含
=========================== 
*/
#include "app_button.h"
#include "sdk_common.h"
#include "app_timer.h"
#include "user_log.h"
#include "nrf_drv_clock.h"
/*
===========================
宏定义
=========================== 
*/
#define BUTTON_COUNTS               1                           ///< 按键个数
#define BUTTON1                     13                          ///< 按键对应的GPIO口
#define TIMER_FOR_LONG_PRESSED      5000                        ///< 长按的时间,单位为ms

#if HX_LOG_UART_ENABLED
#define NRF_LOG_INFO(...)
#endif
/*
===========================
函数别名
=========================== 
*/
typedef void (*user_multi_click_handler_t)(uint8_t button_no,uint8_t *click_counts);

typedef void (*user_long_pressed_handler_t)(uint8_t button_no);

/*
===========================
结构体别名
=========================== 
*/
typedef struct
{
  uint8_t is_long_press : 1;
  uint8_t click_counts;
  app_button_cfg_t app_button_cfg[BUTTON_COUNTS];
  user_multi_click_handler_t user_multi_click_handler;
  user_long_pressed_handler_t user_long_pressed_handler;
} user_multi_click_t;

/*
===========================
函数声明
=========================== 
*/


/** 
* 填充按键的长按、单击以及多击的处理函数
* @param[in]   multi_click_handler    ：填充单击、多击的处理函数
* @param[in]   long_pressed_handler   ：填充长按处理函数
* @param[in]   button_counts          ：按键个数
* @retval      NRF_SUCCESS            ：表示初始化成功，其他值则初始化失败
* @note        初始化按键之前必须先初始化app_timer时钟,因为用到了消抖计时 
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/19, 初始化版本\n 
*/

ret_code_t user_multi_click_init(user_multi_click_handler_t multi_click_handler,user_long_pressed_handler_t long_pressed_handler,uint8_t button_counts);

/** 
* 按键计时所用到的时钟初始化，一定要user_multi_click_init之前调用该函数，否则按键不会正常工作
* @param[in]   null
* @retval      NRF_SUCCESS：表示初始化成功，其他值则初始化失败
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/26, 初始化版本\n 
*/
ret_code_t user_button_timer_init(void);

#endif /* USER_MULTI_CLICK_H */