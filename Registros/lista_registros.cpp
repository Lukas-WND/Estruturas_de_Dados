//Nome do programa: lista_registros.cpp
#include <iostream>
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){ //Configura a posição do próximo texto a ser exibido do terminal
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

//definição da estrutura de um registro de conjuntos de um aluno
typedef struct {
    char  disciplina[30], situacao;
    float notas[5];
    int	  faltas;
} HistoricoEscolar;

//definição da estrutura de uma lista encadeada contendo uma variável do tipo HistoricoEscolar
typedef struct Lista{
    int id;
    HistoricoEscolar ficha;
    Lista *prox;
} ListaRegistros;

//Método utilizado para realizar a busca do nó correspondente ao ID passado como parâmetro
ListaRegistros *buscaRegistro(ListaRegistros *inicio, int idRegistro){
    if(inicio == NULL){
        cout << "\nA lista esta vazia\n";
        return NULL;
    }
    else {
        ListaRegistros *aux = inicio;

        // loop percorre toda a estrutura da lista até encontrar o id correspondente
        while(aux != NULL){
            if(aux->id == idRegistro){
                return aux; //retornar a referência ao próprio nó, e não uma cópia do mesmo;
            }
            aux = aux->prox;
        }
        cout << "\nID nao encontrado\n";
        return NULL;
    }
}

// Método utilizado para adicionar um novo nó na lista
/* Os ponteiros de início e fim são passados como referência e não como uma cópia do seu valor,
 * assim podemos modifica-lo na própria memória, e não necessariamente trabalhar com sua cópia */
void adicionarRegistro(ListaRegistros **inicio, ListaRegistros **fim) {
    ListaRegistros* novo = new ListaRegistros();
    system("cls");
    fflush(stdin); // limpeza do buffer

    cout << "-------------------------------------------------------\n";
    cout << "Informe a Disciplina: ";
    gets(novo->ficha.disciplina); // *inicio.ficha.disciplina

    // São armazenados valores dentro do array notas, dentro da variavel ficha, dentro da estrutura novo;
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

    novo->ficha.notas[4] = (novo->ficha.notas[0] + novo->ficha.notas[1] + novo->ficha.notas[2] + novo->ficha.notas[3]) / 4;

    // Processamento de dados
    if (novo->ficha.notas[4] >= 5) {
        novo->ficha.situacao = 'A';
    }
    else {
        novo->ficha.situacao = 'R';
    }

    // Verifica se a lista está vazia
    if (*inicio == NULL) {
        *inicio = novo; // O início da lista será o novo nó adicionado nela
        *fim = novo; // Assim como o fim da lista

        // O ponteiro que aponta para o próximo nó está vazio pois o elemento adicionado será o primeiro
        novo->prox = NULL;
        novo->id = 1; // O Id do primeiro nó é definido
    }
    // Se a lista não estiver vazia...
    else {
        ListaRegistros *anterior = *fim; // Um novo ponteiro é declarado apontando para o ponteiro fim
        (*fim)->prox = novo; // O ultimo nó da lista vai apontar para o novo nó
        *fim = novo; // O novo nó agora é o último, a inserção na lista ocorre somente no final
        novo->id = anterior->id + 1; // O id no novo nó é igual ao id do nó anterior mais 1
        novo->prox = NULL; // Como o nó foi inserido no final, ele não irá apontar para nenhum outro
    }
}

// Método utilizado para exibir todos os nós da lista no terminal
void exibirRegistros(ListaRegistros* inicio, char aluno[20], int ano) {
    if (inicio == NULL) { // Verifica se a lista está vazia
        cout << "\nA lista está vazia\n";
    }
    else {
        ListaRegistros* aux = inicio; // Uma variavel auxiliar é declarada para percorrer a lista
        system("cls");
        cout << "Ola " << aluno << ", bem-vindo ao seu historico academico do ano de " << ano << "!\n";
        while (aux != NULL) { // Percorre a estrutura até o último nó
            // Exibe as variáveis de ID, disciplina, notas, faltas, e situação
            cout << "\n-------------------------------------------------------\n\n";
            cout << "ID: " << aux->id << "\n";
            cout << "Disciplina: " << aux->ficha.disciplina << "\n";
            cout << "Nota 1: " << aux->ficha.notas[0] << " ";
            cout << "Nota 2: " << aux->ficha.notas[1] << " ";
            cout << "Nota 3: " << aux->ficha.notas[2] << " ";
            cout << "Nota 4: " << aux->ficha.notas[3] << "\n";
            cout << "Faltas: " << aux->ficha.faltas << "\n";
            cout << "Situacao: ";

            if (aux->ficha.situacao == 'A') {
                cout << "Aprovado\n";
            }
            else {
                cout << "Reprovado\n";
            }

            cout << "\n-------------------------------------------------------\n";

            aux = aux->prox; // Ao final do loop a variável aponta para o próximo nó da lista
        }
    }
}

// Como iremos modificar o conteúdo do nó, não podemos usar a sua cópia, mas sim a sua referência
void atualizarRegistro(ListaRegistros **inicio){
    int idRegistro;

    fflush(stdin);
    cout << "Informe o ID do registro que deseja alterar: ";
    cin >> idRegistro;

    // Essa variável armazena o nó encontado pelo método buscaRegistro
    ListaRegistros *registroEncontrado = buscaRegistro(*inicio, idRegistro);

    if(registroEncontrado == NULL){
        cout << "\nRegistro nao encontrado\n";
    } else {
        //As alterações agora são feitas dentro do nó especificado
        cout << "-------------------------------------------------------\n";
        cout << "Informe a Disciplina: ";
        fflush(stdin);
        gets(registroEncontrado->ficha.disciplina);

        cout << "\nInforme a primeira Nota: ";
        cin >> registroEncontrado->ficha.notas[0];
        cout << "\nInforme a segunda Nota: ";
        cin >> registroEncontrado->ficha.notas[1];
        cout << "\nInforme a terceira Nota: ";
        cin >> registroEncontrado->ficha.notas[2];
        cout << "\nInforme a quarta Nota: ";
        cin >> registroEncontrado->ficha.notas[3];

        cout << "\nInforme o numero de faltas: ";
        cin >> registroEncontrado->ficha.faltas;

        registroEncontrado->ficha.notas[4] = (registroEncontrado->ficha.notas[0] + registroEncontrado->ficha.notas[1] + registroEncontrado->ficha.notas[2] + registroEncontrado->ficha.notas[3]) / 4;

        if (registroEncontrado->ficha.notas[4] >= 5) {
            registroEncontrado->ficha.situacao = 'A';
        }
        else {
            registroEncontrado->ficha.situacao = 'R';
        }
    }
}

// Método utilizado para deletar um nó da lista
// Como precisaremos fazer uma alteração na lista, precisamos da referência dos ponteiros de início e fim
void deletarRegistro(ListaRegistros **inicio, ListaRegistros **fim){
    ListaRegistros *anterior;
    ListaRegistros *registroEncontrado;
    int idRegistro;

    fflush(stdin);
    cout << "\nInforme o numero do Registro a ser deletado: ";
    cin >> idRegistro;

    // Essa variável armazena o nó correspondente ao registro anterior do passado como parâmetro
    anterior = buscaRegistro(*inicio, (idRegistro-1));
    registroEncontrado = buscaRegistro(*inicio, idRegistro);

    if(registroEncontrado == NULL){
        cout << "\nRegistro nao encontrado\n";
    } else {
        if (registroEncontrado == *inicio) { // Verifica se o registro encontrado está no começo da lista
            registroEncontrado->id = 1;
            *inicio = registroEncontrado->prox;
            delete (registroEncontrado);
        } else if (registroEncontrado == *fim) { // Verifica se o registro encontrado está no final da lista
            anterior->prox = NULL;
            *fim = anterior;
            delete (registroEncontrado);
            registroEncontrado = NULL;
        } else { // O registro está no meio da lista
            registroEncontrado->prox->id = anterior->id+1;
            anterior->prox = registroEncontrado->prox;
            delete (registroEncontrado);
        }
    }
}

int main(){
    char aluno[50];
    int ano, opcaoMenu = 0;
    ListaRegistros *inicio = NULL; // Ponteiro indica o primeiro nó da lista
    ListaRegistros *fim = NULL; // Ponteiro indica o último nó da lista

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
            case 1: {
                adicionarRegistro(&inicio, &fim);
                break;
            }
            case 2: {
                exibirRegistros(inicio, aluno, ano);
                break;
            }
            case 3: {
                atualizarRegistro(&inicio);
                break;
            }
            case 4: {
                deletarRegistro(&inicio, &fim);
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