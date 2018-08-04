## 前言
> 自从小编在网上发布了[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)这篇文章之后,收到诸多网友的赞评和意见.借此机会,感谢网友们给小编提出宝贵的意见,促进完善该序列的文档.鉴于大家反馈的信息,小编总结并完善了一些内容,故发布了这次的修订篇章节.

## 速度
这也是很多网友吐槽最多的一个G点,什么?你说为啥?因为触发了G点很容易高潮.由于历史原因Windows10之前,windows是没有类UNIX模拟环境的.如果想要使用类UNIX模拟环境就要利用第三方类UNIX模拟环境,例如**msys32**或者**cygwin**.正因为这些原因导致在windows下编译ESP32比在纯linux系统下编译慢很多很多.以下是小编在Windows和Linux下所测试得到的数据.

- 测试电脑的配置

  ![电脑的配置](https://raw.githubusercontent.com/xiaolongba/picture/master/%E7%94%B5%E8%84%91%E9%85%8D%E7%BD%AE.png)

- Windows 7 64bit

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E4%BC%98%E5%8C%96%E5%89%8D.png)

- Linux ubuntu 32bit

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/Screenshot_2018-08-02-22-30-15-228_Clock.png)

由此可以看出这其中的差距还是很大的.远的不说,就目前我们国内的技术氛围,决逼受不了这样的速度.**因为,在公司眼里在项目经理眼中,越快越好才是王道,最好是我代码一写完,就意味着编译完了!!!**

### 减少编译时间
刚开始我在写[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)这篇文章时,我并没有太在意这个编译速度.因为我觉得在一个linux下的产物,你放在windows下编译慢这是理所当然的(**万恶的理所当然,以后再也不这样了**).但是,在不断有网友向我反馈这个问题的时候,我就在反问自己"**真的是理所当然吗?**".显然,这并不是理所当然.通过我两天探索以及参考网上的网友言论,最后通过实验证明.起码是有方法加快编译速度的,那么应该如何来做呢?

- 并行编译
玩过linux的都知道,在linux环境下使用**make**命令时是可以指定PC的CPU处理器个数,即
  ```
  make -jN  ///< 其中N就是你自身电脑的CPU逻辑处理器个数
  ```
  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/CPU%E5%A4%84%E7%90%86%E5%99%A8.png)

 同理,在编译ESP32时我们也可以这样 **(乐鑫原生态的ESP-IDF是没有指定CPU逻辑处理器的)**即
 
   ```
   make -j4 app
   ```
 
  ![优化前](https://raw.githubusercontent.com/xiaolongba/picture/master/%E4%BC%98%E5%8C%96%E5%89%8D.png)
 
  ![优化后](https://raw.githubusercontent.com/xiaolongba/picture/master/%E4%BC%98%E5%8C%96%E5%90%8E.png) 
 
 ## 乱码
 看过我写的[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)这篇文章的读者就知道,在执行**make menuconfig**时弹出来的对话框会是乱码.在一次偶然的机会,我在尝试**Bash on Ubuntu on Windows 10**时发现,在执行**make menuconfig**命令时,居然不会乱码!!!!这样的话,事情就简单多了,还是一样的配法(参考[如何搭建ESP32开发环境](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md)-->如何使用-->第四小点).
 ```
 "terminal.integrated.shell.windows": "C:\\Windows\\System32\\bash.exe "
 ```
 至于,如何在win10上使用vscode来调用Bash on Ubuntu on Windows 10,小编会专门出一篇文章说明,这里篇幅有限就暂时先不讲.
 
 ## 代码补全
 这也是很多网友反馈说,在vscode上发现对一些结构体的成员变量的代码提示功能使用或者提示的内容是不对的.其实,这里的主要原因还是vscode它找不到你的头文件路径在哪里,官方也有详细的说明即
 - [vscode官方文档](https://code.visualstudio.com/docs/languages/cpp)--> **Configuring IntelliSense**根据黄色小灯泡的提示添加头文件路径即可
 
 - 如果遇到增加了头文件中径之后,还是找不到**stdio.h**类似于这些标准的C头文件时.此时,你将找不到的头文件名字在你的编译工具链的根目录下全局搜索,直至找到这个头文件的绝对路径并手动添加至vscode的**c_cpp_properties.json**即可
 
为什么要这样做呢?有人可能会说vscode不可以跟keil那样递归查找头文件吗?**答案是:可以的,但是你要失去vscode强大的代码提示功能**.但是,我们用vscode就是看中它代码补全的强大功能.因此,这种递归的方式小编也就不讲了.更多的详情可以参考[vscode官方文档](https://code.visualstudio.com/docs/languages/cpp)
 
## 总结
网友们反馈的问题,我基本上都给出了解决方案了.后续如果有更佳的方法我也会出文档说明.当然,我也希望更多的人参与进来完善它.
