#include "SIMeasurement.h"

SIMeasurement::SIMeasurement(double magnitude, int8_t lengthEx, int8_t timeEX, int8_t massEx, int8_t temperatureEx, int8_t currentEx, int8_t molesEx, int8_t luminousEx)
{
    this->magnitude = magnitude;
    this->lengthExponent = lengthEx;
    this->timeExponent = timeEX;
    this->massExponent = massEx;
    this->temperatureExponent = temperatureEx;
    this->currentExponent = currentEx;
    this->molesExponent = molesEx;
    this->luminousExponent = luminousEx;
}

SIMeasurement::SIMeasurement()
{
    this->magnitude = 1.0;
    this->lengthExponent = 0;
    this->timeExponent = 0;
    this->massExponent = 0;
    this->temperatureExponent = 0;
    this->currentExponent = 0;
    this->molesExponent = 0;
    this->luminousExponent = 0;
}

SIMeasurement::SIMeasurement(double magnitude)
{
    this->magnitude = magnitude;
    this->lengthExponent = 0;
    this->timeExponent = 0;
    this->massExponent = 0;
    this->temperatureExponent = 0;
    this->currentExponent = 0;
    this->molesExponent = 0;
    this->luminousExponent = 0;
}

SIMeasurement::SIMeasurement(double magnitude, const SIUnit unit)
{
    this->magnitude = magnitude;
    this->lengthExponent = unit.lengthExponent;
    this->timeExponent = unit.timeExponent;
    this->massExponent = unit.massExponent;
    this->temperatureExponent = unit.temperatureExponent;
    this->currentExponent = unit.currentExponent;
    this->molesExponent = unit.molesExponent;
    this->luminousExponent = unit.luminousExponent;
}

SIMeasurement::SIMeasurement(const SIMeasurement& src)
{
    this->magnitude = src.magnitude;
    this->lengthExponent = src.lengthExponent;
    this->timeExponent = src.timeExponent;
    this->massExponent = src.massExponent;
    this->temperatureExponent = src.temperatureExponent;
    this->currentExponent = src.currentExponent;
    this->molesExponent = src.molesExponent;
    this->luminousExponent = src.luminousExponent;
}

double SIMeasurement::getMagnitude() const
{
    return this->magnitude;
}

int8_t SIMeasurement::getLengthExponent() const
{
    return this->lengthExponent;
}

int8_t SIMeasurement::getTimeExponent() const
{
    return this->timeExponent;
}

int8_t SIMeasurement::getMassExponent() const
{
    return this->massExponent;
}

int8_t SIMeasurement::getTemperatureExponent() const
{
    return this->temperatureExponent;
}

int8_t SIMeasurement::getCurrentExponent() const
{
    return this->currentExponent;
}

int8_t SIMeasurement::getMolesExponent() const
{
    return this->molesExponent;
}

int8_t SIMeasurement::getLuminousExponent() const
{
    return this->luminousExponent;
}