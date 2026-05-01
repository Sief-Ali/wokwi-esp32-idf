#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdbool.h>
#include <stdint.h>

typedef volatile uint8_t gpio_pin_t;
typedef volatile bool gpio_level_t;

#define GPIO_LEVEL_LOW false
#define GPIO_LEVEL_HIGH true

void gpio_driver_set_output(gpio_pin_t pin);
void gpio_driver_set_input(gpio_pin_t pin);
void gpio_driver_write(gpio_pin_t pin, gpio_level_t level);
gpio_level_t gpio_driver_read(gpio_pin_t pin);

#endif
