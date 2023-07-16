/*
 * Calculator.c

 *
 *  Created on: july 13, 2023
 *      Author: khalid
 */


#include "../SERVICES/Std_Types.h"
#include "../SERVICES/error_status.h"
#include "../MCAL/DIO_int.h"
#include "../HAL/KPD/Keypad_config.h"
#include "../HAL/KPD/Keypad_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "AVR_calculator_project.h"
#include <util/delay.h>
extern KPD_t KPD_AstrKPDConfig[NUM_OF_KPDs];
u8 Glo_Iterator = 0 ;
int main(void)
{
LCD_enuInit();
KPD_init(KPD_AstrKPDConfig);
u8  Loc_operator1 , Loc_operator2,Local_u8GetPressed ;
u8 	Flag = 1 ;
LCD_enuDisplayString((u8*)"AVR_calculator");
_delay_ms(1000);
LCD_enuSendCommand(0x01);
while(1)
	{
KPD_enuGetPressedKey(KPD_AstrKPDConfig,&Local_u8GetPressed);
		if(Flag == 1)
		{
			Flag = 0 ;
		LCD_enuSendCommand(0x01);
		u16 Local_u16Op1 = Calc_u16GetOp( &Loc_operator1);

		u16 Local_u16Op2 = Calc_u16GetOp( &Loc_operator2 );
		Glo_Iterator = 0 ;
		u16 Result = Calc_u16OpFunc(Local_u16Op1 ,Local_u16Op2 , Loc_operator1 );

		LCD_voidDislayNumber(Result);
		}
		else
		{
			if(Local_u8GetPressed =='c')
			{
				Flag = 1;
			}
		}
	}
    return 0;
}
u16 Calc_u16GetOp (u8* Copy_pu8Opertor )
{
	u16 Local_u16Value = 0 ;
	u8 Local_u8PressedKey;
	u8 Local_Iterator = 0 ;
	u8 Local_AValues[5]= {0};
	while(1)
	{
		do
		{
			KPD_enuGetPressedKey(KPD_AstrKPDConfig,&Local_u8PressedKey);
		}while(!Local_u8PressedKey);
		if(Local_u8PressedKey != 0xff)
		{
			if(Local_u8PressedKey == 'c')
			{
				Glo_Iterator--;
				LCD_enuSetPosition(0,Glo_Iterator);
				LCD_enuDisplayChar(' ');
				LCD_enuSetPosition(0,Glo_Iterator);
				Local_Iterator-- ;
			}
			else
			{
				LCD_enuDisplayChar(Local_u8PressedKey);
				Local_AValues[Local_Iterator] = Local_u8PressedKey ;
				Local_Iterator++ ;
				Glo_Iterator++;
			}
			if(Local_u8PressedKey == '*' || Local_u8PressedKey =='/' || Local_u8PressedKey == '+' ||
					Local_u8PressedKey == '-' || Local_u8PressedKey == '=')
			{
				break ;
			}
		}
	}
u8 j = 0 ;
	while(j != Local_Iterator-1 )
	{
		Local_u16Value *= 10 ;
		Local_u16Value = Local_u16Value + (u16)(Local_AValues[j] -'0');
		j++;
	}
	*Copy_pu8Opertor = Local_AValues[j];
	return Local_u16Value ;
}
u16 Calc_u16OpFunc ( u16 Copy_u16Op1 , u16 Copy_u16Op2 , u8 Copy_u8Operator )
{
	u16 LOC_result = 0 ;
	switch(Copy_u8Operator)
	{
	case '+' : LOC_result = Copy_u16Op1 + Copy_u16Op2 ;
	break;
	case '-':	LOC_result = Copy_u16Op1 - Copy_u16Op2 ;
	break;
	case '*':	LOC_result = Copy_u16Op1* Copy_u16Op2 ;
	break ;
	case '/':	LOC_result = Copy_u16Op1 / Copy_u16Op2 ;
	break;
	default : break;
	}
	return LOC_result ;
}

