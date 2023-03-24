#include <stdio.h>

int main(){
    int n, cont, a, b;
    cont = 0;
    b = 0;

    printf("Insira o tamanho da lista: ");
    scanf("%d",&n);

    while (cont != n){
        printf("Insira um valor: ");
        scanf("%d",&a);
        cont++;
        if (a < b){
            printf("Ordem nao crescente.");
            break;
        } else
            b = a;
        }
}