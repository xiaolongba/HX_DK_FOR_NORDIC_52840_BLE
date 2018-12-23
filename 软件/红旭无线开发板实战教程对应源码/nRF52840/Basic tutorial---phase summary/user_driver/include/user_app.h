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
#include "user_multi_click.h"

/* 
=============
条件编译
=============
*/
#if HX_LOG_UART_ENABLED
#define HX_PRINTF(format, ...) user_customer_printf(format, ##__VA_ARGS__)
#define NRF_LOG_INFO(...)
#else
#define HX_PRINTF(...)
#endif

/* 
=============
结构体声明
=============
*/

/* 声明菜单结构体 */
typedef struct
{
  uint8_t current_menu : 4;
  uint8_t secondary_submenu : 4;  
} modular_test_menu_t;

/* 菜单动作的枚举 */
enum em_submenu_action
{
  // PRIMARY_SUBMENU,                          ///< 一级子菜单
  // SECONDARY_SUBMENU,                        ///< 二级子菜单
  // THREE_LEVEL_SUBMENU,                      ///< 三级子菜单    
  BACK_TO_UPPER_MENU,                       ///< 返回上一次菜单  
  EXIT_PRIMARY_MENU,                        ///< 退出当前的一级子菜单
};

/* 子菜单枚举 */
enum em_submenu
{
  MAIN_MENU = 1,                            ///< 主菜单
  PRIMARY_BUTTON = 2,                       ///< 按键一级子菜单
  PRIMARY_LED = 3,                          ///< LED一级子菜单
  PRIMARY_ADC = 4,                          ///< ADC一级子菜单
  PRIMARY_PWM_MEASURE = 5,                  ///< PWM测量一级子菜单  
  SECONDARY_PPI = 6,                        ///< LED的二级子菜单PPI
  SECONDARY_PWM = 7,                        ///< LED的二级子菜单PWM
  SECONDARY_TIMER = 8,                      ///< LED的二级子菜单TIMER  
  SECONDARY_RGB = 9,                        ///< LED的二级子菜单RGB 
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