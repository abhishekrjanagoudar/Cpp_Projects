#include <iostream>
#include <sstream>

#include "Note.h"
#include "Topic.h"

using namespace std;

// TODO
Note::Note(string title) : Item("") {
}

Note::~Note() {
}

Note* Note::setContent(std::string content) {
	this->content = content;
	return this;
}

std::string Note::getContent() const {
	return content;
}

void Note::printItem(ostream& out, int indent) const {
    // TODO
}

void Note::writeCsv(std::ostream& out, const Item* parent) const {
    // TODO
}

bool Note::fromCsv(std::map<long, Topic*>& topics, std::string line) {
	// TODO (replace dummy)
    return false;
}
