#include "..\include\Lib_Clara.h"
#include "..\include\Dir.h"
#include "string.h"
#include "xmlparse.h"
int wFindLastOf(wchar_t* string, char search);
xml::xml(wchar_t* _xml) {
  int file;
  FSTAT fstat_;
  file = w_fopen(_xml, WA_Read ,0x1FF,0 );

  int indexOfLastBarra = wFindLastOf(_xml, '/');

  wchar_t* folder = getWSubStr(_xml,0,indexOfLastBarra);
  wchar_t* fileName = getWSubStr(_xml,indexOfLastBarra+1,wstrlen(_xml));
  
  int stat = fstat(folder, fileName,&fstat_);
  delete folder; delete fileName;
  
  if ( file > -1 && stat == 0 ) {
   char* fileContent = new char[fstat_.fsize + 0x1];
   wchar_t* wFileContent = new wchar_t[fstat_.fsize + 0x1];

   w_fread(file,fileContent,fstat_.fsize);
   fileContent[fstat_.fsize]=0;
   str2wstr(wFileContent,fileContent);
   delete fileContent;
   fileContent = NULL;
   
   w_fclose(file);   
   this->data = wFileContent;
  }
}

xml::~xml() {
  if (this->data != NULL) delete this->data;
}

