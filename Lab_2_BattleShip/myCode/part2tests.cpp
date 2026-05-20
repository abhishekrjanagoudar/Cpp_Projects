#include "part2tests.h"

using namespace std;

void part2tests()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	Board gameBoard(10, 10);
//	ConsoleView consoleView(&gameBoard);

	// Test 1: Placing a horizontal ship
	// 5-block ship
	{
		Ship horizontalShip(GridPosition('F', 2), GridPosition('F', 6));
		bool result = gameBoard.getOwnGrid().placeShip(horizontalShip);
		assertTrue(result,
				"Error: Horizontal ship was not placed successfully.");
	}

	// Test 2: Placing a vertical ship
	// 4-block ship
	{
		Ship verticalShip(GridPosition('E', 8), GridPosition('H', 8));
		bool result = gameBoard.getOwnGrid().placeShip(verticalShip);
		assertTrue(result, "Error: Vertical ship was not placed successfully.");
	}

	// Test 3: Attempting to place a diagonal ship
	// 4-block ship
	{
		Ship diagonalShip(GridPosition('A', 2), GridPosition('D', 5));
		bool result = gameBoard.getOwnGrid().placeShip(diagonalShip);
		assertTrue(!result, "Error: Diagonal ship was incorrectly placed.");
	}

	// Test 4: Attempting to place a second 5-length ship
	// 5-block ship
	{
		Ship another5BlockShip(GridPosition('J', 2), GridPosition('J', 6));
		bool result = gameBoard.getOwnGrid().placeShip(another5BlockShip);
		assertTrue(!result,
				"Error: Another 5-length ship was incorrectly placed.");
	}

	// Test 5: Placing a ship in the blocked area of another ship
	// 3-block ship
	{
		Ship blockedAreaShip(GridPosition('G', 3), GridPosition('G', 5));
		bool result = gameBoard.getOwnGrid().placeShip(blockedAreaShip);
		assertTrue(!result,
				"Error: Ship was incorrectly placed in a blocked area.");
	}

	// Test 6: Placing a ship at the edges of the grid
	// 2-block ship
	{
		Ship edgeShip(GridPosition('F', 10), GridPosition('G', 10));
		bool result = gameBoard.getOwnGrid().placeShip(edgeShip);
		assertTrue(result,
				"Error: Ship was not placed at the edges of the grid.");
	}
//	consoleView.print();
}
