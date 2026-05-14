#include <iostream>
#include <cstdlib>
#include "Board.h"
#include "ConsoleView.h"
#include "OwnGrid.h"
#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	Board gameBoard(10, 10);
	ConsoleView consoleView(&gameBoard);

	cout << "Part1 test started" << endl;
	part1tests();
	cout << "Ended" << endl;

	cout << "Part2 test started" << endl;
	part2tests();
	cout << "Ended" << endl;

	cout << "Part3 test started" << endl;
	part3tests();
	cout << "Ended" << endl;

	// Define the ships to be placed on the board.
	vector<Ship> ships =
	{ Ship(GridPosition('F', 2), GridPosition('F', 6)),
	Ship(GridPosition('E', 8), GridPosition('H', 8)),
	Ship(GridPosition('A', 2), GridPosition('A', 5)),
	Ship(GridPosition('H', 2), GridPosition('J', 2)),
	Ship(GridPosition('D', 3), GridPosition('D', 5)),
	Ship(GridPosition('B', 10), GridPosition('D', 10)),
	Ship(GridPosition('B', 8), GridPosition('C', 8)),
	Ship(GridPosition('I', 4), GridPosition('I', 5)),
	Ship(GridPosition('C', 1), GridPosition('D', 1)),
	Ship(GridPosition('F', 10), GridPosition('G', 10))
			};

	// Place the ships on the board.
	for (const auto &ship : ships)
	{
		gameBoard.getOwnGrid().placeShip(ship);
	}

	// Simulate player blows on the own grid.
	gameBoard.getOwnGrid().takeBlow(GridPosition('C', 8));
	gameBoard.getOwnGrid().takeBlow(GridPosition('B', 8));
	gameBoard.getOwnGrid().takeBlow(GridPosition('D', 8));
	gameBoard.getOwnGrid().takeBlow(GridPosition('E', 8));
	gameBoard.getOwnGrid().takeBlow(GridPosition('F', 8));
	gameBoard.getOwnGrid().takeBlow(GridPosition('G', 8));
	gameBoard.getOwnGrid().takeBlow(GridPosition('I', 8));

	// Simulate opponent shots on the opponent's grid.
	gameBoard.getOpponentGrid().shotResult(GridPosition("C1"), HIT);
	gameBoard.getOpponentGrid().shotResult(GridPosition("C2"), HIT);
	gameBoard.getOpponentGrid().shotResult(GridPosition("C3"), SUNKEN);
	gameBoard.getOpponentGrid().shotResult(GridPosition("D1"), NONE);
	gameBoard.getOpponentGrid().shotResult(GridPosition("B5"), HIT);
	gameBoard.getOpponentGrid().shotResult(GridPosition("D5"), HIT);
	consoleView.print();

	return 0;
}
