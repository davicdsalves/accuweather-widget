#pragma once

class Weather {
private:
  int state;
  int tempMin;
  int tempMax;
  int windSpeed;
  int averageTemp;
  wchar_t* state_;
  wchar_t* windDirection;
  wchar_t* longWind;
public:
  Weather(int , int, int, int, wchar_t* , wchar_t* , wchar_t* );
  Weather(Weather* copy);
  ~Weather();
  
//  void setState(int );
//  void setTempMin(int );
//  void setTempMax(int );
//  void setWindSpeed(int );
//  void setAverageTemp(int );
//  void setState_(wchar_t* );
//  void setWindDirection(wchar_t* );
  
  int getState() const;
  int getTempMin() const;
  int getTempMax() const;
  int getWindSpeed() const;
  int getAverageTemp() const;
  wchar_t* getState_() const;
  wchar_t* getWindDirection() const;
  wchar_t* getLongWind() const;
};
