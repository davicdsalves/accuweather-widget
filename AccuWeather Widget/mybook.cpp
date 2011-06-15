#include "..\include\Lib_Clara.h"
#include "..\include\Dir.h"
#include "mybook.h"
#include "utils\weather.h"

MyBook::MyBook() : awBook(new BOOK) , location(NULL) , dayWeather(NULL), nightWeather(NULL) , weatherToDraw(NULL) , 
error(false) , hourSeted(-1) , bgCursor(0) , cursorDown(false) , wallpaperType(0) , changeWallpaper(false) { 
  gc = get_DisplayGC();
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
int MyBook::getCursor() const { return this->bgCursor; }

void MyBook::addCursor(int i) { this->bgCursor += i; }
void MyBook::setCursor(int i) { this->bgCursor = i; }
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
}
