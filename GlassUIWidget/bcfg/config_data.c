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
		CFGVAR int BCFG_Images_Background_Position_Y = 195; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr6 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Background ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Condition ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr5 = { CFG_LEVEL ,"Condition" , 1 , 0}; // arg3 = Begin Level >>>LevelName=DayState;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr7 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_DayState_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr8 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_DayState_Position_X = 0; // Default X position.
		CFGVAR int BCFG_Images_DayState_Position_Y = 182; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr10 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Condition ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Clock ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr9 = { CFG_LEVEL ,"Clock" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Clock;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr11 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_Clock_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr12 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_Clock_Position_X = 66; // Default X position.
		CFGVAR int BCFG_Images_Clock_Position_Y = 40; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr14 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Clock ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - AccuWeather Logo ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr13 = { CFG_LEVEL ,"AccuWeather Logo" , 1 , 0}; // arg3 = Begin Level >>>LevelName=AccuWeatherLogo;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr15 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Images_AccuWeatherLogo_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr16 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Images_AccuWeatherLogo_Position_X = 169; // Default X position.
		CFGVAR int BCFG_Images_AccuWeatherLogo_Position_Y = 188; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr18 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - AccuWeather Logo ##########################################################################################
	//
	//
CFGVAR CFG_HDR cfghdr19 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Images ##########################################################################################
//
//

//
//
//####################################  Begin Level - Forecast ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr17 = { CFG_LEVEL ,"Forecast" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Tags;

	
	//
	//
	//####################################  Begin Level - Average Temperature ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr20 = { CFG_LEVEL ,"Average Temperature" , 1 , 0}; // arg3 = Begin Level >>>LevelName=AverageTemperature;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr21 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_Enable = 1; // Default (True). 
		
		//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
		CFGVAR CFG_HDR cfghdr22 = { CFG_UTF16_STRING , "Mask" , 0 , 80};
		CFGVAR wchar_t BCFG_Tags_AverageTemperature_Mask[81] = L"%.0f°C"; // Default. 
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr23 = { CFG_CBOX , "Unit" , 0 , 2 }; 
		CFGVAR int BCFG_Tags_AverageTemperature_Unit = 0; // Default item (Celsius).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn23[2] = {"Celsius" , "Fahrenheit"};
		
	CFGVAR CFG_HDR cfghdr25 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Average Temperature ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Condition ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr24 = { CFG_LEVEL ,"Condition" , 1 , 0}; // arg3 = Begin Level >>>LevelName=DayState;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr26 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_DayState_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr27 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_DayState_Position_X = 83; // Default X position.
		CFGVAR int BCFG_Tags_DayState_Position_Y = 213; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr28 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_DayState_FontSize = 0x10; // Default (E_14R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr29 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_DayState_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr30 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_DayState_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn30[3] = {"Left" , "Right" , "Center"};
		
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr31 = { CFG_UINT , "Line Spacing" , 0 , 240};
		CFGVAR unsigned int BCFG_Tags_DayState_LineSpacing = 16; // Default
		
	CFGVAR CFG_HDR cfghdr33 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Condition ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Location ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr32 = { CFG_LEVEL ,"Location" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Location;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr34 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_Location_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr35 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Tags_Location_Position_X = 83; // Default X position.
		CFGVAR int BCFG_Tags_Location_Position_Y = 259; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr36 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Tags_Location_FontSize = 0x10; // Default (E_14R).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr37 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Tags_Location_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr38 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Tags_Location_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn38[3] = {"Left" , "Right" , "Center"};
		
	CFGVAR CFG_HDR cfghdr40 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Location ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Time ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr39 = { CFG_LEVEL ,"Time" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Time;
	
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr41 = { CFG_UINT , "Day" , 0 , 23};
		CFGVAR unsigned int BCFG_Tags_Time_Day = 6; // Default
		
		//---[Number - Unit (Unsigned)]---------------------------------------------------------[Number - Unit (Unsigned)]
		CFGVAR CFG_HDR cfghdr42 = { CFG_UINT , "Night" , 0 , 23};
		CFGVAR unsigned int BCFG_Tags_Time_Night = 18; // Default
		
	CFGVAR CFG_HDR cfghdr44 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Time ##########################################################################################
	//
	//
CFGVAR CFG_HDR cfghdr45 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Forecast ##########################################################################################
//
//

//
//
//####################################  Begin Level - Date/Time ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr43 = { CFG_LEVEL ,"Date/Time" , 1 , 0}; // arg3 = Begin Level >>>LevelName=DateTime;

	
	//
	//
	//####################################  Begin Level - Date ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr46 = { CFG_LEVEL ,"Date" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Date;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr47 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Date_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr48 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_DateTime_Date_Position_X = 0; // Default X position.
		CFGVAR int BCFG_DateTime_Date_Position_Y = 259; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr49 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Date_FontSize = 0x11; // Default (E_14B).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr50 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Date_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr51 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Date_Align = 1; // Default item (Right).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn51[3] = {"Left" , "Right" , "Center"};
		
		
		//
		//
		//####################################  Begin Level - Weekday ########################################################################################
		//****************************************************************************************************************************************************
		CFGVAR CFG_HDR cfghdr52 = { CFG_LEVEL ,"Weekday" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Weekday;
		
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr53 = { CFG_UTF16_STRING , "Sunday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Sunday[201] = L"Sunday"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr54 = { CFG_UTF16_STRING , "Monday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Monday[201] = L"Monday"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr55 = { CFG_UTF16_STRING , "Tuesday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Tuesday[201] = L"Tuesday"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr56 = { CFG_UTF16_STRING , "Wednesday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Wednesday[201] = L"Wednesday"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr57 = { CFG_UTF16_STRING , "Thursday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Thursday[201] = L"Thursday"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr58 = { CFG_UTF16_STRING , "Friday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Friday[201] = L"Friday"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr59 = { CFG_UTF16_STRING , "Saturday" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Weekday_Saturday[201] = L"Saturday"; // Default. 
			
		CFGVAR CFG_HDR cfghdr61 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
		//****************************************************************************************************************************************************
		//####################################  End Level - Weekday ##########################################################################################
		//
		//
		
		//
		//
		//####################################  Begin Level - Month ########################################################################################
		//****************************************************************************************************************************************************
		CFGVAR CFG_HDR cfghdr60 = { CFG_LEVEL ,"Month" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Month;
		
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr62 = { CFG_UTF16_STRING , "January" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_January[201] = L"Jan"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr63 = { CFG_UTF16_STRING , "February" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_February[201] = L"Feb"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr64 = { CFG_UTF16_STRING , "March" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_March[201] = L"Mar"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr65 = { CFG_UTF16_STRING , "April" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_April[201] = L"Apr"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr66 = { CFG_UTF16_STRING , "May" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_May[201] = L"May"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr67 = { CFG_UTF16_STRING , "June" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_June[201] = L"Jun"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr68 = { CFG_UTF16_STRING , "July" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_July[201] = L"Jul"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr69 = { CFG_UTF16_STRING , "August" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_August[201] = L"Aug"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr70 = { CFG_UTF16_STRING , "September" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_September[201] = L"Sep"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr71 = { CFG_UTF16_STRING , "October" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_October[201] = L"Oct"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr72 = { CFG_UTF16_STRING , "November" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_November[201] = L"Nov"; // Default. 
			
			//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
			CFGVAR CFG_HDR cfghdr73 = { CFG_UTF16_STRING , "December" , 0 , 200};
			CFGVAR wchar_t BCFG_Date_Month_December[201] = L"Dec"; // Default. 
			
		CFGVAR CFG_HDR cfghdr75 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
		//****************************************************************************************************************************************************
		//####################################  End Level - Month ##########################################################################################
		//
		//
	CFGVAR CFG_HDR cfghdr76 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Date ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Time ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr74 = { CFG_LEVEL ,"Time" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Time;
	
		
		//
		//
		//####################################  Begin Level - Analog Clock ########################################################################################
		//****************************************************************************************************************************************************
		CFGVAR CFG_HDR cfghdr77 = { CFG_LEVEL ,"Analog Clock" , 1 , 0}; // arg3 = Begin Level >>>LevelName=AnalogClock;
		
			
			//
			//
			//####################################  Begin Level - Hour ########################################################################################
			//****************************************************************************************************************************************************
			CFGVAR CFG_HDR cfghdr78 = { CFG_LEVEL ,"Hour" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Hour;
			
				//---[Check Box]----------------------------------------------------------------------------------[Check Box]
				CFGVAR CFG_HDR cfghdr79 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
				CFGVAR int BCFG_Time_Hour_Enable = 1; // Default (True). 
				
				//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
				CFGVAR CFG_HDR cfghdr80 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
				CFGVAR int BCFG_DateTime_Time_AnalogClock_Hour_Position_X = 99; // Default X position.
				CFGVAR int BCFG_DateTime_Time_AnalogClock_Hour_Position_Y = 82; // Default Y position.
				
				//---[Font]-------------------------------------------------------------------------------------------[Font]
				CFGVAR CFG_HDR cfghdr81 = {CFG_FONT , "Font Size" , 0 , 0};
				CFGVAR int BCFG_Time_Hour_FontSize = 0x31; // Default (E_20R).
				
				//---[Color]-----------------------------------------------------------------------------------------[Color]
				CFGVAR CFG_HDR cfghdr82 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
				CFGVAR unsigned int BCFG_Time_Hour_TextColor = 0xFFFFFFFF; // Default (ffffffff).
				
				//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
				CFGVAR CFG_HDR cfghdr83 = { CFG_CBOX , "Align" , 0 , 3 }; 
				CFGVAR int BCFG_Time_Hour_Align = 0; // Default item (Left).
				CFGVAR CFG_CBOX_ITEM cfgRadioBtn83[3] = {"Left" , "Right" , "Center"};
				
			CFGVAR CFG_HDR cfghdr85 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
			//****************************************************************************************************************************************************
			//####################################  End Level - Hour ##########################################################################################
			//
			//
			
			//
			//
			//####################################  Begin Level - State ########################################################################################
			//****************************************************************************************************************************************************
			CFGVAR CFG_HDR cfghdr84 = { CFG_LEVEL ,"State" , 1 , 0}; // arg3 = Begin Level >>>LevelName=State;
			
				//---[Check Box]----------------------------------------------------------------------------------[Check Box]
				CFGVAR CFG_HDR cfghdr86 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
				CFGVAR int BCFG_Time_State_Enable = 1; // Default (True). 
				
				//---[Rectangle]-------------------------------------------------------------------------------------[Rectangle]
				CFGVAR CFG_HDR cfghdr87 = {CFG_RECT , "Position" , 0 , 0};
				CFGVAR RECT BCFG_Time_AnalogClock_State_Position = {63 , 171 , 146 , 178}; // Format -> {x1,x2 , y1,y2}
				
				//---[Font]-------------------------------------------------------------------------------------------[Font]
				CFGVAR CFG_HDR cfghdr88 = {CFG_FONT , "Font Size" , 0 , 0};
				CFGVAR int BCFG_Time_State_FontSize = 0x11; // Default (E_14B).
				
				//---[Color]-----------------------------------------------------------------------------------------[Color]
				CFGVAR CFG_HDR cfghdr89 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
				CFGVAR unsigned int BCFG_Time_State_TextColor = 0xFFFFFFFF; // Default (ffffffff).
				
				//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
				CFGVAR CFG_HDR cfghdr90 = { CFG_CBOX , "Align" , 0 , 3 }; 
				CFGVAR int BCFG_Time_State_Align = 0; // Default item (Left).
				CFGVAR CFG_CBOX_ITEM cfgRadioBtn90[3] = {"Left" , "Right" , "Center"};
				
			CFGVAR CFG_HDR cfghdr92 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
			//****************************************************************************************************************************************************
			//####################################  End Level - State ##########################################################################################
			//
			//
		CFGVAR CFG_HDR cfghdr93 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
		//****************************************************************************************************************************************************
		//####################################  End Level - Analog Clock ##########################################################################################
		//
		//
		
		//
		//
		//####################################  Begin Level - Digital Clock ########################################################################################
		//****************************************************************************************************************************************************
		CFGVAR CFG_HDR cfghdr91 = { CFG_LEVEL ,"Digital Clock" , 1 , 0}; // arg3 = Begin Level >>>LevelName=DigitalClock;
		
			//---[Check Box]----------------------------------------------------------------------------------[Check Box]
			CFGVAR CFG_HDR cfghdr94 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
			CFGVAR int BCFG_Time_DigitalClock_Enable = 1; // Default (True). 
			
			//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
			CFGVAR CFG_HDR cfghdr95 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
			CFGVAR int BCFG_DateTime_Time_DigitalClock_Position_X = 150; // Default X position.
			CFGVAR int BCFG_DateTime_Time_DigitalClock_Position_Y = 259; // Default Y position.
			
			//---[Font]-------------------------------------------------------------------------------------------[Font]
			CFGVAR CFG_HDR cfghdr96 = {CFG_FONT , "Font Size" , 0 , 0};
			CFGVAR int BCFG_Time_DigitalClock_FontSize = 0x11; // Default (E_14B).
			
			//---[Color]-----------------------------------------------------------------------------------------[Color]
			CFGVAR CFG_HDR cfghdr97 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
			CFGVAR unsigned int BCFG_Time_DigitalClock_TextColor = 0xFFFFFFFF; // Default (ffffffff).
			
			//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
			CFGVAR CFG_HDR cfghdr98 = { CFG_CBOX , "Align" , 0 , 3 }; 
			CFGVAR int BCFG_Time_DigitalClock_Align = 0; // Default item (Left).
			CFGVAR CFG_CBOX_ITEM cfgRadioBtn98[3] = {"Left" , "Right" , "Center"};
			
			
			//
			//
			//####################################  Begin Level - AM/PM ########################################################################################
			//****************************************************************************************************************************************************
			CFGVAR CFG_HDR cfghdr99 = { CFG_LEVEL ,"AM/PM" , 1 , 0}; // arg3 = Begin Level >>>LevelName=AMPM;
			
				//---[Check Box]----------------------------------------------------------------------------------[Check Box]
				CFGVAR CFG_HDR cfghdr100 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
				CFGVAR int BCFG_Time_AMPM_Enable = 1; // Default (True). 
				
				//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
				CFGVAR CFG_HDR cfghdr101 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
				CFGVAR int BCFG_DateTime_Time_DigitalClock_AMPM_Position_X = 150; // Default X position.
				CFGVAR int BCFG_DateTime_Time_DigitalClock_AMPM_Position_Y = 259; // Default Y position.
				
				//---[Font]-------------------------------------------------------------------------------------------[Font]
				CFGVAR CFG_HDR cfghdr102 = {CFG_FONT , "Font Size" , 0 , 0};
				CFGVAR int BCFG_Time_AMPM_FontSize = 0x11; // Default (E_14B).
				
				//---[Color]-----------------------------------------------------------------------------------------[Color]
				CFGVAR CFG_HDR cfghdr103 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
				CFGVAR unsigned int BCFG_Time_AMPM_TextColor = 0xFFFFFFFF; // Default (ffffffff).
				
				//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
				CFGVAR CFG_HDR cfghdr104 = { CFG_CBOX , "Align" , 0 , 3 }; 
				CFGVAR int BCFG_Time_AMPM_Align = 0; // Default item (Left).
				CFGVAR CFG_CBOX_ITEM cfgRadioBtn104[3] = {"Left" , "Right" , "Center"};
				
			CFGVAR CFG_HDR cfghdr106 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
			//****************************************************************************************************************************************************
			//####################################  End Level - AM/PM ##########################################################################################
			//
			//
		CFGVAR CFG_HDR cfghdr107 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
		//****************************************************************************************************************************************************
		//####################################  End Level - Digital Clock ##########################################################################################
		//
		//
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr105 = { CFG_CBOX , "Type" , 0 , 2 }; 
		CFGVAR int BCFG_Time_Type = 0; // Default item (Analog).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn105[2] = {"Analog" , "Digital"};
		
	CFGVAR CFG_HDR cfghdr109 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Time ##########################################################################################
	//
	//
CFGVAR CFG_HDR cfghdr110 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Date/Time ##########################################################################################
//
//

//
//
//####################################  Begin Level - Music ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr108 = { CFG_LEVEL ,"Music" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Music;

	
	//
	//
	//####################################  Begin Level - Coverart ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr111 = { CFG_LEVEL ,"Coverart" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Coverart;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr112 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Coverart_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr113 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Coverart_Position_X = 150; // Default X position.
		CFGVAR int BCFG_Music_Coverart_Position_Y = 259; // Default Y position.
		
	CFGVAR CFG_HDR cfghdr115 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Coverart ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Artist ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr114 = { CFG_LEVEL ,"Artist" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Artist;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr116 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Artist_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr117 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Artist_Position_X = 150; // Default X position.
		CFGVAR int BCFG_Music_Artist_Position_Y = 259; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr118 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Music_Artist_FontSize = 0x11; // Default (E_14B).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr119 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Music_Artist_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr120 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Music_Artist_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn120[3] = {"Left" , "Right" , "Center"};
		
	CFGVAR CFG_HDR cfghdr122 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Artist ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Title ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr121 = { CFG_LEVEL ,"Title" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Title;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr123 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Title_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr124 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Title_Position_X = 150; // Default X position.
		CFGVAR int BCFG_Music_Title_Position_Y = 259; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr125 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Music_Title_FontSize = 0x11; // Default (E_14B).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr126 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Music_Title_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr127 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Music_Title_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn127[3] = {"Left" , "Right" , "Center"};
		
	CFGVAR CFG_HDR cfghdr129 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Title ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Time ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr128 = { CFG_LEVEL ,"Time" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Time;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr130 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Time_Enable = 1; // Default (True). 
		
		//---[X,Y Position]-------------------------------------------------------------------------------[X,Y Position]
		CFGVAR CFG_HDR cfghdr131 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
		CFGVAR int BCFG_Music_Time_Position_X = 150; // Default X position.
		CFGVAR int BCFG_Music_Time_Position_Y = 259; // Default Y position.
		
		//---[Font]-------------------------------------------------------------------------------------------[Font]
		CFGVAR CFG_HDR cfghdr132 = {CFG_FONT , "Font Size" , 0 , 0};
		CFGVAR int BCFG_Music_Time_FontSize = 0x11; // Default (E_14B).
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr133 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Music_Time_TextColor = 0xFFFFFFFF; // Default (ffffffff).
		
		//---[Radio Button]-----------------------------------------------------------------------------[Radio Button]
		CFGVAR CFG_HDR cfghdr134 = { CFG_CBOX , "Align" , 0 , 3 }; 
		CFGVAR int BCFG_Music_Time_Align = 0; // Default item (Left).
		CFGVAR CFG_CBOX_ITEM cfgRadioBtn134[3] = {"Left" , "Right" , "Center"};
		
	CFGVAR CFG_HDR cfghdr136 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Time ##########################################################################################
	//
	//
	
	//
	//
	//####################################  Begin Level - Progress Bar ########################################################################################
	//****************************************************************************************************************************************************
	CFGVAR CFG_HDR cfghdr135 = { CFG_LEVEL ,"Progress Bar" , 1 , 0}; // arg3 = Begin Level >>>LevelName=ProgressBar;
	
		//---[Check Box]----------------------------------------------------------------------------------[Check Box]
		CFGVAR CFG_HDR cfghdr137 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
		CFGVAR int BCFG_Music_ProgressBar_Enable = 1; // Default (True). 
		
		//---[Rectangle]-------------------------------------------------------------------------------------[Rectangle]
		CFGVAR CFG_HDR cfghdr138 = {CFG_RECT , "Position" , 0 , 0};
		CFGVAR RECT BCFG_Music_ProgressBar_Position = {64 , 178 , 177 , 183}; // Format -> {x1,x2 , y1,y2}
		
		//---[Color]-----------------------------------------------------------------------------------------[Color]
		CFGVAR CFG_HDR cfghdr139 = { CFG_COLOR_INT , "Color" , 0 , 0}; 
		CFGVAR unsigned int BCFG_Music_ProgressBar_Color = 0xFF000000; // Default (ff000000).
		
	CFGVAR CFG_HDR cfghdr141 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
	//****************************************************************************************************************************************************
	//####################################  End Level - Progress Bar ##########################################################################################
	//
	//
CFGVAR CFG_HDR cfghdr142 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Music ##########################################################################################
//
//

//
//
//####################################  Begin Level - Folders ########################################################################################
//****************************************************************************************************************************************************
CFGVAR CFG_HDR cfghdr140 = { CFG_LEVEL ,"Folders" , 1 , 0}; // arg3 = Begin Level >>>LevelName=Path;

	//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
	CFGVAR CFG_HDR cfghdr143 = { CFG_UTF16_STRING , "XML / BG / Logo" , 0 , 200};
	CFGVAR wchar_t BCFG_XMLBGLogoFolder[201] = L"/usb/other/Zbin/Config/GlassUIWidget/"; // Default. 
	
	//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
	CFGVAR CFG_HDR cfghdr144 = { CFG_UTF16_STRING , "States" , 0 , 200};
	CFGVAR wchar_t BCFG_StatesFolder[201] = L"/usb/other/Zbin/Config/GlassUIWidget/States/"; // Default. 
	
	//---[Text - Unicode]----------------------------------------------------------------[Text - Unicode]
	CFGVAR CFG_HDR cfghdr145 = { CFG_UTF16_STRING , "Clock" , 0 , 200};
	CFGVAR wchar_t BCFG_Path_Clock[201] = L"/usb/other/Zbin/Config/GlassUIWidget/clock/"; // Default. 
	
CFGVAR CFG_HDR cfghdr146 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
//****************************************************************************************************************************************************
//####################################  End Level - Folders ##########################################################################################
//
//
