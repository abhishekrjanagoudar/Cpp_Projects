/*
 * ShopDb.h
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#ifndef SHOPDB_H_
#define SHOPDB_H_

#include <map>
#include <vector>
#include <memory>

class Shop;

/**
 * Provides a very simple database with shops.
 */
class ShopDb {
private:
	std::map<std::string, std::unique_ptr<Shop>> knownShops;

public:
	/**
	 * Add a shop to the database. (2 points)
	 *
	 * @param shop the shop to add
	 * @returns the shop database for easy chaining of method invocations
	 */
	ShopDb& addShop(std::unique_ptr<Shop>&& shop);

	/**
	 * Returns the shops in the database. (3 points)
	 *
	 * @returns the shops in the database as a vector of pointers to
	 * the shops
	 */
	std::vector<Shop*> shops() const;

	/**
	 * Returns a pointer to the shop with the given name if such
	 * a shop is known, else a nullptr. (4 points)
	 *
	 * @param name the shop's name
	 * @returns the result as described above
	 */
	Shop* shopByName(std::string name);
};

#endif /* SHOPDB_H_ */
