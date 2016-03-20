#include <avr/io.h>
#include <input.h>

int main()
{
	uint8_t ledRotator = MIN_LED_POS; //initial LED position
	
	INIT(); //initialize LED ports
	
	while(1)
	{
		if(IS_SW_PRESSED()) //check if switch is pressed
		{
			while(IS_SW_PRESSED()); //blocking I/O
			
			ledRotator <<= 1; //shift LED position
			if(ledRotator > MAX_LED_POS)
				ledRotator = MIN_LED_POS; //resest LED position
			
			LED_PORT = ledRotator; //finally display it
		}
	}
}
