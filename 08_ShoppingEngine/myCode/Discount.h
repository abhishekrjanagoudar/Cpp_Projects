/*
 * Discount.h
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#ifndef DISCOUNT_H_
#define DISCOUNT_H_

/**
 * Models a discount that is granted when purchasing certain
 * quantities of a product.
 */
class Discount {
public:
	virtual ~Discount();

	/**
	 * Returns the discount for the given quantity.
	 *
	 * @param quantity the quantity that the customer buys
	 * @return the discount, a value in the range [0, 1)
	 */
	virtual float discountFor(float quantity) const = 0;
};

#endif /* DISCOUNT_H_ */
