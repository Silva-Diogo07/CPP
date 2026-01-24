#ifndef RUNNERS_H
#define RUNNERS_H

#include <string>
#include <vector>

using namespace std;


// Cria um tipo de dado personalizado chamado | Aluno |
// Cada aluno tem nome e nota
struct Aluno {
    string nome;
    float nota;
};

void runAddAluno(vector<Aluno>& alunos); // Recebe um vetor de alunos por referência
void runListarAlunos(const vector<Aluno>& alunos); // Recebe o vetor apenas para leitura (const), não vai alterar.
void runMedia(const vector<Aluno>& alunos); // Também só lê os dados para calcular a média.
void runProcurarAluno(const vector<Aluno>& aluno); 

#endif
