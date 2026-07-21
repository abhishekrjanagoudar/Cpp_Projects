#ifndef SHIP_H_
#define SHIP_H_

#include <set>
#include <string>
#include "GridPosition.h"

// Ship stores the bow and stern positions of one ship.
class Ship
{
private:
    GridPosition bow;
	GridPosition stern;

public:
	// Default constructor.
    Ship();

	// Constructor from bow and stern positions.
    Ship(GridPosition bow, GridPosition stern);

	// Destructor is trivial.
    ~Ship();

	// Checks alignment, length, and validity.
    bool isValid() const;

	// Returns the bow position.
    GridPosition getBow() const;

	// Returns the stern position.
    GridPosition getStern() const;

	// Returns the number of occupied cells.
    int length() const;

	// Returns the positions covered by the ship.
	std::set<GridPosition> occupiedArea() const;

	// Returns the ship plus all surrounding cells.
	std::set<GridPosition> blockedArea() const;

	// Equality compares bow and stern.
    bool operator==(const Ship &other) const;
};

#endif /* SHIP_H_ */
