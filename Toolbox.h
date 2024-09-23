
#include <iostream>
#include <string> //getline
#include <vector>
#include "ToolIf.h"
#define MAX_TOOLS 2
using namespace std;

class Toolbox
{
	std::string name;
	double totalCost;
	std::vector<ToolIf *> item;
	int numItems;

public:
	Toolbox() : name("Makita Toolbox"), numItems(0), totalCost(0.0) {}

	void displayItemsToolbox()
	{
		cout << "Toolbox: " << name << endl;
		if (item.empty())
		{
			cout << "No tools in the toolbox." << endl;
		}
		else
		{
			for (int i = 0; i < item.size(); i++)
			{
				item[i]->display();
			}
			cout << "Total cost: $" << totalCost << endl;
		}
	}

	double getCost()
	{
		return totalCost;
	}


	Toolbox(std::string name)
	{
		this->name = name;
		numItems = 0;
		totalCost = 0.0;
	}

	bool AddTool(ToolIf &tool)
	{
		int ret = true;
		if (numItems < MAX_TOOLS)
		{
			//			item[numItems] = &tool;
			item.push_back(&tool);
			++numItems;
			totalCost += tool.GetCost();


		}
		else
		{
			ret = false;
		}
		return ret;
	}
};