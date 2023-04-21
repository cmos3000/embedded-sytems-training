/*
 * snake_effect.c
 *
 *  Created on: 21 avr. 2023
 *      Author: hp
 */

//#include <avr/io.h>
#include "Std_Types.h"
#include <util/delay.h>
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((volatile u8*)0x39)
#define Nbre_LEDS 8  // Number of LEDs
#define DELAY_MS 200 // Delay between steps of the animation, in ms

int main(void)
{
    // Set PORTA as output
    DDRA = 0xFF;

    while (1)
    {
        // Start with all LEDs off
        PORTA = 0x00;

        // Loop through each LED in the chain
        for (int i = 0; i < Nbre_LEDS; i++)
        {
            // Turn on the current LED
            PORTA |= (1 << i);

            // Delay for a short time to show the LED
            _delay_ms(DELAY_MS);

            // Turn off the current LED
            PORTA &= ~(1 << i);
        }

        // Loop through each LED in reverse order
        for (int i = Nbre_LEDS - 1; i >= 0; i--)
        {
            // Turn on the current LED
            PORTA |= (1 << i);

            // Delay for a short time to show the LED
            _delay_ms(DELAY_MS);

            // Turn off the current LED
            PORTA &= ~(1 << i);
        }
    }

    return 0;
}

