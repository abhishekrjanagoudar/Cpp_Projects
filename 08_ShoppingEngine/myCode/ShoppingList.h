/*
 * ShoppingList.h
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#ifndef SHOPPINGLIST_H_
#define SHOPPINGLIST_H_

#include <list>
#include <memory>

class Item;

/**
 * Models a shopping list. Such a list consists of items, each of
 * which is simply an entry with a name and a quantity (see
 * class Item).
 */
class ShoppingList {
private:
	std::list<Item> neededItems;

public:
	/**
	 * Adds an item with the given name to the shopping list.
	 * (2 points)
	 *
	 * @param name the name of the item
	 * @param quantity the required quantity
	 * @returns the shopping list for easy chaining of method invocations
	 */
	ShoppingList& addItem(std::string name, float quantity);

	/**
	 * Provides access to the items by returning a
	 * begin and end iterator. (2 points)
	 *
	 * @param begin iterator to the first item
	 * @param end iterator to the "item after the last item"
	 * (past-the-end item)
	 */
	void items(std::list<Item>::const_iterator& begin,
			std::list<Item>::const_iterator& end) const;
};

#endif /* SHOPPINGLIST_H_ */
