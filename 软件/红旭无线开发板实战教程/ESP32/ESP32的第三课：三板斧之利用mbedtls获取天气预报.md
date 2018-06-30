## 前言
为什么这一篇教程的命名要加上三板斧呢?看过电视剧的都知道,三板斧是隋末唐初名将程咬金的成名绝技,三板斧的招式是一招还比一招猛.继[入门教程](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/README.md)以及以下两篇实战教程[如何创建自己的第一个热点](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%80%E8%AF%BE%EF%BC%9A%E5%A6%82%E4%BD%95%E5%88%9B%E5%BB%BA%E8%87%AA%E5%B7%B1%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E7%83%AD%E7%82%B9)和[按键单击以及多击的实现](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%BA%8C%E8%AF%BE%EF%BC%9A%E6%8C%89%E9%94%AE%E5%8D%95%E5%87%BB%E4%BB%A5%E5%8F%8A%E5%A4%9A%E5%87%BB%E7%9A%84%E5%AE%9E%E7%8E%B0)推出以来,据各路大佬读者反馈来看,收到了相当多的正面评价以及高度的赞扬.那种场面千言万语犹如此图![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%A5%BD%E8%AF%84%E5%A6%82%E6%BD%AE.jpg)在此,小编感谢大家的赞扬,也虚心接受大家的批评.我相信经过阅读上面提到的那些文章之后,现在入门ESP32应该没有什么难度了吧?起码点个灯总会了吧:grin:.如今,终于可以将这段时间所有讲的内容综合起来实现一个获取北上广深天气预报的实验了,也就是小编在句首所说的三板斧招式一招胜过下一招.不BB,咱们开始今天的内容.

## 原理
本篇教程所要描述的就是通过免费的天气预报API获取对应城市当天以及未来几天的天气情况.通过按键选择想要获取天气的城市,然后通过TCP连接上免费的天气预报API,最后一个GET请求就可以得到免费天气预报API返回的
天气信息.

- 免费天气预报API的选择

  现在你在网上搜索关键字"天气预报API",就会弹出很多网友分享的接口.但是,据小编东测西踩发现大多都不能用的.有的要么给连接上但是只能获取得到HTTP的Header内容,然后没有body的内容.最终,经过实测小编选择了**心知天气**的天气预报免费接口;

- HTTP VS HTTPS

  一般搞嵌入式的工程师大多都不会注意到这两者居然是有区别的.由于篇幅原因这里不会贴上一大段关于HTTP以及HTTPS区别的文章.但是,做为**贴心小棉袄**的小编已经将通向技术大门的[链接地址](https://www.cnblogs.com/wqhwe/p/5407468.html)附上.根据这篇链接文章所说的那样,HTTPS才是以后的方向.因此,此次教程我们就用HTTPS的GET请求,有别于网络上网友分享的HTTP的GET请求;
    - Tips
        1. HTTPS的端口默认是443
        1. HTTP的端口默认是80


- GET请求
GET请求只是HTTP请求中的其中一种方法,还有另外一个比较常用的是POST请求;那么,HTTP的GET请求报文格式是怎么样的呢?
    - 客户端请求消息
    
      客户端发送一个HTTP请求到服务器的请求消息包括以下格式：请求行（request line）、请求头部（header）、空行和请求数据四个部分组成，下图给出了请求报文的一般格式。
![2012072810301161](http://www.runoob.com/wp-content/uploads/2013/11/2012072810301161.png)

      以下是本次教程的GET请求内容:
      ```c
      GET /v3/weather/daily.json?key=4nik0ivxfmxfjzz1&location=beijing&language=zh-Hans&unit=c&start=0&days=5 HTTP/1.1
      Accept:*/*
      Host:api.seniverse.com
      ```

    - 服务器响应消息
    
      HTTP响应也由四个部分组成，分别是：状态行、消息报头、空行和响应正文。
![httpmessage](http://www.runoob.com/wp-content/uploads/2013/11/httpmessage.jpg)

      以下是小编在实战中获取得到的状行行+消息报头的内容:
      ```c
      HTTP/1.1 200 OK
      Date: Sat, 30 Jun 2018 08:47:28 GMT
      Content-Type: application/json; charset=utf-8
      Content-Length: 876
      Connection: keep-alive
      Cache-Control: no-cache
      Pragma: no-cache
      Expires: -1
      ```
  以上部分内容以及更多的HTTP详情就参考[菜鸟教程](http://www.runoob.com/http/http-messages.html)

- 乐鑫的库还是第三方的库
当时小编在做出选择的时候挣扎了好久,进行过激烈的思想斗争.最终下定决心选择了第三方的库即mbedtls(更多的详情[请点我](https://www.mbed.com/zh-cn/technologies/security/mbed-tls/)).理由如下:

    - 加解密库
    
      因为在使用wifi开发产品的时候,我们会用到各种各样的加解密.有的是有硬件加持,但是更多的还是软件层面上的加解密.正因为这样,mbedtls就更加是不二的选择,因为它有各种各样的如**base64/sha1/aes128等**加解密库的同时还支持SSL以及TLS.更更重要的是它背后还有大佬
        [![](https://os.mbed.com/static/img/ArmMbedLogo.svg)](https://www.mbed.com/)

    - 便利性&移值性
    
      专门为了嵌入式而生,即使以后我不再使用乐鑫的wifi芯片了,我用了其他的但是又支持mbedtls的wifi芯片,我就可以直接将之前的代码原封不动的复制过去就可以使用了

## 实战
介绍完原理之后,我想大多数读者已经明白小编是准备使用mbedtls来实现TCP连接并发起HTTPS的GET请求,最后获取得到指定城市的json格式的天气预报数据内容.那么,要实现这个功能我们需要做些什么呢?

### 按键
按键的作用主要是用于选择指定获取哪个城市的天气预报情况,我们可以直接使用[按键单击以及多击的实现](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%BA%8C%E8%AF%BE%EF%BC%9A%E6%8C%89%E9%94%AE%E5%8D%95%E5%87%BB%E4%BB%A5%E5%8F%8A%E5%A4%9A%E5%87%BB%E7%9A%84%E5%AE%9E%E7%8E%B0)中的按键初始化函数即可.

```c
user_app_key_init();
```
### RGB灯
RGB呼吸灯主要用于显示当前获取的是哪个城市的天气预报,其中该教程中所对应的映射关系是:

| 颜色  | 城市  |
| ------------ | ------------ |
|  R | 北京&深圳  |
|  G|  上海 |
|  B |   广州|

直接调用以下的rgb初始化函数即可.
```c
user_app_rgb_init();
```
### TCP
这应该是本篇教程最重要的一部分了.但是,即便是这样我们所要做的事情也不会太多,大多数要么mbedtls已经封装好了,要么就是小编已经封装好了.你只要做的就是填充获取指定城市天气预报的接口即可.
```c
https_request_by_GET(HTTPS_URL_BJ);                ///< HTTPS的GET请求
tls_client_handle(GET_REQ);                        ///< TCP相关的写和读操作
```
- 天气预报接口

  正如上面**原理**中的章节所说,我们最终选用的是心知天气的接口,那么我们如何获取到自己的免费接口呢?登陆[心知天气官网](https://www.seniverse.com/)并注册自己的账号就可以免费获取得到天气预报的接口了,以下是小编的免费天气预报接口:
  ```
  https://api.seniverse.com/v3/weather/now.json?key=4nik0ivxfmxfjzz1&location=beijing&language=zh-Hans&unit=c
  ```
  接口中所表达的详情含义,这里不再废口舌讲解.因为心知天气官网[文档](https://www.seniverse.com/doc)已经说得很详细了,我相信大家都是接受过九年义务教育的大佬,没有道理看不懂吧.

- 天气预报数据解析

  心知天气返回的数据是json格式,那么我们就需要使用到第三方的开源库cJSON了.ESP32的SDK已经自带这些移植好的库了,我们只需要直接使用即可.天气预报的数据格式如下所示:
  
  ```json
  {
    "results": [{
      "location": {
        "id": "WX4FBXXFKE4F",
        "name": "北京",
        "country": "CN",
        "path": "北京,北京,中国",
        "timezone": "Asia/Shanghai",
        "timezone_offset": "+08:00"
      },
      "daily": [{                         //返回指定days天数的结果
        "date": "2015-09-20",             //日期
        "text_day": "多云",               //白天天气现象文字
        "code_day": "4",                  //白天天气现象代码
        "text_night": "晴",               //晚间天气现象文字
        "code_night": "0",                //晚间天气现象代码
        "high": "26",                     //当天最高温度
        "low": "17",                      //当天最低温度
        "precip": "0",                    //降水概率，范围0~100，单位百分比
        "wind_direction": "",             //风向文字
        "wind_direction_degree": "255",   //风向角度，范围0~360
        "wind_speed": "9.66",             //风速，单位km/h（当unit=c时）、mph（当unit=f时）
        "wind_scale": ""                  //风力等级
      }, {
        "date": "2015-09-21",
        "text_day": "晴",
        "code_day": "0",
        "text_night": "晴",
        "code_night": "0",
        "high": "27",
        "low": "17",
        "precip": "0",
        "wind_direction": "",
        "wind_direction_degree": "157",
        "wind_speed": "17.7",
        "wind_scale": "3"
      }, {
        ...                               //更多返回结果
      }],
      "last_update": "2015-09-20T18:00:00+08:00" //数据更新时间（该城市的本地时间）
    }]
  }
  ```
## 效果展示
上面说了这么多,是不是迫不及待想看下效果呢?Ok,Here we go!
![天气预报](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%A4%A9%E6%B0%94%E9%A2%84%E6%8A%A5.gif)

## 源码
实现本章节中所有功能的源码均已经放置[红旭官方的GitHub地址](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B%E5%AF%B9%E5%BA%94%E6%BA%90%E7%A0%81/ESP32/ESP32%E7%9A%84%E7%AC%AC%E4%B8%89%E8%AF%BE%EF%BC%9A%E5%88%A9%E7%94%A8mbedtls%E8%8E%B7%E5%8F%96%E5%A4%A9%E6%B0%94%E9%A2%84%E6%8A%A5/app)了

## 技术交流
![QQ群](https://raw.githubusercontent.com/xiaolongba/picture/master/QQ%20Group.jpg)

**本文原创,转载请注明出处**


