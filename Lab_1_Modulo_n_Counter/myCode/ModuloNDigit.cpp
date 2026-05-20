
/* ModuloNDigit.cpp - implementation with short notes */

#include "ModuloNDigit.h"
#include <iostream>

using namespace std;

// Constructor to initialize counter with a maximum range
// Constructor/Destructor: show basic initialization and cleanup
ModuloNDigit::ModuloNDigit(int maxRange)
{
	rangeN = maxRange; // store the modulo base
	countValue = 0; // ensure starting at 0
}

// Destructor
ModuloNDigit::~ModuloNDigit()
{
}

// Increment counter and reset if it reaches the maximum
// Logic: increment then check for wrap-around (modular arithmetic)
bool ModuloNDigit::incrementCounter()
{
	countValue++; // increase this digit
	if (countValue >= rangeN) // if reached base, wrap to 0
	{
		countValue = 0; // wrap-around
		return true; // indicate wrap occurred (used by ModuloNCounter to propagate carry)
	}
	return false; // no wrap
}

// Print the current value of the counter
// Function purpose: simple output for debugging or demonstration
void ModuloNDigit::printCounter()
{
	cout << countValue << endl;
}

// Default constructor: keep range at 0 until set by parameterized ctor
ModuloNDigit::ModuloNDigit()
{
	countValue = 0;
	rangeN = 0;
}
