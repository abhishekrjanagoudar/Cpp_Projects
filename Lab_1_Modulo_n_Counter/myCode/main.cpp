#include <iostream>
#include <cstdlib>
#include "ModuloNCounter.h"

using namespace std;

int main()
{
	// Disable buffering so prompts appear immediately.
	setvbuf(stdout, NULL, _IONBF, 0);

	int noOfDigits;
	int typeOfCounter;

	while (cin)
	{
		// The PDF asks for repeated tests until the user stops the program.
		cout << endl << endl << "Please enter the parameters of your counter:"
				<< endl;

		cout << "number of digits: ";
		if (!(cin >> noOfDigits))
		{
			break;
		}

		cout << "type (2/8/10/16): ";
		if (!(cin >> typeOfCounter))
		{
			break;
		}

		if (noOfDigits <= 0 || (typeOfCounter != 2 && typeOfCounter != 8
				&& typeOfCounter != 10 && typeOfCounter != 16))
		{
			cout << "End of the test!" << endl;
			break;
		}

		// Friendly label for the counter type.
		cout << noOfDigits << " digit ";
		if (typeOfCounter == 2)
		{
			cout << "binary counter";
		}
		else if (typeOfCounter == 8)
		{
			cout << "octal counter";
		}
		else if (typeOfCounter == 10)
		{
			cout << "decimal counter";
		}
		else if (typeOfCounter == 16)
		{
			cout << "hexadecimal counter";
		}
		cout << endl;

		// Create the counter object. The constructor owns the dynamic array.
		ModuloNCounter myCounter(typeOfCounter, noOfDigits);

		int maxCounterValue = 1;
		for (int i = 0; i < noOfDigits; i++)
		{
			maxCounterValue *= typeOfCounter;
		}

		// Match the PDF style: 16 columns for binary/hex, otherwise base size.
		int valuesPerLine = 16;
		if (typeOfCounter == 8)
		{
			valuesPerLine = 8;
		}
		else if (typeOfCounter == 10)
		{
			valuesPerLine = 10;
		}

		// Print all states and a couple of extra values after wrap-around.
		for (int i = 0; i < maxCounterValue + 2; i++)
		{
			if (i % valuesPerLine == 0)
			{
				cout << endl;
			}

			// print() shows the full multi-digit value using the digit objects.
			myCounter.print();
			myCounter.increment();
		}

		cout << endl;
		cout << "End of the test!" << endl;

	}

	return 0;
}
