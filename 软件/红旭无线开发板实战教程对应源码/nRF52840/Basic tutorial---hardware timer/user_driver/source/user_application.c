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
nrf_drv_timer_t hardware_timer0 = NRF_DRV_TIMER_INSTANCE(0);
nrf_drv_timer_t hardware_timer1 = NRF_DRV_TIMER_INSTANCE(1);
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

static void user_nrf_drv_gpiote_evt_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
  NRF_LOG_INFO("user_nrfx_gpiote_evt_handler pin is %d,action is %d\n", pin, action);
}

/**
 * 初始化gpio,并设置对应的GPIO为输出
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */
static void user_app_gpio_init(void)
{
  nrf_gpio_cfg_output(NRF_GPIO_PIN_MAP(0,26));
}

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
  // ret_code_t err_code;
  // nrf_drv_gpiote_in_config_t m_gpiote_in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);

  // /* 设置LED灯对应的GPIO口当发生电平变化时，产生ENVENT */
  // err_code = nrf_drv_gpiote_in_init(LED_NUMBER, &m_gpiote_in_config, user_nrf_drv_gpiote_evt_handler);
  // NRF_LOG_INFO("nrf_drv_gpiote_in_init is %d\n", err_code);

  // /* 使能gpiote的in event */
  // nrf_drv_gpiote_in_event_enable(LED_NUMBER, true);
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
  // nrf_ppi_channel_t m_nrf_ppi_channel;

  // /* 选择未使用的PPI通道 */
  // nrf_drv_ppi_channel_alloc(&m_nrf_ppi_channel);
  // /* 将event和task通过选中的ppi_channel连接起来 */
  // nrf_drv_ppi_channel_assign(m_nrf_ppi_channel,
  //                            nrf_drv_gpiote_in_event_addr_get(LED_NUMBER),
  //                            nrf_drv_timer_capture_task_address_get(&hardware_timer1,NRF_TIMER_CC_CHANNEL1));
  // /* 使能选中的PPI的通道 */
  // nrf_drv_ppi_channel_enable(m_nrf_ppi_channel);
}
/**
 * hardware timer的event回调涵数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/23, 初始化版本\n
 */

static void user_nrf_timer_evt_handler(nrf_timer_event_t event_type, void *p_context)
{  
  static uint32_t previous_timer_couts = 0;  
  switch (event_type)
  {
  case NRF_TIMER_EVENT_COMPARE0:
    /* 取反当前的LED_NUMBER的电平 */
    nrf_gpio_pin_toggle(LED_NUMBER);
    NRF_LOG_INFO("nrf_gpio_pin_toggle \n");
    break;
  case NRF_TIMER_TASK_CAPTURE1:
    NRF_LOG_INFO("current task - previous task = %d us\n",
                 nrf_drv_timer_capture_get(&hardware_timer1, NRF_TIMER_CC_CHANNEL1) - previous_timer_couts);
    previous_timer_couts = nrf_drv_timer_capture_get(&hardware_timer1, NRF_TIMER_CC_CHANNEL1);             
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
  /* 使用NRFX_TIMER_DEFAULT_CONFIG配置hardware timer为默认的配置参数 */
  nrf_drv_timer_config_t m_hardware_timer0_config = NRF_DRV_TIMER_DEFAULT_CONFIG;

  /* 初始化hardware timer */
  err_code = nrf_drv_timer_init(&hardware_timer0,
                                &m_hardware_timer0_config,
                                user_nrf_timer_evt_handler);
  NRF_LOG_INFO("nrf_drv_timer_init is %d\n", err_code);
  /* 1.设置hardware timer0在NRF_TIMER_CC_CHANNEL0通道每一秒产生event,并触发clear task 
     2.每一秒就回调一次用户自定义的回调处理函数user_nrf_timer_evt_handler
  */
  timer_ms_tick = nrf_drv_timer_ms_to_ticks(&hardware_timer0, 1000);
  NRF_LOG_INFO("nrf_drv_timer_ms_to_ticks is %d\n", timer_ms_tick);
  nrf_drv_timer_extended_compare(&hardware_timer0,
                                 NRF_TIMER_CC_CHANNEL0,
                                 timer_ms_tick,
                                 NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK,
                                 true);
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
  /* 设置hardware timer1的长度为32bit的计数器 */
  nrf_drv_timer_config_t m_hardware_timer1_config = NRF_DRV_TIMER_DEFAULT_CONFIG;
  m_hardware_timer1_config.mode = NRF_TIMER_MODE_COUNTER;
  m_hardware_timer1_config.bit_width = NRF_TIMER_BIT_WIDTH_32;
  /* 初始化hardware timer1 */
  nrf_drv_timer_init(&hardware_timer1, &m_hardware_timer1_config, user_nrf_timer_evt_handler);
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
  user_app_gpio_init();
  // user_app_gpiote_init();
  user_app_timer0_init();
  // user_app_ppi_init();
}