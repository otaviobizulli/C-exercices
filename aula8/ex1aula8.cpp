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

int Rem_Inicio(NO **Inicio, NO **Fim, int *v)
{
	NO *p;
	if (*Inicio!=NULL)
	{
		p = *Inicio;
		*Inicio = p->dir;
		if (p->dir == NULL)  // só existe 1 nó na lista
		    *Fim=NULL;
		else
		    (*Inicio)->esq = NULL;
		*v = p->info;
		delete(p);
		return 1;
	}
	else 
		return 0;
}

int Rem_Fim(NO **Inicio, NO **Fim, int *v)
{
	NO *p;
	if (*Inicio != NULL)
	{
		p = *Fim;
		*Fim = p->esq;
		if (p->esq == NULL)  // só existe 1 nó na lista
		    *Inicio=NULL;
		else
		    (*Fim)->dir=NULL;
		*v=p->info;
		delete(p);
		return 1;
	}
	else 
		return 0;
}

void Rem_Onde(NO **Inicio, NO **Fim, NO *onde)
{
	NO *p;
	if (onde == *Inicio && onde == *Fim)
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
		if (onde == *Inicio)
		{
			*Inicio = onde->dir;
			(*Inicio)->esq = NULL;
		}
		else
			if (onde == *Fim)
			{
				*Fim = onde->esq;
				(*Fim)->dir = NULL;
			}
			else
			{
				onde->esq->dir = onde->dir;
				onde->dir->esq = onde->esq;
			}
	delete(onde);
}

NO *Acesso(NO *Inicio, int v)
{
	NO *p;
	p = Inicio;
	while (p != NULL)
	{
		if (p->info == v)
			return p;
		p = p->dir;
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
	do
	{
		system("cls");
		printf("\nMENU DE OPCOES\n");
		printf("\n01 - Inserir no inicio");
		printf("\n02 - Inserir no fim");
		printf("\n03 - Remover no inicio");
		printf("\n04 - Remover no fim");
		printf("\n05 - Remover no acessado");
		printf("\n08 - Acessar");
		printf("\n09 - Listar");
		printf("\n10 - Sair");
		printf("\n\nOpcao => ");
		fflush(stdin);
		scanf("%d",&op);
	   
	   	switch (op)
	   	{
			case 1: printf("Inserir qual valor? -> ");
					scanf("%d", &valor);
					Ins_Inicio(&Inicio, &Fim, valor);
					printf("\nInsercao efetuada!!\n");
					system("pause");
				    break;
				    
			case 2: printf("Inserir qual valor? -> ");
					scanf("%d", &valor);
					Ins_Fim(&Inicio, &Fim, valor);
					printf("\nInsercao efetuada!!\n");
					system("pause");
				    break;
				    
			case 3: if (Rem_Inicio(&Inicio, &Fim, &valor)==0)
			 			printf("\nLista vazia!! Impossivel remover\n");
		      	  	else
			 			printf("\nRemocao com sucesso!!\nValor removido => %d\n",valor);
		      		system("pause");
		      		break;
		      		
		    case 4: if (Rem_Fim(&Inicio, &Fim, &valor)==0)
			 			printf("\nLista vazia!! Impossivel remover\n");
		      	  	else
			 			printf("\nRemocao com sucesso!!\nValor removido => %d\n",valor);
		      		system("pause");
		      		break;
		      		
		    case 5: printf("Deseja remover qual valor? -> ");
					scanf("%d", &valor);
					onde = Acesso(Inicio, valor);
					if (onde == NULL)
						printf("\nValor nao encontrado!!\n");
					else
					{
					 	Rem_Onde(&Inicio, &Fim, onde);
					 	printf("\nRemocao com sucesso!!\n");
					}
					system("pause");
				    break;
			
			case 8: printf("Procura qual valor? -> ");
					scanf("%d", &valor);
					if (Acesso(Inicio, valor) == NULL)
						printf("\nValor nao encontrado!!\n");
					else
					 	printf("\nValor encontrado!!\n");
					system("pause");
				    break;
				    
			case 9: Imprime(Inicio);
					system("pause");
				    break;
			
			case 10: printf("\nFIM DE PROGRAMA");
			         break;
			
			default: printf("\nOpcao invalida!!\n\n");
			         system("pause");
	   	}	    
	} while (op != 10);
		
}

