#pragma once
#include <cstdint>
#include <string>
#include "SIUnit.h"

class SIMeasurement
{
private:
    double magnitude;
    int8_t lengthExponent;
    int8_t timeExponent;
    int8_t massExponent;
    int8_t temperatureExponent;
    int8_t currentExponent;
    int8_t molesExponent;
    int8_t luminousExponent;

public:
    // constructors
    SIMeasurement();
    SIMeasurement(double magnitude, int8_t lengthEx, int8_t timeEX, int8_t massEx, int8_t temperatureEx, int8_t currentEx, int8_t molesEx, int8_t luminousEx);
    SIMeasurement(double magnitude, const SIUnit unit);
    SIMeasurement(double magnitude);
    SIMeasurement(const SIMeasurement& src);

    // Getters
    double getMagnitude() const;
    int8_t getLengthExponent() const;
    int8_t getTimeExponent() const;
    int8_t getMassExponent() const;
    int8_t getTemperatureExponent() const;
    int8_t getCurrentExponent() const;
    int8_t getMolesExponent() const;
    int8_t getLuminousExponent() const;

    std::string toString() const;

    friend SIMeasurement operator*(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend SIMeasurement operator/(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend SIMeasurement operator+(const SIMeasurement& lhs, const SIMeasurement& rhs);
    friend SIMeasurement operator-(const SIMeasurement& lhs, const SIMeasurement& rhs);
};
