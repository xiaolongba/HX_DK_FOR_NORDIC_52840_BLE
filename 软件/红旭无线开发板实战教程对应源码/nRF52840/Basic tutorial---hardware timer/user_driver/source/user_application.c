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
#include "user_log.h"
#include "user_application.h"

/*
===========================
全局变量
=========================== 
*/
/* 定义timer0和timer1的id */
nrf_drv_timer_t hardware_timer0 = NRF_DRV_TIMER_INSTANCE(0);
nrf_drv_timer_t hardware_timer1 = NRF_DRV_TIMER_INSTANCE(1);



/*
===========================
函数定义
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

static void user_nrf_drv_gpiote_evt_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
  NRF_LOG_INFO("user_nrf_drv_gpiote_evt_handler： pin is %d,action is %d\n", pin, action);
  NRF_LOG_INFO("Number of button presses is %d\n",
               nrf_drv_timer_capture(&hardware_timer1, NRF_TIMER_CC_CHANNEL1));
}

/**
 * 初始化gpio,并设置对应的GPIO为输出,该工程未使用
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
// static void user_app_gpio_init(void)
// {
//   nrf_gpio_cfg_output(LED_NUMBER);
// }

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
  nrf_drv_gpiote_in_config_t m_gpiote_in_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
  nrf_drv_gpiote_out_config_t m_gpiote_out_config = GPIOTE_CONFIG_OUT_TASK_TOGGLE(true);
  /* 初始化gpiote */
  err_code = nrf_drv_gpiote_init();
  NRF_LOG_INFO("nrf_drv_gpiote_init is %d\n", err_code);

  /* 设置按键对应的GPIO口由高电平变低电平时，产生ENVENT */
  err_code = nrf_drv_gpiote_in_init(KEY_NUMBER,
                                    &m_gpiote_in_config,
                                    user_nrf_drv_gpiote_evt_handler);
  NRF_LOG_INFO("nrf_drv_gpiote_in_init is %d\n", err_code);

  /* 设置LED灯对应的GPIO口被hardware timer0 compare event控制，且每次有EVENT触发GPIO OUT TASK时，取反当前的LED灯 */
  err_code = nrf_drv_gpiote_out_init(LED_NUMBER,&m_gpiote_out_config);
  NRF_LOG_INFO("nrfx_gpiote_out_init is %d\n",err_code);

  /* 使能gpiote的in event,并触发user_nrf_drv_gpiote_evt_handler回调函数 */
  nrf_drv_gpiote_in_event_enable(KEY_NUMBER, true);
  /* 使能gpiote的out task */
  nrf_drv_gpiote_out_task_enable(LED_NUMBER);
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
  nrf_ppi_channel_t m_nrf_ppi_channel1,m_nrf_ppi_channel2;
  uint32_t gpiote_evt_addr,gpiote_task_addr;
  uint32_t hardware_timer1_capture_task_addr,hardware_timer0_compare_evt_addr;
  /* 初始化ppi */
  NRF_LOG_INFO("nrf_drv_ppi_init is %d\n", nrf_drv_ppi_init());

  /* 选择未使用的PPI通道 */
  err_code = nrf_drv_ppi_channel_alloc(&m_nrf_ppi_channel1);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_alloc is %d\n", err_code);

  /* 选择未使用的PPI通道 */
  err_code = nrf_drv_ppi_channel_alloc(&m_nrf_ppi_channel2);
  NRF_LOG_INFO("nrf_drv_ppi_channel2_alloc is %d\n", err_code);

  /* 获取event和task的地址 */
  gpiote_task_addr = nrf_drv_gpiote_out_task_addr_get(LED_NUMBER);
  hardware_timer0_compare_evt_addr = nrf_drv_timer_compare_event_address_get(&hardware_timer0,
                                                                             NRF_TIMER_CC_CHANNEL0);
  gpiote_evt_addr = nrf_drv_gpiote_in_event_addr_get(KEY_NUMBER);
  hardware_timer1_capture_task_addr = nrf_drv_timer_task_address_get(&hardware_timer1,
                                                                     NRF_TIMER_TASK_COUNT);
  /* 将event和task通过选中的ppi_channel连接起来 */
  err_code = nrf_drv_ppi_channel_assign(m_nrf_ppi_channel1,
                                        hardware_timer0_compare_evt_addr,
                                        gpiote_task_addr);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_assign is %d\n", err_code);

  err_code = nrf_drv_ppi_channel_assign(m_nrf_ppi_channel2,
                                        gpiote_evt_addr,
                                        hardware_timer1_capture_task_addr);
  NRF_LOG_INFO("nrf_drv_ppi_channel2_assign is %d\n", err_code);

  /* 使能选中的PPI的通道 */
  err_code = nrf_drv_ppi_channel_enable(m_nrf_ppi_channel1);
  NRF_LOG_INFO("nrf_drv_ppi_channel1_enable is %d\n", err_code);

  err_code = nrf_drv_ppi_channel_enable(m_nrf_ppi_channel2);
  NRF_LOG_INFO("nrf_drv_ppi_channel2_enable is %d\n", err_code);
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
    /* 取反当前的LED_NUMBER的电平 */
    nrf_gpio_pin_toggle(LED_NUMBER);       
    NRF_LOG_INFO("nrf_gpio_pin_toggle \n");
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
  /* 使能hardware timer0 */                                 
  nrf_drv_timer_enable(&hardware_timer0);
}

/**
 * 初始化timer1,用于计数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
static void user_app_timer1_init(void)
{
  nrfx_err_t err_code;

  /* 设置hardware timer1的长度为32bit的计数器 */
  nrf_drv_timer_config_t m_hardware_timer1_config = NRF_DRV_TIMER_DEFAULT_CONFIG;
  m_hardware_timer1_config.mode = NRF_TIMER_MODE_COUNTER;
  m_hardware_timer1_config.bit_width = NRF_TIMER_BIT_WIDTH_32;

  /* 初始化hardware timer1 */
  err_code = nrf_drv_timer_init(&hardware_timer1,
                                &m_hardware_timer1_config,
                                user_nrf_timer_evt_handler);
  NRF_LOG_INFO("nrf_drv_timer1_init is %d\n", err_code);
  
  /* 使能hardware timer1*/
  nrf_drv_timer_enable(&hardware_timer1);
}

/**
 * 初始化使用到的外设
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
void user_app_init(void)
{  
  user_app_gpiote_init();
  user_app_timer0_init();
  user_app_timer1_init();
  user_app_ppi_init();
}