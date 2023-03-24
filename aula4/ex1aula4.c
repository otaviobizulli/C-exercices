#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void inserirFim(int *lista, int *fim)
{
	int valor;
	printf("\nInforme um valor -> ");
	scanf("%d", &valor);
	lista[*fim] = valor;
	(*fim)++;
	printf("\nInsercao efetuada!!");
}

void inserirPos(int *lista, int *fim, int k)
{
	int valor;
	printf("\nInforme um valor -> ");
	scanf("%d", &valor);
	for (int i=*fim; i>k; i--)
		lista[i] = lista[i-1];	
	lista[k] = valor;
	(*fim)++;
	printf("\nInsercao efetuada!!");
}

void removerFim(int *lista, int *fim)
{
	printf("\nValor removido -> %d", lista[(*fim)-1]);
	(*fim)--;
	printf("\nRemocao efetuada!!");
}

void removerPos(int *lista, int *fim, int k)
{
	printf("\nValor removido -> %d", lista[k]);
	for (int i=k; i<*fim; i++)
		lista[i] = lista[i+1];	
	(*fim)--;
	printf("\nRemocao efetuada!!");
}

void consultar(int *lista, int fim)
{
	int valor, i;
	printf("\nInforme um valor para consulta -> ");
	scanf("%d", &valor);
	for (i=0; i<fim; i++)
	{
		if (lista[i] == valor)
		{
			printf("\nValor esta na lista!!");
			break;
		}
	}
	if (i==fim)
		printf("\nValor nao esta na lista!!");
}

void listar(int *lista, int fim)
{
	printf("\nLista de valores -> ");
	for (int i=0; i<fim; i++)
		printf("%d ", lista[i]);
}

main()
{
	int op, *p, tam, fim = 0, k;
	printf("\nInforme o tamanho maximo da lista >> ");
	scanf("%d",&tam);
	p = (int *) calloc (tam, sizeof (int));
	while (1)
	{
		system("cls");
		printf("\nMenu de opcoes\n");
		printf("\n1. Inserir no fim");
		printf("\n2. Mostrar a lista");
		printf("\n3. Inserir em uma determinada posicao");
		printf("\n4. Consultar");
		printf("\n5. Remover no fim");
		printf("\n6. Remover uma determinada posicao");
		printf("\n0. Encerrar");
		printf("\n\nOpcao -> ");
		scanf("%d", &op);
		switch (op)
		{
			case 0: printf("\nFIM");
			        break;
			case 1: if (fim == tam)
						printf("\nLista cheia!!");
					else
						inserirFim(p, &fim);
			        break;
			case 2: if (fim == 0)
						printf("\nLista vazia!!");
					else
						listar(p, fim);
					break;
			case 3: if (fim == tam)
						printf("\nLista cheia!!");
					else
					{
						printf("Informe a posicao que deseja inserir -> ");
						scanf("%d", &k);
						if (k < 0 || k > fim)
						   printf("\nPosicao invalida!!");
						else
							inserirPos(p, &fim, k);
					}
					break;
			case 4: if (fim == 0)
						printf("\nLista vazia!!");
					else
						consultar(p, fim);
					break;
			case 5: if (fim == 0)
						printf("\nLista vazia!!");
					else
						removerFim(p, &fim);
					break;
			case 6: if (fim == 0)
						printf("\nLista vazia!!");
					else
					{
						printf("Informe a posicao que deseja remover -> ");
						scanf("%d", &k);
						if (k < 0 || k >= fim)
						   printf("\nPosicao invalida!!");
						else
							removerPos(p, &fim, k);
					}
					break;
		}
		if (op == 0)
			break;
		else
		{
			printf("\n\n");
			system("pause");	
		}
	}
}
