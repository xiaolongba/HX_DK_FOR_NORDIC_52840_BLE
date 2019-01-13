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
  - 其他
  
    日常主要使用的就是这几个软件,其他更多的工具可以官方均可在[官网](https://www.nordicsemi.com/eng/Products)上找到.
