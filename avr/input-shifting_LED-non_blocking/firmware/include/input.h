#ifndef INPUT_H
#define INPUT_H

#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR 	DDRD
#define LED_PORT 	PORTD
#define MAX_LED_POS	0x80
#define MIN_LED_POS	0x01

#define SW_DDR		DDRC
#define SW_PIN		PINC
#define SW			PC3

#define INIT()				LED_DDR |= 0xFF;\
							LED_PORT |= MIN_LED_POS
#define IS_SW_PRESSED()		!(SW_PIN & (_BV(SW)))
#define delay()             _delay_ms(50)
#define delay2()            _delay_ms(100)

#endif //INPUT_H
