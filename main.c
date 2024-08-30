#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"
#include "nrf_gpio.h"

#define IO17 17

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    /* Configure IO17 as output */
    nrf_gpio_cfg_output(IO17);

    /* Toggle IO17 */
    while (true)
    {
        nrf_gpio_pin_toggle(IO17);
        nrf_delay_ms(500); // Toggle every 500ms

        // Original LED toggling code (commented out)
        /*
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            bsp_board_led_invert(i);
            nrf_delay_ms(500);
        }
        */
    }
}