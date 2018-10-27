/**
* @file         user_timer.c
* @brief        定时器1的相关函数定义
* @details      使用定时器来计算脉冲宽度的相关函数定义
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

#include "user_timer.h"
#include "user_log.h"
/* 
=============
函数定义
=============
*/

/**
 * timer1初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
static void user_timer_event_dummy_handler(nrf_timer_event_t event_type, void *p_context)
{
  ///< do nothing!!!
}

/**
 * timer1初始化函数
 * @param[in]   p_instance:表示定时器的ID
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
void user_timer_init(nrfx_timer_t const * const  p_instance)
{
  nrfx_err_t error_code;
  /* 默认的配置通过sdk_config.h中设置 */
  nrf_drv_timer_config_t m_nrf_drv_timer_config = NRF_DRV_TIMER_DEFAULT_CONFIG;
  error_code = nrf_drv_timer_init(p_instance,&m_nrf_drv_timer_config,user_timer_event_dummy_handler);
  NRF_LOG_INFO("nrf_drv_timer_init is %d\n",error_code);

  /* 此时Timer1定时器就开始工作，每个时钟tick就加1 */
  nrf_drv_timer_enable(p_instance);
}

/**
 * 关掉Timer1
 * @param[in]   p_instance:表示定时器的ID
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
void user_timer_stop(nrfx_timer_t const * const  p_instance)
{
  nrf_drv_timer_disable(p_instance);
}
