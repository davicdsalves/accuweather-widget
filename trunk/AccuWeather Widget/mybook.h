#pragma once
#include "utils\weather.h"

class MyBook {
private:
  BOOK* awBook;
  
  wchar_t* location;
  Weather* dayWeather;
  Weather* nightWeather;
  Weather* weatherToDraw;

  int hourSeted;
  int bgCursor;
  bool error;
  GC* gc;
    
public:
  int wallpaperType;
  bool changeWallpaper;
  bool cursorDown;
  u16 ftimer;
  DATETIME dateOfWeather;
  
  MyBook();
  
  wchar_t* getLocation() const;

  Weather* getWeatherToDraw() const;
  Weather* getDayWeather() const;
  Weather* getNightWeather() const;  
  BOOK* getBook() const;
  int getHourSeted() const;
  int getCursor() const;
  bool getError() const;
  u16 getFTimer() const;
  GC* getGC() const;
  DATETIME getDate() const;
  
  void addCursor(int i);
  void setCursor(int i);
  void setError(bool error);
  void setHour(int hour);
  void setWDraw(int one);
  void setLocation(wchar_t* location);
  void setDayWeather(Weather* day);
  void setNightWeather(Weather* night);
  
  void freeWDraw();
  void freeMyVars();
  void donothing();
};
