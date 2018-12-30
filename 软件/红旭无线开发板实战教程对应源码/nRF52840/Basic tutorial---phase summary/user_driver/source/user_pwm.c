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

/* 
=============
头文件包含
=============
*/
#include "user_pwm.h"

/* 
=============
全局变量定义
=============
*/
APP_TIMER_DEF(gs_m_low_power_pwm_app_timer_id);
low_power_pwm_t gs_m_low_power_pwm;
low_power_pwm_config_t s_m_low_power_pwm_config =
    {
        .active_high = false,
        .period = UINT8_MAX,                              ///< 周期是255/32768,125Hz
        .p_port = NRF_P0,                                 ///< 如果想要输出的PWM脚是P1，则此处要填充NRF_P1
        .bit_mask = BROAD_LED_MASK,
        .p_timer_id = &gs_m_low_power_pwm_app_timer_id,
};

/* 
=============
函数定义
=============
*/

/**
 * pwm初始化函数,通过32.768Khz生成PWM波形，默认不使能APP_PWM
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
*               Ver0.0.2:
                  Helon_Chan, 2018/12/30, 屏蔽了硬件PWM和硬件定时器生成PWM的初始化函数\n            
 */

void user_pwm_init(void)
{
  ret_code_t err_code;
  err_code = low_power_pwm_init((&gs_m_low_power_pwm), &s_m_low_power_pwm_config, NULL);
  NRF_LOG_INFO("low_power_pwm_init is %d\n", err_code);
}