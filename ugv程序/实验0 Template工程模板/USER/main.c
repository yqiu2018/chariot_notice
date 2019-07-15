#include "stm32f4xx.h"
#include "delay.h"
#include "IOConfig.h"
#include "Hardware.h"



int main(void)
{
	
volatile	int LF_Encoder,LB_Encoder,RF_Encoder,RB_Encoder;          //±àÂëÆ÷µÄÂö³å¼ÆÊý
	
  GPIO_Config();
	Encoder_Init();
	TIMX_Config(8399,1);
  while(1){
//		GPIO_SetBits(GPIOA,LMOTORF_GPIO1	 	|	LMOTORB_GPIO1	);
//		GPIO_SetBits(GPIOE,RMOTORF_GPIO1	 	|	RMOTORB_GPIO1	 );
//		
//    GPIO_ResetBits(GPIOA, LMOTORF_GPIO2	|	 LMOTORB_GPIO2);
//		GPIO_ResetBits(GPIOE, RMOTORF_GPIO2	|	 RMOTORB_GPIO2);
		  GPIO_SetBits(GPIOA,LMOTORF_GPIO1	 	);
		  GPIO_SetBits(GPIOA,LMOTORB_GPIO1	 	);
		  GPIO_SetBits(GPIOE,RMOTORF_GPIO1	 	);
		  GPIO_SetBits(GPIOE,RMOTORB_GPIO1	 	);
		
		LF_Encoder=Read_Encoder(1);
		
		LB_Encoder=Read_Encoder(2);
		
		RF_Encoder=Read_Encoder(3);
		
		RB_Encoder=Read_Encoder(4);
		
   
	
	}
}



