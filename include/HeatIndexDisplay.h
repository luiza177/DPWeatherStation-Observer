#ifndef HEATINDEXDISPLAY_H
#define HEATINDEXDISPLAY_H
#include <iostream>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class HeatIndexDisplay : public IObserver, IDisplayElement
{
private:
    double m_temperature, m_humidity, m_heatIndex;
    ISubject* m_weatherData;
    double computeHeatIndex(double ct, double rh);
public:
    HeatIndexDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~HeatIndexDisplay(){}
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif