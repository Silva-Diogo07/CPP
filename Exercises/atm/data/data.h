#pragma once

#include <iostream>
#include <vector>

#ifndef DATA_H
#define DATA_H

using namespace std;

struct Cliente
{
    int ID;
    string nome;
    int pin;
    double saldo;
};

extern vector<Cliente> clientes;

void carregarClientes();
void guardarClientes();
int procurarCliente(const vector<Cliente>& clientes, const string& nome);
int gerarID();

#endif