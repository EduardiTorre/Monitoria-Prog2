#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *point(int size, int num);
//retorna "int num[];" q seria um vetor

int main(void){
    int *ptr;
    int size, num;
    printf("quantidade de numeros:");
    scanf("%i", &size);
    printf("numero atribuido:");
    scanf("%i", &num);

    ptr = point(size, num);

    for(int i = 0;i < size; i++){
        printf("%i: %i\n", i+1, ptr[i]);
    }

    free(ptr);
    return 0;
}

int *point(int tamanho, int num){
    int *resp = malloc(tamanho * sizeof(int));

    for(int i = 0;i < tamanho; i++){
        resp[i] = num;
    }

    return resp;
}
