#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 10

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
	PILHA p;
	int i, x;
	srand(time(NULL));
	inicializa(&p);
	printf("Elementos empilhados    -> ");
	for (i=0; i<tam; i++)
	{
		x = rand() % 50 + 1;
		push(&p,x);
		printf("%d ",x);
	}
	printf("\n\nElementos desempilhados -> ");
	for (i=0; i<tam; i++)
	{
		pop(&p, &x);
		printf("%d ",x);
	}
}
