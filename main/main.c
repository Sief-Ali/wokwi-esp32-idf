#include <stdio.h>

// FreeRTOS
// NOLINTNEXTLINE
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Drivers
#include "gpio_driver.h"
#include "led_driver.h"

#define DELAY_TIME 1000
#define LED_PIN 5
#define SWITCH_PIN 2

void app_main(void)
{
    // Initialize the LED driver
    led_driver_init(LED_PIN);
    // Initialize the GPIO driver
    gpio_driver_set_input(SWITCH_PIN);

    // Main loop
    while (1) {
        // Read the switch level
        bool switch_level = gpio_driver_read(SWITCH_PIN);
        // Set the LED level
        led_driver_set(switch_level);
        // Delay for the specified time
        vTaskDelay(pdMS_TO_TICKS(DELAY_TIME));
    }
}
