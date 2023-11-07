// SIMeasurement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SIMeasurement.h"

void printSIMeasurement(SIMeasurement a)
{
    using namespace std;
    cout << a.getMagnitude() << "(" << std::to_string(a.getLengthExponent()) << "," << std::to_string(a.getTimeExponent())
        << "," << std::to_string(a.getMassExponent()) << "," << std::to_string(a.getTemperatureExponent())
        << "," << std::to_string(a.getMolesExponent()) << "," << std::to_string(a.getLuminousExponent()) << ")"
        << endl;
}

int main(int argc, char const* argv[])
{
    SIMeasurement unitlessFive(5.0);
    SIMeasurement length(2.5, 1, 0, 0, 0, 0, 0, 0);
    SIMeasurement time(1, SI_TIME);
    SIMeasurement tcopy(time);

    printSIMeasurement(unitlessFive);
    printSIMeasurement(length);
    printSIMeasurement(time);
    printSIMeasurement(tcopy);
}


