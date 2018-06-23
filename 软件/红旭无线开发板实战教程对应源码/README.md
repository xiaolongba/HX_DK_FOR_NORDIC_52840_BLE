# 红旭无线开发板实战教程对应源码目录资料说明
该目录主要是存放红旭无线开发板的实战对应的源码,由以下两部分组成:
- ESP32
    
  - [ESP32的第一课:如何创建自己的第一个热点](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BE%EF%BC%9A%E5%A6%82%E4%BD%95%E5%88%9B%E5%BB%BA%E8%87%AA%E5%B7%B1%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E7%83%AD%E7%82%B9/app)
  - [ESP32的第二课:按键单击\长按\多击的实现](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%BA%8C%E8%AF%BE%EF%BC%9A%E6%8C%89%E9%94%AE%E5%8D%95%E5%87%BB%E4%BB%A5%E5%8F%8A%E5%A4%9A%E5%87%BB%E7%9A%84%E5%AE%9E%E7%8E%B0/app)
- nRF52840
  - [nRF52840模板工程](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/%E6%A8%A1%E6%9D%BF%E5%B7%A5%E7%A8%8B)
  - [Nordic 52840的第一课Hello World](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Nordic%2052840%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BEHello%20World)


# 红旭无线开发板实战教程对应源码的变量/文件命名/注释的约定俗称
老话说得好 **"无规矩不成方圆"**,我相信有很多初入门的新手甚至一些老手都不太注重这些.反正,代码老子会写就行了我怎么爽就怎么写,功能还不是跑得很6.其实,对于新人大家都还可以理解,毕竟 **"初出牛犊不怕虎"** 嘛.但是,一些老手还这么想我就很不能理解了.我就不信你过段时间再回过头去看你之前的代码你能马上很清楚其中的逻辑,如果要是你离职跑路了接手你工作的人八成是要倒霉了.在这里红旭号召大家秉承 **"一人栽树,后人乘凉"** 的原则,写出来的代码还是有遵守一定的规则,不然全乱套了.红旭做为无线开发板的施道者,首当其冲,必须摒弃乱七8糟的命名等不良的习惯.接下来,小编将说说红旭无线的源码的一些约定俗称.
