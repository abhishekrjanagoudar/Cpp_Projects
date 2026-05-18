/* ModuloNCounter.h - simple notes and exam hints */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

#include "ModuloNDigit.h"

// ModuloNCounter: manages a multi-digit counter (OOP: composition)
// - Uses an array of `ModuloNDigit` objects to represent digits
// Exam notes: constructors allocate resources; copy ctor must deep-copy; destructor frees memory.
class ModuloNCounter
{
public:
	ModuloNCounter(int maxRange, int noOfDigits);
	ModuloNCounter(const ModuloNCounter &other);
	~ModuloNCounter(); // Destructor: frees dynamic array (see cpp)

	int rangeN; // base/range for each digit (syntax: simple member)
	int noOfDigits; // number of digits in the counter
	ModuloNDigit *counter; // pointer to dynamic array (pointers: holds address returned by new)

	// increment: advances the counter; returns true on overall overflow
	bool increment();
	// print: outputs current counter representation
	void print();
};

#endif /* MODULONCOUNTER_H_ */
