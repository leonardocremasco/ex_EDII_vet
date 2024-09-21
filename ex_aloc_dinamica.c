// Nome: Leonardo Cremasco Bernardes Boscariol | RA: 202310228
// Nome: Rafael Fernandes | RA: 202310406


#include <stdio.h>
#include <stdlib.h>

int * initVet ( int *size , int *maxSize ){
    *size = 0;
    *maxSize = 4;
    int *v = (int *)malloc((*maxSize) * sizeof(int)); // alocando dinamicamente
    if (!v) {
        printf("Erro ao alocar memoria\n"); // verificação de erro
        exit(1);
    }
    return v;
}

void printVet ( int *v , int size , int maxSize ){
    printf("Vetor: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }   
    printf("\nTamanho atual: %d, Tamanho alocado: %d\n", size, maxSize);
}

int * addVet( int *v , int *size , int *maxSize , int e ){
    // Se o vetor estiver cheio, redimensiona para o dobro do tamanho
    if (*size == *maxSize) {
        *maxSize *= 2;
        v = (int *)realloc(v, (*maxSize) * sizeof(int));
        if (!v) {
            printf("Erro ao realocar memoria\n");
            exit(1);
        }
    }
    v[*size] = e;  // adicionando o elemento no final do vetor
    (*size)++;     // incrementação/iteração o tamanho atual
    return v;
}

int find(int *v, int size , int e) {
    for (int i = 0; i < size; i++) {
        if (v[i] == e) {
            return i;  // retorna a posição da primeira ocorrência
        }
    }
    return -1;  // se não encontrar, retorna -1, código de erro
}

int * removeVet( int *v , int *size , int *maxSize , int e ) {
     int pos = find(v, *size, e);
    
    if (pos == -1) {
        printf("Elemento %d nao encontrado\n", e);
        return v;
    }
    
    // remove o elemento, movendo os outros para a esquerda do vetor
    for (int i = pos; i < (*size) - 1; i++) {
        v[i] = v[i + 1];
    }
    (*size)--;  // decrementa ou diminui o tamanho do vetor
    
    // se o número de elementos for menor que 1/4 do tamanho alocado, diminui o vetor pela metade
    if (*size < (*maxSize) / 4 && *maxSize > 4) {
        *maxSize /= 2;
        v = (int *)realloc(v, (*maxSize) * sizeof(int));
        if (!v) {
            printf("Erro ao realocar memoria\n");
            exit(1);
        }
    }
    return v;
}

int main () {
    int size, maxSize;
    
    // Inicializa o vetor
    int *vet = initVet(&size, &maxSize);
    
    // Adiciona elementos ao vetor
    vet = addVet(vet, &size, &maxSize, 10);
    vet = addVet(vet, &size, &maxSize, 20);
    vet = addVet(vet, &size, &maxSize, 30);
    vet = addVet(vet, &size, &maxSize, 40);
    vet = addVet(vet, &size, &maxSize, 50);  // O vetor será redimensionado aqui
    
    // Imprime o vetor
    printVet(vet, size, maxSize);
    
    // Remove o elemento 30
    vet = removeVet(vet, &size, &maxSize, 30);
    
    // Imprime o vetor após a remoção
    printVet(vet, size, maxSize);
    
    // Remove o elemento 10
    vet = removeVet(vet, &size, &maxSize, 10);
    
    // Imprime o vetor após a segunda remoção
    printVet(vet, size, maxSize);
    
    // Libera a memória alocada
    free(vet);
    
    return 0;
}