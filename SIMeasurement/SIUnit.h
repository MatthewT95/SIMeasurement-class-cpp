#pragma once
#pragma once
#include <cstdint>
#include <string>

struct SIUnit
{
    int8_t lengthExponent;
    int8_t timeExponent;
    int8_t massExponent;
    int8_t temperatureExponent;
    int8_t currentExponent;
    int8_t molesExponent;
    int8_t luminousExponent;

    SIUnit(int8_t lengthEx, int8_t timeEX, int8_t massEx, int8_t temperatureEx, int8_t currentEx, int8_t molesEx, int8_t luminousEx)
    {
        this->lengthExponent = lengthEx;
        this->timeExponent = timeEX;
        this->massExponent = massEx;
        this->temperatureExponent = temperatureEx;
        this->currentExponent = currentEx;
        this->molesExponent = molesEx;
        this->luminousExponent = luminousEx;
    }
};

// Base Units constants
#define SI_LENGTH SIUnit(1, 0, 0, 0, 0, 0, 0)
#define SI_TIME SIUnit(0, 1, 0, 0, 0, 0, 0)
#define SI_MASS SIUnit(0, 0, 1, 0, 0, 0, 0)
#define SI_TEMPERATURE SIUnit(0, 0, 0, 1, 0, 0, 0)
#define SI_CURRENT SIUnit(0, 0, 0, 0, 1, 0, 0)
#define SI_MOLE SIUnit(1, 0, 0, 0, 0, 1, 0)
#define SI_LUMINOUS SIUnit(1, 0, 0, 0, 0, 0, 1)