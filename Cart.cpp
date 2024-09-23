#include "Cart.h"

Cart::Cart() : totalCost(0.0) {

}

void Cart::displayItems() 
{
   toolbox.displayItemsToolbox();
   groceries.displayItemsGroceryBag();

}

double Cart::getTotalCost() {
    totalCost = toolbox.getCost() + groceries.getCost(); // Ensure `getTotalCost` for groceries is implemented
    return totalCost;
}

