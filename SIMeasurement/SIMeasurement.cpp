#include "SIMeasurement.h"
#include <stdexcept>
#include<sstream>

SIMeasurement::SIMeasurement(double magnitude, int8_t meterEx, int8_t secondEX, int8_t kilogramEx, int8_t kelvinEx, int8_t ampereEx, int8_t molesEx, int8_t candelaEx)
{
    this->magnitude = magnitude;
    this->meterExponent = meterEx;
    this->secondExponent = secondEX;
    this->kilogramExponent = kilogramEx;
    this->kelvinExponent = kelvinEx;
    this->ampereExponent = ampereEx;
    this->molesExponent = molesEx;
    this->candelaExponent = candelaEx;
}

SIMeasurement::SIMeasurement()
{
    this->magnitude = 1.0;
    this->meterExponent = 0;
    this->secondExponent = 0;
    this->kilogramExponent = 0;
    this->kelvinExponent = 0;
    this->ampereExponent = 0;
    this->molesExponent = 0;
    this->candelaExponent = 0;
}

SIMeasurement::SIMeasurement(double magnitude)
{
    this->magnitude = magnitude;
    this->meterExponent = 0;
    this->secondExponent = 0;
    this->kilogramExponent = 0;
    this->kelvinExponent = 0;
    this->ampereExponent = 0;
    this->molesExponent = 0;
    this->candelaExponent = 0;
}

SIMeasurement::SIMeasurement(double magnitude, const SIUnit unit)
{
    this->magnitude = magnitude;
    this->meterExponent = unit.meterExponent;
    this->secondExponent = unit.secondExponent;
    this->kilogramExponent = unit.kilogramExponent;
    this->kelvinExponent = unit.kelvinExponent;
    this->ampereExponent = unit.ampereExponent;
    this->molesExponent = unit.molesExponent;
    this->candelaExponent = unit.candelaExponent;
}

SIMeasurement::SIMeasurement(const SIMeasurement& src)
{
    this->magnitude = src.magnitude;
    this->meterExponent = src.meterExponent;
    this->secondExponent = src.secondExponent;
    this->kilogramExponent = src.kilogramExponent;
    this->kelvinExponent = src.kelvinExponent;
    this->ampereExponent = src.ampereExponent;
    this->molesExponent = src.molesExponent;
    this->candelaExponent = src.candelaExponent;
}

double SIMeasurement::getMagnitude() const
{
    return this->magnitude;
}

int8_t SIMeasurement::getMeterExponent() const
{
    return this->meterExponent;
}

int8_t SIMeasurement::getSecondExponent() const
{
    return this->secondExponent;
}

int8_t SIMeasurement::getKilogramExponent() const
{
    return this->kilogramExponent;
}

int8_t SIMeasurement::getKelvinExponent() const
{
    return this->kelvinExponent;
}

int8_t SIMeasurement::getAmpereExponent() const
{
    return this->ampereExponent;
}

int8_t SIMeasurement::getMolesExponent() const
{
    return this->molesExponent;
}

int8_t SIMeasurement::getCandelaExponent() const
{
    return this->candelaExponent;
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

std::string SIMeasurement::toString(int precision = 5) const
{
    std::string unitsNumerator = "";
    std::string unitsDenominator = "";
    appendUnitString("s", this->getSecondExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("kg", this->getKilogramExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("m", this->getMeterExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("A", this->getAmpereExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("K", this->getKelvinExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("mole", this->getMolesExponent(), unitsNumerator, unitsDenominator);
    appendUnitString("cd", this->getCandelaExponent(), unitsNumerator, unitsDenominator);

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

    std::stringstream stream;
    stream.precision(precision);
    stream << std::fixed;
    stream << getMagnitude();
    std::string magnitudeString = stream.str();

    if (unitsNumerator == "" && unitsDenominator == "")
    {
        return magnitudeString;
    }
    else if (unitsNumerator == "")
    {
        return magnitudeString + "/" + unitsDenominator;
    }
    else if (unitsDenominator == "")
    {
        return magnitudeString + unitsNumerator;
    }
    else
    {
        return magnitudeString + unitsNumerator + "/" + unitsDenominator;
    }
    return std::string();
}

bool SIMeasurement::unitsMatch(const SIMeasurement& a, const SIMeasurement& b)
{
    return (a.meterExponent == b.meterExponent && a.secondExponent == b.secondExponent && a.kilogramExponent == b.kilogramExponent
        && a.kelvinExponent == b.kelvinExponent && a.ampereExponent == b.ampereExponent && a.molesExponent == b.molesExponent
        && a.candelaExponent == b.candelaExponent);
}

bool SIMeasurement::unitsMatch(const SIMeasurement& messurement, const SIUnit& unit)
{
    return (messurement.meterExponent == unit.meterExponent && messurement.secondExponent == unit.secondExponent && 
        messurement.kilogramExponent == unit.kilogramExponent && messurement.kelvinExponent == unit.kelvinExponent 
        && messurement.ampereExponent == unit.ampereExponent  && messurement.molesExponent == unit.molesExponent 
        && messurement.candelaExponent == unit.candelaExponent);
}

SIMeasurement operator*(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    SIMeasurement c;
    c.magnitude = lhs.magnitude * rhs.magnitude;
    c.meterExponent = lhs.meterExponent + rhs.meterExponent;
    c.secondExponent = lhs.secondExponent + rhs.secondExponent;
    c.kilogramExponent = lhs.kilogramExponent + rhs.kilogramExponent;
    c.kelvinExponent = lhs.kelvinExponent + rhs.kelvinExponent;
    c.ampereExponent = lhs.ampereExponent + rhs.ampereExponent;
    c.molesExponent = lhs.molesExponent + rhs.molesExponent;
    c.candelaExponent = lhs.candelaExponent + rhs.candelaExponent;
    return c;
}

SIMeasurement operator/(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    if (rhs.magnitude != 0)
    {
        SIMeasurement c;
        c.magnitude = lhs.magnitude / rhs.magnitude;
        c.meterExponent = lhs.meterExponent - rhs.meterExponent;
        c.secondExponent = lhs.secondExponent - rhs.secondExponent;
        c.kilogramExponent = lhs.kilogramExponent - rhs.kilogramExponent;
        c.kelvinExponent = lhs.kelvinExponent - rhs.kelvinExponent;
        c.ampereExponent = lhs.ampereExponent - rhs.ampereExponent;
        c.molesExponent = lhs.molesExponent - rhs.molesExponent;
        c.candelaExponent = lhs.candelaExponent - rhs.candelaExponent;
        return c;
    }
    else
    {
        throw std::logic_error("Divided by an SIMessurement with magnitude of zero.");
        return SIMeasurement();
    }
}

SIMeasurement operator+(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    if (SIMeasurement::unitsMatch(lhs, rhs))
    {
        SIMeasurement c = lhs;
        c.magnitude = c.magnitude + rhs.magnitude;
        return c;
    }
    else
    {
        throw std::logic_error("Added SIMeasurements with different units.");
        return SIMeasurement();
    }
}

SIMeasurement operator-(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    if (SIMeasurement::unitsMatch(lhs, rhs))
    {
        SIMeasurement c = lhs;
        c.magnitude = c.magnitude - rhs.magnitude;
        return c;
    }
    else
    {
        throw std::logic_error("Subtracted by an SIMeasurement with different units.");
        return SIMeasurement();
    }
}

bool operator==(const SIMeasurement& lhs, const SIMeasurement& rhs)
{

    return (SIMeasurement::unitsMatch(lhs, rhs) && lhs.magnitude == rhs.magnitude);
}

bool operator!=(const SIMeasurement& lhs, const SIMeasurement& rhs)
{

    return !(lhs == rhs);
}

bool operator>(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (SIMeasurement::unitsMatch(lhs, rhs) && lhs.magnitude > rhs.magnitude);
}

bool operator<(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (rhs > lhs);
}

bool operator>=(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (lhs > rhs || lhs == rhs);
}

bool operator<=(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (lhs < rhs || lhs == rhs);
}

std::ostream& operator<<(std::ostream& out, const SIMeasurement& c)
{
    out << c.toString();
    return out;
}
