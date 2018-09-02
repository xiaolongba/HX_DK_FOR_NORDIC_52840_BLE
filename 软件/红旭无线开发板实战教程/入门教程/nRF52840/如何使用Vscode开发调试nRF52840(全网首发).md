## 前言
使用nRF52840已经有段时间了,虽然还没有完全将nRF52840的所有功能都玩一遍，但从目前情况来看，做为一款多协议并存的无线芯片来说还是很强大的，即使目前市场上以及公司层面上对其的评价也大多是**功能虽强，但价更高**。但是，做为Nordic的拳头产品以及随着IoT市场对多协议、大容量以及更复杂的功能的需求越来越旺盛，nRF52840势必在不久的将来会投入各个落地的应用中去。好像扯得有点远了，接下来我们就看看如何在vscode搭建nRF52840的开发调试环境。

## 困惑
虽然nRF52840目前支持4种开发工具链，如下所示：
- SEGGER Embedded Studio
- Keil MDK-ARM
- GCC
- IAR Embedded Workbench

![](https://raw.githubusercontent.com/xiaolongba/picture/master/ToolChains.png)

但是，它们均有各自的优缺点。由于国情以及历史原因，**Keil MDK-ARM**和**IAR Embedded Workbench**在我们国内有很高的支持率。但是，这两个都是商业软件，是需要付费的。随着国内版权意识的不断增强，我相信在不久的将来，这两个软件在国内的占比会大幅下降。基于以上原因，剩下能选的就只有**SEGGER Embedded Studio**和**GCC**了。虽然**SEGGER Embedded Studio**也是商业软件，但是Nordic已经将其版权买下，但凡使用Nordic芯片的用户均可以免费使用这个软件。然而，在小编使用的过程中感觉这个软件还是too young了。
- 经常用着用着，莫名其妙就崩溃了，只留下小编一脸的茫然
- 设置选项太多了
- 目前最新版本V3.5，一些选项莫名其妙的显示不了了
- 设置环境背景为程序员专属颜色即黑色，竟然只是代码编辑区是黑色而不是全局变黑
- 有时小编写代码速度过快，代码提示跟不上小编手速……
- 函数不能折叠
- 剩下的由网友补充……

综上所述，有强迫症的童鞋就只有剩下GCC这条路可选了，因为已经无路可走了。但是GCC只是一个工具链，而上面的其他三位大佬则均是IDE，这个时候就不得不祭出号称 **“最叼编辑器Visual studio”** 它弟----**VSCODE**。

## 准备工作 
### 工具
- [Visual Studio Code](https://code.visualstudio.com/)

    根据自己的开发环境，下载对应的安装包
- [J-Link Software and Documentation pack](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)

    根据自己的开发环境，下载对应的安装包，后面会用来下载调试使用
- [nRF5x-Command-Line-Tools](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5x-Command-Line-Tools-Win32/58850)

    届时配合上面的Jlink软件对nRF52840执行擦除烧录等动作 
- [windows-arm-none-eabi](https://marketplace.visualstudio.com/items?itemName=atomclip.windows-arm-none-eabi#review-details)

    这是GNU Arm embedded toolchain被打包成vscode的插件，直接下载即可安装至vscode
- [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)

    这是vscode中的Cortex-Debug插件，在vscode中使用它来调用**JLinkGDBServer**就可以调试nRF52840,直接下载即可安装至vscode
- [其他](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%95%99%E7%A8%8B%E9%85%8D%E5%A5%97%E7%9A%84%E7%9B%B8%E5%85%B3%E5%B7%A5%E5%85%B7)

    主要是一些windows下没有的常用工具
    
## 设置
1. 增加[windows-arm-none-eabi](https://marketplace.visualstudio.com/items?itemName=atomclip.windows-arm-none-eabi#review-details)以及[nRF5x-Command-Line-Tools](https://www.nordicsemi.com/eng/nordic/Products/nRF52840/nRF5x-Command-Line-Tools-Win32/58850)的路径至环境变量，以下是小编的路径

    ```
    C:\Program Files (x86)\Nordic Semiconductor\nrf5x\bin
    C:\Users\Administrator\.vscode\extensions\atomclip.windows-arm-none-eabi-0.1.2\bin
    ```  
    
    ![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F.png)
    - **注意：如果[windows-arm-none-eabi](https://marketplace.visualstudio.com/items?itemName=atomclip.windows-arm-none-eabi#review-details)升级了，路径也要跟着更新**
1. 解压从[其他](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%95%99%E7%A8%8B%E9%85%8D%E5%A5%97%E7%9A%84%E7%9B%B8%E5%85%B3%E5%B7%A5%E5%85%B7)下载得到的工具，并将其全部复制到[windows-arm-none-eabi](https://marketplace.visualstudio.com/items?itemName=atomclip.windows-arm-none-eabi#review-details)的路径下
![](https://raw.githubusercontent.com/xiaolongba/picture/master/Build%20Tools.png)
    
1. 安装完[Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)之后，指定**JLinkGDBServer**的路径，以下是小编的路径

    ```
    C:/Program Files (x86)/SEGGER/JLink_V634e/JLinkGDBServerCL.exe
    ```
    
    ![](https://raw.githubusercontent.com/xiaolongba/picture/master/JlinkGDBServerPath.png)
1. 增加编译以及烧录等相关任务，至于如何在vscode上增加任务，可以参考此[教程](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/ESP32/windows%E5%BC%80%E5%8F%91ESP32%E7%9A%84%E7%A6%8F%E9%9F%B3%2C%E7%BC%96%E8%AF%91%E9%80%9F%E5%BA%A6%E5%A0%AA%E6%AF%94Linux.md)中的**配置任务**这一小节

    ```json
    {
      "version": "2.0.0",
      "tasks": [
        {
          "label": "build firmware",
          "type": "shell",        
          "command": "make -j8",        
          "options": {          
            "cwd": "D:/Project/wireless_tech/nRF5_SDK_15.0.0_a53641a/examples/ble_peripheral/ble_app_template/pca10056/s140/armgcc"
          },
          "osx": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "linux": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "windows": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin};${env:PATH}",              
              }
            },
          },
          "group": {
            "kind": "build",
            "isDefault": true,
          },
          "problemMatcher": "$gcc"
        },
        {
          "label": "clean firmware",
          "type": "shell",        
          "command": "make clean",        
          "options": {          
            "cwd": "D:/Project/wireless_tech/nRF5_SDK_15.0.0_a53641a/examples/ble_peripheral/ble_app_template/pca10056/s140/armgcc"
          },
          "osx": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "linux": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "windows": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin};${env:PATH}",              
              }
            },
          },
          "group": {
            "kind": "build",
            "isDefault": true,
          },
          "problemMatcher": "$gcc"
        },
        {
          "label": "download flash",
          "type": "shell",        
          "command": "make flash -j8",        
          "options": {          
            "cwd": "D:/Project/wireless_tech/nRF5_SDK_15.0.0_a53641a/examples/ble_peripheral/ble_app_template/pca10056/s140/armgcc"
          },
          "osx": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "linux": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "windows": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin};${env:PATH}",              
              }
            },
          },
          "group": {
            "kind": "build",
            "isDefault": true,
          },
          "problemMatcher": "$gcc"
        },
        {
          "label": "erase all flash",
          "type": "shell",        
          "command": "make erase -j8",        
          "options": {          
            "cwd": "D:/Project/wireless_tech/nRF5_SDK_15.0.0_a53641a/examples/ble_peripheral/ble_app_template/pca10056/s140/armgcc"
          },
          "osx": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "linux": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "windows": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin};${env:PATH}",              
              }
            },
          },
          "group": {
            "kind": "build",
            "isDefault": true,
          },
          "problemMatcher": "$gcc"
        },{
          "label": "download softdevice",
          "type": "shell",        
          "command": "make flash_softdevice -j8",        
          "options": {          
            "cwd": "D:/Project/wireless_tech/nRF5_SDK_15.0.0_a53641a/examples/ble_peripheral/ble_app_template/pca10056/s140/armgcc"
          },
          "osx": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "linux": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin}:${env:PATH}",
              }
            },
          },
          "windows": {
            "options": {
              "env": {
                "PATH": "${config:arm-none-eabi.bin};${env:PATH}",              
              }
            },
          },
          "group": {
            "kind": "build",
            "isDefault": true,
          },
          "problemMatcher": "$gcc"
        }
      ]
    }
    ```

1. 完成1.2.3.4之后，在vscode的工具栏中选择<code>调试</code>-><code>添加配置</code>-><code>{}Cortex Debug：JLink</code>，最后将弹出的内容替换为以下内容：

    ![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%B7%BB%E5%8A%A0%E9%85%8D%E7%BD%AE.png)

    ```json
    {
      // Visual Studio Code launch.json for XMC 2Go development board 
      "version": "0.2.0",
      "configurations": [            
        {
          "cwd": "${workspaceRoot}",
          "executable": "D:/Project/wireless_tech/nRF5_SDK_15.0.0_a53641a/examples/ble_peripheral/ble_app_template/pca10056/s140/armgcc/_build/nrf52840_xxaa.out",// 根据自身的情况填充自己的实际路径
          "name": "Debug Microcontroller",
          "request": "launch",
          "type": "cortex-debug",
          "servertype": "jlink",
          "runToMain": true,
          "device": "nRF52840_xxAA",
          "interface": "swd",
          "ipAddress": null,
          "serialNumber": null, 
          "preLaunchTask": "download flash"//如果你想要在调试之前下载固件，则必须将填充下载固件的任务名(这是自定义的名字)，否则删除掉这一行即可
        },
      ]
    }
    ```
1. 最后，将工程的<code>components</code>-><code>toolchain</code>-><code>gcc</code>-><code>Makefile.windows</code>工具链路径指向[windows-arm-none-eabi](https://marketplace.visualstudio.com/items?itemName=atomclip.windows-arm-none-eabi#review-details)的实际路径,以下是小编的工具链路径：
    ```
    GNU_INSTALL_ROOT := C:/Users/Administrator/.vscode/extensions/atomclip.windows-arm-none-eabi-0.1.2/bin/
    GNU_VERSION := 7.3.1
    GNU_PREFIX := arm-none-eabi
    ```

至此，就完成了所有的设置了，接下来就可以使用vscode开发nRF52840了。

## 效果
### 擦除
![](https://raw.githubusercontent.com/xiaolongba/picture/master/erase%20all%20flash%20with%20vscode%20.gif)
### 编译
![](https://raw.githubusercontent.com/xiaolongba/picture/master/build%20with%20vscode%20.gif)
### 烧录application
![](https://raw.githubusercontent.com/xiaolongba/picture/master/download%20application%20with%20vscode%20.gif)
### 烧录协议栈
![](https://raw.githubusercontent.com/xiaolongba/picture/master/download%20softdevice%20with%20vscode%20.gif)
### 调试并烧录application
![](https://raw.githubusercontent.com/xiaolongba/picture/master/debug%20and%20download%20app%20with%20vscode%20.gif)

## 技术交流
![QQ群](https://raw.githubusercontent.com/xiaolongba/picture/master/QQ%20Group.jpg)

**本文原创,转载请注明出处**

