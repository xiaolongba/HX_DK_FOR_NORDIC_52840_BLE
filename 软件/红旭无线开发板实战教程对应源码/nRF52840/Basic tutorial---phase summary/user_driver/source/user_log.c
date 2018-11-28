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
/* 
=============
头文件包含
=============
*/
#include "user_log.h"

/* 
=============
条件编译
=============
*/
#if DBG_ENABLE
    #define DBG_PRINTF(format,...)              user_debug_printf(format,##__VA_ARGS__)
#else
    #define DBG_PRINTF(...)
#endif

/* 
=============
全局变量
=============
*/
/* 定义uart0实例 */
static nrf_drv_uart_t g_m_uart_id = NRF_DRV_UART_INSTANCE(0);
/* 定义一个255字节的缓冲区 */
static uint8_t s_formatBuffer[MAX_FORMAT_BUFFER_SIZE];
/* 
=============
函数定义
=============
*/
void user_debug_printf(char *format, ...)
{
	uint8_t iWriteNum = 0, i = 0;
	va_list ap;

	if (!format)
		return;

	va_start(ap, format);

	iWriteNum = vsprintf((char *)s_formatBuffer, format, ap);

	va_end(ap);

	if (iWriteNum > MAX_FORMAT_BUFFER_SIZE)
		iWriteNum = MAX_FORMAT_BUFFER_SIZE;

	for (i = 0; i < iWriteNum; i++)
	{
		nrf_drv_uart_tx(&g_m_uart_id,s_formatBuffer+i,1);
	}
}

/**
 * 串口事件处理函数
 * @param[in]   p_event		：触发的具体事件并协带有对应的数据
 * @param[in]   p_context ：外部传入给事件回调的参数内容
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/28, 初始化函数
 */
static void user_uart_evt_handler(nrf_drv_uart_event_t *p_event, void *p_context)
{

}

/**
 * log初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, 初始化版本\n
 *              Ver0.0.2:
                  Helon_Chan, 2018/11/28, 全面放弃使用官方的log模块，直接怼串口
 */
void user_uart_init(nrf_uart_event_handler_t nrf_uart_event_handler)
{
	nrf_drv_uart_config_t m_config = NRF_DRV_UART_DEFAULT_CONFIG;
	m_config.pseltxd = NRF_LOG_BACKEND_UART_TX_PIN;
	m_config.pselrxd = NRF_LOG_BACKEND_UART_RX_PIN;
	m_config.pselcts = NRF_UART_PSEL_DISCONNECTED;
	m_config.pselrts = NRF_UART_PSEL_DISCONNECTED;
	m_config.baudrate = (nrf_uart_baudrate_t)NRF_LOG_BACKEND_UART_BAUDRATE;
	ret_code_t err_code = nrf_drv_uart_init(&g_m_uart_id, &m_config, nrf_uart_event_handler);
	APP_ERROR_CHECK(err_code);	
}


