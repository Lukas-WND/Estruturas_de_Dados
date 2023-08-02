//Nome do programa: lista_registros.cpp
#include <iostream>
#include <windows.h>

#define  TAMCONJ 10
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
    CursorPosition.X = x; // Locates column
    CursorPosition.Y = y; // Locates Row
    SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

//definição da estrutura de um registro de conjuntos de um aluno
typedef struct {
    char	  disciplina[30], situacao;
    float  notas[5];
    int	  faltas;
} HistoricoEscolar;

typedef struct Lista{
    HistoricoEscolar ficha;
    Lista *prox;
} ListaRegistros;

int main(){
    int i;
    char aluno[50];
    int ano, opcaoMenu = 0;
    ListaRegistros *inicio = NULL;
    ListaRegistros *fim = NULL;
    ListaRegistros *aux;
    ListaRegistros *anterior;

    HistoricoEscolar ficha2017[TAMCONJ]; 	//declaração da variável que é um conj. de registros

    setlocale(LC_ALL, "Portuguese");
    system("cls");
    gotoxy(1,5);
    cout << "*********************  Programa: Historico Escolar ***********************";

    //Entrada dos dados da ficha
    fflush(stdin);
    cout << "\nAluno: ";
    gets(aluno);
    //cin >> aluno;
    cout << "\nAno:   ";
    cin >> ano;

    while(opcaoMenu != 5){
        cout << "*********************  Menu de Opções ***********************\n";
        cout << "1 - Adicionar um registro\n";
        cout << "2 - Verificar um registro\n";
        cout << "3 - Atualizar um registro\n";
        cout << "4 - Deletar um registro\n";
        cout << "5 - Sair do programa\n";
        cin >> opcaoMenu;

        switch(opcaoMenu){
            case 1: {
                ListaRegistros *novo = new ListaRegistros();
                fflush(stdin);
                cout << "-------------------------------------------------------\n";
                cout << "Informe a Disciplina: ";
                cin >> novo->ficha.disciplina;

                cout << "\nInforme a primeira Nota: ";
                cin >> novo->ficha.notas[0];
                cout << "\nInforme a segunda Nota: ";
                cin >> novo->ficha.notas[1];
                cout << "\nInforme a terceira Nota: ";
                cin >> novo->ficha.notas[2];
                cout << "\nInforme a quarta Nota: ";
                cin >> novo->ficha.notas[3];

                cout << "\nInforme o numero de faltas: ";
                cin >> novo->ficha.faltas;

                novo->ficha.notas[4] = (novo->ficha.notas[0] + novo->ficha.notas[1] + novo->ficha.notas[2] + novo->ficha.notas[3])/4;

                if(novo->ficha.notas[4] >= 5) {
                    novo->ficha.situacao = 'A';
                }
                else {
                    novo->ficha.situacao = 'R';
                }

                if (inicio == NULL) {
                    inicio = novo;
                    fim = novo;
                    fim->prox = NULL;
                } else {
                    fim->prox = novo;
                    fim = novo;
                    fim->prox = NULL;
                }
                break;
            }
            case 2: {
                if (inicio == NULL) {
                    cout << "A lista está vazia\n";
                } else {
                    aux = inicio;
                    while (aux != NULL) {
                        cout << "\n-------------------------------------------------------\n\n";
                        cout << "Disciplina: " << aux->ficha.disciplina << "\n";
                        cout << "Nota 1: " << aux->ficha.notas[0] << " ";
                        cout << "Nota 2: " << aux->ficha.notas[1] << " ";
                        cout << "Nota 3: " << aux->ficha.notas[2] << " ";
                        cout << "Nota 4: " << aux->ficha.notas[3] << "\n";
                        cout << "Faltas: " << aux->ficha.faltas << "\n";
                        cout << "Situação: ";

                        if(aux->ficha.situacao == 'A') {
                            cout << "Aprovado\n";
                        } else {
                            cout << "Reprovado\n";
                        }
                        cout << "\n-------------------------------------------------------\n";

                        aux = aux->prox;
                    }
                }
                break;
            }

            default:
                cout << "Opção inválida, tente novamente";
        }
    }

    cout << "\n\n";
    system("pause");       //getchar();
    return 0;
}

