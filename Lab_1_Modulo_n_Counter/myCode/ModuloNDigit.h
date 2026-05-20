	/* ModuloNDigit.h - short notes and quick exam hints */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

	// ModuloNDigit: single digit counter that wraps at `rangeN`.
	// Syntax note: member initialization and default values (C++11): `int countValue = 0;`.
	// Exam hint: incrementCounter demonstrates modular arithmetic and wrap-around logic.
class ModuloNDigit
{
public:
	int countValue = 0;
	int rangeN;

	// Constructors/Destructors: initialize and cleanup
	ModuloNDigit();
	ModuloNDigit(int maxRange); // set upper bound for wrap-around
	~ModuloNDigit();

	// incrementCounter: increases value and returns true if wrapped to 0
	bool incrementCounter();
	// printCounter: prints current value (logic kept simple for exams)
	void printCounter();
};

#endif /* MODULONDIGIT_H_ */
