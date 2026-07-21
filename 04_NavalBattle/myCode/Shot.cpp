#include "Shot.h"

// Constructor that initializes a Shot with a target position.
Shot::Shot(GridPosition targetPosition)
{
	this->targetPosition = targetPosition;
}

// Destructor for the Shot class.
Shot::~Shot()
{
}

// Gets the target position of the shot.
GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}
