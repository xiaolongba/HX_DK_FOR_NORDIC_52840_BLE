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
/* =============
全局变量定义
 =============*/
/* 定义一个硬件PWM0的实例 */
static nrf_drv_pwm_t gs_m_nrf_drv_pwm = NRF_DRV_PWM_INSTANCE(0);
/* 定义不同的占空比值 */
static nrf_pwm_values_common_t duty_values [] = 
{
  800,                        ///< 20%,这里指的是高电平占百分之20,下面的以此类推
  600,                        ///< 40%
  400,                        ///< 60%    
  200,                        ///< 80%  
};

/* 
=============
函数定义
=============
*/

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
  /* 使用默认的配置，配置PWM的周期为1K,PWM输出脚为BROAD_LED,其他3路不使用 */
  nrf_drv_pwm_config_t m_nrf_drv_pwm_config = NRF_DRV_PWM_DEFAULT_CONFIG;
//  m_nrf_drv_pwm_config.output_pins[0] = NRF_DRV_PWM_PIN_INVERTED;
  m_nrf_drv_pwm_config.output_pins[1] = NRF_DRV_PWM_PIN_NOT_USED;
  m_nrf_drv_pwm_config.output_pins[2] = NRF_DRV_PWM_PIN_NOT_USED;
  m_nrf_drv_pwm_config.output_pins[3] = NRF_DRV_PWM_PIN_NOT_USED;

  err_code = nrf_drv_pwm_init(&gs_m_nrf_drv_pwm, &m_nrf_drv_pwm_config, NULL);
  NRF_LOG_INFO("nrf_drv_pwm_init is %d\n", err_code);

  nrf_pwm_sequence_t const c_m_seq =
      {
          .values.p_common = duty_values,
          .length = NRF_PWM_VALUES_LENGTH(duty_values),
          .repeats = 0,
          .end_delay = 0};
  /* 重复3次duty_values中指定的占空比,最后保持最后一个占空比的值即100% */
  err_code = nrf_drv_pwm_simple_playback(&gs_m_nrf_drv_pwm, &c_m_seq, 3, 0);
  NRF_LOG_INFO("nrf_drv_pwm_simple_playback is %d\n", err_code);
}