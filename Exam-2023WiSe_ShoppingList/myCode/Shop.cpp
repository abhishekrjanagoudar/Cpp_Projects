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
	// Add the product to the catalog, keyed by its name
	products.insert({product.getName() , product});
	return *this;
}

Shop& Shop::setBasePrice(std::string productName, float basePrice) {
	// Look up the product by name
	auto pair = products.find(productName);
	if (pair == products.end()) {
		// Throw an error if the product doesn't exist in the shop
	   	throw std::invalid_argument("Product Not Found");
	}
	// Update the base price of the found product
	pair->second.setBasePrice(basePrice);
	return *this;
}

Shop& Shop::setDiscount(std::string productName,
		std::shared_ptr<Discount> discount) {
	// Look up the product by name
	auto pair = products.find(productName);
	if(pair == products.end()){
		// Throw an error if the product doesn't exist in the shop
		throw std::invalid_argument("Product Not Found");
	}
	// Update the discount strategy for the found product
	pair->second.setDiscount(discount);
	return *this;
}

float Shop::calculatePurchase(const ShoppingList& shoppingList,
		std::set<const Item*>& notAvailable) const {
	// Ensure the unavailable items set is empty before evaluation
	notAvailable.clear();
	float totalPrice = 0;

	std::list<Item>::const_iterator begin;
	std::list<Item>::const_iterator end;

	// Retrieve boundaries of the shopping list items
	shoppingList.items(begin , end);

	// Iterate over each item requested in the shopping list
	for(auto it = begin ; it !=end ; it++){
		// Check if the shop carries the requested item
		auto productIt = products.find(it->getName());
		if(productIt != products.end()){
			// Accumulate the cost applying any relevant discounts
			totalPrice = totalPrice + productIt->second.priceFor(it->getQuantity());
		}
		else{
			// Record the address of the item since it's not sold here
			notAvailable.insert(&(*it));
		}
	}
	return totalPrice;
}

