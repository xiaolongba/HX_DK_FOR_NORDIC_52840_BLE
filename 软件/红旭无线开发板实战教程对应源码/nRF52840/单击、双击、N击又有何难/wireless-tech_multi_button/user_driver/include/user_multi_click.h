/**
* @file         user_multi_click.h
* @brief        ������صĺ��������Լ��궨��
* @details      �û�����������ʵ�ֵ���������Լ������Ĵ���
* @author       Helon_Chan
* @par Copyright (c):
*               �������߿����Ŷ�
* @par History:
*               Ver0.0.1:
                    Helon_Chan, 2018/08/19, ��ʼ���汾\n
*/
#ifndef USER_MULTI_CLICK_H
#define USER_MULTI_CLICK_H

/*
===========================
ͷ�ļ�����
=========================== 
*/
#include "app_button.h"
#include "sdk_common.h"
#include "app_timer.h"
#include "user_log.h"
/*
===========================
�궨��
=========================== 
*/
#define BUTTON_COUNTS               1                           ///< ��������
#define BUTTON1                     13                          ///< ������Ӧ�����ź�
#define TIMER_FOR_LONG_PRESSED      5000                        ///< ������ʱ�䣬�򳬹����ʱ������Ϊ�ǳ���������Ĭ��������
/*
===========================
��������
=========================== 
*/
typedef void (*user_multi_click_handler_t)(uint8_t button_no,uint8_t click_counts);

typedef void (*user_long_pressed_handler_t)(uint8_t button_no);

/*
===========================
�ṹ�嶨��
=========================== 
*/
typedef struct
{
  app_button_cfg_t app_button_cfg[BUTTON_COUNTS];
  user_multi_click_handler_t user_multi_click_handler;
  user_long_pressed_handler_t user_long_pressed_handler;
}user_multi_click_t;



/*
===========================
��������
=========================== 
*/


/** 
* ��䰴���ĳ����������Լ�����Ĵ�����
* @param[in]   multi_click_handler    ����䵥��������Ĵ�����
* @param[in]   long_pressed_handler   ����䳤��������
* @param[in]   button_counts          ����������
* @retval      NRF_SUCCESS            ����ʾ��ʼ���ɹ�������ֵ���ʼ��ʧ��
* @note        �޸���־ 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/19, ��ʼ���汾\n 
*/

ret_code_t user_multi_click_init(user_multi_click_handler_t multi_click_handler,user_long_pressed_handler_t long_pressed_handler,uint8_t button_counts);


#endif /* USER_MULTI_CLICK_H */