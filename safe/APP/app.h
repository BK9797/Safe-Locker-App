/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: app.h
 *
 * Description: header file for the APP
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef APP_H_
#define APP_H_

/*******************************************************************************
 *                                  DataTypes                                  *
 *******************************************************************************/

typedef enum{TRUE_PASSWORD,WRONG_PASSWORD}password_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LONG_DELAY  3000
#define SHORT_DELAY 1000

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/******************************************************/
/********A function to initialize the Application******/
void APP_voidInit(void);

/*****************************************************/
/********    functions to display screens    *********/

void APP_WelcomeScreen(void);
void APP_Selector(void);

/*****************************************************/
/********  functions to check & change pass  *********/

void APP_CheckPassword(void);
void APP_TruePasswordScreen(void);
void APP_ThiefAlert(void);
void APP_CheckChangePass(void);
void APP_ChangePassword(void);

#endif /* APP_H_ */
