#include <iostream>
#include <string>
#include <map>

#include "Notebook.h"
#include "Note.h"

using namespace std;

Notebook::Notebook(string title)
    : Topic(title) {
}

Notebook::~Notebook() {
}

void Notebook::print(ostream& out) const {
    string caption = "Notebook: " + getTitle();

    // Render the main top-level headline for the notebook structure
    out << caption << endl;
    out << string(caption.length(), '-') << endl;

    // Instruct all internally hosted elements to print themselves sequentially
    for (auto item : getItems()) {
        item->printItem(out, 3);
    }
}

void Notebook::print() const {
    // Relay printing execution targeting standard output console
    print(cout);
}

void Notebook::saveAsCsv(std::ostream& out) const {
    // Bootstrap the CSV export process ensuring the root passes a null parent
    writeCsv(out, nullptr);
}

Notebook* Notebook::loadFromCsv(std::istream& in) {

    map<long, Topic*> topics;
    string line;

    // Iterate line by line evaluating contents to progressively rebuild the hierarchy
    while (getline(in, line)) {

        // Delegate parsing trial to Topic deserializer logic
        if (Topic::fromCsv(topics, line)) {
            continue;
        }

        // Proceed parsing as Note if it was not detected as a Topic
        Note::fromCsv(topics, line);
    }

    // Return safely without instantiation if file provided zero parseable items
    if (topics.empty()) {
        return nullptr;
    }

    // Isolate the very first topic encountered which corresponds to the root notebook
    Topic* rootTopic = topics.begin()->second;

    // Construct the actual Notebook type object using root topic properties
    Notebook* notebook =
            new Notebook(rootTopic->getTitle());

    // Discard the initial generic topic used during bootstrap deserialization
    delete rootTopic;

    // Re-link the primary map element to point toward the final Notebook object
    topics.begin()->second = notebook;

    return notebook;
}
