#pragma once

#define DrawImage(_gc_,_x_,_y_,_imgID_) GC_PutChar(_gc_,_x_ + BCFG_WidgetPosition_X,_y_ + BCFG_WidgetPosition_Y,0,0,_imgID_)

void (*SIonRedraw)(DISP_OBJ* ,int r1,int r2,int r3);
void Draw(DISP_OBJ* db,int r1, int r2,int r3);
void drawWeatherContents();
void beginFile();
void onfTimer (u16 tmr , LPARAM);

DISP_OBJ* StatusIndication;

wchar_t* stateImages[0x44] = {  L"1.png", L"2.png", L"3.png", //1-3
       L"4.png",  L"5.png",  L"6.png",  L"7.png",  L"8.png",  L"1.png", //4-9
       L"1.png",  L"9.png",  L"10.png", L"11.png",  L"12.png",  L"13.png", //10-15
       L"14.png", L"15.png",  L"16.png",  L"17.png",  L"18.png", L"19.png",  L"20.png", //16-22
       L"21.png",  L"22.png",  L"23.png",  L"24.png",  L"1.png",  L"1.png", //23-28
       L"25.png",  L"26.png",  L"27.png",  L"28.png",  L"29.png",  L"30.png", //29-34
       L"31.png",  L"32.png",  L"33.png",  L"34.png",  L"35.png",  L"36.png", //35-40
       L"37.png",  L"38.png",  L"39.png",  L"39.png"  }; //41-44
wchar_t statesID[0x48] = { 0xFFFF, 0xFFFF , 0xFFFF, 0xFFFF , 0xFFFF , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
  0xFFFF, 0xFFFF, 0xFFFF , 0xFFFF };

wchar_t* bgImages[0x20] = {  L"1.png", L"2.png", L"3.png", //1-3
       L"4.png",  L"5.png",  L"6.png",  L"7.png",  L"8.png", L"9.png", L"10.png", //4-10
       L"11.png",  L"12.png",  L"13.png", L"14.png",  L"15.png",  L"16.png", //11-16
       L"17.png", L"18.png",  L"19.png",  L"20.png" };
wchar_t bgID[0x20] = { 0xFFFF, 0xFFFF , 0xFFFF , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0xFFFF, 0xFFFF , 0xFFFF , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };

