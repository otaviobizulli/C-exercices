#include <stdio.h>
#include <stdlib.h>
struct NO
{
	int info;
	NO *prox;
};
 

void Cria_LSE (NO **Inicio)
{
	*Inicio=NULL;
}

void Ins_Inicio (NO ** Inicio, int v)
{
	NO *p = (NO *)calloc (1, sizeof(NO));
    p->info = v;
	p->prox = *Inicio;
	*Inicio = p;
}

void Imprime (NO *Inicio)
{
  	NO *p;
	p = Inicio;
	while (p != NULL) 
  	{
      	printf ("%d -> ", p->info);
		p = p->prox;  
  	}
  	printf ("NULL\n");
}

void ins_fim (NO **Inicio, int v)
{
    NO *p = (NO *)calloc (1, sizeof(NO));
    p->info = v;
    p->prox = NULL;
    NO *q;
	q = *Inicio;
    while (q->prox != NULL)
        q = q->prox;
    q->prox = p;

}

NO *buscar (NO *Inicio, int v)
{
	NO *p;
	p = Inicio;
	while (p != NULL)
	{
		if (p->info == v)
			return p;
		p = p->prox;
	}
	return NULL;
}

main()
{
	NO *L;
	Cria_LSE(&L);
	Ins_Inicio(&L, 8);
	Ins_Inicio(&L, 15);
	Ins_Inicio(&L, 30);
	Ins_Inicio(&L, 5);
    ins_fim(&L, 44);
	Imprime(L);
	if (buscar(L, 29) != NULL) 
		printf("O valor esta na lista.");
	else
		printf("O valor nao esta na lista.");
}

