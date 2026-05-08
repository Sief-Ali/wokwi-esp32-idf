#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdbool.h>
#include <stdint.h>

typedef uint8_t gpio_pin_t;
typedef bool gpio_level_t;

#define GPIO_LEVEL_LOW  ((gpio_level_t)false)
#define GPIO_LEVEL_HIGH ((gpio_level_t)true)

/* GPIO direction */
typedef enum {
    GPIO_DIRECTION_INPUT = 0U,
    GPIO_DIRECTION_OUTPUT = 1U
} gpio_direction_t;

/* API */
void gpio_driver_set_output(gpio_pin_t pin);
void gpio_driver_set_input(gpio_pin_t pin);

void gpio_driver_write(gpio_pin_t pin, gpio_level_t level);
void gpio_driver_toggle(gpio_pin_t pin);

gpio_level_t gpio_driver_read(gpio_pin_t pin);

#endif