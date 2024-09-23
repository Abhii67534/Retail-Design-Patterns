#ifndef TOOLIF_H
#define TOOLIF_H

#include <iostream>
#include <string> //getline
#include <vector>

using namespace std;

class ToolIf
{
public:
	virtual double GetCost() const = 0;
	virtual void display() const = 0;
};

#endif