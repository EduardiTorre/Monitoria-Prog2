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
    scanf("%f", &p->nota);

    printf("\n\n");
    printf("Nome do aluno: %s\n", p->nome);
    printf("Idade do aluno: %i\n", p->idade);
    printf("Nota do aluno: %.2f\n", p->nota);

    free(p); // liberando o malloc

    return EXIT_SUCCESS;
}