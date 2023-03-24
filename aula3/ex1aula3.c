#include <stdio.h>
#include <stdlib.h>

/*1.Escreva um programa em C que contenha uma função para preencher N elementos de um vetor alocado
dinamicamente e uma função que recebe um vetor de inteiros de qualquer tamanho e informe  se  os
elementos  do  array  estão  classificados  em  ordem  crescente,  ou  seja,  ordenados do menor
para o maior. A função deverá retornar um valor verdadeiro (1)ou falso (0).*/

void elements(int *lista, int tam)
{
	for (int i=0; i<tam; i++)
	{
		printf("%d%c elemento: ",(i+1),167);
		scanf("%d",&lista[i]);
	}
}

int arraycrec(int *lista, int tam)
{
	for (int i=1; i<tam; i++)
	{
		if (lista[i] < lista[i-1])
			return 0;
    }
    return 1;
}

main()
{
	int N, *p, cresc;
	printf("Informe a quantidade de elementos da lista: ");
	scanf("%d", &N);
	p = (int *) calloc (N, sizeof (int));
	elements(p, N);
    cresc = arraycrec(p, N);
    printf("%d", cresc);
}