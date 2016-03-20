#ifndef INPUT_H
#define INPUT_H

#include <avr/io.h>

#define LED_DDR 	DDRD
#define LED_PORT 	PORTD
#define MAX_LED_POS	0x07
#define MIN_LED_POS	0x01

#define SW_DDR		DDRD
#define SW_PIN		PIND
#define SW			PD3

#define INIT()				LED_DDR |= _BV(PD0)|_BV(PD1)|_BV(PD2);\
							LED_PORT |= MIN_LED_POS
#define IS_SW_PRESSED()		!(PIND & (_BV(SW)))

#endif //INPUT_H
