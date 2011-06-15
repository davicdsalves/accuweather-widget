#include "..\include\Lib_Clara.h"
#include "..\include\Dir.h"
#include "bcfg\config_data.h"
#include "mybook.h"
#include "debug.h"
#include "utils\weather.h"
#include "standby\MetaDataDll.h"

MyBook::MyBook() : awBook(new BOOK) , location(NULL) , dayWeather(NULL), nightWeather(NULL) , weatherToDraw(NULL) , 
error(false) , hourSeted(-1) , gc(get_DisplayGC()) , dateToDraw(NULL)  , weekToDraw(NULL), monthToDraw(NULL) ,
metadataDll(NULL) {  
  loadDateNames();
}
void MyBook::fillWcharArray(const wchar_t** dest, const wchar_t** src, int len ) {
  for (int i=0; i < len; i++)
    dest[i] = src[i];
}
void MyBook::loadDateNames() {
  const wchar_t* tempWeeks[0x7] = { BCFG_Date_Weekday_Monday, BCFG_Date_Weekday_Tuesday, BCFG_Date_Weekday_Wednesday,
  BCFG_Date_Weekday_Thursday, BCFG_Date_Weekday_Friday, BCFG_Date_Weekday_Saturday, BCFG_Date_Weekday_Sunday };

  const wchar_t* tempMonth[0x12] = { BCFG_Date_Month_January, BCFG_Date_Month_February, BCFG_Date_Month_March,
    BCFG_Date_Month_April, BCFG_Date_Month_May, BCFG_Date_Month_June, BCFG_Date_Month_July, BCFG_Date_Month_August,
    BCFG_Date_Month_September, BCFG_Date_Month_October, BCFG_Date_Month_November, BCFG_Date_Month_December };

  fillWcharArray(weekNames, tempWeeks, 7);
  fillWcharArray(monthNames, tempMonth, 12);
}

void MyBook::donothing() {}

BOOK* MyBook::getBook() const { return this->awBook; }
bool MyBook::getError() const { return this->error; }
u16 MyBook::getFTimer() const { return this->ftimer; }
GC* MyBook::getGC() const { return this->gc; }
int MyBook::getHourSeted() const { return this->hourSeted; }
Weather* MyBook::getWeatherToDraw() const { return this->weatherToDraw; }
Weather* MyBook::getDayWeather() const { return this->dayWeather; }
Weather* MyBook::getNightWeather() const { return this->nightWeather; }
wchar_t* MyBook::getLocation() const { return this->location; }

void MyBook::freeWDraw() { delete this->weatherToDraw; this->weatherToDraw = NULL; }
void MyBook::setHour(int hour) { this->hourSeted = hour; }
void MyBook::setWDraw(int one) { (one == 1) ? weatherToDraw = new Weather(dayWeather) : weatherToDraw = new Weather(nightWeather); }
void MyBook::setError(bool error) { this->error = error; }
void MyBook::setLocation(wchar_t* location) { this->location = location; }
void MyBook::setDayWeather(Weather* day) { this->dayWeather = day; }
void MyBook::setNightWeather(Weather* night) { this->nightWeather = night; }


void MyBook::freeMyVars() {
  if (location != NULL) {
    delete location;
    location = NULL;
  }
  if (dayWeather != NULL) {
    delete dayWeather;
    dayWeather = NULL;
  }
  if (nightWeather != NULL) {
    delete nightWeather;   
    nightWeather = NULL;
  }
  if (weatherToDraw != NULL) { 
    delete weatherToDraw;
    weatherToDraw = NULL; 
  }
  if (dateToDraw != NULL) {
    delete dateToDraw;
    dateToDraw = NULL;
  }
}

void MyBook::loadMetadataDll() {
  if (this->metadataDll == NULL) {
    w_chdir(GetDir(MEM_INTERNAL|DIR_DLL));
    this->metadataDll = (METADATA_DLL_DATA*)LoadDLL(L"MetaDataDLL.dll");
  }
}

void MyBook::unloadMetadataDll() {
  if (this->metadataDll != NULL) {
    UnLoadDLL(this->metadataDll);
    this->metadataDll = NULL;
  }
}
