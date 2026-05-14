#include "ModuloNCounter.h"
#include "ModuloNDigit.h"
#include <iostream>

using namespace std;

// Digits above 9 are printed as A-F for hexadecimal output.
char ch[] = "0123456789ABCDEF";

ModuloNCounter::ModuloNCounter(int maxRange, int noOfDigits)
{
	rangeN = maxRange;
	this->noOfDigits = noOfDigits;
	// Dynamic memory is needed because the digit count is chosen at runtime.
	counter = new ModuloNDigit[noOfDigits];
	for (int i = 0; i < noOfDigits; i++)
	{
		counter[i] = ModuloNDigit(rangeN);
	}
}

ModuloNCounter::~ModuloNCounter()
{
	delete[] counter;
}

bool ModuloNCounter::increment()
{
	// Work from right to left, just like carrying in normal arithmetic.
	for (int index = noOfDigits - 1; index >= 0; index--)
	{
		if (counter[index].incrementCounter())
		{
			if (index == 0)
			{
				return true;
			}
		}
		else
		{
			break;
		}
	}
	return false;
}

ModuloNCounter::ModuloNCounter(const ModuloNCounter &other)
{
	// Deep copy keeps each counter object independent.
	this->rangeN = other.rangeN;
	this->noOfDigits = other.noOfDigits;
	counter = new ModuloNDigit[noOfDigits];
	for (int i = 0; i < noOfDigits; i++)
	{
		counter[i] = other.counter[i];
	}
}

void ModuloNCounter::print()
{
	// Print the most significant digit first.
	for (int i = 0; i < noOfDigits; i++)
	{
		cout << ch[counter[i].countValue];
	}
	cout << " ";
}
