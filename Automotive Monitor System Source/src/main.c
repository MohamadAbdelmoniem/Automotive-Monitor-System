/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"
#include "../src/LIB/Delay/Delay_Interface.h"
#include "string.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MCAL/MRCC/MRCC_Int.h"
#include "MCAL/MGPIO/MGPIO_Int.h"
#include "MCAL/MADC/MADC_Int.h"
#include "MCAL/MNVIC/MNVIC_Int.h"
#include "MCAL/MEXTI/MEXTI_Int.h"

/*******************************************************************************************************/
/*                                      HAL Components                                                 */
/*******************************************************************************************************/
#include "HAL/LCD/LCD_Int.h"

#include "HAL/KeyPad/KeyPad_Int.h"

#include "HAL/DC_Motor/DC_Motor_Int.h"

#include "HAL/Push_Button/Push_Button_Int.h"

#include "HAL/LED/LED_Int.h"

#include "HAL/Ultrasonic/Ultrasonic_Int.h"

#include "HAL/Buzzer/Buzzer_Int.h"

#include "HAL/Switch/Switch_Int.h"

#include "HAL/LM35/LM35_Int.h"

#include "HAL/MPX4115/MPX4115_Int.h"


/*******************************************************************************************************/
/*                                     Global Variables                                                */
/*******************************************************************************************************/
u8 PassWord_u8_PassFlag;
u8 Choice;
u8 Keypad_Value;
u8 Button_Value;
u32 Distance;
f32 Temperature;
float Pressure;


/*******************************************************************************************************/
/*                                         Functions Prototypes                                        */
/*******************************************************************************************************/
u8 Check_Password();
void Main_Menu();
void Ready_Check();
void Start_Engine();
void Calculate_Temperature();
void Calculate_Distance();
void Calculate_Pressure();


/*******************************************************************************************************/
/*                                            Main Function                                            */
/*******************************************************************************************************/
void main()
{

/*******************************************************************************************************/
/*                                     RCC Configuration                                               */
/*******************************************************************************************************/

	/** RCC Initialization **/
	MRCC_vInit();

	/** Enable GPIO Clock **/
	MRCC_vEnableClock(AHB1_BUS, AHB1_GPIOA);
	MRCC_vEnableClock(AHB1_BUS, AHB1_GPIOB);

	/** Enable ADC1 Clock **/
    MRCC_vEnableClock(APB2_BUS, APB2_ADC1);

	/** Enable System Configuration controller Clock **/
    MRCC_vEnableClock(APB2_BUS,APB2_System_Config_controller);


/*******************************************************************************************************/
/*                                     HAL Initialization                                              */
/*******************************************************************************************************/

	H_Lcd_void_LcdInit();

	H_KeyPad_Void_KeyPadInit();

	H_DC_MOTOR_Void_DCMotorInit();

	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_PORT,PUSH_BUTTON_PIN);

	H_Led_Init(GREEN_LED);

	H_Led_Init(RED_LED);

	H_VUltrasonicInit();

	H_Buzzer_Void_BuzzerInit(BUZZER_PORT,BUZZER_PIN);

	H_Switch_Void_SwitchInit(SWITCH_PORT,SWITCH_PIN);


/*******************************************************************************************************/
/*                                           NVIC Configuration                                        */
/*******************************************************************************************************/
	/** Enable NVIC interrupt **/
    MNVIC_vInterruptEnable(6);

    /** Set Group Mode **/
    MNVIC_SetGroupMode(MNVIC_G16_SG0);

    /** Set the interrupt Priority **/
    MNVIC_vSetInterruptPriority (6,0,0);

/*******************************************************************************************************/
/*                                           EXTI Configuration                                        */
/*******************************************************************************************************/

    /** Disable Mask of EXTI on the selected Line **/
    MEXTI_vEnableExternalInterrupt(MEXTI_LINE0);

    /** Configure the Trigger **/
    MEXTI_vSetTrigger( MEXTI_RISING_EDGE, MEXTI_LINE0 );

    /** EXTI Configuration (select lineNo and Port) **/
    MEXTI_vSetExtiConfig(MEXTI_LINE0,MEXTI_PORTB);

    MEXTI0_vCallBack(Start_Engine);

    /** Wait until the user Enter the Correct Password **/
	while(!Check_Password());
	Main_Menu();

	while(1)
	{
		Keypad_Value = H_KeyPad_U8_KeyPadRead();
		if(Keypad_Value != NULL_val)
		{
			Choice = Keypad_Value;
			H_Lcd_void_LcdSendCommand(0xC0);
			H_Lcd_void_LcdSendString((u8*)"       ");
			H_Lcd_void_LcdSendCharacter(Choice);
			H_Lcd_void_LcdSendString((u8*)"       ");
			Delay_vMsIn16MHz(1000);
			H_Lcd_void_LcdClear();
		}

		switch(Choice)
		{
			case '1':
				Ready_Check();
			break;

			case '2':
				Calculate_Temperature();

			break;

			case '3':
				Calculate_Distance();
			break;

			case '4' :
				Calculate_Pressure();

			break;

			case '*':
				Main_Menu();
				Choice = 0;
			break;

			default:
			break;
		}
	}
}


/*******************************************************************************************************/
/*                                     Functions Implementation                                        */
/*******************************************************************************************************/
u8 Check_Password()
{
	  u8 Local_u8_Password[18] = "12345";
	  u8 Local_u8_EnteredPass[18] ;
	  u8 Local_u8_Counter = 0;
	  u8 Local_u8_KeypadRead = 0;
	  H_Lcd_void_LcdSendString((u8*)" ");
	  H_Lcd_void_LcdSendString((u8*)"Enter Password");
	  Delay_vMsIn16MHz(1000);
	  H_Lcd_void_LcdGoTo(1,0);
	  H_Lcd_void_LcdSendString((u8*)"     ");
	  for(Local_u8_Counter=0; Local_u8_Counter<18 ;Local_u8_Counter++)
	  {
	    while((Local_u8_KeypadRead = H_KeyPad_U8_KeyPadRead()) == 0);
	    if(Local_u8_KeypadRead == '#')
	    {
	      Local_u8_EnteredPass[Local_u8_Counter]= '\0';
	      break;
	    }
	    else
	    {
	      Local_u8_EnteredPass[Local_u8_Counter]=Local_u8_KeypadRead;
	    }
	    H_Lcd_void_LcdSendCharacter('*');
	  }
	  H_Lcd_void_LcdClear();

	  // in case of correct password
	  if( strcmp(Local_u8_Password , Local_u8_EnteredPass) == 0)
	  {
	    H_Lcd_void_LcdGoTo(0,0);
	    H_Lcd_void_LcdSendString((u8*)"    ");
	    H_Lcd_void_LcdSendString((u8*)"Welcome");
	    Delay_vMsIn16MHz(1000);
	    H_Lcd_void_LcdClear();
	    return 1;
	  }

	  // in case of incorrect password
	  else
	  {
	    H_Lcd_void_LcdGoTo(0,0);
	    H_Lcd_void_LcdSendString((u8*)" ");
	    H_Lcd_void_LcdSendString((u8*)"Wrong Password");
	    PassWord_u8_PassFlag++;
	    Delay_vMsIn16MHz(1000);
	    if(PassWord_u8_PassFlag == 3)
	    {
	      H_Lcd_void_LcdGoTo(0,0);
	      H_Lcd_void_LcdSendString((u8*)"System will lock");
	      H_Lcd_void_LcdGoTo(1,0);
	      H_Lcd_void_LcdSendString((u8*)" ");
	      H_Lcd_void_LcdSendString((u8*)"For 30 Seconds");
	      Delay_vMsIn16MHz(5000);
	      PassWord_u8_PassFlag=0;
	      H_Lcd_void_LcdClear();
	    }
	    H_Lcd_void_LcdClear();
	    H_Lcd_void_LcdGoTo(0,0);
	    H_Lcd_void_LcdSendString((u8*)"   ");
	    H_Lcd_void_LcdSendString((u8*)"Try again");
	    Delay_vMsIn16MHz(1000);
	    H_Lcd_void_LcdClear();
	    return 0;
	  }
}


void Main_Menu()
{
	H_Lcd_void_LcdSendString((u8*)"    ");
	H_Lcd_void_LcdSendString((u8*)"Main Menu");
	H_Lcd_void_LcdSendString((u8*)"   ");
	H_Lcd_void_LcdSendCommand(0xC0);
	H_Lcd_void_LcdSendString((u8*)"  ");
	H_Lcd_void_LcdSendString((u8*)"1-Check All");
	H_Lcd_void_LcdSendString((u8*)" ");
	Delay_vMsIn16MHz(1000);
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString((u8*)"    ");
	H_Lcd_void_LcdSendString((u8*)"Main Menu");
	H_Lcd_void_LcdSendString((u8*)"   ");
	H_Lcd_void_LcdSendCommand(0xC0);
	H_Lcd_void_LcdSendString((u8*)" ");
	H_Lcd_void_LcdSendString((u8*)"2-Temperature");
	H_Lcd_void_LcdSendString((u8*)" ");
	Delay_vMsIn16MHz(1000);
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString((u8*)"    ");
	H_Lcd_void_LcdSendString((u8*)"Main Menu");
	H_Lcd_void_LcdSendString((u8*)"   ");
	H_Lcd_void_LcdSendCommand(0xC0);
	H_Lcd_void_LcdSendString((u8*)"   ");
	H_Lcd_void_LcdSendString((u8*)"3-Distance");
	H_Lcd_void_LcdSendString((u8*)"   ");
	Delay_vMsIn16MHz(1000);
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString((u8*)"    ");
	H_Lcd_void_LcdSendString((u8*)"Main Menu");
	H_Lcd_void_LcdSendString((u8*)"   ");
	H_Lcd_void_LcdSendCommand(0xC0);
	H_Lcd_void_LcdSendString((u8*)"   ");
	H_Lcd_void_LcdSendString((u8*)"4-Pressure");
	H_Lcd_void_LcdSendString((u8*)"   ");
	Delay_vMsIn16MHz(1000);
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString((u8*)"  ");
	H_Lcd_void_LcdSendString((u8*)"Enter Choice");
	H_Lcd_void_LcdSendString((u8*)"  ");
}

void Ready_Check()
{
	 Temperature = LM35_GetTempreture();
	 Distance = H_u16USRead();

	if((Temperature < 50) && (Distance > 200))
	{
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendString((u8*)"Ready To Start");
		Delay_vMsIn16MHz(1000);
		H_Lcd_void_LcdClear();
	}

	else if((Temperature < 50) && (Distance < 200))
	{
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendString((u8*)"Distance Error");
		Delay_vMsIn16MHz(1000);
		H_Lcd_void_LcdClear();
	}

	else if((Temperature > 50) && (Distance > 200))
	{
		H_Lcd_void_LcdSendString((u8*)"High Temperature");
		Delay_vMsIn16MHz(1000);
		H_Lcd_void_LcdClear();
	}

	else
	{
		H_Lcd_void_LcdSendString((u8*)"   ");
		H_Lcd_void_LcdSendString((u8*)"Not Ready");
		Delay_vMsIn16MHz(1000);
		H_Lcd_void_LcdClear();
	}
}

void Start_Engine()
{
	u8 Switch_Value = H_Switch_U8_SwitchRead(SWITCH_PORT,SWITCH_PIN);
	if(Switch_Value == CLOSE)
	{
		H_Lcd_void_LcdClear();
		H_DC_MOTOR_Void_RotationControl(ROTATE_CLOCKWISE);
		H_Led_On(GREEN_LED);
	    H_Led_Off(RED_LED);
		H_Buzzer_Void_BuzzerOff(BUZZER_PORT,BUZZER_PIN);
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendString((u8*)"Engine Started");
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendCommand(0xC0);
		H_Lcd_void_LcdSendString((u8*)"                ");
		Delay_vMsIn16MHz(1000);
		H_Lcd_void_LcdClear();
	}

	else
	{
		H_Lcd_void_LcdClear();
		H_Led_On(RED_LED);
		H_Led_Off(GREEN_LED);
		H_Buzzer_Void_BuzzerOn(BUZZER_PORT,BUZZER_PIN);
		H_Lcd_void_LcdSendString((u8*)"THE DOOR IS OPEN");
		H_Lcd_void_LcdSendCommand(0xC0);
		H_Lcd_void_LcdSendString((u8*)"   ");
		H_Lcd_void_LcdSendString((u8*)"CLOSE DOOR");
		H_Lcd_void_LcdSendString((u8*)"   ");
		H_DC_MOTOR_Void_RotationControl(STOP);
		Delay_vMsIn16MHz(1000);
		H_Lcd_void_LcdClear();
	    H_Led_Off(RED_LED);
		H_Buzzer_Void_BuzzerOff(BUZZER_PORT,BUZZER_PIN);
		H_Lcd_void_LcdSendString((u8*)"  ");
		H_Lcd_void_LcdSendString((u8*)"Enter Choice");
		H_Lcd_void_LcdSendString((u8*)"  ");
	}
}


void Calculate_Temperature()
{
	 Temperature = LM35_GetTempreture();
	 if (Temperature > 50)
	 {
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdSendString((u8*)"    ");
		H_Lcd_void_LcdSendString((u8*)"Temp: ");
		H_Lcd_void_LcdSendNumberU(Temperature);
		H_Lcd_void_LcdSendString((u8*)"C");
		H_Lcd_void_LcdSendString((u8*)"    ");
		H_Lcd_void_LcdSendCommand(0xC0);
		H_Lcd_void_LcdSendString((u8*)"High Temperature");
		H_Led_On(RED_LED);
	 }

	 else
	 {
		 H_Lcd_void_LcdClear();
		 H_Lcd_void_LcdSendString((u8*)"    ");
		 H_Lcd_void_LcdSendString((u8*)"Temp: ");
		 H_Lcd_void_LcdSendNumberU(Temperature);
		 H_Lcd_void_LcdSendString((u8*)"C");
		 H_Lcd_void_LcdSendString((u8*)"    ");
		 H_Lcd_void_LcdSendCommand(0xC0);
		 H_Lcd_void_LcdSendString((u8*)"Cool Temperature");
		 H_Led_Off(RED_LED);
	  }
	  Delay_vMsIn16MHz(1000); // Delay for 1 second (adjust as needed)
}

void Calculate_Distance()
{
	Distance = H_u16USRead();
	H_Lcd_void_LcdGoTo(0,12);

	if (Distance < 200)
	{
		H_Lcd_void_LcdGoTo(0,2);
		H_Lcd_void_LcdSendString((u8*)"Distance= ");
		H_Lcd_void_LcdSendNumberU(Distance);
		H_Lcd_void_LcdSendString((u8*)"  ");
		H_Lcd_void_LcdGoTo(1,6);
		H_Lcd_void_LcdSendString((u8*)"DANGER");
		H_Lcd_void_LcdSendString((u8*)"      ");
		H_Led_On(RED_LED);
	}

	else
	{
		 H_Lcd_void_LcdGoTo(0,2);
		 H_Lcd_void_LcdSendString((u8*)"Distance= ");
		 H_Lcd_void_LcdSendNumberU(Distance);
		 H_Lcd_void_LcdSendString((u8*)"    ");
		 H_Lcd_void_LcdGoTo(1,6);
		 H_Lcd_void_LcdSendString((u8*)"SAFE");
		 H_Lcd_void_LcdSendString((u8*)"      ");
		 H_Led_Off(RED_LED);
	}
}

void Calculate_Pressure()
{
	Pressure = MPX4115A_GetPressure();
	if (Pressure > 210)
	{
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendString((u8*)"Pressure:");
		H_Lcd_void_LcdSendNumberU(Pressure); // Display pressure with two decimal places
		H_Lcd_void_LcdSendString((u8*)"kPa");
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendCommand(0xC0);
		H_Lcd_void_LcdSendString((u8*)"High Pressure");
		H_Led_On(RED_LED);
	}

	else if (Pressure < 200)
	{
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendString((u8*)"Pressure:");
		H_Lcd_void_LcdSendNumberU(Pressure); // Display pressure with two decimal places
		H_Lcd_void_LcdSendString((u8*)"kPa");
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendCommand(0xC0);
		H_Lcd_void_LcdSendString((u8*)"LOW Pressure");
		H_Led_On(RED_LED);
	}

	else
	{
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendString((u8*)"Pressure:");
		H_Lcd_void_LcdSendNumberU(Pressure); // Display pressure with two decimal places
		H_Lcd_void_LcdSendString((u8*)"kPa");
		H_Lcd_void_LcdSendString((u8*)" ");
		H_Lcd_void_LcdSendCommand(0xC0);
		H_Lcd_void_LcdSendString((u8*)"Normal Pressure");
		H_Led_Off(RED_LED);
	}
    Delay_vMsIn16MHz(1000); // Delay for 1 second (adjust as needed)
}
