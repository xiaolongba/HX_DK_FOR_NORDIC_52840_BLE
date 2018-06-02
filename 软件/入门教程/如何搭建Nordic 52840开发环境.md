# 如何搭建Nordic 52840开发环境

## 前言
> 我相信最近很多小伙伴都已经陆陆续续地收到红旭的无线开发板了吧,小编非常感谢这些红旭铁粉地强力支持,同时**红旭无线开发团队**一致决定在正式售价的基础上打85折用来回馈铁粉.那么对于那些已经收到开发板的小伙伴们,是不是就上个电就放进抽屉**吃灰**呢?显然这是绝对不允许发生的,那么接下来就跟随小编的步伐一起看看如何搭建Nordic 52840开发环境,开启无线事业的另外一个征途吧.

## 开发环境
- Windows/Mac/Linux操作系统
- 红旭nRF52840+ESP32 Mini无线开发板
- SEGGER Embedded Studio IDE
- JLink**(请不要使用2,30块的那种垃圾Jlink OB,因为有可能会出现一些无法想象的问题)**

## 为什么要选择SEGGER Embedded Studio
现在，占据嵌入式开发工具IDE半壁江山的主要是**MDK**和**IAR**,我想从事嵌入式开发的不太可能不认识这两个IDE吧，而且大部分工程师也都很熟悉．这个时候可能有人会问了，既然大家都熟悉的东西你不用，你非要选择偏门的工具，你这不是傻逼嘛,增加我的学习成本．其实，这样骂小编也不是没有道理，但是当你看了下面几个原因之后，也许你就不会骂我了，有可能举双脚赞成哦．具体理由如下：
- Nordic官方主推使用该IDE,后续Nordic在2019年推出的芯片级NB-IOT也是基于该IDE开发的 **(届时红旭也会推出相对应的开发板)**,所以有时候做事不能光看眼前,还是要有一定的前瞻性和格局的;
- 国内很多公司或者工程师,已经将破解版的MDK和IAR当成正版使用了,好像这一切都是理所当然的,其实这个是很不好的,起码在我看来是很不好的;
- SEGGER Embedded Studio在用户体验方面相对会好过MDK和IAR，有些功能显示也会更直观；
- SEGGER Embedded Studio是跨平台开发IDE,支持MAC/Windows/Linux等开发平台,以后你就不必担心换了一个平台代码移植的问题;
- Nordic已经为开发者购买了**SEGGER Embedded Studio的使用版权**,只要是使用Nordic的产品均可以免费使用该IDE,不用再去担心版权的问题;

以上几点也是为什么红旭会选择该IDE来开发Nordic 52840.

## 如何下载
**SEGGER Embedded Studio**是SEGGER公司开发的一款用于嵌入式开发的IDE,不仅支持Nordic的芯片,而且还支持市场上大部分主流的MCU,你即使没有licence也可以使用该IDE的所有功能,没有任何代码限制.大家可以在SEGGER公司的官方上根据自身的开发环境下载对应的软件版本,下载地址如下所示:
[SEGGER Embedded Studio下载地址](https://www.segger.com/downloads/embedded-studio/).

## 如何安装
**SEGGER Embedded Studio**的安装就是无脑式地点击<code>Next</code>就可以完成安装了.

## 如何激活
默认情况下,首次安装**SEGGER Embedded Studio**之后,该软件是没有激活的,也就是说还没有获取到license.那么如何获取免费的license呢,如下步聚所示 **(这里所有操作均是在windows下进行,其他平台的操作跟这个类似)**:
- 在桌面打开SEGGER Embedded Studio,首次打开的界面如下所示:
![首次打开的界面](https://raw.githubusercontent.com/xiaolongba/picture/master/open%20for%20the%20first%20time%20for%20ses.png)

- 按下<code>F7</code>-><code>Activate Your Free License</code>
![](https://raw.githubusercontent.com/xiaolongba/picture/master/No%20license%20for%20commercial%20use.png)
![](https://raw.githubusercontent.com/xiaolongba/picture/master/Emedded%20Studio%20Lisence%20Activate.png)
![](https://raw.githubusercontent.com/xiaolongba/picture/master/Emedded%20Studio%20Lisence%20Activate1.png)
在收到License的邮件中复制license至如下空白处即可<font color=#ff0000>(**注意:QQ邮箱是收不到License的**,小编用的谷歌邮箱是可以的)</font>
![](https://raw.githubusercontent.com/xiaolongba/picture/master/Emedded%20Studio%20Lisence%20Activate2.png)
至此,激活工作就完成了.

## 打开第一个工程
按照上文中的那些描述,此时开发环境搭建已经完成了99%,接下来只需打开一个示例工程,编译并烧录至红旭nRF52840+ESP32 Mini无线开发板即可完成您的第一个工程.步骤如下所示:
- 下载[Nordic 52840 BLE软件开发包，即SDK](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5-SDK-zip/59021)并解压
- 在SEGGER Embedded Studio中选择<code>File</code>-><code>Close Solution</code>
- 在SEGGER Embedded Studio中选择<code>File</code>-><code>Open Solution</code>选择示例工程文件,小编的路径如下所示:
```
C:\Users\Administrator\Desktop\Wireless_Tech\nRF5_SDK_15.0.0_a53641a\examples\ble_peripheral\ble_app_template\pca10056\s140\ses\ble_app_template_pca10056_s140.emProject
```
   <font color=#ff0000>**(注意:正式开发过程中,SDK的路径不要包含有中文以及路径不要过长)**</font>
- 在SEGGER Embedded Studio界面中,按下<code>F7</code>编译,然后连接上Jlink再按<code>F5</code>即可将固件下载至红旭nRF52840+ESP32 Mini无线开发板中

## 延伸
如果大家想要更加了解SEGGER Embedded Studio的使用,其实Nordic官方已经推出了7节视频教程,小编已经从Youtube中下载了这套高清无码格式的视频,下载地址如下:
[SEGGER Embedded Studio官方视频教程](https://pan.baidu.com/s/1PyrMZPZVAqpLKxGpdbeIWA)
