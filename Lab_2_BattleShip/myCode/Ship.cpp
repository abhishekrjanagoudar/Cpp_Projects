#include "Ship.h"
#include <algorithm>
#include <cstdlib>

// Constructor that stores the bow and stern positions.
Ship::Ship(GridPosition bow, GridPosition stern)
{
	this->bow = bow;
	this->stern = stern;
}

// Destructor is trivial.
Ship::~Ship()
{
}

// A ship is valid only when it is straight and has length 2 to 5.
bool Ship::isValid() const
{
	if (bow.getRow() != stern.getRow() && bow.getColumn() != stern.getColumn())
	{
		return false;
	}
	return length() >= 2 && length() <= 5;

}

// Returns the bow position.
GridPosition Ship::getBow() const
{
	return bow;
}

// Returns the stern position.
GridPosition Ship::getStern() const
{
	return stern;
}

// Returns the number of cells the ship occupies.
int Ship::length() const
{
	if (bow.getRow() == stern.getRow())
	{
		return std::abs(bow.getColumn() - stern.getColumn()) + 1;
	}
	if (bow.getColumn() == stern.getColumn())
	{
		return std::abs(bow.getRow() - stern.getRow()) + 1;
	}
	return 0;
}

// Returns all cells occupied by the ship.
std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedArea;
	if (bow.getRow() == stern.getRow())
	{
		int startColumn = std::min(bow.getColumn(), stern.getColumn());
		int endColumn = std::max(bow.getColumn(), stern.getColumn());
		for (int column = startColumn; column <= endColumn; ++column)
		{
			occupiedArea.insert(GridPosition(bow.getRow(), column));
		}
	}
	else if (bow.getColumn() == stern.getColumn())
	{
		char startRow = std::min(bow.getRow(), stern.getRow());
		char endRow = std::max(bow.getRow(), stern.getRow());
		for (char row = startRow; row <= endRow; ++row)
		{
			occupiedArea.insert(GridPosition(row, bow.getColumn()));
		}
	}
	return occupiedArea;

}

// Returns the ship plus the surrounding blocked cells.
std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blockedArea;

	int startRow = min(bow.getRow(), stern.getRow());
	int endRow = max(bow.getRow(), stern.getRow());
	int startCol = min(bow.getColumn(), stern.getColumn());
	int endCol = max(bow.getColumn(), stern.getColumn());

	// Check one cell around the ship in each direction.
	for (int row = startRow - 1; row <= endRow + 1; ++row)
	{
		for (int col = startCol - 1; col <= endCol + 1; ++col)
		{
			if (row >= 'A' && row <= 'Z' && col >= 1)
			{
				blockedArea.insert(GridPosition(row, col));
			}
		}
	}

	return blockedArea;
}

// Default constructor.
Ship::Ship()
{
}

// Equality compares bow and stern.
bool Ship::operator ==(const Ship &other) const
{
	return this->bow == other.getBow() && this->stern == other.getStern();
}
