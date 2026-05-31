#pragma once

#include <iostream>

using namespace std;

/*
========================================================
CLASS: Wheel
========================================================
Purpose:
Represents wheel information.
*/

class Wheel {

private:

    // Wheel size in inches
    int size;

public:

    // Constructor
    Wheel(int s);

    // Returns wheel size
    int getSize();
};
