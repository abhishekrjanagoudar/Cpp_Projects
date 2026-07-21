#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include <vector>

#include "Board.h"

// ConsoleView prints the current board state to the console.
class ConsoleView
{
private:
	Board *board;
	std::vector<std::vector<char>> ownGrid;
	std::vector<std::vector<char>> opponentGrid;

public:
	// Constructor stores the board pointer and prepares the display buffers.
	ConsoleView(Board *board);

	// Destructor is trivial.
	~ConsoleView();

	// Prints the two grids side by side.
	void print();
};

#endif /* CONSOLEVIEW_H_ */
