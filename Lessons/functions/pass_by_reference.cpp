#include <iostream>

void swapNums(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int num1 = 10;
    int num2 = 20;

    std::cout << "Before swap: " << "\n";
    std::cout << "x: " << num1 << "\n" << "y: " << num2 << "\n";

    swapNums(num1, num2);

    std::cout << "After swap: " << "\n";
    std::cout << "x: " << num1 << "\n" << "y: " << num2 << "\n";

    return 0;
}