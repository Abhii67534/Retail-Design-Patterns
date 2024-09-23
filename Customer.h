#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Cart.h"

ToolIf *CreateTool(int input);
GroceryIf *CreateGrocery(int input);

class RetailStore;

class Customer
{
private:
    std::string name;
    double cash;
    RetailStore *store;
    Cart cart;

public:
    Customer(std::string name, double cash);
    double getAmount(){
        return cash;
    }
    bool spendCash(double amount);
    void addCash(double amount);
    void fillCart(Cart &cart);
    std::string getName() const;
    void setStore(RetailStore *store);
    Cart& getCart() { return cart; }
};

#endif
