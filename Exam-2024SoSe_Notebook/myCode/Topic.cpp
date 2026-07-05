#include <iostream>
#include <sstream>

#include "Topic.h"

using namespace std;

Topic::Topic(string title) : Item(title) {}

Topic::~Topic() {}

void Topic::add(std::unique_ptr<Item> &item) {
  // Delegate pointer ownership to internal storage list
  items.push_back(std::move(item));
}

void Topic::add(std::unique_ptr<Item> &&item) {
  // Delegate rvalue pointer ownership directly to internal storage
  items.push_back(std::move(item));
}

std::vector<const Item *> Topic::getItems() const {
  vector<const Item *> result;

  // Provide a list of raw pointers to expose items without releasing ownership
  for (const auto &item : items) {
    result.push_back(item.get());
  }

  return result;
}

void Topic::printItem(ostream &out, int indent) const {
  // Present current topic heading
  Item::printItem(out, indent);

  // Recursively print all child items with increased indentation
  for (const auto &item : items) {
    item->printItem(out, indent + 3);
  }
}

void Topic::writeCsv(std::ostream &out, const Item *parent) const {
  // Generate CSV representation of the topic including ID relationship
  out << "Topic" << ";" << getId() << ";" << (parent ? parent->getId() : 0)
      << ";" << getTitle() << ";" << endl;

  // Traverse and dump all child elements passing the current topic as parent
  for (const auto &item : items) {
    item->writeCsv(out, this);
  }
}

bool Topic::fromCsv(std::map<long, Topic *> &topics, std::string line) {
  stringstream ss(line);

  string type;
  string idStr;
  string parentIdStr;
  string title;

  // Extract item type prefix
  getline(ss, type, ';');

  // Abort if this row is not representing a Topic object
  if (type != "Topic") {
    return false;
  }

  // Extract the remaining attributes from CSV row
  getline(ss, idStr, ';');
  getline(ss, parentIdStr, ';');
  getline(ss, title, ';');

  long id = stol(idStr);
  long parentId = stol(parentIdStr);

  // Instantiate new Topic entity
  Topic *topic = new Topic(title);

  // Register Topic in dictionary to allow resolution of upcoming children
  topics[id] = topic;

  // Attach to the corresponding parent topic if applicable
  if (parentId != 0) {
    auto parent = topics[parentId];
    auto ptr = std::unique_ptr<Item>(topic);
    parent->add(ptr);
  }

  return true;
}
