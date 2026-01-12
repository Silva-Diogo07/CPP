#include <iostream>
using namespace std;

// Sytanx || variable = (condition) = expressionTrue : expressionFalse;

int main()
{
    int age = 18;

    string result = (age >= 18) ? "Adult" : "Not an Adult";
    cout << result << "\n";

    cout << ((age >= 18) ? "Able to vote" : "Not able to vote") << "\n";
}