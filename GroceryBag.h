// GroceryBag.cpp - full code for the grocery bag. This needs to be broken into the appropriate files

#include <iostream>
#include <string> //getline
#include <vector>
#include "GroceryIf.h"

using namespace std;

const int MAX_GROCERIES = 4;

class GroceryBag
{
	std::string name;
	double totalcost;
	std::vector<GroceryIf *> item;
	int numItems;

public:
	GroceryBag() : name("Default Grocery Bag"), numItems(0), totalcost(0.0) {}

	void displayItemsGroceryBag()
	{
		cout << "Grocery: " << name << endl;
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
			cout << "Total cost: $" << totalcost << endl;
		}
	}

	double getCost()
	{
		return totalcost;
	}

	GroceryBag(std::string name)
	{
		this->name = name;
		numItems = 0;
		totalcost = 0.0;
	}

	bool AddGrocery(GroceryIf &grocery)
	{
		int ret = true;
		if (numItems < MAX_GROCERIES)
		{
			//			item[numItems] = &grocery;
			item.push_back(&grocery);
			++numItems;
			totalcost += grocery.GetCost();
		}
		else
		{
			ret = false;
		}
		return ret;
	}
};

// 	void display(std::ostream& os) {
// 		os.setf(std::ios::fixed);
// 		os.precision(2);
// 		os << std::endl;
// 		os << name << " is a grocery bag with the following items:" << std::endl;
// 		for (int i = 0; i < numItems; ++i) {//one can treat a vector similar to an array
// 			item[i]->display(os);
// 		}
// 		os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
// 	}
// };

// std::ostream& operator<<(std::ostream& os, GroceryBag& grocerybag) {
// 	grocerybag.display(os);
// 	return os;
// }
