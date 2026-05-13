#include "SerialResistorConnection.h"

SerialResistorConnection::SerialResistorConnection
    (std::string name) : ResistorConnection{name} {
}

char SerialResistorConnection::separator() const {
    return '-';
}

float SerialResistorConnection::nominalValue() const {
    // TODO: implement method
    return 0;
}

float SerialResistorConnection::minimalValue() const {
    // TODO: implement method
    return 0;
}

float SerialResistorConnection::maximumValue() const {
    // TODO: implement method
    return 0;
}
