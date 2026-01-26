#include <iostream>
#include <vector>

#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

// Estrutura que representa um cliente
// ================================
struct Cliente {
    string nome;   // Nome do cliente
    int pin;       // PIN do cliente
    double saldo;  // Saldo da conta
};

extern vector<Cliente> clientes;


void registo();
// Procura um cliente pelo nome no vetor
// Retorna o índice do cliente ou -1 se não existir
int procurarCliente(const vector<Cliente>& clientes, const string& nome);
void login();
void carregarClientes();
void guardarClientes();

#endif