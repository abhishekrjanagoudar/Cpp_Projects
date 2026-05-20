#include "ParallelResistorConnection.h"

ParallelResistorConnection::ParallelResistorConnection
    (std::string name) : ResistorConnection(name) {
}

char ParallelResistorConnection::separator() const {
    return '|';
}

float ParallelResistorConnection::nominalValue() const {
    // TODO: implement method
    return 0;
}

float ParallelResistorConnection::minimalValue() const {
    // TODO: implement method
    return 0;
}

float ParallelResistorConnection::maximumValue() const {
    // TODO: implement method
    return 0;
}
