## 前言

- 硬件连接
   - [OLED模块(I2C接口),点我即可找到购买的地方](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-18402045841.5.378a2c2cVxUhHD&id=569864974646)
   - ESP32开发板
   - ESP32的IO33  -->  OLED的SCL
   - 4.ESP32的IO32  -->  OLED的SDA
   - 不接  -->  OLED的RST   
   - 电源接3.3V

- 代码使用步骤
   - make clean 清除掉之前编译的残留
   - make menuconfig 修改下载程序的串口号
   - make all 编译程序
   - make flash 下载程序

## 效果
![](https://github.com/xiaolongba/picture/blob/master/OLED%E6%95%88%E6%9E%9C%E5%9B%BE.gif)
