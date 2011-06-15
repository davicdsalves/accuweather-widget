#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "weather.h"

Weather::Weather(int state, int tempMin, int tempMax, int windSpeed, wchar_t* state_, wchar_t* windDirection, wchar_t* longWind) :
  state(state) , tempMin(tempMin) , tempMax(tempMax) , state_(state_) , windDirection(windDirection),
  averageTemp((tempMax+tempMin)/2) , windSpeed(windSpeed * 1.61), longWind(longWind) {

}

Weather::Weather(Weather* copy) : 
  state(copy->state) , tempMin(copy->tempMin) , tempMax(copy->tempMax) , windSpeed(copy->windSpeed) ,
  averageTemp((tempMax+tempMin)/2) {
    
    this->state_ = new wchar_t[ wstrlen( copy->state_ ) + 0x1];
    wstrncpy( this->state_ , copy->state_ , wstrlen( copy->state_ ) );
    this->state_[ wstrlen( copy->state_ ) ] = 0;

    this->windDirection = new wchar_t[ wstrlen( copy->windDirection ) + 0x1];
    wstrncpy( this->windDirection , copy->windDirection , wstrlen( copy->windDirection ) );
    this->windDirection[ wstrlen( copy->windDirection ) ] = 0;

    this->longWind = new wchar_t[ wstrlen( copy->longWind ) + 0x1];
    wstrncpy( this->longWind , copy->longWind , wstrlen( copy->longWind ) );
    this->longWind[ wstrlen( copy->longWind ) ] = 0;    
}

Weather::~Weather() {
  if (this->state_ != NULL) { delete this->state_; this->state_ = NULL; }
  if (this->windDirection != NULL) { delete this->windDirection; this->windDirection = NULL; }
  if (this->longWind != NULL) { delete this->longWind; this->longWind = NULL; }
}

//void Weather::setState(int state) { this->state = state; }
//void Weather::setTempMin(int tempMin) { this->tempMin = tempMin; }
//void Weather::setTempMax(int tempMax) { this->tempMax = tempMax; }
//void Weather::setWindSpeed(int windSpeed) { this->windSpeed = windSpeed; }
//void Weather::setAverageTemp(int averageTemp) { this->averageTemp = averageTemp; }
//void Weather::setState_(wchar_t* state_) { this->state_ = state_; }
//void Weather::setWindDirection(wchar_t* windDirection) { this->windDirection = windDirection; }

int Weather::getState() const { return this->state; }
int Weather::getTempMin() const { return this->tempMin; }
int Weather::getTempMax() const { return this->tempMax; }
int Weather::getWindSpeed() const { return this->windSpeed; }
int Weather::getAverageTemp() const { return this->averageTemp; }
wchar_t* Weather::getState_() const { return this->state_; }
wchar_t* Weather::getWindDirection() const { return this->windDirection; }
wchar_t* Weather::getLongWind() const { return this->longWind; }

