#include <iostream>
#include <sstream>

#include "Note.h"
#include "Topic.h"

using namespace std;

Note::Note(string title)
    : Item(title) {
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
    // Print the base item header first
    Item::printItem(out, indent);

    // Indent by an additional 3 spaces for content payload
    out << string(indent + 3, ' ')
        << content
        << endl;
}

void Note::writeCsv(std::ostream& out, const Item* parent) const {
    // Write note structure with parent reference and actual content text
    out << "Note;"
        << getId() << ";"
        << (parent ? parent->getId() : 0) << ";"
        << getTitle() << ";"
        << content
        << endl;
}

bool Note::fromCsv(std::map<long, Topic*>& topics, std::string line) {
    stringstream ss(line);

    string type;
    string idStr;
    string parentIdStr;
    string title;
    string content;

    // Extract item type prefix
    getline(ss, type, ';');

    // Abort if this row is not representing a Note object
    if (type != "Note") {
        return false;
    }

    // Extract the remaining attributes from CSV row
    getline(ss, idStr, ';');
    getline(ss, parentIdStr, ';');
    getline(ss, title, ';');
    getline(ss, content);

    // Convert parent ID string to integer representation
    long parentId = stol(parentIdStr);

    // Instantiate and populate the new Note entity
    Note* note = new Note(title);
    note->setContent(content);

    // Locate the topic to attach this note to
    auto parent = topics[parentId];
    parent->add(unique_ptr<Item>(note));

    return true;
}
