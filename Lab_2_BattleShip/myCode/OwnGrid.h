#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <map>
#include <set>
#include <vector>

#include "GridPosition.h"
#include "Ship.h"
#include "Shot.h"

// OwnGrid stores the player's ships and all shots received.
class OwnGrid
{
private:
    int rows;
    int columns;
    std::vector<Ship> ships;
    std::set<GridPosition> shotAt;

    // Counts how many ships of each length may still be placed.
    std::map<int, int> totalShip = {{5,1},{4,2},{3,3},{2,4}};

public:
    // Constructor stores the board dimensions.
    OwnGrid(int rows, int columns);

    // Destructor is trivial.
    ~OwnGrid();

    // Returns the number of rows.
    int getRows() const;

    // Returns the number of columns.
    int getColumns() const;

    // Returns the placed ships.
    std::vector<Ship> getShips() const;

    // Returns the positions that have been shot at.
    std::set<GridPosition> getShotAt() const;

    // Tries to place a ship on the grid.
    bool placeShip(const Ship &ship);

    // Processes a shot and returns the impact.
    Impact takeBlow(const Shot& shot);
};

#endif /* OWNGRID_H_ */
