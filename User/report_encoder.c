#include "report_encoder.h"

int put_char(uint8_t ch)
{
    while((USART1->SR & 0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;    
}

uint8_t sum_check(uint8_t* start, uint8_t len)
{
    uint8_t sum = 0;
		int i;
    for(i = 0; i < len; i++)
    {
        sum += start[i];
    }
    return sum;
}

void ReportEncoder(uint16_t value)
{
    const uint8_t buff_len = 8;
		int i;
    uint8_t data_idx = 4;
    uint8_t sum_check_idx = 6;
    uint8_t buff[buff_len] = {0xa5, 0x5a, 0x06, 0xa8, 0xff, 0xff, 0x00, 0xaa};
    *((uint16_t*)&buff[data_idx]) = value;
    buff[sum_check_idx] = sum_check(buff + 2, 4);

    for(i = 0; i < buff_len; i++)
    {
        put_char(buff[i]);
    }
}
