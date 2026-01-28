#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "transactions.h"

using namespace std;

void guardarMovimento(const string& nomeCliente, const string& tipo, double valor)
{
    ofstream file(nomeCliente + "_movimentos.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Erro ao guardar movimento.\n";
        return;
    }

    // Obter data e hora atuais
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm* tm_ptr = localtime(&t);

    ostringstream oss;
    oss << put_time(tm_ptr, "%Y-%m-%d %H:%M:%S"); // formato: 2026-01-28 15:30:45
    string timestamp = oss.str();

    // Guardar no ficheiro: timestamp;tipo;valor
    file << timestamp << ";" << tipo << ";" << valor << endl;

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