#ifndef FORECASTDISPLAY_H
#define FORECASTDISPLAY_H
#include <iostream>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class ForecastDisplay : public IObserver, IDisplayElement
{
private:
    // double m_temperature, m_humidity;
    double m_currentPressure = 29.92;  
	double m_lastPressure;
    ISubject* m_weatherData;
public:
    ForecastDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~ForecastDisplay(){}
    
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif