#include <stdio.h>

int r;
int *p1;

int dobro(int x)
{
    p1 = 2*x;
}

main()
{
    int a;
        printf("Digite um numero: ");
        scanf ("%d", &a);
        r = dobro(a);
        printf("O dobro de %d = %d",a,r);
}

