#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H
#include <iostream>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class StatisticsDisplay : public IObserver, IDisplayElement
{
private:
    double m_temperature/* , m_humidity, m_pressure */;
    ISubject* m_weatherData;
    double m_maxTemp = 0.0;
	double m_minTemp = 200;
	double m_tempSum = 0.0;
	int m_numReadings = 0;
public:
    StatisticsDisplay(ISubject* weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(this);
    }
    virtual ~StatisticsDisplay() {}
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif