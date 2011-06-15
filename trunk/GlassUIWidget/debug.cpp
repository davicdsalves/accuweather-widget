#include "..\include\Lib_Clara.h"
#include "..\include\Dir.h"
#include "debug.h"

void dbtf(char* msg) {
//  w_chdir(GetDir(DIR_OTHER|MEM_INTERNAL));
//  int file = w_fopen(L"debug.txt", WA_Create+ WA_Append+WA_Write ,0x1FF,0);
//  if ( file > -1 ) { 
//    int length = strlen(msg);
//    w_fwrite( file , msg , length ) ;
//    w_fclose( file ) ; 
//  }
  debug_printf("\n+-+-+-+- ");
  debug_printf(msg);
  debug_printf(" +-+-+-+-\n");
}

void printInt(int num) {
  //<!--debug
  debug_printf("\n+-+-+-+- %d  +-+-+-+-\n", num);
  //-->
}

void printFloat(float num) {
  //<!--debug
  debug_printf("\n+-+-+-+- %f  +-+-+-+-\n", num);  //-->
}
//wchar_t* wstrrchr( const wchar_t* wstr, wchar_t wchar );
void printWchar(wchar_t wString) {
  //<!--debug
  char* intI = new char[0x2];
  wchar_t* wstr = new wchar_t[0x2];
  wstr[0x0] = wString;
  wstr2strn(intI,wstr,wstrlen(wstr));
  dbtf(intI);

  //dbtf(" \n");
  delete wstr;
  delete intI;
  //-->
}

void printWstr(const wchar_t* wString) {
  //<!--debug
  char* intI = new char[0x256];
  wstr2strn(intI,wString,wstrlen(wString));
  dbtf(intI);
  delete intI;
  //-->
}
