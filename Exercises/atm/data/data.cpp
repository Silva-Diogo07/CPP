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
    ifstream file("clientes.txt");

    if (!file.is_open())
        return;

    clientes.clear();

    string linha;
    while (getline(file, linha))
    {
        if (linha.empty()) continue; // ignora linhas vazias

        stringstream ss(linha);
        Cliente c;
        string idStr, pinStr, saldoStr;

        // Ler todos os 4 campos: ID;Nome;PIN;Saldo
        getline(ss, idStr, ';');
        getline(ss, c.nome, ';');
        getline(ss, pinStr, ';');
        getline(ss, saldoStr, ';');

        try {
            c.ID = stoi(idStr);
            c.pin = stoi(pinStr);
            c.saldo = stod(saldoStr);
        } catch (const std::invalid_argument&) {
            cerr << "Linha inválida ignorada: " << linha << endl;
            continue; // ignora esta linha
        } catch (const std::out_of_range&) {
            cerr << "Linha com valor fora de alcance ignorada: " << linha << endl;
            continue;
        }

        clientes.push_back(c);

        if (c.ID > ultimoID)
            ultimoID = c.ID; // atualiza último ID
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