#pragma once
#include "SIUnit.h"

struct SIUnit2
{
	SIUnit nonPrefixedUnit;
	int8_t exponent;

	SIUnit2()
	{
		this->nonPrefixedUnit = SI_UNITLESS;
		this->exponent = 0;
	}

	SIUnit2(const SIUnit2 &src)
	{
		this->nonPrefixedUnit = src.nonPrefixedUnit;
		this->exponent = src.exponent;
	}

	SIUnit2(SIUnit nonPrefixedUnit, int8_t exponent)
	{
		this->nonPrefixedUnit = nonPrefixedUnit;
		this->exponent = exponent;
	}
};

// Perfixed units
// Meters
#define SI_KILOMETER SIUnit2(SI_METER,3)
#define SI_MILLIMETER SIUnit2(SI_METER,-3)
#define SI_MICROMETER SIUnit2(SI_METER,-6)
#define SI_NANOMETER SIUnit2(SI_METER,-9)