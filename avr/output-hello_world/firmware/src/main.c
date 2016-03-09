#include <avr/io.h>
#include <output.h>

int main()
{
	INIT_LED(); //initialize I/O pin direction

	/*
	*	infinite loop to keep the controller working as long as 
	*	power is available.
	*/
	while(1)
	{
		/*
		*	shift led from right to left where right means LSB of 
		* 	LED port and left means MSB of LED port.
		*/
		for(uint8_t rotator=0x01; rotator < 0x80; rotator<<=1)
		{
			LED_PORT = rotator; //output the value of rotator on 
								//LED port defined in output.h
			DELAY();			//wait for 500ms
		}

		/*
		*	shift led from left to right.
		*/
		for(uint8_t rotator=0x80; rotator > 0x01; rotator>>=1)
		{
			LED_PORT = rotator;
			DELAY();
		}

	}

	return 0;
}