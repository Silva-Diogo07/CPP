#include <iostream>

int myFunction(int x, int y)
{
    return y + x;
}

int main()
{
    int result = myFunction(7,20);

    std::cout << result << "\n";

    return 0;
}