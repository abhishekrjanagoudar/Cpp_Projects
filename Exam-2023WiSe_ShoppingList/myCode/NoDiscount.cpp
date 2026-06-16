/*
 * NoDiscount.cpp
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#include "NoDiscount.h"

using namespace std;

shared_ptr<Discount> NoDiscount::instance
	= shared_ptr<Discount>(new NoDiscount());

float NoDiscount::discountFor(float quantity) const {
	// Return 0 to indicate no discount applies for any quantity
	return 0;
}
