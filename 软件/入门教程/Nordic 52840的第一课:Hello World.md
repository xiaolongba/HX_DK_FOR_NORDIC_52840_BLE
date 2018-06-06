# Nordic 52840的第一课:Hello World
## 前言
> 众所周知,基本上所有嵌入式入门的第一课都是跟**灯**有关,什么**跑马灯**、**流水灯**、**点天灯**等等.然而,在笔者看来第一课应该跟互联网的第一课一样,向世人宣布我来了,即**Hello World**.因此,红旭的Nordic 52840第一课也是一样.
![](https://raw.githubusercontent.com/xiaolongba/picture/master/emoji.jpg)

## 准备动作
在准备开始**Hello World**之前,我们还必须要有一个Nordic 52840的模板工程,这样我们才可以在工程模版的基础上进行以后一序列地开发.基本上,所有的模板工程就跟嵌入式硬件的最小系统一样,只保留最基本的配置文件,里面什么内容都没有,只有一个入口函数**main()**,至于如何在官方的SDK开发包裁剪出工程模板,这里不表.已经裁剪好的工程模版在这里([请点我]()).

## 欢迎来到这个世界
有了工程模版之后,那么接下进去我们今天的主题,即打印输出**Hello World**,那么通过什么方式打印呢?可以通过以下两种方式:

- UART
- RTT

### UART
这个就是我们平常口中所说的串口,我们可以通过串口可以打印输出"Hello World"字符串.在此之前,我们看一下红旭无线开发板上UART所连接的是Nordic 52840的哪两个脚 **.(注意:除了电源、地、烧录口以及USB接口之外，任意GPIO口均可以做为串口脚)**
- TX-->P0.08
- RX-->P0.06

实物接线示意图如下所示:

![UART接口](https://raw.githubusercontent.com/xiaolongba/picture/master/UART_INTERFACE.jpg)

下图与上图的PIN脚分别是一一对应的

![UART丝印](https://raw.githubusercontent.com/xiaolongba/picture/master/UART_SILK_SCREEN.jpg) 



