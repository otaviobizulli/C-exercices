#include <stdio.h>
#include <stdlib.h>

struct no_arvore {
    no_arvore *esq;
	int info;
    no_arvore *dir;
};


no_arvore* inserirArvore(no_arvore* raiz, int v) {
    if (raiz == NULL) {
        no_arvore *a = new no_arvore;
    	a->info = v;
    	a->esq = NULL;
    	a->dir = NULL;
    	return a;
    } 
	else 
	{
        if (raiz->esq == NULL)
            raiz->esq = inserirArvore(raiz->esq, v);
		else 
            raiz->dir = inserirArvore(raiz->dir, v);
        return raiz;
    }
}

void inorder(no_arvore* raiz) {
    if (raiz != NULL) {
        inorder(raiz->esq);
        printf("%d ", raiz->info);
        inorder(raiz->dir);
    }
}

void preorder(no_arvore* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void posorder(no_arvore* raiz) {
    if (raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("%d ", raiz->info);
    }
}

main() {
    no_arvore* arvore = NULL;
    int num;
    
    for (int i=0; i<10; i++)
    {
    	num = rand() % 20 + 1;
    	arvore = inserirArvore(arvore, num);
	}
    /*
    do {
        printf("Digite um numero (ou -1 para sair): ");
        scanf("%d", &num);
        if (num != -1) {
            arvore = inserirArvore(arvore, num);
        }
    } while (num != -1);*/
    
    printf("Arvore binaria In_Order: ");
    inorder(arvore);
    printf("\n");
    printf("Arvore binaria Pre_Order: ");
    preorder(arvore);
    printf("\n");
    printf("Arvore binaria Pos_Order: ");
    posorder(arvore);
    printf("\n");
}



