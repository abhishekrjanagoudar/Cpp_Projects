/*
 * Notebook.cpp
 *
 *  Created on: 13.07.2024
 *      Author: mnl
 */

#include <iostream>
#include <string>
#include "Notebook.h"
#include "Note.h"

using namespace std;

// TODO
Notebook::Notebook(string title) : Topic("") {
}

Notebook::~Notebook() {
}

void Notebook::print(ostream& out) const {
	// TODO
}

void Notebook::print() const {
	// TODO
}

void Notebook::saveAsCsv(std::ostream &out) const {
	// TODO
}

Notebook* Notebook::loadFromCsv(std::istream &in) {
	// TODO (replace dummy)
    return nullptr;
}
