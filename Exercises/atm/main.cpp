#include <iostream>
#include <vector>
#include "client.h"

using namespace std;

int main()
{
    carregarClientes();

    int opcaoInicial;

    do {
        cout << "\n--- Multibanco ---\n";
        cout << "1 - Criar cliente\n";
        cout << "2 - Entrar\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcaoInicial;

        if (opcaoInicial == 1)
        {
            registo();    
        }
        else if (opcaoInicial == 2)
        {
            login();
        }
        else if (opcaoInicial == 0)
        {
            cout << "Programa terminado.\n";
        }
        else
        {
            cout << "Opcao invalida.\n";
        }

    } while (opcaoInicial != 0);

    guardarClientes();

    return 0;
}

/* TODO: Histório de Movimentos | Limprar ecrã entre menus | */
