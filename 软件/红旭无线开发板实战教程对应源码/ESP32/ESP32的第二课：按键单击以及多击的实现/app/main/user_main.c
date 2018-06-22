/** 
* @file         user_app_main.c 
* @brief        用户应用程序入口
* @details      用户应用程序的入口文件,用户所有要实现的功能逻辑均是从该文件开始或者处理
* @author       Helon_Chan 
* @par Copyright (c):  
*               红旭无线开发团队
* @par History:          
*               Ver0.0.1:
                     Helon_Chan, 2018/06/04, 初始化版本\n 
*/

/* =============
头文件包含
 =============*/
#include <stdio.h>
#include "esp_system.h"
#include <esp_log.h>
#include "user_app.h"
/** 
 * 应用程序的函数入口
 * @param[in]   NULL
 * @retval      NULL              
 * @par         修改日志 
 *               Ver0.0.1:
                     Helon_Chan, 2018/06/04, 初始化版本\n 
 */
void app_main()
{
  /* 建议保留此输出打印SDK版本,用于以后出问题了可以有溯源 */
  ESP_LOGI("app_main","the esp32 sdk version :%s\n", esp_get_idf_version());
  user_app_key_init();
}