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
	products.insert({product.getName(), product});

	return *this;
}

Shop& Shop::setBasePrice(std::string productName, float basePrice) {
	// TODO (add code)
	auto it = products.find(productName);
	    if (it == products.end()) {
	        throw std::invalid_argument("Error");
	    }
	    it->second.setBasePrice(basePrice);
	return *this;
}

Shop& Shop::setDiscount(std::string productName,
		std::shared_ptr<Discount> discount) {
	// TODO (add code)
	auto it = products.find(productName);
	if(it == products.end()){
		throw std::invalid_argument("Error");
	}
	it->second.setDiscount(discount);
	return *this;
}

float Shop::calculatePurchase(
        const ShoppingList& shoppingList,
        std::set<const Item*>& notAvailable) const {

    float totalPrice = 0;

    list<Item>::const_iterator begin;
    list<Item>::const_iterator end;

    shoppingList.items(begin, end);

    for (auto it = begin; it != end; ++it) {

        auto productIt =
                products.find(it->getName());

        if (productIt != products.end()) {

            totalPrice +=
                    productIt->second.priceFor(
                            it->getQuantity());

        } else {

            notAvailable.insert(&(*it));

        }
    }

    return totalPrice;
}

