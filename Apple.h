#include <iostream>
#include <string>//getline
#include <vector>
#include "GroceryIf.h"

using namespace std;


class Apple : public GroceryIf {
	std::string name;
	double cost;
	double calories;
public:
	Apple(std::string name, double cost, double calories) {
		this->name = name;
		this->cost = cost;
		this->calories = calories;
	}
	double GetCost() const override {
		return cost;
	}
	void display() const override {
        cout << name << " is an apple. It has " << calories << " calories and costs $" << cost << "." << endl;
    }
};
