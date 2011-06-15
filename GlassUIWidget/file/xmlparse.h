#pragma once
#include "string.h"
class xml {
private:
  wchar_t* data;
public:
  xml(wchar_t* file);
  ~xml();
};
