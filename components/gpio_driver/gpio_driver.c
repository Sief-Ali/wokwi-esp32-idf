#include "gpio_driver.h"

#define GPIO_BASE 0x3FF44000UL

typedef volatile uint32_t gpio_reg32_t;

// NOLINTBEGIN(performance-no-int-to-ptr)
#define GPIO_OUT_REG (*(gpio_reg32_t *)(GPIO_BASE + 0x04UL))
#define GPIO_ENABLE_REG (*(gpio_reg32_t *)(GPIO_BASE + 0x20UL))
#define GPIO_IN_REG (*(gpio_reg32_t *)(GPIO_BASE + 0x3CUL))
// NOLINTEND(performance-no-int-to-ptr)

void gpio_set_output(gpio_pin_t pin)
{
    GPIO_ENABLE_REG |= (1U << pin);
}

void gpio_set_input(gpio_pin_t pin)
{
    GPIO_ENABLE_REG &= ~(1U << pin);
}

void gpio_write(gpio_pin_t pin, gpio_level_t level)
{
    if (level) {
        GPIO_OUT_REG |= (1U << pin);
    } else {
        GPIO_OUT_REG &= ~(1U << pin);
    }
}

gpio_level_t gpio_read(gpio_pin_t pin)
{
    return (gpio_level_t)((GPIO_IN_REG & (1U << pin)) != 0U);
}
