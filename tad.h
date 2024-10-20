#ifndef TAD_H
#define TAD_H

struct TAD_Vetor {
  int comparacoes;
  int trocas;
  int tamanho;
  int *vetor;
};

void GerarVetor(int, int, TAD_Vetor&);
void VisualizarVetor(TAD_Vetor&);
void BubbleSort(TAD_Vetor&);
void MergeSort(TAD_Vetor&, int, int);
void CountingSort(TAD_Vetor&);

#endif