# 如何创建自己的第一个热点
## 前言
> 在入门教程中，我给大家讲了如何利用 **VSCODE** + **乐鑫的工具链**搭建ESP32的开发环境,众观全网应该算是首创了.如果之前还没有看过或者不知道在哪里看,可以[点击这里](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/%E5%A6%82%E4%BD%95%E6%90%AD%E5%BB%BAESP32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83.md).接下来,红旭无线开始给大家讲解基础教程,也就是今天的第一课 **<<如何创建自己的第一个热点>>**

## 创建模板工程
在开始本节教程之前,我们必须先创建一个自己的模板工程,也就是最干净的一个工程,里面什么都没有,用于接下来的基础以及高级项目教程使用.那么如果创建呢?其实很简单,接下来看如下操作步骤:
- 使用**vscode**打开esp32的sdk开发包文件夹,并在其根目录下,新建一个名为**app**文件夹;
![新建文件夹](https://raw.githubusercontent.com/xiaolongba/picture/master/create_new_folder.gif)

- 将esp32的sdk开发包中的**examples**->**get-started**->**hello_world**中的内容全部复制至根目录下新建的**app**文件夹中
![复制hello_world内容](https://raw.githubusercontent.com/xiaolongba/picture/master/copy_hello_world.gif)

- 修改**app**文件夹下**Makefile**中的**PROJECT_NAME**为**user-app**,同时将**main**目录下的**hello_world_main.c**更改为**user_app_main.c**

![修改工程名以及主函数名](https://raw.githubusercontent.com/xiaolongba/picture/master/name_modified.gif)

至此,模板工程就创建完成了.

## 创建热点
ESP32的开发跟ESP8266有点不太一样,ESP8266因为只有一个wifi功能,所以很多初始化在上电之后内部就已经自动完成了,真正在应用层上的初始化的没多少个.但是ESP32就不同了,因为ESP32不但支持wifi,面且支持蓝牙,所以上电之后内部并不会初始化太多东西,很多初始化还是要放在应用层处理.那么,ESP32是如何创建一个热点的呢?其实新手也不必害怕,因为乐鑫的SoC芯片的API封装程度很高,只需调用几个初始化API以及回调即可实现创建一个自己的热点.具体的核心代码如下所示:
```c
/** 
* @file         user_app_main.c 
* @brief        用户应用程序入口
* @details      用户应用程序的入口文件,用户所有要实现的功能逻辑均是从该文件开始或者处理
* @author       Helon_Chan 
* @par Copyright (c):  
*               红旭无线开发团队
* @par History:          
*               Ver0.0.1:
                     Helon_Chan, 2018/06/04, 初始化版本\n 
*/

/* =============
头文件包含
 =============*/
#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"


/** 
 * wifi事件处理函数
 * @param[in]   ctx     :表示传入的事件类型对应所携带的参数
 * @param[in]   event   :表示传入的事件类型
 * @retval      ESP_OK  : succeed
 *              其他    :失败 
 * @par         修改日志 
 *               Ver0.0.1:
                     Helon_Chan, 2018/06/04, 初始化版本\n 
 */
static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch (event->event_id)
    {
    case SYSTEM_EVENT_AP_START:
        printf("\nwifi_softap_start\n");
        break;
    case SYSTEM_EVENT_AP_STACONNECTED:
        printf("\nwifi_softap_connectted\n");
        break;
    case SYSTEM_EVENT_AP_STADISCONNECTED:
        printf("\nwifi_softap_disconnectted\n");
        break;
    default:
        break;
    }
    return ESP_OK;
}

/** 
 * 应用程序的函数入口
 * @param[in]   NULL
 * @retval      NULL              
 * @par         修改日志 
 *               Ver0.0.1:
                     Helon_Chan, 2018/06/04, 初始化版本\n 
 */
void app_main()
{    
    ESP_ERROR_CHECK( nvs_flash_init() );
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL));

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    wifi_config_t wifi_config = {
        .ap = {
            .ssid = "红旭无线",
            .ssid_len = 0,
            /* 最多只能被4个station同时连接,这里设置为只能被一个station连接 */
            .max_connection = 1,
            .password = "20180604",
            .authmode = WIFI_AUTH_WPA_WPA2_PSK,
        },
    };    
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());    
}

```

直接将**user_app_main.c**里面的所有内容用上面的代码直接全覆盖并编译下载**(在此之前,还需要调用make menuconfig设置下载串口)**即可实现创建一个热点.**(注意:首次编译会很耗时,大概是4~5分钟那样,看电脑性能)**
![设置串口](https://raw.githubusercontent.com/xiaolongba/picture/master/make_menuconfig.gif)

![编译下载](https://raw.githubusercontent.com/xiaolongba/picture/master/build_and_download.gif)

## 观看效果
最终下载之后的效果,由下图所示:

![最终效果](https://raw.githubusercontent.com/xiaolongba/picture/master/phone_show.gif)

## 技术交流
![QQ群](https://raw.githubusercontent.com/xiaolongba/picture/master/QQ%20Group.jpg)

**本文原创,转载请注明出处**


