# 红旭无线开发板BLE实战教程目录资料说明
该目录主要是存放红旭无线开发板的BLE实战文字教程,由以下几部分组成:
<!--
## ESP32
### 入门基础篇

- **搭建ESP32开发环境**
  - [如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)
  
    该文档讲解了如何使用vscode+乐鑫官方的工具链搭建ESP32的开发环境
    
  - [vscode开发ESP32之修订篇](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E4%BD%BF%E7%94%A8vscode%E5%BC%80%E5%8F%91ESP32%E4%B9%8B%E4%BF%AE%E8%AE%A2%E7%AF%87.md)
  
    该文档讲解了基于[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)的修订补充以及完善了编译速度等相关的内容
    
  - [windows开发ESP32的福音,编译速度堪比Linux](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/windows%E5%BC%80%E5%8F%91ESP32%E7%9A%84%E7%A6%8F%E9%9F%B3%2C%E7%BC%96%E8%AF%91%E9%80%9F%E5%BA%A6%E5%A0%AA%E6%AF%94Linux.md)

    该文档讲解了如何使用Cmake ESP-IDF配合vscode开发ESP32,速度更快并且全面解决乱码问题,不需要安装任何跟linux相关的工具,是当前在windows开发环境上开发ESP32,最完美的教程

- [创建一个WIFI热点](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BE%EF%BC%9A%E5%A6%82%E4%BD%95%E5%88%9B%E5%BB%BA%E8%87%AA%E5%B7%B1%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E7%83%AD%E7%82%B9.md)

  该文档讲解了如何使用模板工程创建自己的第一个ESP32热点

- [按键操作之单击/长按/多击](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%BA%8C%E8%AF%BE%EF%BC%9A%E6%8C%89%E9%94%AE%E5%8D%95%E5%87%BB_%E9%95%BF%E6%8C%89_%E5%A4%9A%E5%87%BB%E7%9A%84%E5%AE%9E%E7%8E%B0.md)

  该文档讲解了如何在ESP32上利用队列/定时器/GPIO口中断实现多个按键的单击/双击/多击功能

- PWM彩灯

- 深入了解ESP32的UART

- 如何使用ESP32驱动SHT30

- 如何使用ESP32驱动OLED屏

### 基础应用篇

- ESP32如何建立TCP长连接
  
- ESP32之UDP单播/组播/广播   

- ESP32之MQTT通讯   

- 如何基于ESP32实现WEB_SOCKET的功能

- ESP32如何解析JSON数据 

- ESP32如何创建SSL/TLS连接

- 如何利用第三方库加解密通讯数据

- 如何实现空中升级功能

### 中级应用篇    
- [ESP32如何利用mbedtls获取天气预报](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%89%E8%AF%BE%EF%BC%9A%E4%B8%89%E6%9D%BF%E6%96%A7%E4%B9%8B%E5%88%A9%E7%94%A8mbedtls%E8%8E%B7%E5%8F%96%E5%A4%A9%E6%B0%94%E9%A2%84%E6%8A%A5.md)   
   
  该文档讲解了如何在ESP32上利用mbedtls/按键/呼吸灯实现天气预报的功能   

- 基于ESP32的实现wifi插座的功能  

- 基于ESP32的实现MP3功能   
     
### 高级应用篇
- 基于百度DuerOS实现类似天猫精灵的AI音箱功能   
-->

## nRF52840
### 入门基础篇
- [初识nRF52840](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/nRF52840/%E5%88%9D%E8%AF%86Nordic%2052840.md)

  该文档介绍了nRF52840的整个内存分布框架以及如何获取入门所需的一些官方资料

- [如何搭建 nRF52840 的开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/nRF52840/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BANordic%2052840%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)

  该文档介绍了以下几个内容:

    - 红旭无线开发团队为什么选择SEGGER Embedded Studio做为IDE
    - 如何获取免费的license以及打开自己的第一个工程
    
- [如何使用Vscode开发调试nRF52840(全网首发)](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/nRF52840/%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8Vscode%E5%BC%80%E5%8F%91%E8%B0%83%E8%AF%95nRF52840(%E5%85%A8%E7%BD%91%E9%A6%96%E5%8F%91).md)

  该文档介绍了如何使用vscode开发并调试nRF52840
  
- [Nordic 52840基础教程第一课:Hello World](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/Nordic%2052840%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BEHello%20World.md)

  该文档讲解了如何使用模板工程创建自己的第一个**Hello World**工程,并介绍了通过**UART**以及**RTT**打印输出Hello World信息

- [PWM 点灯,我是专业的](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/PWM%E7%82%B9%E7%81%AF%EF%BC%8C%E6%88%91%E4%BB%AC%E6%98%AF%E4%B8%93%E4%B8%9A%E7%9A%84.md)

  该文档讲解了如何使用RTC、TIMER1、硬件PWM来实现PWM

- [单击,双击,N 击又有何难?](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/%E5%8D%95%E5%87%BB%2C%E5%8F%8C%E5%87%BB%2CN%20%E5%87%BB%E5%8F%88%E6%9C%89%E4%BD%95%E9%9A%BE%3F.md)

  该篇章里介绍如何使用nrf52840搭配官方的APP_BUTTON和APP_TIMER模块，实现单击、长按、多击的功能

- [什么是 PPI，它能干什么?](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/%E4%BB%80%E4%B9%88%E6%98%AF%20PPI%EF%BC%8C%E5%AE%83%E8%83%BD%E5%B9%B2%E4%BB%80%E4%B9%88%3F.md)

  该篇章里介绍如何通过一个GPIO产生Event去触发另外一个GPIO去执行它的Task，小编这里用到的是用按键产生一个Event,LED来实现这个Task

- [如何使用硬件定时及计数器](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8%E7%A1%AC%E4%BB%B6%E5%AE%9A%E6%97%B6%E5%99%A8%E5%8F%8A%E8%AE%A1%E6%95%B0%E5%99%A8.md)

  该篇主要介绍了如何使用nrf52840的硬件TIMER，并通过PPI实现TIMER0以一秒的间隔亮灭LED，TIMER1计数按键按下的次数

- 脉冲宽度很难测?红旭可不怕

- 不一样的 ADC 采集

- 小阶段总结

### 基础应用篇
- BLE 基础知识

- 如何使用 nRF52840 搭建您的第一个蓝牙外设

- 自定义一个简单的 Profile

- 依葫芦画瓢自定义一个完整的 Profile

- 串口无线透传,我也行

- 配对和绑定,也就那么一回事

- 热启动 VS 冷启动,数据如何保存?

- 不同的广播类型,我应如何决择?

- 牛刀小试 Becaon

- 空中升级(OTA)

- 一直都是被动,如何主动出击?

- 平时都是别人连我,这次轮到我了

- 如何实现一个主机连接 20 个从机

- 主从一体,就是 6

- 蓝牙 5.0 新特性之 2 倍速度

- 蓝牙 5.0 新特性之 4 倍距离

- 蓝牙 5.0 新特性之 8 倍容量

- 功耗问题应如何处理

### 中级应用篇
- SIG Mesh 的基础知识

- 如何入 SIG Mesh 网络

- SIG Mesh 网络之代理节点

- SIG Mesh 网络之普通节点

- SIG Mesh 网络之低功耗节点

- SIG Mesh 网络之朋友节点

- SIG Mesh 网络之中继节点

- SIG Mesh 角色如何切换

- [SIG Mesh 之点灯应用](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/Sig%20Mesh%E7%AC%AC%E4%B8%80%E8%AF%BE---%E5%9F%BA%E4%BA%8EGeneric%20OnOff%20Model%E7%9A%84Mesh%E7%82%B9%E7%81%AF%E5%BA%94%E7%94%A8.md)  

  该文档主要是讲解如何通过Nordic官方的Mesh SDK包,创建一个标准的Generic OnOff模型

### 高级应用篇
- 基于天猫精灵的 MESH 应用

- 基于物联网区块链的 MESH 应用

- WIFI 以及 SIG MESH 共存的智能家居应用

- 使用 BLE 点亮 ZIBEE 灯泡,照亮你的美,温暖你的心

- BLE/ZIGBEE/WIFI 三合一,创造无限可能

### 工具应用篇
- [如何修复或者更新nRF52840 Dongle固件](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840%20Dongle/%E5%A6%82%E4%BD%95%E4%BF%AE%E5%A4%8D%E6%88%96%E8%80%85%E6%9B%B4%E6%96%B0nRF52840%20Dongle%E5%9B%BA%E4%BB%B6.md)

  讲解了如何更新或者修复nRF52840 Dongle的固件
<!--
## nRF52840之Zigbee
### 入门基础应用篇
- 认识ZigBee及网络结构

- IEEE 802.15.4规范

- ZigBee帧结构

- 介绍簇、命令、属性、设备ID、端点等联系

- 了解ZigBee3.0的标准规范

- 讲述网络间的参数及其用途

- 如何进行网络分析及抓包器的使用

- ZigBee3.0网络安全分析

### 基础应用篇

- 如何使用nRF52840创建一个简单的标准工程

- ZigBee3.0之BDB过程

- ZigBee3.0之F&B

- ZigBee3.0之install code

- ZigBee3.0之ZLL

- ZigBee3.0之ZCL互操作

- ZigBee3.0之OTA过程

- ZigBee3.0之低功耗

- ZigBee3.0之属性上报

### 中级应用篇

- 地址表/路由表/关联设备表/子设备表/绑定表的作用及区别

- ZigBee3.0之GP

- ZigBee3.0之Aging

- 终端poll rate

- ZigBee3.0之情景面板的识别

-->

