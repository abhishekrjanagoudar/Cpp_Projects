#include "OpponentGrid.h"

#include <string>

using namespace std;

// Constructor that initializes the OpponentGrid with specified row and column
OpponentGrid::OpponentGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

// Destructor for the OpponentGrid class.
OpponentGrid::~OpponentGrid()
{
}

// Gets the number of rows in the grid.
int OpponentGrid::getRows() const
{
	return rows;
}

// Gets the number of columns in the grid.
int OpponentGrid::getColumns() const
{
	return columns;
}


const map<GridPosition, Impact>& OpponentGrid::getShotsAt() const
{
	return shots;
}

// Gets the list of sunken ships.
const vector<Ship>& OpponentGrid::getSunkenShip() const
{
	return sunkenShips;
}

// Records the result of a shot made at the opponent's grid.
void OpponentGrid::shotResult(const Shot &shot, Impact impact)
{
	// Record the shot's impact.
	shots[shot.getTargetPosition()] = impact;

	// If no hit, return early.
	if (impact != HIT && impact != SUNKEN)
	{
		return;
	}

	// Track hit positions.
	std::set<GridPosition> hitAt;
	hitAt.insert(shot.getTargetPosition());

	// Explore the four straight directions.
	const std::vector<std::pair<int, int>> directions =
	{
	{ 0, 1 },   // Right
			{ 0, -1 },  // Left
			{ 1, 0 },   // Down
			{ -1, 0 }   // Up
	};

	// Explore each direction.
	for (const auto &direction : directions)
	{
		int rowStep = direction.first;
		int colStep = direction.second;

		GridPosition current = shot.getTargetPosition();
		while (true)
		{
			// Move in the specified direction.
			current = GridPosition(current.getRow() + rowStep,
					current.getColumn() + colStep);

			// Stop when the search leaves the grid.
			if (current.getRow() < 'A' || current.getRow() >= 'A' + rows
					|| current.getColumn() < 1 || current.getColumn() > columns)
			{
				break;
			}

			// Check shot results.
			auto it = shots.find(current);
			if (it == shots.end() || it->second == NONE)
			{
				break;
			}
			if (it->second == HIT)
			{
				hitAt.insert(current);
			}
		}
	}

	// Add the new sunken ship.
	if (impact == SUNKEN)
	{
		sunkenShips.push_back(Ship(*hitAt.begin(), *hitAt.rbegin()));
	}
}

