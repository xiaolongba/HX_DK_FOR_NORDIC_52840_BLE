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
