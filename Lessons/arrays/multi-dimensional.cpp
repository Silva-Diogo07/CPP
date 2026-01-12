#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<vector<string>> cars; 
    
    cars.push_back({"Volvo", "Bmw", "Ferrari", "Peugeot"});
    cars.push_back({"Honda", "Toyota", "Ford"});

    for (const auto& row : cars)
    {
        for (const auto& car : row)
        {
            cout << car << "\n";
        }
    }

    cars[1][2] = "Jaguar";

    cout << "\n" << cars[1][2] << "\n";
}