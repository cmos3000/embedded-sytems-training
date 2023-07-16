/*
 * Keypad_prog.c
 *
 *  Created on: july 11, 2023
 *      Author: khalid
 */
#include "../../SERVICES/Std_Types.h"
#include "../../SERVICES/error_status.h"
#include "Keypad_priv.h"
#include "Keypad_config.h"
#include "../../MCAL/DIO_int.h"
#include "util/delay.h"

extern u8 KPAD_Auint8PadKeys[NUM_OF_ROWS][NUM_OF_COLUMNS];

ES_t KPD_init(KPD_t * Copy_pstrKPDConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrKPDConfig !=NULL)
	{		Local_enuErrorState = ES_OK;
		for(u8 Local_u8Iterator=0;Local_u8Iterator<NUM_OF_KPDs;Local_u8Iterator++)
		{
			for(u8 Local_u8Iterator1=0;Local_u8Iterator1<NUM_OF_ROWS;Local_u8Iterator1++)
			{
				Local_enuErrorState = DIO_enuSetPinDirection(Copy_pstrKPDConfig[Local_u8Iterator].KPD_strRows[Local_u8Iterator1].Row_u8PortID,
													   	     Copy_pstrKPDConfig[Local_u8Iterator].KPD_strRows[Local_u8Iterator1].Row_u8PinID,
														     DIO_INPUT);
				Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrKPDConfig[Local_u8Iterator].KPD_strRows[Local_u8Iterator1].Row_u8PortID,
														 Copy_pstrKPDConfig[Local_u8Iterator].KPD_strRows[Local_u8Iterator1].Row_u8PinID,
														 DIO_PULL_UP);
			}
			for(u8 Local_u8Iterator1=0;Local_u8Iterator1<NUM_OF_ROWS;Local_u8Iterator1++)
			{
				Local_enuErrorState = DIO_enuSetPinDirection(Copy_pstrKPDConfig[Local_u8Iterator].KPD_strColumns[Local_u8Iterator1].Col_u8PortID,
															 Copy_pstrKPDConfig[Local_u8Iterator].KPD_strColumns[Local_u8Iterator1].Col_u8PinID,
															 DIO_OUTPUT);
				Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrKPDConfig[Local_u8Iterator].KPD_strColumns[Local_u8Iterator1].Col_u8PortID,
														 Copy_pstrKPDConfig[Local_u8Iterator].KPD_strColumns[Local_u8Iterator1].Col_u8PinID,
														 DIO_HIGH);
			}
		}
	}else {Local_enuErrorState=ES_NULL_POINTER;}
	return Local_enuErrorState;
}

ES_t KPD_enuGetPressedKey(KPD_t* Copy_pstrKPDConfig, u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	*Copy_pu8Value=0;
if((Copy_pstrKPDConfig !=NULL) ||(Copy_pu8Value !=NULL) )
 {		Local_enuErrorState = ES_OK;

	u8 Local_uint8GetKey;

	for (u8 Local_u8ColIterator=0;Local_u8ColIterator<NUM_OF_COLUMNS;Local_u8ColIterator++)
	{
		/*Activate for Current Column*/
		Local_enuErrorState=DIO_enuSetPinValue(Copy_pstrKPDConfig->KPD_strColumns[Local_u8ColIterator].Col_u8PortID,
											   Copy_pstrKPDConfig->KPD_strColumns[Local_u8ColIterator].Col_u8PinID,
											   DIO_LOW);
	 for(u8 Local_u8RowIterator=0;Local_u8RowIterator<NUM_OF_ROWS;Local_u8RowIterator++)
		 {
			Local_enuErrorState=DIO_enuGetPinValue(Copy_pstrKPDConfig->KPD_strRows[Local_u8RowIterator].Row_u8PortID,
													Copy_pstrKPDConfig->KPD_strRows[Local_u8RowIterator].Row_u8PinID,
													&Local_uint8GetKey);
		/*Check if switch is pressed*/
			if(!Local_uint8GetKey)
			 {
				_delay_ms(50);

			while(!Local_uint8GetKey)
				{
				Local_enuErrorState=DIO_enuGetPinValue(Copy_pstrKPDConfig->KPD_strRows[Local_u8RowIterator].Row_u8PortID,
																		   Copy_pstrKPDConfig->KPD_strRows[Local_u8RowIterator].Row_u8PinID,
																		   &Local_uint8GetKey);
				}
			*Copy_pu8Value=KPAD_Auint8PadKeys[Local_u8RowIterator][Local_u8ColIterator];
			break;
			 }
		 }
		Local_enuErrorState=DIO_enuSetPinValue(Copy_pstrKPDConfig->KPD_strColumns[Local_u8ColIterator].Col_u8PortID,
											   Copy_pstrKPDConfig->KPD_strColumns[Local_u8ColIterator].Col_u8PinID,
											   DIO_HIGH);
	 }
 }else {Local_enuErrorState=ES_NULL_POINTER;}
	return Local_enuErrorState;
}





