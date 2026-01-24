#include <iostream>
#include <limits>
#include "runners.h"

using namespace std;

void runAddAluno(vector<Aluno>& alunos)
{
    Aluno a; // cria uma instância de Aluno para guardar os dados.

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // impa o buffer do teclado para evitar que o getline seja ignorado.

    cout << "Nome do aluno: ";
    getline(cin, a.nome);

    do {
        cout << "Nota do aluno (0 a 20): ";
        cin >> a.nota;
    } while (a.nota < 0 || a.nota > 20);

    alunos.push_back(a); // adiciona o aluno ao vetor

    cout << "Aluno adicionado com sucesso!\n";
}

void runListarAlunos(const vector<Aluno>& alunos)
{

    if (alunos.empty()) { // Verifica se o vetor está vazio
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    cout << "\n--- Lista de Alunos ---\n";

    for (int i = 0; i < alunos.size(); i++) { // Percorre todos os alunos
        // Imprime os dados dos alunos
        cout << "Aluno: " << alunos[i].nome         
             << " | Nota: " << alunos[i].nota; 

        // Decide se o aluno está aprovado ou reprovado           
        if (alunos[i].nota >= 10)
            cout << " | Aprovado";
        else
            cout << " | Reprovado";

        cout << endl;
    }
}

void runMedia(const vector<Aluno>& alunos)
{
    // Verifica se há alunos.
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    float soma = 0;

    // Percorre todos e somas as notas
    for (int i = 0; i < alunos.size(); i++) {
        soma += alunos[i].nota; // Calcula a média
    }

    cout << "Media da turma: " << soma / alunos.size() << endl;
}
