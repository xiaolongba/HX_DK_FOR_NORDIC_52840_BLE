# 红旭无线开发板BLE实战教程对应源码目录资料说明
该目录主要是存放红旭无线开发板的实战对应的源码,由以下几个部分组成:
<!--
## ESP32
### 入门基础篇

- [创建一个WIFI热点](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BE%EF%BC%9A%E5%A6%82%E4%BD%95%E5%88%9B%E5%BB%BA%E8%87%AA%E5%B7%B1%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E7%83%AD%E7%82%B9/app)

  讲解了如何使用模板工程创建自己的第一个ESP32热点

- [按键操作之单击/长按/多击](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%BA%8C%E8%AF%BE%EF%BC%9A%E6%8C%89%E9%94%AE%E5%8D%95%E5%87%BB%E4%BB%A5%E5%8F%8A%E5%A4%9A%E5%87%BB%E7%9A%84%E5%AE%9E%E7%8E%B0/app)

  讲解了如何在ESP32上利用队列/定时器/GPIO口中断实现多个按键的单击/双击/多击功能

- [PWM彩灯](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%85%A5%E9%97%A8%E5%9F%BA%E7%A1%80%E7%AF%87%EF%BC%9APWM%E5%BD%A9%E7%81%AF)

  讲解了如何使用ESP32的PWM去驱动红旭无线Mini开发板的RGB灯

- [深入了解ESP32的UART](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%85%A5%E9%97%A8%E5%9F%BA%E7%A1%80%E7%AF%87%EF%BC%9A%E6%B7%B1%E5%85%A5%E4%BA%86%E8%A7%A3ESP32%E7%9A%84UART)
  
  讲解了如何使用ESP32的UART

- [如何使用ESP32驱动SHT30（I2C）](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%85%A5%E9%97%A8%E5%9F%BA%E7%A1%80%E7%AF%87%EF%BC%9A%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8ESP32%E9%A9%B1%E5%8A%A8SHT30%EF%BC%88I2C%EF%BC%89)

  讲解了如何使用ESP32的I2C去驱动SHT30传感器

- [如何使用ESP32驱动OLED屏(I2C)](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%85%A5%E9%97%A8%E5%9F%BA%E7%A1%80%E7%AF%87%EF%BC%9A%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8ESP32%E9%A9%B1%E5%8A%A8OLED%E5%B1%8F%EF%BC%88I2C%EF%BC%89)

  讲解了如何使用ESP32的I2C去驱动OLED屏

### 基础应用篇

- [ESP32如何建立TCP长连接](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%9F%BA%E7%A1%80%E5%BA%94%E7%94%A8%E7%AF%87%EF%BC%9AESP32%E5%A6%82%E4%BD%95%E5%BB%BA%E7%AB%8BTCP%E9%95%BF%E8%BF%9E%E6%8E%A5)
  
  讲解了如何使用ESP32建立tcp server和client，让ESP32和手机/进行数据交互

- [ESP32之UDP单播/广播](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%9F%BA%E7%A1%80%E5%BA%94%E7%94%A8%E7%AF%87%EF%BC%9AESP32%E5%A6%82%E4%BD%95%E5%BB%BA%E7%AB%8BUDP%E5%B9%BF%E6%92%AD%E5%92%8C%E5%8D%95%E6%92%AD)

  讲解了如何使用ESP32实现UDP单播和广播的功能 
  
- ESP32之MQTT通讯   

- 如何基于ESP32实现WEB_SOCKET的功能

- ESP32如何解析JSON数据 

- ESP32如何创建SSL/TLS连接

- 如何利用第三方库加解密通讯数据

- 如何实现空中升级功能

- [ESP32如何使用SmartConfig快配](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%9F%BA%E7%A1%80%E5%BA%94%E7%94%A8%E7%AF%87%EF%BC%9ASmartConfig%E5%BF%AB%E9%85%8D%E8%B4%A6%E5%8F%B7%E5%AF%86%E7%A0%81)
  
  讲解了如何使用SmartConfig给ESP32快配SSID和密码，让其连接云服务器获取本地天气

### 中级应用篇    
- [ESP32如何利用mbedtls获取天气预报](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%89%E8%AF%BE%EF%BC%9A%E5%88%A9%E7%94%A8mbedtls%E8%8E%B7%E5%8F%96%E5%A4%A9%E6%B0%94%E9%A2%84%E6%8A%A5/app)   
   
  讲解了如何在ESP32上利用mbedtls/按键/呼吸灯实现天气预报的功能   

- [基于天猫精灵,语音控制ESP32](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%A6%82%E4%BD%95%E5%AE%9E%E7%8E%B0%E5%9F%BA%E4%BA%8E%E5%A4%A9%E7%8C%AB%E7%B2%BE%E7%81%B5%2C%E6%8E%A7%E5%88%B6%E7%BA%A2%E6%97%ADmini%E5%BC%80%E5%8F%91%E6%9D%BF%E7%9A%84RGB%E7%81%AF)

  讲解了如何通过天猫精灵来语音控制ESP32,源码是基于vscode+cmake特性的esp-idf下编译通过
- 基于ESP32的实现wifi插座的功能  

- 基于ESP32的实现MP3功能   
     
### 高级应用篇
- 基于百度DuerOS实现类似天猫精灵的AI音箱功能   
-->

## nRF52840
### 入门基础篇

- [Nordic 52840基础教程第一课:Hello World](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---hello%20world)

  讲解了如何使用模板工程创建自己的第一个**Hello World**工程,并介绍了通过**UART**以及**RTT**打印输出Hello World信息

- [PWM 点灯,我是专业的](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---pwm)

  讲解了如何使用硬件定时器/RTC/硬件PWM产生PWM波形

- [单击,双击,N 击又有何难?](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---multi%20buttons)
  
  讲解了如何使用app_timer实现按键的单击以及多击的功能

- [什么是 PPI，它能干什么?](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---ppi)

  讲解了如何使用ppi实现按键点亮LED

- [如何使用硬件定时及计数器](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---hardware%20timer)

  讲解了如何使用PPI+GPIOTE+TIMER实现硬件定时器以及计数器的功能


- [脉冲宽度很难测?红旭可不怕](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---measure%20pluse%20width)

  讲解了如何使用PPI+GPIOTE+TIMER,测量脉冲的占空比
  
- [不一样的 ADC 采集](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---adc)

  讲解了如何使用过采样的方式，读取当前VDD的电压值，并将电压值打印出来

- [小阶段总结](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Basic%20tutorial---phase%20summary)

  该源码主要是将上面的内容，通过菜单的方式汇集成一个工程，做一个阶段性的总结
  
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

- [SIG Mesh 之点灯应用](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/%E5%9F%BA%E4%BA%8EGeneric%20OnOff%20Model%E7%9A%84Mesh%E7%82%B9%E7%81%AF%E5%BA%94%E7%94%A8)  

  主要是讲解如何通过Nordic官方的Mesh SDK包,创建一个标准的Generic OnOff模型

### 高级应用篇
- 基于天猫精灵的 MESH 应用

- 基于物联网区块链的 MESH 应用

- WIFI 以及 SIG MESH 共存的智能家居应用

- 使用 BLE 点亮 ZIBEE 灯泡,照亮你的美,温暖你的心

- BLE/ZIGBEE/WIFI 三合一,创造无限可能

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

