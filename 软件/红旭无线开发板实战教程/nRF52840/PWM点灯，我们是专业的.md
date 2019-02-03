## 前言
>一说到PWM我想对搞嵌入式的人来说再熟悉不过了，基本上不会有人不认识PWM是什么东西。PWM其全称为Pulse Width Modulation,翻译成中文就叫脉冲宽度调制。然而，小编觉得这样的叫法太装逼了，说得通俗一点不就是方波嘛，高电平持续多长时间，低电平持续多长时间。高电平的时间加上低电平的时间就是一整个周期。这样用土话解释一番会不会更好理解一点呢？可是，就这么简单的玩意，我仍然听到有很多初学者都搞不定，究其原因小编觉得更多的是不同的硬件平台，实现的方法不同导致的。故这一篇我们就谈谈如何在nrf52840实现PWM。

## 开发环境
在小编过去写的几篇文章中，好像并没有指定开发环境，但是随着越来越多的人看了之后出现这样那样的问题。小编觉得还是有需要把开发环境写出来，这样可以减少很多不必要的问题。
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
   > [Basic tutorial---pwm](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---pwm)
 
## PWM实现方式
像这些基本常用的外设，Nordic大多都封装成库了，小编在这里也不建议大家重复造轮子，造轮子的时代已经过去了，我们现在要做的是如何造发动机，即让项目跑起来动起来。接下来小编将会大家呈现三种方式去实现PWM,以下是小编写好的工程通过宏切换从而实现不同的实现方式。
```c
#define SOFTWARE_PWM            1                               ///< 使用硬件定时器产生PWM波形
#define HARDWARE_PWM            0                               ///< 使用硬件的PWM产生PWM波形
#define LOW_POWER_PWM           0                               ///< 使用RTC(32768Hz)产生PWM波形
```

### 定时器
#### RTC
使用低频时钟为时基生成PWM波形，主要的实现代码如下：
```c
static low_power_pwm_t gs_m_low_power_pwm;
APP_TIMER_DEF(gs_m_low_power_pwm_app_timer_id);

lfclk_init();
err_code = app_timer_init();
NRF_LOG_INFO("app_timer_init is %d\n",err_code);
low_power_pwm_config_t s_m_low_power_pwm_config = 
{
.active_high = false,
.period      = UINT8_MAX,                         ///< 周期是255/32768,125Hz
.p_port      = NRF_P0,                            ///< 如果想要输出的PWM脚是P1，则此处要填充NRF_P1
.bit_mask    = BROAD_LED_MASK,
.p_timer_id  = &gs_m_low_power_pwm_app_timer_id,
};
err_code = low_power_pwm_init((&gs_m_low_power_pwm), &s_m_low_power_pwm_config, NULL);    
NRF_LOG_INFO("low_power_pwm_init is %d\n",err_code);

err_code = low_power_pwm_duty_set(&gs_m_low_power_pwm, UINT8_MAX*0.5);                                                 
NRF_LOG_INFO("low_power_pwm_duty_set is %d\n",err_code);

err_code = low_power_pwm_start(&gs_m_low_power_pwm, BROAD_LED_MASK);
NRF_LOG_INFO("low_power_pwm_start is %d\n",err_code);
```
#### TIMER
使用TIMER1定时器生成PWM波形，主要的实现代码如下：
```c
/* 定义一个使用TIMER1实现PWM的实例 */
APP_PWM_INSTANCE(PWM,1);

/* 配置软PWM的周期是１KHz,输出的PIN是BROAD_LED */
app_pwm_config_t app_pwm_config = APP_PWM_DEFAULT_CONFIG_1CH(1000UL, BROAD_LED);
/* 初始化软件PWM */
err_code = app_pwm_init(&PWM,&app_pwm_config,NULL);
NRF_LOG_INFO("app_pwm_init is %d\n",err_code);
/* 使能软件PWM */
app_pwm_enable(&PWM);
/* 设置PWM的占空比为10% */
while(app_pwm_channel_duty_set(&PWM,0,10) == NRF_ERROR_BUSY);
```
### 硬件PWM
这里的PWM是指的nrf52840的硬件PWM，主要的实现代码如下：
```c
/* 定义一个硬件PWM的实例 */
static nrfx_pwm_t gs_m_nrfx_pwm = NRFX_PWM_INSTANCE(0);
/* 定义不同的占空比值 */
static nrf_pwm_values_common_t duty_values [] = 
{
0,                          ///< 0% 
200,                        ///< 20%,这里指的是低电平占百分之20,下面的以此类推
400,                        ///< 40%
600,                        ///< 60%    
800,                        ///< 80%
1000,                       ///< 100%
};

nrfx_pwm_config_t nrfx_pwm_config =
{
  .output_pins =
      {
          BROAD_LED,
          NRFX_PWM_PIN_NOT_USED,
          NRFX_PWM_PIN_NOT_USED,
          NRFX_PWM_PIN_NOT_USED,
      },
  .irq_priority = APP_IRQ_PRIORITY_LOW,
  .base_clock = NRF_PWM_CLK_1MHz,
  .count_mode = NRF_PWM_MODE_UP,
  .top_value = 1000, ///< 即PWM的周期为1KHz
  .load_mode = NRF_PWM_LOAD_COMMON,
  .step_mode = NRF_PWM_STEP_AUTO};
err_code = nrfx_pwm_init(&gs_m_nrfx_pwm, &nrfx_pwm_config, NULL);
NRF_LOG_INFO("nrfx_pwm_init is %d\n", err_code);

nrf_pwm_sequence_t const s_m_seq =
{
  .values.p_common = duty_values,
  .length = NRF_PWM_VALUES_LENGTH(duty_values),
  .repeats = 0,
  .end_delay = 0};
/* 重复3次duty_values中指定的占空比,最后保持最后一个占空比的值即100% */
nrfx_pwm_simple_playback(&gs_m_nrfx_pwm, &s_m_seq, 3, 0);
```
在这里还是要特别说明一下，Nordic 52840的硬件PWM是很强大的，因为我们平时使用PWM时并不一定只是输出一个占空比波形，有的时候我们需要不断地重复去改变占空比，这时如果用纯软件的去实现的话会非常地麻烦。但是，52840的硬件PWM可以先方便的实现这些功能，这里小编就不再详述。小编上面的代码就实现了以20%的占空比步长实现0%~100%且重复3次。

### 优与劣
小编上次讲解了如何用三种不同的方式生成PWM波形，他们各自有各自的优缺点。
- RTC
  - 优点
    采用RTC最大的优点就是可以在需要低功耗的使用场景使用；
  - 缺点
    PWM的精度不够高，PWM的周期最大只能达到255；

- TIMER
  - 优点
    PWM的精度可以达到很高，使用起来也很方便；
  - 缺点
    功耗可能会比较高，无法在低功耗下的场景下使用且如果在定时器不够用的情况下，会给工程带来不小的挑战；
  
- 硬件PWM
  - 优点
    同样可以做到很高精度，而且可以做一些复杂的应用，例如实现LED渐变的功能等等；
  - 缺点
    除了不能在低功耗场景下使用以及配置复杂之外，好像也没有其他什么毛病；
  
### 效果展示
- RTC
 ![](the%20releated%20pics%20about%20tutorials/PWM_FOR_RTC.png)
- TIMER
 ![](the%20releated%20pics%20about%20tutorials/PWM_FOR_TIMER.png)
- 硬件PWM
 ![](the%20releated%20pics%20about%20tutorials/PWM_FOR_HARDWARE_PWM.png)

**本文原创,转载请注明出处**
