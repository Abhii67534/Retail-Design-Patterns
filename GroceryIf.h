#ifndef GROCERYIF_H
#define GROCERYIF_H

#include <iostream>
#include <string>//getline
#include <vector>


using namespace std;

class GroceryIf {
public:
	virtual double GetCost() const = 0;
	virtual void display() const = 0;
	virtual ~GroceryIf() {}
};

#endif