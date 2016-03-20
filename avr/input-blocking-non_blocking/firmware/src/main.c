#include <avr/io.h>
#include <input.h>

int main()
{
	int8_t delay = 10; //a default delay 10*100 ms = 1 sec
	INIT();
	while(1)
	{
		/*
		 * Blocking I/O.
		 * If button 1 is pressed controller will get stuck here and LED
		 * will stop blinking.
		 */
		 if(BUTTON_1_PRESSED())
		 {
			while(BUTTON_1_PRESSED()); //stay here until button 1 is 
										//released
			delay--; //increase animation speed
		 }
		 
		 /*
		  * Non-blocking I/O.
		  * If button 2 is pressed controller will not get stuck.
		  */
		 if(BUTTON_2_PRESSED())
		 {
			 delay--;
			 _delay_ms(50); //give a little time to make this visible
		 }
		 
		 /*
		  * Check if delay counter is less than 0, if so start from 
		  * default value.
		  */
		  if(delay < 0) delay = 10;
		 
		 //Blink LED
		 TOGGLE_LED();
		 DELAY(delay);
	}
	return 0;
}
