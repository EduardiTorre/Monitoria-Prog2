/***************************************************************************
 *   auto2.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert AFD into ER                                                   *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file auto2.c
 * @ingroup GroupUnique
 * @brief Convert AFD into ER
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2022-06-06
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc auto2.c -o auto2.x -Wall -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* Instrucoes para executar:
 * $gcc [inserir instrução]
 *
 * */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto2.h */

#include "auto2.h" /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./auto2 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    t_quintupla *cabeca = NULL;
    FILE *f = NULL;
    int key_d = 0;
    int key_t = 0;

    IFDEBUG("Starting optarg loop...");

    opterr = 0;
    
    while((opt = getopt(argc, argv, "hcvdf:")) != EOF)
        switch(opt)
        {
            case 'h': /* chamada da funcao help */
                help();
                break;
            case 'c': /* chamada copyright e versao */
                copyr();
                break;
            case 'v': /* verbose */
                verb++;
                break;
            case 'd': /* AFD para ER */
                key_d = 1;
                break;
            case 'f': /* abertura com arquivo */
                f = fopen(optarg, "r"); /* abre arquivo "r" significa que o arquivo necessariamente precisa existir, e que abre no modo somente leitura */

                if(f)
                {
                    printf("Arquivo encontrado!\n");
                    casting_str(f, &cabeca); /* chama função casting */
                }
                else
                {
                    printf("Error, arquivo nao encontrado!\n"); /* imprime mensagem de erro caso a condicao nao seja cumprida */
                    exit(EXIT_FAILURE);
                }
                key_t = 1;
                break;
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    if(key_d == 1)
        printf("\nChave -d obrigatória.\n\n");

    if(argc == 1)
    {
		FILE *P;

 		pipe();
 		P = fopen("espelho.txt", "r");
 		casting_str(P, &cabeca);
 		afd2er(&cabeca);
 		libera_memoria(&cabeca);
 		remove("espelho.txt");
 		free(cabeca);
 		fclose(P);
    }
    
    if(key_t == 1)
    {
        afd2er(&cabeca);
        libera_memoria(&cabeca);
        free(cabeca);
    }

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Funcao para escanear um arquivo no terminal e passar ele para um outro arquivo espelho criado no código */
void pipe(void)
 {
     FILE *fc = NULL;
     char conteudo[SBUFF];

     fc = fopen("espelho.txt", "a");  

     while(1)
     {
         scanf(" %[^\n]s", conteudo);  /* ler o terminal e passar o arquivo para string */
         if(getchar() == EOF)  /* getchar escanear todas as linhas */
             break;

        fprintf(fc, "%s\n", conteudo);  /* printar string recebida no arquivo espelho */
     }

     fclose(fc);
 }

/* ---------------------------------------------------------------------- */
/* Pegar quintupla e a expressao, separar a expressao em partes e colocar em delta */
void make_delta_str(t_quintupla **cabeca, char linha[10]) /* &q */ /* 1 a 2 */ /* (t_quintupla **cabeca, int ei, char le[2], int ef)  */
{
    char cle = '0';
    int einit;
    int efinal;
    t_quintupla *head = *cabeca;
    t_delta *delta = head -> D;
    t_delta *aux_delta = head -> D;

    /* convertendo o tipo de char para int para o ei e para o ef */

    sscanf(linha, "%d %c %d", &einit, &cle, &efinal);

    /* colocando os valores da string de entrada no delta */

    while(delta != NULL)  /* enquanto delta existir */
    {
        aux_delta = delta;  /* variavel auxiliar pega o valor de delta */
        delta = delta->prox;  /* valor de delta muda para o proximo valor da lista */
    }

    delta = malloc(sizeof(t_delta));  /* delta ocupa o espaco de uma struct t_delta da memoria */

    delta->le = malloc(100 * sizeof(char));

    delta->ei = einit;

    /* strcpy(delta->le, str_le); */
    delta->le[0] = cle;
    delta->le[1] = '\0';
    /* printf("%s", delta-le); */

    delta->ef = efinal;
    delta -> prox = NULL;

    /* termino da insercao da string no delta */

    if(aux_delta != NULL)
        aux_delta -> prox = delta;
    
    else
    {
        head -> D = delta;
        *cabeca = head;
    }

    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para inserir estados finais */
void make_end_str(t_quintupla **cabeca, char linha[10]) /* Ex: &q, linha = 1 2 */
{
    t_quintupla *head = *cabeca;  /* head eh a copia da cabeca */
    t_lef *final =  head -> F;    /* ponterio do tipo t_lef recebe o que tem no ponteiro F da struct */
    t_lef *aux_final = NULL;      /* ponteiro do tipo t_lef que auxilia a insercao */
    char *pont = NULL;
    int num = 0;

    pont = strtok(linha, " ");

    while(pont)
    {
        num = strtol(pont, NULL, 10); /* Transformando string em decimal */

        while(final != NULL)
        {
            aux_final = final; /* plant = pl */
            final = final->prox; /* pl = pl->prox */
        }

        final = malloc(sizeof(t_lef)); /* alocando memoria */

        final->f = num; /* Novo valor final eh adicionado */
        final->prox = NULL; /* Adiciona NULL no proximo nodo */

        if(aux_final != NULL)
            aux_final->prox = final;
       
        else
        {
            head->F = final;
            *cabeca = head; /* Cabeca eh atualizado com o valor do novo final */
        }

        pont = strtok(NULL, " ");
    }

    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para fazer o casting do txt */
void casting_str(FILE *file, t_quintupla **cabeca)
{
    char Linha[100];
    char ant[100];
    t_quintupla *copia = *cabeca;
    copia = malloc(sizeof(t_quintupla));

    while(!feof(file))
    {

        if(fgets(Linha, 100, file) != NULL) /* vai ler ate encontar NULL (nao ter nada pra ser lido)*/
        {
            if(strstr(ant, "#K") != NULL && strcmp(ant, Linha) != 0) /* atribui #K (estados) */
            {
                copia->K = atoi(Linha);
                strcpy(ant, Linha);
            }
            
            if(strstr(ant, "#A") != NULL && strcmp(ant, Linha) != 0) /* atribui #A (alfabetos) */
            {
                copia->A = Linha[0];
                strcpy(ant, Linha);
            }
            
            if(strstr(ant, "#S") != NULL && strcmp(ant, Linha) != 0) /* atribui #S (estados iniciais) */
            {
                copia->S = atoi(Linha);
                strcpy(ant, Linha);
            }
            
            if(strstr(ant, "#F") != NULL && strcmp(ant, Linha) != 0) /* atribui #F (estados finais) */
            {
                make_end_str(&copia, Linha);
                strcpy(ant, Linha);
            }
            
            if(strstr(ant, "#D") != NULL && strcmp(ant, Linha) != 0) /* atribui #D (delta) */
                make_delta_str(&copia, Linha);
    
            else
                strcpy(ant, Linha);
        }

    }
    
    *cabeca = copia;
    
    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para printagem da quintupla */
void print_quintupla(t_quintupla *cabeca)
{
    t_delta *x = cabeca -> D;
    t_lef *y = cabeca -> F;

    printf("K: %d\n", cabeca->K); /* estados */
    printf("A: %c\n", cabeca->A); /* alfabeto */
    printf("S: %d\n", cabeca->S); /* estado inicial */
    printf("F:");                 /* estados finais */

    while(y != NULL)
    {
        printf(" %d", y->f);

        y = y->prox; /* proximo */
    }

    printf("\nD:\n"); /* print t_delta */
    
    while(x != NULL)
    {
        printf("%d %s %d\n", x->ei, x->le, x->ef);

        x = x->prox; /* proximo */
    }
    
    printf("\n");

    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para printar lista delta a partir do argumento dado */
void print_delta(t_delta *d)
{
    t_delta *copia = d;

    while(copia != NULL)  /* pecorre a lista delta ate o fim */
    {
        printf(" %d | %s | %d\n", copia->ei, copia->le, copia->ef);  /* printar os estados inicial e final, e o alfabeto */
        copia = copia->prox;
    }
    
    printf("\n");
    
    return;
}

/* ---------------------------------------------------------------------- */
/*Funcao para adicionar novo estado final a lista */
void novo_final(t_quintupla **cabeca)
{
    t_quintupla *copia = *cabeca; /* copia do cabeca para nao mexer diretamente no original */
    t_lef *final = copia -> F; /* copia da lista de estados finais */
    t_lef *ant_final = NULL; /* ponteiro auxiliar de final */
    char linha[10]; /* char linha para receber string que sera mandada para a make_delta_str */

    while(final != NULL) /* while que faz o ponterio se mover ate o final da lista */
    {
        ant_final = final; /* ponteiro auxiliar recebe o valor de final */
        sprintf(linha, "%d E %d", final->f, copia->K); /* linha vai ser gerado com o valor do antigo final um 'vazio' e o novo final */
        make_delta_str(&copia, linha); /* o linha eh mandado para a make_delta_str para gerar um novo arco de delta */
        final = final -> prox; /* final passa para o proximo da lista */
    }
    
    final = malloc(sizeof(t_lef)); /* eh alocada memoria para o novo final na lista de finais */

    final -> f = copia -> K; /* novo final recebe o valor correspondente */
    final -> prox = NULL; /* o valor da lista posterior ao atual sera NULL */

    if(ant_final != NULL)
        ant_final -> prox = final;
    
    else
    {
        copia->F = final;
        *cabeca = copia;
    }

    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para adicionar estrela de kleene 
 * verificando se o estado inicial eh igual ao final */
void kleene(t_delta **cabeca)
{
    t_delta *copia_d = *cabeca;
    char* aux = NULL; /* variavel auxiliar que ira receber o ponteiro retornado da funcao */

    /* condicional para verificar a estrela de kleene */
    while(copia_d != NULL)
    {
        if(copia_d->ei == copia_d->ef)  /* verifica se o estado final eh numericamente igual ao estado inicial */
        {
            aux = verificar_kl_le(copia_d->le);
            strcpy(copia_d->le, aux); /* adiciona na lista delta o ponteiro do tipo char processado na funcao verificar_kl */
            free(aux); /* liberacao de memoria do ponteiro auxiliar */
        }

        copia_d = copia_d->prox; /* ponteiro copia aponta para o proximo dele, dando continuidade para a lista */
    }

    copia_d = *cabeca;
    *cabeca = copia_d; /* copia proximo */
}

/* ---------------------------------------------------------------------- */
/* Funcao para remover estados */
void remover_estados(int i, t_delta **cabeca)
{
    t_delta *copia = *cabeca; /* copia do cabeca */
    t_delta *plant = NULL;
    /* while para transitar por toda a lista, ate o copia apontar para NULL */
    while(copia != NULL)
    {
        if(copia->ei == i || copia->ef == i)  /* estado inicial ou estado final dentro da lista */
            break;
        plant = copia; /* o anterior aponta para o copia */
        copia = copia->prox; /* o copia aponta para o proximo dele */
    }
    /* retirar estado da sequencia */

    if(copia == NULL)
        return;
    /* condicionais para verificar se o copia aponta para o primeiro da lista */
    if(plant != NULL)
        plant->prox = copia->prox;
    else
        *cabeca = copia->prox;
    free(copia);  /* liberar memoria */

    return;
}

/* ---------------------------------------------------------------------- */
/* Ver arcos com ei = ef e le diferentes. Ex: (1 a 2 + 1 b 2 = 1 (a|b) 2 ) */
/* Funcao que transita pela quintupla com um algoritmo proximo ao bubble sort,
 * elimina um estado, concatena e adiciona o pipe                             */
void juncao_final_er(t_delta **cabeca)
{
    t_delta *k = *cabeca;
    t_delta *d = *cabeca;
    t_delta *ant_k = NULL;
    char* aux5 = NULL;/* variavel que ira receber a string retornada pela funcao verificar_pp */

   /* char *parentesis = NULL; */
   /* while da primeira variavel auxiliar */
    while(d != NULL)
    {
        k = *cabeca;
        /* while para a segunda variavel auxiliar */
        while(k != NULL)
        {
            if((d->ei == k->ei) && (d->ef == k->ef) && (d != k))
            {
                aux5 = verificar_pp_le(d->le, k->le); 
                strcpy(d->le, aux5);  /* copia para dentro da quintupla a funcao verificada e organizada */
                ant_k->prox = k->prox;  /* ponteiro anterior proximo que aponta para o proximo da segunda variavel auxiliar */
                free(k); /* liberacao de memoria */
                free(aux5); /* liberacao de memoria */
            }
            /* condicional para verificar se a segunda variavel auxiliar eh diferente de NULL */
            
            if(k != NULL)
                ant_k = k;
           
            k = k->prox; /* apontado k para o proximo elemento da lista */
        }

        d = d->prox; /* apontado d para o proximo elemento da lista */
    }

    d = *cabeca;
    *cabeca = d;

    return;
}

/* ---------------------------------------------------------------------- */
/* Atencao nesses casos: (1 a 2 + 2 b 3 = 1 a.b 3) & (0 a 2 + 2 b 1 = 0 a.b 1) */
void soma_arcos(t_delta **cabeca, int E)
{
    t_delta *k = *cabeca;
    t_delta *d = *cabeca;
    int cont = 0;

    char *linha = NULL;

    while(d != NULL)
    {
        k = *cabeca;

        while(k != NULL)
        {
            if((d->ef == k->ei) && (d->ef == E)) /* testa se o estado final apontado por d eh igual a E e o ei apontado por k */
            {
                linha = malloc(100 * sizeof(char));
                sprintf(linha, "%s.%s", d->le, k->le); /* juncao dos le apontados por k e d */
                add_delta(cabeca, d->ei, linha, k->ef); /* adiciona novo nodo */
                free(linha); /* libera memoria */
            }

            k = k -> prox; /* apontando k para o proximo item da lista */
        }

        d = d -> prox; /* apontando d pára o proximo item da lista */
    }

    d = *cabeca;

    while(d != NULL)
    {
        d = d->prox;
        cont++; /* contagem de itens da lista */
    }
    while(cont != 0)
    {
        cont--; /* usa cont para que o while passe por todos os itens */
        remover_estados(E, cabeca); /* faz a remocao do estado */
    }
    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para adicionar um novo nodo a lista delta (novos valores ei, ef e le) */
void add_delta(t_delta **cabeca, int Ei, char *Le, int Ef)
{
    t_delta *d = *cabeca;
    t_delta *ant_d = NULL;

    while(d != NULL)
    {
        ant_d = d;
        d = d -> prox;  /* apontando sempre proximo item */
    }

    d = malloc(sizeof(t_delta));  /* d recebe alocacao de memoria do tamanho de uma struct t_delta */
    d -> le = malloc(100 * sizeof(char));  /* seu le respectivo recebe uma alocacao do tamanho de 100 variaveis do tipo char */

    /* preenche os valores de le, ei e ef novos de acordo com as informacoes recebidas */
    d -> ei = Ei;
    strcpy(d -> le, Le);
    d -> ef = Ef;
    d -> prox = NULL;  /* novo item ser o ultimo elemento da lista */

    if(ant_d != NULL)
        ant_d -> prox = d;
    else
        *cabeca = d;

    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao que soma deltas com estrela de kleene ex: (1 a 3) + (1 a* 1) = (1 a*.a 3)
 * usando um algoritmo parecido ao bubble sort para transitar pela lista           */
void soma_kleene(t_delta **cabeca)
{
    t_delta *k = *cabeca;  /* ponteiro auxiliar1 */
    t_delta *d = *cabeca;  /* ponteiro auxiliar2 */
    char *aux = NULL;

    while(d != NULL) /*while para o auxiliar1 */
    {
        k = *cabeca;
        while(k != NULL) /*while para o auxiliar2 */
        {
            /* k estrela de kleene */
            /* condicional para verificar se o int inicial do d->ei tem inicial igual ao k->ei(estrela de kleene)*/
            if((k->ei == k->ef) && (d->ei == k->ei) && (d != k)) 
            {
                aux = malloc(100 * sizeof(char)); /* alocacao de memoria para a variavel auxiliar */
                if(strcmp(d->le, "E") != 0)
                {
                    sprintf(aux, "%s.%s", k->le, d->le); /* altera a variavel aux para receber a soma do k->le para o d->le */
                    strcpy(d->le, aux); /* copia o aux para o ponteiro de char d->le */
                }
                else
                    strcpy(d->le, k->le); /* copia um ponteiro char k->le para o d->le */

                free(aux); /* liberacao de memoria */
            }

            k = k->prox; /* apontar para o proximo da lista */
        }
        
        d = d->prox; /* apontar para o proximo da lista */
    }

   
    d = *cabeca;
    *cabeca = d;
    
    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao que remove estados quando um desses estados tem estrela de kleene */
void remover_kleene(t_quintupla **cabeca)
{
    t_delta *d = (*cabeca)->D;  /* copia do cabeca */
    t_delta *ant_d = NULL;  /* anterior ao cabeca */

    while(d != NULL)  /* while para chegar ao fim da lista */
    {
        if(d->ei == d->ef)  /* condicional para verificacao de estado inicial igual a final */
        {
            if(ant_d == NULL)  /* condicional para verificar se o anterior eh nulo, ou seja, quando o "d" eh o primeiro elemento da lista */
                (*cabeca)->D = d->prox;
            else
                ant_d->prox = d->prox;

            free(d);  /* liberacao de memoria para o delta com estrela de kleene */
        }
        
        if(d != NULL)
            ant_d = d;
        
        d = d->prox;
    }
}

/* ---------------------------------------------------------------------- */
/* Funcao "main" que faz o chamado das funcoes de conversao */
/* Conversao e printagem final */

void afd2er(t_quintupla **cabeca)
{
    t_quintupla *copia = *cabeca;
    t_lef *copia_f = copia -> F;
    int i = 0;
    int cont = 0;

    novo_final(&copia); /* chamado para a funcao de novo_final */
    
    copia_f = copia -> F;

    while(i < copia->K) /* while para deixar apenas estados iniciais e finais */
    {
        /* O ciclo do/while roda para verificar se o valor 'i' eh estado final ou inicial. *
         * Se 'i' for estado inicial ou final, o valor eh pulado e o proximo entra para a  *
         * comparacao. Caso o valor 'i' seja diferente de inicial e finais, o ciclo para.  */
        do
        {
            if(i == copia->S)
                i++;
            
            copia_f = copia->F;

            while(copia_f != NULL)
            {
                if(i == copia_f->f)
                    i++;
                
                copia_f = copia_f -> prox;
            }

        }
        while(verifica(&copia, i) == true);
        /* Fim do ciclo do/while */

        /* Chamada dsa funcoes para realizar as operacoes */
        juncao_final_er(&copia->D); /* Unir arcos que tenham ei e ef iguais */

        kleene(&copia->D); /* Adicionar a estrela de kleene nos arcos que tem ei = ef */

        soma_kleene(&copia->D); /* Somar os arcos que tem kleene nos arcos correspondentes */

        remover_kleene(&copia); /* Remover o antigos arcos de kleene */

        soma_arcos(&copia->D, i); /* Fazer as somas dos arcos que sejam sequencia um do outro */

        i++; /* Adicao de uma unidade no valor de 'i' para o ciclo continuar rodando ate atingir a condicao de parada */
    }

    /* ciclo para eliminar estados finais */

    i = 0;
    while(i < copia->K) /* While que retira os estados que nao sao nem o inicial nem o novo final */
    {
        /* if para manter o '1' diferente do S da quintupla e dos valores de F */
        if(i == copia->S)
            i++;
        if(i >= copia->K)
            break;

        /* Chamadas das funcoes na ordem correta de execucao */
        juncao_final_er(&copia->D);
        
        kleene(&copia->D);
        
        soma_kleene(&copia->D);
        
        remover_kleene(&copia);
        
        soma_arcos(&copia->D, i);
        
        juncao_final_er(&copia->D);

        i++;
    }

    /* printagem da expressao regular */
   
    copia_f = copia -> F; /* Atualizacao da variavel copia_f */
    
    /* Ciclo while para conferir se existe algum estado inicial que tambem eh estado final */
    while(copia_f != NULL)
    {
        if(copia -> S == copia_f -> f)
        {
            cont++;
        }
        
        copia_f = copia_f -> prox;
    }
    
    /* Prints finais */
    /* Primeiro if printa se o estado inicial for igual a algum estado final */
    /* O segundo printa se o estado inicial for diferente de todos os estados finais */
    if(cont == 1)
        printf("\nER = (E|%s)\n\n", copia->D->le);
    
    if(cont == 0)
        printf("\nER = %s\n\n", copia->D->le);

    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao para verificar os estados */
bool verifica(t_quintupla **cabeca, int i)
{
    t_quintupla *copia = *cabeca;
    t_lef *copia_f = copia -> F;

    if(i == copia->S)  /*  i recebido como argumento igual ao valor do estado inicial apontado por copia no primeiro nodo da lista */
        return true;  /* retornar verdadeiro */
    
    while(copia_f != NULL)
    {
        if(i == copia_f -> f)  /* valor apontado por copia_f número do estado final igual a estado final e diferente de NULL */
            return true;  /* retornar verdadeiro */
       
        copia_f = copia_f -> prox;  /* apontar para o proximo item da lista */
    }
    
    return false;
}

/* ---------------------------------------------------------------------- */
/* Funcao que libera memoria dos ponteiros alocados */
void libera_memoria(t_quintupla **cabeca)
{
    t_delta *del = (*cabeca) -> D;
    t_delta *ant_del = NULL;
    t_lef *end = (*cabeca) -> F;
    t_lef *atende = NULL;

    while(end != NULL) /* liberando estados finais da memoria */
    {
        atende = end; /* atende recebe o valor apontado por end */
        end = end->prox; /* end aponta para o proximo item da lista */

        free(atende); /* libera memoria de atende */
    }

    while(del != NULL) /* liberando funcao delta da memoria */
    {
        ant_del = del; /* ant_del recebe o valor apontado por del */
        del = del -> prox; /* aponta para o proximo item da lista */

        free(ant_del -> le); /* libera memoria de le e ant_del */
        free(ant_del);
    }

    return;
}

/* ---------------------------------------------------------------------- */
/*
 *
 * @ se nao existir parenteses nem em le1 nem em le2 --> adiciona parentesis no inicio, pipe no meio e parentesis final
 * @@ se existir um parentesis inicial no le2 e nao no l1 --> parentesis inicial do le2 é retirado e eh adicionado o pipe no meio
 * @@@ se existir parentesis inicial no le1 e não no le2 --> substitui-se o parentesis final de le1 pelo pipe e no final da string adiciona-se um ')'
 * @@@@ se existir tanto parentesis em l1 inicial e le2 final --> retira-se parentesis final de l1 e inicial de l2
 *
 */
/* Funcao que organiza a expressao regular para o pipe */
char *verificar_pp_le(char *le1, char *le2)
{
    char l1[SBUFF];
    char l2[SBUFF];
    strcpy(l1, le1);  /*copiando o ponteiro de char para uma string */
    strcpy(l2, le2);  /*copiando o ponteiro de char para uma string */
    char *aux3 = malloc(100 * sizeof(char));  /* alocacao de memoria */

    /* verificar se existe parentesis inicial no le1 e nao existe parentesis inicial le2 */
    if(l1[0] == '(' && l2[0] != '(')
    {
        l1[strlen(l1) - 1] =  '|';
        l2[strlen(l2)] = ')';
        l2[strlen(l2) + 1] = '\0';
        strcat(l1, l2);
        strcpy(aux3, l1);
        return aux3;
    }
    /* verificar se le1 tem parentesis inicial */
    if(l1[0] == '(' &&  l1[strlen(l1) - 1] != ')' && l2[0] != '(' && l2[strlen(l2) - 1] != ')')
    {
        l1[strlen(l1) - 1] =  '\0';
        l2[0] = '|';
        strcat(l1, l2);
        strcpy(aux3, l1);
        return aux3;

    }
    /* verificar se le1 nao comeca com perentesis mas o le2 comeca  */
    if(l1[0] != '('  && l2[0] == '(')
    {
        l2[0] = '|';
        sprintf(aux3, "(%s%s", l1, l2);
        return aux3;
    }
    /* se nao existir nao parentesis inicial  em l1 e le2 ---> a + b -> (a|b) */
    
    else
    {
    	sprintf(aux3, "(%s|%s)", l1, l2);
    }
    
    return aux3;
}

/* ---------------------------------------------------------------------- */
/* apenas "*" quando inicial e final forem "(" e ")", respectivamente e tbm n tem outros parenteses no meio
   ex1: a.b.(a|b) --> (a.b.(a|b))*
   ex2: (a|b).(a|c) --> ((a|b).(a|c))*
   ex3:       (a|b) --> (a|b)*  -->so adiciona o *
   ex4:  a          --> a */
/* Funcao que verifica e organiza a expressao regular de acordo com a estrela de kleene */
char *verificar_kl_le(char *le)
{
    char aux6[SBUFF];
    char *aux2 = malloc(100 * sizeof(char));  /* alocacao de memoria para o ponteiro que sera retornado como parametro da funcao */
    strcpy(aux6, le);  /*copiando o ponteiro de char para uma string */
    int x = strlen(aux6);

    /* se so tiver 1 elemento no delta->le */
    if(strlen(aux6)  == 1)
    {
        strcat(aux6, "*");
        strcpy(aux2, aux6);
        return aux2;
    }
    /* se tiver mais de um elemento no delta->le */
    if(aux6[0] == '(' && aux6[strlen(aux6) - 1] == ')')
    {
        for(int j = 1; j < x - 2; j++)
        
            if(aux6[j] == '(' || aux6[j] == ')')
            {
                sprintf(aux2, "(%s)*", aux6);
                return aux2;
            }

        strcat(aux6, "*");  /* concatenando string com o "*" */
        strcpy(aux2, aux6);  /* copiando string para um ponteiroa  ser retornado */
        return aux2;
    }

    else
        sprintf(aux2, "(%s)*", aux6);

    return aux2;  /* retorno do ponteiro do tipo char */
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "auto2", VERSION, "Conversão de AFD para ER");
    printf("\nUsage: %s [-h|-v|-c]\n", "auto2");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-d, \n\t\tRemete a traducao do AFD para ER.\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    printf("\n\nNote (-d): input data is an DFA (Deterministic Finite Automata) 5-tuple to be converted to RE (Regular Expression) string.\n");
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthors:\n\tWritten by %s <%s>\n", "Ruben Carlo Benante", "rcb@beco.cc");
    printf("                   Alanne Carvalho De Paula\n");
    printf("                   Arthur Bezerra Oliveira\n");
    printf("                   Bernardo Lima Milhomens Salomoni\n");
    printf("                   Bruno Alcantara Dias Rodrigues\n");
    printf("                   Camila Povoas Tavares\n");
    printf("                   Giovani Maciel Filho\n");
    printf("                   Matheus Barbosa Lebre Alves\n");
    printf("                   Matheus Henrique De Arruda\n");
    printf("                   Ricardo Giuseppe De Medeiros Fiorentino\n");
    printf("                   Vitoria Manuela Da Silva\n");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto2", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2022, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

