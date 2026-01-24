#include <iostream>
#include <vector>
#include "runners.h"

using namespace std;

int main()
{
    vector<Aluno> alunos;
    int opcao;

    do
    {
        cout << "\n--- Sistema de Notas ---\n";
        cout << "1 - Adicionar aluno\n";
        cout << "2 - Listar alunos\n";
        cout << "3 - Calcular media\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                runAddAluno(alunos);
                break;
            case 2:
                runListarAlunos(alunos);
                break;
            case 3:
                runMedia(alunos);
                break;
        }

    } while (opcao != 0);

    return 0;
}

// TODO: Procurar aluno pelo nome
