/*
 * Register.h
 *
 * Author: Mahmoud Mostafa Tayee
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
typedef unsigned char uint8_t;
typedef signed char int8_t;

/****************************************************************************************/
/* This registers implementation is for ATmega324P                                      */
/* http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42743-ATmega324P_Datasheet.pdf */
/****************************************************************************************/

/************************************************************************/
/* DIO REGISTERS                                                        */
/************************************************************************/
// PORTA register
#define PORTA *((volatile uint8_t*) 0x22)
#define DDRA *((volatile uint8_t*) 0x21)
#define PINA *((volatile uint8_t*) 0x20)

// PORTB register
#define PORTB *((volatile uint8_t*) 0x25)
#define DDRB *((volatile uint8_t*) 0x24)
#define PINB *((volatile uint8_t*) 0x23)

// PORTC register
#define PORTC *((volatile uint8_t*) 0x28)
#define DDRC *((volatile uint8_t*) 0x27)
#define PINC *((volatile uint8_t*) 0x26)

// PORTD register
#define PORTD *((volatile uint8_t*) 0x2B)
#define DDRD *((volatile uint8_t*) 0x2A)
#define PIND *((volatile uint8_t*) 0x29)

#endif /* REGISTERS_H_ */