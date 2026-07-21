/*
 * QuantityDiscount.cpp
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#include "QuantityDiscount.h"

QuantityDiscount& QuantityDiscount::addLimit(float quantity, float discount) {
	// Register the discount rate for the specified minimum quantity
	limits[quantity] = discount;
	return *this;
}

float QuantityDiscount::discountFor(float quantity) const {
	float result = 0;
	// Iterate through limits to find the applicable discount
	for(auto pair : limits){
		if(quantity >= pair.first){
			// Update result as map is sorted by quantity (ascending)
			result = pair.second;
		}
		else{
			// Stop early if the requested quantity is smaller than the next limit threshold
			break;
		}
	}
	return result;
}
