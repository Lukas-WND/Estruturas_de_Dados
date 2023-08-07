//Nome do programa: registro_vetores.cpp
#include <iostream>
#include <string.h>

#define  TAMCONJ 10
using namespace std;

//definição da estrutura de um registro de conjuntos de um aluno
typedef struct {
    char	  disciplina[40], situacao;
    float  notas[5];
    int	  faltas;
} HistoricoEscolar;

int main(){
    int opcaoMenu, count = 0, id = 0;
    char aluno[50];
    int ano;
    HistoricoEscolar lista[TAMCONJ]; 	//declaração da variável que é um conj. de registros

    setlocale(LC_ALL, "Portuguese");
    system("cls");
    cout << "*********************  Programa: Historico Escolar ***********************";

    //Entrada dos dados da ficha
    fflush(stdin);
    cout << "\nAluno: ";
    gets(aluno);
    //cin >> aluno;
    cout << "\nAno:   ";
    cin >> ano;

    // Menu de opções do sistema
    while(opcaoMenu != 5){
        cout << "\n*********************  Menu de Opcoes ***********************\n";
        cout << "1 - Adicionar um registro\n";
        cout << "2 - Verificar os registros\n";
        cout << "3 - Atualizar um registro\n";
        cout << "4 - Deletar um registro\n";
        cout << "5 - Sair do programa\n\n";
        cin >> opcaoMenu;

        switch(opcaoMenu){
            case 1: { //Adicionar um registro
                system("cls");
                fflush(stdin);

                cout << "-------------------------------------------------------\n";
                cout << "Informe a Disciplina: ";
                gets(lista[count].disciplina); // *inicio.ficha.disciplina

                // São armazenados valores dentro do array notas, dentro da variavel ficha, dentro da estrutura novo;
                cout << "\nInforme a primeira Nota: ";
                cin >> lista[count].notas[0];
                cout << "\nInforme a segunda Nota: ";
                cin >> lista[count].notas[1];
                cout << "\nInforme a terceira Nota: ";
                cin >> lista[count].notas[2];
                cout << "\nInforme a quarta Nota: ";
                cin >> lista[count].notas[3];

                cout << "\nInforme o numero de faltas: ";
                cin >> lista[count].faltas;

                lista[count].notas[4] = (lista[count].notas[0] + lista[count].notas[1] + lista[count].notas[2] + lista[count].notas[3]) / 4;

                // Processamento de dados
                if (lista[count].notas[4] >= 5) {
                    lista[count].situacao = 'A';
                }
                else {
                    lista[count].situacao = 'R';
                }

                count++;
                break;
            }
            case 2: { // Exibir registros
                for(int i = 0; i < count; i++){
                    cout << "\n-------------------------------------------------------\n\n";
                    cout << "ID: " << i << "\n";
                    cout << "Disciplina: " << lista[i].disciplina << "\n";
                    cout << "Nota 1: " << lista[i].notas[0] << " ";
                    cout << "Nota 2: " << lista[i].notas[1] << " ";
                    cout << "Nota 3: " << lista[i].notas[2] << " ";
                    cout << "Nota 4: " << lista[i].notas[3] << "\n";
                    cout << "Faltas: " << lista[i].faltas << "\n";
                    cout << "Situacao: ";

                    if (lista[i].situacao == 'A') {
                        cout << "Aprovado\n";
                    }
                    else {
                        cout << "Reprovado\n";
                    }

                    cout << "\n-------------------------------------------------------\n";
                }
                break;
            }
            case 3: {
                system("cls");
                fflush(stdin);

                cout << "Informe o id do Registro o qual deseja alterar: ";
                cin >> id;

                cout << "Alterando registro de id: " << id << "\n";
                cout << "-------------------------------------------------------\n";
                cout << "Informe a Disciplina: ";
                gets(lista[id].disciplina); // *inicio.ficha.disciplina

                // São armazenados valores dentro do array notas, dentro da variavel ficha, dentro da estrutura novo;
                cout << "\nInforme a primeira Nota: ";
                cin >> lista[id].notas[0];
                cout << "\nInforme a segunda Nota: ";
                cin >> lista[id].notas[1];
                cout << "\nInforme a terceira Nota: ";
                cin >> lista[id].notas[2];
                cout << "\nInforme a quarta Nota: ";
                cin >> lista[id].notas[3];

                cout << "\nInforme o numero de faltas: ";
                cin >> lista[id].faltas;

                lista[id].notas[4] = (lista[id].notas[0] + lista[id].notas[1] + lista[id].notas[2] + lista[id].notas[3]) / 4;

                // Processamento de dados
                if (lista[id].notas[4] >= 5) {
                    lista[id].situacao = 'A';
                }
                else {
                    lista[id].situacao = 'R';
                }

                break;
            }
            case 4: {
                system("cls");
                fflush(stdin);

                cout << "Informe o id do Registro o qual deseja deletar: ";
                cin >> id;

                for(int i = id; i < count; i++){
                    if((i+1) < count){
                        lista[i] = lista[i+1];
                    }
                }

                count--;
                break;
            }
            case 5: {
                cout << "\nAte a proxima!\n";
                break;
            }

            default:
                cout << "\nOpção inválida, tente novamente\n";
        }
    }


    cout << "\n\n";
    system("pause");       //getchar();
    return 0;
}

