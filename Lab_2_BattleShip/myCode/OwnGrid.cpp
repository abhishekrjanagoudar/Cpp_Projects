#include "OwnGrid.h"
#include <set>

using namespace std;

// Constructor that stores the board size.
OwnGrid::OwnGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

// Destructor for the OwnGrid class.
OwnGrid::~OwnGrid()
{
}

// Gets the number of rows in the grid.
int OwnGrid::getRows() const
{
	return rows;
}

// Gets the number of columns in the grid.
int OwnGrid::getColumns() const
{
	return columns;
}

// Gets the list of ships placed on the grid.
vector<Ship> OwnGrid::getShips() const
{
	return ships;
}

// Places a ship only if it is valid and does not touch another ship.
bool OwnGrid::placeShip(const Ship &ship)
{
	if (!ship.isValid())
	{
		return false;
	}

	int shipLength = ship.length();
	auto remainingShips = totalShip.find(shipLength);
	if (remainingShips == totalShip.end() || remainingShips->second == 0)
	{
		return false;
	}

	std::set<GridPosition> occupiedArea = ship.occupiedArea();
	for (const Ship &existingShip : ships)
	{
		std::set<GridPosition> blockedArea = existingShip.blockedArea();
		for (const GridPosition &position : occupiedArea)
		{
			if (blockedArea.count(position) > 0)
			{
				return false;
			}
		}
	}

	ships.push_back(ship);
	remainingShips->second--;
	return true;
}

// Returns HIT, SUNKEN, or NONE for a shot at this grid.
Impact OwnGrid::takeBlow(const Shot &shot)
{
	if (shotAt.count(shot.getTargetPosition()) > 0)
	{
		return NONE;
	}

	shotAt.insert(shot.getTargetPosition());

	for (const Ship &ship : ships)
	{
		std::set<GridPosition> occupiedArea = ship.occupiedArea();
		if (occupiedArea.count(shot.getTargetPosition()) > 0)
		{
			bool shipSunk = true;
			for (const GridPosition &position : occupiedArea)
			{
				if (shotAt.count(position) == 0)
				{
					shipSunk = false;
					break;
				}
			}
			if (shipSunk)
			{
				return SUNKEN;
			}
			return HIT;
		}
	}

	return NONE;

}

// Gets the set of positions that have been shot at.
set<GridPosition> OwnGrid :: getShotAt() const
{
	return shotAt;
}
				return HIT;
			}
		}

	}
	// If the shot misses all ships.
	return NONE;
}

// Gets the set of positions that have been shot at.
set<GridPosition> OwnGrid :: getShotAt() const
{
	return shotAt;
}
