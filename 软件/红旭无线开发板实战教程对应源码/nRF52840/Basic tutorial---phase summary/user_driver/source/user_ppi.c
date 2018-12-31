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
nrf_drv_timer_t g_m_hardware_timer0 = NRF_DRV_TIMER_INSTANCE(0);
/* 存放闪烁的频率，默认为1000ms */
uint32_t blink_frequency = DEFAULT_BLINK_FREQUENCY;
/*
===========================
函数定义
=========================== 
*/

/**
 * hardware timer0的event回调涵数,该工程不调用此回调函数
 * @param[in]   event_type:触发该回调的事件类型
 * @param[in]   p_context：指向触发该回调时所携带的内容
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */

static void user_nrf_timer_evt_handler(nrf_timer_event_t event_type, void *p_context)
{    
  /* 该回调不被使用，仅因为相关的初始化函数需要专门指定一个回调处理函数 */
}

/**
 * 初始化gpiote+timer0+ppi,用于LED菜单之子菜单PPI
 * @param[in]   color             :选择LED的颜色,详情参考user_common.h文头件
 * @param[in]   blink_interval_ms :选择LED的闪烁的频率，单位为ms
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/26, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/12/31, 不再将各功能的函数分开独立了，直接集成在该函数\n              
 */

void user_gpiote_timer0_ppi_init(uint8_t color, uint32_t blink_interval_ms)
{
  nrf_ppi_channel_t gs_m_nrf_ppi_channel;  
  nrf_drv_gpiote_out_config_t g_m_gpiote_out_config = GPIOTE_CONFIG_OUT_TASK_TOGGLE(true);

  nrf_ppi_channel_t g_m_nrf_ppi_channel1;
  uint32_t g_gpiote_evt_addr, g_gpiote_task_addr;
  uint32_t g_hardware_timer0_compare_evt_addr;

  nrfx_err_t err_code;

  led_color = color;
  blink_frequency = blink_interval_ms;
  /**********************************GPIOTE初始化**********************************/  
  /* 初始化gpiote */
  if (!nrf_drv_gpiote_is_init())
    err_code = nrf_drv_gpiote_init();
  NRF_LOG_INFO("nrf_drv_gpiote_init is %d\n", err_code);

  /* 设置LED灯对应的GPIO口被hardware timer0 compare event控制，且每次有EVENT触发GPIO OUT TASK时，取反当前的LED灯 */
  err_code = nrf_drv_gpiote_out_init(color,&g_m_gpiote_out_config);
  NRF_LOG_INFO("nrfx_gpiote_out_init is %d\n",err_code);

  /**********************************硬件定时器0初始化**********************************/
  uint32_t timer_ms_tick;
  /* 使用NRFX_TIMER_DEFAULT_CONFIG配置hardware timer0为默认的配置参数 */
  nrf_drv_timer_config_t m_hardware_timer0_config = NRF_DRV_TIMER_DEFAULT_CONFIG;

  /* 初始化hardware timer0 */
  err_code = nrf_drv_timer_init(&g_m_hardware_timer0,
                                &m_hardware_timer0_config,
                                user_nrf_timer_evt_handler);
  NRF_LOG_INFO("nrf_drv_timer0_init is %d\n", err_code);
  /* 1.设置hardware timer0在NRF_TIMER_CC_CHANNEL0通道每一秒产生event,并触发clear task 
     2.每一秒就回调一次用户自定义的回调处理函数user_nrf_timer_evt_handler,当前false不调用
  */
  timer_ms_tick = nrf_drv_timer_ms_to_ticks(&g_m_hardware_timer0, blink_interval_ms);
  NRF_LOG_INFO("nrf_drv_timer_ms_to_ticks is %d\n", timer_ms_tick);
  nrf_drv_timer_extended_compare(&g_m_hardware_timer0,
                                 NRF_TIMER_CC_CHANNEL0,
                                 timer_ms_tick,
                                 NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK,
                                 false);

  /**********************************ppi初始化**********************************/
  /* 初始化ppi */
  NRF_LOG_INFO("nrf_drv_ppi_init is %d\n", nrf_drv_ppi_init());

  /* 选择未使用的PPI通道 */
  err_code = nrf_drv_ppi_channel_alloc(&g_m_nrf_ppi_channel1);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_alloc is %d\n", err_code);

  /* 获取event和task的地址 */
  g_gpiote_task_addr = nrf_drv_gpiote_out_task_addr_get(color);
  g_hardware_timer0_compare_evt_addr = nrf_drv_timer_compare_event_address_get(&g_m_hardware_timer0,
                                                                             NRF_TIMER_CC_CHANNEL0);
  /* 将event和task通过选中的ppi_channel连接起来 */
  err_code = nrf_drv_ppi_channel_assign(g_m_nrf_ppi_channel1,
                                        g_hardware_timer0_compare_evt_addr,
                                        g_gpiote_task_addr);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_assign is %d\n", err_code);

  /* 使能选中的PPI的通道 */
  err_code = nrf_drv_ppi_channel_enable(g_m_nrf_ppi_channel1);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_enable is %d\n", err_code);

  /* 使能hardware timer0 */
  nrf_drv_timer_enable(&g_m_hardware_timer0);
  /* 使能gpiote的out task */
  nrf_drv_gpiote_out_task_enable(color);
}

/**
 * 取消初始化gpiote+timer0+ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/31, 初始化版本\n          
 */

void user_gpiote_timer0_ppi_uninit(void)
{
  /**********************************取消GPIOTE初始化**********************************/
  nrfx_err_t err_code;

  /* 取消初始化gpiote */
  if (nrf_drv_gpiote_is_init())
  {
    nrf_drv_gpiote_uninit();    
  }

  /**********************************取消硬件定时器0初始化**********************************/
  /* 取消初始化hardware timer0 */
  nrf_drv_timer_uninit(&g_m_hardware_timer0);

  /**********************************取消ppi初始化**********************************/
  /* 取消初始化ppi */
  nrf_drv_ppi_uninit();
}