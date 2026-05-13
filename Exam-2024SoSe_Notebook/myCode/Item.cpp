#include <iostream>

#include "Item.h"

using namespace std;

long Item::idCounter = 0;

// TODO
Item::Item(string title) : title{""} {
	// TODO
}

Item::~Item() {
}

long Item::getId() const {
	// TODO (replace dummy)
	return 0;
}

std::string Item::getTitle() const {
	// TODO (replace dummy)
	return "";
}

void Item::printItem(std::ostream &out, int indent) const {
	// TODO
}
