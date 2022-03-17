/* ************************************************************************ *
 *    struct.c, VERSION 1                                                   *
 *    funcao criada para mostrar struc com ponteiros                        *
 *                                                                          *
 *    Copyright (C) 2022 by Jose Eduardo Oliveira Cavalcanti Lupa           *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Jose Eduardo Oliveira Cavalcanti Lupa <jeoc@poli.br>              *
 *  Webpage: http://beco.poli.br/~jeoc                                      *
 *  Phone: (81) 99686-9333                                                  *
 * ************************************************************************ *
 *
 * compilacao:
 * $ gcc struct.c -o struct.x -Wall -Wextra
 *  
 */
/* ---------- includes ---------- */
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

/* ---------- structs ---------- */
typedef struct alunos{
    char nome[200];
    int idade;
    float nota;
}t_alunos;

/* ---------- programa ---------- */
int main(void){
    /* ------- variaveis ------- */
    t_alunos *p = malloc(sizeof(t_alunos)); 

    printf("Nome: ");
    scanf(" %[^\n]s", p->nome); /* atribuindo para a struct com ponteiro, se fosse so struct seria p.nome */  

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

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
