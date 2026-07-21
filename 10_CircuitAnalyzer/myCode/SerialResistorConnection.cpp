#include "SerialResistorConnection.h"

SerialResistorConnection::SerialResistorConnection
    (std::string name) : ResistorConnection{name} {
}

char SerialResistorConnection::separator() const {
    return '-';
}

float SerialResistorConnection::nominalValue() const {
    float total = 0.0;
    for (const auto& r : resistors) {
        total += r->nominalValue();
    }
    return total;
}

float SerialResistorConnection::minimalValue() const {
    float total = 0.0;
    for (const auto& r : resistors) {
        total += r->minimalValue();
    }
    return total;
}

float SerialResistorConnection::maximumValue() const {
    float total = 0.0;
    for (const auto& r : resistors) {
        total += r->maximumValue();
    }
    return total;
}
