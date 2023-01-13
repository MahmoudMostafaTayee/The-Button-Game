/*
 * dio.h
 *
 *  Author: Mahmoud Mostafa Tayee
 */ 

#include "application.h"
#define CONFIDENCE_LEVEL 500 // A confidence level for the De-bouncing problem.

/*This is a variable to indicate a long press as one press not multi presses.
If the button has not been pressed yet, the variable holds the value 1.
But once it's pressed the value is changed to 0 till it's released.
(array index 0 for 1st player and 1 for 2nd player)*/
uint8_t pressed[2] = {1, 1};

void appInit(){
	/************************************************************************/
	/* Initialize LEDs for PORTB for the first player.                      */
	/************************************************************************/
	// Initialization of the pin for the 1st led to be output.
	LED_init(PLAYER_1_PORT, LED_1_PIN);	
	
	// Initialization of the pin for the 2nd led to be output.
	LED_init(PLAYER_1_PORT, LED_2_PIN);	
	
	// Initialization of the pin for the 3rd led to be output.
	LED_init(PLAYER_1_PORT, LED_3_PIN);
	
	// Initialization of the pin for the 4th led to be output.
	LED_init(PLAYER_1_PORT, LED_4_PIN);
	
	// Initialization of the pin for the 5th led to be output.
	LED_init(PLAYER_1_PORT, LED_5_PIN);
	
	// Initialization of the pin for the 6th led to be output.
	LED_init(PLAYER_1_PORT, LED_6_PIN);
	
	// Initialization of the pin for the 7th led to be output.
	LED_init(PLAYER_1_PORT, LED_7_PIN);
	
	/************************************************************************/
	/* Initialize LEDs for PORTB for the 2nd player.                      */
	/************************************************************************/
	// Initialization of the pin for the 1st led to be output.
	LED_init(PLAYER_2_PORT, LED_01_PIN);
	
	// Initialization of the pin for the 2nd led to be output.
	LED_init(PLAYER_2_PORT, LED_02_PIN);
	
	// Initialization of the pin for the 3rd led to be output.
	LED_init(PLAYER_2_PORT, LED_03_PIN);
	
	// Initialization of the pin for the 4th led to be output.
	LED_init(PLAYER_2_PORT, LED_04_PIN);
	
	// Initialization of the pin for the 5th led to be output.
	LED_init(PLAYER_2_PORT, LED_05_PIN);
	
	// Initialization of the pin for the 6th led to be output.
	LED_init(PLAYER_2_PORT, LED_06_PIN);
	
	// Initialization of the pin for the 7th led to be output.
	LED_init(PLAYER_2_PORT, LED_07_PIN);
	
	/************************************************************************/
	/* Initialize the buttons for both players to be input                  */
	/************************************************************************/
	// Initializing the pin of the button to be input for the 1st player.
	buttonInit(BUTTON_1_PORT, BUTTON_1_PIN); //
	
	// Initializing the pin of the button to be input for the 2nd player.
	buttonInit(BUTTON_2_PORT, BUTTON_2_PIN); //
}



void appStart(){
	// This is a value for getting the current state of the button(pressed or not), (index 0 for 1st player and 1 for 2nd player).
	uint8_t value[2];
	
	/* This variable to detect if any of the players has won and therefor the game has ended.
		* -1 -> No won has won yet and the game is still going.
		* PLAYER_ONE -> player 1 has won.
		* PLAYER_TWO -> player 2 has won.
	*/
	int8_t won = -1;
	
	while(1)
	{
		if (won == -1) // Check if the game is still going.
				{
					// Read the state of the button by passing the variable value by reference for 1st player, index 0.
					buttonRead(BUTTON_1_PORT, BUTTON_1_PIN, &value[0]);
					
					// Read the state of the button by passing the variable value by reference for 2nd player, index 1.
					buttonRead(BUTTON_2_PORT, BUTTON_2_PIN, &value[1]);
					
					/************************************************************************/
					/* Check if the button pressed for 1st player                           */
					/************************************************************************/
					// Check if the button is pressed(value[0] = 1).
					if(value[0])
					{
						won = processPressedButton(PLAYER_ONE);
					}
					else // Or if it's released (value[0] = 0).
					{
						processReleasesButton(PLAYER_ONE);
					}
					
					/************************************************************************/

					/* Check if the button pressed for 2nd player                           */

					/************************************************************************/
					// Check if the button is pressed(value[1] = 1).
					if(value[1])
					{
						won = processPressedButton(PLAYER_TWO);
					}
					else //  Or if it's released(value[1] = 0).
					{
						processReleasesButton(PLAYER_TWO);
					}
				}
				else
				{
					// This will be executed if the game has ended and not won has value of one of the players instead of -1.
					blinkAllLEDs(won);
				}
	}
}



uint8_t processPressedButton(uint8_t playerID) // This function is made to handle the state when the button is pressed.
{
	
			//This function call means that the button is pressed(value[i] = 1).
			/* There are 2 cases here
			* value[i] = 1 and pressed[i] = 1 -> the button is pressed and let's turn on the leds based on that.
			* value[i] = 1 and pressed[i] = 0 -> Long press, no action to be done.
			*/
			
			// Initialize the counters for each player to be 0 as it counts the number of presses for each player(index 0 for 1st player and 1 for 2nd player).
			static uint8_t playerCounter[2] = {0, 0};
	
			/*	This variable is to make sure that the  button is pressed for at least that amount of CONFIDENCE_LEVEL
				to avoid the button De-bouncing problem.(index 0 for 1st player and 1 for 2nd player)*/
			static int pressed_confidence_level[2] = {0, 0};
	
						
			pressed_confidence_level[playerID]++; // Incrementing the value each iteration to check on the button if it's pressed at least the CONFIDENCE_LEVEL.
			if(pressed_confidence_level[playerID] >= CONFIDENCE_LEVEL)

			{

				if(pressed[playerID]) // This check to indicate that if it's a new press of just a long one!

				{

					pressed[playerID] = 0; // that's a guard to stop the LEDs from toggling multiple times in the long presses.
					if(playerID == PLAYER_ONE)
						LED_on(PLAYER_1_PORT, playerCounter[playerID]); // Turn on the LED that each one in its turn based on the playerCounter which tracks the number of presses for 1st player.
					else
						LED_on(PLAYER_2_PORT, playerCounter[playerID]); // Turn on the LED that each one in its turn based on the playerCounter which tracks the number of presses for 2nd player.
					
					if(playerCounter[playerID] < 6) // This is to check if the player didn't exceed the number of LEDs.
						playerCounter[playerID]++;

					else // If the player pressed the button 7 times and led all the the LEDs then return that the player has one.
					{
						return playerID;
					}

				}

				pressed_confidence_level[playerID] = 0; // Resetting the check for confidence level if we took action based on a past achieved level to start over.

			}
		return -1; // Return -1 for the won variable to stay the same if no one has won yet.
}

void processReleasesButton(uint8_t playerID) // This function is made to handle when state when the button is released.
{
	/*Calling this function means that the button is not pressed(value = 0) and
	* after passing the CONFIDENCE_LEVEL,
	* we just preserve the value of pressed[i] = 1 and nothing more or
	* reseting the pressed[i] to be 1 after a long press.
	*/
	
	/* This variable is to make sure that the  button is released for at least that amount of CONFIDENCE_LEVEL
	to avoid the button De-bouncing problem.(index 0 for 1st player and 1 for 2nd player)*/
	static int released_confidence_level[2] = {0, 0};
			

	released_confidence_level[playerID]++; // Incrementing the value each iteration to check on the button if it's released at least the CONFIDENCE_LEVEL.
	if(released_confidence_level[playerID] >= CONFIDENCE_LEVEL)

	{
		pressed[playerID] = 1; // Setting the pressed[i] to 1 to indicate that the button is not pressed
		released_confidence_level[playerID] = 0; // Resetting the check for confidence level if we took action based on a past achieved level to start over.
	}

}

void blinkAllLEDs(uint8_t playerID){
	switch (playerID){
		case PLAYER_ONE: // Toggling LEDs for 1st player with a delay of 4000 ms.
			_delay_ms(4000);
			LED_toggle(PLAYER_1_PORT, LED_1_PIN);
			LED_toggle(PLAYER_1_PORT, LED_2_PIN);
			LED_toggle(PLAYER_1_PORT, LED_3_PIN);
			LED_toggle(PLAYER_1_PORT, LED_4_PIN);
			LED_toggle(PLAYER_1_PORT, LED_5_PIN);
			LED_toggle(PLAYER_1_PORT, LED_6_PIN);
			LED_toggle(PLAYER_1_PORT, LED_7_PIN);
			break;
		case PLAYER_TWO: // Toggling LEDs for 2nd player with a delay of 4000 ms.
			_delay_ms(4000);
			LED_toggle(PLAYER_2_PORT, LED_01_PIN);
			LED_toggle(PLAYER_2_PORT, LED_02_PIN);
			LED_toggle(PLAYER_2_PORT, LED_03_PIN);
			LED_toggle(PLAYER_2_PORT, LED_04_PIN);
			LED_toggle(PLAYER_2_PORT, LED_05_PIN);
			LED_toggle(PLAYER_2_PORT, LED_06_PIN);
			LED_toggle(PLAYER_2_PORT, LED_07_PIN);
			break;
	}
}