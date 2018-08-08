## 前言
* ESP32硬件I2C驱动SHT30温湿度模块
* 作者：红旭无线开发团队  QQ群：671139854
* 版本：Ver0.0.1  2018/08/08

* 硬件连接
    * 1.[SHT30模块（I2C接口）](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-18402045841.2.378a2c2cZMcFL8&id=569636756628)
    * 2.ESP32开发板
    * 3.ESP32的IO33  -->  SHT30的SCL
    * 4.ESP32的IO32  -->  SHT30的SDA
    * 5.SHT30的RST，暂时不接  
    * 6.电源接3.3V

* 代码使用步骤
    * 1.make clean 清除掉之前编译的残留
    * 2.make menuconfig 修改下载程序的串口号
    * 3.make all 编译程序
    * 4.make flash 下载程序
