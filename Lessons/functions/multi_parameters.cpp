#include <iostream>

void myFunction(std::string name, int age)
{
    std::cout << name << " is " << age << " years old\n";
}

int main()
{
    myFunction("Tone", 69);
    myFunction("Bianca", 500);
    myFunction("Carlos", 20);

    return 0;
}