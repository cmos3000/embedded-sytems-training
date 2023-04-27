/*
 * push_button_led.c
 *
 *  Created on: 21 avr. 2023
 *      Author: hp
 */
//typedef unsigned char u8;
#include "Std_Types.h"
#include <util/delay.h>
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((volatile u8*)0x39)
#define PORTB *((u8*)0x38)
#define DDRB *((u8*)0x37)
#define PINB *((volatile u8*)0x36)

int main(void)
{
    // Configure the LED pins as output
    DDRA |= (1 << 0) | (1 << 1);

    // Configure the push button pins as input
    DDRB &= ~(1 << 0) & ~(1 << 1) & ~(1 << 2);

    // Enable pull-up resistors for the push buttons pins
    PORTB |= (1 << 0) | (1 << 1) | (1 << 2);

    while (1)
    {
        // Check if button 1 is pressed
        if ((PINB & (1 << 0))==0)
        {
            // Turn on LED 1
            PORTA |= (1 << 0);
        }
        else
        {
            // Turn off LED 1
            PORTA &= ~(1 << 0);
        }

        // Check if button 2 is pressed
        if ((PINB & (1 << 1))==0)
        {
            // Turn on LED 2
            PORTA |= (1 << 1);
        }
        else
        {
            // Turn off LED 2
            PORTA &= ~(1 << 1);
        }

        // Check if button 3 is pressed
        if ((PINB & (1 << 2))==0)
        {
            // Turn on both LEDs
            PORTA |= (1 << 0) | (1 << 1);
        }
    }

    return 0;
}
