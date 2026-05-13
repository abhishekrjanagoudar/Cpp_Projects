#include "ResistorConnection.h"

ResistorConnection::ResistorConnection(std::string name)
    : Resistance(name) {
}

char ResistorConnection::separator() const {
    return ',';
}

std::string ResistorConnection::components() const {
    // TODO: implement method
    return "";
}

ResistorConnection&
    ResistorConnection::operator+= (ResistancePtr resistor) {
    resistors.push_back(std::move(resistor));
    return *this;
}

void ResistorConnection::write(std::ostream &out) {
    // TODO: implement method
}
