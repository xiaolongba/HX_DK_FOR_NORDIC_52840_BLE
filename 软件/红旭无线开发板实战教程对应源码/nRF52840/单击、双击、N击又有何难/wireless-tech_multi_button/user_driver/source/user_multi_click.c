/**
* @file         user_multi_click.c
* @brief        按键相关的函数定义
* @details      用户可以在这里实现单击、多击以及长按的处理
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
#include "user_multi_click.h"

/*
===========================
静态函数声明
=========================== 
*/
static void user_button_handler(uint8_t pin_no, uint8_t button_action);

/*
===========================
全局变量
=========================== 
*/
/* 存放按键相关的参数 */
static user_multi_click_t gs_m_user_multi_click  = 
{
  .app_button_cfg = 
  {
    {BUTTON1,APP_BUTTON_ACTIVE_LOW,NRF_GPIO_PIN_PULLUP,user_button_handler},
  },
  .user_long_pressed_handler = NULL,
  .user_multi_click_handler =NULL,
};


/*
===========================
函数定义
=========================== 
*/



/** 
* 按键处理函数
* @param[in]   pin_no         ：表示进来按键处理函数的的引脚
* @param[in]   button_action  ：表示进来的按键的状态是按下还是释放
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/19, 初始化版本\n 
*/

static void user_button_handler(uint8_t pin_no, uint8_t button_action)
{
  switch(pin_no)
  {
    case BUTTON1:
      switch(button_action)
      {
        /* 按键按下 */
        case APP_BUTTON_PUSH:
          NRF_LOG_INFO("APP_BUTTON_PUSH\n");
          break;
        /* 按键释放 */
        case APP_BUTTON_RELEASE:
          NRF_LOG_INFO("APP_BUTTON_RELEASE\n");
          break;
        default:

          break;
      }
      break;
    default:
      break;
  }
}

/** 
* 开启32.768KHz的时钟,在sdk_config.h中可以选择是RC还是XTAL
* @param[in]   null
* @retval      null
* @note        如果使能了SOFT_DEVICE则不需要调用此函数，因为使能协议栈时会初始化LFCLK，这里我们没有使能协议栈故用户自己调用
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/19, 初始化版本\n 
*/
static ret_code_t lfclk_config(void)
{
  /* 初始化nrf_drv_clock模块 */
  ret_code_t err_code = nrf_drv_clock_init();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("nrf_drv_clock_init is %d\n",err_code);
    return err_code;
  }
  
  /* 请求LFCLK，即开启LFCLK时钟 */
  nrf_drv_clock_lfclk_request(NULL);

  return err_code;
}


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

ret_code_t user_multi_click_init(user_multi_click_handler_t multi_click_handler,user_long_pressed_handler_t long_pressed_handler,uint8_t button_counts)
{
  uint8_t loop_counts;
  ret_code_t err_code = NRF_SUCCESS;
  
  err_code = lfclk_config();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("lfclk_config is %d\n",err_code);
    return err_code;
  }

  err_code = app_timer_init();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_init is %d\n",err_code);
    return err_code;
  }  

  if((!multi_click_handler)||(!button_counts))
  {
    return NRF_ERROR_INVALID_PARAM;
  }

  gs_m_user_multi_click.user_multi_click_handler  = multi_click_handler;
  gs_m_user_multi_click.user_long_pressed_handler = long_pressed_handler;   

  /* 初始化按键并设置按键消抖时间为10ms */
  err_code = app_button_init(gs_m_user_multi_click.app_button_cfg, button_counts, APP_TIMER_TICKS(10));
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_button_init is %d\n",err_code);
    return err_code;
  }  
  /* 使能按键 */
  err_code = app_button_enable();  
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_button_enable is %d\n",err_code);
    return err_code;
  }    
  return err_code;
}
