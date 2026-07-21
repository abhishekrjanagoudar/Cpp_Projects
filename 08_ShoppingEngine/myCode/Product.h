/*
 * Product.h
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
#include <memory>

class Discount;

/**
 * Represents a product offered by a shop. The product has a name and a
 * price. The price is the price per "unit". The precise definition of a
 * "unit" is not important for this exercise. Assume the unit to be
 * something commonly used when shopping, e.g. "litre/liter" for milk,
 * "kg" for bread, "g" for butter and "piece" for a tooth brush.
 * All shops use the same units for similar products.
 */
class Product {
private:
	std::string name;
	float basePrice;
	std::shared_ptr<Discount> discount;

public:
	/**
	 * Initializes a new instance with the given name and price per unit.
	 * The discount is set to NoDisount::instance.
	 *
	 * @param name the product's name
	 * @param basePrice the price per unit
	 */
	Product(std::string name, float basePrice);

	/**
	 * Returns the product's name.
	 *
	 * @return the name
	 */
	std::string getName() const;

	/**
	 * Changes the product's price per unit.
	 *
	 * @param basePrice the new price per unit
	 * @returns the product for easy chaining of method invocations
	 */
	Product& setBasePrice(float basePrice);

	/**
	 * Sets the discount to be applied when calculating the price
	 * for a given quantity of this product.
	 *
	 * @param discount the discount to set
	 * @returns the product for easy chaining of method invocations
	 */
	Product& setDiscount(std::shared_ptr<Discount> discount);

	/**
	 * Calculates the price for a desired quantity of this product,
	 * taking into account the discount. (2 points)
	 *
	 * @param quantity the quantity
	 */
	float priceFor(float quantity) const;
};

#endif /* PRODUCT_H_ */
