#pragma once
#include "..\utils\weather.h"
Weather* getDayWeather(wchar_t* , int& , wchar_t* );
Weather* getWeather(wchar_t* fileContent, int& pos, wchar_t*);
wchar_t* getLocation(wchar_t* fileContent, int& i);
