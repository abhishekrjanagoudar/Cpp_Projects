#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>


#include "FixedDiscount.h"
#include "Item.h"
#include "QuantityDiscount.h"
#include "Shop.h"
#include "ShopDb.h"
#include "ShoppingList.h"


using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
  if (!condition) {
    cout << failedMessage << endl;
  }
}

/**
 * Tests for the shopping list classes. (XX points)
 */
void shoppingListTests() {
  /*
   * Create a shopping list with 2 (l) of milk, 250 (g) butter,
   * and 1.5 (kg) bread. Use ShoppingList::items to retrieve
   * the items and assert that for each that they have the
   * expected name and quantity. (12 points)
   */
  ShoppingList list;
  // Populate shopping list with items
  list.addItem("Milk", 2);
  list.addItem("Butter", 250);
  list.addItem("Bread", 1.5);

  std::list<Item>::const_iterator begin;
  std::list<Item>::const_iterator end;
  // Retrieve iterators to access elements in the shopping list
  list.items(begin, end);

  // Verify the first item is 2 units of Milk
  assertTrue(begin->getName() == "Milk", "Milk Name Error");
  assertTrue(begin->getQuantity() == 2, "Milk Quantity Error");
  begin++;
  // Verify the second item is 250 units of Butter
  assertTrue(begin->getName() == "Butter", "Butter Name Error");
  assertTrue(begin->getQuantity() == 250, "Butter Quantity Error");
  begin++;
  // Verify the third item is 1.5 units of Bread
  assertTrue(begin->getName() == "Bread", "Bread Name Error");
  assertTrue(begin->getQuantity() == 1.5, "Bread Quantity Error");
  begin++;
}

/**
 * Tests for the shop db classes. (XX points)
 */
void shopDbTests() {
  /*
   * (1) Test the methods of class ShopDb using the names given below.
   * Proceed as follows:
   *   * Create a ShopDb and add shops with the given names to it.
   *   * Use ShopDb::shops to get pointers to the shops in the database.
   *   * For each shop,
   *       * assert that that the shop's name is in the set "names".
   *       * assert that that the pointer that you got from ShopDb::shops
   *         is equal to the pointer that you get from ShopDb::shopByName
   *       * remove the shop's name from the set "names".
   *   * Finally assert that that you got all shops by checking that the
   *     set "names" is empty.
   *   (7 points)
   */
  set<string> names = {"Foodie1",       "Bakers4less",      "Spiceology",
                       "Grainfruit",    "Sweetteas",        "Savorystyle",
                       "TheSpiceHouse", "FoodieFun",        "FlavorStation",
                       "DoughLife",     "INGredientsOnly",  "FreshFix",
                       "Tastync",       "FlavorFile",       "BiteMe",
                       "TheFlavorSpot", "AtisfyMyCravings", "TastyTreats",
                       "TheFoodFactor", "MunchiesLand",     "TheSnackCave",
                       "FoodieFrenzy",  "TheMorselMansion", "BiteClub",
                       "TheSavorStore", "TheFoodieFactor",  "FlavorfulFinds",
                       "TheTastyTrove"};

  ShopDb db;
  // Create and register each shop from the provided names list
  for (const auto &name : names) {
    db.addShop(make_unique<Shop>(name));
  }

  // Validate that every shop in the database exists in the original names set
  for (Shop *shop : db.shops()) {
    assertTrue(names.find(shop->getName()) != names.end(), "Shop Not Found");
    // Verify shop lookup by name returns the identical object pointer
    assertTrue(db.shopByName(shop->getName()) == shop, "Pointer Mismatch");
    names.erase(shop->getName());
  }

  // Ensure that all names were matched and removed from the set
  assertTrue(names.empty(), "Names not empty");

  /*
   * (2) Test LinearDiscount by creating an instance for 5% (0.05) and
   * another one for 10% (0.1) and then asserting for each of the
   * two that you get the expected result when invoking
   * LinearDiscount::discountFor with arguments 0, 10 and 100. (6 points)
   */
  // Create fixed discounts of 5% and 10%
  FixedDiscount fd5(0.05);
  FixedDiscount fd10(0.10);

  // Verify the 5% discount applies evenly across different quantities
  assertTrue(fd5.discountFor(0) == 0.05, "Fixed Discount 5 failed");
  assertTrue(fd5.discountFor(10) == 0.05, "Fixed Discount 5 failed");
  assertTrue(fd5.discountFor(100) == 0.05, "Fixed Discount 5 failed");

  // Verify the 10% discount applies evenly across different quantities
  assertTrue(fd10.discountFor(0) == 0.10, "Fixed Discount 10 failed");
  assertTrue(fd10.discountFor(10) == 0.10, "Fixed Discount 10 failed");
  assertTrue(fd10.discountFor(100) == 0.10, "Fixed Discount 10 failed");

  /*
   * (3) Test QuantityDiscount by creating an instance for the
   * following rules:
   *   * A discount of 5% (0.05) starting with a quantity of 10
   *   * A discount of 10% (0.1) starting with a quantity of 50
   *   * A discount of 15% (0.15) starting with a quantity of 100
   *
   * Assert that that QuantityDiscount::discountFor returns the expected
   * values for quantities 0, 9, 10, 11, 49, 50, 51, 99, 100 and 101.
   * (8 points)
   */
  // Set up quantity thresholds for increasing discount levels
  QuantityDiscount qd;
  qd.addLimit(10, 0.05);
  qd.addLimit(50, 0.10);
  qd.addLimit(100, 0.15);

  // Verify no discount applied below the first threshold
  assertTrue(qd.discountFor(0) == 0, "Quantity Discount for 0 Failed");
  assertTrue(qd.discountFor(9) == 0, "Quantity Discount for 9 Failed");

  // Verify 5% discount triggers exactly at quantity 10
  assertTrue(qd.discountFor(10) == 0.05, "Quantity Discount for 10 Failed");
  assertTrue(qd.discountFor(11) == 0.05, "Quantity Discount for 11 Failed");
  assertTrue(qd.discountFor(49) == 0.05, "Quantity Discount for 49 Failed");

  // Verify 10% discount triggers exactly at quantity 50
  assertTrue(qd.discountFor(50) == 0.10, "Quantity Discount for 50 Failed");
  assertTrue(qd.discountFor(51) == 0.10, "Quantity Discount for 51 Failed");
  assertTrue(qd.discountFor(99) == 0.10, "Quantity Discount for 99 Failed");

  // Verify 15% discount triggers exactly at quantity 100
  assertTrue(qd.discountFor(100) == 0.15, "Quantity Discount for 100 Failed");
  assertTrue(qd.discountFor(101) == 0.15, "Quantity Discount for 101 Failed");

  /*
   * (4) Create a shop "Bakers4less" that sells bread at
   * 5.6 per unit (kg). Assert that changing the base price
   * (price per unit) for milk (!) at Bakers4less throws an
   * invalid_argument exception (because they don't offer milk)
   * (5 points)
   */
  // Create a test shop and add a single product
  Shop shop("Bakers4less");
  shop.addProduct(Product("Bread", 5.6));

  // Confirm that attempting to set the price for an unstocked item fails safely
  try {
    shop.setBasePrice("Milk", 2);
    assertTrue(false, "invalid_argument expected");
  } catch (invalid_argument &) {
  }
}

// Tests the purchase cost evaluation logic using a varied set of shops and
// complex discount rules.
void evalTests() {
  //(19 points)
  // TODO
  /*
   * Create a shop db. Add the shop "Bakers4less" from the
   * function shopDbTests. Add another shop "Foodie1" that
   * sells "Milk" at 2.1 per unit, "Bread" at 5.8 per unit
   * and "Butter" at 0.00996 per unit.
   */
  ShopDb db;
  db.addShop(make_unique<Shop>("Bakers4less"));
  db.shopByName("Bakers4less")->addProduct(Product("Bread", 5.6));
  db.addShop(make_unique<Shop>("Foodie1"));
  db.shopByName("Foodie1")->addProduct(Product("Milk", 2.1));
  db.shopByName("Foodie1")->addProduct(Product("Bread", 5.8));
  db.shopByName("Foodie1")->addProduct(Product("Butter", 0.00996));

  /*
   * Copy the shopping list from function shoppingListTests.
   */
  ShoppingList list;

  list.addItem("Milk", 2);
  list.addItem("Butter", 250);
  list.addItem("Bread", 1.5);

  /*
   * (1) Assert that purchasing everything from the shopping
   * list at Foodie1 costs 15.39 and that they have everything
   * available.
   */
  set<const Item *> notAvailable;
  float costFoodie =
      db.shopByName("Foodie1")->calculatePurchase(list, notAvailable);
  assertTrue(abs(costFoodie - 15.39) < 0.01, "Foodie Cost Error");

  assertTrue(notAvailable.empty(), "Error: Not Available Item List Not empty");

  /*
   * (2) Assert that the purchase at Bakers4less amounts to
   * 8.40 only and that the method reports that the shop does not
   * provide milk and butter.
   */
  float costBakers =
      db.shopByName("Bakers4less")->calculatePurchase(list, notAvailable);
  assertTrue(abs(costBakers - 8.4) < 0.01, "Bakers Cost Error");
  assertTrue(notAvailable.size() == 2,
             "Error: Not Available List size must be 2");

  bool hasMilk = false;
  bool hasButter = false;
  for (const Item* item : notAvailable) {
    if (item->getName() == "Milk") {
      hasMilk = true;
    } else if (item->getName() == "Butter") {
      hasButter = true;
    }
  }
  assertTrue(hasMilk, "Milk not reported as unavailable");
  assertTrue(hasButter, "Butter not reported as unavailable");
}

// Runs all test cases.
void allTests() {
  shoppingListTests();
  shopDbTests();
  evalTests();
}
