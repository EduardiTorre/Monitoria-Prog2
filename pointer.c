/* ************************************************************************ *
 *    pointer.c, VERSION 1                                                      *
 *    funcao criada para mostrar autilização da lib pessoal                 *
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
 * $ gcc pointer.c -o pointer.x -Wall -Wextra
 *  
 */
/* ---------- includes ---------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "libjeoc.h"

/* ---------- prototypes ---------- */
int *point(int size, int num); /* chamando a funcao do tipo ponteiro inteiro */
//retorna "int num[];" q seria um vetor

/* ---------- programa ---------- */
int main(void){
    /* ------- variaveis ------- */
    int *ptr; 
    int size, num;
    printf("quantidade de numeros:");
    scanf("%i", &size);
    printf("numero atribuido:");
    scanf("%i", &num);

    ptr = point(size, num); // ponteiro recebe o retorno da funcao, que pe do tipo ponteiro inteiro 

    /* ciclo para mostra o que se encontra na variavel ptr */
    for(int i = 0;i < size; i++){
        printf("%i: %i\n", i+1, ptr[i]);
    }

    free(ptr); /* libera espaco do ponteiro */

    return 0;
}

/* funcoes externas */
int *point(int tamanho, int num){
    int *resp = malloc(tamanho * sizeof(int)); /* aloca memoria no ponteiro (resp)osta */

    /* ciclo para adicionar o valor no vetor */
    for(int i = 0;i < tamanho; i++){
        resp[i] = num;
    }

    return resp; /* retorna o vetor */
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
