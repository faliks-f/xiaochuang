
// ADC ��ͨ���ɼ�����ʹ��DMA��һ��ֻ��ADC2������ʹ�ã���ΪADC2����ʹ��DMA

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"

extern __IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal;        

volatile int measureFlag = 0;

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
	// ���ô���
	USART_Config();
	
	// ADC ��ʼ��
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
