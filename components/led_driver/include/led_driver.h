#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdbool.h>
#include <stdint.h>

typedef volatile uint8_t led_pin_t;
typedef volatile bool led_state_t;

#define LED_STATE_OFF false
#define LED_STATE_ON true

void led_driver_init(led_pin_t pin);
void led_driver_set(led_state_t on);

#endif
