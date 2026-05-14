#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

#include "ModuloNDigit.h"

// The multi-digit counter owns a dynamic array of digits.
class ModuloNCounter
{
public:
	// Constructor builds the digit array and stores the base.
	ModuloNCounter(int maxRange, int noOfDigits);
	// Copy constructor keeps the dynamic array safe with deep copy.
	ModuloNCounter(const ModuloNCounter &other);
	// Destructor releases the allocated digit array.
	~ModuloNCounter();

	int rangeN;
	int noOfDigits;
	ModuloNDigit *counter;

	// Increments the whole counter like an odometer.
	bool increment();
	// Prints the full value from most significant to least significant digit.
	void print();
};

#endif /* MODULONCOUNTER_H_ */
