# 前言
这是红旭无线开发板的nRF52840第一课 **(Nordic 52840的第一课Hello World)** 源码,该源码是基于[模板工程](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/%E6%A8%A1%E6%9D%BF%E5%B7%A5%E7%A8%8B)的基础上添加的应用程序.

# 如何使用
下载了源码直接用 **SEGGER Embedded Studio for ARM** 打开并编译是没有用的,这个有点嵌入式开发常识的人都知道绝逼会报错的.那么应该如何使用呢?其实,
在[模板工程源码使用说明]()中就已经讲到了.

- 在nRF52840的SDK包的根目录下创建一个文件夹,也就是你存放你应用工程的文件夹(笔者这里命名为 **template_project** ),并将源码中的所有内容复制到template_project这个文件夹
- 设置SDK包路径宏

  <code>在SES的项目浏览中选中整个工程并右击</code>-><code>Edit Options...</code>-><code>Common</code>-><code>Build</code>-><code>Project Macros</code>
  ,在打开**Project Macros**的设置中,添加SDK开发包的路径宏(小编的SDK包实际路径如下所示);

  ```
  nRF52840_SDK_DIR=D:/Project/wireless_tech/wireless_tech_template
  ```
  ![添加sdk路径宏](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E8%B7%AF%E5%BE%84%E5%AE%8F.gif)

- 设置头文件路径,其实源码工程中都已经设置好了.如果出现找不到头文件的话,就再将头文件路径设置进去就行了 **(出现这种情况的可能就是官方的SDK包目录有变更导致找不到头文件)**.

  <code>在SES的项目浏览中选中整个工程并右击</code>-><code>Edit Options...</code>-><code>Common</code>-><code>Preprocessor</code>-><code>User Include Directories</code>,
在**User Include Directories**添加头文件路径;
![添加头文件路径](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E5%A4%B4%E6%96%87%E4%BB%B6%E8%B7%AF%E5%BE%84.gif)

  ```
  $(nRF52840_SDK_DIR)/components/toolchain/cmsis/include
  $(nRF52840_SDK_DIR)/components/libraries/experimental_log
  $(nRF52840_SDK_DIR)/components/libraries/util
  $(nRF52840_SDK_DIR)/template_project/config
  $(nRF52840_SDK_DIR)/modules/nrfx/mdk
  $(nRF52840_SDK_DIR)/components/softdevice/s140/headers
  $(nRF52840_SDK_DIR)/components/libraries/experimental_section_vars
  $(nRF52840_SDK_DIR)/components/libraries/strerror
  $(nRF52840_SDK_DIR)/components/libraries/experimental_log/src
  $(nRF52840_SDK_DIR)/components/libraries/experimental_memobj
  $(nRF52840_SDK_DIR)\components\libraries\balloc
  $(nRF52840_SDK_DIR)\template_project\user_driver\include
  $(nRF52840_SDK_DIR)\external\fprintf
  $(nRF52840_SDK_DIR)\integration\nrfx\legacy
  $(nRF52840_SDK_DIR)\modules\nrfx
  $(nRF52840_SDK_DIR)\integration\nrfx
  $(nRF52840_SDK_DIR)\modules\nrfx\drivers\include
  $(nRF52840_SDK_DIR)\components\libraries\atomic
  $(nRF52840_SDK_DIR)\components\libraries\delay
  $(nRF52840_SDK_DIR)\external\segger_rtt

  ```

- 如果按下<code>F5</code>进行编译下载时,出现找不到协议栈路径时,直接指定自己的协议栈绝对路径即可.当然,你也可以使用SDK包路径宏来指定.至于如何设置这个路径
,[Nordic 52840的第一课Hello World](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/nRF52840/Nordic%2052840%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BEHello%20World.md)文字教程中的 **<编译并下载>** 这一章节有讲.

  <code>在SES的项目浏览中选中整个工程并右击</code>-><code>Edit Options...</code>-><code>Common</code>-><code>Debug</code>-><code>Loader</code>-><code>Additional Load File[0]</code>,在打开的设置中添加协议的绝对路径(以下是小编的协议栈实际路径).

  ```
  $(nRF52840_SDK_DIR)/components/softdevice/s140/hex/s140_nrf52_6.0.0_softdevice.hex
  ```
  ![添加协议栈路径](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E5%8D%8F%E8%AE%AE%E6%A0%88%E8%B7%AF%E5%BE%84.gif)
  
  
# 最后
如何在使用上有什么问题,欢迎提Issues或者到[红旭对应的无线技术论坛](http://bbs.wireless-tech.cn/forum.php)提问.
