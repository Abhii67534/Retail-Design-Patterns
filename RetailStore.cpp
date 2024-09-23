#include "RetailStore.h"

RetailStore::RetailStore(std::string name, std::vector<Customer *> myvec)
    : name(name), customers(myvec)
{
}

void RetailStore::printReport(Customer &customer)
{
    std::cout << "--------" << std::endl;
    std::cout << "Report for customer: \n"
              << customer.getName() << std::endl;
    std::cout << "You have cash amount of: $" << customer.getAmount() << endl;
    cout << endl;
    customer.getCart().displayItems();

    double totalCost = customer.getCart().toolbox.getCost() + customer.getCart().groceries.getCost();
    double tax = totalCost * 0.13;
    totalCost += tax;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Purchase Cost(Tools+Groceries) including GST: $" << totalCost << std::endl;
}

double RetailStore::average()
{
    double total = 0.0;
    int count = customers.size();

    for (int i = 0; i < customers.size(); i++)
    {
        total += customers[i]->getCart().getTotalCost();
    }

    return count > 0 ? total / count : 0;
}

double RetailStore::getTotalCost()
{
    for (int i = 0; i < customers.size(); i++)
    {
        revenue += customers[i]->getCart().getTotalCost();
    }
    return revenue;
}

double RetailStore::toolsPercent()
{
    double amount = 0;
    for (int i = 0; i < customers.size(); i++)
    {
        amount += customers[i]->getCart().toolbox.getCost();
    }

    if (getTotalCost() != 0)
    {
        double percent = (amount / getTotalCost()) * 100;
        return percent;
    }

    return 0.0;
}

double RetailStore::groceryPercent()
{
    double amount = 0;
    for (int i = 0; i < customers.size(); i++)
    {
        amount += customers[i]->getCart().groceries.getCost();
    }

    if (getTotalCost() != 0)
    {
        double percent = (amount / getTotalCost()) * 100;
        return percent;
    }

    return 0.0;
}
