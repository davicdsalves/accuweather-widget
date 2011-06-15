#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "..\bcfg\config_data.h"
#include "openfile.h"

wchar_t* openFile(const wchar_t* path, wchar_t* fileName) {
  int file;
  FSTAT fstat_;

  w_chdir(path);
  
  file = w_fopen(fileName, WA_Read ,0x1FF,0 );
  int stat = fstat(path,fileName,&fstat_);

  if ( file > -1 && stat == 0 ) {

   char* fileContent = new char[fstat_.fsize + 0x1];
   wchar_t* wFileContent = new wchar_t[fstat_.fsize + 0x1];

   w_fread(file,fileContent,fstat_.fsize);
   fileContent[fstat_.fsize]=0;
   str2wstr(wFileContent,fileContent);
   delete fileContent;
   fileContent = NULL;
   
   w_fclose(file);   
   return wFileContent;
  }
  return NULL;
}

