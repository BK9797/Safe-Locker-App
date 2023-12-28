/******************************************************************************
 *
 * Module: RED_LED
 *
 * File Name: RED_LED.c
 *
 * Description: source file for the AVR LCD driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include"common_macros.h"
#include<avr/io.h>
#include"red_led.h"
#include"gpio.h"

/*******************************************************************************/

/*******************************************************************************/

/**********************************Functions************************************/

/*
 * Description :
 * A function to initialize the RED_LED
 */
void RED_LED_init(void)
{
	/*Make the REDLED pin output pin*/
	GPIO_setupPinDirection(RED_LED_PORT,RED_LED_PIN,PIN_OUTPUT);

	/*Turn off the RED_LED*/
	GPIO_writePin(RED_LED_PORT,RED_LED_PIN,PIN_INPUT);
}

/*
 * Description :
 * A function to turn on the RED_LED
 */
void RED_LED_on(void)
{
	/*Turn on the RED_LED*/
	GPIO_writePin(RED_LED_PORT,RED_LED_PIN,PIN_OUTPUT);
}

/*
 * Description :
 * A function to turn off theRED_LED
 */
void RED_LED_off(void)
{
	/*Turn off the RED_LED*/
	GPIO_writePin(RED_LED_PORT,RED_LED_PIN,PIN_INPUT);
}
