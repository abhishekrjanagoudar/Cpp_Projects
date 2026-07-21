#include "Resistor.h"

#include <sstream>
#include <string>


Resistor::Resistor(std::string name, float value, float tolerance)
    : Resistance{name}, value{value}, tolerance{tolerance} {
}

ResistancePtr Resistor::from(std::string line) {
    std::stringstream ss(line);
    std::string name, valStr, tolStr;
    
    std::getline(ss, name, ';');
    std::getline(ss, valStr, ';');
    std::getline(ss, tolStr, ';');
    
    if (name.empty()) return nullptr;
    
    return std::make_unique<Resistor>(name, std::stof(valStr), std::stof(tolStr));
}

float Resistor::nominalValue() const {
    return value;
}

float Resistor::minimalValue() const {
    return value * (1.0 - tolerance);
}

float Resistor::maximumValue() const {
    return value * (1.0 + tolerance);
}

