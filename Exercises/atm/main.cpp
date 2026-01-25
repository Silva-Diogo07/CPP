#include <iostream>
using namespace std;

void verSaldo(double saldo)
{
    cout << "Saldo atual: " << saldo << "£\n";
}

void depositar(double &saldo)
{
    double valor_depósito;
    cout << "Valor a depositar: ";
    cin >> valor_depósito;

    if (valor_depósito > 0)
    {
        saldo += valor_depósito;
        cout << "Depósito concluido com sucesso!\n";
    }
    else
    {
        cout << "Valor inválido.\n";
    }
}

void levantar(double &saldo)
{
    double valor_levantamento;
    cout << "Valor a levantar: ";
    cin >> valor_levantamento;

    if (valor_levantamento > 0 && valor_levantamento <= saldo)
    {
        saldo -= valor_levantamento;
        cout << "Levantamento realizado com sucesso!\n";
    }
    else
    {
        cout << "Saldo insuficiente ou valor inválido.\n";
    }
}

int main()
{
    int opção;
    double saldo = 0.0;

    do
    {
        cout << "\n--- Multibanco ---\n";
        cout << "1 - Depositar dinheiro\n";
        cout << "2 - Sacar dinheiro\n";
        cout << "3 - Consultar Saldo\n";
        cout << "0 - Retirar cartão\n";
        cin >> opção;

        switch (opção)
        {
            case 1:
                depositar(saldo);
                break;
            case 2:
                levantar(saldo);
                break;
            case 3:
                verSaldo(saldo);
                break;
            case 0:
                cout << "A sair...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opção != 0);
    
    return 0;
}

// TODO: Adicionar PIN
// TODO: Ter vários clientes
// TODO: Guardar dados em ficheiro
// TODO: Histórico de movimentos
