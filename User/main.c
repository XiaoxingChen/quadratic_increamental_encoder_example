#include "STM32F1.h"

u16	Parameter = 512;																	//�������������
u16 Count,Old_Count;

int main(void)
{
	delay_init();	    	 																//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 																//���ڳ�ʼ��Ϊ115200
	LCD_Init();			   																	//��ʼ��LCD  
	TIM4_Init();																				//��ʼ��TIM4Ϊ���������ģʽ
	POINT_COLOR=BLUE;																		//������ɫ
	LCD_ShowString(75,150,200,16,16,"Count:");
	LCD_ShowNum(125,150,0,1,16);
	LCD_ShowNum(135,150,0,1,16);
	LCD_ShowNum(145,150,0,1,16);
	LCD_ShowNum(155,150,0,1,16);
  while(1)
	{
		Old_Count = Count;																//��ȡ��ǰ�ļ���ֵ
		Count = TIM4->CNT;																//��ȡ��������ǰ��ֵ
		if(Old_Count != Count)														//�����ǰ�ļ���ֵ�뵱ǰ����ֵ����ȣ�˵����������ת����ӡ��ǰ��ֵ
		{
			printf("val = %d\n",Count);										//���ڴ�ӡ��ֵ
			LCD_ShowNum(125,150,Count/1000,1,16);						//Һ����ʾ��ֵ
			LCD_ShowNum(135,150,(Count%1000)/100,1,16);
			LCD_ShowNum(145,150,(Count%100)/10,1,16);
			LCD_ShowNum(155,150,Count%10,1,16);
		}		
	}
}
