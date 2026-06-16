// Standard (system) header files
#include <iostream>
#include <cstdlib>

// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main entry point that executes all tests.
int main () {
	// Print student details
    cout << "Student Name: Abhishek Janagoudar, Matrikel-Nb: 1134273" << endl << endl;
    
	// Execute all test cases
    extern void allTests();
    allTests();
    return 0;
}
