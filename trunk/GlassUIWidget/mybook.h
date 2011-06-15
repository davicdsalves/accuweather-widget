#pragma once
#include "utils\weather.h"
#include "standby\MetaDataDll.h"

class MyBook {
private:
  BOOK* awBook;
  
  wchar_t* location;
  Weather* dayWeather;
  Weather* nightWeather;
  Weather* weatherToDraw;
  

  
  int hourSeted;
  bool error;
  GC* gc;
  void fillWcharArray( const wchar_t** , const wchar_t** , int  );
public:
  METADATA_DLL_DATA* metadataDll;
  const wchar_t* weekNames[0x7];
  const wchar_t* weekToDraw;
  const wchar_t* monthNames[0x12];
  const wchar_t* monthToDraw;
  
  wchar_t* hourState;
  wchar_t* dateToDraw;  
  DATETIME now;
  u16 ftimer;
  DATETIME dateOfWeather;
  
  MyBook();
  
  wchar_t* getLocation() const;
  Weather* getWeatherToDraw() const;
  Weather* getDayWeather() const;
  Weather* getNightWeather() const;  
  BOOK* getBook() const;
  int getHourSeted() const;
  bool getError() const;
  u16 getFTimer() const;
  GC* getGC() const;
  
  void setError(bool error);
  void setHour(int hour);
  void setWDraw(int one);
  void setLocation(wchar_t* location);
  void setDayWeather(Weather* day);
  void setNightWeather(Weather* night);
  
  void freeWDraw();
  void freeMyVars();
  void donothing();
  void loadDateNames();
  void loadMetadataDll();  
  void unloadMetadataDll();
};
