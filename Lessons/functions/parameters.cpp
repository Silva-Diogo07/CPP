#include <iostream>

void myFunction(std::string fname) {
  std::cout << fname << " Silva\n";
}

int main() {
  myFunction("Michael");
  myFunction("Diogo");
  myFunction("Ana");
  return 0;
}