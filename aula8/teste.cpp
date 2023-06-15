#include <stdio.h>
#include <stdlib.h>
struct NO
{
	NO *esq;
	int info;
	NO *dir;
};
 

void Cria_LDE (NO **Inicio, NO **Fim)
{
	*Inicio=NULL;
	*Fim = NULL;
}

void Ins_Inicio (NO **Inicio, NO **Fim, int v)
{
	NO *p = new NO;
	p->info = v;
	p->esq = NULL;
	p->dir = *Inicio;
	if (*Inicio == NULL)
	    *Fim = p;
	else
	    (*Inicio)->esq = p;
	*Inicio = p;
}

void Rem_Onde(NO **Inicio, NO **Fim, NO *onde)
{
	NO *p, *q;
	if (onde == *Inicio)
	{
		if (onde == *Fim)
        {
			*Inicio = NULL;
			*Fim = NULL;
		}
        else
        {
			*Inicio = (*Inicio)->dir;
			(*Inicio)->esq = NULL;
		}
	}
    else if (onde == *Fim)
	{
		*Fim = (*Fim)->esq;
		(*Fim)->dir = NULL;
	}
	else
	{
		p = onde->esq;
		q = onde->dir;
		p->dir = q;
		q->esq = p;
	}
	delete(onde);
}


NO *Acesso(NO *Inicio, NO* Fim, int v)
{
	NO *p, *q;
	p = Inicio;
	q = Fim;
	if (p->dir == NULL && q->esq == NULL && p->info == v && q->info == v)
		return p;
	else
	{
		while (p->dir != NULL || q->esq != NULL)
		{
			if (p->info == v)
				return p;
			if (q->info == v)
				return q;
			p = p->dir;
			q = q->esq;
		}
	}
	return NULL;
} 

void Imprime (NO *Inicio)
{
    NO *p;
	p = Inicio;
	printf("NULL");
	while (p!=NULL)
	{
		printf(" <-%d-> ", p->info);
	    p = p->dir;
	}
	printf("NULL\n\n");
}

main()
{
	NO *Inicio, *Fim, *onde;
	int op, valor;
	Cria_LDE(&Inicio, &Fim);
	Ins_Inicio(&Inicio, &Fim, 4);
	Ins_Inicio(&Inicio, &Fim, 3);
	Ins_Inicio(&Inicio, &Fim, 2);
	Ins_Inicio(&Inicio, &Fim, 1);
	Imprime(Inicio);	

	printf("Deseja remover qual valor? -> ");
	scanf("%d", &valor);
	onde = Acesso(Inicio, Fim, valor);
	if (onde == NULL)
		printf("\nValor nao encontrado!!\n");
	else
	{
		Rem_Onde(&Inicio, &Fim, onde);
		printf("\nRemocao com sucesso!!\n");
	}
	Imprime(Inicio);
}

