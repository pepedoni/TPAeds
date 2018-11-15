#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

#define FACIL       1
#define MEDIO       2
#define DIFICIL     3
#define TESTE       4
#define INVALIDO    0
#define VALIDO      1

void geraCabecalho(int nivel, int* senha){
    system("cls");
    switch(nivel) {
        case FACIL:
            printf("Nivel Escolhido: Fácil");
            break;
        case MEDIO:
            printf("Nivel Escolhido: Médio");
            break;
        case DIFICIL:
            printf("Nivel Escolhido: Díficil");
            break;
        case TESTE:
            printf("Nivel Escolhido: Teste\n");
            printf("Senha: ");
            for(int i = 0; i < 4; i++) {
                printf("%d", senha[i]);
            }
            break;
    }

}

void tentativaSenha(nivel, numDigitos, senha) {
    int tentativa[numDigitos];
    for(int j = 0; j < numDigitos; j++) {
        num = (int) getche() - 48;
        if(num < 0 || num > 10) tentativaInvalida = INVALIDO;
        tentativa[j] = (int) getche() - 48;
    }
    for(int i = 0; i < numDigitos; i++) {
        printf("%d", tentativa[i]);
    }
}

void geraJogo(int nivel, int numDigitos, int senha) {
    geraCabecalho(nivel, senha);
    printf("\n");
    printf("Descubra a senha \n");
    tentativaSenha(nivel, numDigitos, senha);
}
