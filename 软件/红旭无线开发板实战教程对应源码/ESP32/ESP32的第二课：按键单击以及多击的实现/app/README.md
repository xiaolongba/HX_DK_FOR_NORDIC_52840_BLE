# 前言
> 这个是红旭无线开发板的第二课教程 **(ESP32的第二课：按键单击/双击/多击的实现)** 所对应的源码,主要是实现了按键单击/双击/多击的功能.
# 如何使用
用户只需要将 **app**这个文件夹复制至esp32 sdk的根目录下即可,无须做任何更改.但是,有一点还是需要注意一下;
- 如果在编译的过程中出现编译错误,只需要<cdoe>make app-clean</code>即可.出现这种情况的可能是因为编译的时候遗留了一些文件,而这些文件由于不同人把sdk存放的目录不同而不同
- 只需要在<cdoe>main</code>.c文件中包含<cdoe>#include "user_app.h"</code>.同时,在<cdoe>main函数</code>中调用<cdoe>user_app_key_init</code>即可在红旭无线开发板上实现单击/双击/多击的功能

# 最后
如何在使用上有什么问题,欢迎提Issues或者到[红旭对应的无线技术论坛](http://bbs.wireless-tech.cn/forum.php)提问.
