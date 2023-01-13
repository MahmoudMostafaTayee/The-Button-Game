/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 

#ifndef LED_H_
#define LED_H_

//Include the DIO driver to communicate with the Microcontroller DIO with a level of abstraction.
#include "../../MCAL/DIO/dio.h"

// Specifies the CPU frequency to be considered by the delay macros.
#define F_CPU 1000000U //1Mhz

// Include the delay library.
#include <util/delay.h> // to use delay function

//Define on what are the ports that my LEDs are connected to on PORTB.
#define PLAYER_1_PORT PORT_B // Port of player 1 which is PORTB
#define LED_1_PIN PIN0 //  Pin of the  first pin on PORTB

#define LED_2_PIN PIN1 //  Pin of the  second pin on PORTB

#define LED_3_PIN PIN2 //  Pin of the  third pin on PORTB

#define LED_4_PIN PIN3 //  Pin of the  forth pin on PORTB

#define LED_5_PIN PIN4 //  Pin of the  fifth pin on PORTB

#define LED_6_PIN PIN5 //  Pin of the  sixth pin on PORTB

#define LED_7_PIN PIN6 //  Pin of the  seventh pin on PORTB

//Define on what are the ports that my LEDs are connected to on PORTD.
#define PLAYER_2_PORT PORT_D // Port of player 2 which is PORTD

#define LED_01_PIN PIN0 //  Pin of the  first pin on PORTB

#define LED_02_PIN PIN1 //  Pin of the  second pin on PORTB

#define LED_03_PIN PIN2 //  Pin of the  third pin on PORTB

#define LED_04_PIN PIN3 //  Pin of the  forth pin on PORTB

#define LED_05_PIN PIN4 //  Pin of the  fifth pin on PORTB

#define LED_06_PIN PIN5 //  Pin of the  sixth pin on PORTB

#define LED_07_PIN PIN6 //  Pin of the  seventh pin on PORTB

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);


#endif /* LED_H_ */