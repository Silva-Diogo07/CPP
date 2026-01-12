#include <iostream>
using namespace std;

int main()
{
    bool isCodingFun = true;
    bool isFishTasty = false;

    cout << boolalpha; // enable printing "true"/"false"
    cout << isCodingFun << "\n";

    cout << noboolalpha; // reset to 1/0
    cout << isFishTasty << "\n";

    return 0;
}