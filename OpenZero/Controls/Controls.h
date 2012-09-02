#ifndef _CONTROLS_H
#define _CONTROLS_H

#ifndef F_CPU
	#define F_CPU					1000000UL
#endif

#define DEBOUNCE_TIME			5			// msec

#define ADC_THRESHOLD_CLOSE		965			// adc value cut off point while closing
#define ADC_THRESHOLD_OPEN		965			// adc value cut off point while opening

#define ADC_CONVERSION_BUSY		bit_is_set( ADCSRA, ADSC )
			
#define BUTTON_TIME_PRESSED		bit_is_clear( PINB, PB5 )
#define BUTTON_MENU_PRESSED		bit_is_clear( PINB, PB4 )
#define BUTTON_OK_PRESSED		bit_is_clear( PINB, PB6 )
#define BUTTON_UP_PRESSED		bit_is_clear( PINB, PB0 )
#define BUTTON_DOWN_PRESSED		bit_is_clear( PINB, PB7 )

typedef enum {
	TEMP,
	TIME,
	OFFSET,
	ADCVAL,
	LAST_ITEM								// this is just here to be able to wrap around, do not actually use it
} MAINMENU;

typedef enum {
	ROTARY_UNKNOWN,
	ROTARY_UP,
	ROTARY_DOWN
} ROTARYBUTTON;

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>

extern volatile MAINMENU mainmenu;

void initControls( void );

ROTARYBUTTON readRotaryButton( void );
unsigned char menuButtonPressed( void );
unsigned char timeButtonPressed( void );
unsigned char okButtonPressed( void );

#endif
