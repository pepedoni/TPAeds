#include <stdio.h>
#include <stdlib.h>
#include "maquina.h"

int escolheJogador() {
    int opcao = 0;
    system("cls");
    do{
        printf("Quem irá jogar?\n");
        printf("1 - Humano \n");
        printf("2 - Maquina Força Bruta \n");
        //printf("3 - Maquina Inteligente \n");
        scanf("%d", &opcao);
        if(opcao != 1 && opcao != 2 ) printf("Opcaoo inválida! Tente Novamente!\n");
    }while(opcao != 1 && opcao != 2 );
    return opcao;
}

