/** 
* @file         user_tmall_genie.h 
* @brief        声明接收天猫精灵控制命令以及其他相关的宏定义
* @details      实质上esp32模块最终的命令均来自于贝壳物联的云平台,因为贝壳物联已经跟天猫精灵已经对接好了
* @author       Helon_Chan 
* @par Copyright (c):  
*               红旭无线开发团队
* @par History:          
*               Ver0.0.1:
                    Helon_Chan, 2018/08/12, 初始化版本\n 
*/
#ifndef USER_TMALL_GENIE_H_
#define USER_TMALL_GENIE_H_


/*
===========================
宏定义
=========================== 
*/
#define BIG_IOT_URL                 "www.bigiot.net"
#define BIG_IOT_PORT                "8585"
#define TAG                         "big_iot_cloud_connect"
#define BIG_IOT_CONNECT_SUCCESS     "{\"M\":\"WELCOME TO BIGIOT\"}"
#define BIG_IOT_SIGN_IN             "{\"M\":\"checkin\",\"ID\":\"7130\",\"K\":\"87e3a2638\"}\n"               
#define BIG_IOT_SIGN_IN_MD5         "{\"M\":\"checkin\",\"ID\":\"7130\",\"K\":\"61569d7aee3bdef9c7b83ee0abc73df0\"}\n"    
/*
===========================
函数声明
=========================== 
*/
/** 
* 通过TCP的方式连接贝壳物联的云平台接口
* @param[in]   url：表示贝壳物联的云平台接口地址
* @param[in]   port：表示贝壳物联云平台接口地址的端口
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/12, 初始化版本\n 
*/
void big_iot_cloud_connect(const char *url, const char *port);



#endif /* USER_TMALL_GENIE_H_ */