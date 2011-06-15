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
#include "..\classes.h"
#include "standbyDraw.h"
#include "stdby.h" 
#include "id3.h"
#include "..\debug.h"
MyBook* mybook;

//<!--bookmanager
void Send_REDRAW_RELEASE() {
  REDRAW_RELEASE_MESSAGE * sbm= new REDRAW_RELEASE_MESSAGE;
  memset(sbm,0,sizeof(REDRAW_RELEASE_MESSAGE));
  sbm->SB_OldOnRedraw=SIonRedraw;
  sbm->SB_NewOnRedraw=Draw;
  UI_Event_wData(SBY_REDRAW_RELEASE_EVENT ,sbm,(void (*)(void*))mfree_adr());
}

int ReconfigElf(void *mess ,BOOK *book)
{
  RECONFIG_EVENT_DATA *reconf=(RECONFIG_EVENT_DATA *)mess;
  int result=0;
  if (wstrcmpi(reconf->path,successed_config_path)==0 && wstrcmpi(reconf->name,successed_config_name)==0)
  {
    InitConfig();
    mybook->setHour(-1);
    mybook->loadDateNames();
    makeDateMask();
    result=1;
  }
  return(result);
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
    DrawString( drawText , align , x , y , displayWidth, displayHeigth , 60 , 0x05 , textColor , textColor );
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

void ifDrawImage( bool _drawImage, int x, int y, const wchar_t& imgID) {
  if (_drawImage)
    DrawImage(mybook->getGC(), x , y, imgID );
}

void Draw(DISP_OBJ* db,int r1, int r2,int r3) { //change lines for w800
  if (SIonRedraw) SIonRedraw(db,r1,r2,r3);
  ifDrawImage( BCFG_Images_Background_Enable, BCFG_Images_Background_Position_X, BCFG_Images_Background_Position_Y,
              statesID[0x0] );
  if (!FindBook(get_IsAudioPlayerBook())) {
    mybook->unloadMetadataDll();
    drawWeatherContents();
  }
  else {
    mybook->loadMetadataDll();
    drawId3(mybook);
  }
} 

void ifDrawNoMask(bool contentIf, wchar_t* message, int fontSize, int align, int x, int y, unsigned int color) {
  if (contentIf)
    drawOnStby( message, fontSize, align, x, y, color);
}



void drawStdby(wchar_t* message,int fontSize, int align, int x1, int y1, int x2, int y2, int textColor ) {
  int msgSize = wstrlen(message);
  TEXTID drawText = TextID_Create(message, ENC_UCS2 , msgSize);
  SetFont(fontSize);
  DrawString( drawText , align , x1, y1 -16, x2, y2 -16, 60 , 0x05 , textColor , textColor );
  TextID_Destroy( drawText );
}

void drawClock(int hour, int min) {
  wchar_t* tempHour = NULL;
  if (BCFG_Time_Type == 0) { //analog clock
    RECT statePos = BCFG_Time_AnalogClock_State_Position;
    ifDrawImage( BCFG_Images_Clock_Enable, BCFG_Images_Clock_Position_X, BCFG_Images_Clock_Position_Y,
                clockID[min] );
    tempHour = makeNullWchar( 3 );
    snwprintf( tempHour, 3, L"%d", hour);
    ifDrawNoMask( BCFG_Time_Hour_Enable, tempHour, BCFG_Time_Hour_FontSize, BCFG_Time_Hour_Align,
                 BCFG_DateTime_Time_AnalogClock_Hour_Position_X, BCFG_DateTime_Time_AnalogClock_Hour_Position_Y - 16, BCFG_Time_Hour_TextColor );
    delete tempHour;  tempHour = NULL;
    if (BCFG_Time_State_Enable)
      drawStdby( mybook->hourState, BCFG_Time_State_FontSize, BCFG_Time_State_Align,
                statePos.x1, statePos.y1, statePos.x2, statePos.y2, BCFG_Time_State_TextColor );
   }
  
  else {  //digital clock
    tempHour = makeNullWchar( 7 );
    wchar_t* hourMask = L"";
    (min > 10 ? (hourMask = L"%d:%d") : (hourMask = L"%d:0%d") );
    snwprintf( tempHour, 7, hourMask, (hour%12), min);
    ifDrawNoMask( BCFG_Time_DigitalClock_Enable, tempHour, BCFG_Time_DigitalClock_FontSize, BCFG_Time_DigitalClock_Align,
                 BCFG_DateTime_Time_DigitalClock_Position_X, BCFG_DateTime_Time_DigitalClock_Position_Y - 16, BCFG_Time_DigitalClock_TextColor );
    wchar_t* ampm = ((hour >= BCFG_Tags_Time_Night || hour < BCFG_Tags_Time_Day) ? L"pm" : L"am");
    ifDrawNoMask( BCFG_Time_AMPM_Enable, ampm, BCFG_Time_AMPM_FontSize, BCFG_Time_AMPM_Align,
                 BCFG_DateTime_Time_DigitalClock_AMPM_Position_X, BCFG_DateTime_Time_DigitalClock_AMPM_Position_Y - 16,
                 BCFG_Time_AMPM_TextColor );
    delete tempHour; tempHour = NULL;
  }
}

void finalDraw(wchar_t* location, wchar_t* state, int dayState, int averageTemp) {
  //<!--images
  //bg removed cuz it's default for music too so we always need it.
  ifDrawImage( BCFG_Images_AccuWeatherLogo_Enable, BCFG_Images_AccuWeatherLogo_Position_X, BCFG_Images_AccuWeatherLogo_Position_Y,
              statesID[0x1] );
  ifDrawImage( BCFG_Images_DayState_Enable, BCFG_Images_DayState_Position_X, BCFG_Images_DayState_Position_Y,
              statesID[dayState+0x1] );
  //-->
  //<!--text
  ifDrawNoMask(BCFG_Tags_Location_Enable , location, BCFG_Tags_Location_FontSize , BCFG_Tags_Location_Align , 
               BCFG_Tags_Location_Position_X , BCFG_Tags_Location_Position_Y - 16 , BCFG_Tags_Location_TextColor);
  
  if (BCFG_Tags_AverageTemperature_Enable) {// %d
    wchar_t* stateAvg = makeAvgState( state, averageTemp );
    ifDrawNoMask( BCFG_Tags_AverageTemperature_Enable, stateAvg, BCFG_Tags_DayState_FontSize, BCFG_Tags_DayState_Align,
                 BCFG_Tags_DayState_Position_X, BCFG_Tags_DayState_Position_Y - 16, BCFG_Tags_DayState_TextColor );
    delete stateAvg; stateAvg = NULL;
  }
  else
    ifDrawNoMask( BCFG_Tags_DayState_Enable , state , BCFG_Tags_DayState_FontSize , BCFG_Tags_DayState_Align ,
                 BCFG_Tags_DayState_Position_X, BCFG_Tags_DayState_Position_Y - 16 , BCFG_Tags_DayState_TextColor );
  
  ifDrawNoMask( BCFG_Date_Enable , mybook->dateToDraw , BCFG_Date_FontSize, BCFG_Date_Align ,
               BCFG_DateTime_Date_Position_X , BCFG_DateTime_Date_Position_Y - 16, BCFG_Date_TextColor );
  
  //-->
}

void onfTimer (u16 tmr , LPARAM) {
  if (0 == strcmp(Display_GetTopBook(0)->xbook->name, "StandbyBook"))
    DispObject_InvalidateRect(StatusIndication,0);  
  Timer_ReSet(&mybook->ftimer,1000,onfTimer,0);
}

void makeDateMask() { //0 = segunda, 1 = terça, ... , 6 = domingo
  if (mybook->dateToDraw != NULL) { delete mybook->dateToDraw; mybook->dateToDraw = NULL; }
  char _weekDay;
  DATE_GetWeekDay(&mybook->now.date, &_weekDay);
  int weekday = _weekDay;
  if (weekday < 1 && weekday > 6)
    weekday = 0;
  mybook->weekToDraw = mybook->weekNames[weekday];
  int month = mybook->now.date.mon;
  mybook->monthToDraw = mybook->monthNames[ (month > 0 ? month - 0x1 : 0x0) ];
  int dateLength = wstrlen(mybook->weekToDraw) + wstrlen(mybook->monthToDraw) + 5;
  wchar_t* dateToDraw = makeNullWchar( dateLength );
  wstrcpy(dateToDraw, mybook->weekToDraw);
  wstrcat(dateToDraw, L", ");
  wstrcat(dateToDraw, mybook->monthToDraw);
  wchar_t* day = makeNullWchar( 4 );
  int intDay = mybook->now.date.day;
  snwprintf( day, 4, L" %d", intDay);
  wstrcat(dateToDraw, day);
  mybook->dateToDraw = dateToDraw;
  delete day;
}

void drawWeatherContents() {
  //18 ~ 06: night, 06 ~ 18: day
  mybook->now = getDateTime();

  if (mybook->getHourSeted() == -1) {
    if (mybook->getWeatherToDraw() != NULL) mybook->freeWDraw();
    mybook->setHour(mybook->now.time.hour);

    if (mybook->now.time.hour >= BCFG_Tags_Time_Night || mybook->now.time.hour < BCFG_Tags_Time_Day) //need to check that later, midnight weather!
      mybook->setWDraw(2);
    else
      mybook->setWDraw(1);
  }
  
  if (mybook->getHourSeted() != mybook->now.time.hour) {
    mybook->setHour(-1);
    mybook->hourState = getStateByHour(mybook->now.time.hour);
  }

  finalDraw(mybook->getLocation(), mybook->getWeatherToDraw()->getState_(),
            mybook->getWeatherToDraw()->getState(), mybook->getWeatherToDraw()->getAverageTemp());
  drawClock(mybook->now.time.hour, mybook->now.time.min);
  if (isDateEqual(&mybook->now,&mybook->dateOfWeather) != 0) {
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
  dbtf("loading file");
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
        else { mybook->dateOfWeather = getDateTime(); mybook->now = mybook->dateOfWeather; makeDateMask(); 
          mybook->hourState = getStateByHour(mybook->now.time.hour); }
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
  ImageID_Get(BCFG_XMLBGLogoFolder,L"background.png",&statesID[0x0]);
  ImageID_Get(BCFG_XMLBGLogoFolder,L"logo.png",&statesID[0x1]);
  for (int i = 0 ; i < 44 ; i++) ImageID_Get(BCFG_StatesFolder,stateImages[i],&statesID[i+0x2]);
  for (int i = 0 ; i < 60 ; i++)ImageID_Get(BCFG_Path_Clock,clockImages[i],&clockID[i]);
}

void DestroyImages(void) {
  for (int i = 0 ; i < 46 ; i++) ImageID_Free(statesID[i]);
  for (int i = 0 ; i < 60 ; i++) ImageID_Free(clockID[i]);
}

void drawWeatherInfo(MyBook* book) {
  mybook = book;
  beginFile();

  if (!mybook->getError()) {
    InitImages();
    StatusIndication = GUIObject_GetDispObject( (GUI*)List_Get(Find_StandbyBook()->xguilist->guilist,0) );
    SIonRedraw=DispObject_GetOnRedraw(StatusIndication);
    DISP_DESC_SetOnRedraw(DispObject_GetDESC(StatusIndication),Draw);
    mybook->ftimer=Timer_Set(1000,onfTimer,0);
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
