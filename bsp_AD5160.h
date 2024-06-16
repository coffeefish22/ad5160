#ifndef _BSP_AD5160_H_
#define _BSP_AD5160_H_

#define HVW_DELAY		10

#define hvw_sck_rcc                    RCC_APB2Periph_GPIOD
#define hvw_sck_gpio                   GPIOD
#define hvw_sck_pin                    (GPIO_Pin_7)

#define hvw_sdi_rcc                    RCC_APB2Periph_GPIOD
#define hvw_sdi_gpio                   GPIOD
#define hvw_sdi_pin                    (GPIO_Pin_6)

#define hvw_cs_rcc                    RCC_APB2Periph_GPIOD
#define hvw_cs_gpio                   GPIOD
#define hvw_cs_pin                    (GPIO_Pin_5)

#define HVW_SCK_L()   GPIO_ResetBits(hvw_sck_gpio,hvw_sck_pin )  
#define HVW_SCK_H()  	GPIO_SetBits(hvw_sck_gpio,hvw_sck_pin )


#define HVW_SDI_L()   GPIO_ResetBits(hvw_sdi_gpio,hvw_sdi_pin )  
#define HVW_SDI_H()  	GPIO_SetBits(hvw_sdi_gpio,hvw_sdi_pin )

#define HVW_CS_L()   GPIO_ResetBits(hvw_cs_gpio,hvw_cs_pin )  
#define HVW_CS_H()  	GPIO_SetBits(hvw_cs_gpio,hvw_cs_pin )

extern void rt_hw_ad5160_init(void);
extern void setAd5160(unsigned char in);

#endif
