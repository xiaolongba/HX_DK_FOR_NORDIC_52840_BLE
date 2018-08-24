# 红旭无线开发板实战教程对应源码目录资料说明
该目录主要是存放红旭无线开发板的实战对应的源码,由以下几个部分组成:
## ESP32
### 入门基础篇

- [创建一个WIFI热点](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BE%EF%BC%9A%E5%A6%82%E4%BD%95%E5%88%9B%E5%BB%BA%E8%87%AA%E5%B7%B1%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E7%83%AD%E7%82%B9/app)

  讲解了如何使用模板工程创建自己的第一个ESP32热点

- [按键操作之单击/长按/多击](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%BA%8C%E8%AF%BE%EF%BC%9A%E6%8C%89%E9%94%AE%E5%8D%95%E5%87%BB%E4%BB%A5%E5%8F%8A%E5%A4%9A%E5%87%BB%E7%9A%84%E5%AE%9E%E7%8E%B0/app)

  讲解了如何在ESP32上利用队列/定时器/GPIO口中断实现多个按键的单击/双击/多击功能

- [PWM彩灯](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/PWM%E5%BD%A9%E7%81%AF)

  讲解了如何使用ESP32的PWM去驱动红旭无线Mini开发板的RGB灯

- [深入了解ESP32的UART](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E6%B7%B1%E5%85%A5%E4%BA%86%E8%A7%A3ESP32%E7%9A%84UART)
  
  讲解了如何使用ESP32的UART

- [如何使用ESP32驱动SHT30](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8ESP32%E9%A9%B1%E5%8A%A8SHT30)

  讲解了如何使用ESP32的I2C去驱动SHT30传感器

- [如何使用ESP32驱动OLED屏](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8ESP32%E9%A9%B1%E5%8A%A8OLED%E5%B1%8F)

  讲解了如何使用ESP32的I2C去驱动OLED屏

### 基础应用篇

- [ESP32如何建立TCP长连接](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E5%A6%82%E4%BD%95%E5%BB%BA%E7%AB%8BTCP%E9%95%BF%E8%BF%9E%E6%8E%A5)
  
  讲解了如何使用ESP32建立tcp server和client，让ESP32和手机/进行数据交互

- ESP32之UDP单播/广播   

- ESP32之MQTT通讯   

- 如何基于ESP32实现WEB_SOCKET的功能

- ESP32如何解析JSON数据 

- ESP32如何创建SSL/TLS连接

- 如何利用第三方库加解密通讯数据

- 如何实现空中升级功能

- [ESP32如何使用SmartConfig快配](https://github.com/double2243/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/SmartConfig%E5%BF%AB%E9%85%8D)
  
  讲解了如何使用SmartConfig给ESP32快配SSID和密码，让其连接云服务器获取本地天气

### 中级应用篇    
- [ESP32如何利用mbedtls获取天气预报](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%89%E8%AF%BE%EF%BC%9A%E5%88%A9%E7%94%A8mbedtls%E8%8E%B7%E5%8F%96%E5%A4%A9%E6%B0%94%E9%A2%84%E6%8A%A5/app)   
   
  讲解了如何在ESP32上利用mbedtls/按键/呼吸灯实现天气预报的功能   

- 基于ESP32的实现wifi插座的功能  

- 基于ESP32的实现MP3功能   
     
### 高级应用篇
- 基于百度DuerOS实现类似天猫精灵的AI音箱功能   
  
## nRF52840
### 入门基础篇

- [Nordic 52840基础教程第一课:Hello World](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/Nordic%2052840%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BEHello%20World)

  讲解了如何使用模板工程创建自己的第一个**Hello World**工程,并介绍了通过**UART**以及**RTT**打印输出Hello World信息

- [PWM 点灯,我是专业的](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/PWM%20%E7%82%B9%E7%81%AF%2C%E6%88%91%E6%98%AF%E4%B8%93%E4%B8%9A%E7%9A%84)

  讲解了如何使用硬件定时器/RTC/硬件PWM产生PWM波形

- 单击,双击,N 击又有何难?

- 小阶段总结

- 什么是 PPI，它能干什么?

- 如何使用硬件定时及计数器

- 脉冲宽度很难测?红旭可不怕

- 不一样的 ADC 采集

### 基础应用篇
- BLE 基础知识

- 如何使用 nRF52840 搭建您的第一个蓝牙外设

- 自定义一个简单的 Profile

- 依葫芦画瓢自定义一个完整的 Profile

- 串口无线透传,我也行

- 配对和绑定,也就那么一回事

- 热启动 VS 冷启动,数据如何保存?

- 不同的广播类型,我应如何决择?

- 牛刀小试 Becaon

- 空中升级(OTA)

- 一直都是被动,如何主动出击?

- 平时都是别人连我,这次轮到我了

- 如何实现一个主机连接 20 个从机

- 主从一体,就是 6

- 蓝牙 5.0 新特性之 2 倍速度

- 蓝牙 5.0 新特性之 4 倍距离

- 蓝牙 5.0 新特性之 8 倍容量

- 功耗问题应如何处理

### 中级应用篇
- SIG Mesh 的基础知识

- 如何入 SIG Mesh 网络

- SIG Mesh 网络之代理节点

- SIG Mesh 网络之普通节点

- SIG Mesh 网络之低功耗节点

- SIG Mesh 网络之朋友节点

- SIG Mesh 网络之中继节点

- SIG Mesh 角色如何切换

- [SIG Mesh 之点灯应用](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/nRF52840/%E5%9F%BA%E4%BA%8EGeneric%20OnOff%20Model%E7%9A%84Mesh%E7%82%B9%E7%81%AF%E5%BA%94%E7%94%A8)  

  主要是讲解如何通过Nordic官方的Mesh SDK包,创建一个标准的Generic OnOff模型

### 高级应用篇
- 基于天猫精灵的 MESH 应用

- 基于物联网区块链的 MESH 应用

- WIFI 以及 SIG MESH 共存的智能家居应用

- 使用 BLE 点亮 ZIBEE 灯泡,照亮你的美,温暖你的心

- BLE/ZIGBEE/WIFI 三合一,创造无限可能


## nRF52840之Zigbee
### 入门基础应用篇
- 认识ZigBee及网络结构

- IEEE 802.15.4规范

- ZigBee帧结构

- 介绍簇、命令、属性、设备ID、端点等联系

- 了解ZigBee3.0的标准规范

- 讲述网络间的参数及其用途

- 如何进行网络分析及抓包器的使用

- ZigBee3.0网络安全分析

### 基础应用篇

- 如何使用nRF52840创建一个简单的标准工程

- ZigBee3.0之BDB过程

- ZigBee3.0之F&B

- ZigBee3.0之install code

- ZigBee3.0之ZLL

- ZigBee3.0之ZCL互操作

- ZigBee3.0之OTA过程

- ZigBee3.0之低功耗

- ZigBee3.0之属性上报

### 中级应用篇

- 地址表/路由表/关联设备表/子设备表/绑定表的作用及区别

- ZigBee3.0之GP

- ZigBee3.0之Aging

- 终端poll rate

- ZigBee3.0之情景面板的识别
  

# 红旭无线开发板实战教程对应源码的变量/文件命名/注释的约定俗称
老话说得好 **"无规矩不成方圆"**,我相信有很多初入门的新手甚至一些老手都不太注重这些.反正,代码老子会写就行了我怎么爽就怎么写,功能还不是跑得很6.其实,对于新人大家都还可以理解,毕竟 **"初出牛犊不怕虎"** 嘛.但是,一些老手还这么想我就很不能理解了.我就不信你过段时间再回过头去看你之前的代码你能马上很清楚其中的逻辑,如果要是你离职跑路了接手你工作的人八成是要倒霉了.在这里红旭号召大家秉承 **"一人栽树,后人乘凉"** 的原则,写出来的代码还是要遵守一定的规则,不然全乱套了.红旭做为无线开发板的施道者,必须摒弃乱七8糟的命名等不良的习惯.接下来,小编将说说红旭无线的源码的一些约定俗称.

## 规则
### 点h文件&点C文件
红旭所有的.h以及.c文件均会在文件的最前面写有一个大注释,用于说明这个点h以及点c文件声明或者定义了哪些内容,主要的功能是用来干什么的.
- 红旭点c文件最上面的注释

  大家根据自己的实际情况更改相对应的内容
  ```c
  /** 
  * @file         user_app.c
  * @brief        用户实现自己功能相关函数定义
  * @details      定义用户所需的结构体变量以及局部全局变量定义
  * @author       Helon_Chan 
  * @par Copyright (c):  
  *               红旭无线开发团队
  * @par History:          
  *               Ver0.0.1:
                       Helon_Chan, 2018/06/19, 初始化版本\n 
  */
  ```
  
- 红旭点h文件最上面的注释
  
  大家根据自己的实际情况更改相对应的内容
  ```c
  /** 
  * @file         user_app.h 
  * @brief        用户实现自己功能相关声明
  * @details      声明用户所需的结构体或者宏定义,以及函数声明
  * @author       Helon_Chan 
  * @par Copyright (c):  
  *               红旭无线开发团队
  * @par History:          
  *               Ver0.0.1:
                       Helon_Chan, 2018/06/19, 初始化版本\n 
  */
  #ifndef USER_APP_H_
  #define USER_APP_H_



  #endif/* USER_APP_H_ */
  ```
- 头文件包含&函数定义&宏定义&全局变量定义

  以下注释的内容主要用在点C或者点h文件中需要定义变量或者函数以及头文件包含时,可以起来分隔的作用.让阅读代码的人知道这一部分是干什么的.

  ```c
  /*
  ===========================
  头文件包含
  =========================== 
  */
  ```

  ```c
  /*
  ===========================
  函数定义
  =========================== 
  */
  ```

  ```c
  /*
  ===========================
  宏定义
  =========================== 
  */
  ```

  ```c
  /*
  ===========================
  全局变量定义
  =========================== 
  */
  ```
  
- 函数声明以及定义的注泽

  大家根据自己的实际情况进行修改对应的内容,红旭的函数声明和定义注释以下所示:
  
   ```c
    /** 
   * 按键初始化
   * @param[in]   p_key_config        :不同按键的参数的配置
   * @param[in]   key_counts          :按键的个数
   * @param[in]   decoune_timer       :消抖的时长,单位是ms
   * @param[in]   long_pressed_cb     :长按时的回调处理函数
   * @param[in]   short_pressed_cb    :短按以及多击的回调处理函数
   * @retval      -1                  :按键参数的配置为空
   *              -2                  :短按的回调处理函数为空,但是长按的回调可以为空,因为有的按键并不需要长按功能
   *              -3                  :按键的个数为0
   * @note        修改日志 
   *               Ver0.0.1:
                       Helon_Chan, 2018/06/16, 初始化版本\n 
   */
  int32_t user_key_init(key_config_t *p_key_config,
                        uint8_t key_counts,
                        uint16_t decoune_timer,
                        user_key_function_callback_t long_pressed_cb,
                        user_key_function_callback_t short_pressed_cb);
   ```


### 变量
红旭所有变量的命名均是小写加横杆的方式组成.

- 全局静态变量
  - 普通变量
    ```c
    uint8_t gs_value;
    ```
  - 指针变量
    ```c
    uint8_t gs_p_value;
    ```
  - 结构体变量
    ```c
    struct test gs_m_value;
    ```
  - 结构体指针变量
    ```c
    struct test gs_m_p_value;
    ```
  - 枚举变量
    ```c
    enum test gs_em_value;
    ```
  - 共同体/联合体变量
    ```c
    union test gs_un_value;
    ```
    
 - 全局变量 
    - 普通变量
      ```c
      uint8_t g_value;
      ```
    - 指针变量
      ```c
      uint8_t g_p_value;
      ```
    - 结构体变量
      ```c
      struct test g_m_value;
      ```
    - 结构体指针变量
      ```c
      struct test g_m_p_value;
      ```
    - 枚举变量
      ```c
      enum test g_em_value;
      ```
    - 共同体/联合体变量
      ```c
      union test g_un_value;
      ```
        
- 局部静态变量&局部变量
  - 普通变量
    ```c
    uint8_t s_value;
    ```
  - 指针变量
    ```c
    uint8_t s_p_value;
    ```
  - 结构体变量
    ```c
    struct test s_m_value;
    ```
  - 结构体指针变量
    ```c
    struct test s_m_p_value;
    ```
  - 枚举变量
    ```c
    enum test s_em_value;
    ```
  - 共同体/联合体变量
    ```c
    union test s_un_value;
    ```
    
- 形参变量
  - 普通变量&结构体变量
    ```c
    uint8_t value;
    struct test m_value;      
    ```
  - 指针变量&结构体指针变量
    ```c
    uint8_t p_value;
    struct test m_p_value;
    ```       
  - 枚举变量
    ```c
    enum test em_value;
    ```
  - 共同体/联合体变量
    ```c
    union test un_value;
    ```  
### 别名
  使用typedef定义了一些结构体或者函数别名,命名规则如下:
  
  - 结构体
  
  ```c
    typedef struct test
    {
      变量1;
      变量2;
    }test_t    
  ```  
    
  - 函数
  
  ```c
    typedef void (*test_func_t)(void*,void*);
  ``` 
    
  - 共同体/联合体
  
  ```c
    typedef union test
    {
      变量1;
      变量2;
    }test_u  
  ``` 
