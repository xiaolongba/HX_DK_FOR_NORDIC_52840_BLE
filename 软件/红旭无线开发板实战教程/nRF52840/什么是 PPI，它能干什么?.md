## 前言
>在我接触Nordic的BLE之前，我从未听说过PPI,更不知PPI是何物。后经查阅，发现这东西真叼似DMA又不是DMA，但是用起来又跟DMA很像。共同点就是大家都完全释放了CPU，不同点则是DMA是从内存中存取数据，而PPI则是有点类似于区块链的智能合约一样，只要条件满足Event就会去触发Task．
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
  > [Basic tutorial---ppi](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---ppi)
   
## 什么叫PPI
查阅nrf52840的规格书可以了解到，PPI的全称是**Programmable peripheral interconnect**，译成中文就叫**可编程外设互连**，从名字上看好像有点似懂非懂的感觉，是不是觉得还是有点懵比:grinning:?那么我们再来看一个原文:
```
The programmable peripheral interconnect (PPI) enables peripherals to interact autonomously with each other 
using tasks and events independent of the CPU. The PPI allows precise synchronization between peripherals 
when real-time application constraints exist and eliminates the need for CPU activity to implement behavior 
which can be predefined using PPI.
```
总得来说，就像我在前言中所说的一样Event触发Task，在触发的过程中是不需要CPU干预的。特别适合一些对实时性要求很高的地方，**如即将要写的脉冲宽度调制宽度的测量就是利用PPI的特性来实现，这个我们后面的文章会讲，这里我只是提一下**. 正常情况下，光看文字还是太抽象了没办法很好地理解，那么我们就来看看PPI的框图：
![PPI block diagram](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/PPI%20block%20diagram.svg?sanitize=true)

也许，有的人仍然还是看不懂，那么小编再将这个框图浓缩一下，这样总能看懂吧？
![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/PPI_Block_Simplify.png)

用土语来讲，就是能产生Event的任意外设由PPI通道将能产生Task的任意外设连接起来，然后当这个通道关系建立之后，只要有Event产生那么PPI通道的另一头Task就会被自动触发，整个过程是不需要CPU干预的。

## 如何实现PPI的功能
前面讲解了PPI的一些概念，或多或少有相应的概念以及理解，那么为了进一步深入了解，我们看看如何在nrf52840实现这个功能，基本上PPI遍布在nrf52840的各个外设中，为了减少复杂性，小编准备要讲的是通过一个GPIO产生Event去触发另外一个GPIO去执行它的Task，但是这个前提是要双方提前达成协议，否则就算你的Event来了Task也是不会响应的。
### 初始化GPIOTE和PPI
**这里还是有必要指出来说一下，经常有人问GPIOTE和GPIO的区别是什么。其中多的那个TE分别就是对应的Task和Event.但凡带有这个标志的均支持PPI**，接下来我们看看如何初始化。
```c
/**
 * 初始化gpiote和ppi
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/09/08, 初始化版本\n
 */

void user_app_gpiote_ppi_init(void)
{
  ret_code_t err_code;  
  nrf_ppi_channel_t m_nrf_ppi_channel;
  nrfx_gpiote_out_config_t m_gpiote_out_config = NRFX_GPIOTE_CONFIG_OUT_TASK_TOGGLE(NRF_GPIOTE_INITIAL_VALUE_HIGH);
  nrfx_gpiote_in_config_t m_gpiote_in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(true);

  uint32_t nrfx_gpiote_out_task_addr;
  uint32_t nrfx_gpiote_in_event_addr;
  /* 初始化gpiote */  
  err_code = nrfx_gpiote_init();    
  NRF_LOG_INFO("nrfx_gpiote_init is %d\n",err_code);
  /* 初始化ppi */
  err_code = nrf_drv_ppi_init();
  NRF_LOG_INFO("nrf_drv_ppi_init is %d\n",err_code);

  /* 设置LED灯对应的GPIO口被GPIO TASK控制，且每次有EVENT触发TASK时，取反当前的LED灯 */
  err_code = nrfx_gpiote_out_init(LED_NUMBER,&m_gpiote_out_config);
  NRF_LOG_INFO("nrfx_gpiote_out_init is %d\n",err_code);

  /* 设置按键对应的GPIO口当由高电平变低电平时，产生ENVENT */
  err_code = nrfx_gpiote_in_init(KEY_NUMBER,&m_gpiote_in_config,user_nrfx_gpiote_evt_handler);
  NRF_LOG_INFO("nrfx_gpiote_in_init is %d\n",err_code);

  /* 获取event和task的地址 */
  nrfx_gpiote_out_task_addr = nrfx_gpiote_out_task_addr_get(LED_NUMBER);
  nrfx_gpiote_in_event_addr = nrfx_gpiote_in_event_addr_get(KEY_NUMBER);

  /* 选择未使用的PPI通道 */
  nrfx_ppi_channel_alloc(&m_nrf_ppi_channel);
  /* 将event和task通过ppi_channel0连接起来 */
  nrfx_ppi_channel_assign(m_nrf_ppi_channel,nrfx_gpiote_in_event_addr,nrfx_gpiote_out_task_addr);
  /* 使能选中的PPI的通道 */
  nrfx_ppi_channel_enable(m_nrf_ppi_channel);
  /* 使能gpiote的out task */
  nrfx_gpiote_out_task_enable(LED_NUMBER);
  /* 使能gpiote的in event */
  nrfx_gpiote_in_event_enable(KEY_NUMBER,true);
}
```
从代码的注释就可以很清楚的看到初始化的整个过程。

![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/GPIOTE_PPI.png)

通过以上代码的初始化，就可以实现一个GPIO产生Event去触发另外一个GPIO去执行它的Task，小编这里用到的是用按键产生一个Event,LED来实现这个Task.

## 最后
希望看了这篇文章之后，大家的妈妈再也不用担心你不懂PPI啦，最终的效果如下图所示
**图片待补充**
