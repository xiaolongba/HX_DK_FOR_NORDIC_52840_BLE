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
/* 存放接收到的串口数据的临时变量 */
uint8_t temp = 0; 
/* 定义菜单结构体变量 */
modular_test_menu_t g_m_menu;


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

  
  for (i = 0; i < iWriteNum; i++)
  {    
    app_uart_put(g_s_tx_buffer[i]);   
  }
}

/**
 * 主菜单信息显示
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
void main_menu_display(void)
{
  HX_PRINTF("/******************************************************************************/\n");
  HX_PRINTF("                         Welcome to phase summary project                       \n");
  HX_PRINTF("                         website :bbs.wireless-tech.cn                          \n");
  HX_PRINTF("                         QQ Group:671139854                                     \n");
  HX_PRINTF("/==============================================================================/\n");
  HX_PRINTF("--> This is the phase summary project to test what the basic tutorials said,\n");
  HX_PRINTF("--> and there are total 4 modular test projects,please input the corresponded\n");
  HX_PRINTF("--> number to come into the corresponded the test project.\n");
  HX_PRINTF("--> Such as \"1\" for testing the button. \n");
  HX_PRINTF("/==============================================================================/\n");
  HX_PRINTF("1.BUTTON\n");
  HX_PRINTF("2.LED\n");
  HX_PRINTF("3.ADC\n");  
  HX_PRINTF("4.Pulse Width Measure\n");
}



/**
 * 一级子菜单识别
 * @param[in]   NULL
 * @retval      返回当前在哪个菜单，详情就参考em_submenu枚举
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
static uint8_t user_submenu_identification(void)
{
  if(g_m_menu.button_submenu)
  {
    return PRIMARY_BUTTON;
  }
  if(g_m_menu.led_menu.led_primary_submenu)
  {
    if(g_m_menu.led_menu.ppi_secondary_submenu)
    {
      return SECONDARY_PPI;
    }
    if(g_m_menu.led_menu.pwm_secondary_sumenu)
    {
      return SECONDARY_PWM;
    }
    if(g_m_menu.led_menu.timer_secondary_submenu)
    {
      return SECONDARY_TIMER;
    }
    return PRIMARY_LED;
  }
  if(g_m_menu.adc_sumenu)
  {
    return PRIMARY_ADC;
  }
  if(g_m_menu.pluse_width_measure_submenu)
  {
    return PRIMARY_PWM_MEASURE;
  }
  return MAIN_MENU;
}


/**
 * 按键子菜单处理
 * @param[in]   type：ENTER表示进入子菜单，EXIT表示退出子菜单
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
static void user_button_submenu_handler(uint8_t type)
{
  switch (type)
  {
  /* 进入子菜单 */
  case ENTER:
    g_m_menu.button_submenu = 1;
    g_m_menu.main_menu = 0;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can implement click、Double click、Multi click after go to this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("/==============================================================================/\n");
    break;
  /* 退出子菜单 */
  case EXIT:
    g_m_menu.button_submenu = 0;
    g_m_menu.main_menu = 1;
    main_menu_display();
    break;
  }
  
  
}

/**
 * LED子菜单处理
 * @param[in]   type：ENTER表示进入子菜单，EXIT表示退出子菜单
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
static void user_led_submenu_handler(uint8_t type)
{
  switch (type)
  {
  /* 进入一级子菜单 */
  case ENTER:
    if(!g_m_menu.led_menu.led_primary_submenu)
    {
      g_m_menu.led_menu.led_primary_submenu = 1;
      g_m_menu.main_menu = 0;
      HX_PRINTF("/==============================================================================/\n");
      HX_PRINTF("--> You can implement the LED related functions in this submenu.\n");
      HX_PRINTF("--> 0. Back to the upper menu.\n");
      HX_PRINTF("--> 1. PPI\n");
      HX_PRINTF("--> 2. PWM\n");
      HX_PRINTF("--> 3. TIMER\n");
      HX_PRINTF("/==============================================================================/\n");
    }
    /* 二级子菜单处理 */
    else
    {
      switch (temp)
      {
      case 1:
        HX_PRINTF("/==============================================================================/\n");
        HX_PRINTF("--> Press the user button to control led on or off in this submenu.\n");
        HX_PRINTF("--> 0. Back to the upper menu.\n");
        HX_PRINTF("/==============================================================================/\n");
        break;
      case 2:
        break;
      case 3:
        break;
      }
    }
    break;
  case EXIT:
    g_m_menu.led_menu.led_primary_submenu = 0;
    g_m_menu.main_menu = 1;
    main_menu_display();
    break;
  }
  
}

/**
 * ADC子菜单处理
 * @param[in]   type：ENTER表示进入子菜单，EXIT表示退出子菜单
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
static void user_adc_submenu_handler(uint8_t type)
{
  HX_PRINTF("/==============================================================================/\n");
  HX_PRINTF("--> You can implement the ADC Measure in this submenu.\n");
  HX_PRINTF("--> 0. Back to the upper menu.\n");
  HX_PRINTF("/==============================================================================/\n");
}

/**
 * 脉冲宽度测量子菜单处理
 * @param[in]   type：ENTER表示进入子菜单，EXIT表示退出子菜单
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
static void user_pluse_width_measure_submenu_handler(uint8_t type)
{
  HX_PRINTF("/==============================================================================/\n");
  HX_PRINTF("--> You can implement Pluse Width Measure function in this submenu.\n");
  HX_PRINTF("--> 0. Back to the upper menu.\n");
  HX_PRINTF("/==============================================================================/\n");
}



/**
 * 串口接收处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/5, 初始化版本\n
 */
static void user_uart_recevice_process(void)
{
  if(g_m_menu.main_menu)
  {
    switch (temp)
    {
    /* BUTTON */
    case 1:
      user_button_submenu_handler(ENTER);
      break;
    /* LED */
    case 2:
      user_led_submenu_handler(ENTER);
      break;
    /* ADC */
    case 3:
      user_adc_submenu_handler(ENTER);
      break;
    /* Pluse Width Measure */
    case 4:
      user_pluse_width_measure_submenu_handler(ENTER);
      break;
    /* 其他的数字则无效 */
    default:
      HX_PRINTF("Invalid Command is %d.Please input the numeric 1~4 !!!\r\n", temp);        
      break;
    }
  }
  else
  {

  }
  
  if (temp != 0x00)
    temp = 0x00;
}

/**
 * 串口事件处理函数
 * @param[in]   p_app_uart_event：传进来的相关事件以及错误码 
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/11/28, 初始化函数
 */
static void user_uart_evt_handler(app_uart_evt_t *p_app_uart_event)
{    
  switch (p_app_uart_event->evt_type)
  {
  case APP_UART_DATA_READY:
    app_uart_get(&temp);    
    user_uart_recevice_process();    
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
  user_log_init(user_uart_evt_handler);
  /* 默认是在主菜单 */
  g_m_menu.main_menu = 1;
}