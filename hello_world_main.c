

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "gpio_struct.h"

void config_pin(void)
{
    gpio_config_t cfg_pin_2;

    // Define specific parameters for GPIO pin 1
    cfg_pin_2.pin_bit_mask = (1ULL << GPIO_NUM_1);     // Bit mask
    cfg_pin_2.pull_up_en = GPIO_PULLUP_DISABLE;        // Disable pull-up
    cfg_pin_2.pull_down_en = GPIO_PULLDOWN_DISABLE;    // Disable pull-down
    cfg_pin_2.mode = GPIO_MODE_OUTPUT;                 // Set mode to output
    cfg_pin_2.intr_type = GPIO_INTR_DISABLE;           // Disable interrupts

    // Configure GPIO pin
    gpio_config(&cfg_pin_2);
}


void app_main(void)
{
    // Configure GPIO pin 1
    config_pin();

    // Set GPIO pin 1 level to low, then high
    gpio_set_level(GPIO_NUM_1, 0);    // Set pin low
    gpio_set_level(GPIO_NUM_1, 1);    // Set pin high
}
