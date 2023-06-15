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

void Ins_Inicio (NO **Inicio, int v)
{
	NO *p = new NO;
    p->info = v;
	p->prox = *Inicio;
	*Inicio = p;
}

void Ins_Fim (NO **Inicio, int v)
{
	NO *p = new NO, *q;
    p->info = v;
	p->prox = NULL;
	if (*Inicio == NULL)
		*Inicio = p;
	else
	{
		q = *Inicio;
		while (q->prox != NULL)
			q = q->prox;
		q->prox = p;	
	}
}

int Rem_Inicio(NO **Inicio, int *v)
{
	NO *p;
	if (*Inicio == NULL)
		return 0;
	p=*Inicio;
	*Inicio=p->prox;
	*v=p->info;
	delete (p);
	return 1;
}

int Rem_Fim(NO **Inicio, int *v)
{
	NO *p, *q;
	if (*Inicio == NULL)
		return 0;
	p=*Inicio;
	if (p->prox == NULL)
		*Inicio = NULL;
	else
	{
		while (p->prox != NULL)
		{
			q = p;
			p = p->prox;
		}
		q->prox = NULL;
	}
	*v = p->info;
	delete(p);
	return 1;
}

void Rem_Onde(NO **Inicio, NO *onde)
{
	NO *p;
	if (onde == *Inicio)
		*Inicio = onde->prox;
	else
	{
		p = *Inicio;
		while (p->prox != onde)
			p = p->prox;
		p->prox = onde->prox;
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
		p = p->prox;
	}
	return NULL;
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
  	printf ("NULL\n\n");
}

main()
{
	NO *L, *onde;
	int op, valor;
	Cria_LSE(&L);
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
					Ins_Inicio(&L, valor);
					printf("\nInsercao efetuada!!\n");
					system("pause");
				    break;
				    
			case 2: printf("Inserir qual valor? -> ");
					scanf("%d", &valor);
					Ins_Fim(&L, valor);
					printf("\nInsercao efetuada!!\n");
					system("pause");
				    break;
				    
			case 3: if (Rem_Inicio(&L, &valor)==0)
			 			printf("\nLista vazia!! Impossivel remover\n");
		      	  	else
			 			printf("\nRemocao com sucesso!!\nValor removido => %d\n",valor);
		      		system("pause");
		      		break;
		      		
		    case 4: if (Rem_Fim(&L, &valor)==0)
			 			printf("\nLista vazia!! Impossivel remover\n");
		      	  	else
			 			printf("\nRemocao com sucesso!!\nValor removido => %d\n",valor);
		      		system("pause");
		      		break;
		      		
		    case 5: printf("Deseja remover qual valor? -> ");
					scanf("%d", &valor);
					onde = Acesso(L, valor);
					if (onde == NULL)
						printf("\nValor nao encontrado!!\n");
					else
					{
					 	Rem_Onde(&L, onde);
					 	printf("\nRemocao com sucesso!!\n");
					}
					system("pause");
				    break;
			
			case 8: printf("Procura qual valor? -> ");
					scanf("%d", &valor);
					if (Acesso(L, valor) == NULL)
						printf("\nValor nao encontrado!!\n");
					else
					 	printf("\nValor encontrado!!\n");
					system("pause");
				    break;
				    
			case 9: Imprime(L);
					system("pause");
				    break;
			
			case 10: printf("\nFIM DE PROGRAMA");
			         break;
			
			default: printf("\nOpcao invalida!!\n\n");
			         system("pause");
	   	}	    
	} while (op != 10);
		
}