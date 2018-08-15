# 红旭无线开发板

红旭无线开发板主要由乐鑫**ESP32**模块以及**Nordic 52840**模块组成，涵盖了目前市面上大部分的主流无线通讯协议，可以满足大部分的物联网应用场景。
## 简介
红旭无线开发板主要由以下两大部分组成
- NRF52840+ESP32 Mini核心板
- NRF52840以及ESP32的各个外设配件(例如传各种感器模块、语音识别模块、锂电池充放电模块等等)

红旭无线开发板包括丰富的硬件资源，**NRF52840**以及**ESP32**模块的IO口均全部引出。同时，红旭无线开发板支持**WiFi**、**BLE5.0**、**Zigbee3.0**、**Thread**、**2.4G**以及**SIG MESH**等市面上主流的无线通讯协议，基本上满足用户大部分的功能需求，特别是智能家居的应用场景。

红旭无线开发板可以同时运行**Wifi+BLE5.0+Zigbee/Thread**或者**Wifi+SIG MESH**两种模式，并且提供丰富的示例以及软件实战教程，希望大家通过红旭无线开发板学习到这些无线技术，从而在工作上如鱼得水，获得更高的薪酬，为共和国的无线事业作出贡献，登上人生巅峰。
[![NRF52840+ESP32 Mini海报图](https://raw.githubusercontent.com/xiaolongba/wireless-tech/master/pics/ESP32%2BNordic%2052840%20Mini.jpg)](https://shop507575225.taobao.com/index.htm?spm=2013.1.w5002-16973646476.2.56ea1f47dUx4Ha)
## 硬件规格
- Nordic高性能多协议共存的SoC nRF52840
    - 32-bit ARM Cortex-M4F @ 64MHz内核 
    - 1MB flash和256KB RAM
    - 支持全功能特性的BLE 5.0、802.15.4、2.4G以及SIG MESH
    - 全速12Mbs USB控制器
    - NFC Tag-A
    - 支持+ 1.7V~5.5V的工作宽电压
    - 支持I2S、I2C、SPI、UART、ADC、PDM等外设
    - 支持128 bit AES/ECB/CCM/AAR等加密硬件加速器

- 乐鑫高性能多协议共存的SoC ESP32
    - 两个可以单独控制的 CPU 内核，时钟频率可调，范围从 80 MHz 到 240 MHz
    - 520-kB SRAM、448-kB ROM、16-kB SRAM in RTC 
    - +19.5 dBm 天线端输出功率，确保良好的覆盖范围
    - 802.11 b/g/n
    - 802.11 n (2.4 GHz)，速度高达 150 Mbps
    - 传统蓝牙支持 L2CAP，SDP，GAP，SMP，AVDTP，AVCTP，A2DP (SNK) 和 AVRCP (CT) 协议
    - 低功耗蓝牙 (BLE) 支持 L2CAP, GAP, GATT, SMP, 和 GATT 之上的 BluFi, SPP-like 协议等
    - 集成 4 MB flash
    - 外设包括电容式触摸传感器，霍尔传感器，低噪声放大器，SD 卡接口，以太网，高速 SPI，UART，I2S 和 I2C
- ESP32模块具有22个可编程GPIO口
- nRF52840模块具有17个可编程GPIO口
- 可编程RGB
- 标准的2.54mm间距的GPIO引脚
- 锂电池供电接口
- ESP32模块以及nRF52840模块分别对应一个复位按键以及用户按键

## 引脚位图
红旭无线开发板中的所有IO口均引出成2.54mm间隔的排针，具体如下图所示：

![红旭开发板硬件模块图](https://raw.githubusercontent.com/xiaolongba/wireless-tech/master/pics/%E7%BA%A2%E6%97%AD%E5%BC%80%E5%8F%91%E6%9D%BF%E7%A1%AC%E4%BB%B6%E6%A8%A1%E5%9D%97%E5%9B%BE.jpg)

## 资料
### 硬件
- [开发板原理图](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%ADnRF52840%2BESP32%20Mini%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%8E%9F%E7%90%86%E5%9B%BE)
- [NRF52840 芯片相关文档](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/NRF52840%20%E8%8A%AF%E7%89%87%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3)
- [ESP32 芯片相关文档](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/ESP32%20%E8%8A%AF%E7%89%87%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3)
- [配件模块芯片相关文档](https://github.com/xiaolongba/wireless-tech/blob/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%AD%E9%85%8D%E4%BB%B6%E6%A8%A1%E5%9D%97%E8%8A%AF%E7%89%87%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3/README.md)
- [配件模块原理图](https://github.com/xiaolongba/wireless-tech/blob/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%AD%E9%85%8D%E4%BB%B6%E6%A8%A1%E5%9D%97%E5%8E%9F%E7%90%86%E5%9B%BE/README.md)
- [红旭nRF52840 Dongle原理图](https://github.com/xiaolongba/wireless-tech/blob/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%ADnRF52840%20Dongle%E5%8E%9F%E7%90%86%E5%9B%BE/README.md)

### 软件
- [快速入门指南](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B)
- [红旭无线开发板实战教程](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B)
- [红旭无线开发板实战教程对应源码](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81)
- [软件开发工具](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/PC%E4%B8%8A%E4%BD%8D%E6%9C%BA%E8%BD%AF%E4%BB%B6/README.md)

## 技术交流
![QQ群](https://raw.githubusercontent.com/xiaolongba/picture/master/QQ%20Group.jpg)

