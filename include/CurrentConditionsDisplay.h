#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H
#include <iostream>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class CurrentConditionsDisplay : public IObserver, IDisplayElement
{
private:
    double m_temperature, m_humidity;
    ISubject* m_weatherData;
public:
    CurrentConditionsDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~CurrentConditionsDisplay() {}
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif