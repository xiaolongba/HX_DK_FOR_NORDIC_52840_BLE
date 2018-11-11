/**
* @file         user_adc.c
* @brief        adc相关的函数定义
* @details      用户可以调用这里的函数进行adc采样
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/11/10, 初始化版本\n
*/

/*
===========================
头文件包含
=========================== 
*/
#include "user_adc.h"

/*
===========================
函数定义
=========================== 
*/

/**
 * 开始adc采样
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/11, 初始化版本\n
 */
void user_adc_sample_start(void)
{
  nrfx_err_t err_code;
  // while (nrf_drv_saadc_is_busy())
  //   ;
  err_code = nrf_drv_saadc_sample();
  NRF_LOG_INFO("nrf_drv_saadc_sample is %d\n", err_code);
}

/**
 * adc初始化函数
 * @param[in]   nrf_drv_saadc_event_handler:adc事件回调处理函数
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/10, 初始化版本\n
 */
void user_adc_init(nrfx_saadc_event_handler_t nrf_drv_saadc_event_handler,
                   nrf_saadc_value_t *m_nrf_saadc_value)
{
  ret_code_t err_code;
  nrf_drv_saadc_config_t m_nrf_drv_saadc_config = NRF_DRV_SAADC_DEFAULT_CONFIG;
  nrf_saadc_channel_config_t m_nrf_saadc_channel_config = NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(NRF_SAADC_INPUT_VDD);
  /* 使能Bust模式 */
  m_nrf_saadc_channel_config.burst = NRF_SAADC_BURST_ENABLED;

  /* 配置成要测试的AN口为VDD,且在第0通道 */
  err_code = nrf_drv_saadc_channel_init(0, &m_nrf_saadc_channel_config);
  NRF_LOG_INFO("nrf_drv_saadc_channel_init is %d\n", err_code);

  /* 注册adc的事件回调处理函数 */
  err_code = nrf_drv_saadc_init(&m_nrf_drv_saadc_config, nrf_drv_saadc_event_handler);
  NRF_LOG_INFO("nrf_drv_saadc_init is %d\n", err_code);

  /* 分配一个缓冲区用于存放adc值 */
  err_code = nrf_drv_saadc_buffer_convert(m_nrf_saadc_value, 1); 
  NRF_LOG_INFO("nrf_drv_saadc_buffer_convert is %d\n", err_code);
}