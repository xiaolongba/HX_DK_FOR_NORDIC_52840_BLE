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
  .user_multi_click_handler  = NULL,
  .click_counts              = 0,
  .is_long_press             = 0,
};

/* 用于计时长按的timer_id */
APP_TIMER_DEF(g_long_press_timer_id);
/* 用于计时短按的timer_id */
APP_TIMER_DEF(g_short_press_timer_id);

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
          /* 开始长按计时 */
          app_timer_start(g_long_press_timer_id,APP_TIMER_TICKS(TIMER_FOR_LONG_PRESSED),&pin_no);
          /* 暂停短按计时 */
          app_timer_stop(g_short_press_timer_id);
          break;
        /* 按键释放 */
        case APP_BUTTON_RELEASE:
          NRF_LOG_INFO("APP_BUTTON_RELEASE\n");
          /* 开始短按计时,如果释放之后150ms内没有新的按键按下则说明该按键已经完全释放.注意这个时长可以根据自己的需要进行更改 */
          app_timer_start(g_short_press_timer_id,APP_TIMER_TICKS(150),&pin_no);
          /* 暂停长按计时 */
          app_timer_stop(g_long_press_timer_id);
          if(gs_m_user_multi_click.is_long_press)
          {
            gs_m_user_multi_click.is_long_press = 0;
            gs_m_user_multi_click.click_counts  = 0;
          }
          else
          {
            gs_m_user_multi_click.click_counts++;
          }
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
* 按键长按处理函数
* @param[in]   p_context：传进来给按键处理函数使用的参数，这里传进来的是具体的哪个按键
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/26, 初始化版本\n 
*/

static void user_long_press_handler(void *p_context)
{
  gs_m_user_multi_click.user_long_pressed_handler(*((uint8_t*)(p_context)));
  gs_m_user_multi_click.is_long_press = 1;
}

/** 
* 按键短按处理函数
* @param[in]   p_context：传进来给按键处理函数使用的参数，这里传进来的是具体的哪个按键
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/26, 初始化版本\n 
*/

static void user_short_press_handler(void *p_context)
{
  gs_m_user_multi_click.user_multi_click_handler(*((uint8_t*)(p_context)),&gs_m_user_multi_click.click_counts);
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
ret_code_t lfclk_config(void)
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
* 按键计时所用到的时钟初始化，一定要user_multi_click_init之前调用该函数，否则按键不会正常工作
* @param[in]   null
* @retval      NRF_SUCCESS：表示初始化成功，其他值则初始化失败
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/26, 初始化版本\n 
*               Ver0.0.2: 
                  Helon_Chan, 2018/12/26, 屏蔽了app_timer初始化\n                   
*/
ret_code_t user_button_timer_init(void)
{
  ret_code_t err_code = NRF_SUCCESS;

  err_code = app_timer_create(&g_long_press_timer_id,APP_TIMER_MODE_SINGLE_SHOT,user_long_press_handler);
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_create is %d\n",err_code);
    return err_code;
  } 
  err_code = app_timer_create(&g_short_press_timer_id,APP_TIMER_MODE_SINGLE_SHOT,user_short_press_handler);
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_create is %d\n",err_code);
    return err_code;
  } 

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
*               Ver0.0.2: 
                  Helon_Chan, 2018/12/23, 初始化时不使能按键\n   
*               Ver0.0.3: 
                  Helon_Chan, 2018/12/26, 屏蔽了开启32.768KHz时钟的参数\n                                 
*/
ret_code_t user_multi_click_init(user_multi_click_handler_t multi_click_handler,user_long_pressed_handler_t long_pressed_handler,uint8_t button_counts)
{
  ret_code_t err_code = NRF_SUCCESS;

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
  /* 除能按键 */
  err_code = app_button_disable();  
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_button_disable is %d\n",err_code);
    return err_code;
  }    
  return err_code;
}
