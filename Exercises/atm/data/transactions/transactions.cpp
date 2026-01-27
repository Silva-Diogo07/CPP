#include <iostream>
#include <fstream>

#include "transactions.h"

using namespace std;

void guardarMovimento(string nomeCliente, string tipo, double valor)
{
    ofstream file(nomeCliente + "_movimentos.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Erro ao guardar movimento.\n";
        return;
    }

    file << tipo << ";" << valor << endl;

    file.close();
}

void mostrarMovimento(string nomeCliente)
{
    ifstream file(nomeCliente + "_movimentos.txt");

    if (!file.is_open())
    {
        cout << "Sem movimento.\n";
        return;
    }

    string linha;
    while (getline(file, linha)) {
        cout << linha << endl;
    }

    file.close();
}