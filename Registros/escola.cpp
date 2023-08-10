//
// Created by lukas on 10/08/2023.
//
#include <iostream>
using namespace std;

typedef struct Registro {
    char *disciplina, situacao;
    float notas[5];
    int faltas;
} Registro;

typedef struct Historico {
    int *id;
    Registro dadosAluno;
    Historico *proxRegistro;
} Historico;

typedef struct Aluno {
    char *nome;
    int matricula;
    Historico **Registros;
    Aluno *proxAluno;
}Aluno;

int contarNos(int id);

// Métodos menu principal

void exibirAlunos(Aluno *inicioAlunos){
    system("cls");

    if(inicioAlunos == NULL){
        cout << "A lista esta vazia\n";
    }
    else {
        Aluno *alunoAtual;

        while(alunoAtual != NULL){
            cout << "---------------------------------------------------\n";
            cout << "Aluno: " << alunoAtual->nome << "\n";
            cout << "Matricula: " << alunoAtual->matricula << "\n";
            cout << "Quantidade de disciplinas: " << contarNos(alunoAtual->matricula) << "\n";
            cout << "---------------------------------------------------\n";

            alunoAtual = alunoAtual->proxAluno;
        }
    }
}

void adicionarAluno(Aluno **inicioAlunos, Aluno **fimAlunos){
    Aluno *novoAluno = new Aluno();
    system("cls");
    fflush(stdin);

    cout << "---------------------------------------------------\n";
    cout << "Informe o nome do aluno: ";
    cin >> novoAluno->nome;
    cout << "\nInforme a matricula do aluno: ";
    cin >> novoAluno->matricula;

    novoAluno->proxAluno = NULL;

    if(*inicioAlunos == NULL){
        *inicioAlunos = novoAluno;
        *fimAlunos = novoAluno;
    } else {
        (*fimAlunos)->proxAluno = novoAluno;
        *fimAlunos = novoAluno;
    }
}

void atualizarAluno(Aluno **inicioAlunos, Aluno **fimAlunos, Historico **inicioHistorico, Historico **fimHistorico){
    int menuAluno = 0;

    while(menuAluno!= 7){
        cout << "******************************************************************************\n";
        cout << "Bem-vindo ao menu do aluno, por favor, selecione uma opcao: \n";
        cout << "1 - Alterar nome do aluno\n";
        cout << "2 - Alterar matricula do aluno\n";
        cout << "3 - Adicionar um registro\n";
        cout << "4 - Exibir os registros\n";
        cout << "5 - Atualizar um registro\n";
        cout << "6 - Deletar um registro\n";
        cout << "7 - Voltar ao menu principal\n\n";

        fflush(stdin);
        cin >> menuAluno;

        switch(menuAluno){
            case 3: {
                // adicionarRegistro(**inicioHistorico, **fimHistorico);
                break;
            }
            case 4: {
                // exibirRegistros(*inicioHistorico);
                break;
            }
            case 5: {
                // atualizarRegistro(**inicioHistorico);
                break;
            }
            case 6: {
                // deletarRegistro(**inicioHistorico, **fimHistorico);
                break;
            }
            case 7: {
                cout << "\nAte a proxima!\n";
                break;
            }

            default:
                cout << "\nOpção inválida, tente novamente\n";
        }
    }
}

int main(){
    int menuEscola = 0;
    Historico *inicioHistorico, *fimHistorico;
    Aluno *inicioAlunos, *fimAlunos;

    while(menuEscola != 5){
        cout << "******************************************************************************\n";
        cout << "Bem vindo ao menu principal da escola, por favor, selecione uma opcao: \n";
        cout << "1 - Exibir a lista de alunos\n";
        cout << "2 - Adicionar um novo aluno\n";
        cout << "3 - Atualizar dados de um aluno\n";
        cout << "4 - Excluir um aluno\n";
        cout << "5 - Sair do progama\n";

        fflush(stdin);
        cin >> menuEscola;

        switch (menuEscola) {
            case 1: {
                exibirAlunos(inicioAlunos);
                break;
            }
            case 2: {
                adicionarAluno(&inicioAlunos, &fimAlunos);
                break;
            }
            case 3: {
                // atualizarAluno();
                break;
            }
            case 4: {
                // deletarAluno();
                break;
            }
            case 5: {
                cout << "\nAte a proxima!\n";
                break;
            }
            default: {
                system("cls");
                cout << "Opcao invalida, tente novamente!\n";
            }
        }
    }

    system("pause");
    return 0;
}