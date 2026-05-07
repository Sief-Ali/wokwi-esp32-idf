#include "led_driver.h"
#include "gpio_driver.h"

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
static led_pin_t s_led_pin;

void led_driver_init(led_pin_t pin)
{
    s_led_pin = pin;
    gpio_driver_set_output(s_led_pin);
}

void led_driver_set(led_state_t state)
{
    gpio_driver_write(s_led_pin, state);
}
