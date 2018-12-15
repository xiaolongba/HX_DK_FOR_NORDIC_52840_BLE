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
结构体声明
=============
*/
/* led二级子菜单结构体 */
typedef struct
{
  uint8_t ppi_secondary_submenu : 1;
  uint8_t timer_secondary_submenu : 1;
  uint8_t pwm_secondary_sumenu : 1;  
  uint8_t led_primary_submenu : 1;
} led_menu_t;

/* 声明菜单结构体 */
typedef struct
{
  uint8_t button_submenu : 1;  
  uint8_t adc_sumenu : 1;
  uint8_t pluse_width_measure_submenu : 1;
  uint8_t main_menu : 1;
  led_menu_t led_menu;
} modular_test_menu_t;

/* 进入或者退出子菜单的枚举 */
enum em_submenu_action
{
  ENTER,
  EXIT,
};

/* 子菜单枚举 */
enum em_submenu
{
  MAIN_MENU,
  PRIMARY_BUTTON,
  PRIMARY_LED,
  PRIMARY_ADC,
  PRIMARY_PWM_MEASURE,
  SECONDARY_PPI,
  SECONDARY_PWM,
  SECONDARY_TIMER,
};
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
 * 主菜单信息显示
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
void main_menu_display(void);

#endif