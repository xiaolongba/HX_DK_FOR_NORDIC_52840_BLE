# PC上位机软件目录资料说明

该子目录主要存放开发nRF52840所需要的一些上位机辅助软件,具体如下所示:
  - [SEGGER Embedded Studio for ARM IDE](https://www.segger.com/downloads/embedded-studio/)
    
    该IDE是官方配合Nordic 52840首推的开发工具，**强烈建议新手使用该工具进行Nordic 52840开发！！！**
  - [nRF-Connect-Windows](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Connect-for-desktop/Download#infotabs)
  
    该软件主要是配合USB Dongle做一些辅助的评估测试以及一些电流测试相关的应用,更多详情请安装软件之后查看;
  - [nRFgo Studio-Win64](https://www.nordicsemi.com/eng/nordic/Products/nRFgo-Studio/nRFgo-Studio-Win64/14964)
  
    该软件主要是配合Jlink进行 **协议栈/应用程程序/Bootloader**烧录或者擦除的图形化上位机软件.现在很少使用这个软件,好像官方并不怎么推荐使用了 **(由于兼容性问题，红旭不推荐使用该软件工具，这里指出只是为了说明有这个软件)**;  
  - [nRF5x-Command-Line-Tools-Win32](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5x-Command-Line-Tools-Win32/58850)
  
    该软件主要是实现 **烧录/擦除/合并**固件的命令行下工具,在安装**nRF-Connect-Windows**以及**nRFgo Studio**会一起安装,当然你也可以单独安装 **(红旭推荐使用该工具软件烧录协议栈、Bootloader、application)**;
    
  - [Visual Studio Code](https://code.visualstudio.com/)
  
    红旭推荐入门之后的开发者，采用该工具软件进行Nordic 52840开发，好不好用谁用谁知道 :smile: ,至于没有使用过的人可以参考我们专门写的一篇文章：[如果使用VScode 开发Nordic 52840的教程](https://github.com/xiaolongba/HX_DK_FOR_NORDIC_52840_BLE/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/nRF52840/%E5%A6%82%E4%BD%95%E4%BD%BF%E7%94%A8Vscode%E5%BC%80%E5%8F%91%E8%B0%83%E8%AF%95nRF52840(%E5%85%A8%E7%BD%91%E9%A6%96%E5%8F%91).md)
  - 其他
  
    日常主要使用的就是这几个软件,其他更多的工具可以官方均可在[官网](https://www.nordicsemi.com/eng/Products)上找到.
