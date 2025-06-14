/*


Declare um array com os números: {88,42,17,95,23,56,71,3,39,64}
Implemente uma função para imprimir o array
Use busca linear para encontrar o número 23
Ordene o array usando bubble sort
Use busca binária para encontrar o número 23 novamente

*/

// Esqueleto para a atividade
#include <stdio.h>


void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int buscaLinear(int arr[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int buscaBinaria(int arr[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (arr[meio] == valor) {
            return meio;
        } else if (arr[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; 
}



int main() {
    int numeros[] = {88, 42, 17, 95, 23, 56, 71, 3, 39, 64};
    int tamanho = 10;

    printf("Array original:\n");
    imprimirArray(numeros, tamanho);

    int valor = 23;
    int posicaoLinear = buscaLinear(numeros, tamanho, valor);
    if (posicaoLinear != -1) {
        printf("\nBusca Linear: valor %d encontrado na posição %d\n", valor, posicaoLinear);
    } else {
        printf("\nBusca Linear: valor %d não encontrado\n", valor);
    }

    printf("\nOrdenando array...\n");
    bubbleSort(numeros, tamanho);

    printf("Array ordenado:\n");
    imprimirArray(numeros, tamanho);

    int posicaoBinaria = buscaBinaria(numeros, tamanho, valor);
    if (posicaoBinaria != -1) {
        printf("\nBusca Binária: valor %d encontrado na posição %d\n", valor, posicaoBinaria);
    } else {
        printf("\nBusca Binária: valor %d não encontrado\n", valor);
    }

    return 0;
}
