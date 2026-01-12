#include <iostream>
using namespace std;

// Sytanx || for (type variableName : arrayName) {}

int main()
{
    int numbers[] = {10, 30, 50, 70 , 80};

    for (int num : numbers)
    {
        cout << num << "\n";
    }

    string pizza = "Pizza";

    for (char c : pizza)
    {
        cout << "\n" << c << "\n";
    }

    string words[] = {"Banana", "Apple", "Pizza", "Coconut"};

    for (string word : words)
    {
        cout << "\n" << word << "\n";
    }

    for (string word : words)
    {
        cout << "\n" << word << "\n";

        for (char c : word)
        {
            cout << "\n" << c << "\n";
        }
    }


    return 0;
}