/*
 * LinearDiscount.h
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#ifndef FIXEDDISCOUNT_H_
#define FIXEDDISCOUNT_H_

#include "Discount.h"

/**
 * Represents a fixed discount. This is simply a value in the range
 * [0, 1), i.e. the discount is effectively independent of the
 * quantity.
 */
class FixedDiscount: public Discount {
private:
	float discount;

public:
	/**
	 * Initializes a new fixed discount with the given value.
	 *
	 * @param discount the discount
	 */
	FixedDiscount(float discount);

	/**
	 * Returns the fixed discount.
	 *
	 * @param quantity the quantity that the customer buys
	 * @return the discount (the value passed to the constructor)
	 */
	virtual float discountFor(float quantity) const;
};

#endif /* FIXEDDISCOUNT_H_ */
