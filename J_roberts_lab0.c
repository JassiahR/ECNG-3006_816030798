//Jassiah Roberts
// Platform-specific headers
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "gpio_struct.h"

void configure_pin(void)
{
    gpio_config_t confg_pin_1;

    // Define parameters for GPIO pin 1
    confg_pin_1.pin_bit_mask = (1ULL << GPIO_NUM_1);    // Bit mask for pin 1
    confg_pin_1.pull_up_en = GPIO_PULLUP_DISABLE;       // Disable pull-up
    confg_pin_1.pull_down_en = GPIO_PULLDOWN_DISABLE;   // Disable pull-down
    confg_pin_1.mode = GPIO_MODE_OUTPUT;                // Set mode to output
    confg_pin_1.intr_type = GPIO_INTR_DISABLE;          // Disable interrupt

    // Configure GPIO pin
    gpio_config(&confg_pin_1);
}

 
void app_main(void)
{
    // Configure GPIO pin 1
    configure_pin();

    // Set GPIO pin 1 level to low
    gpio_set_level(GPIO_NUM_1, 0);    // Set pin low
}
