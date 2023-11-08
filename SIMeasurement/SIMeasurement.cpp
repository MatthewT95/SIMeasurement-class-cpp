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

inline void SIMeasurement::appendUnitString(std::string unitSymbol, int8_t unitExponent, std::string& unitsNumerator, std::string& unitsDenominator) const
{
    if (unitExponent > 1)
    {
        unitsNumerator += unitSymbol + "^" + std::to_string(abs(unitExponent)) + "*";
    }
    else if (unitExponent == 1)
    {
        unitsNumerator += unitSymbol + "*";
    }
    else if (unitExponent == 0)
    {
    }
    else if (unitExponent == -1)
    {
        unitsDenominator += unitSymbol + "*";
    }
    else if (unitExponent < -1)
    {
        unitsDenominator += unitSymbol + "^" + std::to_string(abs(unitExponent)) + "*";
    }
}

std::string SIMeasurement::toString() const
{
    std::string unitsNumerator = "";
    std::string unitsDenominator = "";
    appendUnitString("s", this->getTimeExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("kg", this->getMassExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("m", this->getLengthExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("A", this->getCurrentExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("K", this->getTemperatureExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("mole", this->getMolesExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("cd", this->getLuminousExponent(), unitsNumerator, unitsDenominator);

    // Trim extra * from unitsNumerator
    if (unitsNumerator.size() > 1)
    {
        unitsNumerator = unitsNumerator.substr(0, unitsNumerator.size() - 1);
    }
    // Trim extra * from unitsDenominator
    if (unitsDenominator.size() > 1)
    {
        unitsDenominator = unitsDenominator.substr(0, unitsDenominator.size() - 1);
    }

    if (unitsNumerator == "" && unitsDenominator == "")
    {
        return std::to_string(getMagnitude());
    }
    else if (unitsNumerator == "")
    {
        return std::to_string(getMagnitude()) + "1/" + unitsDenominator;
    }
    else if (unitsDenominator == "")
    {
        return std::to_string(getMagnitude()) + unitsNumerator;
    }
    else
    {
        return std::to_string(getMagnitude()) + unitsNumerator + "/" + unitsDenominator;
    }
    return std::string();
}

SIMeasurement operator*(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    SIMeasurement c;
    c.magnitude = lhs.magnitude * rhs.magnitude;
    c.lengthExponent = lhs.lengthExponent + rhs.lengthExponent;
    c.timeExponent = lhs.timeExponent + rhs.timeExponent;
    c.massExponent = lhs.massExponent + rhs.massExponent;
    c.temperatureExponent = lhs.temperatureExponent + rhs.temperatureExponent;
    c.currentExponent = lhs.currentExponent + rhs.currentExponent;
    c.molesExponent = lhs.molesExponent + rhs.molesExponent;
    c.luminousExponent = lhs.luminousExponent + rhs.luminousExponent;
    return c;
}

SIMeasurement operator/(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    SIMeasurement c;
    c.magnitude = lhs.magnitude / rhs.magnitude;
    c.lengthExponent = lhs.lengthExponent - rhs.lengthExponent;
    c.timeExponent = lhs.timeExponent - rhs.timeExponent;
    c.massExponent = lhs.massExponent - rhs.massExponent;
    c.temperatureExponent = lhs.temperatureExponent - rhs.temperatureExponent;
    c.currentExponent = lhs.currentExponent - rhs.currentExponent;
    c.molesExponent = lhs.molesExponent - rhs.molesExponent;
    c.luminousExponent = lhs.luminousExponent - rhs.luminousExponent;
    return c;
}