#pragma once

int wGetIndexOf(wchar_t* string, char search, int time, int from=0);
int wGetIndexOfLine(wchar_t* string);
wchar_t* getWSubStr(wchar_t* wString, int begin, int end);
bool compareWchar(wchar_t* tagFound, wchar_t* todayTag);
int intlen(int start);
wchar_t* int2wstr(int num);
bool searchLine(wchar_t* string);

DATETIME getDateTime();
bool isDateEqual(DATETIME* r1, DATETIME* r2);
float celsiusToFahrenheit(int celsius);
float km2Mile(int km);
float km2meter(int km);
void showBox(wchar_t* message, int time);
wchar_t* getStateByHour(int hour);
wchar_t* returnMask(const wchar_t* mask, int tag, bool contentIf, float (*func)(int) , int cond=0);
wchar_t* makeAvgState(wchar_t* state, int averageTemp);
wchar_t* makeNullWchar(int len);
