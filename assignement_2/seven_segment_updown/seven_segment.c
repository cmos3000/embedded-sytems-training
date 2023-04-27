/*
 * seven_segment.c
 *
 *  Created on: 22 avr. 2023
 *      Author: hp
 */
/*typedef unsigned char u8;
#include "Std_Types.h"
#include <util/delay.h>
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((volatile u8*)0x39)
#define PORTB *((u8*)0x38)
#define DDRB *((u8*)0x37)
#define PINB *((volatile u8*)0x36)
#define DDRD *((u8*)0x31)
//#include <avr/io.h>
//#include <util/delay.h>
//#include "Std_Types.h"

int main(void)
{
u8 segCthd[]={0x3F,0x06,0x5B,
              0x4F,0x66,0x6D,
              0x7D,0x07,0x7F,
              0x6F};
//u8 swState=0;
u8 i=0;
// Set PORTA as input
    DDRA = 0x00;

//all pins of PORTA are pulled up
    PORTA=0;
    PORTB = 0x00;
    DDRB = 0XFF;
    while(1)
    {

    	for (i=0;i<=9;i++)
    	{
    	    PORTB = segCthd[i];
    	    _delay_ms(500);

    	}


    	return 0;
    }

}*/
//#define F_CPU 8000000UL*/
//#include<avr/io.h>
//#include<util/delay.h>
#include "Std_Types.h"
#include <util/delay.h>
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((volatile u8*)0x39)
#define PORTB *((u8*)0x38)
#define DDRB *((u8*)0x37)
#define PINB *((volatile u8*)0x36)
int main(){
	u8 i = 0;
	/*Configurations*/
	unsigned char sgment []={0x3F,0x06,0x5B,
                             0x4F,0x66,0x6D,
                             0x7D,0x07,0x7F,
                             0x6F};
	DDRB=0xFF;           /*ddr d0,d1,d2,d3,d4,d5,d6,d7 output */
	DDRA &= (~(1<<0)); /*ddrd2 = 0 input*/
	DDRA&=(~(1<<1)); /*ddrd3 = 0 input*/
	PORTB=0X3F;             /*as a start PORTA = 0 */
	//DDRC = (1<<6);
	//PORTC = (1<<6);
	/*Code*/
	while(1)
	{
		if (!(PINA&(1<<0)))
		{   if(i>=9){i=9;}
		else{
			i++;
			PORTB=sgment[i];
			_delay_ms(250);}

		} else if (!(PINA&(1<<1)))
		{   if(i<=0){i=0;}
		else{
			i--;
			PORTB=sgment[i];
				_delay_ms(250);}

			}
		else{}
		}


	}

