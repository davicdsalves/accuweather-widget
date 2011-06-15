#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "utils.h"

//<Day State="02">,12,13
wchar_t* getWSubStr(wchar_t* wString, int begin, int end) {
  if (begin < 0 || end < 0 || (end - begin) < 0) return NULL;
  wchar_t* wSubStr = new wchar_t[end - begin + 0x2];
  int i;
  for (i=0;i < (end - begin + 1); i++)
       wSubStr[i] = wString[begin + i];
  wSubStr[i] = 0;
  return wSubStr;
}

int wGetIndexOfLine(wchar_t* string) {
  for (int i=0;i<wstrlen(string);i++) {
	if (string[i] == '\\' && string[i+0x1] == 'n')
          return i;
  }
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
  wchar_t* number = new wchar_t[intlen(num) + 0x1];
  snwprintf(number,intlen(num),L"%d",num);
  number[intlen(num)] = 0;
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
