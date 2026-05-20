#include <iostream>
#include <sstream>

#include "Topic.h"

using namespace std;

// TODO
Topic::Topic(string title) : Item("") {
}

Topic::~Topic() {
}

void Topic::add(std::unique_ptr<Item>& item) {
	// TODO
}

void Topic::add(std::unique_ptr<Item>&& item) {
	// TODO
}

std::vector<const Item*> Topic::getItems() const {
	// TODO (replace dummy)
    return {};
}

void Topic::printItem(ostream& out, int indent) const {
	// TODO
}

void Topic::writeCsv(std::ostream& out, const Item* parent) const {
	// TODO
}

bool Topic::fromCsv(std::map<long, Topic*>& topics, std::string line) {
	// TODO (replace dummy)
    return false;
}
