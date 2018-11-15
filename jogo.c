#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

#define FACIL       1
#define MEDIO       2
#define DIFICIL     3
#define TESTE       4
#define INVALIDO    0
#define VALIDO      1

void computaTentativa(int* posicaoCerta, int* posicaoErrada, int* tentativa, int* senha, int numDigitos) {
    int posicoesValidasTentativa[numDigitos];
    // Zera vetor posicoes validas Tentativas
    int posicoesValidasSenha[numDigitos];

    for(int i = 0; i < numDigitos; i++) {
        if(tentativa[i] == senha[i]) {
            *posicaoCerta += 1;
            posicoesValidasTentativa[i] = 1;
            posicoesValidasSenha[i]     = 1;
        }
        else {
            posicoesValidasTentativa[i] = 0;
            posicoesValidasSenha[i]     = 0;
        }
    }

    for(int j = 0; j < numDigitos; j++) {
        if(posicoesValidasTentativa[j] == 0) {
            for(int k = 0; k < numDigitos; k++) {
                if(posicoesValidasSenha[k] == 0) {
                    if(tentativa[j] == senha[k]) {
                            posicoesValidasTentativa[j] = 1;
                            posicoesValidasSenha[k]     = 1;
                            *posicaoErrada += 1;
                    }
                }
            }
        }
    }
}

int validaNumero(int nivel, int num) {
    if(nivel == FACIL && (num < 0 || num > 4)) return INVALIDO;
    else if(nivel == MEDIO && (num < 0 || num > 5)) return INVALIDO;
    else if((nivel == DIFICIL || nivel == TESTE) && (num < 0 || num > 9)) return INVALIDO;
    return VALIDO;
}

int tentativaSenha(int nivel, int numDigitos, int* senha, int* sairJogo) {
    int tentativa[numDigitos];
    int num = 0, posicaoCerta = 0, posicaoErrada = 0;
    int tentativaInvalida = VALIDO;
    int sairDoJogo = VALIDO;
    do {
        tentativaInvalida = VALIDO;
        for(int j = 0; j < numDigitos; j++) {
            num = ((int) getche()) - 48;
            if(validaNumero(nivel, num) == 0) tentativaInvalida = INVALIDO;
            if(num != 0) sairDoJogo = INVALIDO;
            tentativa[j] = num;
        }
        if(tentativaInvalida == INVALIDO) {
            printf(" Tentativa Inválida\n");
            printf("   ");
        }
    }while(tentativaInvalida != VALIDO);

   /* for(int i = 0; i < numDigitos; i++) {
        printf("%d", tentativa[i]);
    }*/
    if(sairDoJogo == INVALIDO) {
        computaTentativa(&posicaoCerta, &posicaoErrada, tentativa, senha, numDigitos);
        printf(" %d %d", posicaoCerta, posicaoErrada);
    }
    if(posicaoCerta == numDigitos) return 1;
    return 0;
}


void geraCabecalho(int nivel, int* senha){
    system("cls");
    switch(nivel) {
        case FACIL:
            printf("Nivel Escolhido: Fácil\n");
            printf("Numero de Digitos: 3\b");
            printf("Algarismos de 0 a 4 que não se repetem!!!");
            break;
        case MEDIO:
            printf("Nivel Escolhido: Médio");
            printf("Numero de Digitos: 4");
            printf("Algarismos de 0 a 5 que podem repetir!!!");
            break;
        case DIFICIL:
            printf("Nivel Escolhido: Díficil\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 9 que podem repetir!!!");
            break;
        case TESTE:
            printf("Nivel Escolhido: Teste\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 9 que podem repetir!!!\n");
            printf("Senha: ");
            for(int i = 0; i < 4; i++) {
                printf("%d", senha[i]);
            }
            break;
    }

}

void geraJogo(int nivel, int numDigitos, int senha) {
    int sairDoJogo = INVALIDO, tentativa = 0, ganhou = 0;
    geraCabecalho(nivel, senha);
    printf("\n");
    printf("Descubra a senha abaixo. Para sair digite 0 para todas as posições\n");
    while(sairDoJogo == INVALIDO && ganhou != VALIDO) {
        printf("%d - ", tentativa);
        ganhou = tentativaSenha(nivel, numDigitos, senha, &sairDoJogo);
        printf("\n");
        tentativa++;
    }
}
