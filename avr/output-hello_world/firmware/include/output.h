#ifndef OUTPUT_H
#define OUTPUT_H

#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR 	DDRB
#define LED_PORT 	PORTB

#define INIT_LED()	LED_DDR = 0xFF 
#define DELAY()		_delay_ms(100)

#endif //OUTPUT_H