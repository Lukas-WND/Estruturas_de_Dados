#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

typedef struct ListaNotas
{
  float nota;                   /* valor da nota */
  struct ListaNotas *prox_nota; /* ponteiro para próxima nota */
} ListaNotas;

typedef struct Aluno
{
  int matricula;
  string nome;
  ListaNotas *notas_inicio, *notas_fim;
} Aluno;

typedef struct ListaAlunos
{
  Aluno aluno;
  ListaAlunos *prox_aluno;
} ListaAlunos;

ListaAlunos *buscarAluno(ListaAlunos *inicio, int matricula)
{
  ListaAlunos *aux = inicio;
  while (aux != NULL)
  {
    if (aux->aluno.matricula == matricula)
    {
      return aux;
    }
    else
    {
      aux = aux->prox_aluno;
    }
  }

  return NULL;
}

void adicionarAluno(ListaAlunos **inicio, ListaAlunos **fim, int *incMatricula)
{
  system("cls");
  cout << "Cadastro de aluno\n\n";

  ListaAlunos *novoAluno = new ListaAlunos();
  novoAluno->aluno.matricula = (2023 * 100) + *incMatricula;
  cout << "Informe o nome do aluno: ";
  cin >> novoAluno->aluno.nome;
  novoAluno->aluno.notas_inicio = NULL;
  novoAluno->aluno.notas_fim = NULL;

  if (*inicio == NULL)
  {
    (*inicio) = novoAluno;
    (*fim) = novoAluno;
    novoAluno->prox_aluno = NULL;
  }
  else
  {
    (*fim)->prox_aluno = novoAluno;
    (*fim) = novoAluno;
    novoAluno->prox_aluno = NULL;
  }

  (*incMatricula)++;

  system("cls");
  cout << "Aluno cadastrado!" << endl;
  cout << "Retornando ao menu principal!\n\n";
}

void exibirAlunos(ListaAlunos *inicio)
{
  ListaAlunos *aux = inicio;

  system("cls");

  if (aux == NULL)
  {
    system("cls");
    cout << "Nenhum aluno cadastrado!\n\n";
  }
  else
  {
    cout << "Lista de alunos:\n\n";

    while (aux != NULL)
    {
      cout << "Nome: " << aux->aluno.nome << " || Matricula: " << aux->aluno.matricula << endl;
      aux = aux->prox_aluno;
    }

    cout << endl;
  }

  system("pause");
  system("cls");
  cout << "Retornando ao menu principal!\n\n";
}

void adicionarNota(ListaAlunos **inicio)
{
  system("cls");
  ListaAlunos *aluno;
  int matricula = 0;
  cout << "Adicionar notas\n\n";
  cout << "Informe a matricula do aluno: ";
  cin >> matricula;
  cin.ignore();

  aluno = buscarAluno(*inicio, matricula);

  if (aluno == NULL)
  {
    system("cls");
    cout << "Aluno nao encontrado!\n\n";
  }
  else
  {
    cout << "Para parar de adicionar notas, basta digitar um numero menor que 0!\n\n";

    while (1)
    {
      ListaNotas *novaNota = new ListaNotas();
      cout << "Informe a nota do aluno " << aluno->aluno.nome << ": ";
      cin >> novaNota->nota;

      if (novaNota->nota < 0)
      {
        break;
      }

      if (aluno->aluno.notas_inicio == NULL)
      {
        aluno->aluno.notas_inicio = novaNota;
        aluno->aluno.notas_fim = novaNota;
        novaNota->prox_nota = NULL;
      }
      else
      {
        aluno->aluno.notas_fim->prox_nota = novaNota;
        aluno->aluno.notas_fim = aluno->aluno.notas_fim->prox_nota;
        novaNota->prox_nota = NULL;
      }
    }
  }
  system("cls");
  cout << "Retornando ao menu principal!\n\n";
}

void exibirNotas(ListaAlunos *inicio)
{
  ListaAlunos *alunoEncontrado;
  int matricula = 0;

  system("cls");

  cout << "Informe a matricula do aluno: ";
  cin >> matricula;

  alunoEncontrado = buscarAluno(inicio, matricula);

  if (alunoEncontrado == NULL)
  {
    system("cls");
    cout << "Aluno nao encontrado!\n\n";
  }
  else
  {
    ListaNotas *nota;

    nota = alunoEncontrado->aluno.notas_inicio;

    if (nota == NULL)
    {
      system("cls");
      cout << "Aluno " << alunoEncontrado->aluno.nome << " nao possui notas cadastradas\n\n";
    }
    else
    {
      int numNota = 1;
      float countMedia = 0, resultado = 0;
      cout << "\nExibindo as notas do aluno: " << alunoEncontrado->aluno.nome << endl;

      while (nota != NULL)
      {
        cout << "Nota " << numNota << ": " << nota->nota << endl;
        countMedia += nota->nota;
        nota = nota->prox_nota;
        numNota++;
      }
      resultado = countMedia / (numNota - 1);
      cout << "\nMedia: " << resultado << "\n\n";
    }
  }
  system("pause");
  system("cls");
  cout << "Retornando ao menu principal!\n\n";
}

int main()
{
  int menu = 0, incMatricula = 1;
  ListaAlunos *inicio = NULL;
  ListaAlunos *fim = NULL;

  cout << "PROGRAMA PARA GUARDAR NOTAS EM UMA LISTA SIMPLESMENTE ENCADEADA\n\n";

  while (menu != 5)
  {
    cout << "Menu principal" << endl;
    cout << "Selecione uma das opcoes a seguir: " << endl;
    cout << "1 - Cadastrar um aluno" << endl;
    cout << "2 - Exibir lista de alunos" << endl;
    cout << "3 - Adicionar nota a um aluno" << endl;
    cout << "4 - Verificar as notas de um aluno" << endl;
    cout << "5 - Sair\n\n";
    cout << "Informe a opcao: ";
    cin >> menu;
    cin.ignore();

    switch (menu)
    {
    case 1:
      adicionarAluno(&inicio, &fim, &incMatricula);
      break;

    case 2:
      exibirAlunos(inicio);
      break;

    case 3:
      adicionarNota(&inicio);
      break;

    case 4:
      exibirNotas(inicio);
      break;

    case 5:
      system("cls");
      cout << "Ate a proxima!" << endl;
      break;

    default:
      system("cls");
      cout << "Opcao invalida, tente novamente!\n\n";
      break;
    }
  }

  return 0;
}
