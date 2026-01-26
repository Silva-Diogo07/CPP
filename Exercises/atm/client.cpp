#include <iostream>
#include <vector>
#include <limits>

#include <fstream> // Para trabalhar com ficheiros
#include <sstream>
#include "client.h"


using namespace std;

// vetor global de clientes
vector<Cliente> clientes;

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
        file << c.nome << ";"
             << c.pin << ";"
             <<c.saldo << endl;
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
    }

    file.close();
}

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
        guardarMovimento(clientes[indiceCliente].nome, "DEPOSITO", valor);
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
        guardarMovimento(clientes[indiceCliente].nome, "LEVANTAMENTO", valor);

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
        limparEcra();
        cout << "\n--- Menu da Conta ---\n";
        cout << "1 - Levantar\n";
        cout << "2 - Depositar\n";
        cout << "3 - Ver saldo\n";
        cout << "4 - Sair da conta\n";
        cout << "5 - Histórico de transações\n";
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
            case 5:
                mostrarMovimento(clientes[indiceCliente].nome);
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

/* TODO: Melhor organização de ficheiros | Gerar um ID único para cada cliente | Adicionar data e hora nas transações | transferências entre clientes e atualizar saldos e históricos de ambos os clientes| */