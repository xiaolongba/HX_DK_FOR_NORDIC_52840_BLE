## 前言
在阅读本篇文章之前,为了更好地理解即将展开的内容,读者们还是需要提前阅读[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)以及[使用vscode开发ESP32之修订篇](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E4%BD%BF%E7%94%A8vscode%E5%BC%80%E5%8F%91ESP32%E4%B9%8B%E4%BF%AE%E8%AE%A2%E7%AF%87.md)这两篇文章.如果是我们的老朋友,那接下来的内容也自然可以看得明白.接下来,小编将给大家讲解使用全新的方式,更快更适合Windows环境下使用vscode来开发ESP32开发.

> 这段时间在QQ群里经常有很多新人在看了笔者的这篇文章,按照步骤来操作之后，出现大概率无法正常编译的问题。当时小编听到他们的抱怨，心底就想 **“你们头脑能不能再Smart点”** ,大学的老师上课的PPT都用了几十年了，还不是照样教你们，你们出来社会不也照 样拿着几十K的月薪？难道你们连小编都不如吗？后来，我发现我日，乐鑫官方的SDK已经全面支持Cmake了。好吧，这个时候小编也不得不再次更新此教程了。随我慢慢道来……

## 系统环境
小编要讲的内容均在以下环境进行测试通过，其他的系统环境理应也是大同小异.
![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E7%94%B5%E8%84%91%E9%85%8D%E7%BD%AE.png)

## 准备工作
在开始进入主题之后,我们还要下载以下几个工具.

- [ESP-IDF Tools Installer](https://docs.espressif.com/projects/esp-idf/en/latest/get-started-cmake/windows-setup.html)
	 
	 打开上面的链接找到 **ESP-IDF Tools Installer**章节，下载最新版本的ESP-IDF Tools Installer即可。

- [Git For Windows](https://gitforwindows.org/)

	如果之前安装过，则不用再次下载此工具

上面两个工具下载完成之后,均无脑地安装至自己指定的盘符下即可.
### 下载Cmake特性的ESP-IDF（最新的版本已经默认全面支持Cmake了）
这个SDK是必须要下载的.这个SDK跟前两篇[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)以及[使用vscode开发ESP32之修订篇](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E4%BD%BF%E7%94%A8vscode%E5%BC%80%E5%8F%91ESP32%E4%B9%8B%E4%BF%AE%E8%AE%A2%E7%AF%87.md)中的SDK不一样.

- 步骤1

  打开任意你想要存放ESP-IDF文件的绝对路径,单击**鼠标右键**->**Git Bash Here**

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/Git%20Bash%20Here.png)

- 步骤2

  ```
  git clone --recursive https://github.com/espressif/esp-idf.git
  ```
  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/Cmake%20%E4%B8%8B%E8%BD%BD.gif)

### 设置环境变量
这个操作是充要条件必不可少,否则会出现意想不到的情况.如果有 **天秀之才**不听劝,然后出了问题就是活该.

- 设置SDK的路径&增加编译工具的路径

**这里的路径是指到SDK的根目录**，以下是小编的相关设置信息.

- SDK根目录的绝对路径
  ```
  D:\Project\ESP32\esp\esp-idf
  ```

- 编译工具的路径
  ```
  %IDF_PATH%\tools
  ```

- 详细地操作 

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F%E8%AE%BE%E7%BD%AE.gif)
	
### 查看注册表
**注意**,这一小篇节很重要.是否有乱码就靠这里的神操作了.希望那些不认真看文字的大佬要睁大眼睛看了,小编来放大招了.

 - <code>Windows键</code>+<code>R</code>
 - <code>regedit</code>
 - 找到**HKEY_CURRENT_USER\Console**


- 查看是否有关键信息

  这里所说的关键信息是指的是,是否有如下两个内容.

	- **%SystemRoot%_system32_cmd.exe**
	- **C:_Python27_python.exe**

	![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B3%A8%E5%86%8C%E8%A1%A8.png)

  如果有这两项内容，则**分别**将 **%SystemRoot%_system32_cmd.exe** 以及 **C:_Python27_python.exe** 右侧中的 **CodePage**对应的值改成十进制的 **437**,以及 **FaceName**对应的值改为 **Lucida Console**

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B3%A8%E5%86%8C%E8%A1%A8%E6%9B%B4%E6%96%B0%E5%80%BC.png)
 
  如果好死不死,我特么电脑没有这两玩意呢？这个时候也不要怕,小编说是大招就肯定是大招.直接新建两个后缀为 **.reg**的文件，内容分别填充以下内容:
 
 - 第一个.reg文件的内容
   ```
    Windows Registry Editor Version 5.00
    [HKEY_CURRENT_USER\Console\%SystemRoot%_system32_cmd.exe]
    "FaceName"="Lucida Console"
    "InsertMode"=dword:00000000
    "ScreenBufferSize"=dword:001e0078
    "WindowPosition"=dword:004e004e
    "CodePage"=dword:000001b5
   ```
 - 第二个.reg文件的内容
   ```
    Windows Registry Editor Version 5.00
    [HKEY_CURRENT_USER\Console\C:_Python27_python.exe]
    "InsertMode"=dword:00000000
    "CodePage"=dword:000001b5
    "ScreenBufferSize"=dword:001e0078
    "WindowPosition"=dword:001a001a
    "FaceName"="Lucida Console" 
   ```
   填充完成之后,直接双击打开这两个 **.reg**文件.然后,不管弹什么警告都同意.

## vscode
好像前面的**准备工作**中所讲的内容有点多,但这一切都是值得的,接下来我好像听到大家**磨刀霍霍**的声音.

### 打开示例工程
使用vscode以文件夹打开的方式打开示例工程.在这里,我还要说明一下.使用vscode打开示例工程的时候,不需要打开整个ESP-IDF,你只需要打开示例工程即可.

### 配置任务
任务这个概念是vscode中的,不是小编提出来的.小编做为一个九线土锤的24K纯屌丝是搞不出这样的高级货的.那么如何来配置任务呢?
 - <code>Ctrl</code>+<code>Shift</code>+<code>P</code>
 - Tasks:Configure Task
 - 使用模板创建tasks.json文件
 - others
 - 填充参数
	 ```json
	 {
	// See https://go.microsoft.com/fwlink/?LinkId=733558
	// for the documentation about the tasks.json format
	"version": "2.0.0",
	"tasks": [
	{
	"label": "build app",
	"command": "idf.py",
	"type": "shell",
	"args": [
	"build"
	],
	"presentation": {
	"reveal": "always",
	"echo": true
	},
	"problemMatcher": {
	"owner": "cpp",
	"fileLocation": "absolute",
	"pattern": {
	"regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
	"file": 1,
	"line": 2,
	"column": 3,
	"severity": 4,
	"message": 5
	}
	}
	},
	{
	"label": "clean app",
	"command": "idf.py",
	"type": "shell",
	"args": [
	"fullclean"
	],
	"presentation": {
	"reveal": "always",
	},
	},
	{
	"label": "flash app",
	"command": "idf.py",
	"type": "shell",
	"args": [
	"-p","COM3","flash"
	],
	"presentation": {
	"reveal": "always",
	},
	},
	{
	"label": "monitor",
	"type":"shell",
	"windows": {
	"command": "",
	"args": [
	"idf.py",
	"-p",
	"COM3",
	"monitor"
	],
	},
	"presentation": {
	"reveal": "always",
	},
	"problemMatcher": []
	},
	{
	"label": "menuconfig",
	"type":"shell",
	"windows": {
	"command": "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell",
	"args": [
	"idf.py",
	"menuconfig"
	]
	},
	"presentation": {
	"reveal": "always",
	},
	"problemMatcher": []
	}
	]
	}
	 ```
	 **注意**,有可能不同的电脑**powershell路径** && **串口号**也不尽相同,以上是小编的路径
	
 - 详细的操作图示
![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E9%85%8D%E7%BD%AE%E4%BB%BB%E5%8A%A1.gif)

### 配置任务快捷键
虽然我们已经配置任务,可以通过任务来调用编译.但是,每次去点**任务**->**运行任务**->**具体的编译命令**,其实这样也挺烦人的.对于喜欢了IDE的嵌入式的工程师来说,早就习惯了各种快捷键了,那么为了使不是IDE的vscode更像一个更像IDE,接下来我们给这些编译命令增加快捷键.

- <code>Ctrl</code>+<code>Shift</code>+<code>P</code>
- 首选项:打开键盘快捷方式
- 高级自定义请打开和编辑**keybindings.json**
- 填充参数
	```json
	// Place your key bindings in this file to overwrite the defaults
	[
	{
	"key": "f5",
	"command": "workbench.action.tasks.runTask",
	"args": "build app"
	},
	{
	"key": "f6",
	"command": "workbench.action.tasks.runTask",
	"args": "clean app"
	},
	{
	"key": "f7",
	"command": "workbench.action.tasks.runTask",
	"args": "flash app"
	},
	{
	"key": "f8",
	"command": "workbench.action.tasks.runTask",
	"args": "monitor"
	},
	{
	"key": "f12",
	"command": "workbench.action.tasks.runTask",
	"args": "menuconfig"
	}
	]
	```
- 详细的操作图示
![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E9%85%8D%E7%BD%AE%E5%BF%AB%E6%8D%B7%E9%94%AE.gif)

- 快捷键映射表

	| 快捷键  | 执行的编译命令  |
	| ------------ | ------------ |
	| F5  | build app  |
	| F6  | clean app |
	| F7  | flash app  |
	| F8  | monitor  |
	| F12  | menuconfig  |

- [更多的命令](https://esp-idf.readthedocs.io/en/feature-cmake/api-guides/build-system.html#idf-py)

## 效果展示
 - menuconfig
 	  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/Cmake_menuconfig.gif)
	 	
 - fullclean
 	![](https://raw.githubusercontent.com/xiaolongba/picture/master/Cmake_full_clean.gif)
 - build
 	 ![](https://raw.githubusercontent.com/xiaolongba/picture/master/Cmake_build.gif)
 
其他的类似烧录app等这些动作均跟上面的操作一致。
## 最后
至此,就可以愉快地使用快捷键来开发ESP32啦.此文档解决了前面两篇中提到的**乱码**以及**速度过慢**的问题.编译速度已经达到在linux下编译的水准,应该是目前最完美的vscode开发esp32教程了.
