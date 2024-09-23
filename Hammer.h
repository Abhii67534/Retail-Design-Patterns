#include <iostream>
#include <string>//getline
#include <vector>
#include "ToolIf.h"

using namespace std;

class Hammer : public ToolIf {
	std::string name;
	double cost;
public:
	Hammer(std::string name, double cost) {
		this->name = name;
		this->cost = cost;
	}
	double GetCost() const override{
		return cost;
	}
    void display() const override {
        cout << name << " is a hammer and costs $" << cost << "." << endl;
    }
};