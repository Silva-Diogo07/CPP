#include <iostream>

struct Car
{
    std::string model;
    int year;
};

void myFunction(Car c)
{
    std::cout << "Model: " << c.model << "\n" << "Year: " << c.year << "\n";
}

int main()
{
    Car honda = {"Civic", 2000};
    myFunction(honda);

    return 0;
}