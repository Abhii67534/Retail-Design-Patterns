#include <iostream>
#include <string>
#include <limits>
#include "Hammer.h"
#include "Screwdriver.h"

using namespace std;

ToolIf *CreateTool(int input)
{
    ToolIf *tool = nullptr;
    string name;
    double cost;
    if (input == 1)
    {
        cout << "What is the hammer's name? ";
        cin.ignore(); 
        getline(cin, name);
        cout << "How much does this hammer cost? $";
        cin >> cost;
        
        tool = new Hammer(name, cost);
    }

    else if (input ==2){
          cout << "What is the screwdriver's name? ";
        cin.ignore(); 
        getline(cin, name);
            cout << "How much does this screwdriver cost? $";
            cin >> cost;

            tool = new Screwdriver(name, cost);
    }

    return tool;

}