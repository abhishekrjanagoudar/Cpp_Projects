#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor>&& sensor)
{
    // Check duplicates
    for (const auto& existingSensor : sensors)
    {
        if (existingSensor->getName() == sensor->getName())
        {
            throw DuplicateSensorName(sensor->getName());
        }
    }

    // Move sensor into list
    sensors.push_back(std::move(sensor));

    return *this;
}
