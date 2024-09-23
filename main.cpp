#include <iostream>
#include <vector>
#include <iomanip>
#include "RetailStore.h"

using namespace std;
int main(void)
{
    int input;
    Customer *cus1 = new Customer("Hasan", 100);
    Customer *cus2 = new Customer("Abhishek", 200);
    Customer *cus3 = new Customer("MUBS", 100);

    std::vector<Customer *> vec = {cus1, cus2, cus3};

    RetailStore *store = new RetailStore("FreshCo", vec);

    Cart cart;

    for (Customer *customer : vec)
    {
        customer->setStore(store);
    }

    for (Customer *customer : vec)
    {
        cout << "\n"
             << customer->getName() << " is shopping and has a cash amount of $" << customer->getAmount() << endl;
        customer->fillCart(customer->getCart());
        store->printReport(*customer);
        cout << "---------------------------------------\n"
             << endl;
    }

    cout << store->getName() << " report for all customers:" << endl;
    std::cout << std::fixed << std::setprecision(2);
    cout << "The average spent is: $" << store->average() << endl;
    cout << "The total revenue is $" << store->getTotalCost() << endl;
    cout << "The percentage spent on tools is " << store->toolsPercent() << "%" << endl;
    cout << "The percent spent on groceries is " << store->groceryPercent() << "%" << endl;

    delete cus1;
    delete cus2;
    delete cus3;
    delete store;
}

/* **************************
Question 1->What type of design pattern did you employ (creational, structural, behavioral, custom)? Why?
Answer--> In the Retail Sotre assignment, we used creational design pattern and to be more precise , Factory design pattern.
We can see that the Hammer, Screwdriver , Apple and Orange are derived classes from ToolIf and GroceryIf and we have an interface CreateTools and CreateGrocery which
hides the creation of objects.
Factory Method pattern allows for creating objects without specifying the exact class of the object that will be created, promoting flexibility and code reuse.

Question 2-->What is inversion of control?
Answer 2-->IoC is design concept where a container or framework gains control over a program's object creation and flow instead of the program itself.

Question 3-->The open/close principle states that any class, component or entity should be open for extension but closed for modification. How could one extend a class without modifying the code?
Answer 3-->
Inheritance -- We create new classes from existing ones ,override functions and add new functions.
Interfaces and Abstract Classes-->Build an abstract class that defines the behaviors you wish to extend. Create new classes based on this interface.

Question 4-->How are design patterns different from algorithms?
Answer 4--> Design Patterns are reusable fixes on typical issues in software design. They offer templates that show you how to organize your code in a flexible and manageable way.
An algorithm is a set of instructions or a formula for resolving a certain type of issue, usually one that calls for several steps or calculations. The logic required to carry out 
operations like sorting, searching, and calculating is the main emphasis of algorithms.



*/