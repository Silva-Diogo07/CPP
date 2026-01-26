#include <iostream>
#include <vector>
#include "runners.h"

using namespace std;

int main() {
    vector<Cliente> clientes;
    int opcaoInicial;

    do {
        cout << "\n--- Multibanco ---\n";
        cout << "1 - Criar cliente\n";
        cout << "2 - Entrar\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcaoInicial;
        cin.ignore();

        if (opcaoInicial == 1) {
            Cliente novo;

            cout << "Nome: ";
            getline(cin, novo.nome);

            cout << "PIN: ";
            cin >> novo.pin;
            novo.saldo = 0.0;

            clientes.push_back(novo);
            cout << "Cliente criado com sucesso!\n";
        }

        else if (opcaoInicial == 2) {
            string nome;
            int pin;

            cout << "Nome: ";
            getline(cin, nome);

            int indice = procurarCliente(clientes, nome);

            if (indice == -1) {
                cout << "Cliente nao encontrado.\n";
                continue;
            }

            cout << "PIN: ";
            cin >> pin;

            if (pin != clientes[indice].pin) {
                cout << "PIN incorreto.\n";
                continue;
            }

            // MENU DO CLIENTE
            int opcao;
            do {
                cout << "\n--- Conta de " << clientes[indice].nome << " ---\n";
                cout << "1 - Depositar\n";
                cout << "2 - Levantar\n";
                cout << "3 - Ver saldo\n";
                cout << "4 - Resetar saldo\n";
                cout << "0 - Logout\n";
                cout << "Opcao: ";
                cin >> opcao;

                switch (opcao) {
                    case 1:
                        depositar(clientes[indice]);
                        break;
                    case 2:
                        levantar(clientes[indice]);
                        break;
                    case 3:
                        verSaldo(clientes[indice]);
                        break;
                    case 4:
                        resetSaldo(clientes[indice]);
                        break;
                    case 0:
                        cout << "Logout efetuado.\n";
                        break;
                    default:
                        cout << "Opcao invalida.\n";
                }

            } while (opcao != 0);
        }

    } while (opcaoInicial != 0);

    cout << "Programa terminado.\n";
    return 0;
}

/* TODO: Limitar tentativas de PIN | Evitar valores negativos de depósitios/levantamentos | Guardar clientes em ficheiro | Carregar clientes ao iniciar o programa | Atualizar ficheiro ao sair | Histório de Movimentos | Limprar ecrã entre menus | */
