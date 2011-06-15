#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "..\utils\utils.h"
#include "fileAnaliser.h"

wchar_t* getDate() { //"2011/3/20"
  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC,&dt);
  wchar_t* data = new wchar_t[0x32];
  snwprintf(data,32,L"<Period StartDate=\"%u/%d/%d\">",dt.date.year,dt.date.mon,dt.date.day);
  return data;
}

wchar_t* getTag(wchar_t* line, int pos, int& sizeOfTag) {
  int tagClose = wGetIndexOf(line, '>', 1, pos);
  wchar_t* tag = new wchar_t[tagClose+0x2];
  sizeOfTag = tagClose - pos + 2;
  for (tagClose=0; tagClose < wstrlen(line) && line[pos + tagClose] != '>' && (tagClose < sizeOfTag); tagClose++)
    tag[tagClose] = line[pos + tagClose];
  tag[tagClose] = line[pos + tagClose];
  tag[tagClose+0x1] = 0;
  return tag;
}

wchar_t* getEqualContent(wchar_t* fileContent, int& pos) {
  int indexOfEqual = wGetIndexOf(fileContent,'=',1,pos);
  indexOfEqual+=2;
  int indexOfQuotes = wGetIndexOf(fileContent,'"',1,indexOfEqual);
  pos = indexOfQuotes;

  return getWSubStr(fileContent,indexOfEqual,indexOfQuotes-1);
}

int getDayState(wchar_t* fileContent,int& pos) {
  int dayState_ = 0;

  wchar_t* dayState = getEqualContent(fileContent,pos); //getWSubStr(fileContent,indexOfEqual,indexOfQuotes-1);
  swscanf (dayState, L"%d", &dayState_);
  delete dayState; dayState = NULL;
  
  return dayState_;
}

wchar_t* getLocation(wchar_t* fileContent, int& cursor) {
      while (cursor < wstrlen(fileContent)) {
        if (fileContent[cursor] == '<' && fileContent[cursor+0x1] == 'F')
          return getEqualContent(fileContent,cursor);
        cursor++;
      }
      return NULL;
}

wchar_t* getWeatherConditions(wchar_t* num, wchar_t* xmlContent) {
  wchar_t* tag = NULL;
  for (int i=0; i<wstrlen(xmlContent);i++){
    if (xmlContent[i] == '"') {
      tag = getWSubStr(xmlContent,i+1,wGetIndexOf(xmlContent,'"',1,i+1));
      if (compareWchar(tag,num)) {
        delete tag; tag = NULL;
        return getEqualContent(xmlContent,i);
      }
      if (tag != NULL) { delete tag; tag = NULL; }
    }
  }
  return NULL;
}

Weather* getWeather(wchar_t* fileContent, int& pos, wchar_t* xmlContent) {
  int* states = new int[0x4];
  for (int i=0;i<4;i++)
    states[i] = getDayState(fileContent,pos);
  wchar_t* state_ = int2wstr(states[0x0]);
  wchar_t* dayState = getWeatherConditions(state_, xmlContent);
  wchar_t* windDirection = getEqualContent(fileContent,pos);
  wchar_t* longWind = getWeatherConditions(windDirection, xmlContent);
  Weather* todayWeather = new Weather(states[0x0],states[0x1],states[0x2],states[0x3],dayState,windDirection,longWind);
  delete states; states = NULL;
  delete state_; state_ = NULL;
  return todayWeather;
}

Weather* getDayWeather(wchar_t* fileContent, int& i, wchar_t* xmlContent) {
    Weather* todayWeather = NULL;


    while (i < wstrlen(fileContent)) {

      if (fileContent[i] == '<' && fileContent[i+0x1] == 'P') {
        int sizeOfTag = 0;
        wchar_t* tag = getTag(fileContent,i,sizeOfTag);
        i += sizeOfTag;

        wchar_t* today = getDate();
        if (compareWchar(tag,today))
          todayWeather = getWeather(fileContent,i, xmlContent);
        delete tag;
        delete today;
        if (todayWeather != NULL) break;
       }
      i++;
    }
    
   return todayWeather;
}
