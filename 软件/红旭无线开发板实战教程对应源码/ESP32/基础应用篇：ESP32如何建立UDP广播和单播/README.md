/*
* ESP32搭建udp client的广播（用途多）和单播（用途较少）
* 作者：红旭无线开发团队，QQ群：671139854
* 版本：Ver0.0.2，2018/08/24


* 代码使用步骤：
    * 3.修改STA的账号密码，依据UDP单播还是广播，修改IP和端口
    * 4.make clean 清除掉之前编译的残留
    * 5.make menuconfig 修改下载程序的串口号
    * 6.make all 编译程序
    * 7.make flash 下载程序。本人喜欢把6、7步合二为一 make all flash monitor，顺便打开串口
    * 8.作为client时，需要使用手机或者电脑使用助手工具打开UDP监听，让esp32自动连接
    
* 待完善
    * 无
    
* 结果
    * 1.UDP丢包数5%~10%，看网络情况

