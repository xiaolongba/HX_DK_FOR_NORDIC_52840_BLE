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
 * adc事件回调处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/10, 初始化版本\n
 */
static void nrf_drv_saadc_event_handler(nrfx_saadc_evt_t const *p_event)
{
  ret_code_t err_code;
  switch (p_event->type)
  {
    /* 转换完成，如果有多路ADC采集，则此时表示多路采集完成，
    读ADC值则有多少路就要读多少次，这里只有一路所以只读一路的值 */
    case NRFX_SAADC_EVT_DONE:      
      char float_str[80];      
      err_code = nrf_drv_saadc_buffer_convert(p_event->data.done.p_buffer, 1);
      NRF_LOG_INFO("nrf_drv_saadc_buffer_convert is %d\n", err_code);

      /* 保留小数点后4位 */
      sprintf(float_str, "VDD voltage is %.4f\n", (float)((p_event->data.done.p_buffer[0] * 3.6) / 4096));
      /* 采样得到VDD电压值 */
      NRF_LOG_INFO("%s\n", float_str);
      break;
  }
}

/**
 * adc初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/10, 初始化版本\n
 */
void user_adc_init(void)
{
  ret_code_t err_code;
  nrf_drv_saadc_config_t m_nrf_drv_saadc_config = NRF_DRV_SAADC_DEFAULT_CONFIG;
  nrf_saadc_channel_config_t m_nrf_saadc_channel_config = NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(NRF_SAADC_INPUT_VDD);
  /* 使能Bust模式 */
  m_nrf_saadc_channel_config.burst = NRF_SAADC_BURST_ENABLED;

  /* 配置成要测试的AN口为VDD */
  err_code = nrf_drv_saadc_channel_init(&m_nrf_saadc_channel_config);
  NRF_LOG_INFO("nrf_drv_saadc_channel_init is %d\n",err_code);

  /* 注册adc的事件回调处理函数 */
  err_code = nrf_drv_saadc_init(&m_nrf_drv_saadc_config,nrf_drv_saadc_event_handler);
  NRF_LOG_INFO("nrf_drv_saadc_init is %d\n",err_code);
  
}