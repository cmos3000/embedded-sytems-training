/*
 * LCD_int.h
 *
 *  Created on: july 8, 2023
 *      Author: khalid
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuDisplayString(u8 *Copy_pu8Data);

ES_t LCD_enuSetPosition(u8 Copy_u8Row,u8 Copy_u8Col);

void LCD_voidDislayNumber	(u32 Copy_u32Number);

#endif /* LCD_INT_H_ */
