/**
* @file         user_application.c
* @brief        实现用户逻辑功能相关的函数定义
* @details      用户调用自己写的驱动或者Nordic的外设驱动实现自定义的功能
* @author       Helon_Chan
* @website      http://bbs.wireless-tech.cn/
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                    Helon_Chan, 2018/09/08, 初始化版本\n
*/

/*
===========================
头文件包含
=========================== 
*/
#include "user_application.h"
#include "user_log.h"
/*
===========================
宏定义
=========================== 
*/

/**
 * 当in event由高电平变低电平时,此回调便会响应
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/09/08, 初始化版本\n
 */

static void user_nrfx_gpiote_evt_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
  NRF_LOG_INFO("user_nrfx_gpiote_evt_handler pin is %d,action is %d\n",pin,action);
}


/**
 * 初始化gpiote和ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/09/08, 初始化版本\n
 */

void user_app_gpiote_ppi_init(void)
{
  ret_code_t err_code;  
  nrf_ppi_channel_t m_nrf_ppi_channel;
  nrfx_gpiote_out_config_t m_gpiote_out_config = NRFX_GPIOTE_CONFIG_OUT_TASK_TOGGLE(NRF_GPIOTE_INITIAL_VALUE_HIGH);
  nrfx_gpiote_in_config_t m_gpiote_in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(true);

  uint32_t nrfx_gpiote_out_task_addr;
  uint32_t nrfx_gpiote_in_event_addr;
  /* 初始化gpiote */  
  err_code = nrfx_gpiote_init();    
  NRF_LOG_INFO("nrfx_gpiote_init is %d\n",err_code);
  /* 初始化ppi */
  err_code = nrf_drv_ppi_init();
  NRF_LOG_INFO("nrf_drv_ppi_init is %d\n",err_code);

  /* 设置LED灯对应的GPIO口被GPIO TASK控制，且每次有EVENT触发TASK时，取反当前的LED灯 */
  err_code = nrfx_gpiote_out_init(LED_NUMBER,&m_gpiote_out_config);
  NRF_LOG_INFO("nrfx_gpiote_out_init is %d\n",err_code);

  /* 设置按键对应的GPIO口当由高电平变低电平时，产生ENVENT */
  err_code = nrfx_gpiote_in_init(KEY_NUMBER,&m_gpiote_in_config,user_nrfx_gpiote_evt_handler);
  NRF_LOG_INFO("nrfx_gpiote_in_init is %d\n",err_code);

  /* 获取event和task的地址 */
  nrfx_gpiote_out_task_addr = nrfx_gpiote_out_task_addr_get(LED_NUMBER);
  nrfx_gpiote_in_event_addr = nrfx_gpiote_in_event_addr_get(KEY_NUMBER);

  /* 选择未使用的PPI通道 */
  nrfx_ppi_channel_alloc(&m_nrf_ppi_channel);
  /* 将event和task通过ppi_channel0连接起来 */
  nrfx_ppi_channel_assign(m_nrf_ppi_channel,nrfx_gpiote_in_event_addr,nrfx_gpiote_out_task_addr);
  /* 使能选中的PPI的通道 */
  nrfx_ppi_channel_enable(m_nrf_ppi_channel);
  /* 使能gpiote的out task */
  nrfx_gpiote_out_task_enable(LED_NUMBER);
  /* 使能gpiote的in event */
  nrfx_gpiote_in_event_enable(KEY_NUMBER,true);
}