#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "..\bcfg\config_data.h"
#include "utils.h"

//<Day State="02">,12,13
wchar_t* getWSubStr(wchar_t* wString, int begin, int end) {
  if (begin < 0 || end < 0 || (end - begin) < 0) return NULL;
  wchar_t* wSubStr = makeNullWchar( end - begin + 0x2 );
  int i;
  for (i=0;i < (end - begin + 1); i++)
       wSubStr[i] = wString[begin + i];
  return wSubStr;
}

int wGetIndexOfLine(wchar_t* string) {
  for (int i=0;i<wstrlen(string);i++)
	if (string[i] == '\\' && string[i+0x1] == 'n')
          return i;
  return 0;  
}

bool searchLine(wchar_t* string) {
  for (int i=0;i<wstrlen(string);i++)
    if (string[i] == '\\' && string[i+0x1] == 'n') return true;
  return false;
}

int wGetIndexOf(wchar_t* string, char search, int time, int from) {
  int found = 0;
  for (int i=0;i<wstrlen(string);i++) {
	if (string[i + from] == search){
	  found++;
	  if (found == time) return i+from;
	}
  }
  return 0;
}

bool compareWchar(wchar_t* tagFound, wchar_t* todayTag) {
  for (int i=0;i<wstrlen(tagFound) && i<wstrlen(todayTag);i++)
    if (tagFound[i] != todayTag[i]) return false;
  return true;
}

int intlen(int start) {
    int end = 0;
    while(start > 0) {
        start = start/10;
        end++;
    }
    return end;
}  

DATETIME getDateTime() { //"2011/3/20"
  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC,&dt);
  return dt;
}

wchar_t* int2wstr(int num) {
  wchar_t* number = makeNullWchar( intlen(num) );
  snwprintf(number,intlen(num),L"%d",num);
  return number;
}

bool isDateEqual(DATETIME* r1, DATETIME* r2) {
  int dif = r1->date.year - r2->date.year;
  if (dif == 0) {
    dif = r1->date.mon - r2->date.mon;
    if (dif == 0) dif = r1->date.day - r2->date.day;
  }
  return dif;
}

float celsiusToFahrenheit(int celsius) {
  return (celsius * 9 / 5) + 32;
}

float km2Mile(int km) {
  return (km * 0.6214);
}

float km2meter(int km) {
  return (km / 3.6);
}

void showBox(wchar_t* message, int time) {
  MessageBox(0x6FFFFFFF,TextID_Create(message,ENC_UCS2 , wstrlen(message)), NOIMAGE, 1, time,0);
  message = NULL;
  delay(time);
}

wchar_t* getStateByHour(int hour) {
  wchar_t* states[0x5] = { L"Morning", L"Noon", L"Afternoon", L"Evening", L"Night" };
  int hourState[0x5] = { 0, 12, 13, 16, 18 };
  for (int i=0;i<4;i++)
    if (hour >= hourState[i] && hour < hourState[i + 0x1])
      return states[i];
  return states[0x4];
}

wchar_t* returnMask(const wchar_t* mask, int tag, bool contentIf, float (*func)(int) , int cond) {
  int sizeOfTemp = wstrlen(mask) + intlen(tag);
  wchar_t* newMask = makeNullWchar( sizeOfTemp );
  snwprintf( newMask, sizeOfTemp, mask, ( contentIf == cond ? tag : (*func)(tag) ) );
  return newMask;
}

wchar_t* makeAvgState(wchar_t* state, int averageTemp) {
    wchar_t* temp = returnMask( BCFG_Tags_AverageTemperature_Mask , averageTemp , BCFG_Tags_AverageTemperature_Unit , celsiusToFahrenheit );
    wchar_t* stateAvg = makeNullWchar( 256 );
    
    wstrcpy(stateAvg,state);
    wstrcat(stateAvg, L"\\n");
    wstrcat(stateAvg, temp );
    delete temp;
    return stateAvg;
}

wchar_t* makeNullWchar(int len) {
  wchar_t* asRequested = new wchar_t[len];
  memset( asRequested, 0, sizeof(wchar_t)*len );
  return asRequested;
}
