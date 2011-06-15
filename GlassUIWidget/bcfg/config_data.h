//##################################################################################################
//## ******************************************************************************************** ##
//## *                       The Code Created by ConfigCodeMaker v1.0                           * ##
//## *                       (Copyright) 2009 - Scorpion 16 (X) Richi.                          * ##
//## ******************************************************************************************** ##
//##################################################################################################


#ifndef _CONFIGDATA_H_
  #define _CONFIGDATA_H_


//-------------------------------------------------- Images;

	//-------------------------------------------------- Background;
	extern const int BCFG_Images_Background_Enable;
	extern const int BCFG_Images_Background_Position_X;
	extern const int BCFG_Images_Background_Position_Y;


	//-------------------------------------------------- Condition;
	extern const int BCFG_Images_DayState_Enable;
	extern const int BCFG_Images_DayState_Position_X;
	extern const int BCFG_Images_DayState_Position_Y;


	//-------------------------------------------------- Clock;
	extern const int BCFG_Images_Clock_Enable;
	extern const int BCFG_Images_Clock_Position_X;
	extern const int BCFG_Images_Clock_Position_Y;


	//-------------------------------------------------- AccuWeather Logo;
	extern const int BCFG_Images_AccuWeatherLogo_Enable;
	extern const int BCFG_Images_AccuWeatherLogo_Position_X;
	extern const int BCFG_Images_AccuWeatherLogo_Position_Y;


//-------------------------------------------------- Forecast;

	//-------------------------------------------------- Average Temperature;
	extern const int BCFG_Tags_AverageTemperature_Enable;
	extern const wchar_t BCFG_Tags_AverageTemperature_Mask[81];
	extern const int BCFG_Tags_AverageTemperature_Unit;


	//-------------------------------------------------- Condition;
	extern const int BCFG_Tags_DayState_Enable;
	extern const int BCFG_Tags_DayState_Position_X;
	extern const int BCFG_Tags_DayState_Position_Y;
	extern const int BCFG_Tags_DayState_FontSize;
	extern const unsigned int BCFG_Tags_DayState_TextColor;
	extern const int BCFG_Tags_DayState_Align;
	extern const unsigned int BCFG_Tags_DayState_LineSpacing;


	//-------------------------------------------------- Location;
	extern const int BCFG_Tags_Location_Enable;
	extern const int BCFG_Tags_Location_Position_X;
	extern const int BCFG_Tags_Location_Position_Y;
	extern const int BCFG_Tags_Location_FontSize;
	extern const unsigned int BCFG_Tags_Location_TextColor;
	extern const int BCFG_Tags_Location_Align;


	//-------------------------------------------------- Time;
	extern const unsigned int BCFG_Tags_Time_Day;
	extern const unsigned int BCFG_Tags_Time_Night;


//-------------------------------------------------- Date/Time;

	//-------------------------------------------------- Date;
	extern const int BCFG_Date_Enable;
	extern const int BCFG_DateTime_Date_Position_X;
	extern const int BCFG_DateTime_Date_Position_Y;
	extern const int BCFG_Date_FontSize;
	extern const unsigned int BCFG_Date_TextColor;
	extern const int BCFG_Date_Align;

		//-------------------------------------------------- Weekday;
		extern const wchar_t BCFG_Date_Weekday_Sunday[201];
		extern const wchar_t BCFG_Date_Weekday_Monday[201];
		extern const wchar_t BCFG_Date_Weekday_Tuesday[201];
		extern const wchar_t BCFG_Date_Weekday_Wednesday[201];
		extern const wchar_t BCFG_Date_Weekday_Thursday[201];
		extern const wchar_t BCFG_Date_Weekday_Friday[201];
		extern const wchar_t BCFG_Date_Weekday_Saturday[201];


		//-------------------------------------------------- Month;
		extern const wchar_t BCFG_Date_Month_January[201];
		extern const wchar_t BCFG_Date_Month_February[201];
		extern const wchar_t BCFG_Date_Month_March[201];
		extern const wchar_t BCFG_Date_Month_April[201];
		extern const wchar_t BCFG_Date_Month_May[201];
		extern const wchar_t BCFG_Date_Month_June[201];
		extern const wchar_t BCFG_Date_Month_July[201];
		extern const wchar_t BCFG_Date_Month_August[201];
		extern const wchar_t BCFG_Date_Month_September[201];
		extern const wchar_t BCFG_Date_Month_October[201];
		extern const wchar_t BCFG_Date_Month_November[201];
		extern const wchar_t BCFG_Date_Month_December[201];


	//-------------------------------------------------- Time;

		//-------------------------------------------------- Analog Clock;

			//-------------------------------------------------- Hour;
			extern const int BCFG_Time_Hour_Enable;
			extern const int BCFG_DateTime_Time_AnalogClock_Hour_Position_X;
			extern const int BCFG_DateTime_Time_AnalogClock_Hour_Position_Y;
			extern const int BCFG_Time_Hour_FontSize;
			extern const unsigned int BCFG_Time_Hour_TextColor;
			extern const int BCFG_Time_Hour_Align;


			//-------------------------------------------------- State;
			extern const int BCFG_Time_State_Enable;
			extern const RECT BCFG_Time_AnalogClock_State_Position;
			extern const int BCFG_Time_State_FontSize;
			extern const unsigned int BCFG_Time_State_TextColor;
			extern const int BCFG_Time_State_Align;


		//-------------------------------------------------- Digital Clock;
		extern const int BCFG_Time_DigitalClock_Enable;
		extern const int BCFG_DateTime_Time_DigitalClock_Position_X;
		extern const int BCFG_DateTime_Time_DigitalClock_Position_Y;
		extern const int BCFG_Time_DigitalClock_FontSize;
		extern const unsigned int BCFG_Time_DigitalClock_TextColor;
		extern const int BCFG_Time_DigitalClock_Align;

			//-------------------------------------------------- AM/PM;
			extern const int BCFG_Time_AMPM_Enable;
			extern const int BCFG_DateTime_Time_DigitalClock_AMPM_Position_X;
			extern const int BCFG_DateTime_Time_DigitalClock_AMPM_Position_Y;
			extern const int BCFG_Time_AMPM_FontSize;
			extern const unsigned int BCFG_Time_AMPM_TextColor;
			extern const int BCFG_Time_AMPM_Align;

	extern const int BCFG_Time_Type;


//-------------------------------------------------- Music;

	//-------------------------------------------------- Coverart;
	extern const int BCFG_Music_Coverart_Enable;
	extern const int BCFG_Music_Coverart_Position_X;
	extern const int BCFG_Music_Coverart_Position_Y;


	//-------------------------------------------------- Artist;
	extern const int BCFG_Music_Artist_Enable;
	extern const int BCFG_Music_Artist_Position_X;
	extern const int BCFG_Music_Artist_Position_Y;
	extern const int BCFG_Music_Artist_FontSize;
	extern const unsigned int BCFG_Music_Artist_TextColor;
	extern const int BCFG_Music_Artist_Align;


	//-------------------------------------------------- Title;
	extern const int BCFG_Music_Title_Enable;
	extern const int BCFG_Music_Title_Position_X;
	extern const int BCFG_Music_Title_Position_Y;
	extern const int BCFG_Music_Title_FontSize;
	extern const unsigned int BCFG_Music_Title_TextColor;
	extern const int BCFG_Music_Title_Align;


	//-------------------------------------------------- Time;
	extern const int BCFG_Music_Time_Enable;
	extern const int BCFG_Music_Time_Position_X;
	extern const int BCFG_Music_Time_Position_Y;
	extern const int BCFG_Music_Time_FontSize;
	extern const unsigned int BCFG_Music_Time_TextColor;
	extern const int BCFG_Music_Time_Align;


	//-------------------------------------------------- Progress Bar;
	extern const int BCFG_Music_ProgressBar_Enable;
	extern const RECT BCFG_Music_ProgressBar_Position;
	extern const unsigned int BCFG_Music_ProgressBar_Color;


//-------------------------------------------------- Folders;
extern const wchar_t BCFG_XMLBGLogoFolder[201];
extern const wchar_t BCFG_StatesFolder[201];
extern const wchar_t BCFG_Path_Clock[201];

#endif
