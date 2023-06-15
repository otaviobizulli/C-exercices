#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct NO
{
	char nome[50], tipo;
	NO *prox;
};

void Cria_LSE (NO **Inicio)
{
	*Inicio = NULL;
}

void InserirFila (NO **Inicio, char n[50], char t, NO *onde)
{
	NO *p = new NO, *q;
    strcpy(p->nome, n);
    p->tipo = t;
	if (*Inicio == NULL && (p->tipo =='C' || p->tipo =='P'))
	{
		*Inicio = p;
		p->prox = NULL;
		printf("\nInsercao efetuada!!\n");
	}
	else
	{
        if (p->tipo == 'C')
        {
            q = *Inicio;
            while (q->prox != NULL)
            {
                q = q->prox;
            }
            q->prox = p;
			p->prox = NULL;
			printf("\nInsercao efetuada!!\n");
        }
        else if (p->tipo == 'P')
        {
            if (*Inicio == onde)
            {
                *Inicio = p;
				p->prox = onde;
				printf("\nInsercao efetuada!!\n");
            }
            else
            {
                q = *Inicio;
                while (q->prox != onde)
                {
                    q = q->prox;
                }
                q->prox = p;
				p->prox = onde;
				printf("\nInsercao efetuada!!\n");
            }
        }
		else
			printf("\nTipo Invalido.\n");
	}
}

NO *Acesso(NO *Inicio, char n[50], char t)
{
    NO *p = Inicio;
    while (p != NULL)
    {
        if (p->tipo == 'C')
        {
            return p;
        }
        p = p->prox;
    }
    return NULL;
}

void Imprime (NO *Inicio)
{
  	NO *p = Inicio;
	while (p != NULL)
  	{
      	printf ("(%s|%c) -> ", p->nome, p->tipo);
		p = p->prox;
  	}
  	printf("NULL\n\n");
}

int main()
{
	NO *Fila, *onde;
	int op;
	char nome[50], tipo;
	Cria_LSE(&Fila);
	do
	{
		system("cls");
		printf("\nMENU DE OPCOES\n");
		printf("\n1 - Inserir na Fila");
		printf("\n2 - Listar a Fila");
		printf("\n0 - Sair");
		printf("\n\nOpcao => ");
		fflush(stdin);
		scanf("%d",&op);

	   	switch (op)
	   	{
			case 1:
                    printf("Insira o nome: ");
                    fflush(stdin);
					gets(nome);
                    printf("Insira o tipo [P/C]: ");
                    fflush(stdin);
                    scanf("%c",&tipo);
					tipo = toupper(tipo);
                    onde = Acesso(Fila, nome, tipo);
					InserirFila(&Fila, nome, tipo, onde);
					system("pause");
				    break;

			case 2:
                    Imprime(Fila);
                    system("pause");
				    break;

			case 0: printf("\nFIM DE PROGRAMA\n");
			        break;

			default: printf("\nOpcao invalida!!\n\n");
			         system("pause");
	    }
	} while (op != 0);

}
