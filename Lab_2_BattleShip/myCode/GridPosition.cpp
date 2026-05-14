#include "GridPosition.h"
#include <string>

// Constructor that initializes a GridPosition with specified row and column.
GridPosition::GridPosition(char row, int column)
{
	this->row = row;
	this->column = column;
}

GridPosition::~GridPosition()
{
}

// Constructor that initializes GridPosition from a string such as "A1".
GridPosition::GridPosition(std::string position)
{
	// Take the first character as the row letter.
	this->row = position[0];

	// Convert the remaining characters to a column number.
	this->column = (stoi(position.substr(1)));
}

// Check if the GridPosition is valid.
bool GridPosition::isValid() const
{
	return (row >= 'A' && row <= 'Z' && column >= 1);

}

// Get the row of the position.
char GridPosition::getRow() const
{
	return row;
}

// Get the column of the position.
int GridPosition::getColumn() const
{
	return column;
}

// Converts the GridPosition to a string representation.
GridPosition::operator std::string() const
{
	// Build the usual text form like "B10".
	return std::string(1, row) + std::to_string(column);
}

// Equality operator to compare two GridPosition objects.
bool GridPosition::operator==(const GridPosition &other) const
{
	return (row == other.row) && (column == other.column);
}

// Default constructor that leaves the object invalid.
GridPosition::GridPosition()
{
}

// Less-than operator to compare two GridPosition objects.
bool GridPosition::operator<(const GridPosition &other) const
{
	if (row < other.row)
	{
		return true;
	}
	if (row == other.row)
	{
		return column < other.column;
	}
	return false;
}
