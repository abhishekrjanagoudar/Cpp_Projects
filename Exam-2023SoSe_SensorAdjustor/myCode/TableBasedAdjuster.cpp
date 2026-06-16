#include "TableBasedAdjuster.h"
#include <iterator>

TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y)
{
	// Store or update the mapping for a given input threshold
	breakpoints[x] = y;
	return *this;
}

float TableBasedAdjuster::adjust(float value) const
{
	// Return value unchanged if no adjustment rules exist
	if(breakpoints.empty()){
		return value;
	}
	
	// Identify boundaries of defined breakpoints
	auto k_min = breakpoints.begin();
	auto k_max = --breakpoints.end();

	// Extrapolate below the lowest defined breakpoint
	if(value <= k_min->first){
		float v_min = k_min->second;
		return v_min - (k_min->first - value);
	}

	// Extrapolate above the highest defined breakpoint
	if(value >= k_max->first){
		float v_max = k_max->second;
		return v_max + (value - k_max->first);
	}

	// Iterate to find surrounding breakpoints for interpolation
	auto k_n = breakpoints.begin();
	auto k_n1 = std::next(k_n);

	while(k_n1 != breakpoints.end()){
		if(k_n->first < value && value <= k_n1->first){
			float v_n = k_n->second;
			float v_n1 = k_n1->second;
			// Linearly interpolate between the two matching breakpoints
			return (value - k_n->first) / (k_n1->first - k_n->first) * (v_n1 - v_n) + v_n;
		}
		k_n++;
		k_n1++;
	}
	return value;
}