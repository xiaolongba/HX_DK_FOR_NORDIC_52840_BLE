# 如何搭建ESP32开发环境
## 前言
> ESP32是乐鑫在其上一代ESP8266一炮而红之后,推出的第二代高性价比的产品,ESP32在上一代的基础上增加了蓝牙4.2的功能,加上乐鑫超暴力的价格体系以及不俗的性能,打的其他的wifi半导体厂商黯然失色.同时,各大终端设备厂商纷纷也采用这颗芯片,毕竟谁他妈会跟钱过不去呢,特别是在我们目前这个金钱至上的社会.既然主流的旋律是这样,红旭无线在这点上当然也不会逆流而行,接下来我们就讲讲如何搭建这个ESP32开发环境平台吧.
## 如何选择
不管是ESP8266还是ESP32在wifi这个行业中实在是太红了,简直就是当红炸子鸡.从而导致能搜索到的资料太泛了,我竖着能"点灯",横着也能"点灯",那到底灯要如何点是最好的呢?其实出现这样的情况,看起来好像是**百家争鸣,百花齐放**.但是,在红旭无线看来,这对新手来说这是非常不好的,因为可选择性太强了,新手压根就不知道如何入手.那么,接下来就说说红旭无线是怎么选择的.
- 开源
- 轻量级
- 定位
- 跨平台
- 简单好用

### 开源
这里的开源是指开发工具是不是开源,比如IDE以及其他的辅助工具.特别是我们国内,由于先天性的问题,不可避免的会出现将破解版当正版使用了,你说这样好不好呢?在前期可能没什么问题,但是长期如此就用严重打击工具开发者的利益,就像当年周立功气愤地宣布停止开发TK Studio一样.导致现在国内失去了一款优秀的软件,真是让人惋惜.因为软件开发者也要生存,如果条件允许尽可能地支持正版软件吧.哈哈,反正小编会尽可能地选择开源的.
### 轻量级
轻量级的意思是指开发工具占用的空间要小,不要像微软的**Microsoft Visual Studio**一样,虽然它很强大而且也很牛逼,但是尼玛发展到现在要几十G的空间喔,很容易吓哭工程师好嘛,其实大部分工程师也就是想要写个代码而已,以及使用其强大的代码提示功能.
### 定位
至于定位,这个就是因人而异了,有的人是想我用这个芯片就是DIY玩玩为生活中添加一点乐趣,并不想用来做一些产品级的东西.而有的人是想要做一些产品级的东西,这个时候可能会更加考虑更多的是能深入开发了,也就是说能完全通过代码来控制这个芯片.
### 跨平台
在很久很久以前,可能开发工具大多是在windows系统上运行,那个时候可能还没有跨平台这样的概念或者还不是很流行.如今,现在已经发展到Windows/Mac/Linux三国鼎立的局面了,作为工程师在选择上就应该更多的考虑到这一点.
### 简单好用
这点也是广大工程师所求,如果一个工具软件要设置一堆参数,这是很让人崩溃的.同时,也很容易导致很多问题.

综上所述,微软的**Visual Studio Code**就成为红旭无线做为开发ESP32的选择.
## 如何下载安装
### IDE
**Visual Studio Code**大家可以在微软的官网上根据自身的开发平台下载,至于安装方法就是无脑式地按<code>Next</code>就好了,下载地址如下所示:
[Visual Studio Code下载地址](https://code.visualstudio.com/)
### SDK
乐鑫的SDK包均放在Github上 **(尽可能地选择release版本,不要选择尝鲜版本)**,具体下载地址如下所示:
[esp32 sdk开发包下载地址](https://github.com/espressif/esp-idf/releases)
### 工具链
**Visual Studio Code**毕竟只是一个轻量级的代码编辑工具,本身是不自带工具链的,而且乐鑫ESP32芯片使用的又不是主流的ARM内核,所以还是要使用乐鑫官方指供的工具链才行,具体的下载如下所示:
[ESP32工具链下载地址](http://esp-idf.readthedocs.io/en/latest/get-started/windows-setup.html)
## 如何使用
下载完**Visual Studio Code**和**ESP32工具链**,那么如何搭建起来开发ESP32呢?其实很简单,
**ESP32工具链**其实完成了大部分的设备了,只需要解压就可以直接使用,具体的使用步骤如下所示:
- 在自己选择适当的路径下解压ESP32工具链 **(不要存在有中文路径,路径也要尽可能地短)**
![解压ESP32工具链](https://raw.githubusercontent.com/xiaolongba/picture/master/unzip_toolchain.gif)

- 在自己选择适当的路径下解压SDK开发包 **(不要存在有中文路径,路径也要尽可能地短)**
![解压SDK开发包](https://raw.githubusercontent.com/xiaolongba/picture/master/unzip_sdk.gif)

- 设置sdk开发包的路径,那解压后sdk开发包的根目录路径,那在 **esp32_toolchain.sh** 增加
sdk开发包的根目录路径 **(export IDF_PATH="D:/Project/ESP32/sdk/esp-idf-v3.0")** 这个是小编的sdk开发包路径
![设置sdk开发包的路径](https://raw.githubusercontent.com/xiaolongba/picture/master/sdk_path_setting.gif)

- 打开**Visual Studio Code**并将shell嵌入至**Visual Studio Code**的集成终端,设置的参数 **(其中shell的路径因不同解压路径不同而不同)**,如下所示:
```
"terminal.integrated.shell.windows": "D:\\Project\\ESP32\\toolchain\\esp32_win32_msys2_environment_and_toolchain-20180110\\msys32\\msys2_shell.cmd",
"terminal.integrated.shellArgs.windows": ["-defterm", "-mingw32", "-no-start", "-here"]
```
![嵌入shell](https://raw.githubusercontent.com/xiaolongba/picture/master/interate%20shell%20to%20vscode.gif)

- 使用**Visual Studio Code**打开sdk开发包中的工程示例文件,打开之后,然后同时下<code>Ctrl</code>+<code>`</code>就可以打开嵌入了shell的终端,此时就可以开发您的第一个esp32应用了
![开发esp32应用](https://raw.githubusercontent.com/xiaolongba/picture/master/develop%20sdk.gif)

## 遗憾
经过上面几个步骤,一个ESP32的开发环境就算搭建完成了.但是,有个小小的遗憾,在**Visual Studio Code**的集成终端中使用 **"make menuconfig"** 命令时会出现乱码 **(我已经在vscode的github上提出了这个问题,就看vscode官方怎么解决吧)**

## 技术交流
![QQ群](https://raw.githubusercontent.com/xiaolongba/picture/master/QQ%20Group.jpg)

**本文原创,转载请注明出处**
