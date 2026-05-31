/*
 * QuantityDiscount.cpp
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#include "QuantityDiscount.h"

QuantityDiscount& QuantityDiscount::addLimit(float quantity, float discount) {
	limits[quantity] = discount;
	return *this;
}

float QuantityDiscount::discountFor(float quantity) const {
	// TODO (add code/replace dummy return)
	float result = 0;
	for (auto pair : limits){
		if(quantity >= pair.first){
			return pair.second;
		}
	else {
		break;
	}
}
	return result;
}
