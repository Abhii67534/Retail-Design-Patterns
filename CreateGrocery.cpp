#include <iostream>
#include <string>
#include <vector>
#include "Apple.h"
#include "Orange.h"

using namespace std;

GroceryIf *CreateGrocery(int input) {
    GroceryIf *grocery = nullptr;
    string name;
    double cost;
    double calories;

    if (input == 1) { // Apple
        cout << "What is the apple's name? ";
        cin.ignore(); 
        getline(cin, name);
        cout << "How many calories does this apple have? ";
        cin >> calories;
        cout << "How much does this apple cost? $";
        cin >> cost;
        grocery = new Apple(name, cost, calories);
    } else if (input == 2) { // Orange
        cout << "What is the orange's name? ";
        cin.ignore(); // Clear the input buffer
        getline(cin, name);
        cout << "How many calories does this orange have? ";
        cin >> calories;
        cout << "How much does this orange cost? $";
        cin >> cost;
        grocery = new Orange(name, cost, calories);
    }

    return grocery;
}
