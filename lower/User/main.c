
// ADC 单通道采集，不使用DMA，一般只有ADC2才这样使用，因为ADC2不能使用DMA

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"

extern __IO uint16_t ADC_ConvertedValue;

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal;        

volatile int measureFlag = 0;

// 软件延时
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	// 配置串口
	USART_Config();
	
	// ADC 初始化
	ADCx_Init();
	while (1)
	{
//		if (sendFlag)
//		{
//			uint16_t send;
//			ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; 
//			send = (uint16_t)(ADC_ConvertedValueLocal * 10);
//			//send = (uint16_t)(ADC_ConvertedValueLocal * 10);
//			Usart_SendHalfWord(DEBUG_USARTx, send);
//			sendFlag = 0;
//		}
	}
}
/*********************************************END OF FILE**********************/
