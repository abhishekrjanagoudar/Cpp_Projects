#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>
#include <iostream>

// GridPosition stores one row and one column.
class GridPosition
{
private:
	char row;
	int column;

public:
	// Default constructor leaves the object invalid until set.
	GridPosition();

	// Constructor from row and column.
	GridPosition(char row, int column);

	// Constructor from a string such as "A1".
	GridPosition(std::string position);

	~GridPosition();

	// Checks whether row and column are inside the legal range.
	bool isValid() const;

	// Returns the row.
	char getRow() const;

	// Returns the column.
	int getColumn() const;

	// Converts the position to text like "B10".
	operator std::string() const;

	// Equality compares row and column.
	bool operator==(const GridPosition &other) const;

	// Less-than is needed for ordered STL containers.
	bool operator<(const GridPosition &other) const;
};

#endif /* GRIDPOSITION_H_ */
