#include "gpio_driver.h"

#define GPIO_BASE 0x3FF44000UL
#define GPIO_OUT_REG (*(volatile uint32_t *)(GPIO_BASE + 0x04))
#define GPIO_ENABLE_REG (*(volatile uint32_t *)(GPIO_BASE + 0x20))
#define GPIO_IN_REG (*(volatile uint32_t *)(GPIO_BASE + 0x3C))

void gpio_driver_set_output(gpio_pin_t pin)
{
    GPIO_ENABLE_REG |= (1U << pin);
}

void gpio_driver_set_input(gpio_pin_t pin)
{
    GPIO_ENABLE_REG &= ~(1U << pin);
}

void gpio_driver_write(gpio_pin_t pin, gpio_level_t level)
{
    if (level) {
        GPIO_OUT_REG |= (1U << pin);
    } else {
        GPIO_OUT_REG &= ~(1U << pin);
    }
}

gpio_level_t gpio_driver_read(gpio_pin_t pin)
{
    return ((GPIO_IN_REG & (1U << pin)) != 0U) ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW;
}
