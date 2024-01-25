/*
 * PORT_LCfg.c
 *
 * Created: 9/16/2023 12:15:59 PM
 *  Author: amgad
 */ 
#include "PORT_LCfg.h"


PIN_PARAMETERS PORT_Intialization[DEFINED_PINS] = 
{
	/*LCD Pins*/
	{  PORTA_PIN1    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN2    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN3    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN4    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN5    ,  PIN_DIR_OUTPUT   },
	{  PORTA_PIN6    ,  PIN_DIR_OUTPUT   },
	/*KeyPad Pins*/
	{  PORTB_PIN4    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN5    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN6    ,  PIN_DIR_OUTPUT   },
	{  PORTB_PIN7    ,  PIN_DIR_OUTPUT   },
	{  PORTD_PIN2    ,  PIN_DIR_INPUT   },
	{  PORTD_PIN3    ,  PIN_DIR_INPUT   },
	{  PORTD_PIN4    ,  PIN_DIR_INPUT   },
	{  PORTD_PIN5    ,  PIN_DIR_INPUT   }
};