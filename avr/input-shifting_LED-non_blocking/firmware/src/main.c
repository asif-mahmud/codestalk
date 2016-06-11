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
			//it's non-blocking 
            //so we move on after a short delay
            delay();
            ledRotator <<= 1;
            if(ledRotator == 0)
                ledRotator = MIN_LED_POS;
		}
        LED_PORT = ledRotator;
        delay2();
        LED_PORT = 0x00;
        delay2();
	}
}
