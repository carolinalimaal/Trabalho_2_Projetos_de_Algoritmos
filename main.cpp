// Trabalho 2 de Projetos de Algortimos I 
// Alunos: Carolina de Lima Alves e Gabriel Lemos da Silva Mastub

#include "tad.h"
#include <chrono> // Inclui a biblioteca para medir o tempo de execução
#include <iostream>

using namespace std;

int main() {
  TAD_Vetor vetor; // Declara uma variável do tipo TAD_Vetor, que será usada para
  // armazenar os elementos.

  // Respostas das escolhas do menu
  int quantidade, ordem, algoritmo, visualizar;

  // Menu para a escolha da quantidade de valores no vetor
  cout << "Escolha uma quantidade de valores no vetor: [10], [100], [1000], "
          "[10000]: "
       << endl;
  cin >> quantidade;

  // Menu para a escolha da ordem em que os valores estão no vetor
  cout << "Escolha a ordem que os valores estão no vetor: " << endl;
  cout << "[1] Ordem crescente" << endl;
  cout << "[2] Ordem decrescente" << endl;
  cout << "[3] Ordem aleatoria" << endl;
  cin >> ordem;

  GerarVetor(quantidade, ordem, vetor);

  // Opção para visualizar o vetor antes de ordenar
  cout << "Deseja vizualizar o vetor? [1] Sim [0] Não" << endl;
  cin >> visualizar;

  if (visualizar == 1) {
    VisualizarVetor(vetor);
  }

  // Menu para escolher qual o algoritmo de ordenação será usado
  cout << "Escolha um algoritmo para ordenar o vetor: " << endl;
  cout << "[1] Bubble Sort" << endl;
  cout << "[2] Merge Sort" << endl;
  cout << "[3] Counting Sort" << endl;
  cin >> algoritmo;

  // Início do cronomêtro
  auto inicio = chrono::high_resolution_clock::now();

  // Algoritmos
  switch (algoritmo) {
  case 1: // Bubble Sort
  {
    BubbleSort(vetor);
    break;
  }
  case 2: // Merge Sort
  {
    MergeSort(vetor, 0, vetor.tamanho - 1);
    break;
  }
  case 3: // Counting Sort
  {
    CountingSort(vetor);
    break;
  }
  }

  // Fim do cronomêtro
  auto fim = chrono::high_resolution_clock::now();

  // // Tempo de execução
  chrono::duration<double> tempo_execucao = fim - inicio;

  // Vetor ordenado
  VisualizarVetor(vetor);
  // Número de comparações no algoritmo
  cout << "Numero de comparacoes: " << vetor.comparacoes << endl;
  // Número de trocas no algoritmo
  cout << "Numero de trocas: " << vetor.trocas << endl;
  // Tempo de execução do algoritmo
  cout << "Tempo de execucao: " << tempo_execucao.count() << " segundos"
       << endl;

  return 0;
}