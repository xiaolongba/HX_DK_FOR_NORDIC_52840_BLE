deps_config := \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/app_trace/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/aws_iot/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/bt/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/esp32/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/esp_adc_cal/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/ethernet/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/fatfs/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/freertos/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/heap/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/libsodium/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/log/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/lwip/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/mbedtls/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/openssl/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/pthread/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/spi_flash/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/spiffs/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/tcpip_adapter/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/wear_levelling/Kconfig \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/bootloader/Kconfig.projbuild \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/esptool_py/Kconfig.projbuild \
	/d/Project/ESP32/sdk/esp-idf-v3.0/components/partition_table/Kconfig.projbuild \
	/d/Project/ESP32/sdk/esp-idf-v3.0/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
