#include "Customer.h"

Customer::Customer(std::string name, double cash) : name(name), cash(cash)
{
    // Initialize any other members if needed
}

void Customer::fillCart(Cart &cart)
{
    int input;
    bool retVal;
    double tax;
    double amount;

    while (true)
    { // Loop until user chooses to exit
        cout << "What do you want to buy? Press 1 for Tools, 2 for Grocery, or 0 to exit purchasing." << endl;
        cin >> input;

        if (input == 0)
        {
            cout << "Exiting the purchasing process." << endl;
            return; // Exit the function
        }

        if (input != 1 && input != 2)
        {
            cout << "Invalid selection, please try again." << endl;
            continue; // Prompt again
        }

        int subinput;

        if (input == 1)
        { // Tools section
            ToolIf *tool = nullptr;

            do
            {
                cout << "Enter 1 for Hammer \nEnter 2 for Screwdriver" << endl;
                cout << "Selection:";
                cin >> subinput;

                if (subinput == 0)
                {
                    cout << "Exiting the purchasing process." << endl;
                    return; // Exit the function
                }

                if (subinput == 1)
                {
                    tool = CreateTool(1);
                }
                else if (subinput == 2)
                {
                    tool = CreateTool(2);
                }
                else
                {
                    cout << "Invalid tool selection, please try again." << endl;
                }

            } while (subinput != 1 && subinput != 2);

            if (tool)
            {
                tax = tool->GetCost() * 0.13;
                amount = tool->GetCost() + tax;
                bool ret = spendCash(amount);
                if (!ret)
                {
                    cout << "Not enough cash" << endl;
                    return;
                }
                retVal = cart.toolbox.AddTool(*tool);
                if (retVal)
                {
                    cout << "Tool added to cart" << endl;
                }
                else
                {
                    cout << "Failed to add tool to cart";
                }
            }

            if (tool == nullptr)
            {
                cout << "NULLLLL";
            }
        }
        else if (input == 2)
        { // Grocery section
            GroceryIf *grocery = nullptr;

            do
            {
                cout << "Enter 1 for Apple \nEnter 2 for Orange (Press 0 to exit purchasing)" << endl;
                cout << "Selection:";
                cin >> subinput;

                if (subinput == 0)
                {
                    cout << "Exiting the purchasing process." << endl;
                    return; // Exit the function
                }

                if (subinput == 1)
                {
                    grocery = CreateGrocery(1);
                }
                else if (subinput == 2)
                {
                    grocery = CreateGrocery(2);
                }
                else
                {
                    cout << "Invalid grocery selection, please try again." << endl;
                }

            } while (subinput != 1 && subinput != 2);

            if (grocery)
            {
                tax = grocery->GetCost() * 0.13;
                amount = grocery->GetCost() + tax;
                bool ret = spendCash(amount);
                if (!ret)
                {
                    cout << "Not enough cash" << endl;
                    delete grocery; // Clean up if not added
                    continue;       // Prompt again for purchasing
                }
                retVal = cart.groceries.AddGrocery(*grocery);
                if (retVal)
                {
                    cout << "Grocery added to cart" << endl;
                }
                else
                {
                    cout << "Failed to add Grocery to Cart" << endl;
                }
            }
        }
    }
}

std::string Customer::getName() const
{
    return name;
}

void Customer::setStore(RetailStore *store)
{
    this->store = store;
}

bool Customer::spendCash(double amount)
{
    if (amount <= cash)
    {
        cash -= amount;
        return true; // Successfully spent cash
    }
    return false; // Not enough cash
}

void Customer::addCash(double amount)
{
    cash += amount;
}
