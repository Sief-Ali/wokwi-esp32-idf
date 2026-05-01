#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

#define DELAY_TIME 1000
#define LED_PIN 5
#define SWITCH_PIN 2
#define GPIO_BASE 0x3FF44000

#define GPIO_OUT_REG (*(volatile uint32_t *)(GPIO_BASE + 0x04))
#define GPIO_ENABLE_REG (*(volatile uint32_t *)(GPIO_BASE + 0x20))
#define GPIO_IN_REG (*(volatile uint32_t *)(GPIO_BASE + 0x3C))

void app_main(void)
{

    GPIO_ENABLE_REG |= (1 << LED_PIN);      // LED as output
    GPIO_ENABLE_REG &= ~(1 << SWITCH_PIN);  // Switch as input

    while (1) {
        volatile uint8_t pin2_status = (GPIO_IN_REG & (1 << SWITCH_PIN)) ? 1 : 0;
        printf("GPIO %d is %s\n", SWITCH_PIN, pin2_status ? "HIGH" : "LOW");

        if (pin2_status) {
            GPIO_OUT_REG |= (1 << LED_PIN);
        } else {
            GPIO_OUT_REG &= ~(1 << LED_PIN);
        }
        vTaskDelay(pdMS_TO_TICKS(DELAY_TIME));
    }
}