/** 
* @file         user_tmall_genie.c
* @brief        定义接收以及处理天猫精灵命令的相关函数
* @details      获取得到天猫精灵的控制命令并控制
* @author       Helon_Chan 
* @par Copyright (c):  
*               红旭无线开发团队
* @par History:          
*               Ver0.0.1:
                     Helon_Chan, 2018/08/12, 初始化版本\n 
*/

/*
===========================
头文件包含
=========================== 
*/
#include "mbedtls/platform.h"
#include "mbedtls/net.h"
#include "mbedtls/debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include "mbedtls/certs.h"
#include "cJSON.h"
#include "user_tmall_genie.h"
#include "esp_log.h"
#include "os.h"
#include "esp_wifi.h"

#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
/*
===========================
全局变量定义
=========================== 
*/
typedef struct
{
  mbedtls_net_context *net_ctx;
  mbedtls_entropy_context *entropy;
  mbedtls_ctr_drbg_context *ctr_drbg;
  mbedtls_ssl_context *ssl_ctx;
  mbedtls_ssl_config *ssl_conf;
}tcp_ssl_connect_t;

tcp_ssl_connect_t tcp_ssl_connect =
{
  .net_ctx  = NULL,
  .entropy  = NULL,
  .ctr_drbg = NULL,
  .ssl_ctx  = NULL,
  .ssl_conf = NULL,
};
/* 存放接收到GET请求的数据 */
static uint8_t  gs_recv_buff[1024*2];
/*
===========================
函数定义
=========================== 
*/

/** 
* tcp+ssl连接的相关参数清空
* @param[in]   null
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/12, 初始化版本\n 
*/
static void tcp_ssl_parameters_clean(void)
{  
  mbedtls_ssl_close_notify(tcp_ssl_connect.ssl_ctx);
  mbedtls_net_free(tcp_ssl_connect.net_ctx);
  
  mbedtls_ssl_free(tcp_ssl_connect.ssl_ctx);
  mbedtls_ssl_config_free(tcp_ssl_connect.ssl_conf);
  mbedtls_ctr_drbg_free(tcp_ssl_connect.ctr_drbg);
  mbedtls_entropy_free(tcp_ssl_connect.entropy);

  os_free(tcp_ssl_connect.ssl_ctx);
  os_free(tcp_ssl_connect.net_ctx);
  os_free(tcp_ssl_connect.ctr_drbg);
  
  os_free(tcp_ssl_connect.entropy);
  os_free(tcp_ssl_connect.ssl_conf);
}
/** 
* 向云平台服务器发送数据
* @param[in]   p_json_data:需要发送给云平台的数据,json的数据格式
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/12, 初始化版本\n 
*/
static void tcp_ssl_write(const char *p_json_data)
{
  int ret, len;    
  while ((ret = mbedtls_ssl_write(tcp_ssl_connect.ssl_ctx, (unsigned char*)personal_info, strlen(personal_info))) <= 0)
  {
    if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE)
    {
      ESP_LOGI(TAG, " failed\n  ! mbedtls_ssl_write returned %d\n\n", ret);
      return;
    }
  }
  len = ret;
  ESP_LOGI("tcp_ssl_write", " %d bytes written\n\n%s", len, (char *)p_json_data);  
}
/** 
* 连接云平台成功之后,进行设备登录
* @param[in]   personal_info：云平台提供的用户以及设备相关的登录信息
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/12, 初始化版本\n 
*/
static void get_token_from_big_iot_cloud(const char *device_info)
{ 
  tcp_ssl_write(personal_info); 
}

/** 
 * tcp连接任务处理函数
 * @param[in]   pvParameters: 表示任务所携带的参数 
 * @retval      null 
 *              其他:          失败 
 * @par         修改日志 
 *               Ver0.0.1:
                    Helon_Chan, 2018/08/12, 初始化版本\n 
 */
static void tcp_receive_task(void *pvParameters)
{
  int ret, len;
  do
  {
    len = sizeof(gs_recv_buff) - 1;
    memset(gs_recv_buff, 0, sizeof(gs_recv_buff));
    ret = mbedtls_ssl_read(tcp_ssl_connect.ssl_ctx, gs_recv_buff, len);
    if (ret == MBEDTLS_ERR_SSL_WANT_READ || ret == MBEDTLS_ERR_SSL_WANT_WRITE)
    {
      continue;
    }

    if (ret == MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY)
    {
      ESP_LOGI(TAG, "MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY\n");
      ret = 0;
      tcp_ssl_parameters_clean();
      break;
    }

    if (ret < 0)
    {
      ESP_LOGI(TAG, "failed\n  ! mbedtls_ssl_read returned %d\n\n", ret);
      
    }
    if (ret == 0)
    {
      ESP_LOGI(TAG, "\n\nEOF\n\n");      
    }
    else
    {
      len = ret;
      ESP_LOGI(TAG, " %d bytes read\n\n%s", len, gs_recv_buff);
      if (strncmp((char *)gs_recv_buff, BIG_IOT_CONNECT_SUCCESS, 25) == 0)
      {
        ESP_LOGI(TAG, "big_iot_connect success\n");   
        
        // big_iot_cloud_sign(BIG_IOT_SIGN_IN);
      }
    }
  } while (1);
  vTaskDelete(NULL);
}


/** 
* 通过TCP的方式连接贝壳物联的云平台接口
* @param[in]   url：表示贝壳物联的云平台接口地址
* @param[in]   port：表示贝壳物联云平台接口地址的端口
* @retval      null
* @note        修改日志 
*               Ver0.0.1: 
                  Helon_Chan, 2018/08/12, 初始化版本\n 
*/
void big_iot_cloud_connect(const char *url, const char *port)
{
  int ret, len;
  tcp_ssl_connect.net_ctx = (mbedtls_net_context *)os_malloc(sizeof(mbedtls_net_context));  
  tcp_ssl_connect.entropy = (mbedtls_entropy_context *)os_malloc(sizeof(mbedtls_entropy_context));
  tcp_ssl_connect.ctr_drbg = (mbedtls_ctr_drbg_context *)os_malloc(sizeof(mbedtls_ctr_drbg_context));
  tcp_ssl_connect.ssl_ctx = (mbedtls_ssl_context *)os_malloc(sizeof(mbedtls_ssl_context));
  tcp_ssl_connect.ssl_conf = (mbedtls_ssl_config *)os_malloc(sizeof(mbedtls_ssl_config));
/*
  * 0. Initialize the RNG and the session data
*/
  mbedtls_net_init(tcp_ssl_connect.net_ctx);
  mbedtls_ssl_init(tcp_ssl_connect.ssl_ctx);
  mbedtls_ssl_config_init(tcp_ssl_connect.ssl_conf);  
  mbedtls_ctr_drbg_init(tcp_ssl_connect.ctr_drbg);

/*
  * 1. Initialize the RNG and the session data
*/
  ESP_LOGI(TAG, "\n  . Seeding the random number generator...");

  mbedtls_entropy_init(tcp_ssl_connect.entropy);
  if ((ret = mbedtls_ctr_drbg_seed(tcp_ssl_connect.ctr_drbg, mbedtls_entropy_func, tcp_ssl_connect.entropy,
                                   (const unsigned char *)NULL,
                                   0)) != 0)
  {
    ESP_LOGI(TAG, "failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret);
    tcp_ssl_parameters_clean();
    return;
  }

  ESP_LOGI(TAG, " ok\n");
  

/*
  * 2. Start the connection
  * 进行TCP连接
*/
  ESP_LOGI(TAG, "  . Connecting to tcp/%s/%s...", url, port);
  //fflush( stdout );

  if ((ret = mbedtls_net_connect(tcp_ssl_connect.net_ctx, url,
                                 port, MBEDTLS_NET_PROTO_TCP)) != 0)
  {
    ESP_LOGI(TAG, " failed\n  ! mbedtls_net_connect returned %d\n\n", ret);
    tcp_ssl_parameters_clean();
    return;
  }

  ESP_LOGI(TAG, " ok\n");

/*
  * 3. Setup SSL/TLS相关参数
*/
  ESP_LOGI(TAG, "  . Setting up the SSL/TLS structure...");

  if ((ret = mbedtls_ssl_config_defaults(tcp_ssl_connect.ssl_conf,
                                         MBEDTLS_SSL_IS_CLIENT,
                                         MBEDTLS_SSL_TRANSPORT_STREAM,
                                         MBEDTLS_SSL_PRESET_DEFAULT)) != 0)
  {
    ESP_LOGI(TAG, " failed\n  ! mbedtls_ssl_config_defaults returned %d\n\n", ret);
    tcp_ssl_parameters_clean();
    return;
  }

  ESP_LOGI(TAG, " ok %d\n", esp_get_free_heap_size());

  /* 由于证书会过期,所以这些不进行证书认证 */
  mbedtls_ssl_conf_authmode(tcp_ssl_connect.ssl_conf, MBEDTLS_SSL_VERIFY_NONE);
  /* 设置随机数生成的函数及方法 */
  mbedtls_ssl_conf_rng(tcp_ssl_connect.ssl_conf, mbedtls_ctr_drbg_random, tcp_ssl_connect.ctr_drbg);
  /* 这里不需要设置调试函数 */
  mbedtls_ssl_conf_dbg(tcp_ssl_connect.ssl_conf, NULL, NULL);

  /* 将ssl_conf的相关信息填充于ssl_ctx中去,用于进行SSL握手时使用 */
  if ((ret = mbedtls_ssl_setup(tcp_ssl_connect.ssl_ctx, tcp_ssl_connect.ssl_conf)) != 0)
  {
    ESP_LOGI(TAG, " failed\n  ! mbedtls_ssl_setup returned %d\n\n", ret);
    tcp_ssl_parameters_clean();
    return;
  }

  if ((ret = mbedtls_ssl_set_hostname(tcp_ssl_connect.ssl_ctx, "mbed TLS Server")) != 0)
  {
    ESP_LOGI(TAG, " failed\n  ! mbedtls_ssl_set_hostname returned %d\n\n", ret);
    tcp_ssl_parameters_clean();
    return;
  }
  /* 设置发送以及接收的时候,调用的内部函数 */
  mbedtls_ssl_set_bio(tcp_ssl_connect.ssl_ctx, tcp_ssl_connect.net_ctx, mbedtls_net_send, mbedtls_net_recv, NULL);

/*
  * 4. Handshake
*/
  ESP_LOGI(TAG, "  . Performing the SSL/TLS handshake...");

  while ((ret = mbedtls_ssl_handshake(tcp_ssl_connect.ssl_ctx)) != 0)
  {
    if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE)
    {
      ESP_LOGI(TAG, " failed\n  ! mbedtls_ssl_handshake returned -0x%x\n\n", -ret);
      tcp_ssl_parameters_clean();
    return;
    }
  }

  ESP_LOGI(TAG, " ok\n");
  

  /*
    * 5. Read the HTTP response
  */
  int err_code = xTaskCreate(tcp_receive_task,
                             "tcp_receive_task",
                             1024 * 8,
                             NULL,
                             3,
                             NULL);
  if (err_code != pdPASS)
  {
    ESP_LOGI("event_handler", "tcp_receive_task create failure,reason is %d\n", err_code);
  }    
}


