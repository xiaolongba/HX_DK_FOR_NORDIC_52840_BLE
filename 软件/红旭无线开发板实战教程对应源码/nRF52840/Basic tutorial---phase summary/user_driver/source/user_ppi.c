/**
* @file         user_ppi.c
* @brief        实现ppi功能相关的函数定义
* @author       Helon_Chan
* @website      http://bbs.wireless-tech.cn/
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                    Helon_Chan, 2018/12/26, 初始化版本\n
*/

/*
===========================
头文件包含
=========================== 
*/
#include "user_ppi.h"
/*
===========================
全局变量
=========================== 
*/
static nrf_ppi_channel_t gs_m_nrf_ppi_channel;
nrf_drv_timer_t hardware_timer0 = NRF_DRV_TIMER_INSTANCE(0);

/**
 * 初始化gpiote
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
static void user_app_gpiote_init(void)
{
  nrfx_err_t err_code;
  nrf_drv_gpiote_out_config_t m_gpiote_out_config = GPIOTE_CONFIG_OUT_TASK_TOGGLE(true);
  /* 初始化gpiote */
  err_code = nrf_drv_gpiote_init();
  NRF_LOG_INFO("nrf_drv_gpiote_init is %d\n", err_code);


  /* 设置LED灯对应的GPIO口被hardware timer0 compare event控制，且每次有EVENT触发GPIO OUT TASK时，取反当前的LED灯 */
  err_code = nrf_drv_gpiote_out_init(LED_NUMBER,&m_gpiote_out_config);
  NRF_LOG_INFO("nrfx_gpiote_out_init is %d\n",err_code);

  /* 除能gpiote的out task */
  nrf_drv_gpiote_out_task_disable(LED_NUMBER);
}

/**
 * 初始化ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */

static void user_app_ppi_init(void)
{
  nrfx_err_t err_code;
  nrf_ppi_channel_t m_nrf_ppi_channel1;
  uint32_t gpiote_evt_addr,gpiote_task_addr;
  uint32_t hardware_timer0_compare_evt_addr;
  /* 初始化ppi */
  NRF_LOG_INFO("nrf_drv_ppi_init is %d\n", nrf_drv_ppi_init());

  /* 选择未使用的PPI通道 */
  err_code = nrf_drv_ppi_channel_alloc(&m_nrf_ppi_channel1);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_alloc is %d\n", err_code);


  /* 获取event和task的地址 */
  gpiote_task_addr = nrf_drv_gpiote_out_task_addr_get(LED_NUMBER);
  hardware_timer0_compare_evt_addr = nrf_drv_timer_compare_event_address_get(&hardware_timer0,
                                                                             NRF_TIMER_CC_CHANNEL0);

  /* 将event和task通过选中的ppi_channel连接起来 */
  err_code = nrf_drv_ppi_channel_assign(m_nrf_ppi_channel1,
                                        hardware_timer0_compare_evt_addr,
                                        gpiote_task_addr);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_assign is %d\n", err_code);


  /* 使能选中的PPI的通道 */
  err_code = nrf_drv_ppi_channel_enable(m_nrf_ppi_channel1);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_enable is %d\n", err_code);

}
/**
 * hardware timer0的event回调涵数,该工程不调用此回调函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */

static void user_nrf_timer_evt_handler(nrf_timer_event_t event_type, void *p_context)
{    
  switch (event_type)
  {
  case NRF_TIMER_EVENT_COMPARE0:
    
    break;            
  default:
    break;
  }
}

/**
 * 初始化timer0,用于定时
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
static void user_app_timer0_init(void)
{
  nrfx_err_t err_code;
  uint32_t timer_ms_tick;
  /* 使用NRFX_TIMER_DEFAULT_CONFIG配置hardware timer0为默认的配置参数 */
  nrf_drv_timer_config_t m_hardware_timer0_config = NRF_DRV_TIMER_DEFAULT_CONFIG;

  /* 初始化hardware timer0 */
  err_code = nrf_drv_timer_init(&hardware_timer0,
                                &m_hardware_timer0_config,
                                user_nrf_timer_evt_handler);
  NRF_LOG_INFO("nrf_drv_timer0_init is %d\n", err_code);
  /* 1.设置hardware timer0在NRF_TIMER_CC_CHANNEL0通道每一秒产生event,并触发clear task 
     2.每一秒就回调一次用户自定义的回调处理函数user_nrf_timer_evt_handler,当前false不调用
  */
  timer_ms_tick = nrf_drv_timer_ms_to_ticks(&hardware_timer0, 1000);
  NRF_LOG_INFO("nrf_drv_timer_ms_to_ticks is %d\n", timer_ms_tick);
  nrf_drv_timer_extended_compare(&hardware_timer0,
                                 NRF_TIMER_CC_CHANNEL0,
                                 timer_ms_tick,
                                 NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK,
                                 false);
  /* 除能hardware timer0 */                                   
  nrf_drv_timer_disable(&hardware_timer0);
}

/**
 * 初始化gpiote+timer0+ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/26, 初始化版本\n
 */

void user_gpiote_timer0_init(void)
{
  user_app_gpiote_init();
  user_app_timer0_init();    
  user_app_ppi_init();
}
