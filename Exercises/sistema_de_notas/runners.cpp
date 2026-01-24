#include <iostream>
#include <limits>
#include "runners.h"

using namespace std;

void runAddAluno(vector<Aluno>& alunos)
{
    Aluno a;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nome do aluno: ";
    getline(cin, a.nome);

    do {
        cout << "Nota do aluno (0 a 20): ";
        cin >> a.nota;
    } while (a.nota < 0 || a.nota > 20);

    alunos.push_back(a);

    cout << "Aluno adicionado com sucesso!\n";
}

void runListarAlunos(const vector<Aluno>& alunos)
{
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    cout << "\n--- Lista de Alunos ---\n";

    for (const Aluno& aluno : alunos) {
        cout << "Aluno " << aluno.nome
             << " | Nota: " << aluno.nota;

        if (aluno.nota >= 10)
            cout << " | Aprovado";
        else
            cout << " | Reprovado";

        cout << endl;
    }
}

void runMedia(const vector<Aluno>& alunos)
{
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    float soma = 0.0f;

    for (const Aluno& aluno : alunos) {
        soma += aluno.nota;
    }

    cout << "Media da turma: " << soma / static_cast<float>(alunos.size()) << endl;
}

void runProcurarAluno(const vector<Aluno>& alunos)
{
    bool encontrado = false;
    string aluno_procurado;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Aluno a procurar: ";
    getline(cin, aluno_procurado);

    for (const Aluno& aluno : alunos) {
        if (aluno.nome == aluno_procurado) {
            cout << "Aluno encontrado: "
                 << aluno.nome
                 << " | Nota: "
                 << aluno.nota
                 << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Aluno nao encontrado.\n";
    }
}
