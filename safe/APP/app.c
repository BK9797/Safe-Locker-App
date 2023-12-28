/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: app.c
 *
 * Description: source file for the APP
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Inclusions                                  *
 *******************************************************************************/

#include<util/delay.h>
#include"app.h"
#include"red_led.h"
#include"green_led.h"
#include"lcd.h"
#include"keypad.h"
#include"std_types.h"
#include"common_macros.h"

/*******************************************************************************
 *                              Global Variables	                           *
 *******************************************************************************/

static uint8 password[]= {1,1,2,2};

/*******************************************************************************
 *                            Local Functions Prototypes                       *
 *******************************************************************************/

static void APP_WrongPasswordScreen(uint8 illetrations);

/*******************************************************************************
 *                             Functions definition                            *
 *******************************************************************************/

void APP_voidInit()
{
	LCD_init();
	GRN_LED_init();
	RED_LED_init();
}


void APP_WelcomeScreen()
{
	LCD_clearScreen();
    LCD_displayString("Welcome my user");
    _delay_ms(LONG_DELAY);
	APP_Selector();

}


void APP_Selector()
{
	LCD_clearScreen();
	LCD_displayString("1)open safe");
	LCD_moveCursor( 1, 0);
	LCD_displayString("2)change pass");

	if(KEYPAD_getPressedKey()==1)
	{
		_delay_ms(500);
		LCD_clearScreen();
		APP_CheckPassword();
	}
	else if(KEYPAD_getPressedKey()==2)
	{
		_delay_ms(500);
		LCD_clearScreen();
		APP_CheckChangePass();
		APP_ChangePassword();
	}
	else
	{
		LCD_clearScreen();
		LCD_displayString("Wrong Input");
		LCD_moveCursor(1, 0);
		LCD_displayString("System reset");
		_delay_ms(LONG_DELAY);

		APP_WelcomeScreen();
	}
}


void APP_CheckPassword()
{
	uint8 pass[4];
	password_State state= WRONG_PASSWORD;
	for(uint8 i=0; i<3 && state==WRONG_PASSWORD ;i++)
	{
		LCD_clearScreen();
		LCD_displayString("Enter Pass:");
		LCD_moveCursor(1, 0);

		for(uint8 j=0;j<4;j++)
		{
			pass[j]= KEYPAD_getPressedKey();
			_delay_ms(500);
			LCD_displayCharacter('*');
		}

		state = TRUE_PASSWORD;

		for(uint8 j=0;j<4;j++)
		{
			if(pass[j] != password[j])
			{
				APP_WrongPasswordScreen(3-i);
				state = WRONG_PASSWORD;
				break;
			}
		}

	}

	if(state == TRUE_PASSWORD)
	{
		APP_TruePasswordScreen();
		_delay_ms(SHORT_DELAY) ;
		LCD_clearScreen() ;
		LCD_displayString("Balance=1000000$");
		_delay_ms(LONG_DELAY) ;
		LCD_clearScreen() ;
		APP_Selector();
	}
	else
	{
		APP_ThiefAlert();
		APP_WelcomeScreen();
	}
}


void APP_CheckChangePass(void)
{
	uint8 pass[4];
	password_State state= WRONG_PASSWORD;
	for(uint8 i=0; i<3 && state==WRONG_PASSWORD ;i++)
	{
		LCD_clearScreen();
		LCD_displayString("Enter old Pass:");
		LCD_moveCursor(1, 0);

		for(uint8 j=0;j<4;j++)
		{
			pass[j]= KEYPAD_getPressedKey();
			_delay_ms(500);
			LCD_displayCharacter('*');
		}

		state = TRUE_PASSWORD;

		for(uint8 j=0;j<4;j++)
		{
			if(pass[j] != password[j])
			{
				APP_WrongPasswordScreen(3-i);
				state = WRONG_PASSWORD;
				break;
			}
		}
	}

	if(state == TRUE_PASSWORD)
	{
		APP_ChangePassword();
		APP_Selector();
	}
	else
	{
		APP_ThiefAlert();
		APP_WelcomeScreen();
	}
}


void APP_ChangePassword(void)
{
	LCD_clearScreen();
	LCD_displayString("Enter new Pass:");
	LCD_moveCursor(1, 0);

	for(uint8 i=0;i<4;i++)
	{
		password[i] = KEYPAD_getPressedKey();
		_delay_ms(500);
		LCD_displayCharacter('*');
	}

	LCD_clearScreen();
	LCD_displayString("Password Updated");
	LCD_moveCursor(1, 0);
	LCD_displayString("Successfully!!");
	_delay_ms(SHORT_DELAY);
}


void APP_ThiefAlert()
{
	LCD_clearScreen();
	LCD_displayString("Thief Alert !!");

	RED_LED_on();
	_delay_ms(LONG_DELAY);
	RED_LED_off();

	APP_Selector();
}


void APP_TruePasswordScreen()
{
	LCD_clearScreen();

	LCD_displayString("True password !!");
	LCD_moveCursor(1, 0);

	GRN_LED_on();
	_delay_ms(LONG_DELAY);
	GRN_LED_off();
}


static void APP_WrongPasswordScreen(uint8_t illetrations)
{
	LCD_clearScreen();

	LCD_displayString("Wrong password !!");
	LCD_moveCursor(1, 0);
	LCD_integerToString(illetrations);
	LCD_displayString(" Tries left ");

	RED_LED_on();
	_delay_ms(LONG_DELAY);
	RED_LED_off();
}
