#include <iostream>

int main()
{
    auto message = []()
    {
        std::cout << "Hello World" << "\n";
    };

    message();

    auto add = [](int x, int y)
    {
        return x + y;
    };

    std::cout << add(11, 24) << "\n";

    int x = 10;

    auto show = [x]()
    {
        std::cout << x << "\n";
    };

    show();

    return 0;
}