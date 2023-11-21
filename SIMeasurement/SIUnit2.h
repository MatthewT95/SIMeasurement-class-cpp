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
// Seconds
#define SI_MILLISECOND SIUnit2(SI_SECOND,-3)
#define SI_MICROSECOND SIUnit2(SI_SECOND,-6)
#define SI_NANOSECOND SIUnit2(SI_SECOND,-9)
// Kilograms
#define SI_GRAM SIUnit2(SI_KILOGRAM,-3)
#define SI_MILLIGRAM SIUnit2(SI_KILOGRAM,-6)
#define SI_MICROGRAM SIUnit2(SI_KILOGRAM,-9)
// Amperes
#define SI_KILOAMPERES SIUnit2(SI_AMPERE,3)
#define SI_MILLIAMPERES SIUnit2(SI_AMPERE,-3)
// Herts
#define SI_KILOHERT SIUnit2(SI_HERTS,3)
#define SI_MEGAHERT SIUnit2(SI_HERTS,6)
#define SI_GIGAHERT SIUnit2(SI_HERTS,9)
#define SI_TERAHERT SIUnit2(SI_HERTS,12)
// Newtons
#define SI_KILONEWTON SIUnit2(SI_NEWTON,3)
#define SI_MILLINEWTON SIUnit2(SI_NEWTON,-3)
// Joules
#define SI_KILOJOULE SIUnit2(SI_JOULE,3)
#define SI_MILLIJOULE SIUnit2(SI_JOULE,-3)
// Watts
#define SI_KILOWATT SIUnit2(SI_WATT,3)
#define SI_MILLIWATT SIUnit2(SI_WATT,-3)
// Pascals
#define SI_KILOPASCAL SIUnit2(SI_PASCAL,3)
// OHM
#define SI_KILOOHM SIUnit2(SI_OHM,3)
// Farad
// Pascals
#define SI_MICROFARAD SIUnit2(SI_FARAD,-6)