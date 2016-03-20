#ifndef INPUT_H
#define INPUT_H

#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR 	DDRB
#define LED_PORT	PORTB
#define LED			PB0
#define BUTTON_DDR	DDRB
#define BUTTON_1	PB1
#define BUTTON_2	PB2
#define BUTTON_PIN	PINB

#define INIT() 	LED_DDR |= _BV(LED)

#define BUTTON_1_PRESSED() 	!(BUTTON_PIN & _BV(BUTTON_1))
#define BUTTON_2_PRESSED() 	!(BUTTON_PIN & _BV(BUTTON_2))

#define DELAY(X) 		for(int8_t counter = 0;counter<= X; counter++)_delay_ms(100)

#define TOGGLE_LED()	LED_PORT ^= _BV(LED)

#endif //INPUT_H
