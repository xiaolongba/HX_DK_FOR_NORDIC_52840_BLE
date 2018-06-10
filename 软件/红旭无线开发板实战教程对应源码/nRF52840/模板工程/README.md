# 前言
这个是红旭无线开发板的nRF52840的模板工程源码,该源码删除了官方工程中大量的内容,只保留了维持这个工程模版编译不报错的最小系统所需要的文件.

# 如何使用
那么如何来使用这个源码,用于以后在此工程模板上添加自己的用户程序呢?我想任何一个有想法的嵌入式工程师都不喜欢在官方SDK提供的工程模版上开发自己的应用吧?
更多的人更愿意用自己的空白模板工程创建自己的不同应用吧.**Here we go!**
- 在nRF52840的SDK包的根目录下创建一个文件夹,也就是你存放你应用工程的文件夹(笔者这里命名为**template_project**)
- 将**模板工程**中的所有内容复制到**template_project**这个文件夹,复制后最终的内容如下图所示:

  ![最终的内容](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%9C%80%E7%BB%88%E7%9A%84%E5%86%85%E5%AE%B9.png)

- 打开<code>SEGGER Embedded Studio for ARM</code>-><code>Open Solution</code>-><code>选择刚刚复制的源码中的SEGGER Embedded Studio工程文件</code>;

  ![打开刚复制的工程文件](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%89%93%E5%BC%80%E6%96%B0%E5%BB%BA%E7%9A%84%E5%B7%A5%E7%A8%8B.gif)

- 设置自己SDK包的路径宏,然后再设置**core_cm4.h**的路径,这样在编译模板工程的时候才不会出现找不到**core_cm4.h**;

  - 设置SDK包路径宏
    ```
    nRF52840_SDK_DIR=C:\Users\Helon\Desktop\nRF5_SDK_15.0.0_a53641a
    ```
    ![添加sdk路径宏](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E8%B7%AF%E5%BE%84%E5%AE%8F.gif)

  - 设置**core_cm4.h**的路径
    ```
    $(nRF52840_SDK_DIR)/components/toolchain/cmsis/include
    ```
    ![添加头文件路径](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E5%A4%B4%E6%96%87%E4%BB%B6%E8%B7%AF%E5%BE%84.gif)

经过上面的设置,你就可以编译通过模板工程了.

![编译模板工程](https://raw.githubusercontent.com/xiaolongba/picture/master/%E7%BC%96%E8%AF%91%E6%A8%A1%E6%9D%BF%E5%B7%A5%E7%A8%8B.gif)

# 最后
如何在使用上有什么问题,欢迎提Issues或者到[红旭对应的无线技术论坛](http://bbs.wireless-tech.cn/forum.php)提问.
