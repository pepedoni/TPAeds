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
            printf("Numero de Digitos: 3");
            printf("Algarismos de 0 a 4 que não se repetem!!!");
            break;
        case MEDIO:
            printf("Nivel Escolhido: Médio");
            printf("Numero de Digitos: 4");
            printf("Algarismos de 0 a 5 que podem repetir!!!");
            break;
        case DIFICIL:
            printf("Nivel Escolhido: Díficil");
            printf("Numero de Digitos: 4");
            printf("Algarismos de 0 a 9 que podem repetir!!!");
            break;
        case TESTE:
            printf("Nivel Escolhido: Teste\n");
            printf("Numero de Digitos: 4");
            printf("Algarismos de 0 a 9 que podem repetir!!!");
            printf("Senha: ");
            for(int i = 0; i < 4; i++) {
                printf("%d", senha[i]);
            }
            break;
    }

}

void tentativaSenha(nivel, numDigitos, senha, maxValue) {
    int tentativa[numDigitos];
    int num = 0, posicaoCerta = 0, posicaoErrada = 0;
    int tentativaInvalida = VALIDO;
    do {
        tentativaInvalida = VALIDO;
        for(int j = 0; j < numDigitos; j++) {
            num = (int) getche() - 48;
            if(num < 0 || num > 9) tentativaInvalida = INVALIDO;
            tentativa[j] = num;
        }
        if(tentativaInvalida == INVALIDO) printf(" Tentativa Inválida\n");
    }while(tentativaInvalida != VALIDO);

    for(int i = 0; i < numDigitos; i++) {
        printf("%d", tentativa[i]);
    }

    computaTentativa(&posicaoCerta, &posicaoErrada, senha, tentativa, numDigitos);
}

void computaTentativa(int* posicaoCerta, int* posicaoErrada, int* tentativa, int* senha, int numDigitos) {
    int posicoesUtilizadas[numDigitos];

    for(int i = 0; i < numDigitos; i++) {

    }
}

void geraJogo(int nivel, int numDigitos, int senha) {
    geraCabecalho(nivel, senha);
    printf("\n");
    printf("Descubra a senha abaixo. Para sair digite 0 para todas as posições\n");
    tentativaSenha(nivel, numDigitos, senha);
}
