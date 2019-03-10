## 前言
不管是初学者还是已经在职场上耕耘多年的老工程师，不管是触摸的还是机械的开关多多少少会离不开跟按键打交道。但是，很多IOT的产品基本上很难看到一排的按键的，大多都是零星的1~2个按键。因此，要想在这么少的按键上实现复杂的功能，就务必会涉及到各种功能组合键。基于小编这几年项目上的经验，单击、双击、长按以及N击是用到最多的。这里就给大家分享下如何实现这些功能。

## 开发环境
- 操作系统
   ```
   Windows10
   ```
- SDK
   ```
   nRF5_SDK_15.2.0_9412b96
   ```
- IDE
   ```
   SEGGER Embedded Studio for ARM 4.12
   ```
- Source code

  > [Basic tutorial---multi buttons](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---multi%20buttons)
   
## 背景
一说到按键,我想不管是新鸟还是老鸟在嵌入式的职业生涯中必定会项目上有用到按键吧.在网络上也有很多大佬分享他们的按键心得体会.基本上的情况如下所示:

- 几个按键都是连续在一起的,即GPIO1,2,3,4,5在硬件上是连接在一起的,加上定时器轮询判断是哪个按键按下;

    **疑问:** 哪里有这么巧刚好按键的连接顺序都是GPIO口连着的?

- 链表+定时器的方法,定时轮询哪个按键按下并对相对应的按键动作做出处理；

    **疑问:** 这种写法的确很巧妙,但是如果要求的按键击数多的话,程序会不会很长很复杂?

- GPIO中断＋定时器的方法，GPIO口中断触发定时器,从而实现按键的逻辑判断

    **疑问:**
其实这个方向是对的,但是网络上分享的内容还是有所欠缺;
   - 如果我有多个按键需要单击/长按/多击时呢? 
   
以上这几种按键处理方法均是网络上能查找得到的.虽然大部分都可以用,但是在我看来还并不是那么的完美.总是让人感觉缺点什么,比如:

- 如果产品有低功耗要求呢?一个定时器频繁轮询是否有按键按下,这样真的好么?
- 如果产品存在有多个按键,并且每个按键均有单击/长按/多击且时长都不同的需求,那应怎么办呢?

那么针对以上的这些情况,那么有没有满足以上方法优点的同时把缺点也补上呢?答案很明显,当然是有的.随我抛砖引玉慢慢道来.

## 原理
首先,既然要判断按键是否是短按、长按、多击,那么定时器是不可以避免的,这是必需品绝对不可少.但是定时轮询这种方式是肯定不会采取的.那么最终需要哪些东西呢?如果全是文字的话,未免太过于枯燥难懂,下面我将以一张脑图展示这些内容:

![按键所需要的条件](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%8D%95%E5%87%BB_%E9%95%BF%E6%8C%89_%E5%A4%9A%E5%87%BB.png)
### GPIO中断
按键对应的GPIO口设置为双边沿触发，而不是通过定时器轮询判断.因为在小编看来定时器轮询效率太低,大部分时间按键都是处于未触发状态的.同时这样的做法对一些要低功耗处理的场合并不太适合.
### 定时器
定时器在按键的应用是不可避免的,属于充分必要条件.那么要实现单击、长按、多击这里需要4个定时器,可能有人就会说 **"卧槽!搞个按键需要太多定时器了吧"**.
虽然需要4个定时器,但是它们基本上不会同时工作,你完全可以用一个定时器实现单击,长按,多击的计时.但是,因为ESP32自带freertos,所以有软件定时器可以直接用.
因此,这个并不是什么问题,如果有老铁的定时器外设资源不够的话,你可以挪用一个定时器做为时基,采用链表的方法扩展出无限个软件定时器 **(Nordic的APP_TIMER模块已经实现了该功能，还是那是老话我们不要去重复造轮子，我们要造的是发动机)**.

- 定时器1

   用于按键消抖,那么为什么要消抖呢?这是有历史原因的 **(使用触摸就不用消抖了,因为它也没办法抖:smirk:)**,具体原因如下所示:

   ```rst
  按键消抖通常的按键所用开关为机械弹性开关，当机械触点断开、闭合时.
  由于机械触点的弹性作用，一个按键开关在闭合时不会马上稳定地接通，在断开时也不会一下子断开。
  因而在闭合及断开的瞬间均伴随有一连串的抖动，为了不产生这种现象而作的措施就是按键消抖.(出自<百度百科>)
  ```
  **!!!NOTE:Nordic的APP_BUTTON模块已经实现了按键消抖，而且还可以自定义消抖时长，单位为ms.**
- 定时器2

  用于按键长按计时,当消抖完成之后检测到有按键按下则开启些定时器2用于长按计时.如果检测到按键释放了则停止定时器2计时.

  ![长按按键示意图](https://raw.githubusercontent.com/xiaolongba/picture/master/%E9%95%BF%E6%8C%89%E7%A4%BA%E6%84%8F%E5%9B%BE.svg?sanitize=true)

  从上图我们可以看出,当按下的时间大于等于5000ms,即认为是长按动作并执行长按的回调处理函数

- 定时器3&定时器4

   这两个定时器组合在一起,用于判断短按的整个动作是否完成,这里所谓的**短按整个动作**指的是按键按下并释放.那么怎么认为一个按键动作完成呢?并不是按下然后释放就算了,释放之后还需要再等待150ms左右,看看是否有新的按键按下,这样的目的主要是用于多击判断.

   ![单击/多击按键示意图](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%8D%95%E5%87%BB%20%E5%A4%9A%E5%87%BB.svg?sanitize=true)

   从上面的示意图,我们可以分析看出:

  - 一个完整的短按动作,从按下开始计时到释放这个过程不能大于250ms,否则认为这个短按动作无效
  - 有效的短按动作完成之后,还需要再等待150ms用于检测有没有下一波的按键到来,如果没有则才是真正意义的短按动作完成,并且短按次数会自加,接下来就可以通过短按次数判断是多少击了
  - 如果是一个被识别为一个无效的短按动作,则将短按次数清0

## 如何实现
上面的小节小编已经讲解了实现短按、长按、多击的基本原理，那么如何配合Nordic的APP_TIMER以及APP_BUTTON模块去实现呢？
### 关键的宏变量及全局变量
这些宏变量或者全局变量实则就是为了改变一些时长以及一些按键的相关配置。
```c
/*
===========================
静态函数声明
=========================== 
*/
static void user_button_handler(uint8_t pin_no, uint8_t button_action);

/*
===========================
全局变量
=========================== 
*/
/* 存放按键相关的参数 */
static user_multi_click_t gs_m_user_multi_click  = 
{
  .app_button_cfg = 
  {
    {BUTTON1,APP_BUTTON_ACTIVE_LOW,NRF_GPIO_PIN_PULLUP,user_button_handler},
  },
  .user_long_pressed_handler = NULL,
  .user_multi_click_handler  = NULL,
  .click_counts              = 0,
  .is_long_press             = 0,
};

/* 用于计时长按的timer_id */
APP_TIMER_DEF(g_long_press_timer_id);
/* 用于计时短按的timer_id */
APP_TIMER_DEF(g_short_press_timer_id);

/*
===========================
宏定义
=========================== 
*/
#define BUTTON_COUNTS               1                           ///< 按键个数
#define BUTTON1                     13                          ///< 按键对应的GPIO口
#define TIMER_FOR_LONG_PRESSED      5000                        ///< 长按的时间,单位为ms
/*
===========================
函数别名
=========================== 
*/
typedef void (*user_multi_click_handler_t)(uint8_t button_no,uint8_t *click_counts);

typedef void (*user_long_pressed_handler_t)(uint8_t button_no);

/*
===========================
结构体别名
=========================== 
*/
typedef struct
{
  uint8_t is_long_press : 1;
  uint8_t click_counts;
  app_button_cfg_t app_button_cfg[BUTTON_COUNTS];
  user_multi_click_handler_t user_multi_click_handler;
  user_long_pressed_handler_t user_long_pressed_handler;
} user_multi_click_t;
```
### 定时器初始化
由于Nordic已经提供现成的基于RTC的APP_TIMER模块，秉着 **不重复造轮子** 的原则。这里我再一次说下，免得有杠精附件，不要整天想着我这个代码写出来能不能在其他平台复用啊，我不想用现成的。现在这么快的节奏，什么事都这样做黄花菜都凉。在小编看来，你只要掌握了核心技术原理，其实这就间接等于可以在其他平台复用了。
```c
/** 
* 按键计时所用到的时钟初始化，一定要user_multi_click_init之前调用该函数，否则按键不会正常工作
* @param[in]   null
* @retval      NRF_SUCCESS：表示初始化成功，其他值则初始化失败
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/26, 初始化版本\n 
*/
ret_code_t user_button_timer_init(void)
{
  ret_code_t err_code = NRF_SUCCESS;
  err_code = app_timer_init();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_init is %d\n",err_code);
    return err_code;
  }  
  err_code = app_timer_create(&g_long_press_timer_id,APP_TIMER_MODE_SINGLE_SHOT,user_long_press_handler);
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_create is %d\n",err_code);
    return err_code;
  } 
  err_code = app_timer_create(&g_short_press_timer_id,APP_TIMER_MODE_SINGLE_SHOT,user_short_press_handler);
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_timer_create is %d\n",err_code);
    return err_code;
  } 

  return err_code;
}
```
这里小编定义了两个软件定时器，一个用于长按计时，一个用于短按计时。可能有人会问消抖的计时呢？这个APP_BUTTON模块已经帮我们实现了，我们直接用即可。

### 按键初始化
同样的，我们这里直接使用现成的APP_BUTTON模块。为了更贴近实际的工程应用场景，小编在这个基础上又封装多了一层。
```c
/** 
* 填充按键的长按、单击以及多击的处理函数
* @param[in]   multi_click_handler    ：填充单击、多击的处理函数
* @param[in]   long_pressed_handler   ：填充长按处理函数
* @param[in]   button_counts          ：按键个数
* @retval      NRF_SUCCESS            ：表示初始化成功，其他值则初始化失败
* @note        初始化按键之前必须先初始化app_timer时钟,因为用到了消抖计时 
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/19, 初始化版本\n 
*/
ret_code_t user_multi_click_init(user_multi_click_handler_t multi_click_handler,user_long_pressed_handler_t long_pressed_handler,uint8_t button_counts)
{
  // uint8_t loop_counts;
  ret_code_t err_code = NRF_SUCCESS;
  
  err_code = lfclk_config();
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("lfclk_config is %d\n",err_code);
    return err_code;
  }

  if((!multi_click_handler)||(!button_counts))
  {
    return NRF_ERROR_INVALID_PARAM;
  }

  gs_m_user_multi_click.user_multi_click_handler  = multi_click_handler;
  gs_m_user_multi_click.user_long_pressed_handler = long_pressed_handler;   

  /* 初始化按键并设置按键消抖时间为10ms */
  err_code = app_button_init(gs_m_user_multi_click.app_button_cfg, button_counts, APP_TIMER_TICKS(10));
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_button_init is %d\n",err_code);
    return err_code;
  }  
  /* 使能按键 */
  err_code = app_button_enable();  
  if(err_code != NRF_SUCCESS)
  {
    NRF_LOG_INFO("app_button_enable is %d\n",err_code);
    return err_code;
  }    
  return err_code;
}
```
### 按键逻辑处理
这里的代码主要就是实现了原理篇里展示的长按以及多击示意图中所描述的功能。

```c
/** 
* 按键处理函数
* @param[in]   pin_no         ：表示进来按键处理函数的的引脚
* @param[in]   button_action  ：表示进来的按键的状态是按下还是释放
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/19, 初始化版本\n 
*/

static void user_button_handler(uint8_t pin_no, uint8_t button_action)
{
  switch(pin_no)
  {
    case BUTTON1:
      switch(button_action)
      {
        /* 按键按下 */
        case APP_BUTTON_PUSH:
          NRF_LOG_INFO("APP_BUTTON_PUSH\n");          
          /* 开始长按计时 */
          app_timer_start(g_long_press_timer_id,APP_TIMER_TICKS(TIMER_FOR_LONG_PRESSED),&pin_no);
          /* 暂停短按计时 */
          app_timer_stop(g_short_press_timer_id);
          break;
        /* 按键释放 */
        case APP_BUTTON_RELEASE:
          NRF_LOG_INFO("APP_BUTTON_RELEASE\n");
          /* 开始短按计时,如果释放之后150ms内没有新的按键按下则说明该按键已经完全释放.注意这个时长可以根据自己的需要进行更改 */
          app_timer_start(g_short_press_timer_id,APP_TIMER_TICKS(150),&pin_no);
          /* 暂停长按计时 */
          app_timer_stop(g_long_press_timer_id);
          if(gs_m_user_multi_click.is_long_press)
          {
            gs_m_user_multi_click.is_long_press = 0;
            gs_m_user_multi_click.click_counts  = 0;
          }
          else
          {
            gs_m_user_multi_click.click_counts++;
          }
          break;
        default:

          break;
      }
      break;
    default:
      break;
  }
}
```

### 按键处理函数
这里主要是单击,长按，多击的分别处理函数。
- 单击&&多击

   ```c
    /** 
    * 按键短按处理函数
    * @param[in]   p_context：传进来给按键处理函数使用的参数，这里传进来的是具体的哪个按键
    * @retval      null
    * @note        修改日志 
    *               Ver0.0.1: 
              Helon_Chan, 2018/08/26, 初始化版本\n 
    */

    static void user_short_press_handler(void *p_context)
    {
      gs_m_user_multi_click.user_multi_click_handler(*((uint8_t*)(p_context)),&gs_m_user_multi_click.click_counts);
    }
   ```
- 长按

	```c
	/** 
	* 按键长按处理函数
	* @param[in]   p_context：传进来给按键处理函数使用的参数，这里传进来的是具体的哪个按键
	* @retval      null
	* @note        修改日志 
	*               Ver0.0.1: 
					  Helon_Chan, 2018/08/26, 初始化版本\n 
	*/

	static void user_long_press_handler(void *p_context)
	{
	  gs_m_user_multi_click.user_long_pressed_handler(*((uint8_t*)(p_context)));
	  gs_m_user_multi_click.is_long_press = 1;
	}
	```
- 小编封装后的处理函数

	```c
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
		  NRF_LOG_INFO("click counts is %d\n",*click_counts);
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
		  NRF_LOG_INFO("gpio%d long pressed\n",button_no);      
		  break;
		default:
		  break;
	  }
	}
	```
- Main
  ```c
  /**
   * 用户应用初始化函数
   * @param[in]   NULL
   * @retval      NULL
   * @par         修改日志
   *              Ver0.0.1:
                    Helon_Chan, 2018/08/19, 初始化版本\n
   */
  void user_application_init(void)
  {
    /* log函数初始化  */
    log_init();
    user_button_timer_init();
    user_multi_click_init(user_multi_click_handler,user_long_pressed_handler,BUTTON_COUNTS);
    NRF_LOG_INFO("/******************************************************************************/\n");
    NRF_LOG_INFO("                         Welcome to multi click demo project                    \n");
    NRF_LOG_INFO("                         website :bbs.wireless-tech.cn                          \n");
    NRF_LOG_INFO("                         QQ Group:671139854                                     \n");
    NRF_LOG_INFO("                         Author  :wireless-tech                                 \n");
    NRF_LOG_INFO("/******************************************************************************/\n");
  }
  ```
  ```c
  /**
   * 应用程序的函数入口
   * @param[in]   NULL
   * @retval      NULL
   * @par         修改日志
   *              Ver0.0.1:
                    Helon_Chan, 2018/06/09, 初始化版本\n
   */
  int main(void)
  {  
    user_application_init();
  }
  ```
## 最后
至此，该篇章完成了如何使用nrf52840搭配官方的APP_BUTTON和APP_TIMER模块，实现单击、长按、多击的功能。让我们来看看最终的效果吧！！！

![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/Basci_tutorial_multi_button.png)


**本文原创,转载请注明出处**

