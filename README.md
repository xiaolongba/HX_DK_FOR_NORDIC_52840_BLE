# 红旭无线开发板

红旭无线开发板主要由乐鑫**ESP32**模块以及**Nordic 52840**模块组成，涵盖了目前市面上大部分的主流无线通讯协议，可以满足大部分的物联网应用场景。
## 简介
红旭无线开发板主要由以下两大部分组成
- NRF52840+ESP32 Mini核心板
- NRF52840以及ESP32的各个外设配件(例如传各种感器模块、语音识别模块、锂电池充放电模块等等)

红旭无线开发板包括丰富的硬件资源，**NRF52840**以及**ESP32**模块的IO口均全部引出。同时，红旭无线开发板支持**WiFi**、**BLE5.0**、**Zigbee3.0**、**Thread**、**2.4G**以及**SIG MESH**等市面上主流的无线通讯协议，基本上满足用户大部分的功能需求，特别是智能家居的应用场景。

红旭无线开发板可以同时运行**Wifi+BLE5.0+Zigbee/Thread**或者**Wifi+SIG MESH**两种模式，并且提供丰富的示例以及软件实战教程，希望大家通过红旭无线开发板学习到这些无线技术，从而在工作上如鱼得水，获得更高的薪酬，为共和国的无线事业作出贡献，登上人生巅峰。
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

## 开发板资料
### 硬件
- [开发板原理图](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/%E7%BA%A2%E6%97%ADnRF52840%2BESP32%20Mini%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%8E%9F%E7%90%86%E5%9B%BE)
- [NRF52840 芯片相关文档](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/NRF52840%20%E8%8A%AF%E7%89%87%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3)
- [ESP32 芯片相关文档](https://github.com/xiaolongba/wireless-tech/tree/master/%E7%A1%AC%E4%BB%B6/ESP32%20%E8%8A%AF%E7%89%87%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3)
- [板载芯片相关文档]()
- [配件模块相关文档]()

### 软件
- [快速入门指南](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B)
- [红旭无线开发板实战教程](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B)
- [红旭无线开发板实战教程对应源码](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81)
- [软件开发工具](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/PC%E4%B8%8A%E4%BD%8D%E6%9C%BA%E8%BD%AF%E4%BB%B6/README.md)

## 如何下载红旭无线开发板资料
原本这里的内容其实应该很早就要面世的.但是,我们团队内部一直就生成PDF文档以及源码上传至百度网盘还是将Markdown写的文档以及源码上传至Github上没有一致的结论.两种不同的意见如下:
 - 百度网盘

   受传统单片机的思想影响,很多开发板的资料都是放在百度网盘.开发板生产商通过网盘链接的方式存储以及分享他们的资料.

   - 优点

     大多数嵌入式工程师对这种方式都已经习惯了,学习成本较低;

   - 缺点
     1. 百度网盘经常以**扫黄**为由,删除之前分享的链接,经常会出现过一段时间导致链接失效的情史发生;
     2. 百度网盘因为**极度缺钱**,非会员下载不能全速下载;
     3. 百度网盘的资料细化之后,浏览不方便;
     4. 如果有一部分资料更新,一时半会找到不到更新的是哪些.经常会出现"群主,开发板的资料更新了没有?"这样的对话,经常要人肉通知.

 - Github

   最开始是互联网搞IT那边兴起的.但是,随着时代进步发展,Github慢慢地引伸至嵌入式领域特别是物联网.因为物联网相当于桥梁将传统的嵌入式与互联网联系起来并绑定在一起.

    - 优点

      1. 用户可以通过<code>git log</code>的命令查看修改的内容;
      2. "群主,开发板的资料更新了没有?"这样的对话再也不会重现,用户只需要通过<code>git pull</code>即可下载更新的那部分的内容,而不必下载整个资料;
      3. 可以清晰地浏览整个开发板资料的架构;
      4. 使用markdown写出来的文档,排版更加好看更加丰富;
      5. 如果开发板生产商提供的资料有错误的地方,可以pull request告之开发板生产商.然后,开发板生产商合并即可完成错误的引正;最后,用户只要<code>git pull</code>即可下载更新的那部分的内容.

   - 缺点

     增加用户的学习时间成本

综上所述,我们最终选定Github为主,百度网盘为辅的方式来存储红旭无线开发板的资料.其中,Github主要用于存储教程以及其对应的源码,而百度网盘则存放一些视频.



### 如何下载

Github的下载有两种方式,分别如下所示:

- 打开[红旭开发板资料代码仓](https://github.com/xiaolongba/wireless-tech),直接<code>clone or download</code>---><code>Download ZIP</code>.但是这种不推荐,因为这样跟直接跟百度网盘下载的方式没什么区别;

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/github%E4%B8%8B%E8%BD%BD%E6%96%B9%E5%BC%8F1.gif)

  

- 使[Git](https://git-scm.com/)来下载红旭开发板资料,操作步骤如下:

  1. 下载[Git工具](https://git-scm.com/download/win)

  2. 下载完成之后,在任意想要存放红旭无线开发板资料的地方,右击鼠标选择<code>Git Bash here</code>.然后再弹出来的窗口输入

     ```c
     git clone https://github.com/xiaolongba/wireless-tech.git
     ```

     即可从Github将资料下载至本地.

     ![](https://raw.githubusercontent.com/xiaolongba/picture/master/github%E4%B8%8B%E8%BD%BD%E6%96%B9%E5%BC%8F2.gif)

     

### 如何查看更新的内容

这个就比较简单,在红旭无线开发板资料的根目录(即有<code>.git</code>的那一层目录)下,右击鼠标选择<code>Git Bash here</code>.然后再弹出来的窗口输入

```c
git log
```

即可查看更新了什么内容.

![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%9F%A5%E7%9C%8B%E6%9B%B4%E6%96%B0%E7%9A%84%E5%86%85%E5%AE%B9.gif)



### 如何同步

这也就是我们平时所说的,开发板供应商的资料理论上永远都是最新的.因此,只想把开发板供应商更新的那部分内容下载下来.只需要在红旭无线开发板资料的根目录(即有<code>.git</code>的那一层目录)下,右击鼠标选择<code>Git Bash here</code>.然后再弹出来的窗口输入

```c
git pull
```

即可跟Github上的红旭开发板资料同步了,不必要又重新下载整个资料,方便地一逼.

![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%90%8C%E6%AD%A5github%E5%86%85%E5%AE%B9.gif)



### 如何只下载Github指定的文件夹内容

有的用户可能比较优秀,他再首次下载时,不想下载整个资料.只想下载他想要的那个文件夹里的内容.本质上Github是没有这样的功能的.但是,全球几十亿人口,总会有一些出类拔萃的人才已经帮我们铺平了道路实现这个功能.即<code>google 浏览器 + gitzip for github插件</code>.

![](https://github.com/xiaolongba/picture/raw/master/GitHub%E4%B8%8B%E8%BD%BD%E5%8D%95%E7%8B%AC%E7%9A%84%E6%96%87%E4%BB%B6%E5%A4%B9%E7%9A%84%E6%96%B9%E6%B3%95.gif)



### 最后

希望广大使用百度网盘的嵌入式工程师,尽快投入Github的怀抱吧.科技才是生产力的第一要素,而不是旧或固化的思想和大脑.
