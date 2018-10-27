/**
* @file         user_application.c
* @brief        实现用户逻辑功能相关的函数定义
* @details      用户调用自己写的驱动或者Nordic的外设驱动实现自定义的功能
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/07/28, 初始化版本\n
*/

/* 
=============
头文件包含
=============
*/

#include "user_application.h"

/* 
=============
全局变量定义
=============
*/
/* 定义一个timer1的ID */
nrf_drv_timer_t m_nrf_drv_timer1_id = NRF_DRV_TIMER_INSTANCE(1);

/* 
=============
函数定义
=============
*/


/**
 * 脉冲宽度测试初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
static void user_app_gpiote_in_evt_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
  static uint32_t previous_timer_counts = 0;
  /* 统计20次即可 */
  static uint32_t calculate_counts = 0;
  /* 如果是上升沿,则记下此时的时间 */
  if(nrf_gpio_pin_read(GPIOTE_IN_PIN))
  {
    previous_timer_counts = nrf_drv_timer_capture_get(&m_nrf_drv_timer1_id,
                                                      NRF_TIMER_CC_CHANNEL1);
  }
  /* 如果是下降沿，则用当前的时间减去上升沿时的时间 */
  else
  {
    /* ！！！因为速度过快,使用串口打印会出现异常,该工程使用RTT打印输出 */
    NRF_LOG_INFO("pluse width is %d us\n",
                 nrf_drv_timer_capture_get(&m_nrf_drv_timer1_id, NRF_TIMER_CC_CHANNEL1) - previous_timer_counts);
  }
  if (calculate_counts > 30)
  {
    nrf_drv_gpiote_in_event_disable(GPIOTE_IN_PIN);
  }
  calculate_counts++;
}
/**
 * 脉冲宽度测试初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
static void user_app_measure_pluse_width_init(void)
{
  uint32_t gpio_in_evt_addr = nrf_drv_gpiote_in_event_addr_get(GPIOTE_IN_PIN);
  uint32_t nrf_drv_timer_capture_task_addr = nrf_drv_timer_capture_task_address_get(&m_nrf_drv_timer1_id,
                                                                                    NRF_TIMER_CC_CHANNEL1);
  user_gpiote_init(user_app_gpiote_in_evt_handler);    
  user_ppi_init(gpio_in_evt_addr,nrf_drv_timer_capture_task_addr);
  user_timer_init(&m_nrf_drv_timer1_id);
  user_pwm_init();
}

/**
 * app初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/26, 初始化版本\n
 */
void user_app_init(void)
{
  user_log_init();
  user_app_measure_pluse_width_init();  
}