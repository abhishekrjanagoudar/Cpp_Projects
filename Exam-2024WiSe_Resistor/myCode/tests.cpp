#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>

#include "Resistor.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "ResistanceReader.h"

using namespace std;

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
 * Basic tests for resistors. (5 points)
 */
void resistorTests() {
	/*
	 * Create a resistor with name "R1", value 1000 Ohm and tolerance of 10%.
	 * Then assert that the name is "R1", the nominal value is 1000 Ohm
	 * and the minimal and maximum values are evaluated correctly.
	 */
	// TODO
}

/**
 * Basic tests for serial connections. (4 points)
 */
void serialTests() {
    /*
     * Create a serial connection with name "Rs". It combines the
     * resistors with names "R1" (1 kOhm +/-10%) and "R2"
     * (4.7 kOhm +/-10%). Then assert that components() returns the
     * expected result "[R1-R2]" and the nominal, minimal and maximum
     * values are returned correctly. (4 points)
     */
    SerialResistorConnection rS("Rs");
    ResistancePtr r1 = make_unique<Resistor>(Resistor("R1", 1000, 0.1));
    rS += std::move(r1);
    rS += make_unique<Resistor>(Resistor("R2", 4700, 0.1));

    // TODO check name and values
}

/**
 * Basic tests for parallel connections. (10 points)
 */
void parallelTests() {
    /*
     * Create a parallel connection with name "Rp". It combines the
     * resistors with names "R1" (1 kOhm +/-10%) and "R2"
     * (1 kOhm +/-10%). Then assert that the result from components() and
     * the nominal, minimal and maximum values are returned correctly.
     *
     * Remember when doing the checks that float arithmetic is not exact.
     * If you expect a value of 500 Ohm, then it is ok if the value is
     * between 499.999 and 500.001 Ohm.
     */
    // TODO
}

/**
 * Basic tests for reading and writing. (8 points)
 */
void readWriteTests() {
    /*
     * Create a parallel connection with name "Rnet". It connects the
     * resistors with names "R1" (1 kOhm +/-10%), "R2" (4.7 kOhm +/-10%)
     * and "R3" (6.8 kOhm +/-10%) as shown here:
     *
     *     .-----[R1]-----.
     * ----|              |----
     *     '--[R2]--[R3]--'
     *
     * Write the data to a file. Read it back using the read() method.
     * Assert that the map with results has only a single entry, that
     * the name of the entry is "Rnet" and that a call to components()
     * returns the same result as for the original network which was
     * written to the file.
     */
    auto rNet = make_unique<ParallelResistorConnection>
        (ParallelResistorConnection("Rnet"));
    (*rNet) += make_unique<Resistor>(Resistor("R1", 1000, 0.1));
    auto rS = make_unique<SerialResistorConnection>
        (SerialResistorConnection(SerialResistorConnection("Rs")));
    (*rS) += make_unique<Resistor>(Resistor("R2", 4700, 0.1));
    (*rS) += make_unique<Resistor>(Resistor("R3", 6800, 0.1));
    (*rNet) += std::move(rS);

    // TODO
}


void allTests() {
    resistorTests();
    serialTests();
    parallelTests();
    readWriteTests();
}
