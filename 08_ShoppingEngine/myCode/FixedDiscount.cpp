/*
 * LinearDiscount.cpp
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#include "FixedDiscount.h"

FixedDiscount::FixedDiscount(float discount) : discount{discount} {
}

float FixedDiscount::discountFor(float quantity) const {
	// Apply the same discount regardless of the purchased quantity
	return discount;
}
