#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define tam 100

struct PILHA
{
  int topo;
  char info[tam]; 
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

int push (PILHA *p, char v)
{
   	if (cheia(p))
	  	return 0; // pilha cheia
   	p->info[++p->topo]=v;
   	return 1;
}

int pop (PILHA *p, char *v)
{
   	if (vazia(p))
	  	return 0;  // pilha vazia
   	*v = p->info[p->topo--];
   	return 1;
}

main()
{
	PILHA p;
	char palavra[100], inversa[100], x;
	int i;
	inicializa(&p);
	printf("Informe uma palavra -> ");
	fflush(stdin);
	gets(palavra);
	for (i=0; i<strlen(palavra); i++)
	{
		palavra[i] = toupper(palavra[i]);
		push(&p,palavra[i]);
	}
	
	for (i=0; i<strlen(palavra); i++)
	{
		pop(&p, &x);
		inversa[i] = x;
	}
	inversa[i] = '\0';
	printf("%s - %s", palavra, inversa);
	if (strcmp(palavra,inversa) == 0)
		printf("\nEh uma palavra palindrome");
	else
		printf("\nNao eh uma palavra palindrome");
}
