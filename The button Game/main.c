/*
 * The button Game.c
 *
 * Created: 11/01/2023 21:06:36
 * Author : ahmed
 */ 

//#include <avr/io.h>
//#include <util/delay.h>
#include "Application/application.h"

int main(void)
{
    while (1) 
    {
		appInit();
		appStart();
    }
}

