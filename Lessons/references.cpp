#include <iostream>
#include <string>
using namespace std;

int main()
{
    string food = "Pizza";
    string &meal = food;

    meal = "Burger";

    cout << food << "\n";
    cout << meal << "\n";

    return 0;
}