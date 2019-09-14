# 红旭无线开发板（Nordic 52840 + ESP32）

红旭无线开发板主要由乐鑫**ESP32**模块以及**Nordic 52840**模块组成，涵盖了目前市面上大部分的主流无线通讯协议，可以满足大部分的物联网应用场景。
## 简介
红旭无线开发板主要由以下两大部分组成
- NRF52840+ESP32 Mini核心板
- NRF52840以及ESP32的各个外设配件(例如传各种感器模块、语音识别模块、锂电池充放电模块等等)

红旭无线开发板包括丰富的硬件资源，**NRF52840**以及**ESP32**模块的IO口均全部引出。同时，红旭无线开发板支持**WiFi**、**BLE5.0**、**Zigbee3.0**、**Thread**、**2.4G**以及**SIG MESH**等市面上主流的无线通讯协议，基本上满足用户大部分的功能需求，特别是智能家居的应用场景。

红旭无线开发板可以同时运行**Wifi+BLE5.0+Zigbee/Thread**或者**Wifi+SIG MESH**两种模式，并且提供丰富的示例以及软件实战教程，希望大家通过红旭无线开发板学习到这些无线技术，从而在工作上如鱼得水，获得更高的薪酬，为共和国的无线事业作出贡献，登上人生巅峰。
![NRF52840+ESP32 Mini海报图](https://raw.githubusercontent.com/xiaolongba/wireless-tech/master/pics/ESP32%2BNordic%2052840%20Mini.jpg)
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
    
- nRF52840模块具有17个可编程GPIO口
- 可编程RGB
- 标准的2.54mm间距的GPIO引脚
- 锂电池供电接口
- 一个复位按键以及用户按键

## 引脚位图
红旭无线开发板中的所有IO口均引出成2.54mm间隔的排针，具体如下图所示：

![红旭开发板硬件模块图](https://raw.githubusercontent.com/xiaolongba/wireless-tech/master/pics/%E7%BA%A2%E6%97%AD%E5%BC%80%E5%8F%91%E6%9D%BF%E7%A1%AC%E4%BB%B6%E6%A8%A1%E5%9D%97%E5%9B%BE.jpg)

## 资料
### 硬件
#### 原理图
- [红旭nRF52840+ESP32 Mini无线开发板原理图](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%ADnRF52840%2BESP32%20Mini%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%8E%9F%E7%90%86%E5%9B%BE)
- [红旭nRF52840Mini无线开发板原理图](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%ADnRF52840Mini%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%8E%9F%E7%90%86%E5%9B%BE)
- [红旭nRF52840 Dongle原理图](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%ADnRF52840%20Dongle%E5%8E%9F%E7%90%86%E5%9B%BE)
#### 芯片资料
- [NRF52840 芯片相关文档](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/NRF52840%20%E8%8A%AF%E7%89%87%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3)
### 软件
- [【新手必读】如何下载红旭无线开发板资料](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8%E6%8C%87%E5%8D%97)
- [【新手必读】红旭相关源码的约定俗称](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E7%9A%84%E6%BA%90%E7%A0%81%E7%9B%B8%E5%85%B3%E7%9A%84%E7%BA%A6%E5%AE%9A%E4%BF%97%E7%A7%B0/README.md)
- [【文字】红旭无线开发板之BLE开发教程](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B)
- [【源码】红旭无线开发板之BLE源码](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81)
- [【开发必备】软件开发工具](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/PC%E4%B8%8A%E4%BD%8D%E6%9C%BA%E8%BD%AF%E4%BB%B6/README.md)
- [【SDK】nRF52840软件开发包](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/Nordic%2052840%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91%E5%8C%85/README.md)

以上仅显示Nordic 52840相关的内容,想了解ESP32相关的内容,请在另外一个代码仓[查看](https://github.com/xiaolongba/HX_DK_FOR_ESP32)

<!--
## 购买链接
- [Nordic 52840 + ESP32 Mini开发板](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-16973646507.20.6eb1196c1FlaxB&id=568845368797)    

    该开发板主要由ESP32+Nordic 52840组成，适合热衷于WiFI+BLE的技术开发者进行项目评估及自身技术提升，**如果仅仅是想学习ESP32的工程师，不推荐购买我们的开发板，您可以在网上购买ESP32最小系统的开发板会更划算**。
    ![](pics/ESP32%2BNordic%2052840.png)
- [Nordic 52840 Mini开发板](https://item.taobao.com/item.htm?spm=2013.1.w4004-16973646497.7.206015c7pA0j2L&id=576599477442)

    该开发板主要由我们红旭根据Nordic 52840芯片并参考官方推荐电路设计完成，适合热衷于BLE5.0、Zigbee、Thread以及BLE Mesh的技术开发者进行项目评估及自身技术提升。
    ![](pics/Nordic%2052840%20Mini.png)
- [Nordic 52840 Dongle开发板](https://item.taobao.com/item.htm?spm=2013.1.w4004-16973646497.9.206015c7pA0j2L&id=580295327820)

    该开发板主要由我们红旭根据Nordic 52840芯片并参考官方推荐电路设计完成，LED灯以及按键跟官方的Dongle完全PIN对PIN且烧录口已通过排针引出来，相较于官方的Dongle更符合开发者的习惯，是做为BLE Mesh、Zigbee、Thread组网节点的首选。
    
    ![](pics/Nordic%2052840%20Dongle.png)
-->    
## [SIG MESH教程代码仓](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE_MESH_PUBLIC)
## 技术交流
- QQ群

    ![QQ群](https://raw.githubusercontent.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/master/pics/qq_group_QR_Code.png)

    QQ群主要用于自主的技术以及行业信息交流，现常驻活跃技术人员350+ **（仅限技术开发者加入，非技术人员请勿加入免得发现被踢）**
    
- [技术论坛](http://bbs.wireless-tech.cn/)

    可以在这个论坛上描述你的问题，我可以免费为你解答BLE相关的问题 **(24小时内回复!!!)**
- Github

    也可以直接在这个代码仓的issues向我发起提问 **(24小时内回复!!!)**
    ![](pics/Summit%20your%20issues%20step1.png)
    ![](pics/Summit%20your%20issues%20step2.png)
    ![](pics/Summit%20your%20issues%20step3.png)



