#pragma once
#pragma once
#include <cstdint>
#include <string>

struct SIUnit
{
    int8_t meterExponent;
    int8_t secondExponent;
    int8_t kilogramExponent;
    int8_t kelvinExponent;
    int8_t ampereExponent;
    int8_t molesExponent;
    int8_t candelaExponent;

    SIUnit(int8_t meterEx, int8_t secondEX, int8_t kilogramEx, int8_t kelvinEx, int8_t ampereEx, int8_t molesEx, int8_t candelaEx)
    {
        this->meterExponent = meterEx;
        this->secondExponent = secondEX;
        this->kilogramExponent = kilogramEx;
        this->kelvinExponent = kelvinEx;
        this->ampereExponent = ampereEx;
        this->molesExponent = molesEx;
        this->candelaExponent = candelaEx;
    }
};

#define SI_UNITLESS SIUnit(0,0,0,0,0,0,0)
// Base Units constants
#define SI_METER SIUnit(1, 0, 0, 0, 0, 0, 0)
#define SI_SECOND SIUnit(0, 1, 0, 0, 0, 0, 0)
#define SI_KILOGRAM SIUnit(0, 0, 1, 0, 0, 0, 0)
#define SI_KELVIN SIUnit(0, 0, 0, 1, 0, 0, 0)
#define SI_AMPERE SIUnit(0, 0, 0, 0, 1, 0, 0)
#define SI_MOLE SIUnit(0, 0, 0, 0, 0, 1, 0)
#define SI_CANDELA SIUnit(0, 0, 0, 0, 0, 0, 1)
// Derived Units
#define SI_METER_SQUARED SIUnit(2, 0, 0, 0, 0, 0, 0)
#define SI_METER_CUBED SIUnit(3, 0, 0, 0, 0, 0, 0)
#define SI_METER_PER_SECOND SIUnit(1, -1, 0, 0, 0, 0, 0)
#define SI_METER_PER_SECOND_SQUARED SIUnit(1, -2, 0, 0, 0, 0, 0)
#define SI_HZ SIUnit(0, -1, 0, 0, 0, 0, 0)
#define SI_METER_CUBED_PER_SECOND SIUnit(3, -1, 0, 0, 0, 0, 0)
#define SI_NEWTON SIUnit(1, -2, 1, 0, 0, 0, 0)
#define SI_JOULE SIUnit(2, -2, 1, 0, 0, 0, 0)
#define SI_WATT SIUnit(2, -3, 1, 0, 0, 0, 0)
#define SI_KILOGRAM_PER_CUBIC_METER SIUnit(-3,0,1,0,0,0,0)
#define SI_PASCAL SIUnit(-1,-2,1,0,0,0,0)
#define SI_COULOMB SIUnit(0,1,0,0,1,0,0)
#define SI_VOLT SIUnit(2,-3,1,0,-1,0,0)
#define SI_OHM SIUnit(2,-3,1,0,-2,0,0)
#define SI_FARAD SIUnit(-2,4,-1,0,2,0,0)
#define SI_TESLA SIUnit(0,-2,1,0,-1,0,0)
#define SI_HENRY SIUnit(2,-2,1,0,-2,0,0)
