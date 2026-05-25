#include "TestSensor.h"

TestSensor::TestSensor(const std::string &name,
		std::shared_ptr<Adjuster> adjustor) : Sensor(name, adjustor)
{
	value = 0;
}

void TestSensor::setRawReading(float value) : value(value) {}

float TestSensor::rawReading() const
{
	return value;
}
