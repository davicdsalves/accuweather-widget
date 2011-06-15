#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "..\..\include\cfg_items.h"
#include "..\bcfg\config_data.h"
#include "..\bcfg\conf_loader.h"
#include "..\file\openfile.h"
#include "..\file\fileAnaliser.h"
#include "..\utils\weather.h"
#include "..\utils\utils.h"
#include "..\mybook.h"
#include "standbyDraw.h"
#include "stdby.h"

MyBook* mybook;

//<!--bookmanager
void Send_REDRAW_RELEASE() {
  REDRAW_RELEASE_MESSAGE * sbm= new REDRAW_RELEASE_MESSAGE;
  memset(sbm,0,sizeof(REDRAW_RELEASE_MESSAGE));
  sbm->SB_OldOnRedraw=SIonRedraw;
  sbm->SB_NewOnRedraw=Draw;
  UI_Event_wData(SBY_REDRAW_RELEASE_EVENT ,sbm,(void (*)(void*))mfree_adr());
}


//-->

void drawOnStby(wchar_t* message, int fontSize, int align, int x, int y, int textColor ) {
  int displayWidth = Display_GetWidth( 0 );
  int displayHeigth = Display_GetHeight( 0 );
  int msgSize = wstrlen(message);
  if (searchLine(message)) {
    int indexLine = wGetIndexOfLine(message);
    wchar_t* line1 = getWSubStr(message,0,indexLine-1);
    wchar_t* line2 = getWSubStr(message,indexLine+2,wstrlen(message));
    msgSize = wstrlen(line1);
    
    TEXTID drawText = TextID_Create(line1, ENC_UCS2 , msgSize);
    SetFont(fontSize);
#if defined(DB3210)|| defined(DB3200) || defined (DB3350)
    DrawString( drawText , align , x , y , displayWidth, displayHeigth , 0 , 0 , textColor , textColor );
#elif defined(DB3150) || defined(DB2020)
    DrawString( drawText , align , x , y , displayWidth, displayHeigth , 60 , 0x05 , textColor , textColor );    
#endif
    TextID_Destroy( drawText );

    delete line1; 
    line1 = NULL;
    drawOnStby(line2, fontSize, align, x, y + BCFG_Tags_DayState_LineSpacing, textColor );
    delete line2;
    line2 = NULL;
  }
  else {
    TEXTID drawText = TextID_Create(message, ENC_UCS2 , msgSize);
    SetFont(fontSize);
    DrawString( drawText , align , x , y , displayWidth, displayHeigth , 60 , 0x05 , textColor , textColor );
    TextID_Destroy( drawText );
  }
}

void Draw(DISP_OBJ* db,int r1, int r2,int r3) { //change lines for w800
  if (SIonRedraw) SIonRedraw(db,r1,r2,r3);
  BCFG_HideOnMusic ? (!FindBook(get_IsAudioPlayerBook()) ? drawWeatherContents() : mybook->donothing() ) : drawWeatherContents();

} 

void drawForShadow( wchar_t* message, int fontSize, int align, int x, int y, unsigned int color, unsigned int shadowColor, bool shadowEnable) {
  if (shadowEnable)
    drawOnStby( message , fontSize , align , x - 2 + BCFG_WidgetPosition_X, y + BCFG_WidgetPosition_Y, shadowColor );
  drawOnStby( message , fontSize , align , x + BCFG_WidgetPosition_X, y + BCFG_WidgetPosition_Y, color );
}

wchar_t* returnMask(const wchar_t* mask, int tag, bool contentIf, float (*func)(int) , int cond=0) {
  int sizeOfTemp = wstrlen(mask) + intlen(tag);
  wchar_t* newMask = new wchar_t[ sizeOfTemp + 0x1 ];
  snwprintf( newMask, sizeOfTemp, mask, ( contentIf == cond ? tag : (*func)(tag) ) );
  newMask[sizeOfTemp] = 0;
  return newMask;
}
void manageCursor() {
  (mybook->cursorDown) ? mybook->addCursor(-1) : mybook->addCursor(1);
  if (mybook->getCursor() == 0) { mybook->cursorDown = false; mybook->changeWallpaper = false; }
  if (mybook->getCursor() == 19) { mybook->cursorDown = true; mybook->changeWallpaper = false; }
  
}
void finalDraw(wchar_t* location, int dayState, int tempMin, int tempMax, int windSpeed, wchar_t* state, wchar_t* windDirection, int averageTemp) {
  wchar_t* temp = NULL;
  //<!--images
  if (BCFG_Images_Background_Enable) {
    if (BCFG_Images_Background_Method == 0) 
      DrawImage(mybook->getGC(), BCFG_Images_Background_Position_X , BCFG_Images_Background_Position_Y, statesID[0x0] );
    else if (BCFG_Images_Background_Method == 1)
      DrawImage(mybook->getGC(), BCFG_Images_Background_Position_X , BCFG_Images_Background_Position_Y, statesID[ 0x1 + mybook->wallpaperType ] );
    else {
      DrawImage(mybook->getGC(), BCFG_Images_Background_Position_X , BCFG_Images_Background_Position_Y, bgID[ mybook->getCursor() ] );
      if (mybook->changeWallpaper) manageCursor();
    }
  }
  
  if (BCFG_Images_AccuWeatherLogo_Enable)
    DrawImage(mybook->getGC(), BCFG_Images_AccuWeatherLogo_Position_X , BCFG_Images_AccuWeatherLogo_Position_Y , statesID[0x1] );
    
  if (!BCFG_Images_ImageOnTop && BCFG_Images_DayState_Enable)
      DrawImage(mybook->getGC(), BCFG_Images_DayState_Position_X , BCFG_Images_DayState_Position_Y , statesID[dayState+0x3] );
  //-->
  //<!--text
  if (BCFG_Tags_Location_Enable)
    drawForShadow( location , BCFG_Tags_Location_FontSize , BCFG_Tags_Location_Align , BCFG_Tags_Location_Position_X ,
                  BCFG_Tags_Location_Position_Y - 16 , BCFG_Tags_Location_TextColor , BCFG_Tags_Location_ShadowColor ,
                  BCFG_Tags_Location_EnableShadow );
  
    
  
  if (BCFG_Tags_MinTemperature_Enable) {//L: %d
    temp = returnMask( BCFG_Tags_MinTemperature_Mask , tempMin , BCFG_Tags_MinTemperature_Unit , celsiusToFahrenheit );
   
    drawForShadow( temp , BCFG_Tags_MinTemperature_FontSize , BCFG_Tags_MinTemperature_Align , BCFG_Tags_MinTemperature_Position_X,
                  BCFG_Tags_MinTemperature_Position_Y - 16 , BCFG_Tags_MinTemperature_TextColor , BCFG_Tags_MinTemperature_ShadowColor,
                  BCFG_Tags_MinTemperature_EnableShadow );

    delete temp; temp = NULL;
  }
  
  if (BCFG_Tags_MaxTemperature_Enable) { //H: %d
    temp = returnMask( BCFG_Tags_MaxTemperature_Mask , tempMax , BCFG_Tags_MaxTemperature_Unit , celsiusToFahrenheit );
    
    drawForShadow( temp , BCFG_Tags_MaxTemperature_FontSize , BCFG_Tags_MaxTemperature_Align , BCFG_Tags_MaxTemperature_Position_X,
                  BCFG_Tags_MaxTemperature_Position_Y - 16 , BCFG_Tags_MaxTemperature_TextColor , BCFG_Tags_MaxTemperature_ShadowColor,
                  BCFG_Tags_MaxTemperature_EnableShadow );
    delete temp; temp = NULL;
  }
  
  if (BCFG_Tags_WindSpeed_Enable) {// %d KM/H
    if (BCFG_Tags_WindSpeed_Unit == 2)
      temp = returnMask( BCFG_Tags_WindSpeed_Mask , windSpeed , BCFG_Tags_WindSpeed_Unit , km2meter );
    else
      temp = returnMask( BCFG_Tags_WindSpeed_Mask , windSpeed , BCFG_Tags_WindSpeed_Unit , km2Mile );
    
    drawForShadow( temp , BCFG_Tags_WindSpeed_FontSize , BCFG_Tags_WindSpeed_Align , BCFG_Tags_WindSpeed_Position_X,
                  BCFG_Tags_WindSpeed_Position_Y - 16 , BCFG_Tags_WindSpeed_TextColor , BCFG_Tags_WindSpeed_ShadowColor,
                  BCFG_Tags_WindSpeed_EnableShadow );
    delete temp; temp = NULL;
  }

  if (BCFG_Tags_AverageTemperature_Enable) {// %d
    temp = returnMask( BCFG_Tags_AverageTemperature_Mask , averageTemp , BCFG_Tags_AverageTemperature_Unit , celsiusToFahrenheit );
    
    drawForShadow( temp , BCFG_Tags_AverageTemperature_FontSize , BCFG_Tags_AverageTemperature_Align , BCFG_Tags_AverageTemperature_Position_X,
                  BCFG_Tags_AverageTemperature_Position_Y - 16 , BCFG_Tags_AverageTemperature_TextColor , BCFG_Tags_AverageTemperature_ShadowColor,
                  BCFG_Tags_AverageTemperature_EnableShadow );
    delete temp; temp = NULL;
  }
  
  if (BCFG_Tags_DayState_Enable)
    drawForShadow( state , BCFG_Tags_DayState_FontSize , BCFG_Tags_DayState_Align , BCFG_Tags_DayState_Position_X,
                  BCFG_Tags_DayState_Position_Y - 16 , BCFG_Tags_DayState_TextColor , BCFG_Tags_DayState_ShadowColor,
                  BCFG_Tags_DayState_EnableShadow );
  
  if (BCFG_Tags_WindDirection_Enable)
    drawForShadow( windDirection , BCFG_Tags_WindDirection_FontSize , BCFG_Tags_WindDirection_Align , BCFG_Tags_WindDirection_Position_X,
                  BCFG_Tags_WindDirection_Position_Y - 16 , BCFG_Tags_WindDirection_TextColor , BCFG_Tags_WindDirection_ShadowColor,
                  BCFG_Tags_WindDirection_EnableShadow );
  //-->
  //<!--image again
  if (BCFG_Images_ImageOnTop && BCFG_Images_DayState_Enable)
    DrawImage(mybook->getGC(), BCFG_Images_DayState_Position_X , BCFG_Images_DayState_Position_Y , statesID[dayState+0x3] );
  //-->

}

void onfTimer (u16 tmr , LPARAM) {
  DispObject_InvalidateRect(StatusIndication,0);
  int refresh;
  (BCFG_Images_Background_Method == 2 && BCFG_Images_Background_Enable && mybook->changeWallpaper) ? refresh = BCFG_RefreshTime : refresh = 1000;
  Timer_ReSet(&mybook->ftimer,refresh,onfTimer,0);
}
void checkWallpaper(int type) { //1 = dia, 2 = noite
  if (mybook->wallpaperType != type && BCFG_Images_Background_Method == 2) {
    (type == 1) ? mybook->setCursor(19) : mybook->setCursor(0);
    mybook->changeWallpaper = true;
    mybook->wallpaperType = type;
  }
}
void drawWeatherContents() {
  //18 ~ 06: night, 06 ~ 18: day
  DATETIME now = getDateTime();
  if (mybook->getHourSeted() == -1) {
    if (mybook->getWeatherToDraw() != NULL) mybook->freeWDraw();
    mybook->setHour(now.time.hour);

    if (now.time.hour >= BCFG_Tags_Time_Night || now.time.hour < BCFG_Tags_Time_Day) {//need to check that later, midnight weather!
      checkWallpaper(2);
      mybook->setWDraw(2);
    }
    else {
      checkWallpaper(1);
      mybook->setWDraw(1);
    }
  }
  
  if (mybook->getHourSeted() != now.time.hour) mybook->setHour(-1);
  
  finalDraw(mybook->getLocation(), mybook->getWeatherToDraw()->getState() , mybook->getWeatherToDraw()->getTempMin(), mybook->getWeatherToDraw()->getTempMax(), 
            mybook->getWeatherToDraw()->getWindSpeed(), mybook->getWeatherToDraw()->getState_(), 
            ((BCFG_Tags_WindDirection_Format == 0) ? mybook->getWeatherToDraw()->getWindDirection() : mybook->getWeatherToDraw()->getLongWind()),
            mybook->getWeatherToDraw()->getAverageTemp());

  if (isDateEqual(&now,&mybook->dateOfWeather) != 0) {
    mybook->setHour(-1);
    beginFile();
  }  
}

void errorInFile(wchar_t* message) {
  MessageBox(0x6FFFFFFF,TextID_Create(message,ENC_UCS2 , wstrlen(message)), NOIMAGE, 1, 0,0);
  mybook->setError(true);
  message = NULL;
  FreeBook(mybook->getBook());
}

void beginFile() {
  wchar_t* fileContent = openFile(BCFG_XMLBGLogoFolder,L"weather.txt");
  wchar_t* conditionXml = openFile(BCFG_XMLBGLogoFolder, L"condition.xml");
  if (fileContent != NULL && conditionXml != NULL) {
    int pos = 0;
    mybook->freeMyVars();
    mybook->setLocation(getLocation(fileContent, pos));

    if (mybook->getLocation() == NULL) 
      errorInFile(L"Error in location! Update your file weather.txt and run the elf again!");
    else {
      mybook->setDayWeather(getDayWeather(fileContent, pos, conditionXml));

      if (mybook->getDayWeather() == NULL) errorInFile(L"Error in Day Weather! Update your file weather.txt and run the elf again!");
      else {
        mybook->setNightWeather(getWeather(fileContent,pos, conditionXml));
        if (mybook->getNightWeather() == NULL) errorInFile(L"Error in Night Weather! Update your file weather.txt and run the elf again!");
        else mybook->dateOfWeather = getDateTime();
      }
    }
    delete fileContent;
    delete conditionXml;
  } 
  else
    errorInFile(L"Error while trying to open weather.txt and condition.xml!");
}

int SB_ELF_Killed(void *mess ,BOOK* book) {
  REDRAW_RELEASE_MESSAGE* sbm=(REDRAW_RELEASE_MESSAGE*)mess;
  REDRAW_RELEASE_MESSAGE* res = 0;
  if (sbm->SB_NewOnRedraw==SIonRedraw) {
    res=new REDRAW_RELEASE_MESSAGE;
    memcpy(res,sbm,sizeof(REDRAW_RELEASE_MESSAGE));
    if (sbm->SB_OldOnRedraw!=EMPTY_REDRAW_METHOD) SIonRedraw=sbm->SB_OldOnRedraw;
    DISP_DESC_SetOnRedraw(DispObject_GetDESC(StatusIndication),Draw);
    res->SB_OldOnRedraw=EMPTY_REDRAW_METHOD;
    res->SB_NewOnRedraw=Draw;
  }
  if (res) {
    UI_Event_wData(SBY_REDRAW_RELEASE_EVENT ,res,(void (*)(void*))mfree_adr());
    return BLOCK_EVENT_GLOBALLY;
  }
  return 0;
}

void InitImages(void) {
  ImageID_Get(BCFG_Path_Background_StaticBackground,L"background.png",&statesID[0x0]);
  ImageID_Get(BCFG_XMLBGLogoFolder,L"logo.png",&statesID[0x1]);
  ImageID_Get(BCFG_Path_Background_DayAndNightBG,L"day.png",&statesID[0x2]);
  ImageID_Get(BCFG_Path_Background_DayAndNightBG,L"night.png",&statesID[0x3]);
  
  for (int i = 0 ; i < 44 ; i++) ImageID_Get(BCFG_StatesFolder,stateImages[i],&statesID[i+0x4]);
  for (int i = 0 ; i < 20 ; i++) ImageID_Get(BCFG_Path_Background,bgImages[i],&bgID[i]);
 
}

void DestroyImages(void) {
  for (int i = 0 ; i < 48 ; i++) ImageID_Free(statesID[i]);
  for (int i = 0 ; i < 20 ; i++) ImageID_Free(bgID[i]);  
}

void drawWeatherInfo(MyBook* book) {
  
  mybook = book;

  beginFile();

  if (!mybook->getError()) {
    InitImages();
    StatusIndication = GUIObject_GetDispObject( (GUI*)List_Get(Find_StandbyBook()->xguilist->guilist,0) );
    SIonRedraw=DispObject_GetOnRedraw(StatusIndication);
    DISP_DESC_SetOnRedraw(DispObject_GetDESC(StatusIndication),Draw);
    int refresh;
    (BCFG_Images_Background_Method == 2 && BCFG_Images_Background_Enable) ? refresh = BCFG_RefreshTime : refresh = 1000;    
    mybook->ftimer=Timer_Set(refresh,onfTimer,0);
  }
}

void onCloseBEBook(BOOK* book) {
  if (book)  {
    if (StatusIndication) {
      Timer_Kill(&mybook->ftimer);
      DestroyImages();
      DISP_DESC_SetOnRedraw(DispObject_GetDESC(StatusIndication),SIonRedraw);
      DispObject_InvalidateRect(StatusIndication,0);
      Send_REDRAW_RELEASE();
    }
    mybook->freeMyVars();
    delete mybook;
    SUBPROC(elf_exit);
  }
}
