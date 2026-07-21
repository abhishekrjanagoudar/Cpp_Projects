/*
 * Item.h
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>

/**
 * Represents an item on a shopping list. An item consist of a name and
 * the required quantity expressed in implicitly assumed "units". The
 * precise definition of the "unit" for a good is not important for this
 * exercise. Assume the unit to be something commonly used when shopping,
 * e.g. "litre/liter" for milk, "kg" for bread, "g" for butter and "piece(s)"
 * for tooth brushes.
 */
class Item {
private:
	std::string name;
	float quantity;

public:
	/**
	 * Initializes a new item with the given name and quantity.
	 *
	 * @param name the item's name
	 * @param quantity the required quantity
	 */
	Item(std::string name, float quantity);

	/**
	 * Returns the item's name.
	 *
	 * @return the item's name
	 */
	std::string getName() const;

	/**
	 * Returns the required quantity.
	 *
	 * @return the required quantity
	 */
	float getQuantity() const;
};

#endif /* ITEM_H_ */
