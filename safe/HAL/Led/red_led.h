/******************************************************************************
 *
 * Module: RED_LED
 *
 * File Name: RED_LED.h
 *
 * Description: source file for the AVR LCD driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef RED_LED_H
#define RED_LED_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define RED_LED_PIN  PIN0_ID
#define RED_LED_PORT PORTC_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the RED_LED
 */
void RED_LED_init(void);

/*
 * Description :
 * A function to turn on the RED_LED
 */
void RED_LED_on(void);

/*
 * Description :
 * A function to turn off the RED_LED
 */
void RED_LED_off(void);

#endif /* RED_LED_H */
