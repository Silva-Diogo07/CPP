#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void limparEcra()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main()
{
    int option;

    do
    {
        this_thread::sleep_for(std::chrono::seconds(1));
        limparEcra();
        cout << "1 - Registar Leitor\n";
        cout << "2 - Emprestar Livro\n";
        cout << "3 - Devolver Livro\n";
        cout << "4 - Listar Leitores\n";
        cout << "5 - Listar Livros\n";
        cout << "0 - Sair\n";
        cout << "Enter: ";
        cin >> option;

        switch (option)
        {
            case 1:
                // registar_leitor();
                cout << 1 << endl;
                break;
            case 2:
                // emprestar_livro();
                cout << 2 << endl;
                break;
            case 3:
                // devolver_livro();
                cout << 3 << endl;
                break;
            case 4:
                // listar_leitores();
                cout << 4 << endl;
                break;
            case 5:
                // listar_livros();
                cout << 5 << endl;
                break;
            case 0:  
                break;
            default:
                cout << "Opção inválida.\n";
        }
        
    } while (option != 0);
    cout << "A sair..." << endl;
    this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Programa terminado!" << endl;

    return 0;
}

// Menu principal
/* Enquanto usuário não escolher sair:
  Mostrar menu:
    1 - Registar leitor
    2 - Emprestar livro
    3 - Devolver livro
    4 - Listar leitores
    5 - Listar livros
    0 - Sair
  Ler opção do usuário
  Se opção = 1:
    Chamar função RegistarLeitor
  Se opção = 2:
    Chamar função EmprestarLivro
  Se opção = 3:
    Chamar função DevolverLivro
  Se opção = 4:
    Chamar função ListarLeitores
  Se opção = 5:
    Chamar função ListarLivros
  Se opção = 0:
    Sair do programa
  Senão:
    Mostrar "Opção inválida"
*/

// Função RegistarLeitor
/*
  Pedir nome do leitor
  Criar novo leitor
    ID = próximo ID disponível
    Nome = nome fornecido
  Adicionar leitor à lista de leitores
  Incrementar próximo ID
  Mostrar mensagem de sucesso
*/

// Função EmprestarLivro
/*Pedir ID do livro
  Pedir ID do leitor
  Procurar livro na lista
    Se livro não existe:
      Mostrar mensagem "Livro não encontrado"
      Terminar função
    Se livro já emprestado:
      Mostrar mensagem "Livro já emprestado"
      Terminar função
    Se leitor não existe:
      Mostrar mensagem "Leitor não encontrado"
      Terminar função
    Senão:
      Marcar livro como emprestado
      Registrar ID do leitor
      Mostrar mensagem "Livro emprestado com sucesso"
*/

// Função DevolverLivro
/*Pedir ID do livro a devolver
  Procurar livro na lista
    Se livro não existe:
      Mostrar mensagem "Livro não encontrado"
      Terminar função
    Se livro não está emprestado:
      Mostrar mensagem "Livro não estava emprestado"
      Terminar função
    Senão:
      Marcar livro como disponível
      Remover ID do leitor
      Mostrar mensagem "Livro devolvido com sucesso"
*/

// Função ListarLeitores
/*Para cada leitor na lista:
    Mostrar ID e Nome do leitor
*/

// Função ListarLivros
/* Para cada livro na lista:
    Mostrar ID e Título
    Se livro está emprestado:
      Mostrar "Emprestado para ID do leitor"
    Senão:
      Mostrar "Disponível"
*/