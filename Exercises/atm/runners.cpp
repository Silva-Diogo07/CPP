#include <iostream>
#include "runners.h"

using namespace std;

void depositar(Cliente &c) {
    double valor;
    cout << "Valor a depositar: ";
    cin >> valor;

    // Verifica se o valor é valido
    if (valor > 0) {
        c.saldo += valor; // adiciona ao saldo
        cout << "Deposito efetuado com sucesso.\n";
    } else {
        cout << "Valor invalido.\n";
    }
}

void levantar(Cliente &c)
{
    double valor;

    cout << "Valor a levantar: ";
    cin >> valor;

    // Verifica se o valor é válido e se há saldo suficiente
    if (valor > 0 && valor <= c.saldo)
    {
        c.saldo -= valor; // remove do saldo
        cout << "Levantamento efetuado com sucesso.\n";
    } else {
        cout << "Saldo insuficiente ou valor invalido.\n";
    }
}

void verSaldo(const Cliente &c)
{
    cout << "Saldo atual: " << c.saldo << " €\n";
}

void resetSaldo(Cliente &c) {
    c.saldo = 0.0; // Coloca o saldo a zero
    cout << "Saldo resetado.\n";
}

// Procura um cliente pelo nome
// ================================
int procurarCliente(const vector<Cliente>& clientes, const string& nome) {

    // Percorre o vetor de clientes
    for (int i = 0; i < clientes.size(); i++) {

        // Compara o nome procurado com o nome do cliente
        if (clientes[i].nome == nome) {
            return i;  // Cliente encontrado
        }
    }

    // Se não encontrar, retorna -1
    return -1;
}

