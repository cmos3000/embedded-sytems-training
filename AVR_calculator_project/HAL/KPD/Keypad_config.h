/*
 * Keypad_config.h
 *
 *  Created on: july 11, 2023
 *      Author: khalid
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define NUM_OF_KPDs		1

#define NUM_OF_COLUMNS	4
#define NUM_OF_ROWS		4

typedef struct
{
	struct
	{
		u8 Row_u8PortID;
		u8 Row_u8PinID;
	}KPD_strRows[NUM_OF_ROWS];
	struct
	{
		u8 Col_u8PortID;
		u8 Col_u8PinID;
	}KPD_strColumns[NUM_OF_COLUMNS];
}KPD_t;

#define PAD_KEY_VALUES	{{'7','8','9','/'},\
						 {'4','5','6','*'},\
						 {'1','2','3','-'},\
						 {'c','0','=','+'}}

#endif /* KEYPAD_CONFIG_H_ */
