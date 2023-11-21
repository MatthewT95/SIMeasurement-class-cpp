#pragma once
#include <cstdint>
#include <string>
#include "SIUnit.h"
#include <iostream>

class SIMeasurement
{
private:
    double magnitude;
    int8_t meterExponent;
    int8_t secondExponent;
    int8_t kilogramExponent;
    int8_t kelvinExponent;
    int8_t ampereExponent;
    int8_t molesExponent;
    int8_t candelaExponent;

    void appendUnitString(std::string unitSymbol, int8_t unitExponent, std::string& unitsNumerator, std::string& unitsDenominator) const;
    static std::string scientificNotation(double value,int8_t significantDigits);
    static std::string engineeringNotation(double value, int8_t significantDigits);
public:
    // constructors
    SIMeasurement();
    SIMeasurement(double magnitude, const SIUnit unit, int8_t e = 0);
    SIMeasurement(double magnitude, int8_t e = 0);
    SIMeasurement(const SIMeasurement& src);

    // Getters
    double getMagnitude() const;
    int8_t getMeterExponent() const;
    int8_t getSecondExponent() const;
    int8_t getKilogramExponent() const;
    int8_t getKelvinExponent() const;
    int8_t getAmpereExponent() const;
    int8_t getMolesExponent() const;
    int8_t getCandelaExponent() const;

    std::string toString(int8_t notationMode = 1,int8_t significantDigits = 4) const;

    static bool unitsMatch(const SIMeasurement& a, const SIMeasurement& b);
    static bool unitsMatch(const SIMeasurement& messurement, const SIUnit& unit);

    // Arithmetic operators
    friend SIMeasurement operator*(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend SIMeasurement operator/(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend SIMeasurement operator+(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend SIMeasurement operator-(const SIMeasurement& lhs, const SIMeasurement& rhs);

    // Equality operators
    friend bool operator==(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend bool operator!=(const SIMeasurement& lhs, const SIMeasurement& rhs);

    // Realtionship operators
    friend bool operator>(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend bool operator<(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend bool operator>=(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend bool operator<=(const SIMeasurement& lhs, const SIMeasurement& rhs);

    // Stream opeartor
    friend std::ostream& operator << (std::ostream& out, const SIMeasurement& c);
};

