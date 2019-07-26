#include "WeatherData.h"

void WeatherData::registerObserver(IObserver* obs)
{
    m_observers.insert(obs);
}
void WeatherData::removeObserver(IObserver* obs)
{
    m_observers.erase(obs);
}
void WeatherData::notifyObservers()
{
    for(auto obs : m_observers) 
    {
        obs->update(m_temperature, 
            m_humidity, 
            m_pressure);
    }    
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(double temp, double hum, double press) // TODO: write C++ version of python weather
{
    this->m_temperature = temp;
    this->m_humidity = hum;
    this->m_pressure = press;
    measurementsChanged();
}