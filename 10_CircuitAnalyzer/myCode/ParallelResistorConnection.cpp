#include "ParallelResistorConnection.h"

ParallelResistorConnection::ParallelResistorConnection
    (std::string name) : ResistorConnection(name) {
}

char ParallelResistorConnection::separator() const {
    return '|';
}

float ParallelResistorConnection::nominalValue() const {
    float total = 0.0;
    for (const auto& r : resistors) {
        total += 1.0 / r->nominalValue();
    }
    if (total == 0.0) return 0.0;
    return 1.0 / total;
}

float ParallelResistorConnection::minimalValue() const {
    float total = 0.0;
    for (const auto& r : resistors) {
        total += 1.0 / r->minimalValue();
    }
    if (total == 0.0) return 0.0;
    return 1.0 / total;
}

float ParallelResistorConnection::maximumValue() const {
    float total = 0.0;
    for (const auto& r : resistors) {
        total += 1.0 / r->maximumValue();
    }
    if (total == 0.0) return 0.0;
    return 1.0 / total;
}
