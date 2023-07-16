/*
 * DIO_int.h
 *
 *  Created on: july 10, 2023
 *      Author: khalid
 */
#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8PORTA		0
#define DIO_u8PORTB		1
#define DIO_u8PORTC		2
#define DIO_u8PORTD		3

#define DIO_u8PIN0	0
#define DIO_u8PIN1	1
#define DIO_u8PIN2	2
#define DIO_u8PIN3	3
#define DIO_u8PIN4	4
#define DIO_u8PIN5	5
#define DIO_u8PIN6	6
#define DIO_u8PIN7	7

#define DIO_HIGH	1
#define DIO_LOW		0
#define DIO_OUTPUT	1
#define DIO_INPUT	0
#define DIO_PULL_UP 1


ES_t DIO_enuInit(void);
ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID ,u8 Copy_u8Value);
ES_t DIO_enuSetPortValue(u8 Copy_u8PortID ,u8 Copy_u8Value);
ES_t DIO_enuTogPortValue(u8 Copy_u8PortID);
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID ,u8 *Copy_Pu8Value);
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID ,u8 Copy_u8PinID,u8 Copy_u8Value);
ES_t DIO_enuSetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID,u8 Copy_u8Value);
ES_t DIO_enuTogPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID,u8 *Copy_Pu8Value);

#endif /* DIO_INT_H_ */
