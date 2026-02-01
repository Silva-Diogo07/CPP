#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <iostream>
#include <vector>

struct Produto
{
    std::string name;
    double price;
};

extern std::vector<Produto> produtos;

#endif
