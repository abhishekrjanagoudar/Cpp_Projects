#include "ResistorConnection.h"

ResistorConnection::ResistorConnection(std::string name)
    : Resistance(name) {
}

char ResistorConnection::separator() const {
    return ',';
}

std::string ResistorConnection::components() const {
    if (resistors.empty()) return "[]";
    std::string result = "[";
    bool first = true;
    for (const auto& r : resistors) {
        if (!first) result += separator();
        result += r->getName() + r->components();
        first = false;
    }
    result += "]";
    return result;
}

ResistorConnection&
    ResistorConnection::operator+= (ResistancePtr resistor) {
    resistors.push_back(std::move(resistor));
    return *this;
}

void ResistorConnection::write(std::ostream &out) {
    for (const auto& r : resistors) {
        r->write(out);
    }
    
    out << getName() << "[";
    bool first = true;
    for (const auto& r : resistors) {
        if (!first) out << separator();
        out << r->getName();
        first = false;
    }
    out << "];;\n";
}
