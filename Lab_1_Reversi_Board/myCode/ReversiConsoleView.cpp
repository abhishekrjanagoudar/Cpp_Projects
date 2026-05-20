/* ReversiConsoleView.cpp
 * Simple implementation notes and exam hints added for printing logic.
 * Shows pointer member access and basic I/O with std::cout/std::cin.
 */

#include <iostream>
#include "ReversiConsoleView.h"
#include "ReversiBoard.h"

using namespace std;

// Constructor: store pointer to board (no ownership assumed).
ReversiConsoleView::ReversiConsoleView(ReversiBoard *reversiBoard)
{
	this->reversiBoard = reversiBoard; // pointer assignment
}

// Destructor: nothing to free since this class doesn't `new` the board.
ReversiConsoleView::~ReversiConsoleView()
{
}

// Print board: iterate rows and columns and map enum -> character.
// Syntax/loops note: nested for-loops, if/else branching, and member access
// using pointer `reversiBoard->board[column][row]`.
void ReversiConsoleView::print()
{
	cout << " 0  1  2  3  4  5  6  7 " << endl; // column headers

	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			// Map FieldState to symbol: exam-friendly shorthand
			if (reversiBoard->board[column][row] == WHITE)
			{
				cout << " O "; // WHITE -> O (circle)
			}
			else if (reversiBoard->board[column][row] == BLACK)
			{
				cout << " X "; // BLACK -> X (cross)
			}
			else
			{
				cout << " + "; // BLANK -> + (empty)
			}

			if (column == 7)
				cout << endl << endl; // new line after each row
		}
	}
}
