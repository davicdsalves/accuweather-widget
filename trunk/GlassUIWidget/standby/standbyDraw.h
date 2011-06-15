#pragma once
#include "..\mybook.h"
int SB_ELF_Killed(void *mess ,BOOK* book);
void onCloseBEBook(BOOK* book);
void drawWeatherInfo(MyBook* book);
void elf_exit(void);
int ReconfigElf(void *mess ,BOOK *book);
void drawOnStby(wchar_t* message, int fontSize, int align, int x, int y, int textColor );
void ifDrawNoMask(bool contentIf, wchar_t* message, int fontSize, int align, int x, int y, unsigned int color);

