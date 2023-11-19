# SIMeasurement Class

This class provides a datatype for storing measurements using SI Units. All arithmetic operations can be performed on the datatype,which will update itself automatically with appropriate combination of SI base units. All comparative operations can be performed like a double datatype. Strings can be easily generated that represent the measurement and its units.

## Authors

- [@MatthewT95 (Matthew Taormina)](https://www.github.com/MatthewT95)

## Installation

To add to project one must add three files.

- SIUnit.h
- SIMeasurement.h
- SIMeasurement.cpp

## Documentation

### Constructors

```cpp
SIMeasurement();
```

This is the default constructor for the class. It creates a SIMeasurement with no units and a magnitude of one.

```cpp
SIMeasurement(double magnitude, const SIUnit unit, int8_t e = 0);
```

This constructor creates a SIMeasurement using 3 arguments, one of which is optional.

magnitude : the magnitude of the measurement to create.
unit : An SIUnit containing a template for this measurement's units.
e : An exponent for scaling the magnitude. Magnitude is scaled by 10^e.

```cpp
SIMeasurement(const SIMeasurement& src);
```

The copy constructor for the class.

```cpp
SIUnit(int8_t meterEx, int8_t secondEX, int8_t kilogramEx, int8_t kelvinEx,
int8_t ampereEx, int8_t molesEx, int8_t candelaEx)
```

The constructor for the SIUnit struct takes seven arguments. An exponent for each SI base unit.

```cpp
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
```

There are many marcos defined as shortcuts to common unit combinations.

### Arithmetic operations

```cpp
SIMeasurement a = SIMeasurement(5,SI_METER);
SIMeasurement b = SIMeasurement(5,SI_SECOND);
SIMeasurement c = SIMeasurement(3,SI_METER);
SIMeasurement ans;

// One can multiply and divide any two measurements by each other
ans = a * b;
ans = a / b;

// One can add and subtract measurements with matching units
// Exception will be thrown if units don't match.
ans = a + c;
ans = a - c;
```

### Comparative operations

```cpp
SIMeasurement a = SIMeasurement(5,SI_METER);
SIMeasurement b = SIMeasurement(3,SI_METER);

// Can compare any two measurements with matching units.
// All operators will return false if units don't match except != which will return true.
a > b;
a < b;
a >= a;
a <= b;
a == b
a != b;
```

### Other methods

```cpp
std::string toString(int8_t significantDigits = 4) const;
```

toString() will return a string representing the measurement. It takes only one option argument significantDigits.The measurement will be displayed in scientific notations with no more significant digits then specified. Trailing zeros will be trimmed.
ex. "5e+1(kg*m/s^2)"
