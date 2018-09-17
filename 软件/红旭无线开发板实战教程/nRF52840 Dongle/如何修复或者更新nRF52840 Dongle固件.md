# 前言
近期，**nRF Connect**的版本升级到了v2.5.0，导致一些发货出去的nRF52840 Dongle根据**nRF Connect**的指引升级Bootloader时，出现无法升级的情况。最初，我们在遇到这个问题时也很纳闷，为什么在v2.4.0版本升级没有问题，怎么到了v2.5.0反而出问题了呢。后来，我们在官方的Release Note中看到了如下信息：

- Updated connectivity firmware from SoftDevice v3.0 to v3.1 for better compatibility 
- with SoftDevice 6.1
- Support for upgrading bootloader on nRF52840 dongle
- Support for Programmer app update
- Updated electron to 2.0
- Updated jest to 23.4.1
- Support to relaunch app when encountering libusb error
- Exposed start & stop watching device API

其中，在v2.5.0版本中增加了更新bootloader的功能，而Nordic在SDK12.0版本开始增加了**micro-ecc**，所以会出现这种情况。原因就是使用Public Key的Bootloader计算出来的哈希值与Initdata计算出来的哈希值不一致，那么出现这种问题应该怎么做呢？接下来，我将介绍如何修复以及更新nRF52840 Dongle的固件，请跟随小编的步伐一步一步来。

# 准备工具
- [pc-nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil/releases)

  用于生成Public Key
- [SEGGER Embedded Studio for ARM](https://www.segger.com/downloads/embedded-studio/)

  用于编译下载Bootloader工程

# 准备工作 
## 生成Public Key
使用**pc-nrfutil**生成public key,具体步骤如下所示：

- 在cmd中切换至pc-nrfutil路径下，并输入以下命令
  ```
  .\nrfutil.exe keys generate private.pem
  ```
  ![title](/api/file/getImage?fileId=5b9f560549b9631924000023)

- 将生成的<code>private.pem</code>转换成.c文件，并将生成的.c文件的内容覆盖掉<code>dfu_public_key.c</code>的内容，如下所示：
  ```
  .\nrfutil.exe keys display --key pk --format code private.pem --out_file public_key.c
  ```
  ![title](/api/file/getImage?fileId=5b9f570a49b9631924000024)
  覆盖后的情况，如下所示：
  ![title](/api/file/getImage?fileId=5b9f594549b9631924000025)

## 屏蔽哈希值校验函数

屏蔽文件所在的绝对路径**（下面是小编的SDK路径下的绝对路径）**，如下所示：
<code>C:\Users\Administrator\Desktop\New_folder\nRF5_SDK_15.0.0_a53641a\components\libraries\bootloader\dfu\nrf_dfu_validation.c</code>
```
    err_code = nrf_crypto_ecdsa_verify(&m_verify_context,
                                       &m_public_key,
                                       m_init_packet_hash,
                                       hash_len,
                                       m_signature,
                                       sizeof(m_signature));
//    if (err_code != NRF_SUCCESS)
//    {
//        NRF_LOG_ERROR("Signature failed (err_code: 0x%x)", err_code);
//        NRF_LOG_DEBUG("Signature:");
//        NRF_LOG_HEXDUMP_DEBUG(m_signature, sizeof(m_signature));
//        NRF_LOG_DEBUG("Hash:");
//        NRF_LOG_HEXDUMP_DEBUG(m_init_packet_hash, hash_len);
//        NRF_LOG_DEBUG("Public Key:");
//        NRF_LOG_HEXDUMP_DEBUG(pk, sizeof(pk));
//        NRF_LOG_FLUSH();
//
//        return NRF_DFU_RES_CODE_INVALID_OBJECT;
//    }
```

# 编译Bootloader工程
使用**SEGGER Embedded Studio for ARM**打开如下路径的工程，具体的路径如下所示：
```
C:\Users\Administrator\Desktop\New_folder\nRF5_SDK_15.2.0_9412b96\examples\dfu\open_bootloader\pca10059_usb_debug\ses
```
此时工程中的<code>dfu_public_key.c</code>的内容，应该覆盖成**生成Public Key**中第二步骤中所说的内容。同时，也要将**屏蔽哈希值校验函数**中提到的函数屏蔽掉。最后,编译下载至nRF52840 Dongle Dongle上即可。**（Tips:如果下载完成之后，Dongle的红色Led不闪烁，则按下复位键即可）**

# 最后
打开**nRF Connect**,选择**Bluetooth Low Energy**,选择nRF52840 Dongle映射出来的串口，即可完成升级。效果图如下所示：
![](https://raw.githubusercontent.com/xiaolongba/picture/master/upgrate%20nRF52840%20%20Dongle.gif)
