#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio_driver.h"
#include "led_driver.h"

#define DELAY_TIME 1000
#define LED_PIN 5
#define SWITCH_PIN 2

void app_main(void)
{
    led_driver_init(LED_PIN);
    gpio_driver_set_input(SWITCH_PIN);

    while (1) {
        bool switch_level = gpio_driver_read(SWITCH_PIN);
        printf("GPIO %d is %s\n", SWITCH_PIN, switch_level ? "HIGH" : "LOW");
        led_driver_set(switch_level);
        vTaskDelay(pdMS_TO_TICKS(DELAY_TIME));
    }
}