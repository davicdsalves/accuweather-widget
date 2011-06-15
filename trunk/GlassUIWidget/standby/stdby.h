#pragma once
#include "..\..\include\Lib_Clara.h"
#define DrawImage(_gc_,_x_,_y_,_imgID_) GC_PutChar(_gc_,_x_,_y_,0,0,_imgID_)

void (*SIonRedraw)(DISP_OBJ* ,int r1,int r2,int r3);
void Draw(DISP_OBJ* db,int r1, int r2,int r3);
void drawWeatherContents();
void beginFile();
void onfTimer (u16 tmr , LPARAM);
void makeDateMask();
void InitImages(void);
void DestroyImages(void);
DISP_OBJ* StatusIndication;

wchar_t* stateImages[0x44] = {  L"1.png", L"2.png", L"3.png", //1-3
       L"4.png",  L"5.png",  L"6.png",  L"7.png",  L"8.png",  L"1.png", //4-9
       L"1.png",  L"9.png",  L"10.png", L"11.png",  L"12.png",  L"13.png", //10-15
       L"14.png", L"15.png",  L"16.png",  L"17.png",  L"18.png", L"19.png",  L"20.png", //16-22
       L"21.png",  L"22.png",  L"23.png",  L"24.png",  L"1.png",  L"1.png", //23-28
       L"25.png",  L"26.png",  L"27.png",  L"28.png",  L"29.png",  L"30.png", //29-34
       L"31.png",  L"32.png",  L"33.png",  L"34.png",  L"35.png",  L"36.png", //35-40
       L"37.png",  L"37.png",  L"38.png",  L"39.png"  }; //41-44
wchar_t statesID[0x46] = { 0xFFFF, 0xFFFF , 0xFFFF, 0xFFFF , 0xFFFF , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF };

wchar_t* clockImages[0x60] = {  L"0.png", L"1.png", L"2.png", L"3.png", //1-3
       L"4.png", L"5.png",  L"6.png",  L"7.png",  L"8.png",  L"9.png",  //4-9
       L"10.png", L"11.png",  L"12.png",  L"13.png", L"14.png", L"15.png",  //10-15
       L"16.png", L"17.png",  L"18.png", L"19.png",  L"20.png", //16-20
       L"21.png", L"22.png",  L"23.png",  L"24.png",  L"25.png",  L"26.png", //21-25
       L"27.png", L"28.png",  L"29.png",  L"30.png", L"31.png",  L"32.png", //26-32
       L"33.png", L"34.png",  L"35.png",  L"36.png", L"37.png",  L"38.png", //33-38
       L"39.png", L"40.png", L"41.png", L"42.png", L"43.png", L"44.png", 
       L"45.png", L"46.png", L"47.png", L"48.png", L"49.png",
       L"50.png", L"51.png", L"52.png", L"53.png", L"54.png", L"55.png",
       L"56.png", L"57.png", L"58.png", L"59.png" };
wchar_t clockID[0x60] = { 0xFFFF, 0xFFFF, 0xFFFF , 0xFFFF, 0xFFFF , 0xFFFF , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
