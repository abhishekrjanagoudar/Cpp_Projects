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
	knownShops[shop->getName()] = std::move(shop);

	return *this;
}

vector<Shop*> ShopDb::shops() const {

    vector<Shop*> result;

    for (auto& pair : knownShops) {
        result.push_back(pair.second.get());
    }

    return result;
}

Shop* ShopDb::shopByName(std::string name) {
	// TODO (add code/replace "dummy return")
	auto it = knownShops.find(name);
	if (it != knownShops.end()){
		return it->second.get();
	}

	return nullptr;
}
