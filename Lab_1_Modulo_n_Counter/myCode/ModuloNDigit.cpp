#include "ModuloNDigit.h"
#include <iostream>

using namespace std;

// Default constructor keeps the digit in a known state.
ModuloNDigit::ModuloNDigit() : countValue(0), rangeN(0)
{
}

// Constructor to initialize the digit with a maximum range.
ModuloNDigit::ModuloNDigit(int maxRange)
    : countValue(0), rangeN(maxRange)
{
}

ModuloNDigit::~ModuloNDigit()
{
}

bool ModuloNDigit::incrementCounter()
{
	// Prefix-style increment: update first, then test for overflow.
	countValue++;
	if (rangeN <= 0 || countValue >= rangeN)
	{
		countValue = 0;
		return true;
	}
	return false;
}

void ModuloNDigit::printCounter()
{
	// The PDF asks for value output without a newline.
	cout << countValue;
}
