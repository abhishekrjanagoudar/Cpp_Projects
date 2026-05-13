#include "Resistance.h"

#include <cmath>
#include <sstream>

Resistance::Resistance(std::string name): name{name} {
}

Resistance::~Resistance() {
}

std::string Resistance::getName() const {
    return name;
}

std::string Resistance::components() const {
    return "";
}

std::string Resistance::toString() const {
    // TODO: implement method
    return "";
}

std::ostream& operator<< (std::ostream& out, Resistance& resistor) {
    out << resistor.toString();
    return out;
}

void Resistance::write(std::ostream &out) {
    // TODO: implement method
}
