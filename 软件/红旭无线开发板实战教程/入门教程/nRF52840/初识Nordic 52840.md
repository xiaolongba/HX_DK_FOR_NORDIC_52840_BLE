# 初识Nordic 52840

##  前言

> 接触过BLE的朋友，我想基本上都听过Nordic吧，如果真有用过BLE的人没听说过这个品牌，那你很大可能性就是骗别人说你做过BLE开发。Nordic是挪威一家只做2.4G频段的无线通讯技术半导体芯片厂商，明年也就是2019年中旬也会推出量产级别兼芯片级的NB-IOT即nRF91，其目前在BLE行业中占据了百分之60以上的市场份额 **（数据来源于Nordic官方）** ，不得不说这样的数据是相当恐怖的。当然了，Nordic的成功是有原因的，其BLE芯片出色的性能、完善的资料系统以及对工程师相当友好的开发社区等等都是广大用户有目共睹的。简单地介绍完Nordic之后，接下来我们直接进入主题。

## 整体框架了解

不管是新手还是老鸟工程师，接触到之前没有用过的芯片，首先要做的就是去官方网站或者代理商获取芯片相关的文档进行查阅，从而为后面的芯片开发铺路或者打下基础。理所当然，对于Nordic 52840也是这样，所有的资料均可在官方网站下载得到，但是对从来没有用过Nordic BLE芯片的人来说，肯定是一脸懵逼的，有的人可能在哪里下载到相关的文档都不知道。大家莫慌，随我慢慢道来，但是我不会马上就告诉你相关的文档在哪里下载，因为写这篇文章就是让你初识Nordic 52840，假设直接就告诉你相关的文档在哪里，那么你看了这篇文章就等于没看。因此，要想知道如何开发这个芯片，就应该先看看这个芯片相关的框架。

### 内存布局


<span id="jump">我们</span>先来看看Nordic 52840的内存分布，如下图所示	

![bootloader_memory_nrf52](https://raw.githubusercontent.com/xiaolongba/picture/master/bootloader_memory_nrf52.svg?sanitize=true)

我们先暂时不要去理会上图左右两边的标注，就单看中间的Nordic 52840的内存分布结构。由上图可以知道，Nordic 52840是由以下几个部分组成:
- MBR
- SoftDevice
- Application
- Bootloader
- MBR parameter storage
- Bootloader settings

那这时候问题来了，这些都是些啥鸡巴玩意啊？兄弟，莫慌！听哥徐徐道来（如果短时间看不明白，可以暂时忽略这些）。

- MBR

  MBR的全称是**Master Boot Record** ，即主引导记录的意思，其主要功能就是提供一个接口用于应用程序固件、协议栈或者Bootloader固件在系统内更新；

- MBR parameter storage

  具体的作用如下所示：

  ```
  官方原文：

    This used to store the SD_MBR_COMMAND_COPY_BL or the SD_MBR_COMMAND_VECTOR_TABLE_BASE_SET command when resetting the IC. E.g. under a bootloader update. Also if reset or power is lost, the MBR will read the stored commands and continue the update process. Upon reset the MBR read the stored commands, which will not be erased before the update is finished. Seeing that there is a “copy bootloader” command, the MBR will check if the bootloader was successfully copied, if not, it will re-write the bootloader to the bootloader section.

  译文：
    这用于当复位芯片时，存储SD_MBR_COMMAND_COPY_BL或SD_MBR_COMMAND_VECTOR_TABLE_BASE_SET命令（例如，在更新bootloader时）。此外，如果重启或断电，MBR将读取存储的命令并继续更新过程。复位后，MBR读取存储的命令，在更新完成之前不会擦除这些命令。看到有一个“copy bootloader”命令，MBR将检查bootloader是否被成功复制，如果没有，它会将bootloader重新写入flash中的bootloader空间
  ```

- SoftDevice

  这个就是Nordic的协议栈的统称，其所有协议栈都叫SoftDevice,不同功能的协议栈通过代号来区分。例如，目前最新的BLE、Zigbee、Thread以及SIG　Mesh四合一的协议栈就是S140，它是以16进制的形式提供的，首次使用时只需直接下载至flash中即可；

- Application

  我们平时所写的程序就是保存在这里，包括用户需要掉电保护的一此自定义数据也是保存在这里的；

- Bootloader

  Bootloader主要用于处理系统内的更新过程，具体作用如下所示

  ```
  官方原文：
    The bootloader has full access to the SoftDevice API and can be implemented like any application that uses the SoftDevice. In particular, the bootloader can make use of the SoftDevice API for Bluetooth low energy communication.
  The bootloader is also responsible for keeping track of and verifying the integrity of the SoftDevice. If an unexpected reset occurs during an update of the SoftDevice, it is the responsibility of the bootloader to detect this and resume the update procedure.

  译文：
    bootloader可以完全访问SoftDevice API函数，并且可以像使用SoftDevice的任何应用程序中一样实现同样的功能。尤其是，bootloader可以利用SoftDevice API函数进行蓝牙低功耗通信。
    bootloader还负责跟踪和验证SoftDevice的完整性。 如果在更新SoftDevice期间发生意外重启，bootloader有责任检测这种情况并重新开始更新过程。
  ```

- Bootloader settings

  具体作用如下所示：

  ```
  官方原文：
    A bootloader settings page contains information about the current DFU process. In addition, it can contain information about the installed application and the firmware version.

  译文：
    bootloader设置页包含当前空中升级进程的信息。此外，还可能包含有应用程序和固件的版本信息。
  ```


看完以上的介绍，估计大部分人都已经明白Nordic 52840的内存分布结构吧，那这个时候可能又有一个问题了，那这些组成部分到底各占用多大的空间呢？这也是普众单片机工程师都很在意或者关心的东西，具体如下表格所示：

| 各组成部分                          | 各组成部分占用的空间范围           |
| :---------------------------------- | :--------------------------------- |
| Bootloader settings                 | 0x000F F000 - 0x0010 0000 (4 kB)   |
| MBR parameter storage               | 0x000F E000 - 0x000F F000 (4 kB)   |
| Bootloader                          | 0x000F 8000 - 0x000F E000 (24 kB)  |
| Application area (incl. free space) | 0x0002 0000 - 0x000F 8000 (864 kB)  |
| SoftDevice                          | 0x0000 1000 - 0x0002 0000 (124 kB) |
| Master Boot Record (MBR)            | 0x0000 0000 - 0x0000 1000 (4 kB)   |

**注意**：SoftDevice即协议栈的大小会根据版本不同而不同

### 如何选择协议栈和SDK

通过[内存布局](#jump)中可以看出，我们主要关注SoftDevice和Application部分即可，但是Nordic的SoftDevice有好多版本，SDK也有好多版本，而且这两者不能乱选择，这样就让初学者会很容易限入窘境不知道哪个才适合他使用。其实，官方已经有一个映射表格说明这些了，具体如下表格所示：

| nRF52840 IC revision                                         | nRF5 SDK                                                     | S132 SD                                                      | S132 SDS                                                     | S140 SD | S140 SDS                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------- | ------------------------------------------------------------ |
| Engineering A                                                | [12.2.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v12.2.0/index.html) | 3.0.0[1](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/nRF52840_ic_rev_sdk_sd_comp_matrix.html#nRF52840_ic_rev_sdk_sd_comp_matrix__SD_132_300_limitation-fn) | [3.1](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.s132.sds/dita/softdevices/s130/s130sds.html)[2](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/nRF52840_ic_rev_sdk_sd_comp_matrix.html#nRF52840_ic_rev_sdk_sd_comp_matrix__SDS_132_31_limitation) | -       | -                                                            |
| [12.3.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v12.3.0/index.html) |                                                              |                                                              |                                                              |         |                                                              |
| [13.0.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v13.0.0/index.html) | -                                                            | -                                                            | 5.0.0-2.alpha                                                |         |                                                              |
| [13.1.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v13.1.0/index.html) |                                                              |                                                              |                                                              |         |                                                              |
| [14.0.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v14.0.0/index.html) |                                                              |                                                              |                                                              |         |                                                              |
| [14.1.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v14.1.0/index.html) |                                                              |                                                              |                                                              |         |                                                              |
| [14.2.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v14.2.0/index.html) |                                                              |                                                              |                                                              |         |                                                              |
| -                                                            | 5.0.0-3.alpha                                                |                                                              |                                                              |         |                                                              |
| 6.0.0-6.alpha                                                |                                                              |                                                              |                                                              |         |                                                              |
| Engineering B; Engineering C; 1                              | [15.0.0](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.sdk5.v15.0.0/index.html) |                                                              |                                                              | 6.0.0   | [1.x](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.nrf52/dita/nrf52/compatibility_matrix/keydef/PLUGINS_ROOT/com.nordic.infocenter.s140.sds/dita/softdevices/s130/s130sds.html) |

从这个表格可以看到，不同版本的SDK不是都支持所有协议栈的。在这里，我们只需要查看最后一行即可，即

- SoftDevice

  选择S140版本

- SDK

  选择15.0.0版本

- 其他

  SDS全称是SoftDevice Specification 即协议栈规格书

## 文档下载

说了这么多，终于来到如何下载开发所需的Nordic 52840相关文档这一章节了，之所以在前面叨叨说那些内容，就是想让初学者明白，官方的文档有很多如果没有一个整体地了解，那么就会很容易稀里糊涂地下载一堆没用的资料，而且下载下来也不知道该看哪个，其实对于大部分开发者来说只需要下载如下几个文档就可以了，具体如下所示：

- [Nordic 52840规格书](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.s140.sds%2Fdita%2Fsoftdevices%2Fs130%2Fs130sds.html)
- [Nordic 52840勘误表](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.s140.sds%2Fdita%2Fsoftdevices%2Fs130%2Fs130sds.html)
- [Nordic 52840型号说明表(官方会不定期更新)](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.nrf52%2Fdita%2Fnrf52%2Fcompatibility_matrix%2FnRF52840_ic_revision_overview.html)
- [Nordic 52820型号、SDK以及协议栈的映射表（官方会不定期更新）](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.nrf52%2Fdita%2Fnrf52%2Fcompatibility_matrix%2FnRF52840_ic_revision_overview.html)
- [Nordic 52840协议栈](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/S140-SD-v6/60624)
- [Nordic 52840 BLE软件开发包，即SDK](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5-SDK-zip/59021)
- [Nordic 52840 Zigbee以及Thread软件开发包，即SDK](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5-SDK-for-Thread-and-Zigbee/67604)
- [Nordic 52840 SIG Mesh软件开发包，即SDK](https://www.nordicsemi.com/eng/nordic/Products/nRF5-SDK-for-Mesh/nRF5-SDK-for-Mesh/62377)

其中，SDK包中均包含有API手册，如果需要更多的文档可以到[官方的文档中心](https://infocenter.nordicsemi.com/index.jsp)下载

## 最后

希望看过这篇文章的初学者能有所收获，而期望各位大佬、大神以及砖家斧正，当然如果你想要购买Nordic 52840开发板玩玩，也可以[点击这里](https://shop507575225.taobao.com/index.htm?spm=2013.1.w5002-16973646476.2.56ea1f47dUx4Ha)。
