#ifndef RUNNERS_H
#define RUNNERS_H

#include <string>
#include <vector>

using namespace std;

// Estrutura que representa um cliente
// ================================
struct Cliente {
    string nome;   // Nome do cliente
    int pin;       // PIN do cliente
    double saldo;  // Saldo da conta
};

// Funções do multibanco
void depositar(Cliente &c);
void levantar(Cliente &c);
void verSaldo(const Cliente &c);
void resetSaldo(Cliente &c);

// Procura um cliente pelo nome no vetor
// Retorna o índice do cliente ou -1 se não existir
int procurarCliente(const vector<Cliente>& clientes, const string& nome);

#endif
