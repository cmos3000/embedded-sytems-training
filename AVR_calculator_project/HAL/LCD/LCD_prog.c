/*
 * LCD_prog.c
 *
 *  Created on: july 8, 2023
 *      Author: khalid
 */
#include "../../SERVICES/Std_Types.h"
#include "../../SERVICES/error_status.h"

#include "../../MCAL/DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"

#include "util/delay.h"

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_OUTPUT);

	_delay_ms(35);

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_OUTPUT);

	//function set
	LCD_invidSendCommand(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_invidSendCommend(0x28);
#endif
	_delay_ms(1);
	LCD_invidSendCommand(0x0f);
	_delay_ms(1);
	LCD_invidSendCommand(0x01);
	_delay_ms(2);
	LCD_invidSendCommand(0x06);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_HIGH);

	LCD_vidLatch(Copy_u8Data);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;

	// set rs as command
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_LOW);

	LCD_vidLatch(Copy_u8Command);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t LCD_enuDisplayString(u8 *Copy_pu8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 count=0;
	for (count=0;Copy_pu8Data[count];count++)
	{
		LCD_enuDisplayChar(Copy_pu8Data[count]);
	}
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t LCD_enuSetPosition(u8 Copy_u8Row,u8 Copy_u8Col)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8Row==0 && Copy_u8Col<16)
	{
		LCD_enuSendCommand((Copy_u8Col & 0x0F)|0x80);
	}else if(Copy_u8Row==1 && Copy_u8Col<16)
	{
		LCD_enuSendCommand((Copy_u8Col & 0x0F)|0xC0);
	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
void LCD_voidDislayNumber	(u32 Copy_u32Number)
{

	u32 Copy_u32Reversed=1;

		while(Copy_u32Number!=0)
			{
			Copy_u32Reversed=(Copy_u32Reversed*10)+(Copy_u32Number%10);
			Copy_u32Number/=10;
			}
		while(Copy_u32Reversed!=1)
			{
			LCD_enuDisplayChar((Copy_u32Reversed%10)+'0');
			Copy_u32Reversed/=10;
			}
}
static void LCD_vidLatch(u8 Copy_u8Data)
{
	// set rw as write operation , EN is low
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_LOW);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_LOW);
	//write Data
	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data>>4)&1));

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Data>>0)&1));

#elif LCD_MODE == FOUR_BIT

#endif

	// Enable latch
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_LOW);


	_delay_ms(10);
}


static inline void LCD_invidSendCommand(u8 Copy_u8Command)
{
	// set rs as command
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_LOW);
	// set rw as write operation , EN is low
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_LOW);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_LOW);
	//write Data
	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Command>>7)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Command>>6)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Command>>5)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Command>>4)&1));
	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Command>>3)&1));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Command>>2)&1));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Command>>1)&1));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Command>>0)&1));

	// Enable latch
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_LOW);

}


