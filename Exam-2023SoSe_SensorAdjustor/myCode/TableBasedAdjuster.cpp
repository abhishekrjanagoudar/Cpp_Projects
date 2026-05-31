#include "TableBasedAdjuster.h"

TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y)
{
	breakpoints[x] = y;
	return *this;
}

float TableBasedAdjuster::adjust(float value) const
{
    // Empty map
    if (breakpoints.empty())
    {
        return value;
    }

    // Smallest breakpoint
    auto k_min = breakpoints.begin();

    // Largest breakpoint
    auto k_max = std::prev(breakpoints.end());

    // value <= k_min
    if (value <= k_min->first)
    {
        float v_min = k_min->second;

        return v_min - (k_min->first - value);
    }

    // value >= k_max
    if (value >= k_max->first)
    {
        float v_max = k_max->second;

        return v_max + (value - k_max->first);
    }

    // Adjacent breakpoints
    auto k_n = breakpoints.begin();
    auto k_n1 = std::next(k_n);

    while (k_n1 != breakpoints.end())
    {
        float v_n = k_n->second;
        float v_n1 = k_n1->second;

        // k_n < value <= k_(n+1)
        if (k_n->first < value && value <= k_n1->first)
        {
            return (value - k_n->first)
                    / (k_n1->first - k_n->first)
                    * (v_n1 - v_n)
                    + v_n;
        }

        ++k_n;
        ++k_n1;
    }

    return value;
}
