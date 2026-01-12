#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct car
    {
        string brand;
        string model;
        int year;
    };

int main()
{
    // Vector para guardar vários carros
    vector<car> cars;

    cars.push_back({"BMW", "M2", 2022});
    cars.push_back({"Ford", "Mustang", 1969});
    cars.push_back({"Honda", "Civic", 2020});
    
    for (const auto& c : cars)
    {
        cout << "Brand: " << c.brand << "\t"
             << "Model: " << c.model << "\t"
             << "Year: " << c.year << "\n";
    }

    return 0;
}