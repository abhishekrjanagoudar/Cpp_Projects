/*
 * Item.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "Item.h"

Item::Item(std::string name, float quantity)
	: name{name}, quantity{quantity} {
}

std::string Item::getName() const {
	return name;
}

float Item::getQuantity() const {
	return quantity;
}
