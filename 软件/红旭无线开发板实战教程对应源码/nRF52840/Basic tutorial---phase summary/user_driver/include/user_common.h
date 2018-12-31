/**
* @file         user_common.h
* @brief        各个点C文件用到的公共的变量或者函数或者宏变量等等
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/12/30, 初始化版本\n
*/
#ifndef USER_COMMON_H
#define USER_COMMON_H


/* 
=============
宏定义
=============
*/
#define COMMON_R_LED_NUMBER         26               ///< LED对应的GPIO为P0.26
#define COMMON_G_LED_NUMBER         15               ///< LED对应的GPIO为P1.15
#define COMMON_B_LED_NUMBER         13               ///< LED对应的GPIO为P1.13
#define DEFAULT_BLINK_FREQUENCY     1000             ///< 单位ms

/* 
=============
外部变量声明
=============
*/
extern uint8_t led_color;
extern uint8_t pwm_duty_cycle;
extern uint32_t blink_frequency;


#endif //USER_COMMON_H