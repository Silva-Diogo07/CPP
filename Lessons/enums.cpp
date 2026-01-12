#include <iostream>
#include <string>

using namespace std;

enum Level
{
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75
};

int main()
{
    Level variable = MEDIUM;

    switch (variable)
    {
        case 25:
            cout << "Low Level\n";
            break;
        
        case 50:
            cout << "Medium Level\n";
            break;

        case 75:
            cout << "High Level\n";
            break;
    }

    return 0;
}