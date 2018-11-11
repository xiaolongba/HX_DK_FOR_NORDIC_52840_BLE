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

/* 存放ADC的值的缓冲 */
static nrf_saadc_value_t m_buffer_pool[1]; 
/*
===========================
函数定义
=========================== 
*/

/**
 * adc事件回调处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/11, 初始化版本\n
 */
static void user_saadc_event_handler(nrfx_saadc_evt_t const *p_event)
{
  ret_code_t err_code;
 char float_str[80]={0};   
  float adc_value;

  switch (p_event->type)
  {
    /* 转换完成，如果有多路ADC采集，则此时表示多路采集完成，
        读ADC值则有多少路就要读多少次，这里只有一路所以只读一路的值 */
    case NRF_DRV_SAADC_EVT_DONE:
      /* 只需转换一个通道，如果这里有4个通道，则填充4，以此类推 */
      err_code = nrf_drv_saadc_buffer_convert(p_event->data.done.p_buffer, 1);
      NRF_LOG_INFO("nrf_drv_saadc_buffer_convert is %d\n", err_code);

      adc_value = p_event->data.done.p_buffer[0] * 3.6 / 16384;     

      /* 这里是Nordic自带的打印浮点数，但是只保留小数点后两位，
         这里不使用，仅供后来人使用或者了解 */
      // NRF_LOG_INFO("adc_value is " NRF_LOG_FLOAT_MARKER " voltage \n",
//                   NRF_LOG_FLOAT(adc_value));

      /* 保留小数点后4位,这里还需要在工程项目中使能float,否则这个sprintf函数用不了 */
      sprintf(float_str, "VDD voltage is %.4f\n", adc_value);
      /* 采样得到VDD电压值 */
      NRF_LOG_INFO("%s\n", float_str);
      break;
    default:
      break;
  }
}

/**
 * 按键单击、多击处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
static void user_multi_click_handler(uint8_t button_no, uint8_t *click_counts)
{
  switch(button_no)
  {
    case BUTTON1:
      NRF_LOG_INFO("click counts is %d\n",*click_counts);
      *click_counts = 0;
      /* 每次有按键触发均进行一次ADC采样 */
      user_adc_sample_start();
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
static void user_long_pressed_handler(uint8_t button_no)
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
  user_adc_init(user_saadc_event_handler,m_buffer_pool);  
}