#include <iostream>

void myFunction(std::string country = "Portugal")
{
    std::cout << country << "\n" ;
}

int main()
{
    myFunction("Espanha");
    myFunction("Inglaterra");
    myFunction("Alemanha");
    myFunction("Polónia");
    myFunction();

    return 0;
}