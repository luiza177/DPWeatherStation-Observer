#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <set>
#include "WeatherFromWeb.h"
#include "interface/ISubject.h"

class WeatherData : public ISubject
{
private:
    std::set<IObserver*> m_observers;
    double m_temperature, m_humidity, m_pressure;
    WeatherFromWeb* m_weatherStation;
public:
    WeatherData();
    virtual ~WeatherData();

    void registerObserver(IObserver* obs) override;
    void removeObserver(IObserver* obs) override;
    void notifyObservers() override;
    void measurementsChanged();
    void setMeasurements();
    void setMeasurements(double temp, double hum, double press);
};

#endif