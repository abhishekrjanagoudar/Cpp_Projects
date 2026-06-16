#include "LinearAdjuster.h"

LinearAdjuster::LinearAdjuster(float factor, float offset) {
  this->factor = factor;
  this->offset = offset;
}

float LinearAdjuster::adjust(float value) const {
  return (value * factor) + offset;
}