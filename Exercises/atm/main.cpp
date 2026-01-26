#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "client.h"

using namespace std;

void limparEcra() {
#ifdef _WIN32
    system("cls");   // Windows
#else
    system("clear"); // Linux / macOS
#endif
}


int main()
{
    carregarClientes();

    int opcaoInicial;

    do
    {
        this_thread::sleep_for(std::chrono::seconds(1));   
        limparEcra();
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
