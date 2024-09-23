#ifndef CART_H
#define CART_H

#include <vector>
#include "Toolbox.h"
#include "GroceryBag.h"

class Cart
{
    private:
    double totalCost;
public:
    Toolbox toolbox;
    GroceryBag groceries;
    Cart();

    // Method to display the items in the cart (for reporting)
    void displayItems();

    double getTotalCost();
};

#endif // CART_H
