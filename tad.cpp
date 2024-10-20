#include "tad.h"

#include <iostream>

using namespace std;

void GerarVetor(int quantidade, int ordem, TAD_Vetor &vetor) {
  vetor.comparacoes = 0;
  vetor.trocas = 0;
  vetor.tamanho = quantidade;
  vetor.vetor = new int[quantidade];

  if (ordem == 1) { // Ordem crescente
    for (int i = 0; i < quantidade; i++) {
      vetor.vetor[i] = i;
    }

  } else if (ordem == 2) { // Ordem decrescente
    for (int i = 0; i < quantidade; i++) {
      vetor.vetor[i] = vetor.tamanho - i;
    }
  } else if (ordem == 3) { // Ordem aleatória
    for (int i = 0; i < quantidade; i++) {
      vetor.vetor[i] = (rand() % quantidade);
    }
  }
};

void VisualizarVetor(TAD_Vetor &vetor) {
  for (int i = 0; i < vetor.tamanho; i++) {
    cout << vetor.vetor[i] << " ";
  }
  cout << endl;
};

void BubbleSort(TAD_Vetor &vetor) {
  // Laço externo corresponde ao número de elementos que serão ordenados
  for (int i = 0; i < vetor.tamanho - 1; i++) {
    // Os últimos i elementos já estão ordenados, então não é preciso que o laço
    // vá até o final do vetor
    for (int j = 0; j < vetor.tamanho - i - 1; j++) {
      vetor.comparacoes++;
      if (vetor.vetor[j] > vetor.vetor[j + 1]) {
        // Criação de uma variável auxiliar para armazenar o valor e depois
        // fazer a troca
        int temp = vetor.vetor[j];
        vetor.vetor[j] = vetor.vetor[j + 1];
        vetor.vetor[j + 1] = temp;
        vetor.trocas++;
      }
    }
  }
};

void MergeSort(TAD_Vetor &vetor, int esq, int dir) {
  if (esq >= dir)
    return;
  else {
    // Encontrar o index do meio
    int meio = (esq + dir) / 2;

    // Recursivamente dividir o vetor em duas partes até que chegue em vetores
    // de um único elemento
    MergeSort(vetor, esq, meio);
    MergeSort(vetor, meio + 1, dir);

    // Criar um vetor auxiliar para fazer as operações de ordenação
    int aux[vetor.tamanho];

    // Laço para percorrer o vetor e copiar seus elementos para o auxiliar
    for (int i = 0; i < vetor.tamanho; i++) {
      aux[i] = vetor.vetor[i];
    }

    // Valores para poder manipular os vetores e fazer as comparações
    int i = esq;      // Início primeira metade
    int j = meio + 1; // Início segunda metade
    int k = esq;      // Início do vetor original para fazer o ordenamento

    // Laço para fazer as comparações, i não pode ultrapassar o meio e o j não
    // pode ultrapassar o fim do vetor
    while (i <= meio and j <= dir) {
      // Contar a comparação
      vetor.comparacoes++;

      // Se o elemento da primeira metade for menor ou igual ao elemento da
      // segunda metade
      if (aux[i] <= aux[j]) {
        vetor.vetor[k] = aux[i];
        // Incremento de i para pegar o próximo elemento da mesma metade do
        // vetor
        i++;
      }

      // Caso contrário, o elemento da segunda metade é colocado na posição k do
      // vetor original
      else {
        vetor.vetor[k] = aux[j];
        // Incremento de j para pegar o próximo elemento da mesma metade do
        // vetor
        j++;
      }
      // Contar a troca
      vetor.trocas++;
      // Incremento de k para ordenar a próxima posição do vetor original
      k++;
    }

    // Se a primeira metade não foi toda consumida, adicionar o resto dos
    // elementos até o meio
    while (i <= meio) {
      vetor.vetor[k] = aux[i];
      i++;
      k++;
      // Contar a troca (mesmo que os elementos já estejam ordenados, estamos
      // movendo-os)
      vetor.trocas++;
    }
  }
};

void CountingSort(TAD_Vetor &vetor) {
  // Verifica se o vetor está vazio
  if (vetor.tamanho == 0)
    return;

  // Variável para armazenar o maior elemento do vetor
  int maior = vetor.vetor[0];
  vetor.comparacoes++;

  // Laço para encontrar o maior elemento do vetor
  for (int i = 1; i < vetor.tamanho; i++) {
    vetor.comparacoes++;
    if (vetor.vetor[i] > maior) {
      maior = vetor.vetor[i];
    }
  }

  // Criação dinâmica do vetor de contagem dos elementos e inicialização
  int *C = new int[maior + 1];

  // Preenchendo o vetor de contagem com a quantidade de elementos
  for (int i = 0; i < vetor.tamanho; i++) {
    C[vetor.vetor[i]]++;
    vetor.trocas++;
  }

  // Transformar o vetor de contagem em um vetor acumulativo
  for (int i = 1; i <= maior; i++) {
    C[i] += C[i - 1]; // Vai somando o valor anterior ao valor atual
  }

  // Criação dinâmica do vetor auxiliar para armazenar os elementos ordenados
  int *aux = new int[vetor.tamanho];

  for (int i = vetor.tamanho - 1; i >= 0; i--) {
    C[vetor.vetor[i]]--; // Decrementa a contagem
    aux[C[vetor.vetor[i]]] =
        vetor.vetor[i]; // Adiciona o elemento no vetor auxiliar
    vetor.trocas++;
  }

  // Copia o vetor ordenado de volta para o vetor original
  for (int i = 0; i < vetor.tamanho; i++) {
    vetor.vetor[i] = aux[i];
    vetor.trocas++;
  }
}
