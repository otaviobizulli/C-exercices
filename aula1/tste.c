/*Fazer um programa em C para criar o jogo Papel, Pedra e Tesoura.​

O usuário poderá escolher entre papel, pedra e tesoura e jogará contra o computador,
o qual aleatoriamente gerará um dos três. O melhor de três vence, lembrando que papel ganha de pedra,
que ganha de tesoura, que ganha de papel.​

Obs.: Para gerar um número aleatório, é necessário utilizar as funções srand() e rand().
Para parar a execução por um tempo determinado pode-se utilizar a função system(“pause”) ou sleep().*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int selec, alea, contm, contu;
    contm = 0;
    contu = 0;

    while (contm < 2 && contu < 2){
        printf("Insira: \n0 para PEDRA; \n1 para PAPEL;\n2 para TESOURA.\n\n");
        scanf("%d",&selec);
        srand(time(NULL));
        alea = ("%d ", rand() % 3);
            if (selec == 0){
                if (alea == 0){
                    printf("Empate!\n\n");
                } else if (alea == 1){
                    printf("PAPEL!\nComputador venceu!\n\n");
                    contm++;
                } else if (alea == 2){
                    printf("TESOURA!\nVoce venceu!\n\n");
                    contu++;
            }
          } else if (selec == 1) {
                if (alea == 0) { 
                    printf("PEDRA!\nVoce venceu!\n\n");
                    contu++;
                } else if (alea == 1){
                    printf("Empate!\n\n");
                } else if (alea == 2){
                    printf("TESOURA!\nComputador venceu!\n\n");
                    contm++;
                }
          } else if (selec == 2) {
                if (alea == 0) {
                    printf("PEDRA!\nComputador venceu!\n\n");
                    contm++;
                } else if (alea == 1){
                    printf("PAPEL!\nVoce venceu!\n\n");
                    contu++;
                } else if (alea == 2){
                    printf("Empate!\n\n");
                }
          } else
                printf("Digito Invalido.\n\n");
    }
printf("PLACAR FINAL: USUARIO %i x %i MAQUINA",contu,contm);
}