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
// /* 定义一个字节的rx缓冲区 */
// static uint8_t g_s_rx_buffer[1]={0};
// /* 定义uart0实例 */
// static nrf_drv_uart_t g_m_uart_id = NRF_DRV_UART_INSTANCE(0);
/* 定义菜单结构体变量 */
modular_test_menu_t g_m_menu;


/* 
=============
函数定义
=============
*/

/**
 * 按键单击、多击处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
void user_multi_click_handler(uint8_t button_no, uint8_t *click_counts)
{
  switch(button_no)
  {
    case BUTTON1:
      if (*click_counts != 0)
        HX_PRINTF("click counts is %d\n", *click_counts);
      *click_counts = 0;
      break;
    default:
      break;
  }
}

/**
 * 按键长按处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
void user_long_pressed_handler(uint8_t button_no)
{
  switch(button_no)
  {
    case BUTTON1:
      HX_PRINTF("gpio%d long pressed\n",button_no);      
      break;
    default:
      break;
  }
}

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
 * 子菜单识别
 * @param[in]   NULL
 * @retval      返回当前在哪个菜单，详情就参考em_submenu枚举
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/15, 初始化版本\n
 */
static uint8_t user_submenu_identification(void)
{  
  return g_m_menu.current_menu;
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
  case PRIMARY_BUTTON:
    g_m_menu.current_menu = PRIMARY_BUTTON;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can implement click、Double click、Multi click and Long Pressafter go to this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("/==============================================================================/\n");
    /* 使能按键 */
    app_button_enable();
    break;
  /* 退出子菜单 */
  case EXIT_PRIMARY_MENU:
    g_m_menu.current_menu = MAIN_MENU;
    main_menu_display();
    /* 除能按键 */
    app_button_disable();
    break;
  }
  
  
}

/**
 * LED子菜单处理
 * @param[in]   type：详情请参考em_submenu_action枚举
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
  case PRIMARY_LED:
    g_m_menu.current_menu = PRIMARY_LED;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can implement the LED related functions in this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("--> 1. PPI\n");
    HX_PRINTF("--> 2. PWM\n");
    HX_PRINTF("--> 3. TIMER\n");
    HX_PRINTF("--> 4. RGB\n");
    HX_PRINTF("/==============================================================================/\n");
    break;
  case SECONDARY_PPI:
    g_m_menu.current_menu = SECONDARY_PPI;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> The led is on or off by 1000ms interval in this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("/==============================================================================/\n");
    nrf_drv_timer_enable(&hardware_timer0);
    nrf_drv_gpiote_out_task_enable(LED_NUMBER);
    break;
  case SECONDARY_PWM:
    g_m_menu.current_menu = SECONDARY_PWM;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can modify the PWM duty cycle in this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("--> 1. 20%c \n",'%');
    HX_PRINTF("--> 2. 40%c\n",'%');
    HX_PRINTF("--> 3. 60%c\n",'%');
    HX_PRINTF("--> 4. 80%c\n",'%');
    HX_PRINTF("/==============================================================================/\n");
    break;
  case SECONDARY_TIMER:
    g_m_menu.current_menu = SECONDARY_TIMER;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can modify the blink frequency in this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("--> 1. 100ms \n");
    HX_PRINTF("--> 2. 200ms \n");
    HX_PRINTF("--> 3. 300ms \n");
    HX_PRINTF("--> 4. 400ms \n");
    HX_PRINTF("/==============================================================================/\n");
    break;
  case SECONDARY_RGB:
    g_m_menu.current_menu = SECONDARY_RGB;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can select the led color in this submenu. The default color is Red.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("--> 1. Red \n");
    HX_PRINTF("--> 2. Green \n");
    HX_PRINTF("--> 3. Blue \n");    
    HX_PRINTF("/==============================================================================/\n");
    break;
  case EXIT_PRIMARY_MENU:
    g_m_menu.current_menu = MAIN_MENU;
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
  switch (type)
  {
  /* 进入子菜单 */
  case PRIMARY_ADC:
    g_m_menu.current_menu = PRIMARY_ADC;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can implement the ADC Measure in this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("/==============================================================================/\n");
    break;
  /* 退出子菜单 */
  case EXIT_PRIMARY_MENU:
    g_m_menu.current_menu = MAIN_MENU;
    main_menu_display();
    break;
  }
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
  switch (type)
  {
  /* 进入子菜单 */
  case PRIMARY_PWM_MEASURE:
    g_m_menu.current_menu = PRIMARY_PWM_MEASURE;
    HX_PRINTF("/==============================================================================/\n");
    HX_PRINTF("--> You can implement Pluse Width Measure function in this submenu.\n");
    HX_PRINTF("--> 0. Back to the upper menu.\n");
    HX_PRINTF("/==============================================================================/\n");
    break;
  /* 退出子菜单 */
  case EXIT_PRIMARY_MENU:
    g_m_menu.current_menu = MAIN_MENU;
    main_menu_display();
    break;
  }
}



/**
 * 串口接收处理函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/12/5, 初始化版本\n
 */
static void user_uart_recevice_process(uint8_t rx_buffer)
{
  switch(g_m_menu.current_menu)
  {
    /* 主菜单 */
    case MAIN_MENU:
      switch (rx_buffer)
      {
      /* BUTTON */
      case 1:
        user_button_submenu_handler(PRIMARY_BUTTON);
        break;
      /* LED */
      case 2:
        user_led_submenu_handler(PRIMARY_LED);
        break;
      /* ADC */
      case 3:
        user_adc_submenu_handler(PRIMARY_ADC);
        break;
      /* Pluse Width Measure */
      case 4:
        user_pluse_width_measure_submenu_handler(PRIMARY_PWM_MEASURE);
        break;
      /* 其他的数字则无效 */
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 1~4 !!!\r\n", rx_buffer);
        break;
      }
      break;
    /* 按键一级子菜单 */
    case PRIMARY_BUTTON:
      switch (rx_buffer)
      {
      /* 返回上一级菜单 */
      case 0:
        user_button_submenu_handler(EXIT_PRIMARY_MENU);
        break;      
      /* 其他的数字则无效 */
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 0 in this submenu!!!\r\n", rx_buffer);
        break;
      }
      break;
    /* LED一级子菜单 */
    case PRIMARY_LED:
      switch(rx_buffer)
      {
        /* 返回上一级菜单 */
        case 0:
          user_led_submenu_handler(EXIT_PRIMARY_MENU);
          break;
        /* 进入PPI二级菜单 */
        case 1:
          user_led_submenu_handler(SECONDARY_PPI);
          break;
        /* 进入PWM二级菜单 */
        case 2:
          user_led_submenu_handler(SECONDARY_PWM);
          break;
        /* 进入TIMER二级菜单 */
        case 3:
          user_led_submenu_handler(SECONDARY_TIMER);
          break;
        /* 进入RGB二级菜单 */
        case 4:
          user_led_submenu_handler(SECONDARY_RGB);
          break;
        default:
          HX_PRINTF("Invalid Command is %d.Please input the numeric 0~4 in this submenu!!!\r\n", rx_buffer);
          break;
      }
    break;
    /* LED二级子菜单PPI */
    case SECONDARY_PPI:
      switch (rx_buffer)
      {
      case 0:
        user_led_submenu_handler(PRIMARY_LED);
        nrf_drv_timer_disable(&hardware_timer0);  
        nrf_drv_gpiote_out_task_disable(LED_NUMBER);
        break;
      /* 其他的数字则无效 */
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 0 in this submenu!!!\r\n", rx_buffer);
        break;
      }
      break;
    case SECONDARY_PWM:
      switch (rx_buffer)
      {
      case 0:
        user_led_submenu_handler(PRIMARY_LED);
        break;
      /* 输出20%的占空比 */
      case 1:
        break;
      /* 输出40%的占空比 */
      case 2:
        break;
      /* 输出60%的占空比 */
      case 3:
        break;
      /* 输出80%的占空比 */
      case 4:
        break;
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 0~4 in this submenu!!!\r\n", rx_buffer);
        break;
      }
      break;
    case SECONDARY_TIMER:
      switch (rx_buffer)
      {
      case 0:
        user_led_submenu_handler(PRIMARY_LED);
        break;
      /* LED灯100ms闪烁 */
      case 1:
        break;
      /* LED灯200ms闪烁 */
      case 2:
        break;
      /* LED灯300ms闪烁 */
      case 3:
        break;
      /* LED灯400ms闪烁 */
      case 4:
        break;
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 0~4 in this submenu!!!\r\n", rx_buffer);
        break;
      }
      break;
    case SECONDARY_RGB:
      switch (rx_buffer)
      {
      case 0:
        user_led_submenu_handler(PRIMARY_LED);
        break;
      /* 红色LED灯 */
      case 1:
        break;
      /* 绿色LED灯 */
      case 2:
        break;
      /* 蓝色LED灯 */
      case 3:
        break;
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 0~3 in this submenu!!!\r\n", rx_buffer);
        break;
      }
      break;
    case PRIMARY_ADC:
    case PRIMARY_PWM_MEASURE:
      switch (rx_buffer)
      {
      case 0:
        user_adc_submenu_handler(EXIT_PRIMARY_MENU);
        break;
      /* 其他的数字则无效 */
      default:
        HX_PRINTF("Invalid Command is %d.Please input the numeric 0 in this submenu!!!\r\n", rx_buffer);
        break;
      }
      break;    
  }   
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
  /* 存放接收到的串口数据的临时变量 */
  uint8_t rx_buffer_temp = 0;
  switch (p_app_uart_event->evt_type)
  {
  case APP_UART_DATA_READY:
    app_uart_get(&rx_buffer_temp);
    user_uart_recevice_process(rx_buffer_temp);
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
  ret_code_t err_code = NRF_SUCCESS;
  /* log函数初始化  */
  user_log_init(user_uart_evt_handler);
  /* 默认是在主菜单 */
  g_m_menu.current_menu = MAIN_MENU;

  /* 初始化app_timer模块 */
  err_code = app_timer_init();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_init is %d\n",err_code);
//    return err_code;
  }  

  /* 开启32.768KHz的时钟 */
  err_code = lfclk_config();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("lfclk_config is %d\n",err_code);
//    return err_code;
  }

  /* 创建用于按键的定时器 */
  user_button_timer_init();
  /* 这里已经初始了低频时钟了,其他地方不需要再次调用了 */
  user_multi_click_init(user_multi_click_handler, user_long_pressed_handler, BUTTON_COUNTS);
  /* 初始化GPIOTE+PPI+TIMER0 */
  user_gpiote_timer0_init();
}