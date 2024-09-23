#include <iostream>
#include <string>//getline
#include <vector>
#include "ToolIf.h"

using namespace std;
class Screwdriver : public ToolIf {
	std::string name;
	double cost;
public:
	Screwdriver(std::string name, double cost) {
		this->name = name;
		this->cost = cost;
	}
	double GetCost() const override{
		return cost;
	}
	void display() const override {
        cout << name << " is a screwdriver and costs $" << cost << "." << endl;
    }
};
