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
public:
    // constructors
    SIMeasurement();
    SIMeasurement(double magnitude, int8_t meterEx, int8_t timeEX, int8_t kilogramEx, int8_t kelvinEx, int8_t ampereEx, int8_t molesEx, int8_t candelaEx,int8_t e = 1);
    SIMeasurement(double magnitude, const SIUnit unit, int8_t e = 1);
    SIMeasurement(double magnitud, int8_t e = 1);
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

    std::string toString() const;

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

