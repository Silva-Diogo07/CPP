#include <iostream>

#include "funcs.h"

using namespace std;

void limpar_ecra()
{
    system("clear");
}

void mostrar_produtos()
{
    for (const Produto& p : produtos)
    {
        cout << "Produto: " << p.name
             << " | Preço: " << p.price << "£\n";
        
    }

}