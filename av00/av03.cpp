#include <stdio.h>
#include <time.h>
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

void Ins_Fim (NO **Inicio, NO **Fim, int v)
{
	NO *p = new NO;
	p->info = v;
	p->esq = *Fim;
	p->dir = NULL;
	if (*Inicio == NULL)
	    *Inicio = p;
	else
	    (*Fim)->dir = p;
	*Fim = p;
}

void SepararLista(NO **Inicio, NO **InicioImpar, NO **FimPar)
{
    NO *p;
	p = *Inicio;
    while (p->info % 2 == 0)
    {
        p = p->dir;
    }
    *InicioImpar = p;
    *FimPar = p->esq;
    p->esq = NULL;
    (*FimPar)->dir = NULL;
}

int main()
{
    NO *FimPar, *InicioImpar,*Inicio, *Fim;
    int alea;
    Cria_LDE(&Inicio, &Fim);
    srand(time(NULL));
    for (int i=0; i<20; i++)
    {  
        alea = (rand() % 99+1);
        if (alea % 2 == 0)
            Ins_Inicio(&Inicio, &Fim, alea);
        else
            Ins_Fim(&Inicio, &Fim, alea);
    }
    Imprime(Inicio);
    SepararLista(&Inicio, &InicioImpar, &FimPar);
    Imprime(Inicio);
    Imprime(InicioImpar);
} 