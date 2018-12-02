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
 * @param[in]   nrf_drv_uart:串口实例
 * @param[in]   nrf_uart_event_handler:uart事件回调处理函数
  * @param[in]   rx_buffer:uart的rx缓冲区
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/11/28, 全面放弃使用官方的log模块，直接怼串口
 */
void user_uart_init(nrf_drv_uart_t *nrf_drv_uart,
										nrf_uart_event_handler_t nrf_uart_event_handler,										
										uint8_t *rx_buffer)
{
	nrf_drv_uart_config_t m_config = NRF_DRV_UART_DEFAULT_CONFIG;
	m_config.pseltxd = HX_LOG_UART_TX_PIN;
	m_config.pselrxd = HX_LOG_UART_RX_PIN;
	m_config.pselcts = NRF_UART_PSEL_DISCONNECTED;
	m_config.pselrts = NRF_UART_PSEL_DISCONNECTED;
	m_config.baudrate = (nrf_uart_baudrate_t)HX_LOG_UART_BAUDRATE;
	ret_code_t err_code = nrf_drv_uart_init(nrf_drv_uart, &m_config, nrf_uart_event_handler);	
	APP_ERROR_CHECK(err_code);		
	err_code = nrf_drv_uart_rx(nrf_drv_uart,rx_buffer,1);
	APP_ERROR_CHECK(err_code);
	// err_code = nrf_drv_uart_tx(&g_m_uart_id,tx_buffer,sizeof(tx_buffer));
	// APP_ERROR_CHECK(err_code);
}


