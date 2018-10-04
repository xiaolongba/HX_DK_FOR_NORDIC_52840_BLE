/**
* @file         user_application.h
* @brief        按键相关函数的声明以及宏定义
* @author       Helon_Chan
* @par Copyright (c):
*               红旭无线开发团队
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/09/18, 初始化版本\n
*/
#ifndef USER_APPLICATION_H
#define USER_APPLICATION_H


/*
===========================
头文件包含
=========================== 
*/
#include "user_log.h"
#include "user_multi_click.h"

/*
===========================
函数声明
=========================== 
*/

/**
 * 用户应用初始化函数
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *              Ver0.0.1:
                  Helon_Chan, 2018/08/19, 初始化版本\n
 */
void user_application_init(void);


#endif  /* USER_APPLICATION_H */