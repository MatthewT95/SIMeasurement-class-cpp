#include "SIMeasurement.h"
#include <stdexcept>
#include<sstream>

/// <summary>
/// Initializes all attributes to there deafult setup, A unitless measurement with magnitude of one.
/// </summary>
SIMeasurement::SIMeasurement()
{
    // 
    this->magnitude = 1.0;
    this->meterExponent = 0;
    this->secondExponent = 0;
    this->kilogramExponent = 0;
    this->kelvinExponent = 0;
    this->ampereExponent = 0;
    this->molesExponent = 0;
    this->candelaExponent = 0;
}

/// <summary>
/// Initializes all attributes to create a unitless measurement with provided magnitude
/// </summary>
/// <param name="magnitude">The magnitude of the measurement.</param>
SIMeasurement::SIMeasurement(double magnitude, int8_t e)
{
    
    this->magnitude = magnitude;
    this->meterExponent = 0;
    this->secondExponent = 0;
    this->kilogramExponent = 0;
    this->kelvinExponent = 0;
    this->ampereExponent = 0;
    this->molesExponent = 0;
    this->candelaExponent = 0;

    // adjust magnitude by e
    // Checks if e is greater then zero and multiples by 10 e times
    if (e > 0)
    {
        for (int i = 0; i < e; i++)
        {
            this->magnitude *= 10;
        }
    }
    // Checks if e is greater less then zero and divides by 10 e times
    else  if (e < 0)
    {
        for (int i = 0; i > e; i--)
        {
            this->magnitude /= 10;
        }
    }
}

SIMeasurement::SIMeasurement(double magnitude, SIUnit2 unit)
{
    *this = SIMeasurement(magnitude, unit.nonPrefixedUnit, unit.exponent);
}

/// <summary>
/// Initializes all attributes to using provided unit as a template
/// </summary>
/// <param name="magnitude">The magnitude of the measurement.</param>
/// <param name="unit">A template contaning the unit exponents for this measurement.</param>
SIMeasurement::SIMeasurement(double magnitude, const SIUnit unit, int8_t e)
{
    this->magnitude = magnitude;
    this->meterExponent = unit.meterExponent;
    this->secondExponent = unit.secondExponent;
    this->kilogramExponent = unit.kilogramExponent;
    this->kelvinExponent = unit.kelvinExponent;
    this->ampereExponent = unit.ampereExponent;
    this->molesExponent = unit.molesExponent;
    this->candelaExponent = unit.candelaExponent;

    // adjust magnitude by e
    // Checks if e is greater then zero and multiples by 10 e times
    if (e > 0)
    {
        for (int i = 0; i < e; i++)
        {
            this->magnitude *= 10;
        }
    }
    // Checks if e is greater less then zero and divides by 10 e times
    else  if (e < 0)
    {
        for (int i = 0; i > e; i--)
        {
            this->magnitude /= 10;
        }
    }
}

/// <summary>
/// Copy constructor for SIMeasurement.
/// </summary>
/// <param name="src">The source object to copy.</param>
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

/// <summary>
/// Gets the magnitude of the measurement
/// </summary>
/// <returns>The measurement magnitude.</returns>
double SIMeasurement::getMagnitude() const
{
    return this->magnitude;
}

/// <summary>
/// Gets the meter exponent of the measurement.
/// </summary>
/// <returns>The meter exponent of the measurement.</returns>
int8_t SIMeasurement::getMeterExponent() const
{
    return this->meterExponent;
}

/// <summary>
/// Gets the second exponent of the measurement.
/// </summary>
/// <returns>The second exponent of the measurement.</returns>
int8_t SIMeasurement::getSecondExponent() const
{
    return this->secondExponent;
}

/// <summary>
/// Gets the kilogram exponent of the measurement.
/// </summary>
/// <returns>The kilogram exponent of the measurement.</returns>
int8_t SIMeasurement::getKilogramExponent() const
{
    return this->kilogramExponent;
}

/// <summary>
/// Gets the Kelvin exponent of the measurement.
/// </summary>
/// <returns>The Kelvin exponent of the measurement.</returns>
int8_t SIMeasurement::getKelvinExponent() const
{
    return this->kelvinExponent;
}

/// <summary>
/// Gets the Ampere exponent of the measurement.
/// </summary>
/// <returns>The Ampere exponent of the measurement.</returns>
int8_t SIMeasurement::getAmpereExponent() const
{
    return this->ampereExponent;
}

/// <summary>
/// Gets the moles exponent of the measurement.
/// </summary>
/// <returns>The moles exponent of the measurement.</returns>
int8_t SIMeasurement::getMolesExponent() const
{
    return this->molesExponent;
}

/// <summary>
/// Gets the candela exponent of the measurement.
/// </summary>
/// <returns>The candela exponent of the measurement.</returns>
int8_t SIMeasurement::getCandelaExponent() const
{
    return this->candelaExponent;
}

/// <summary>
/// Assists the toString() method in generating the string. Genearates and appends a unit and it's exponent to numerator or denominator. 
/// </summary>
/// <param name="unitSymbol">The symbol for the unit.</param>
/// <param name="unitExponent">The exponent of the unit.</param>
/// <param name="unitsNumerator">A reference to unitNumerator in toString() method.</param>
/// <param name="unitsDenominator">A reference to unitDenominator in toString() method.</param>
inline void SIMeasurement::appendUnitString(std::string unitSymbol, int8_t unitExponent, std::string& unitsNumerator, std::string& unitsDenominator) const
{
    if (unitExponent > 1)
    {
        // Appends unit and exponent to numerator (unit^exponent)
        unitsNumerator += unitSymbol + "^" + std::to_string(abs(unitExponent)) + "*";
    }
    else if (unitExponent == 1)
    {
        // Appends unit only to numerator (unit)
        unitsNumerator += unitSymbol + "*";
    }
    else if (unitExponent == 0)
    {
        // Does nothing
    }
    else if (unitExponent == -1)
    {
        // Appends unit only to denominator (unit)
        unitsDenominator += unitSymbol + "*";
    }
    else if (unitExponent < -1)
    {
        // Appends unit and exponent to denominator (unit^exponent)
        unitsDenominator += unitSymbol + "^" + std::to_string(abs(unitExponent)) + "*";
    }
}

std::string SIMeasurement::scientificNotation(double value,int8_t significantDigits)
{
    int8_t exponent = 0;
    std::string valueString = "";

    // Guards against significantDigits arugment less then one
    if (significantDigits < 1 && value != 0)
    {
        significantDigits = 1;
    }

    // Adjusts exponet so there is not more then one signifcant digit to the left of the decimal
    while (value >= 10 && value != 0)
    {
        // Adjusts value before exponent
        value /= 10;
        // Increaments exponent
        exponent += 1;
    }
    // Adjusts exponet so there is at one signifcant digit to the left of the decimal
    while (value < 1)
    {
        // Adjusts value before exponent
        value *= 10;
        // Decreament exponent
        exponent -= 1;
    }

    // Converts adjusted value to string
    std::stringstream stream;
    stream.precision(significantDigits - 1);
    stream << std::fixed << value;
    valueString = stream.str();

    while (valueString[valueString.size()-1] == '0' || valueString[valueString.size() - 1] == '.')
    {
        valueString = valueString.substr(0, valueString.size() - 1);
    }
    if (exponent > 0)
    {
        return valueString + "e+" + std::to_string(exponent);
    }
    else if (exponent < 0)
    {
        return valueString + "e" + std::to_string(exponent);
    }
    else
    {
        return valueString;
    }
    
}

std::string SIMeasurement::engineeringNotation(double value, int8_t significantDigits)
{
    int8_t exponent = 0;
    std::string valueString = "";

    // Conevert to scientfic notation first
    // Adjusts exponet so there is not more then one signifcant digit to the left of the decimal
    while (value >= 10 && value != 0)
    {
        // Adjusts value before exponent
        value /= 10;
        // Increaments exponent
        exponent += 1;
    }
    // Adjusts exponet so there is at one signifcant digit to the left of the decimal
    while (value < 1 && value != 0)
    {
        // Adjusts value before exponent
        value *= 10;
        // Decreament exponent
        exponent -= 1;
    }

    int8_t signficanteDigitsWholePortion = 0;

    // Convert to engineering notation
    if (exponent > 0)
    {
        if (exponent % 3 == 0)
        {
            signficanteDigitsWholePortion = 1;
        }
        else if (exponent % 3 == 1)
        {
            // Adjusts value before exponent
            value *= 10;
            // Decreament exponent
            exponent -= 1;
            signficanteDigitsWholePortion = 2;
        }
        else if (exponent % 3 == 2)
        {
            // Adjusts value before exponent
            value *= 100;
            // Decreament exponent
            exponent -= 2;
            signficanteDigitsWholePortion = 3;
        }
    }
    else if (exponent < 0)
    {
        if (exponent % 3 == 0)
        {
            signficanteDigitsWholePortion = 1;
        }
        else if (exponent % 3 == -1)
        {
            // Adjusts value before exponent
            value *= 100;
            // Decreament exponent
            exponent -= 2;
            signficanteDigitsWholePortion = 3;
        }
        else if (exponent % 3 == -2)
        {
            // Adjusts value before exponent
            value *= 10;
            // Decreament exponent
            exponent -= 1;
            signficanteDigitsWholePortion = 2;
        }
    }

    // Converts adjusted value to string
    std::stringstream stream;
    stream.precision(significantDigits - signficanteDigitsWholePortion);
    stream << std::fixed << value;
    valueString = stream.str();

    while (valueString[valueString.size() - 1] == '0' )
    {
        valueString = valueString.substr(0, valueString.size() - 1);
    }

    if (valueString[valueString.size() - 1] == '.')
    {
        valueString = valueString.substr(0, valueString.size() - 1);
    }

    if (exponent > 0)
    {
        return valueString + "e+" + std::to_string(exponent);
    }
    else if (exponent < 0)
    {
        return valueString + "e" + std::to_string(exponent);
    }
    else
    {
        return valueString;
    }
}

/// <summary>
/// Generates and returns a string representing the measurement.
/// </summary>
/// <returns>The string represention of the measurement.</returns>
std::string SIMeasurement::toString(int8_t notationMode, int8_t significantDigits) const
{
    std::string unitsNumerator = ""; // The numerator portion of the measurement
    std::string unitsDenominator = ""; // The denominator portion of the measurement
    // Adds each unit to the appropriate string
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
    std::string magnitudeString;
    // Creates a string representing the magnitude.
    if (notationMode == 0)
    {
        magnitudeString = std::to_string(getMagnitude());
    }
    else if (notationMode == 1)
    {
        magnitudeString = scientificNotation(getMagnitude(), significantDigits);
    }
    else if (notationMode == 2)
    {
        magnitudeString = engineeringNotation(getMagnitude(), significantDigits);
    }

    // Checks if there are no units in measurement
    if (unitsNumerator == "" && unitsDenominator == "")
    {
        return magnitudeString;
    }
    // Checks if there no units in numerator portion of measurement
    else if (unitsNumerator == "")
    {
        return magnitudeString + "/" + "(" + unitsDenominator + ")";
    }
    // Checks if there no units in denominator portion of measurement
    else if (unitsDenominator == "")
    {
        return magnitudeString + "(" + unitsNumerator + ")";
    }
    // Checks if there units in both in numerator and denominator
    else
    {
        return magnitudeString + "(" + unitsNumerator + "/" + unitsDenominator + ")";
    }
    return std::string();
}
/// <summary>
/// Compares two SIMeasurements and returns true if the units match.
/// </summary>
/// <param name="a">SIMeasurement a</param>
/// <param name="b">SIMeasurement b</param>
/// <returns>The result of the comparison.</returns>
bool SIMeasurement::unitsMatch(const SIMeasurement& a, const SIMeasurement& b)
{
    // Checks if all unit exponents match
    return (a.meterExponent == b.meterExponent && a.secondExponent == b.secondExponent && a.kilogramExponent == b.kilogramExponent
        && a.kelvinExponent == b.kelvinExponent && a.ampereExponent == b.ampereExponent && a.molesExponent == b.molesExponent
        && a.candelaExponent == b.candelaExponent);
}

/// <summary>
/// Compares a SIMeasurement to a template SIUnit a returns true if the units match.
/// </summary>
/// <param name="messurement">a SIMeasurement</param>
/// <param name="unit">a SIUnit</param>
/// <returns>The result of the comparison.</returns>
bool SIMeasurement::unitsMatch(const SIMeasurement& messurement, const SIUnit& unit)
{
    // Checks if all unit exponents match
    return (messurement.meterExponent == unit.meterExponent && messurement.secondExponent == unit.secondExponent && 
        messurement.kilogramExponent == unit.kilogramExponent && messurement.kelvinExponent == unit.kelvinExponent 
        && messurement.ampereExponent == unit.ampereExponent  && messurement.molesExponent == unit.molesExponent 
        && messurement.candelaExponent == unit.candelaExponent);
}

/// <summary>
/// Multiples two SIMeasurements togetter and returns the result.
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The right hand side of the opeartor.</param>
/// <returns>The product of the multiplication.</returns>
SIMeasurement operator*(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    SIMeasurement c;
    // Multiplies the magnitude
    c.magnitude = lhs.magnitude * rhs.magnitude;
    // Adds the exponents of the units
    c.meterExponent = lhs.meterExponent + rhs.meterExponent;
    c.secondExponent = lhs.secondExponent + rhs.secondExponent;
    c.kilogramExponent = lhs.kilogramExponent + rhs.kilogramExponent;
    c.kelvinExponent = lhs.kelvinExponent + rhs.kelvinExponent;
    c.ampereExponent = lhs.ampereExponent + rhs.ampereExponent;
    c.molesExponent = lhs.molesExponent + rhs.molesExponent;
    c.candelaExponent = lhs.candelaExponent + rhs.candelaExponent;
    return c;
}

/// <summary>
/// Divides a SIMeasurement by another and returns the result.
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The right hand side of the opeartor.</param>
/// <returns>The result of the division.</returns>
SIMeasurement operator/(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    // Checks if magnitude of rhs is not zero
    if (rhs.magnitude != 0)
    {
        SIMeasurement c;
        // Divides the magnitude of lhs by rhs
        c.magnitude = lhs.magnitude / rhs.magnitude;
        // Subtracts the unit exponents of rhs from lhs
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
        // Throws an error if a divide by zero magnitude is attemped
        throw std::logic_error("Divided by an SIMessurement with magnitude of zero.");
        return SIMeasurement();
    }
}

/// <summary>
/// Adds to SIMeasurments with matching units.
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns>The result of the addtion.</returns>
SIMeasurement operator+(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    // Checks if lhs and rhs units match
    if (SIMeasurement::unitsMatch(lhs, rhs))
    {
        // Copies lhs
        SIMeasurement c = lhs;
        // adds magnitude of lhs and rhs
        c.magnitude = c.magnitude + rhs.magnitude;
        return c;
    }
    else
    {
        // Returns error if units don't match
        throw std::logic_error("Added SIMeasurements with different units.");
        return SIMeasurement();
    }
}

/// <summary>
/// Subtarcts an SIMeasurments from another with matching units.
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns>The result of the subtraction.</returns>
SIMeasurement operator-(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    // Checks if the units match
    if (SIMeasurement::unitsMatch(lhs, rhs))
    {
        SIMeasurement c = lhs;
        c.magnitude = c.magnitude - rhs.magnitude;
        return c;
    }
    else
    {
        // Returns an error if units do not match
        throw std::logic_error("Subtracted by an SIMeasurement with different units.");
        return SIMeasurement();
    }
}

/// <summary>
/// Compares two SIMeasurements and returns true if there identical
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns></returns>
bool operator==(const SIMeasurement& lhs, const SIMeasurement& rhs)
{

    return (SIMeasurement::unitsMatch(lhs, rhs) && lhs.magnitude == rhs.magnitude);
}

/// <summary>
/// Compares two SIMeasurements and returns true if there not identical
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns></returns>
bool operator!=(const SIMeasurement& lhs, const SIMeasurement& rhs)
{

    return !(lhs == rhs);
}

/// <summary>
/// Compares two SIMeasurements and returns true if the units match and lhs magnitude is greater then rhs magnitude
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns></returns>
bool operator>(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (SIMeasurement::unitsMatch(lhs, rhs) && lhs.magnitude > rhs.magnitude);
}

/// <summary>
/// Compares two SIMeasurements and returns true if the units match and lhs magnitude is less then rhs magnitude
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns></returns>
bool operator<(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (rhs > lhs);
}

/// <summary>
/// Compares two SIMeasurements and returns true if the units match and lhs magnitude is greater then or equal to rhs magnitude
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns></returns>
bool operator>=(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (lhs > rhs || lhs == rhs);
}

/// <summary>
/// Compares two SIMeasurements and returns true if the units match and lhs magnitude is less then or equal to rhs magnitude
/// </summary>
/// <param name="lhs">The left hand side of the opeartor.</param>
/// <param name="rhs">The rigth hand side of the opeartor.</param>
/// <returns></returns>
bool operator<=(const SIMeasurement& lhs, const SIMeasurement& rhs)
{
    return (lhs < rhs || lhs == rhs);
}

/// <summary>
/// Outputs SIMeasuremnt.toString() when output stream operator is used.
/// </summary>
/// <param name="out"></param>
/// <param name="c"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& out, const SIMeasurement& c)
{
    out << c.toString();
    return out;
}
