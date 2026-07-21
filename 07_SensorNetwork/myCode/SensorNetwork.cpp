#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor> &&sensor)
{
	// Check against all existing sensors to avoid name collisions
	for(const auto& existing : sensors){
		if(existing->getName() == sensor->getName()){
			// Reject insertion by throwing if name is already registered
			throw DuplicateSensorName(sensor->getName());
		}
	}
	// Append the new sensor taking ownership
	sensors.push_back(std::move(sensor));
	return *this;
}