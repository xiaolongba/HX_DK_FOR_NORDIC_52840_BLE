/**
* @file         user_ppi.c
* @brief        PPI的相关函数定义
* @details      使用PPI来计算脉冲宽度的相关函数定义
* @author       Helon_Chan
* @QQ Group     671139854
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/10/27, 初始化版本\n
*/

/* 
=============
全局变量定义
=============
*/

/* 
=============
头文件包含
=============
*/
#include "user_ppi.h"
#include "user_log.h"
/* 
=============
函数定义
=============
*/
/**
 * ppi初始化函数
 * @param[in]   eep:event的地址
 * @param[in]   tep:task的地址
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/10/27, 初始化版本\n
 */
void user_ppi_init(uint32_t eep, uint32_t tep)
{
  ret_code_t error_code;
  /* 存放ppi通道 */
  nrf_ppi_channel_t m_nrf_ppi_channel;
  /* 初始化ppi */
  error_code = nrf_drv_ppi_init();
  NRF_LOG_INFO("nrf_drv_ppi_init is %d\n",error_code);
  /* 从未使用的ppi通道中分配一个通道 */
  error_code = nrf_drv_ppi_channel_alloc(&m_nrf_ppi_channel);
  NRF_LOG_INFO("nrf_drv_ppi_channel_alloc is %d\n",error_code);

  /* 将指定的event地址和task地址安排至分配到的ppi channel */
  error_code = nrf_drv_ppi_channel_assign(m_nrf_ppi_channel,eep,tep);
  NRF_LOG_INFO("nrf_drv_ppi_channel_assign is %d\n",error_code);

  /* 使能ppi channel */
  error_code = nrf_drv_ppi_channel_enable(m_nrf_ppi_channel);
  NRF_LOG_INFO("nrf_drv_ppi_channel_enable is %d\n",error_code);
}