#include <stdio.h>
#include <stdlib.h>
#define tam 100

struct PILHA
{
  int topo;
  int info[tam]; 
};


void inicializa (PILHA *p)
{
	p->topo=-1;
}

int cheia (PILHA *p)
{
	return (p->topo==tam-1);
}

int vazia(PILHA *p)
{
	return (p->topo==-1);
}

int push (PILHA *p, int v)
{
   	if (cheia(p))
	  	return 0; // pilha cheia
   	p->info[++p->topo]=v;
   	return 1;
}

int pop (PILHA *p, int *v)
{
   	if (vazia(p))
	  	return 0;  // pilha vazia
   	*v = p->info[p->topo--];
   	return 1;
}


main()
{
	PILHA restos;
	int retorno = -1, decimal, binario = 0, dec, bin;
	inicializa(&restos);
	printf("Informe um numero -> ");
	scanf("%d", &decimal);
	dec = decimal;
	while (dec > 0)
	{
		push(&restos, dec % 2);
		dec /= 2;
	}
	
	while (retorno != 0)
	{
		retorno = pop(&restos, &bin);
		if (retorno != 0)
		{
			binario *= 10; 
			binario += bin; 
		}
	}
	printf("\n\n%d em binario eh -> %d", decimal, binario);
}
