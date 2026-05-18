/* ModuloNCounter.cpp - implementation with exam-friendly notes */

#include "ModuloNCounter.h"
#include "ModuloNDigit.h"
#include <iostream>

using namespace std;

// Character map for printing digits in bases up to 16 (strings represent digits)
// Syntax note: this is a C-style string/array used for mapping numeric value -> character.
char ch[] = "0123456789ABCDEF";

// Constructor: initializes counter array with specified range and digits
// OOP note: allocates dynamic array of `ModuloNDigit` (composition via pointer)
ModuloNCounter::ModuloNCounter(int maxRange, int noOfDigits)
{
	rangeN = maxRange; // store base/range
	this->noOfDigits = noOfDigits; // store digit count
	counter = new ModuloNDigit[noOfDigits]; // allocate dynamic array (remember to delete[] in destructor)
	for (int i = 0; i < noOfDigits; i++)
	{
		counter[i] = ModuloNDigit(rangeN); // initialize each digit with same range
	}
}

// Destructor: releases allocated memory for `counter`
// Constructors/Destructors: manage resource lifecycle (RAII note: this class uses manual new/delete)
ModuloNCounter::~ModuloNCounter()
{
	delete[] counter; // free dynamic memory to avoid leaks
}

// Increment the counter, checking each digit for wrap-around.
// Loops & conditions: iterate from least-significant to most-significant and handle carry-like behavior.
bool ModuloNCounter::increment()
{
	// Start from rightmost digit (index noOfDigits-1) and move left
	for (int index = noOfDigits - 1; index >= 0; index--)
	{
		// incrementCounter() returns true when this digit wrapped to 0 (like a carry)
		if (counter[index].incrementCounter())
		{
			if (index == 0) // leftmost digit wrapped => overall overflow
			{
				return true; // signal overflow to caller
			}
			// else continue loop to propagate carry to next digit on the left
		}
		else
		{
			break; // no wrap-around, stop propagation
		}
	}
	return false; // no overall overflow
}

// Copy constructor: performs deep copy to own a separate dynamic array
// Pointers/References note: copying pointer values would cause double-free; allocate new array instead.
ModuloNCounter::ModuloNCounter(const ModuloNCounter &other)
{
	this->rangeN = other.rangeN; // copy primitive member
	this->noOfDigits = other.noOfDigits; // copy count
	counter = new ModuloNDigit[noOfDigits]; // allocate fresh array
	for (int i = 0; i < noOfDigits; i++)
	{
		counter[i] = other.counter[i]; // copy each ModuloNDigit (calls its assignment operator)
	}
}
// Print current counter value using `ch` mapping (no STL used here)
// Function purpose: produce human-readable representation in configured base.
void ModuloNCounter::print()
{
	for (int i = 0; i < noOfDigits; i++)
	{
		// Access digit value and map to character (array indexing and member access)
		cout << ch[counter[i].countValue];
	}
	cout << " "; // spacing between printed values
}
