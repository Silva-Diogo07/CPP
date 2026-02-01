#include <iostream>

#include "funcs/funcs.h"

using namespace std;

int main()
{
    int option;

    do
    {
        cout << "1 - Ver produtos\n";
        cout << "2 - Adicionar produtos ao carrinho\n";
        cout << "3 - Mostrar carrinho\n";
        cout << "0 - SAIR\n";
        cin >> option;

        switch (option)
        {
            case 1:
                mostrar_produtos();
                break;
            case 2:
                //add_produtos_carrinho();
                break;
            case 3:
                //mostrar_carrinho();
                break;
        }
    }
    while (option != 0);

    return 0;
}