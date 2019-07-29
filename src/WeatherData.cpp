#include "WeatherData.h"

WeatherData::WeatherData()
{
    m_weatherStation = new WeatherFromWeb();
    m_weatherStation->updateWeatherDataPacket();
}

WeatherData::~WeatherData()
{
    delete m_weatherStation;
}

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

void WeatherData::setMeasurements(double temp, double hum, double press)
{
    this->m_temperature = temp;
    this->m_humidity = hum;
    this->m_pressure = press;
    measurementsChanged();
}

void WeatherData::setMeasurements()
{

    WeatherDataPacket weatherDataPacket = m_weatherStation->getWeatherDataPacket();
    this->m_temperature = weatherDataPacket.temperature - 272.15;
    this->m_humidity = weatherDataPacket.humidity;
    this->m_pressure = weatherDataPacket.pressure;
    measurementsChanged();
}