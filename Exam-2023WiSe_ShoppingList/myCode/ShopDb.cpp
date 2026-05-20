/*
 * ShopDb.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "ShopDb.h"
#include "Shop.h"

using namespace std;

ShopDb& ShopDb::addShop(std::unique_ptr<Shop>&& shop) {
	// TODO (add code)
	return *this;
}

vector<Shop*> ShopDb::shops() const {
	// TODO (add code/replace "dummy return")
	return vector<Shop*>();
}

Shop* ShopDb::shopByName(std::string name) {
	// TODO (add code/replace "dummy return")
	return nullptr;
}
