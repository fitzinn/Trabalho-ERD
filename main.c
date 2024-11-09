#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Selection Sort: Um algoritmo simples que repetidamente seleciona o menor elemento restante.
void selectionSort(int array[], int n) {
  for(int i = 0; i < n - 1; i++){
    int min = i;

    for(int j = i + 1; j < n; j++){
      if(array[j] < array[min]){
        min = j;
      }
    }
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

//Insertion Sort: Constrói a lista final um item de cada vez, como organizar cartas de baralho na mão.
void insertionSort(int array[], int n) {
  for(int i = 1; i < n; i++){
    int temp = array[i];
    int j = i - 1;
    while(j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
}

//Bubble Sort: Compara pares adjacentes e os troca se estiverem fora de ordem.
void bubbleSort(int array[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//Merge Sort: Um algoritmo eficiente que divide a lista, ordena as partes e depois as mescla.
void mergeSort(int array[], int n) {

}


//Quick Sort: Um algoritmo rápido que usa a estratégia de dividir e conquistar.
void quickSort(int array[], int n) {

}


//Heap Sort: Utiliza uma estrutura de dados chamada heap para ordenar os elementos.
void heapSort(int array[], int n) {

}


//main para testes
int main() {

}