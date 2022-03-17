/* ************************************************************************ *
 *    lista.c, VERSION 1                                                    *
 *    lista disponibilizada pelo professor Ruben Carlo Benante              *
 *    modificada e comentada para melhor entendimento na monitoria          *
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
 * $ gcc lista.c -o lista.x -Wall -Wextra
 *  
 */
/* ---------- includes ---------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "libjeoc.h"

/* ---------- structs ---------- */
typedef struct st_lista {
    int valor;              //o item armazenado 
    struct st_lista *prox;  //ponteiro para próximo
}lista;

/* ---------- prototypes ---------- */
void inserir(lista **cabeca, int x); // insere valor na lista
void imprimir(lista *cabeca); // imprime os valores da lista, sem perde-la
lista *buscar(lista *cabeca, int x); // busca struct q tenha o valor == ao mandado
void remover(lista **cabeca, lista *r); // remove a struct enviada da lista de structs
lista *anterior(lista *cabeca, lista *r); // mostra a struct anterior a struct r da lista cabeca

/* ---------- programa ---------- */
int main(void){
    /* ------- variaveis ------- */
    lista *l1=NULL, *b=NULL, *a=NULL;

    inserir(&l1, 1);
    imprimir(l1);
    b=buscar(l1, 4);
    if(b!=NULL)
        printf("b->c: %d\n", b->valor);
    a=anterior(l1, b);
    if(a!=NULL)
        printf("a->c: %d\n", a->valor);
    b=buscar(l1, 1);
    remover(&l1, b);

    return EXIT_SUCCESS;
}

// HELP:    pl creio que seja ponteiro de lista

void inserir(lista **cabeca, int x){
    lista *pl=*cabeca; // 'pl' eh como sera usado o cabeca para q ele n se perca
    lista *ant_pl = NULL; // ponteiro do anterior ao "pl"

    while(pl!=NULL){
        ant_pl=pl; // o anterior pl recebe o pl atual
        pl=pl->prox;  // e o pl apos deixar salvo o atual, muda para o proximo, fazendo o anterior pl ser agr o anterior
    } // esse ciclo faz com q o pl sempre seja o final da lista e o ant_pl o anterior ao final, que tem "valor salvo"

    pl = malloc(sizeof(lista)); // alocar memoria no pl
    pl->valor = x; // na struct do pl, dps de alocado pode receber o valor a ser guardado, recebido na funcao como segundo parametro
    pl->prox=NULL; // faz com q o proximo q sera add na lista seja sempre null(sendo o final da lista)
    
    if(ant_pl!=NULL) // se tem anteriro entao nao eh o primeiro item da lista
        ant_pl->prox=pl; // faz com q a ultima struc->prox aponte para o novo pl q sera add no final da lista
    else
        *cabeca=pl;
}

void imprimir(lista *cabeca){
    lista *pl=cabeca; // pl recebe cabeca para pl poder percorrer a lista

    while(pl!=NULL){ // enquanto o pl for diferente de NULL vc printara o valor do pl e dps fara ele ir para o prox da lista
        printf("%d->",pl->valor);
        pl=pl->prox;
    }
    printf("NULL\n"); // print opcional do professor para q o final fique aparecendo NULL
}

lista *buscar(lista *cabeca, int x){
    lista *pl=cabeca; // pl aponta para cabeca da lista
    while(pl!=NULL){ // fica andando pela lista ate encontrar uma struct que temnha valor == x
        if(pl->valor==x) // se for o valor  == x entao retorna a propria struct
            return pl;
        pl=pl->prox;
    }
    return NULL;
}

void remover(lista **cabeca, lista *r){
    lista *pl=*cabeca; // pl aponta para cabeca da lista
    lista *ant_pl=NULL; // anterior ao pl

    if(r==NULL) // acaba a funcao caso n tenha encontrando struct com aquele valor atribuido
        return;

    while(pl!=NULL && pl!=r){ //ate achar r ou fim
        ant_pl=pl; // o anterior do pl sera salvo no ant_plant
        pl=pl->prox;
    }

    if(pl==NULL) //nao achou a struct r na lista ou lista vazia
        return;
        
    if(ant_pl!=NULL) //tem anterior
        ant_pl->prox=pl->prox; // o anterior ao pl apontara para o proximo do pl, deixando o pl fora da lista
    else //eliminando cabeca
        *cabeca=pl->prox; // se ant. ao pl for == NULL entao o pl esta na primeira struct da lista
                          // entao vc aponta a cabeca da lista direto para o proximo do pl(que é o msm q a cabeca) 
    
    free(pl); // apos o pl fora da lista desaloca memoria para nao ocupar mem. do pc

    return;
}

lista *anterior(lista *cabeca, lista *r){
    lista *pl=cabeca, // pl aponta para cabeca
          *ant_pl=NULL; // anterior ao pl

    if(r==NULL) // se r == null entoa n existe struct com tal valor nessa lista
        return NULL;
    while(pl!=NULL && pl!=r){ // percorre procurando a struct na lista 
        ant_pl=pl; // salva o pl anterior
        pl=pl->prox; // pl aponta para aa proxima struct
    }
    return ant_pl; 
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
