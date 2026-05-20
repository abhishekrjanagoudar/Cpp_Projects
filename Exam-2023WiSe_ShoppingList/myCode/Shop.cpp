/*
 * Shop.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include <list>
#include <stdexcept>

#include "Shop.h"
#include "ShoppingList.h"
#include "Item.h"
#include "Discount.h"

using namespace std;

Shop::Shop(std::string name) : name{name} {
}

std::string Shop::getName() const {
	return name;
}

Shop& Shop::addProduct(const Product &product) {
	// TODO (add code)
	return *this;
}

Shop& Shop::setBasePrice(std::string productName, float basePrice) {
	// TODO (add code)
	return *this;
}

Shop& Shop::setDiscount(std::string productName,
		std::shared_ptr<Discount> discount) {
	// TODO (add code)
	return *this;
}

float Shop::calculatePurchase(const ShoppingList& shoppingList,
		std::set<const Item*>& notAvailable) const {
	// TODO (add code/replace "dummy return")
	return 0;
}

