/**
* @file         user_gpiote.c
* @brief        gpiote的相关函数定义
* @details      使用gpiote来计算脉冲宽度的相关函数定义
* @author       Helon_Chan
* @QQ Group     671139854
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/10/27, 初始化版本\n
*/

/* 
=============
全局变量定义
=============
*/

/* 
=============
头文件包含
=============
*/
#include "user_gpiote.h"
#include "user_log.h"
/* 
=============
函数定义
=============
*/
/**
 * gpiote初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
 */
void user_gpiote_init(nrf_drv_gpiote_evt_handler_t evt_handler)
{
  nrfx_err_t error_code;
  nrf_drv_gpiote_in_config_t m_nrf_drv_gpiote_in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
  /* 初始化gpiote */
  error_code = nrf_drv_gpiote_init();
  NRF_LOG_INFO("nrf_drv_gpiote_init is %d\n", error_code);

  /* gpiote输入初始化 */
  error_code = nrf_drv_gpiote_in_init(GPIOTE_IN_PIN,&m_nrf_drv_gpiote_in_config,evt_handler);
  NRF_LOG_INFO("nrf_drv_gpiote_in_init is %d\n", error_code);

  /* 使能gpiote输入事件 */
  nrf_drv_gpiote_in_event_enable(GPIOTE_IN_PIN,true);
}