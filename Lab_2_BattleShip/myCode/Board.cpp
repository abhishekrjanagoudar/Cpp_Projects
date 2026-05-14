#include "Board.h"

// Constructor that initializes the Board with given grid dimensions.
Board::Board(int rows, int columns) :
		ownGrid(rows, columns), opponentGrid(rows, columns)
{
}

// Destructor for the Board class.
Board::~Board()
{
}

// Gets the player's grid (OwnGrid).
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

// Gets the opponent's grid (OpponentGrid).
OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}

// Gets the number of rows in the grid.
int Board::getRows() const
{
	return ownGrid.getRows();
}

// Gets the number of columns in the grid.
int Board::getColumns() const
{
	return ownGrid.getColumns();
}
