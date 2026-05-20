#include <sstream>
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "Resistor.h"
#include "ResistanceReader.h"

void ResistanceReader::read(std::istream &in, std::map<std::string,
        ResistancePtr > &found) {
    while (!in.eof()) {
        std::string line;
        getline(in, line);
        if (line.find_first_of(";") == std::string::npos) {
            continue;
        }

        // TODO: process line content
    }
}
