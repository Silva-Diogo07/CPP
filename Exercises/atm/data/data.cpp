#include <iostream>
#include <fstream>
#include <sstream>

#include "data.h"

using namespace std;

vector<Cliente> clientes;

int ultimoID = 100100;

void guardarClientes()
{
    ofstream file("clientes.txt");

    if (!file.is_open())
    {
        cout << "Erro ao abrir ficheiro para escrita.\n";
        return;
    }

    /* Percorre todos os clientes , escreve uma linha por cliente */
    for (const Cliente& c : clientes)
    {
        file << c.ID << ";" 
             << c.nome << ";"
             << c.pin << ";"
             << c.saldo << endl;
    }

    file.close();
}

void carregarClientes()
{
    ifstream file("clientes.txt"); // abre o ficheiro 

    if (!file.is_open())
    {
        return;
    }

    clientes.clear();

    // Enquanto houver linhas no ficheiro vai ler uma de cada vez
    string linha;
    while (getline(file, linha))
    {
        stringstream ss(linha);
        Cliente c;
        string pinStr, saldoStr;

        getline(ss, c.nome, ';');
        getline(ss, pinStr, ';');
        getline(ss, saldoStr, ';');

        c.pin = stoi(pinStr); // stoi -> string -> int
        c.saldo = stod(saldoStr); // stod -> string -> double

        clientes.push_back(c); // guarda o cliente na memória

        if (c.ID > ultimoID)
        {
            ultimoID = c.ID;
        }
    }

    file.close();
}

int gerarID()
{
    if (ultimoID >= 99'99'999)
    {
        throw std:: runtime_error("Limite máximo de ID's atingido");
    }
    return ++ultimoID;
}

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