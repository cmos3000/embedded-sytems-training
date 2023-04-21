/*
 * blink_pa0.c
 *
 *  Created on: 20 avr. 2023
 *      Author: hp
 */
//typedef unsigned char u8;
#include "Std_Types.h"
#include <util/delay.h>
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((volatile u8*)0x39)

int main(void)
{
	// PIN 4 in DDRA is output
DDRA|=0x01;
while(1){
    //PIN 4 in PORTA is high
PORTA|=0x01;
// Delay for 1s
_delay_ms(1000);
     //PIN 4 in PORTA is low
PORTA&=~(0x01);
// Delay for 1s
_delay_ms(1000);

}
return 0;
}

