#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, s, heron;

    printf("Insira o lado A de um triangulo: ");
    scanf("%f",&a);
    printf("Insira o lado B de um triangulo: ");
    scanf("%f",&b);
    printf("Insira o lado C de um triangulo: ");
    scanf("%f",&c);

    s = (a + b + c)/2;
    heron = sqrt(s*(s-a)*(s-b)*(s-c));

    if (a == b && a == c && b == c){
        printf("\nTriangulo Equilatero!\n");
    } else if (a != b && a != c && b != c){
        printf("\nTriangulo Escaleno!\n");
    } else{
        printf("\nTriangulo Isosceles!\n");
    }
    printf("E a area do triangulo eh: %.2f",heron);
}