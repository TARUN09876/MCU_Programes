//PC0 -PC7  --D0-D7 IN LCD
//PB5 -RS
//PB6 -RW
//PB7 -EN

#include <stdint.h>
#include "stm32f4xx.h"

#define RS 0x20 //0010 0000
#define RW 0x40 //0100 0000
#define EN 0x80  //1000 0000

unsigned char Message[]=("HELLO WORLD...");
void GPIO_Init(void);
void LCD_Command(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_Init(void);
void delayMs(int delay);


int main(void)
{
	{
	uint32_t *portcAHB1ENR =(uint32_t*)0x40023830;
	uint32_t *portcMODER=(uint32_t*)0x40020800;
	uint32_t *portcODR=(uint32_t*)0x40020814;
	uint32_t *portcIDR=(uint32_t*)0x40020810;

	uint32_t *portPUPDR=(uint32_t*)0x4002080C;


	// Enable the peripheral clock of GPIOC Register
	//*portcAHB1ENR  |=0X04;
	*portcAHB1ENR  |=(1<<2);
	//configure ROW GPIO IN OUTPUT MODE  PC0-PC3

	//configure COLUMN GPIO IN INPUT MODE PC4-PC7



	*portPUPDR &= 0XFFFF0000;
	*portPUPDR |= 0X00005500;

/////////////////

	*portcMODER &= 0XFFFF0000;
		*portcMODER |= 0X00000055;
	/////
	*portcODR|=0x0f;

	//MAKE R1 LOW
	while(1)
	{

		*portcODR|=0x0f;
	*portcODR &= ~(1<<0);

	if(!(*portcIDR & (1 <<4 )))
	{
		//key is pressed
		delay();
		LCD_display("1 \n");
	}
	/*if(!(*portcIDR & (1 <<5 )))
		{
			//key is pressed
		delay();
		LCD_display(("2 \n");
		}
	if(!(*portcIDR & (1 <<6 )))
			{
				//key is pressed
		delay();
		LCD_display(("3 \n");
			}
	if(!(*portcIDR & (1 <<7 )))
			{
				//key is pressed
		delay();
		LCD_display(("4 \n");
			}
//MAKE R2 LOW
	*portcODR|=0x0f;
	*portcODR &= ~(1<<1);
	if(!(*portcIDR & (1 <<4 )))
		{
			//key is pressed
			delay();
			LCD_display(("5 \n");
		}
		if(!(*portcIDR & (1 <<5 )))
			{
				//key is pressed
			delay();
			LCD_display(("6 \n");
			}
		if(!(*portcIDR & (1 <<6 )))
				{
					//key is pressed
			delay();
			LCD_display(("7 \n");
				}
		if(!(*portcIDR & (1 <<7 )))
				{
					//key is pressed
			delay();
			LCD_display(("8 \n");
				}
		//MAKE R3 LOW
		*portcODR|=0x0f;
			*portcODR &= ~(1<<2);
			if(!(*portcIDR & (1 <<4 )))
					{
						//key is pressed
						delay();
						LCD_display(("9 \n");
					}
					if(!(*portcIDR & (1 <<5 )))
						{
							//key is pressed
						delay();
						LCD_display(("10 \n");
						}
					if(!(*portcIDR & (1 <<6 )))
							{
								//key is pressed
						delay();
						LCD_display(("11 \n");
							}
					if(!(*portcIDR & (1 <<7 )))
							{
								//key is pressed
						delay();
						LCD_display(("12 \n");
							}
					//MAKE R4 LOW
					*portcODR|=0x0f;
					*portcODR &= ~(1<<3);
								if(!(*portcIDR & (1 <<4 )))
										{
											//key is pressed
											delay();
											LCD_display(("13 \n");
										}
										if(!(*portcIDR & (1 <<5 )))
											{
												//key is pressed
											delay();
											LCD_display(("14 \n");
											}
										if(!(*portcIDR & (1 <<6 )))
												{
													//key is pressed
											delay();
											LCD_display(("15 \n");
												}
										if(!(*portcIDR & (1 <<7 )))
												{
													//key is pressed
											delay();
											LCD_display(("16 \n");*/
												}

//	delay();


}
}



	LCD_Init();
	/* Loop forever */

	for(;;);
}

void GPIO_Init(void)
{
	RCC->AHB1ENR |= 0X06;
	GPIOB->MODER |=0X5400;
	GPIOB->BSRR =0X00C; //SET EN AND RW LOW
	GPIOC->MODER |=0X00005555;



}
void LCD_Command(unsigned char command)
{
	// RS=0  RW=0
	GPIOB->BSRR=(RS|RW)<<16;
	GPIOC->ODR=command;
	GPIOB->BSRR=EN ; //ENABLE EN
	delayMs(0);
	GPIOB->BSRR=EN<<16 ; //clear EN
	//delayMs(30);

}

void LCD_Data(unsigned char data)
{
	//RS=1 ,RW=0
	GPIOB->BSRR=RS;
	GPIOB->BSRR=RW<<16;
	GPIOC->ODR=data;
	GPIOB->BSRR=EN ; //ENABLE EN
	delayMs(30);
	GPIOB->BSRR=EN<<16 ; //clear EN
	delayMs(30);



}

void LCD_Init(void)
{
	unsigned char i=0;

	GPIO_Init();
	LCD_Command(0x28); //select one line
	delayMs(15);
	LCD_Command(0x0c); //set b it data mode
	delayMs(15);
	LCD_Command(0x06); //move the cursor right
	delayMs(15);
	LCD_Command(0x01); //clear screen move cursor home
	delayMs(15);
	delayMs(5000);

	LCD_Command(0x80); //turn display
	delayMs(15);
	while (Message[i]!='\0')
		{
			LCD_Data(Message[i]);
			i++;
		}
		delayMs(50);
		LCD_Command(0xC0); //turn display
		delayMs(15);

}
void delayMs(int delay)
{
	int i;
	for (;delay>0;delay--)
	{
		for(i=0;i<3195;i++)
		{

		}
	}
}
