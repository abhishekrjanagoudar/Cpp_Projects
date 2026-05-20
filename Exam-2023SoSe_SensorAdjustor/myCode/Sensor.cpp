#include "Sensor.h"
#include "Adjuster.h"

Sensor::~Sensor() {
}

std::string Sensor::getName() const {
    return name;
}

float Sensor::reading() const {
    // TODO, dummy implementation
    return 0;
}
