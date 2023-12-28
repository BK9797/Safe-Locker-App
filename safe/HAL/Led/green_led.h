/******************************************************************************
 *
 * Module: GREEN_LED
 *
 * File Name: GREEN_LED.h
 *
 * Description: source file for the AVR LCD driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef GRN_LED_H
#define GRN_LED_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define GRN_LED_PIN  PIN1_ID
#define GRN_LED_PORT PORTC_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the GRN_LED
 */
void GRN_LED_init(void);

/*
 * Description :
 * A function to turn on the GRN_LED
 */
void GRN_LED_on(void);

/*
 * Description :
 * A function to turn off the GRN_LED
 */
void GRN_LED_off(void);

#endif /* RED_LED_H */
