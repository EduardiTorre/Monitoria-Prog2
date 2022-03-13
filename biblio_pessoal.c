/* ************************************************************************ *
 *    ex2.c, VERSION 1                                                      *
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
 * Compilação:
 * gcc ex2.c -o ex2.x -Wall -Wextra
 *
 * 
 * verifique os arquivos libjeoc.h e libjeoc.c
 */

/* ---------- includes ---------- */
#include "libjeoc.h"

/* ---------- programa ---------- */
int main(void){
	/* ---------- variaveis ---------- */
	int num1;
	int num2;
	int soma;

	printf("Dois numeros para somar: "); // print no terminal bla bla bla
	scanf("%i", &num1); // escaneia variavel do terminal bla bla bla
	scanf("%i", &num2);

	/* ---------- executando funcao ---------- */
	soma = soma_dois(num1, num2);

	printf("Soma: %i\n", soma);

	return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
