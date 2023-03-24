#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alea, chute, cont, contf;
	srand(time(NULL));
	alea = ("%d ", rand() % 101);
	cont = 0;
    printf("Qual o numero magico? \n");
    while (chute != alea)
	{
    	cont++;
		scanf("%d",&chute);
    	if (chute > alea)
    		printf("O numero magico eh menor... \n\n");
		else
			if (chute < alea)
	    		printf("O numero magico eh maior... \n\n");
	}
printf("Parabens! o numero magico era %d. ",alea);

if (cont <= 3)
	printf("Voce eh muito sortudo! Apenas %d tentativas!",cont);
if (cont >= 4 && cont <= 6)
	printf("Voce eh sortudo! %d tentativas!",cont);	
if (cont >= 7 && cont < 10)
	printf("Voce foi normal. %d tentativas.",cont);
if (cont > 10)
	printf("Mas %d tentativas... Tente novamente!",cont);
}
