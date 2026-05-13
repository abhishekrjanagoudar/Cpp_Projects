#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

#include "TestSensor.h"
#include "LinearAdjuster.h"
#include "TableBasedAdjuster.h"
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the adjustor classes. (12 points)
 */
void adjusterTests() {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using the test values given above as samples, assert that a
     * NullAdjustor's adjust method returns the argument's value
     * unchanged.
     */
    // TODO

    /*
     * (2) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with a single breakpoint (0,0) returns
     * the same values as a NullAdjustor.
     */
    // TODO

    /*
     * (3) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with breakpoints (-100,-110), (0,0)
     * and (100,90) returns the given expected values.
     *
     * Remember (from your basic C/C++ courses) that floating
     * point calculations do not always yield exact results
     * (rounding errors due to using the binary system).
     * Take this into account when checking the result.
     */
    float expected[] = { -11, -1.1, 0, 0.9, 9 };
    // TODO

}

/**
 * Tests for the sensor classes. (12 points)
 */
void sensorTests () {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a NullAdjustor returns the raw
     * readings of a sensor as readings.
     */
    // TODO

    /*
     * (2) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a LinearAdjustor returns the
     * expected readings. Test with 10 differently configured
     * LinearAdjustors for each test value for exhaustive testing
     * (50 "assertTrue" invocations in total).
     */
    // TODO
}

/**
 * Tests for the sensor network. (16 points)
 */
void networkTests() {
    /*
     * Create a sensor network with 10 TestSensors named
     * "Thermometer n" (with n being the number of the thermometer)
     * that have their readings set to values 20 + n * 0.05.
     */
    // TODO

    /*
     * (1) Assert that adding a sensor with a name that is already
     * used by a sensor in the network throws a DuplicateSensorName
     * exception with the sensor's name as "what".
     */
    // TODO
}

void allTests() {
    adjusterTests();
    sensorTests();
    networkTests();
}
