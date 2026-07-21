/*
 * Shop.h
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#ifndef SHOP_H_
#define SHOP_H_

#include <string>
#include <map>
#include <set>
#include <memory>

#include "Product.h"

class Discount;
class Item;
class ShoppingList;

/**
 * Represents a shop. A shop has a name and products that it offers.
 */
class Shop {
private:
	std::string name;
	std::map<std::string, Product> products;

public:
	/**
	 * Initializes a shop with the given name.
	 *
	 * @param name the name
	 */
	Shop(std::string name);

	/**
	 * Return the shop's name.
	 *
	 * @return the name
	 */
	std::string getName() const;

	/**
	 * Adds a product to the products offered by the shop.
	 * (2 points)
	 *
	 * @param product the product to add
	 * @returns the shop for easy chaining of method invocations
	 */
	Shop& addProduct(const Product& product);

	/**
	 * Changes the base price for a product offered by the shop.
	 * (4 points)
	 *
	 * @param productName the product's name
	 * @param basePrice the new price per unit
	 * @returns the shop for easy chaining of method invocations
	 * @throws invalid_argument if the product is not available at
	 * the shop
	 */
	Shop& setBasePrice(std::string productName, float basePrice);

	/**
	 * Changes the discount for a product offered by the shop.
	 * (4 points)
	 *
	 * @param productName the product's name
	 * @param discount the new discount
	 * @returns the shop for easy chaining of method invocations
	 * @throws invalid_argument if the product is not available at
	 * the shop
	 */
	Shop& setDiscount
		(std::string productName, std::shared_ptr<Discount> discount);

	/**
	 * Calculate the price for a purchase.
	 * (12 points)
	 *
	 * @param shoppingList the items to be bought
	 * @param notAvailable collected items from the shopping list
	 * that are not available at the shop. The set is cleared before
	 * evaluation, i.e. it does not need to be empty when the method
	 * is called.
	 */
	float calculatePurchase(const ShoppingList& shoppingList,
			std::set<const Item*>& notAvailable) const;
};

#endif /* SHOP_H_ */
