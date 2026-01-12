#include <iostream>
using namespace std;

int main()
{
    string cars[] = {"Volvo", "BMW", "Ford", "Mazda"};

    cout << cars[0] << "\n";

    cars[2] = "Honda";

    cout << cars[2] << "\n";

    for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    {
        cout << i << " = " << cars[i] << "\n";
    }

    return 0;
}