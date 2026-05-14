#include <iostream>
#include "ReversiConsoleView.h"

using namespace std;

ReversiConsoleView::ReversiConsoleView(ReversiBoard *reversiBoard)
{
	// Constructor stores the board pointer; it does not own the board.
	this->reversiBoard = reversiBoard;
}

ReversiConsoleView::~ReversiConsoleView()
{
	// Nothing to delete because the board belongs to main().
}

void ReversiConsoleView::print()
{
	// Print a simple coordinate header before the board cells.
	cout << " 0  1  2  3  4  5  6  7 " << endl;

	// Each row is printed from left to right using a single character.
	for (int row = 0; row < 8; row++)
	{
		// A nested loop is the clearest way to walk through the 2D board.
		for (int column = 0; column < 8; column++)
		{
			// The view asks the board for its state instead of reading raw data.
			FieldState fieldState = reversiBoard->getFieldState(column, row);
			if (fieldState == WHITE)
			{
				cout << " O ";
			}
			else if (fieldState == BLACK)
			{
				cout << " X ";
			}
			else
			{
				cout << " + ";
			}

			if (column == 7)
			{
				// Blank line separates rows and keeps the board easy to scan.
				cout << endl << endl;
			}
		}
	}
}
