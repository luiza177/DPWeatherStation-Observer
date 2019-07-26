#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "ForecastDisplay.h"
#include "StatisticsDisplay.h"
#include "HeatIndexDisplay.h"

int main(int argc, char const *argv[])
{
    WeatherData* weatherData = new WeatherData();
    CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
    HeatIndexDisplay* heatIndexDisplay = new HeatIndexDisplay(weatherData);
    ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData);
    StatisticsDisplay* statsDisplay = new StatisticsDisplay(weatherData);

    // weatherData->setMeasurements(30, 65, 30.4);
    weatherData->setMeasurements();
    std::cout << std::endl;
    // weatherData->setMeasurements(24, 70, 29.2);
    // std::cout << std::endl;
    weatherData->removeObserver(heatIndexDisplay);
    weatherData->setMeasurements();
    // weatherData->setMeasurements(27, 90, 29.2);

    delete currentConditionsDisplay;
    delete forecastDisplay;
    delete statsDisplay;
    delete weatherData;
    
    return 0;
}
