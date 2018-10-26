# Nordic 52840的第一课:Hello World
## 前言
> 众所周知,基本上所有嵌入式入门的第一课都是跟**灯**有关,什么**跑马灯**、**流水灯**、**点天灯**等等.然而,在笔者看来第一课应该跟互联网的第一课一样,向世人宣布我来了,即**Hello World**.因此,红旭的Nordic 52840第一课也是一样.
![](https://raw.githubusercontent.com/xiaolongba/picture/master/emoji.jpg)

## 准备动作
在准备开始**Hello World**之前,我们还必须要有一个Nordic 52840的模板工程,这样我们才可以在工程模版的基础上进行以后一序列地开发.基本上,所有的模板工程就跟嵌入式硬件的最小系统一样,只保留最基本的配置文件,里面什么内容都没有,只有一个入口函数**main()**,至于如何在官方的SDK开发包裁剪出工程模板,这里不表.已经裁剪好的工程模版在这里([请点我](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/%E6%A8%A1%E6%9D%BF%E5%B7%A5%E7%A8%8B)).

## 欢迎来到这个世界
有了工程模版之后,那么接下来进行我们今天的主题,即打印输出**Hello World**.那么通过什么方式打印呢?可以通过以下两种方式:

- UART
- RTT

### UART
#### 硬件
这个就是我们平常口中所说的串口,我们可以通过串口可以打印输出"Hello World"字符串.在此之前,我们看一下红旭无线开发板上USB转TTL所连接的是Nordic 52840的哪两个串口脚. **(注意:除了电源、地、烧录口以及USB接口之外，任意GPIO口均可以做为串口脚)**

- TX-->P0.08
- RX-->P0.06

实物接线示意图如下所示:

![UART接口](https://raw.githubusercontent.com/xiaolongba/picture/master/UART_INTERFACE.jpg)

下图与上图的PIN脚分别是一一对应的

![UART丝印](https://raw.githubusercontent.com/xiaolongba/picture/master/UART_SILK_SCREEN.jpg)

**从上面两幅图可以看出,只需要将 USB_T & NRF52_R,USB_R & NRF52_T**两两通过跳帽连接在一起即可.

#### 软件
我们在模板工程的基础上,添加驱动串口的相关函数.因为模板工程是纯净的,只有维持最小系统所需的一些文件.那么如何来操作呢?如下步骤所示:

- 添加Nordic官方已经封装好的UART驱动函数

![UART相关的驱动函数](https://raw.githubusercontent.com/xiaolongba/picture/master/uart%E7%9B%B8%E5%85%B3%E7%9A%84%E5%87%BD%E6%95%B0.png)

上图就是要实现这次串口打印所需要的UART驱动函数，可能会问怎么需要这么多文件，因为这些文件集成了UART重映射以及接下来的RTT等功能,异常的强大.

- 添加UART相关的头文件路径

![UART相关的头文件路径](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%A4%B4%E6%96%87%E4%BB%B6%E8%B7%AF%E5%BE%84.png)

同样,需要添加的头文件路径也有很多.那是因为官方的SDK将各个功能模块分得很细,不像我们自己写的程序一样所有的文件都放在一个文件夹,所以这个包含的头文件会很多.那么,这个时候问题来了?在SES上是如何添加头文件路径的呢?对于用惯了MDK以及IAR的工程师来说，肯定会一脸懵逼．不过**幸好你们买了红旭的无线开发板**，对于这些细活，肯定有详细的步骤告诉你的，如下所示：

- <code>在SES的项目浏览中选中整个工程并右击</code>-><code>Edit Options...</code>-><code>Common</code>-><code>Build</code>-><code>Project Macros</code>

在打开**Project Macros**的设置中,添加SDK开发包的路径宏(小编的SDK包实际路径如下所示);

```
nRF52840_SDK_DIR=D:/Project/wireless_tech/wireless_tech_template
```
![添加sdk路径宏](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E8%B7%AF%E5%BE%84%E5%AE%8F.gif)
- <code>在SES的项目浏览中选中整个工程并右击</code>-><code>Edit Options...</code>-><code>Common</code>-><code>Preprocessor</code>-><code>User Include Directories</code>

在**User Include Directories**添加头文件路径;
![添加头文件路径](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E5%A4%B4%E6%96%87%E4%BB%B6%E8%B7%AF%E5%BE%84.gif)


```
$(nRF52840_SDK_DIR)/components/toolchain/cmsis/include
$(nRF52840_SDK_DIR)/components/libraries/experimental_log
$(nRF52840_SDK_DIR)/components/libraries/util
$(nRF52840_SDK_DIR)/template_project/config
$(nRF52840_SDK_DIR)/modules/nrfx/mdk
$(nRF52840_SDK_DIR)/components/softdevice/s140/headers
$(nRF52840_SDK_DIR)/components/libraries/experimental_section_vars
$(nRF52840_SDK_DIR)/components/libraries/strerror
$(nRF52840_SDK_DIR)/components/libraries/experimental_log/src
$(nRF52840_SDK_DIR)/components/libraries/experimental_memobj
$(nRF52840_SDK_DIR)\components\libraries\balloc
$(nRF52840_SDK_DIR)\template_project\user_driver\include
$(nRF52840_SDK_DIR)\external\fprintf
$(nRF52840_SDK_DIR)\integration\nrfx\legacy
$(nRF52840_SDK_DIR)\modules\nrfx
$(nRF52840_SDK_DIR)\integration\nrfx
$(nRF52840_SDK_DIR)\modules\nrfx\drivers\include
$(nRF52840_SDK_DIR)\components\libraries\atomic
$(nRF52840_SDK_DIR)\components\libraries\delay
$(nRF52840_SDK_DIR)\external\segger_rtt

```
- 使能UART以及更改UART的TX引脚

在**sdk_config.h**中找到**NRF_LOG_BACKEND_UART_ENABLED**、**NRF_LOG_BACKEND_UART_TX_PIN**以及**NRF_LOG_BACKEND_RTT_ENABLED**,并更改为以下所显示的值.

```c
#ifndef NRF_LOG_BACKEND_RTT_ENABLED
#define NRF_LOG_BACKEND_RTT_ENABLED 0
#endif

#ifndef NRF_LOG_BACKEND_UART_ENABLED
#define NRF_LOG_BACKEND_UART_ENABLED 1
#endif

#ifndef NRF_LOG_BACKEND_UART_TX_PIN
#define NRF_LOG_BACKEND_UART_TX_PIN 8
#endif

#ifndef NRF_LOG_DEFERRED
#define NRF_LOG_DEFERRED 0
#endif
```
至此,就完成了UART函数以及头文件路径地添加,接下来要做的事情就是在main函数调用初始化函数和打印输出函数,最后编译下载即可.

### RTT
RTT全称是 **"Real Time Transfer"**,是SEGGER公司发明的基于Jlink的一门新技术,如果想要更加了解RTT请点击如下链接:
[RTT更多详情](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/).

#### 硬件
要实现RTT的功能,其实只有手上有Jlink即可实现这个功能,并不用再需要额外的一些外设硬件来搭配使用.你只需要将Jlink的SWD引脚分别一一对应接到目标设备的SWD接口即可,**它比UART的好处就是不占用硬件设备的UART外设**.

![开发板SWD接口正面](https://raw.githubusercontent.com/xiaolongba/picture/master/SWD_%E6%AD%A3%E9%9D%A2.jpg)

![开发板SWD接口反面](https://raw.githubusercontent.com/xiaolongba/picture/master/SWD%E5%8F%8D%E9%9D%A2.jpg)

#### 软件
其实这里所要做的事情跟UART中的基本一致.只需要将RTT的使能宏打开并关闭UART的使能宏即可.
- 增加RTT所需要的驱动函数文件

![RTT所需要的驱动函数文件](https://raw.githubusercontent.com/xiaolongba/picture/master/RTT%E7%9B%B8%E5%85%B3%E7%9A%84%E5%87%BD%E6%95%B0.png)

- 在**sdk_config.h**中找到**NRF_LOG_BACKEND_UART_ENABLED**、**NRF_LOG_BACKEND_UART_TX_PIN**以及**NRF_LOG_BACKEND_RTT_ENABLED**,并更改为以下所显示的值.

```c
#ifndef NRF_LOG_BACKEND_RTT_ENABLED
#define NRF_LOG_BACKEND_RTT_ENABLED 1
#endif

#ifndef NRF_LOG_BACKEND_UART_ENABLED
#define NRF_LOG_BACKEND_UART_ENABLED 0
#endif

#ifndef NRF_LOG_DEFERRED
#define NRF_LOG_DEFERRED 0
#endif
```
至此就完成了RTT的配置工作了,接下来要做的事情就是在main函数调用初始化函数和打印输出函数,最后编译下载即可.

## 主函数
上面已经完成了大部分的工作,这里只要在**main函数**,调用以下几个函数即可.
```c
/**
 * Copyright (c) 2014 - 2018, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* =================================================================================
  由于是在官方的基础上更改,故上面的说明不敢更改,从而保持下来
 =================================================================================*/

/**
* @file         main.c
* @brief        用户应用程序入口
* @details      用户应用程序的入口文件,用户所有要实现的功能逻辑均是从该文件开始或者处理
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/06/09, 初始化版本\n
*/


/* =============
头文件包含
 =============*/
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "user_log.h"

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
  /* log函数初始化  */
  log_init();
  NRF_LOG_INFO("/******************************************************************************/\n");
  NRF_LOG_INFO("                         Welcome to wireless-tech world                         \n");
  NRF_LOG_INFO("                         website :bbs.wireless-tech.cn                          \n");
  NRF_LOG_INFO("                         QQ Group:671139854                                     \n");
  NRF_LOG_INFO("/******************************************************************************/\n");
}

```
## 编译并下载
历经千辛万苦最终来到观看结果的这一环节了,很快大家就会看到打印信息了.但是,在此之前我们还需要做最后一个设置.即配置协议栈的路径.如下所示:
<code>在SES的项目浏览中选中整个工程并右击</code>-><code>Edit Options...</code>-><code>Common</code>-><code>Debug</code>-><code>Loader</code>-><code>Additional Load File[0]</code>,在打开的设置中添加协议的绝对路径(以下是小编的协议栈实际路径).

```
D:/Project/wireless_tech/wireless_tech_template/components/softdevice/s140/hex/s140_nrf52_6.0.0_softdevice.hex
```
![添加协议栈路径](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E5%8D%8F%E8%AE%AE%E6%A0%88%E8%B7%AF%E5%BE%84.gif)
配置完成之后,在SES中直接按下<code>F5</code>即可.

## 效果演示
### UART
小编是使用 **SecureCRT**来显示串口打印,至于如何设置以及下载**SecureCRT**,我们这里不表.不废话直接看效果.
![UART输出效果](https://raw.githubusercontent.com/xiaolongba/picture/master/nRF52840_UART_115200.jpg)

### RTT
RTT的效果查看,相对于UART来说会麻烦一些.但是也只是首次要配置下,以后直接用即可.步骤如下所示:
- 打开**JLinkRTTViewer(安装Jlink6.12以上的版本,因为旧版本还没有nRF52840)**并按下图所示设置,设置完成之后点击**OK**且不要关闭RTT View,以后每次使用并要打开;

![RTT设置](https://raw.githubusercontent.com/xiaolongba/picture/master/RTT%E8%AE%BE%E7%BD%AE.png)

- 打开**SecureCRT**,然后点<code>文件</code>-><code>快速连接</code>-><code>选择协议</code>-><code>IP地址</code>-><code>端口号</code>-><code>点连接</code>

![SecureCRT设置](https://raw.githubusercontent.com/xiaolongba/picture/master/SecureCRT.jpg)

![SecureCRT输出效果](https://raw.githubusercontent.com/xiaolongba/picture/master/nRF52840_RTT.png)

## 最后
该教程对应的源码,放在[红旭无线开发板的github代码仓](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Nordic%2052840%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BEHello%20World),热烈欢迎各行业大佬斧正,鄙人虚心接受任何批评以及赞扬.
## 技术交流
![QQ群](https://raw.githubusercontent.com/xiaolongba/picture/master/QQ%20Group.jpg)

**本文原创,转载请注明出处**



