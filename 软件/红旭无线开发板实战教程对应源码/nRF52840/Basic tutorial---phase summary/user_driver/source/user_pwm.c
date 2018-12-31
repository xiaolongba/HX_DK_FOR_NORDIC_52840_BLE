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
/* 定义一个使用TIMER1实现PWM的实例 */
APP_PWM_INSTANCE(PWM,1);
/* 存放pwm的占空比，默认为百分之5 */
uint8_t pwm_duty_cycle = 5;

/* 
=============
函数定义
=============
*/

/**
 * pwm初始化函数,通过Timer1生成PWM波形,默认的PWM占空比为百分之5
 * @param[in]   color:指定LED的颜色，详情请参考user_common.h头文件
 * @param[in]   duty :指定PWM的占空比，单位为百分比（%）
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/07/28, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/12/30, 屏蔽了硬件PWM和硬件定时器生成PWM的初始化函数\n            
 *              Ver0.0.3:
                  Helon_Chan, 2018/12/31, 使能硬件PWM,屏蔽了RTC以及硬件PWM\n
 */
void user_pwm_init(uint32_t color,app_pwm_duty_t duty)
{
  ret_code_t err_code;
  led_color = color;
  /* 配置软PWM的周期是１KHz,输出的PIN是BROAD_LED */
  app_pwm_config_t app_pwm_config = APP_PWM_DEFAULT_CONFIG_1CH(1000UL, led_color);
  /* 初始化软件PWM */
  err_code = app_pwm_init(&PWM, &app_pwm_config, NULL);
  NRF_LOG_INFO("app_pwm_init is %d\n", err_code);
  /* 使能软件PWM */
  app_pwm_enable(&PWM);

  pwm_duty_cycle = duty;
  /* 设置PWM的占空比为5% */
  while (app_pwm_channel_duty_set(&PWM, 0, duty) == NRF_ERROR_BUSY)
    ;
}


/**
 * 设置PWM的占空比
 * @param[in]   duty:想要设置的占空比，单位为百分比（%）
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/31, 初始化版本\n           
*/
void user_set_pwm_duty_cycle(app_pwm_duty_t duty)
{
  /* 设置PWM的占空比 */
  pwm_duty_cycle = duty;
  while (app_pwm_channel_duty_set(&PWM, 0, duty) == NRF_ERROR_BUSY);
}

/**
 * 取消初始化app_pwm
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/31, 初始化版本\n           
*/
void user_pwm_uninit(void)
{
  /* 取消初始化APP_PWM函数 */
  app_pwm_uninit(&PWM);  
}