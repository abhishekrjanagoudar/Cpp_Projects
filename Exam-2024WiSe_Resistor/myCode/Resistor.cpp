#include "Resistor.h"

#include <sstream>
#include <string>


Resistor::Resistor(std::string name, float value, float tolerance)
    : Resistance{name}, value{value}, tolerance{tolerance} {
}

ResistancePtr Resistor::from(std::string line) {
    // TODO: implement method
    return 0;
}

float Resistor::nominalValue() const {
    return value;
}

float Resistor::minimalValue() const {
    // TODO: return the correct value
    return 0;
}

float Resistor::maximumValue() const {
    // TODO: return the correct value
    return 0;
}

