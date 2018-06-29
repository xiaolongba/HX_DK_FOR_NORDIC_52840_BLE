deps_config := \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/app_trace/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/aws_iot/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/bt/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/esp32/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/esp_adc_cal/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/ethernet/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/fatfs/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/freertos/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/heap/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/libsodium/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/log/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/lwip/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/mbedtls/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/openssl/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/pthread/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/spi_flash/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/spiffs/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/tcpip_adapter/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/wear_levelling/Kconfig \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/bootloader/Kconfig.projbuild \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/esptool_py/Kconfig.projbuild \
	/f/Project/esp32/sdk/esp-idf-v3.0/components/partition_table/Kconfig.projbuild \
	/f/Project/esp32/sdk/esp-idf-v3.0/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
