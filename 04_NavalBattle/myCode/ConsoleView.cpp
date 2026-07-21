#include "ConsoleView.h"
#include <iostream>
#include <vector>

using namespace std;

// Constructor stores the board and builds the empty display grids.
ConsoleView::ConsoleView(Board *board)
{
	this->board = board;
	ownGrid.resize(board->getRows() + 2,
			std::vector<char>(board->getColumns() + 1, '~'));

	opponentGrid.resize(board->getRows() + 2,
			std::vector<char>(board->getColumns() + 1, '~'));

	ownGrid.at(0) = vector<char>(board->getColumns() + 2, ' ');
	opponentGrid.at(0) = vector<char>(board->getColumns() + 2, ' ');

	// Fill the top header row.
	for (int colNo = 0; colNo <= board->getColumns(); colNo++)
	{
		if (colNo < 10)
		{
			ownGrid.at(0).at(colNo) = ' ';
			opponentGrid.at(0).at(colNo) = ' ';
		}
		else
		{
			ownGrid.at(0).at(colNo) = (colNo / 10) + '0';
			opponentGrid.at(0).at(colNo) = (colNo / 10) + '0';
		}
	}

	// Fill the second header row.
	for (int colNo = 0; colNo <= board->getColumns(); colNo++)
	{
		if (colNo == 0)
		{
			ownGrid.at(1).at(colNo) = ' ';
			opponentGrid.at(1).at(colNo) = ' ';
		}
		else
		{
			ownGrid.at(1).at(colNo) = (colNo % 10) + '0';
			opponentGrid.at(1).at(colNo) = (colNo % 10) + '0';
		}
	}

	// Fill the row labels.
	for (char c = 'A'; c < 'A' + board->getRows(); c++)
	{
		ownGrid.at(c - 'A' + 2).at(0) = c;
		opponentGrid.at(c - 'A' + 2).at(0) = c;
	}
}

// Destructor is trivial.
ConsoleView::~ConsoleView()
{
}

// Prints the current state of the grids to the console.
void ConsoleView::print()
{
	auto ownDisplay = ownGrid;
	auto opponentDisplay = opponentGrid;

	// Populate ownGrid with ship positions.
	for (const Ship &ship : board->getOwnGrid().getShips())
	{
		for (const GridPosition &pos : ship.occupiedArea())
		{
			ownDisplay[pos.getRow() - 'A' + 2][pos.getColumn()] = '#';
		}
	}

	// Mark hits and misses on the own grid.
	for (const GridPosition &shotPosi : board->getOwnGrid().getShotAt())
	{
		bool hitShip = false;
		for (const Ship &ship : board->getOwnGrid().getShips())
		{
			if (ship.occupiedArea().count(shotPosi) > 0)
			{
				hitShip = true;
				break;
			}
		}
		if (hitShip)
		{
			ownDisplay[shotPosi.getRow() - 'A' + 2][shotPosi.getColumn()] = 'O';
		}
		else
		{
			ownDisplay[shotPosi.getRow() - 'A' + 2][shotPosi.getColumn()] = '^';
		}
	}

	// Mark shots on the opponent grid.
	for (const auto &shot : board->getOpponentGrid().getShotsAt())
	{
		if (shot.second == HIT || shot.second == SUNKEN)
		{
			opponentDisplay.at((shot.first.getRow()) - 'A' + 2).at(
					shot.first.getColumn()) = 'O';
		}
		else
		{
			opponentDisplay.at((shot.first.getRow()) - 'A' + 2).at(
					shot.first.getColumn()) = '^';
		}
	}

	// Print the two grids side by side.
	for (int row = 0; row < board->getOwnGrid().getRows() + 2; row++)
	{
		for (int col = 0; col < board->getOwnGrid().getColumns() + 1; col++)
		{
			cout << ownDisplay[row][col] << " ";
		}

		cout << "  ";

		for (int col = 0; col < board->getOwnGrid().getColumns() + 1; col++)
		{
			cout << opponentDisplay[row][col] << " ";
		}
		cout << endl;
	}
}
