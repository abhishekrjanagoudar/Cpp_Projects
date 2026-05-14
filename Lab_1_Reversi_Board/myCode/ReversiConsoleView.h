#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

// Console view uses a pointer so it can read the same board object as main.
class ReversiConsoleView
{
private:
	ReversiBoard *reversiBoard;

public:
	ReversiConsoleView(ReversiBoard *reversiBoard);

	~ReversiConsoleView();

	void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */
