#include "Hardware.h"
#include "IOConfig.h"


void GPIO_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOE, ENABLE);//

  //USART1 
  GPIO_InitStructure.GPIO_Pin = USART1_TX | USART1_RX;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉                    
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB
	
  //USART2 陀螺仪
  GPIO_InitStructure.GPIO_Pin = USART2_TX | USART2_RX;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD
	
  //USART3 
  GPIO_InitStructure.GPIO_Pin = USART3_TX | USART3_RX;
  GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB
	
	//USART6 
  GPIO_InitStructure.GPIO_Pin = USART6_TX | USART6_RX;
  GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC
	
	//电机控制引脚
  GPIO_InitStructure.GPIO_Pin = LMOTORF_GPIO1	 | LMOTORF_GPIO2	|	LMOTORB_GPIO1	 | LMOTORB_GPIO2 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA
	GPIO_ResetBits(GPIOA,LMOTORF_GPIO1	|	LMOTORF_GPIO2	|	LMOTORB_GPIO1	|	LMOTORB_GPIO2	);
	
	GPIO_InitStructure.GPIO_Pin = RMOTORF_GPIO1	 | RMOTORF_GPIO2	|	RMOTORB_GPIO1	 | RMOTORB_GPIO2 ;															;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉    
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE  
  GPIO_ResetBits(GPIOE,RMOTORF_GPIO1	|	RMOTORF_GPIO2	|	RMOTORB_GPIO1	|	RMOTORB_GPIO2	);
	
	//电机PWM TIM3_CH3 TIM3_CH4
	GPIO_InitStructure.GPIO_Pin = LMOTORF_PWM	 | LMOTORB_PWM ;															;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉    
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOE  
  GPIO_ResetBits(GPIOB,LMOTORF_PWM	 | LMOTORB_PWM	);
	
	
  //电机PWM TIM9_CH1 TIM9_CH2
	GPIO_InitStructure.GPIO_Pin = RMOTORF_PWM	 | RMOTORB_PWM ;															;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//500MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉    
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE  
  GPIO_ResetBits(GPIOE,RMOTORF_PWM	 | RMOTORB_PWM	);
  
  //电机编码器 PA0 PA1 PA6 PA7	PA9
	GPIO_InitStructure.GPIO_Pin = LMOTORF_ENCONDER1	 
															| LMOTORB_ENCONDER1	
															| LMOTORB_ENCONDER2	
															|	RMOTORF_ENCONDER1	
															|	RMOTORF_ENCONDER2;															;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉    
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA 
//  GPIO_ResetBits(GPIOA,LMOTORF_ENCONDER1	 
//															| LMOTORB_ENCONDER1	
//															| LMOTORB_ENCONDER2	
//															|	RMOTORF_ENCONDER1	
//															|	RMOTORF_ENCONDER2	);
															
	GPIO_PinAFConfig(GPIOA,LMOTORF_ENCONDER1,GPIO_AF_TIM1); 	//GPIOA9配置成TIM1_CH1
  GPIO_PinAFConfig(GPIOA,LMOTORB_ENCONDER1,GPIO_AF_TIM2); 	//GPIOA9配置成TIM2_CH1
	GPIO_PinAFConfig(GPIOA,LMOTORB_ENCONDER2,GPIO_AF_TIM2); 	//GPIOA9配置成TIM2_CH2
	GPIO_PinAFConfig(GPIOA,RMOTORF_ENCONDER1,GPIO_AF_TIM3); 	//GPIOA9配置成TIM3_CH1
	GPIO_PinAFConfig(GPIOA,RMOTORF_ENCONDER2,GPIO_AF_TIM3); 	//GPIOA9配置成TIM3_CH2
	
	//电机编码器 PE9
	GPIO_InitStructure.GPIO_Pin = LMOTORF_ENCONDER2 ;															;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉    
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE  
//  GPIO_ResetBits(GPIOE,LMOTORF_ENCONDER2	);
	
	GPIO_PinAFConfig(GPIOE,RMOTORF_ENCONDER2,GPIO_AF_TIM1); 	//GPIOE9配置成TIM1_CH2
	
	//电机编码器 PD12 PD13
	GPIO_InitStructure.GPIO_Pin = RMOTORB_ENCONDER1	 | RMOTORB_ENCONDER2 ;															;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉    
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD  
//  GPIO_ResetBits(GPIOD,RMOTORB_ENCONDER1	 | RMOTORB_ENCONDER2	);

  GPIO_PinAFConfig(GPIOD,RMOTORB_ENCONDER1,GPIO_AF_TIM4); 	//GPIOD12配置成TIM4_CH1
	GPIO_PinAFConfig(GPIOD,RMOTORB_ENCONDER2,GPIO_AF_TIM4); 	//GPIOD13配置成TIM4_CH2
}

void TIMX_Config(u16 arr,u16 psc)
{ 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE); 
		/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = arr;//定时器周期
	TIM_TimeBaseStructure.TIM_Prescaler = psc;//预分频器
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;//时钟分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//TIM向上计数模式
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM9, &TIM_TimeBaseStructure);

	 /*LB PWM模式配置*/
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = LBP1_duty	;      //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  	  //当定时器计数值小于CCR1_Val时为高电平
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 //使能通道3
	
	/*LF PWM模式配置*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = LFP2_duty	;      //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  	  //当定时器计数值小于CCR1_Val时为高电平
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);	 //使能通道4
	
	/*RB PWM模式配置*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = RBP1_duty	;    //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  	  //当定时器计数值小于CCR1_Val时为高电平
  TIM_OC1Init(TIM9, &TIM_OCInitStructure);	 //使能通道1
	
	/*RF PWM模式配置*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//比较输出使能
  TIM_OCInitStructure.TIM_Pulse = RFP2_duty	;    //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  	  //当定时器计数值小于CCR1_Val时为高电平
	TIM_OC2Init(TIM9, &TIM_OCInitStructure);	 //使能通道2
	
	
	TIM_CtrlPWMOutputs(TIM3,ENABLE);	//MOE 主输出使能
  TIM_CtrlPWMOutputs(TIM9,ENABLE);	//MOE 主输出使能


	/*使能通道重载*/
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIM3在ARR上的预装载寄存器
	TIM_ARRPreloadConfig(TIM9, ENABLE); //使能TIM9在ARR上的预装载寄存器
	
	
	
	// 使能定时器
	TIM_Cmd(TIM3, ENABLE);	
	TIM_Cmd(TIM9, ENABLE);	
}
void Encoder_Init(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //使能定时器1的时钟	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能定时器2的时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //使能定时器3的时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能定时器4的时钟
	
	//TIM1 是属于高级定时器
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; 			// 预分频器 
	TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //设定计数器自动重装值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM向上计数 
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;//重复计数设置	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM1,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);//使用编码器模式3
	
	
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 0;
	TIM_ICInit(TIM1, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//清除TIM的更新标志位
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	
	TIM_SetCounter(TIM1,0);
	TIM_Cmd(TIM1, ENABLE); 
 
 //TIM2
 
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);		//
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0; 			// 预分频器 
	TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //设定计数器自动重装值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM向上计数  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);//使用编码器模式3
	
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 0;
	TIM_ICInit(TIM2, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除TIM的更新标志位
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	TIM_SetCounter(TIM2,0);
	TIM_Cmd(TIM2, ENABLE); 
 
 //TIM3
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // 预分频器 
	TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //设定计数器自动重装值65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM向上计数  
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 0;
	TIM_ICInit(TIM3, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清除TIM的更新标志位
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	TIM_SetCounter(TIM3,0);
	TIM_Cmd(TIM3, ENABLE); 

//TIM4
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // 预分频器 
	TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //设定计数器自动重装值65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM向上计数  
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 0;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);//清除TIM的更新标志位
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	
	TIM_SetCounter(TIM4,0);
	TIM_Cmd(TIM4, ENABLE); 
}

/**************************************************************************
函数功能：单位时间读取编码器计数
入口参数：定时器
返回  值：速度值
**************************************************************************/
int Read_Encoder(u8 TIMX)
{
   int Encoder_TIM;    
   switch(TIMX)
	 {
		 case 1:  Encoder_TIM= (short)TIM1 -> CNT;  TIM1 -> CNT=0;break;
		 case 2:  Encoder_TIM= (short)TIM2 -> CNT;  TIM2 -> CNT=0;break;
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;	
		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0;break;
		 default: Encoder_TIM=0;
	 }
		return Encoder_TIM;
}
/**************************************************************************
函数功能：定时器中断服务函数
入口参数：无
返回  值：无
**************************************************************************/
void TIM1_IRQHandler(void) 
{ 	    	  	     
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)//检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update); //清除TIM1的中断待处理位:TIM 中断源 
 }	     
} 

void TIM2_IRQHandler(void)
{ 		    		  			    
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update); //清除TIM2的中断待处理位:TIM 中断源 
 }	     
}

void TIM3_IRQHandler(void)
{ 		    		  			    
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)//检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除TIM3的中断待处理位:TIM 中断源 
 }	     
}


void TIM4_IRQHandler(void)
{ 		    		  			    
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)//检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update); //清除TIM4的中断待处理位:TIM 中断源 
 }	   
}



//void USART_Config(USART_TypeDef* USARTx, u32 rate)
//{ 
//	
//  USART_InitTypeDef USART_InitStructure;
//	USART_InitStructure.USART_BaudRate = rate;						//串口波特率
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//数据位8位
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;			//停止位1位
//	USART_InitStructure.USART_Parity = USART_Parity_No;				//无校验位
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //无硬件流控
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//收发模式
//	/* Configure USARTx */
//	USART_Init(USARTx, &USART_InitStructure);							//配置串口参数函数
//	/* Enable USART1 Receive and Transmit interrupts */
//	USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);                      //使能接收中断
//	USART_Cmd(USARTx, ENABLE);
//	USART_ClearFlag(USARTx, USART_FLAG_TC);
//}

//void NVIC_Configuration(void)
//{
//	NVIC_InitTypeDef NVIC_InitStructure;

//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); //嵌套向量中断控制器组选择 

//  
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			     	//设置串口1中断
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;					//抢断优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能中断
//	NVIC_Init(&NVIC_InitStructure);

//	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			     	//设置串口2中断
//	NVIC_Init(&NVIC_InitStructure);

//	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;			     	//设置串口3中断
//	NVIC_Init(&NVIC_InitStructure);

//	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;			     	//设置串口5中断
//	NVIC_Init(&NVIC_InitStructure);

//	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;			     	//设置串口4中断
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_Init(&NVIC_InitStructure);

//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
//	NVIC_Init(&NVIC_InitStructure);

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

//	//NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //抢占式中断优先级设置为1
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;         //响应式中断优先级设置为1
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;        //使能中断
//	NVIC_Init(&NVIC_InitStructure);

//}


