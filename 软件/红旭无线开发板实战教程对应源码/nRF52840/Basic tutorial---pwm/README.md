# 前言
> 该文档主要是讲解如何使用该源码并将源码适配到用户自己的硬件平台上

# 如何适配
其实很多时候我们在网络上找到的很多源码，想要适配到自己的硬件平台上大部分情况都是很困难的。大多数源码分享者很少有专门文档去解释如何去将源码适配到其他人的硬件平台，这就导致一个问题就是即便下载了源码还是需要仔细阅读源码内容并更改，有的能力较差的工程师可能看了也不懂。为了避免这种情况，小编在写源码的时候就注意到这点，尽可能让大家只需稍微改动即可适配到自己的硬件平台上。

- 下载源码

  这里小编就不再重复造轮子，我将我之前写的一篇[《如何下载红旭无线开发板资料》](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8%E6%8C%87%E5%8D%97)的文章贴上来，那里有说明如何下载源码。

- 适配
  1. 复制**Basic tutorial---pwm**文件夹至SDK的根目录下，如下图所示
    ![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/Basic%20tutorial---pwm_Source1_User_Guide.PNG)
  
  1. 修改自己的SDK的绝对路径
    
      <code>打开**Basic tutorial---pwm**的SES工程</code>-><code>Tools</code>-><code>Options</code>-><code>Buildings</code>-><code>Global Macros</code>，然后修改自己的SDK绝对路径 **(下面是小编SDK包的绝对路径，其他用户要根据自己的SDK路径进行相应的更改)**
      ```
      SDK_ROOT=F:/Bluetooth/Nordic/SDK/nRF5_SDK_15.2.0_9412b96
      ```
      ![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/Absolute%20Pathgif.gif)
  1. 修改自己的CMSIS_CONFIG_TOOL的绝对路径
    
      <code>选中**Basic tutorial---pwm**的SES工程，并右击鼠标右键</code>-><code>Options</code>-><code>Common</code>-><code>Build</code>-><code>Project Macros</code>，然后修改自己的CMSIS_TOOLS_CONFIG绝对路径 **(下面是小编CMSIS_CONFIG_TOOL的绝对路径，其他用户要根据自己的CMSIS_CONFIG_TOOL路径进行相应的更改)**
      ```
      CMSIS_CONFIG_TOOL=$(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
      ```
      ![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/CMSIS_TOOLS_CONFIG_PATH.gif)

经过以上的步骤，用户就可以直接在自己的开发环境下编译通过了。主要的工作集中在更改自己的路径，也并没有什么很复杂的操作。

## 编译
我相信经过上面的修改，基本上是能解决编译不过的問题的。接下来用户只需更改相应的宏就可以在自己的硬件平台运行该份代码了。
![](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/the%20releated%20pics%20about%20tutorials/Basic%20tutorial---pwm_Source2_User_Guide.PNG)
