/*
 * NoDiscount.h
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#ifndef NODISCOUNT_H_
#define NODISCOUNT_H_

#include <memory>

#include "Discount.h"

/**
 * Represents a "no discount". This is used when there is no discount
 * granted, no matter how much the customer buys.
 */
class NoDiscount: public Discount {
public:
	/**
	 * An instance used e.g. by the constructor of Product.
	 */
	static std::shared_ptr<Discount> instance;

	/**
	 * Returns 0.
	 *
	 * @param quantity the quantity that the customer buys
	 * @returns 0 (no discount)
	 */
	virtual float discountFor(float quantity) const;
};

#endif /* NODISCOUNT_H_ */
