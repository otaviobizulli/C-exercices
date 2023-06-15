#include <stdio.h>
#include <stdlib.h>

struct NO
{
	NO *esq;
	char modelo;
    char cor;
    char placa;
	NO *dir;
};
 

void Cria_LDE (NO **Inicio, NO **Fim)
{
	*Inicio = NULL;
	*Fim = NULL;
}

void Ins_Fim (NO **Inicio, NO **Fim, char model, char color, char plate)
{
	NO *p = new NO;
	p->modelo = model;
	p->cor = color;
	p->placa = plate;
	p->esq = *Fim;
	p->dir = NULL;
	if (*Inicio == NULL)
	    *Inicio = p;
	else
	    (*Fim)->dir = p;
	*Fim = p;
}

int Rem_Fim(NO **Inicio, NO **Fim, char *model, char *color, char *plate)
{
	NO *p;
	if (*Inicio != NULL)
	{
		p = *Fim;
		*Fim = p->esq;
		if (p->esq == NULL)
		    *Inicio=NULL;
		else
		    (*Fim)->dir=NULL;
		delete(p);
		return 1;
	}
	else 
		return 0;
}

/*NO *Acesso(NO *Inicio, int v)
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
}*/

main()
{
	NO *Inicio, *Fim, *onde;
	int op;
	char modelo, cor, placa;
	Cria_LDE(&Inicio, &Fim);
	do
	{
		system("cls");
		printf("\nMENU DE OPCOES\n");
		printf("\n01 - Entrada de veiculo");
		printf("\n02 - Saida de veiculo");
		printf("\n03 - Sair do programa");
		printf("\n\nOpcao => ");
		fflush(stdin);
		scanf("%d",&op);
	   
	   	switch (op)
	   	{
			case 1: printf("Insira o modelo: ");
                    fflush(stdin);
					getchar(modelo);
					printf("Insira a cor: ");
                    fflush(stdin);
					getchar(cor);
					printf("Insira a placa: ");
                    fflush(stdin);
					getchar(placa);
					Ins_Fim(&Inicio, &Fim, modelo, cor, placa);
					printf("\nInsercao efetuada!!\n");
					system("pause");
				    break;
				    
			case 2: if (Rem_Fim(&Inicio, &Fim, &modelo, &cor, &placa)==0)
			 			printf("\nLista vazia! Impossivel remover.\n");
		      	  	else
			 			printf("\nRemocao com sucesso!\nCarro removido => %s %s, placa %s\n",modelo,cor,placa);
		      		system("pause");
		      		break;

			case 3: printf("\nFIM DE PROGRAMA");
			         break;
			
			default: printf("\nOpcao invalida.\n\n");
			         system("pause");
	   	}	    
	} while (op != 3);
		
}

