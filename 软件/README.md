# 软件资料说明
本目录主要是存放红旭无线开发板的软件相关的资料以及源码,目前由以下几个部分组成:

- Nordic 52840协议栈

  该子目录存放各个不同版本的协议栈,因为官方会根据市场以及实际情况更新协议栈,所以协议栈并不是固化不变的;协议栈的获取有下面两个渠道:
  - [Nordic 52840 单独的协议栈下载地址](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/S140-SD-v6/60624)
  - SDK开发包中已经自带有协议栈了,<code>SDK开发包的绝对路径</code>-><code>components</code>-><code>softdevice</code>-><code>协议栈代号</code>-><code>hex</code>即可找到协议的HEX文件
- Nordic 52840软件开发包
  
  该子目录存放各个不同版本的SDK软件开发包,官方会不断增加并完善SDK,然后发布新版本的SDK.因此,SDK也是会不断更新的.同样,有时候我们会来不及将最新的SDK上传,大伙可以通过以下链接获取最新的SDK开发包下载地址:
  - [BLE SDK下载地址](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5-SDK-zip/59021)
  - [ZIGBEE & THREAD SDK下载地址](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5-SDK-for-Thread-and-Zigbee/67604)
  - [SIG Mesh SDK下载地址](https://www.nordicsemi.com/eng/nordic/Products/nRF5-SDK-for-Mesh/nRF5-SDK-for-Mesh/62377)
- PC上位机软件
  该子目录主要存放开发nRF52840所需要的一些上位机辅助软件,具体如下所示:
  - [SEGGER Embedded Studio for ARM IDE](https://www.segger.com/downloads/embedded-studio/)
  - [nRF-Connect-Windows](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF-Connect-Windows/58847)
  
    该软件主要是配合USB Dongle做一些辅助的评估测试以及一些电流测试相关的应用,更多详情请安装软件之后查看;
  - [nRFgo Studio-Win64](https://www.nordicsemi.com/eng/nordic/Products/nRFgo-Studio/nRFgo-Studio-Win64/14964)
  
    该软件主要是配合Jlink进行 **协议栈/应用程程序/Bootloader**烧录或者擦除的图形化上位机软件.现在很少使用这个软件,好像官方并不怎么推荐使用了;  
  - [nRF5x-Command-Line-Tools-Win32](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5x-Command-Line-Tools-Win32/58850)
  
    该软件主要是实现 **烧录/擦除/合并**固件的命令行下工具,在安装**nRF-Connect-Windows**以及**nRFgo Studio**会一起安装,但是也可以单独安装;
  日常主要使用的就是这几个软件,其他更多的工具可以官方均可在[官网](https://www.nordicsemi.com/eng/Products)上找到.
- 入门教程

  该子目录主要是存放讲解如何入门红旭无线开发板的文字教程,更多详情请查看对应的[文件夹](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B)
- 红旭无线开发板实战教程

  该子目录主要是存放红旭无线开发板的实战文字教程,更多详情请查看对应的[文件夹](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B)
- 红旭无线开发板实战教程对应源码

  该子目录主要是存放红旭无线开发板的实战对应的源码,更多详情请查看对应的[文件夹](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81)
  
