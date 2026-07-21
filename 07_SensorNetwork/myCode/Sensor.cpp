#include "Sensor.h"
#include "Adjuster.h"

Sensor::~Sensor() {
}

std::string Sensor::getName() const {
    return name;
}

Sensor::Sensor(const std::string &name, std::shared_ptr<Adjuster> adjuster)
{
        this->name = name;
        this->adjuster = adjuster;
}

float Sensor::reading() const {
    // Obtain raw reading and apply the configured adjustment strategy
    return adjuster->adjust(rawReading());
}