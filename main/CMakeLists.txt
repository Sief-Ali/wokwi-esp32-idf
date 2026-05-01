idf_component_register(
    SRCS "wokwi-esp32-idf.c"
    INCLUDE_DIRS "."
    REQUIRES led_driver gpio_driver
)
