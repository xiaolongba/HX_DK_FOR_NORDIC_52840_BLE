/**
* @file         user_app.c
* @brief        应用层相关的函数定义
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/12/02, 初始化版本\n
*/

/* 
=============
头文件包含
=============
*/

#include "user_app.h"



/* 
=============
全局变量
=============
*/

/* 定义一个1字节的tx缓冲区 */
static uint8_t g_s_tx_buffer[HX_LOG_UART_TEMP_BUFFER_SIZE];
/* 定义一个字节的rx缓冲区 */
static uint8_t g_s_rx_buffer[1]={0};
/* 定义uart0实例 */
static nrf_drv_uart_t g_m_uart_id = NRF_DRV_UART_INSTANCE(0);

volatile uint8_t temp = 0; 
/* 
=============
函数定义
=============
*/

/**
 * 重新映射串口
 * @param[in]   format：输出的格式
 * @retval      ...：可变长度的参数
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/2, 初始化版本\n
 */
void user_customer_printf(char *format, ...)
{
	volatile uint8_t iWriteNum = 0, i = 0;
	va_list ap;

	if (!format)
		return;

	va_start(ap, format);

	iWriteNum = vsprintf((char *)g_s_tx_buffer, format, ap);

	va_end(ap);

	if (iWriteNum > HX_LOG_UART_TEMP_BUFFER_SIZE)
		iWriteNum = HX_LOG_UART_TEMP_BUFFER_SIZE;

//  nrf_drv_uart_tx(&g_m_uart_id, g_s_tx_buffer, iWriteNum);
//  while (nrf_drv_uart_tx_in_progress(&g_m_uart_id))
//    ;
  for (i = 0; i < iWriteNum; i++)
  {
    while (nrf_drv_uart_tx_in_progress(&g_m_uart_id))
      ;
    nrf_drv_uart_tx(&g_m_uart_id, g_s_tx_buffer + i, 1);
    /* 等待tx空闲时，即将数据发送出去 */
    //  		while(nrf_drv_uart_tx_in_progress(&g_m_uart_id));
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
  switch (p_event->type)
  {
  case NRF_DRV_UART_EVT_RX_DONE:
    nrf_drv_uart_rx(&g_m_uart_id,g_s_rx_buffer,1);   
	temp = g_s_rx_buffer[0];
    break;
  default:
    break;
  }
}

/**
 * 应用层初始化
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/2, 初始化版本\n
 */
void user_app_init(void)
{  
  /* log函数初始化  */
  user_uart_init(&g_m_uart_id,user_uart_evt_handler,g_s_rx_buffer);
}