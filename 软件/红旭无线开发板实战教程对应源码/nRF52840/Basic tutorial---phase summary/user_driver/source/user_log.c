/**
* @file         user_log.c
* @brief        log相关的函数定义
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/06/09, 初始化版本\n
*/
/* 
=============
头文件包含
=============
*/
#include "user_log.h"


/* 
=============
全局变量
=============
*/
static uint8_t s_formatBuffer[HX_LOG_UART_TEMP_BUFFER_SIZE];
/* 
=============
函数定义
=============
*/

/**
 * uart初始化函数 
 * @param[in]   app_uart_event_handler:uart事件回调处理函数  
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/11/28, 全面放弃使用官方的log模块，直接怼串口
*               Ver0.0.3:
                  Helon_Chan, 2018/12/15, 因为使用driver的uart会出现丢包的情况故放弃,直接使用官方的app_uart
 */
void user_log_init(app_uart_event_handler_t app_uart_event_handler)
{
	ret_code_t err_code;
	app_uart_comm_params_t m_app_uart_comm_param;
	m_app_uart_comm_param.flow_control = APP_UART_FLOW_CONTROL_DISABLED;
	m_app_uart_comm_param.use_parity = false;
	m_app_uart_comm_param.rx_pin_no = HX_LOG_UART_RX_PIN;
	m_app_uart_comm_param.tx_pin_no = HX_LOG_UART_TX_PIN;
	m_app_uart_comm_param.rts_pin_no = UART_PIN_DISCONNECTED;
	m_app_uart_comm_param.cts_pin_no = UART_PIN_DISCONNECTED;  
	m_app_uart_comm_param.baud_rate = HX_LOG_UART_BAUDRATE;

	APP_UART_FIFO_INIT(&m_app_uart_comm_param,
										 UART_RX_BUFFER,
										 UART_TX_BUFFER,
										 app_uart_event_handler,
										 APP_IRQ_PRIORITY_LOWEST,
										 err_code);
	APP_ERROR_CHECK(err_code);
}


