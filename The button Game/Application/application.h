/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 




#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"

#ifndef APPLICATION_H_
#define APPLICATION_H_

#define PLAYER_ONE 0
#define PLAYER_TWO 1

void appInit(); // function that will initialize the beginning state of the project.
void appStart(); // Function that will call the program to run after setting the initial state.
uint8_t processPressedButton(uint8_t playerID); // This function is made to handle when state when the button is pressed.
void processReleasesButton(uint8_t playerID); // This function is made to handle when state when the button is released.
void blinkAllLEDs(uint8_t playerID); // This function is to toggle all LEDs if one of the players has won.

#endif /* APPLICATION_H_ */