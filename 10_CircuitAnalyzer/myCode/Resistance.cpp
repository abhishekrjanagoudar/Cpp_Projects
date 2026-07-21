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
    return getName() + components() + "=" + std::to_string(nominalValue()) + " Ohm";
}

std::ostream& operator<< (std::ostream& out, Resistance& resistor) {
    out << resistor.toString();
    return out;
}

void Resistance::write(std::ostream &out) {
    float nom = nominalValue();
    float tol = 0.0;
    if (nom > 0.0) {
        tol = (maximumValue() - minimalValue()) / (2.0 * nom);
    }
    out << getName() << components() << ";" << nom << ";" << tol << "\n";
}
