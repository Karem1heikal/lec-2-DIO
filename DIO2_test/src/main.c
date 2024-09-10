/*
 * main.c
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_interface.h"
#include "../MCAL/PORT_interface.h"
#include "../HAL/SSD_interface.h"
#include "../HAL/LED_interface.h"
#include "../HAL/SW_interface.h"
u8 GetPortKey()
{
	u8 i=0,x;

	for(i=0;i<8;i++)
	{
		DIO_u8GetPinValue(DIO_PORTC,i,&x);
		if(x==0)
		{
			//Not pressed
			return i;
		}

	}
	return 8;
}
void Not1();
void Not2();
u8 x,y;
s8 inc=50;
void main()
{
	PORT_voidInit();

	/*
	u8 seg[10]={0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
	u8 i=0;
	while(1)
	{
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		for(i=1;i<=15;i++)
		{
			DIO_u8SetPortValue(DIO_PORTC,~seg[(15-i)/10]);
			DIO_u8SetPortValue(DIO_PORTB,~seg[(15-i)%10]);
			_delay_ms(500);
		}
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		for(i=1;i<=3;i++)
		{
			DIO_u8SetPortValue(DIO_PORTC,~seg[(3-i)/10]);
			DIO_u8SetPortValue(DIO_PORTB,~seg[(3-i)%10]);
			_delay_ms(500);
		}
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
		for(i=1;i<=15;i++)
		{
			DIO_u8SetPortValue(DIO_PORTC,~seg[(15-i)/10]);
			DIO_u8SetPortValue(DIO_PORTB,~seg[(15-i)%10]);
			_delay_ms(500);
		}
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
	}
	*/
	/*
	u8 read;
	u8 x=1,i,x1,x2;
	while(1)
		{
			read=GetPortKey();
			switch(read)
			{
				case 0:
				DIO_u8SetPortValue(DIO_PORTB,0xff);
				_delay_ms(500);
				DIO_u8SetPortValue(DIO_PORTB,0);
				break;
				case 1:
				x=128;
				for(i=0;i<8;i++)
				{
					DIO_u8SetPortValue(DIO_PORTB,x>>i);
					_delay_ms(250);
				}
				break;
				case 2:
				x=1;
				for(i=0;i<8;i++)
				{
					DIO_u8SetPortValue(DIO_PORTB,x<<i);
					_delay_ms(250);
				}
				break;
				case 3:
				x1 = 1;
				x2 = 128;
				for(i=0;i<4;i++)
				{
					DIO_u8SetPortValue(DIO_PORTB,x1|x2);
					x1<<=1;
					x2>>=1;
					_delay_ms(250);
				}
				break;
				case 4:
				x1 = 0x08;
				x2 = 0x10;
				for(i=0;i<4;i++)
				{
					DIO_u8SetPortValue(DIO_PORTB,x1|x2);
					x1>>=1;
					x2<<=1;
					_delay_ms(250);
				}
				break;
				case 5:
				x=128;
				for(i=0;i<8;i++)
				{
					DIO_u8SetPortValue(DIO_PORTB,x>>i);
					_delay_ms(250);
				}
				x=1;
				for(i=0;i<8;i++)
				{
					DIO_u8SetPortValue(DIO_PORTB,x<<i);
					_delay_ms(250);
				}
				break;

				case 6:
				x=1;
				for(i=1;i<8;i++)
				{
				DIO_u8SetPortValue(DIO_PORTB,x);
				x|=(1<<i);
				_delay_ms(250);
				}
				break;
				case 7:
				x1 = 1;
				x2 = 128;
				for(i=0;i<4;i++)
				{
				DIO_u8SetPortValue(DIO_PORTB,x1|x2);
				x1<<=1;
				x2>>=1;
				_delay_ms(250);
				}
				x1 = 0x08;
				x2 = 0x10;
				for(i=0;i<4;i++)
				{
				DIO_u8SetPortValue(DIO_PORTB,x1|x2);
				x1>>=1;
				x2<<=1;
				_delay_ms(250);
				}
				break;
		}*/


		//u8 seg[10]={0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
		//u8 pressed=0;
		//u8 pressed_conf_level = 0;
		//u8 released_conf_level = 0;
		SSD_t ssd1={ANODE,DIO_PORTD,DIO_PORTA,DIO_PIN6},ssd2={ANODE,DIO_PORTD,DIO_PORTA,DIO_PIN7};
		//LED_t led1 = {DIO_PORTA,DIO_PIN0,LED_SOUCE};
		SW_t sw1={DIO_PORTC,DIO_PIN0,SW_PULL_UP,SW_SELF_LOCK,Not1},sw2={DIO_PORTC,DIO_PIN1,SW_PULL_UP,SW_SELF_LOCK,Not2};

		while(1)
		{

		/*
			DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0,&x);
			if(x==0)
			{
				pressed_conf_level++;
				if(pressed_conf_level>20)
				{
					if(pressed==0)
					{
						inc++;
						if(inc==100)
							inc=99;
						pressed=1;
					}
					pressed_conf_level=0;
				}
				else
				{
					released_conf_level++;
					if(released_conf_level>20)
					{
						pressed = 0;
						released_conf_level = 0;

					}
				}

			}
			*/
			/*
			DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1,&y);
			if(y==0)
			{
				pressed_conf_level++;
				if(pressed_conf_level>20)
				{
					if(pressed==0)
					{
						inc--;
						if(inc==0)
							inc=0;
						pressed=1;
					}
					pressed_conf_level=0;
				}
				else
				{
					released_conf_level++;
					if(released_conf_level>20)
					{
						pressed = 0;
						released_conf_level = 0;
					}
				}
			}*/

			SW_u8GetState2(&sw1,&x);

			SW_u8GetState2(&sw2,&y);

			/*
			DIO_u8SetPortValue(DIO_PORTD,~seg[inc%10]);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			_delay_ms(5);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
			DIO_u8SetPortValue(DIO_PORTD,~seg[inc/10]);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			_delay_ms(15);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
			*/

			SSD_u8SetNumber(inc%10,&ssd1);
			SSD_u8Enable(&ssd1);
			_delay_ms(10);
			SSD_u8Disable(&ssd1);
			SSD_u8SetNumber(inc/10,&ssd2);
			SSD_u8Enable(&ssd2);
			_delay_ms(10);
			SSD_u8Disable(&ssd2);

		}

}

void Not1()
{
	if(x==0)
	{

		inc++;
		if(inc>100)
			inc=99;
	}
}
void Not2()
{
	if(y==0)
	{
		inc--;
		if(inc<0)
			inc=0;
	}
}
