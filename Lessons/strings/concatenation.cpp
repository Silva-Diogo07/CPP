#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstName = "John ";
    string lastName = "Doe";
    string fullName = firstName + lastName;

    cout << fullName << "\n";
    cout << firstName + lastName << "\n";
    cout << firstName.append(lastName) << "\n";

    return 0;
}