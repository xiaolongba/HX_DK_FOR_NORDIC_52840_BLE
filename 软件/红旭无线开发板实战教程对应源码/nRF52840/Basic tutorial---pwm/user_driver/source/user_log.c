/**
* @file         user_log.c
* @brief        log相关的函数定义
* @details      用户可以选择使用通过UART打印log消息还是RTT打印log消息
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/06/09, 初始化版本\n
*/
/* =============
头文件包含
 =============*/
#include "user_log.h"

/**
 * log初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 */
 void user_log_init(void)
 {
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);
    NRF_LOG_DEFAULT_BACKENDS_INIT();
    NRF_LOG_INFO("/******************************************************************************/\n");
    NRF_LOG_INFO("                         Welcome to wireless-tech pwm project                   \n");
    NRF_LOG_INFO("                         website :bbs.wireless-tech.cn                          \n");
    NRF_LOG_INFO("                         QQ Group:671139854                                     \n");
    NRF_LOG_INFO("/******************************************************************************/\n");
 }