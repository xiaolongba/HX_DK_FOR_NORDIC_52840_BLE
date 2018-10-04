/**
* @file         user_pwm.c
* @brief        pwm相关的函数定义
* @details      用户可以选择使用软件pwm或者硬件pwm去驱动自己的外设
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/07/28, 初始化版本\n
*/

/* =============
头文件包含
 =============*/

#include "user_pwm.h"
#include "user_log.h"
#include "nrf_drv_clock.h"
/* =============
全局变量定义
 =============*/

#if SOFTWARE_PWM
/* 定义一个使用TIMER1实现PWM的实例 */
APP_PWM_INSTANCE(PWM,1);
#endif

#if HARDWARE_PWM
/* 定义一个硬件PWM的实例 */
static nrfx_pwm_t gs_m_nrfx_pwm = NRFX_PWM_INSTANCE(0);
/* 定义不同的占空比值 */
static nrf_pwm_values_common_t duty_values [] = 
{
  0,                          ///< 0%
  200,                        ///< 20%  
  400,                        ///< 40%
  600,                        ///< 60%    
  800,                        ///< 80%
  1000,                       ///< 100%
};
#endif

#if LOW_POWER_PWM
static low_power_pwm_t gs_m_low_power_pwm;
APP_TIMER_DEF(gs_m_low_power_pwm_app_timer_id);
#endif
/* =============
函数定义
 =============*/

/**
 * 初始化低频时钟
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/29, 初始化版本\n
 */
static void lfclk_init(void)
{
    uint32_t err_code;
    err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_clock_lfclk_request(NULL);
}

/**
 * pwm初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
 */

void user_pwm_init(void)
{
  ret_code_t err_code;
  #if SOFTWARE_PWM
    /* 配置软PWM的周期是１KHz,输出的PIN是BROAD_LED */
    app_pwm_config_t app_pwm_config = APP_PWM_DEFAULT_CONFIG_1CH(1000UL, BROAD_LED);
    /* 初始化软件PWM */
    err_code = app_pwm_init(&PWM,&app_pwm_config,NULL);
    NRF_LOG_INFO("app_pwm_init is %d\n",err_code);
    /* 使能软件PWM */
    app_pwm_enable(&PWM);
    /* 设置PWM的占空比为10% */
    while(app_pwm_channel_duty_set(&PWM,0,10) == NRF_ERROR_BUSY);
  #endif
  #if HARDWARE_PWM    
    nrfx_pwm_config_t nrfx_pwm_config = 
    {
      .output_pins = 
      {
        BROAD_LED,
        NRFX_PWM_PIN_NOT_USED,
        NRFX_PWM_PIN_NOT_USED,
        NRFX_PWM_PIN_NOT_USED,
      },
      .irq_priority = APP_IRQ_PRIORITY_LOW,
      .base_clock   = NRF_PWM_CLK_1MHz,
      .count_mode   = NRF_PWM_MODE_UP,
      .top_value    = 1000,                       ///< 即PWM的周期为1KHz
      .load_mode    = NRF_PWM_LOAD_COMMON,
      .step_mode    = NRF_PWM_STEP_AUTO
    };
    err_code = nrfx_pwm_init(&gs_m_nrfx_pwm,&nrfx_pwm_config,NULL);
    NRF_LOG_INFO("nrfx_pwm_init is %d\n",err_code);
     
    nrf_pwm_sequence_t const s_m_seq =
    {
      .values.p_common = duty_values,
      .length          = NRF_PWM_VALUES_LENGTH(duty_values),
      .repeats         = 0,
      .end_delay       = 0
    };
    /* 重复3次duty_values中指定的占空比,最后保持最后一个占空比的值即100% */
    nrfx_pwm_simple_playback(&gs_m_nrfx_pwm, &s_m_seq, 3, 0);
  #endif

  #if LOW_POWER_PWM
    lfclk_init();
    err_code = app_timer_init();
    NRF_LOG_INFO("app_timer_init is %d\n",err_code);
    low_power_pwm_config_t s_m_low_power_pwm_config = 
    {
      .active_high = false,
      .period      = UINT8_MAX,                         ///< 周期是255/32768,125Hz
      .p_port      = NRF_P1,
      .bit_mask    = BROAD_LED_MASK,
      .p_timer_id  = &gs_m_low_power_pwm_app_timer_id,
    };
    err_code = low_power_pwm_init((&gs_m_low_power_pwm), &s_m_low_power_pwm_config, NULL);    
    NRF_LOG_INFO("low_power_pwm_init is %d\n",err_code);

    err_code = low_power_pwm_duty_set(&gs_m_low_power_pwm, UINT8_MAX*0.5);                                                 
    NRF_LOG_INFO("low_power_pwm_duty_set is %d\n",err_code);

    err_code = low_power_pwm_start(&gs_m_low_power_pwm, BROAD_LED_MASK);
    NRF_LOG_INFO("low_power_pwm_start is %d\n",err_code);

  #endif

}