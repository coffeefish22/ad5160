#include <rtthread.h>
#include <rthw.h>
#include "stm32f10x.h"
#include "bsp_AD5160.h"
#ifdef USE_AD5160
void rt_hw_ad5160_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
//	DAC_InitTypeDef DAC_InitType; 

    RCC_APB2PeriphClockCmd(hvw_sck_rcc|hvw_sdi_rcc|hvw_cs_rcc,ENABLE);

	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin   = hvw_sck_pin;
    GPIO_Init(hvw_sck_gpio, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin   = hvw_sdi_pin;
    GPIO_Init(hvw_sdi_gpio, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin   = hvw_cs_pin;
    GPIO_Init(hvw_cs_gpio, &GPIO_InitStructure);


}


//����ad5160���
void setAd5160(unsigned char in)
{
	unsigned char i;
	unsigned char delay;
	unsigned char t = in;
	
	//ѡ��ad5160
	HVW_CS_L();

	HVW_SCK_H();
	delay=HVW_DELAY;
	while(delay--);

	HVW_SCK_L();
	delay=HVW_DELAY;
	while(delay--);


	for(i=0;i<8;i++)
	{
		if(t & 0x80)
		{
			HVW_SDI_H();
		}
		else
		{
			HVW_SDI_L();
		}

		t<<=1;
		
		delay=HVW_DELAY;
		while(delay--);
		
		HVW_SCK_H();
		delay=HVW_DELAY;
		while(delay--);
		
		HVW_SCK_L();
		delay=HVW_DELAY;
		while(delay--);
	}

//������д��AD5160
	HVW_CS_H();
}

#endif



