/******************************************************************************
 *
 * Module: GREEN_LED
 *
 * File Name: GREEN_LED.c
 *
 * Description: source file for the AVR LCD driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include"common_macros.h"
#include<avr/io.h>
#include"green_led.h"
#include"gpio.h"

/*******************************************************************************/

/*******************************************************************************/

/**********************************Functions************************************/

/*
 * Description :
 * A function to initialize the GRN_LED
 */
void GRN_LED_init(void)
{
	/*Make the GRNLED pin output pin*/
	GPIO_setupPinDirection(GRN_LED_PORT,GRN_LED_PIN,1);

	/*Turn off the GRN_LED*/
	GPIO_writePin(GRN_LED_PORT,GRN_LED_PIN,0);
}

/*
 * Description :
 * A function to turn on the GRN_LED
 */
void GRN_LED_on(void)
{
	/*Turn on the RED_LED*/
	GPIO_writePin(GRN_LED_PORT,GRN_LED_PIN,1);
}

/*
 * Description :
 * A function to turn off theGRN_LED
 */
void GRN_LED_off(void)
{
	/*Turn off the RED_LED*/
	GPIO_writePin(GRN_LED_PORT,GRN_LED_PIN,0);
}
