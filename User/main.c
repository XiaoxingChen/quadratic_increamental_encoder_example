#include "STM32F1.h"

u16	Parameter = 512;																	//输入编码器线数
u16 Count,Old_Count;

int main(void)
{
	delay_init();	    	 																//延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 																//串口初始化为115200
	LCD_Init();			   																	//初始化LCD  
	TIM4_Init();																				//初始化TIM4为编码器借口模式
	POINT_COLOR=BLUE;																		//字体颜色
	LCD_ShowString(75,150,200,16,16,"Count:");
	LCD_ShowNum(125,150,0,1,16);
	LCD_ShowNum(135,150,0,1,16);
	LCD_ShowNum(145,150,0,1,16);
	LCD_ShowNum(155,150,0,1,16);
  while(1)
	{
		Old_Count = Count;																//获取先前的计数值
		Count = TIM4->CNT;																//获取编码器当前数值
		if(Old_Count != Count)														//如果先前的计数值与当前计数值不相等，说明编码器已转动打印当前数值
		{
			printf("val = %d\n",Count);										//串口打印数值
			LCD_ShowNum(125,150,Count/1000,1,16);						//液晶显示数值
			LCD_ShowNum(135,150,(Count%1000)/100,1,16);
			LCD_ShowNum(145,150,(Count%100)/10,1,16);
			LCD_ShowNum(155,150,Count%10,1,16);
		}		
	}
}
