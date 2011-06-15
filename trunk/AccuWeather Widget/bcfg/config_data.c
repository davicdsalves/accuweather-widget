//##################################################################################################
//## ******************************************************************************************** ##
//## *                       The Code Created by ConfigCodeMaker v1.0                           * ##
//## *                       (Copyright) 2009 - Scorpion 16 (X) Richi.                          * ##
//## ******************************************************************************************** ##
//##################################################################################################


#include "..\..\include\cfg_items.h"
#include "config_data.h"

#pragma diag_suppress = Pe177


//
//
//####################################  Begin Level - Images ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr1 = { CFG_LEVEL ,"Images" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Images;

	
	//
	//
	//####################################  Begin Level - Background ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr2 = { CFG_LEVEL ,"Background" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Background;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr3 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_Background_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr4 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_Background_Position_X = 0; // Default X position.
		CFGVAR int BCFG_Images_Background_Position_Y = 13; // Default Y position.
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr5 = { CFG_CBOX , "Method" , 0 , 3 }; 
		CFGVAR int BCFG_Images_Background_Method = 0; // Default item (Single).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn5[3] = {"Single" , "Day and Night" , "Animated Day and Night"};
		
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr6 = { CFG_UINT , "Refresh Time" , 0 , 5000};
		CFGVAR unsigned int BCFG_RefreshTime = 20; // Default
		
	CFGVAR CFG_HDR cfghdr8 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Background ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Condition ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr7 = { CFG_LEVEL ,"Condition" , 1 , 0}; // arg3 = Begin Level >>>LevelName=DayState;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr9 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_DayState_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr10 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_DayState_Position_X = 0; // Default X position.
		CFGVAR int BCFG_Images_DayState_Position_Y = 0; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr12 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Condition ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - AccuWeather Logo ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr11 = { CFG_LEVEL ,"AccuWeather Logo" , 1 , 0}; // arg3 = Begin Level >>>LevelName=AccuWeatherLogo;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr13 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_AccuWeatherLogo_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr14 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_AccuWeatherLogo_Position_X = 155; // Default X position.
		CFGVAR int BCFG_Images_AccuWeatherLogo_Position_Y = 79; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr16 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - AccuWeather Logo ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Wind Direction ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr15 = { CFG_LEVEL ,"Wind Direction" , 1 , 0}; // arg3 = Begin Level >>>LevelName=WindDirection;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr17 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_WindDirection_Enable = 0; // Default (False). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr18 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_WindDirection_Position_X = 195; // Default X position.
		CFGVAR int BCFG_Images_WindDirection_Position_Y = 128; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr20 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Wind Direction ##########################################################################################
	//
	//
	//---[Check Box]----------------------------------------------------------------------------------[Check Box]
	CFGVAR CFG_HDR cfghdr19 = {CFG_CHECKBOX , "Images on Top of Text" , 0 , 0 }; 
	CFGVAR int BCFG_Images_ImageOnTop = 0; // Default (False). 
	
CFGVAR CFG_HDR cfghdr22 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Images ##########################################################################################
//
//

//
//
//####################################  Begin Level - Forecast ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr21 = { CFG_LEVEL ,"Forecast" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Tags;

	
	//
	//
	//####################################  Begin Level - Min Temperature ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr23 = { CFG_LEVEL ,"Min Temperature" , 1 , 0}; // arg3 = Begin Level >>>LevelName=MinTemperature;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr24 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_MinTemperature_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr25 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_MinTemperature_Position_X = 80; // Default X position.
		CFGVAR int BCFG_Tags_MinTemperature_Position_Y = 74; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr26 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_MinTemperature_FontSize = 0x10; // Default (E_14R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr27 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_MinTemperature_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr28 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_MinTemperature_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr29 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_MinTemperature_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr30 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_MinTemperature_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn30[3] = {"Left" , "Right" , "Center"};
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr31 = { CFG_UTF16_STRING , "Mask" , 0 , 80};
		CFGVAR wchar_t BCFG_Tags_MinTemperature_Mask[81] = L"%.0f°C /"; // Default. 
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr32 = { CFG_CBOX , "Unit" , 0 , 2 }; 
		CFGVAR int BCFG_Tags_MinTemperature_Unit = 0; // Default item (Celsius).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn32[2] = {"Celsius" , "Fahrenheit"};
		
	CFGVAR CFG_HDR cfghdr34 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Min Temperature ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Average Temperature ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr33 = { CFG_LEVEL ,"Average Temperature" , 1 , 0}; // arg3 = Begin Level >>>LevelName=AverageTemperature;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr35 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr36 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_Position_X = 180; // Default X position.
		CFGVAR int BCFG_Tags_AverageTemperature_Position_Y = 55; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr37 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_AverageTemperature_FontSize = 0x17; // Default (E_16R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr38 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_AverageTemperature_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr39 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr40 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_AverageTemperature_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr41 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn41[3] = {"Left" , "Right" , "Center"};
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr42 = { CFG_UTF16_STRING , "Mask" , 0 , 80};
		CFGVAR wchar_t BCFG_Tags_AverageTemperature_Mask[81] = L"%.0f°C"; // Default. 
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr43 = { CFG_CBOX , "Unit" , 0 , 2 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_Unit = 0; // Default item (Celsius).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn43[2] = {"Celsius" , "Fahrenheit"};
		
	CFGVAR CFG_HDR cfghdr45 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Average Temperature ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Max Temperature ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr44 = { CFG_LEVEL ,"Max Temperature" , 1 , 0}; // arg3 = Begin Level >>>LevelName=MaxTemperature;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr46 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_MaxTemperature_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr47 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_MaxTemperature_Position_X = 128; // Default X position.
		CFGVAR int BCFG_Tags_MaxTemperature_Position_Y = 74; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr48 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_MaxTemperature_FontSize = 0x10; // Default (E_14R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr49 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_MaxTemperature_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr50 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_MaxTemperature_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr51 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_MaxTemperature_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr52 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_MaxTemperature_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn52[3] = {"Left" , "Right" , "Center"};
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr53 = { CFG_UTF16_STRING , "Mask" , 0 , 80};
		CFGVAR wchar_t BCFG_Tags_MaxTemperature_Mask[81] = L"%.0f°C"; // Default. 
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr54 = { CFG_CBOX , "Unit" , 0 , 2 }; 
		CFGVAR int BCFG_Tags_MaxTemperature_Unit = 0; // Default item (Celsius).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn54[2] = {"Celsius" , "Fahrenheit"};
		
	CFGVAR CFG_HDR cfghdr56 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Max Temperature ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Condition ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr55 = { CFG_LEVEL ,"Condition" , 1 , 0}; // arg3 = Begin Level >>>LevelName=DayState;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr57 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_DayState_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr58 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_DayState_Position_X = 80; // Default X position.
		CFGVAR int BCFG_Tags_DayState_Position_Y = 57; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr59 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_DayState_FontSize = 0x10; // Default (E_14R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr60 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_DayState_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr61 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_DayState_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr62 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_DayState_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr63 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_DayState_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn63[3] = {"Left" , "Right" , "Center"};
		
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr64 = { CFG_UINT , "Line Spacing" , 0 , 240};
		CFGVAR unsigned int BCFG_Tags_DayState_LineSpacing = 20; // Default
		
	CFGVAR CFG_HDR cfghdr66 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Condition ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Location ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr65 = { CFG_LEVEL ,"Location" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Location;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr67 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_Location_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr68 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_Location_Position_X = 80; // Default X position.
		CFGVAR int BCFG_Tags_Location_Position_Y = 43; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr69 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_Location_FontSize = 0x10; // Default (E_14R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr70 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_Location_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr71 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_Location_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr72 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_Location_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr73 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_Location_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn73[3] = {"Left" , "Right" , "Center"};
		
	CFGVAR CFG_HDR cfghdr75 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Location ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Wind Speed ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr74 = { CFG_LEVEL ,"Wind Speed" , 1 , 0}; // arg3 = Begin Level >>>LevelName=WindSpeed;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr76 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_WindSpeed_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr77 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_WindSpeed_Position_X = 187; // Default X position.
		CFGVAR int BCFG_Tags_WindSpeed_Position_Y = 78; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr78 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_WindSpeed_FontSize = 0x9; // Default (D_7R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr79 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_WindSpeed_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr80 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_WindSpeed_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr81 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_WindSpeed_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr82 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_WindSpeed_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn82[3] = {"Left" , "Right" , "Center"};
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr83 = { CFG_UTF16_STRING , "Mask" , 0 , 200};
		CFGVAR wchar_t BCFG_Tags_WindSpeed_Mask[201] = L"%.1f Km/h"; // Default. 
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr84 = { CFG_CBOX , "Unit" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_WindSpeed_Unit = 0; // Default item (Kilometer).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn84[3] = {"Kilometer" , "Miles" , "Meter"};
		
	CFGVAR CFG_HDR cfghdr86 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Wind Speed ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Wind Direction ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr85 = { CFG_LEVEL ,"Wind Direction" , 1 , 0}; // arg3 = Begin Level >>>LevelName=WindDirection;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr87 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_WindDirection_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr88 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_WindDirection_Position_X = 194; // Default X position.
		CFGVAR int BCFG_Tags_WindDirection_Position_Y = 47; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr89 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_WindDirection_FontSize = 0x9; // Default (D_7R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr90 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_WindDirection_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr91 = {CFG_CHECKBOX , "Enable Shadow" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_WindDirection_EnableShadow = 0; // Default (False). 
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr92 = { CFG_COLOR_INT , "Shadow Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_WindDirection_ShadowColor = 0xFF000000; // Default (ff000000).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr93 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_WindDirection_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn93[3] = {"Left" , "Right" , "Center"};
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr94 = { CFG_CBOX , "Format" , 0 , 2 }; 
		CFGVAR int BCFG_Tags_WindDirection_Format = 0; // Default item (Short).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn94[2] = {"Short" , "Long"};
		
	CFGVAR CFG_HDR cfghdr96 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Wind Direction ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Time ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr95 = { CFG_LEVEL ,"Time" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Time;
	
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr97 = { CFG_UINT , "Day" , 0 , 23};
		CFGVAR unsigned int BCFG_Tags_Time_Day = 6; // Default
		
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr98 = { CFG_UINT , "Night" , 0 , 23};
		CFGVAR unsigned int BCFG_Tags_Time_Night = 18; // Default
		
	CFGVAR CFG_HDR cfghdr100 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Time ##########################################################################################
	//
	//
CFGVAR CFG_HDR cfghdr101 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Forecast ##########################################################################################
//
//

//
//
//####################################  Begin Level - Folders ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr99 = { CFG_LEVEL ,"Folders" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Path;

	
	//
	//
	//####################################  Begin Level - Background ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr102 = { CFG_LEVEL ,"Background" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Background;
	
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr103 = { CFG_UTF16_STRING , "Single Background" , 0 , 200};
		CFGVAR wchar_t BCFG_Path_Background_StaticBackground[201] = L"/usb/other/Zbin/Config/AccuWeather/bg/single/"; // Default. 
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr104 = { CFG_UTF16_STRING , "Day and Night BG" , 0 , 200};
		CFGVAR wchar_t BCFG_Path_Background_DayAndNightBG[201] = L"/usb/other/Zbin/Config/AccuWeather/bg/daynight/"; // Default. 
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr105 = { CFG_UTF16_STRING , "Animated Background" , 0 , 200};
		CFGVAR wchar_t BCFG_Path_Background[201] = L"/usb/other/Zbin/Config/AccuWeather/bg/animated/"; // Default. 
		
	CFGVAR CFG_HDR cfghdr107 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Background ##########################################################################################
	//
	//
	//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
	CFGVAR CFG_HDR cfghdr106 = { CFG_UTF16_STRING , "XML & Logo" , 0 , 200};
	CFGVAR wchar_t BCFG_XMLBGLogoFolder[201] = L"/usb/other/Zbin/Config/AccuWeather/"; // Default. 
	
	//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
	CFGVAR CFG_HDR cfghdr108 = { CFG_UTF16_STRING , "States" , 0 , 200};
	CFGVAR wchar_t BCFG_StatesFolder[201] = L"/usb/other/Zbin/Config/AccuWeather/States/"; // Default. 
	
CFGVAR CFG_HDR cfghdr110 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Folders ##########################################################################################
//
//

//
//
//####################################  Begin Level - Widget Position ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr109 = { CFG_LEVEL ,"Widget Position" , 1 , 0}; // arg3 = Begin Level >>>LevelName=WidgetPosition;

	//---[Number - Integer (signed)]---------------------------------------------------------[Number - Integer (signed)]
	CFGVAR CFG_HDR cfghdr111 = { CFG_INT , "X" , 0 , 240};
	CFGVAR unsigned int BCFG_WidgetPosition_X = 0; // Default
	
	//---[Number - Integer (signed)]---------------------------------------------------------[Number - Integer (signed)]
	CFGVAR CFG_HDR cfghdr112 = { CFG_INT , "Y" , 0 , 240};
	CFGVAR unsigned int BCFG_WidgetPosition_Y = 0; // Default
	
CFGVAR CFG_HDR cfghdr114 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Widget Position ##########################################################################################
//
//
//---[Check Box]----------------------------------------------------------------------------------[Check Box]
CFGVAR CFG_HDR cfghdr113 = {CFG_CHECKBOX , "Hide on music" , 0 , 0 }; 
CFGVAR int BCFG_HideOnMusic = 0; // Default (False). 

