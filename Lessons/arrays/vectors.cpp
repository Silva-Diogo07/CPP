#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> cars = {"Volvo", "BMW", "Ford"};

    cars.push_back("Honda");

    for (string car : cars)
    {
        cout << car << "\t";
    }
}