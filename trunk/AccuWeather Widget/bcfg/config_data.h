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
	extern const int BCFG_Images_Background_Method;
	extern const unsigned int BCFG_RefreshTime;


	//-------------------------------------------------- Condition;
	extern const int BCFG_Images_DayState_Enable;
	extern const int BCFG_Images_DayState_Position_X;
	extern const int BCFG_Images_DayState_Position_Y;


	//-------------------------------------------------- AccuWeather Logo;
	extern const int BCFG_Images_AccuWeatherLogo_Enable;
	extern const int BCFG_Images_AccuWeatherLogo_Position_X;
	extern const int BCFG_Images_AccuWeatherLogo_Position_Y;


	//-------------------------------------------------- Wind Direction;
	extern const int BCFG_Images_WindDirection_Enable;
	extern const int BCFG_Images_WindDirection_Position_X;
	extern const int BCFG_Images_WindDirection_Position_Y;

extern const int BCFG_Images_ImageOnTop;


//-------------------------------------------------- Forecast;

	//-------------------------------------------------- Min Temperature;
	extern const int BCFG_Tags_MinTemperature_Enable;
	extern const int BCFG_Tags_MinTemperature_Position_X;
	extern const int BCFG_Tags_MinTemperature_Position_Y;
	extern const int BCFG_Tags_MinTemperature_FontSize;
	extern const unsigned int BCFG_Tags_MinTemperature_TextColor;
	extern const int BCFG_Tags_MinTemperature_EnableShadow;
	extern const unsigned int BCFG_Tags_MinTemperature_ShadowColor;
	extern const int BCFG_Tags_MinTemperature_Align;
	extern const wchar_t BCFG_Tags_MinTemperature_Mask[81];
	extern const int BCFG_Tags_MinTemperature_Unit;


	//-------------------------------------------------- Average Temperature;
	extern const int BCFG_Tags_AverageTemperature_Enable;
	extern const int BCFG_Tags_AverageTemperature_Position_X;
	extern const int BCFG_Tags_AverageTemperature_Position_Y;
	extern const int BCFG_Tags_AverageTemperature_FontSize;
	extern const unsigned int BCFG_Tags_AverageTemperature_TextColor;
	extern const int BCFG_Tags_AverageTemperature_EnableShadow;
	extern const unsigned int BCFG_Tags_AverageTemperature_ShadowColor;
	extern const int BCFG_Tags_AverageTemperature_Align;
	extern const wchar_t BCFG_Tags_AverageTemperature_Mask[81];
	extern const int BCFG_Tags_AverageTemperature_Unit;


	//-------------------------------------------------- Max Temperature;
	extern const int BCFG_Tags_MaxTemperature_Enable;
	extern const int BCFG_Tags_MaxTemperature_Position_X;
	extern const int BCFG_Tags_MaxTemperature_Position_Y;
	extern const int BCFG_Tags_MaxTemperature_FontSize;
	extern const unsigned int BCFG_Tags_MaxTemperature_TextColor;
	extern const int BCFG_Tags_MaxTemperature_EnableShadow;
	extern const unsigned int BCFG_Tags_MaxTemperature_ShadowColor;
	extern const int BCFG_Tags_MaxTemperature_Align;
	extern const wchar_t BCFG_Tags_MaxTemperature_Mask[81];
	extern const int BCFG_Tags_MaxTemperature_Unit;


	//-------------------------------------------------- Condition;
	extern const int BCFG_Tags_DayState_Enable;
	extern const int BCFG_Tags_DayState_Position_X;
	extern const int BCFG_Tags_DayState_Position_Y;
	extern const int BCFG_Tags_DayState_FontSize;
	extern const unsigned int BCFG_Tags_DayState_TextColor;
	extern const int BCFG_Tags_DayState_EnableShadow;
	extern const unsigned int BCFG_Tags_DayState_ShadowColor;
	extern const int BCFG_Tags_DayState_Align;
	extern const unsigned int BCFG_Tags_DayState_LineSpacing;


	//-------------------------------------------------- Location;
	extern const int BCFG_Tags_Location_Enable;
	extern const int BCFG_Tags_Location_Position_X;
	extern const int BCFG_Tags_Location_Position_Y;
	extern const int BCFG_Tags_Location_FontSize;
	extern const unsigned int BCFG_Tags_Location_TextColor;
	extern const int BCFG_Tags_Location_EnableShadow;
	extern const unsigned int BCFG_Tags_Location_ShadowColor;
	extern const int BCFG_Tags_Location_Align;


	//-------------------------------------------------- Wind Speed;
	extern const int BCFG_Tags_WindSpeed_Enable;
	extern const int BCFG_Tags_WindSpeed_Position_X;
	extern const int BCFG_Tags_WindSpeed_Position_Y;
	extern const int BCFG_Tags_WindSpeed_FontSize;
	extern const unsigned int BCFG_Tags_WindSpeed_TextColor;
	extern const int BCFG_Tags_WindSpeed_EnableShadow;
	extern const unsigned int BCFG_Tags_WindSpeed_ShadowColor;
	extern const int BCFG_Tags_WindSpeed_Align;
	extern const wchar_t BCFG_Tags_WindSpeed_Mask[201];
	extern const int BCFG_Tags_WindSpeed_Unit;


	//-------------------------------------------------- Wind Direction;
	extern const int BCFG_Tags_WindDirection_Enable;
	extern const int BCFG_Tags_WindDirection_Position_X;
	extern const int BCFG_Tags_WindDirection_Position_Y;
	extern const int BCFG_Tags_WindDirection_FontSize;
	extern const unsigned int BCFG_Tags_WindDirection_TextColor;
	extern const int BCFG_Tags_WindDirection_EnableShadow;
	extern const unsigned int BCFG_Tags_WindDirection_ShadowColor;
	extern const int BCFG_Tags_WindDirection_Align;
	extern const int BCFG_Tags_WindDirection_Format;


	//-------------------------------------------------- Time;
	extern const unsigned int BCFG_Tags_Time_Day;
	extern const unsigned int BCFG_Tags_Time_Night;


//-------------------------------------------------- Folders;

	//-------------------------------------------------- Background;
	extern const wchar_t BCFG_Path_Background_StaticBackground[201];
	extern const wchar_t BCFG_Path_Background_DayAndNightBG[201];
	extern const wchar_t BCFG_Path_Background[201];

extern const wchar_t BCFG_XMLBGLogoFolder[201];
extern const wchar_t BCFG_StatesFolder[201];


//-------------------------------------------------- Widget Position;
extern const unsigned int BCFG_WidgetPosition_X;
extern const unsigned int BCFG_WidgetPosition_Y;

extern const int BCFG_HideOnMusic;

#endif
