#include <iostream>
#include <string>//getline
#include <vector>
#include "GroceryIf.h"

using namespace std;


class Orange : public GroceryIf {
	std::string name;
	double cost;
	double calories;
public:
	Orange(std::string name, double cost, double calories) {
		this->name = name;
		this->cost = cost;
		this->calories = calories;
	}
	double GetCost() const override {
		return cost;
	}
	void display() const override {
        cout << name << " is an Orange. It has " << calories << " calories and costs $" << cost << "." << endl;
    }
};