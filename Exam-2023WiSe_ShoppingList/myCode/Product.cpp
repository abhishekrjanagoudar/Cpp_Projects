/*
 * Product.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "Product.h"
#include "NoDiscount.h"

using namespace std;

Product::Product(std::string name, float basePrice)
	: name{name}, basePrice{basePrice}, discount{NoDiscount::instance} {
}

string Product::getName() const {
	return name;
}

Product& Product::setBasePrice(float basePrice) {
	this->basePrice = basePrice;
	return *this;
}

Product& Product::setDiscount(std::shared_ptr<Discount> discount) {
	this->discount = discount;
	return *this;
}

float Product::priceFor(float quantity) const {
	// TODO (replace "dummy return")
	return 0;
}

