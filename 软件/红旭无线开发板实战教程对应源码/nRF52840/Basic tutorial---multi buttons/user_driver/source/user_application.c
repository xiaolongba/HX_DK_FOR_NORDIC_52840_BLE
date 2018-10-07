/**
* @file         user_application.c
* @brief        实现用户逻辑功能相关的函数定义
* @details      用户调用自己写的驱动或者Nordic的外设驱动实现自定义的功能
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/08/19, 初始化版本\n
*/

/*
===========================
头文件包含
=========================== 
*/

#include "user_application.h"

/*
===========================
函数定义
=========================== 
*/


/**
 * 按键单击、多击处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
void user_multi_click_handler(uint8_t button_no, uint8_t *click_counts)
{
  switch(button_no)
  {
    case BUTTON1:
      NRF_LOG_INFO("click counts is %d\n",*click_counts);
      *click_counts = 0;
      break;
    default:
      break;
  }
}

/**
 * 按键长按处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
void user_long_pressed_handler(uint8_t button_no)
{
  switch(button_no)
  {
    case BUTTON1:
      NRF_LOG_INFO("gpio%d long pressed\n",button_no);      
      break;
    default:
      break;
  }
}
/**
 * 用户应用初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
void user_application_init(void)
{
  /* log函数初始化  */
  log_init();
  user_button_timer_init();
  user_multi_click_init(user_multi_click_handler,user_long_pressed_handler,BUTTON_COUNTS);
  NRF_LOG_INFO("/******************************************************************************/\n");
  NRF_LOG_INFO("                         Welcome to multi click demo project                    \n");
  NRF_LOG_INFO("                         website :bbs.wireless-tech.cn                          \n");
  NRF_LOG_INFO("                         QQ Group:671139854                                     \n");
  NRF_LOG_INFO("                         Author  :wireless-tech                                 \n");
  NRF_LOG_INFO("/******************************************************************************/\n");
}