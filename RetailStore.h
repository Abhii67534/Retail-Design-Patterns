#include <iostream>
#include <string>//getline
#include <vector>
#include <iomanip>
#include "Customer.h"

using namespace std;
class RetailStore{
    string name;
    std::vector<Customer*> customers;
    double revenue;

    public:

    string getName(){return name;}
    RetailStore(string name,std::vector<Customer*> myvec);
    void printReport(Customer &customer);
    double average();
    double getTotalCost();
    double toolsPercent();
    double groceryPercent();


};