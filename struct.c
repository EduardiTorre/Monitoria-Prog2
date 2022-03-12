#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct alunos{
    char nome[30];
    float idade;
    float nota;
};
*/

typedef struct alunos{
    char nome[200];
    int idade;
    float nota;
}t_alunos;

int main(void){
    t_alunos *p = malloc(sizeof(t_alunos));

    printf("Nome: ");
    scanf(" %[^\n]s", p->nome);   

    printf("Idade: ");
    scanf("%i", &p->idade); 
    
    printf("Nota: ");  

    free(p); // liberando o malloc

    return EXIT_SUCCESS;
}