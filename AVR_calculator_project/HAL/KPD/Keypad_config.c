/*
 * Keypad_config.c
 *
 *  Created on: july 11, 2023
 *      Author: khalid
 */

#include "../../SERVICES/Std_Types.h"
#include "../../SERVICES/error_status.h"
#include "../../MCAL/DIO_int.h"
#include "Keypad_config.h"





KPD_t KPD_AstrKPDConfig[NUM_OF_KPDs] = {
	{
		{
				{DIO_u8PORTC, DIO_u8PIN0},
				{DIO_u8PORTC, DIO_u8PIN1},
				{DIO_u8PORTC, DIO_u8PIN2},
				{DIO_u8PORTC, DIO_u8PIN3}
		},
		{
				{DIO_u8PORTC, DIO_u8PIN4},
				{DIO_u8PORTC, DIO_u8PIN5},
				{DIO_u8PORTC, DIO_u8PIN6},
				{DIO_u8PORTC, DIO_u8PIN7}
		}
	}
};
u8 KPAD_Auint8PadKeys[NUM_OF_ROWS][NUM_OF_COLUMNS] = PAD_KEY_VALUES;
