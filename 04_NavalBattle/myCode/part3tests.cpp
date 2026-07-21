#include "part3tests.h"

using namespace std;

void part3tests()
{

	Board gameBoard(10, 10);
	//	ConsoleView consoleView(&gameBoard);

	// Section 1: Testing Hits and Sinking on Own Grid
	{
		// Placing a 3-block horizontal ship
		Ship testShip(GridPosition('B', 10), GridPosition('D', 10));
		gameBoard.getOwnGrid().placeShip(testShip);

		// Test: Hitting a valid position
		assertTrue(
				gameBoard.getOwnGrid().takeBlow(GridPosition('C', 10)) == HIT,
				"Error: Expected HIT at GridPosition('C', 10)");

		// Test: Hitting a blank position
		assertTrue(
				gameBoard.getOwnGrid().takeBlow(GridPosition('J', 10)) == NONE,
				"Error: Unexpected HIT at GridPosition('J', 10')");

		// Test: Sinking the ship
		gameBoard.getOwnGrid().takeBlow(GridPosition('D', 10)); // Second hit
		assertTrue(
				gameBoard.getOwnGrid().takeBlow(GridPosition('B', 10))
						== SUNKEN,
				"Error: Ship was not correctly marked as SUNKEN");
	}

	// Section 2: Testing Opponent Grid Shot Results
	{
		auto &opponentGrid = gameBoard.getOpponentGrid();

		// Simulating hits and sinking on opponent's grid
		opponentGrid.shotResult(Shot(GridPosition("C5")), HIT);
		opponentGrid.shotResult(Shot(GridPosition("C7")), HIT);
		opponentGrid.shotResult(Shot(GridPosition("C6")), SUNKEN);

		// Test: Verifying the sunken ship
		Ship expectedSunkenShip(GridPosition("C5"), GridPosition("C7"));
		vector<Ship> sunkenShips = opponentGrid.getSunkenShip();

		if (std::find(sunkenShips.begin(), sunkenShips.end(),
				expectedSunkenShip) == sunkenShips.end())
		{
			cout << "Error: Sunken ship not found in the list of sunken ships"
					<< endl;
		}
	}
	//	consoleView.print();
}
