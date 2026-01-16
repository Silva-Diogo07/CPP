#include <iostream>

int plusFunc(int x, int y)
{
    return x + y;
}

int plusFunc(int x, int y, int z)
{
    return x + y + z;
}

int main()
{
    int sum2 = plusFunc(5, 10);
    int sum3 = plusFunc(3, 8, 9);

    std::cout << "Sum of 2 numbers: " << sum2 << "\n";
    std::cout << "Sum of 3 numbers: " << sum3 << "\n";
    
    return 0;
}