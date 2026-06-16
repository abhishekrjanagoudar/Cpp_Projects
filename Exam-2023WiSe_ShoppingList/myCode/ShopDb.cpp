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
	// Transfer ownership of the shop into the database using its name as the key
	knownShops[shop->getName()] = std::move(shop);
	return *this;
}

vector<Shop*> ShopDb::shops() const {
	vector<Shop*> result;
	for(auto& it : knownShops){
		result.push_back(it.second.get());
	}

	return result;
}

Shop* ShopDb::shopByName(std::string name) {
	auto it = knownShops.find(name);
	if(it != knownShops.end()){
		return it->second.get();
	}
	return nullptr;
}
