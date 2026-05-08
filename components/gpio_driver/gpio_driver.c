#include "gpio_driver.h"

typedef volatile uint32_t gpio_reg32_t;

#define GPIO_BASE 0x3FF44000UL

/* GPIO Registers */
#define GPIO_OUT_REG        (*(gpio_reg32_t *)(GPIO_BASE + 0x04UL))
#define GPIO_OUT_W1TS_REG   (*(gpio_reg32_t *)(GPIO_BASE + 0x08UL))
#define GPIO_OUT_W1TC_REG   (*(gpio_reg32_t *)(GPIO_BASE + 0x0CUL))

#define GPIO_ENABLE_REG     (*(gpio_reg32_t *)(GPIO_BASE + 0x20UL))
#define GPIO_ENABLE_W1TS_REG \
    (*(gpio_reg32_t *)((uintptr_t)GPIO_BASE + 0x24UL))
#define GPIO_ENABLE_W1TC_REG (*(gpio_reg32_t *)(GPIO_BASE + 0x28UL))

#define GPIO_IN_REG         (*(gpio_reg32_t *)(GPIO_BASE + 0x3CUL))

/* ========================= */

void gpio_driver_set_output(gpio_pin_t pin)
{
    GPIO_ENABLE_W1TS_REG = (1UL << pin);
}

void gpio_driver_set_input(gpio_pin_t pin)
{
    GPIO_ENABLE_W1TC_REG = (1UL << pin);
}

void gpio_driver_write(gpio_pin_t pin, gpio_level_t level)
{
    if (level == GPIO_LEVEL_HIGH) {
        GPIO_OUT_W1TS_REG = (1UL << pin);
    } else {
        GPIO_OUT_W1TC_REG = (1UL << pin);
    }
}

void gpio_driver_toggle(gpio_pin_t pin)
{
    GPIO_OUT_REG ^= (1UL << pin);
}

gpio_level_t gpio_driver_read(gpio_pin_t pin)
{
    return (gpio_level_t)((GPIO_IN_REG & (1UL << pin)) != 0UL);
}