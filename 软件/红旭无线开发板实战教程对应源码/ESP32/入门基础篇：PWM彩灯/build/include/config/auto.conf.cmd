deps_config := \
	/d/ESP/esp-idf-v3.0/components/app_trace/Kconfig \
	/d/ESP/esp-idf-v3.0/components/aws_iot/Kconfig \
	/d/ESP/esp-idf-v3.0/components/bt/Kconfig \
	/d/ESP/esp-idf-v3.0/components/esp32/Kconfig \
	/d/ESP/esp-idf-v3.0/components/esp_adc_cal/Kconfig \
	/d/ESP/esp-idf-v3.0/components/ethernet/Kconfig \
	/d/ESP/esp-idf-v3.0/components/fatfs/Kconfig \
	/d/ESP/esp-idf-v3.0/components/freertos/Kconfig \
	/d/ESP/esp-idf-v3.0/components/heap/Kconfig \
	/d/ESP/esp-idf-v3.0/components/libsodium/Kconfig \
	/d/ESP/esp-idf-v3.0/components/log/Kconfig \
	/d/ESP/esp-idf-v3.0/components/lwip/Kconfig \
	/d/ESP/esp-idf-v3.0/components/mbedtls/Kconfig \
	/d/ESP/esp-idf-v3.0/components/openssl/Kconfig \
	/d/ESP/esp-idf-v3.0/components/pthread/Kconfig \
	/d/ESP/esp-idf-v3.0/components/spi_flash/Kconfig \
	/d/ESP/esp-idf-v3.0/components/spiffs/Kconfig \
	/d/ESP/esp-idf-v3.0/components/tcpip_adapter/Kconfig \
	/d/ESP/esp-idf-v3.0/components/wear_levelling/Kconfig \
	/d/ESP/esp-idf-v3.0/components/bootloader/Kconfig.projbuild \
	/d/ESP/esp-idf-v3.0/components/esptool_py/Kconfig.projbuild \
	/d/ESP/esp-idf-v3.0/components/partition_table/Kconfig.projbuild \
	/d/ESP/esp-idf-v3.0/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
