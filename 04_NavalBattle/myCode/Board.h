#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

// Board owns one own grid and one opponent grid.
class Board
{
private:
    OwnGrid ownGrid;
    OpponentGrid opponentGrid;

public:
	// Constructor stores the board size in both grids.
    Board(int rows, int columns);

	// Destructor is trivial.
    ~Board();

	// Returns the player's grid.
    OwnGrid& getOwnGrid();

	// Returns the opponent's grid.
    OpponentGrid& getOpponentGrid();

	// Returns the number of rows.
    int getRows() const;

	// Returns the number of columns.
    int getColumns() const;
};

#endif /* BOARD_H_ */
