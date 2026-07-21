/* main.cpp - simple runner with exam-friendly inline notes */

#include <iostream>
#include <cstdlib>
#include "ModuloNCounter.h"

using namespace std;

int main()
{
	// `setvbuf` used to disable stdout buffering for immediate console output
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfDigits, typeOfCounter;

	// Main interactive loop - demonstrates program flow, input and loops
	while (true)
	{
		cout << endl << endl << "Please enter the parameters of your counter:" << endl;

		cout << "number of digits: ";
		cin >> noOfDigits; // user input (no validation here)

		cout << "type (2/8/10/16): ";
		cin >> typeOfCounter; // base of counter (syntax: integer variable)

		// Print human-readable description of chosen base
		cout << noOfDigits << " digit ";
		if (typeOfCounter == 2)
			cout << "binary counter";
		else if (typeOfCounter == 8)
			cout << "octal counter";
		else if (typeOfCounter == 10)
			cout << "decimal counter";
		else if (typeOfCounter == 16)
			cout << "hexadecimal counter";
		cout << endl;

		// Initialize the counter object (calls constructor)
		ModuloNCounter myCounter = ModuloNCounter(typeOfCounter, noOfDigits);

		// Compute number of states: base^digits using a loop (avoid pow to keep it simple)
		int maxCounterValue = 1;
		for (int i = 0; i < noOfDigits; i++)
		{
			// Loop and arithmetic: repeated multiplication produces base^digits
			maxCounterValue *= typeOfCounter;
		}

		// Iterate and print counter values; note: +2 shows wrap-around examples
		for (int i = 0; i < maxCounterValue + 2; i++)
		{
			if (i % typeOfCounter == 0)
				cout << endl; // formatting: new line every `typeOfCounter` prints
			myCounter.print(); // prints current value
			myCounter.increment(); // advance counter (may cause wrap)
		}

	}

	return 0; // program never reaches here due to infinite loop
}
