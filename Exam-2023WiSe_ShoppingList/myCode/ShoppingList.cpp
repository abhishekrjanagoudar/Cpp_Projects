/*
 * ShoppingList.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "ShoppingList.h"
#include "Item.h"

using namespace std;

ShoppingList& ShoppingList::addItem(std::string name, float quantity) {
	// Instantiate and append the item to the needed items list
	neededItems.push_back(Item(name , quantity));
	return *this;
}

// Retrieves begin and end iterators for the items.
void ShoppingList::items(std::list<Item>::const_iterator& begin,
		std::list<Item>::const_iterator& end) const {
	begin = neededItems.begin();
	end = neededItems.end();
}
