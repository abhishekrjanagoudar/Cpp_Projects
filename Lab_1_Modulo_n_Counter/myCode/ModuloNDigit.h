#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

// One digit stores its current value and the base it counts in.
class ModuloNDigit
{
public:
	// Public data keeps the example simple and easy to inspect.
	int countValue = 0;
	int rangeN;

	// Default constructor creates an empty digit with zero values.
	ModuloNDigit();
	// This constructor sets the base for one modulo digit.
	ModuloNDigit(int maxRange);
	// No dynamic memory is used, so the destructor is empty.
	~ModuloNDigit();

	// Adds one and wraps back to zero when the base is reached.
	bool incrementCounter();
	// Prints only the value, without a newline.
	void printCounter();
};

#endif /* MODULONDIGIT_H_ */
