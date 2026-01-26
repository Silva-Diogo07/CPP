#include <iostream>
#include <vector>
#include <limits>

#include "client.h"


using namespace std;

// vetor global de clientes
vector<Cliente> clientes;

// ==============================
// Função para registar um cliente
// ==============================
void registo()
{
    Cliente novo;
    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar buffer
    getline(cin, novo.nome);

    cout << "PIN: ";
    cin >> novo.pin;

    novo.saldo = 0; // saldo inicial
    clientes.push_back(novo);
    cout << "Cliente criado com sucesso!\n";
}

// ==============================
// Função para procurar cliente
// ==============================
int procurarCliente(const vector<Cliente>& clientes, const string& nome)
{
    for (size_t i = 0; i < clientes.size(); ++i)
    {
        if (clientes[i].nome == nome)
            return i;
    }
    return -1; // não encontrado
}

// ==============================
// Funções de levantamento e depósito
// ==============================
void depositar(int indiceCliente)
{
    double valor;
    cout << "Valor a depositar: ";
    cin >> valor;
    if (valor > 0)
    {
        clientes[indiceCliente].saldo += valor;
        cout << "Deposito efetuado com sucesso!\n";
    }
    else
    {
        cout << "Valor invalido!\n";
    }
}

void levantar(int indiceCliente)
{
    double valor;
    cout << "Valor a levantar: ";
    cin >> valor;
    if (valor > 0 && valor <= clientes[indiceCliente].saldo)
    {
        clientes[indiceCliente].saldo -= valor;
        cout << "Levantamento efetuado com sucesso!\n";
    }
    else
    {
        cout << "Saldo insuficiente ou valor invalido!\n";
    }
}

// ==============================
// Menu da conta (após login)
// ==============================
void menuConta(int indiceCliente)
{
    int opcao;
    do
    {
        cout << "\n--- Menu da Conta ---\n";
        cout << "1 - Levantar\n";
        cout << "2 - Depositar\n";
        cout << "3 - Ver saldo\n";
        cout << "4 - Sair da conta\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1: 
                levantar(indiceCliente);
                break;
            case 2:
                depositar(indiceCliente);
                break;
            case 3:
                cout << "Saldo atual: " << clientes[indiceCliente].saldo << endl;
                break;
            case 4:
                cout << "Saindo da conta...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }

    } while(opcao != 4);
}

// ==============================
// Função de login
// ==============================
void login()
{
    string nome;
    int pin;

    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar buffer
    getline(cin, nome);

    int indice = procurarCliente(clientes, nome);

    if (indice == -1)
    {
        cout << "Cliente não encontrado.\n";
        return;
    }

    int tentativas = 3;

    while (tentativas > 0)
    {
        cout << "PIN: ";
        cin >> pin;

        if (pin == clientes[indice].pin)
        {
            cout << "Login efetuado com sucesso!\n";
            menuConta(indice); // chama o menu da conta
            return;
        }
        else
        {
            tentativas--;
            cout << "PIN incorreto. Tentativas restantes: "
                 << tentativas << endl;
        }
    }

    cout << "Conta bloqueada.\n";
}
