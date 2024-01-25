/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Calcultor.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 keypad_button=0;
sint16 num[10]={};
sint16 operation[5]={};
uint8 cnt_op=0;
uint8 cnt_num=0;
sint16 Result=0; 
uint8 i=0;
uint8 j=0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Calculator_init(void){
		PORT_Init();
		LCD_Init();
		Keypad_Init();
		
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Operations(void){
	keypad_button=Keypad_GetValue();
	if(keypad_button!=0){
		LCD_WriteChar(keypad_button);
		if(keypad_button=='+'||keypad_button=='-'||keypad_button=='/'||keypad_button=='*'){
			operation[cnt_op]=keypad_button;
			cnt_op++;
			cnt_num++;
			
		}
	else if(keypad_button>=48 && keypad_button<=57){
		Numbers();
	}	
	else if(keypad_button=='='){
		equal();
	}
	else if(keypad_button=='c'){
		Clear();
	}
	
}
	}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Numbers(void){
	num[cnt_num]*=10;
	num[cnt_num]+=(keypad_button-48);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Clear(void){
	
		LCD_Clear();
		cnt_num=0;
		cnt_op=0;
		i=0;
		j=0;
		Result=0;
		
		while(cnt_op<5){
			operation[cnt_op++]=0;
		}
		while(cnt_num<10){
			num[cnt_num++]=0;
		}
		cnt_num=0;
		cnt_op=0;
		
	
}


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void multi_sequance(void){

		for(i=0;i<cnt_op;i++){
			if(operation[i]=='*'){
				while(operation[i]=='*'){
					Multi_equ();
					
				}
				
			}
			else if(operation[i]=='/'){
				while(operation[i]=='/'){
					Division_Equ();
				}
			}
		}
		
	 
	 Result=num[0];
	 
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Application (void){
	Operations();
}




		
void Multi_equ(void){
  num[i]*= num[i+1];
  for(j=i;j<cnt_op;j++){
	  operation[j]=operation[j+1];
	  num[j+1]=num[j+2];
  }
  
  
	
}

void Division_Equ(void){
	num[i]/=num[i+1];
	for(j=i;j<cnt_op;j++){
		operation[j]=operation[j+1];
		num[j+1]=num[j+2];
	}
	
}

void Sum_Sub_Sequance(void){
  for(i=0;i<cnt_op;i++){
	  if(operation[i]=='+'){
		  Result+=num[i+1];

	  }
	  else if(operation[i]=='-'){
		  Result-=num[i+1];
  }
}
}
void equal(void){

	multi_sequance();
	Sum_Sub_Sequance();
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WiteInteger(Result);
	num[0]=Result;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
