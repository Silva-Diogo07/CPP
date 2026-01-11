#include <iostream>
#include <string>
using namespace std;

int main()
{
    string myString = "Hello";

    cout << myString[0] << "\n"; // first character
    
    cout << myString[myString.size() - 1] << "\n"; // last character

    myString[0] = 'J';

    cout << myString << "\n";

    return 0;
}