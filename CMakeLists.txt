cmake_minimum_required(VERSION 3.15)
project(WeatherStation)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/CurrentConditionsDisplay.cpp
    src/ForecastDisplay.cpp
    src/StatisticsDisplay.cpp
    src/HeatIndexDisplay.cpp
    src/WeatherData.cpp
)

add_executable(WeatherStation ${SOURCES})