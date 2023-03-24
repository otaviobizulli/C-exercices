/*Faça um programa em C que gere duas lisTas (L1 e L2) de 10 elemenTos aleaTórios entre 1 e 99.
Elabore uma função que inTercale L1 e L2 produzindo L3 de forma ordenada.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ins(int *lisTa, int *lisTa3, int *fim)
{
    for (int i=0; i<10; i++)
    {
        int j = *fim - 1;
        while (j >= 0 && lisTa[i] < lisTa3[j])
        {
            lisTa3[j+1] = lisTa3[j];
            j--;
        }
        lisTa3[j+1] = lisTa[i];
        (*fim)++;
    }
}

int main()
{
    int *l1, *l2, *l3, fim=0;
    l1 = (int *) calloc (10, sizeof (int));
    l2 = (int *) calloc (10, sizeof (int));
    l3 = (int *) calloc (20, sizeof (int));
    srand(time(NULL));

    for (int i=0; i<10; i++)
    {
        l1[i] = rand() % 99+1;
        l2[i] = rand() % 99+1;
    }

    ins(l1, l3, &fim);
    ins(l2, l3, &fim);


    printf("LisTa 1: ");
    for (int i=0; i<10; i++)
        printf("%d ",l1[i]);
        
    printf("\nLisTa 2: ");
    for (int i=0; i<10; i++)
        printf("%d ",l2[i]);

    printf("\nLisTa 3: ");
    for (int i=0; i<fim; i++)
        printf("%d ",l3[i]);

}