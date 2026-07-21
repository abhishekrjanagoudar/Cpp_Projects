#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

// Impact describes what happened at a target position.
enum Impact
{
    NONE,
    HIT,
    SUNKEN
};

// Shot stores the target position.
class Shot
{
private:
    GridPosition targetPosition;

public:
	// Constructor from a target position.
    Shot(GridPosition targetPosition);

	// Destructor is trivial.
    ~Shot();

	// Returns the stored target position.
    GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */
