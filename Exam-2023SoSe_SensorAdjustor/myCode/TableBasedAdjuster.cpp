#include "TableBasedAdjuster.h"

TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y)
{
	breakpoints[x] = y;
	return *this;
}

float TableBasedAdjuster::adjust(float value) const
{
}
