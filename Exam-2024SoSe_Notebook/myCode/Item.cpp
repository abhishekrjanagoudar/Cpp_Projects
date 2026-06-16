#include <iostream>

#include "Item.h"

using namespace std;

long Item::idCounter = 0;

Item::Item(string title) : id(++idCounter), title{title} {}

Item::~Item() {}

long Item::getId() const { return id; }

std::string Item::getTitle() const { return title; }

void Item::printItem(std::ostream &out, int indent) const {
  // Output item title with correct indentation level and bullet format
  out << string(indent, ' ') << "- " << title << endl;
}
