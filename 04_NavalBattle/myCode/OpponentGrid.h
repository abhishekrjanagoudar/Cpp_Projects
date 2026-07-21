#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <map>
#include <set>
#include <vector>
#include <string>

#include "Ship.h"
#include "Shot.h"

// OpponentGrid stores all visible shot results on the enemy side.
class OpponentGrid
{
private:
	int rows;
	int columns;
	std::map<GridPosition, Impact> shots;
	std::vector<Ship> sunkenShips;

public:
	// Constructor stores the board dimensions.
	OpponentGrid(int rows, int columns);

	// Destructor is trivial.
	~OpponentGrid();

	// Returns the number of rows.
	int getRows() const;

	// Returns the number of columns.
	int getColumns() const;

	// Returns the recorded shots.
	const std::map<GridPosition, Impact>& getShotsAt() const;

	// Returns the sunk ships.
	const std::vector<Ship>& getSunkenShip() const;

	// Stores the result of one shot.
	void shotResult(const Shot &shot, Impact impact);
};

#endif /* OPPONENTGRID_H_ */
