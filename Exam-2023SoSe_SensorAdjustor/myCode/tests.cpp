#include <iostream>
#include <cstdlib>
#include <memory>
#include <cmath>

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
    NullAdjuster adj;

    // Verify that NullAdjuster returns every input identically
    for(float value : testValues){
    	assertTrue(
    			adj.adjust(value) == value,
				"Null Adjustor Failed");
    }

    /*
     * (2) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with a single breakpoint (0,0) returns
     * the same values as a NullAdjustor.
     */
    TableBasedAdjuster tabAdj;
    tabAdj.addBreakpoint(0,0);

    // Verify a TableBasedAdjuster with a single origin breakpoint acts like a NullAdjuster
    for(float value : testValues){
    	assertTrue(
    			tabAdj.adjust(value) == value,
				"Table Based Adjuster Failed");
    }

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

    // Set up a TableBasedAdjuster for linear interpolation across three points
    TableBasedAdjuster tabAdj1;
    tabAdj1.addBreakpoint(-100,-110);
    tabAdj1.addBreakpoint(0,0);
    tabAdj1.addBreakpoint(100,90);

    // Validate calculations allowing for small floating point inaccuracies
    for(int i = 0 ; i < 5 ; i++){
    	assertTrue(
    			fabs(tabAdj1.adjust(testValues[i]) - expected[i]) < 0.0001,
				"Table Based Adjuster Interpolation Failed");
    }
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

    TestSensor sensor("Test Sensor" , NullAdjuster::sharedInstance);
    
    // Verify a sensor with a NullAdjuster yields readings exactly equal to its raw input
    for(float value : testValues){
    	sensor.setRawReading(value);
        
    	assertTrue(
    			sensor.reading() == value,
				"Test Sensor NullAdjuster Failed ");
    }

    /*
     * (2) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a LinearAdjustor returns the
     * expected readings. Test with 10 differently configured
     * LinearAdjustors for each test value for exhaustive testing
     * (50 "assertTrue" invocations in total).
     */
    // Verify combinations of LinearAdjuster settings against varying inputs
    for(int factor = 1 ; factor <= 10; factor++){
    	auto adjuster = std::make_shared<LinearAdjuster>(
    			factor, factor - 1);
        TestSensor sensor("Test Sensor" , adjuster);

    	for(float value : testValues){
    		sensor.setRawReading(value);
    		// Calculate mathematical expectation for the linear formula
    		float expected = value * factor + (factor - 1);
    		assertTrue(
    				sensor.reading() == expected,
					"LinearAdjuster sensor test failed");
    	}
    }
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
	SensorNetwork network;
	// Populate the network with sequentially named and valued sensors
	for(int i = 0; i < 10; i++){

	    auto sensor = std::make_unique<TestSensor>
	    ("Thermometer " + std::to_string(i),
	    		NullAdjuster::sharedInstance);
	    sensor->setRawReading(20 + i * 0.05);
	    network.add(std::move(sensor));
	}

    /*
     * (1) Assert that adding a sensor with a name that is already
     * used by a sensor in the network throws a DuplicateSensorName
     * exception with the sensor's name as "what".
     */
	try
	{
	    auto duplicate = std::make_unique<TestSensor>
	            ("Thermometer 5",
	            NullAdjuster::sharedInstance);

		// Attempting to add an identically named sensor must throw DuplicateSensorName
	    network.add(std::move(duplicate));
	    assertTrue(
	        false,
	        "DuplicateSensorName not thrown");
	}
	catch(const DuplicateSensorName& e)
	{
		// Verify the exception payload carries the offending sensor name
	    assertTrue(
	        std::string(e.what()) == "Thermometer 5",
	        "Wrong exception message");
	}
}
void allTests() {
    adjusterTests();
    sensorTests();
    networkTests();
}
