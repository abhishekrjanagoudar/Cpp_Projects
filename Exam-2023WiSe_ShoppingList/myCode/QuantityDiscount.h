/*
 * QuantityDiscount.h
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#ifndef QUANTITYDISCOUNT_H_
#define QUANTITYDISCOUNT_H_

#include <map>

#include "Discount.h"

/**
 * Models a discount depending on the quantity that you buy. E.g.
 * "discount 0.05 (5%) for 10 or more", "discount 0.1 (10%) for 20 or more".
 */
class QuantityDiscount: public Discount {
private:
	std::map<float,float> limits;
public:
	/**
	 * Adds a new limit for a quantity and an associated discount.
	 * (2 points)
	 *
	 * @param quantity the quantity
	 * @param discount the discount to apply
	 */
	QuantityDiscount& addLimit(float quantity, float discount);

	/**
	 * Evaluates the discount for the given (requested) quantity.
	 * The discount is 0 if the requested quantity is smaller than
	 * the quantity of the limit with the smallest quantity (see
	 * method addLimit). Else the discount is used from the limit
	 * with the largest quantity that is smaller or equal to
	 * the requested quantity.
	 * (4 points)
	 *
	 * @param quantity the quantity that the customer buys (requests)
	 * @return the discount, a value in the range [0, 1)
	 */
	virtual float discountFor(float quantity) const;
};

#endif /* QUANTITYDISCOUNT_H_ */
