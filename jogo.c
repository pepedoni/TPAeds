#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "maquina.h"

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

int tentativaSenha(int nivel, int numDigitos, int* senha, int* sairDoJogo, int jogador, int numTentativa) {
    int tentativa[numDigitos];
    int num = 0, posicaoCerta = 0, posicaoErrada = 0;
    int tentativaInvalida = VALIDO;
    char repete;
    int maxNumber;
    if(jogador == 1) {
        do {
            tentativaInvalida = VALIDO;
            *sairDoJogo        = VALIDO;
            for(int j = 0; j < numDigitos; j++) {
                num = (int) getche() - 48;
                if(validaNumero(nivel, num) == 0) tentativaInvalida = INVALIDO;
                if(num != 67 && num != 35) *sairDoJogo = INVALIDO;
                tentativa[j] = num;
            }
            if(tentativaInvalida == INVALIDO && *sairDoJogo == INVALIDO) {
                printf(" Tentativa Inválida\n");
                printf("     ");
            }
        }while(tentativaInvalida != VALIDO && *sairDoJogo == INVALIDO);
    }
    else if(jogador == 2) {
        if(nivel == FACIL) {
            maxNumber = 5;
            repete = 'N';
        }
        else if(nivel == MEDIO) {
            maxNumber = 6;
            repete = 'S';
        }
        else {
            maxNumber = 10;
            repete = 'S';
        }
        geraSenhaAleatoria(numDigitos, maxNumber, tentativa, repete);
        for(int i = 0; i < numDigitos; i++) {
            printf("%d", tentativa[i]);
        }
        *sairDoJogo = INVALIDO;
    }

    if(*sairDoJogo == INVALIDO) {
        computaTentativa(&posicaoCerta, &posicaoErrada, tentativa, senha, numDigitos);
        printf("    %d %d", posicaoCerta, posicaoErrada);
    }
    if(posicaoCerta == numDigitos) return 1;
    return 0;
}


void geraCabecalho(int nivel, int* senha, int maxTentativas){
    system("cls");
    switch(nivel) {
        case FACIL:
            printf("Nivel Escolhido: Fácil\n");
            printf("Numero de Digitos: 3\n");
            printf("Algarismos de 0 a 4 que não se repetem!!!");
            if(maxTentativas != 0) printf("Máximo de Tentativas: %d\n", maxTentativas);
            break;
        case MEDIO:
            printf("Nivel Escolhido: Médio\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 5 que podem repetir!!!");
            if(maxTentativas != 0) printf("Máximo de Tentativas: %d\n", maxTentativas);
            break;
        case DIFICIL:
            printf("Nivel Escolhido: Díficil\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 9 que podem repetir!!!");
            if(maxTentativas != 0) printf("Máximo de Tentativas: %d\n", maxTentativas);
            break;
        case TESTE:
            printf("Nivel Escolhido: Teste\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 9 que podem repetir!!!\n");
            if(maxTentativas != 0) printf("Máximo de Tentativas: %d\n", maxTentativas);
            printf("Senha: ");
            for(int i = 0; i < 4; i++) {
                printf("%d", senha[i]);
            }
            break;
    }
    printf("\n");
    printf("Descubra a senha abaixo. Para sair digite 'S' para todas as posições\n");
    printf("N   Senha   Dica\n");
}

int geraJogo(int nivel, int numDigitos, int* senha, int maxTentativas, int jogador) {
    int sairDoJogo = VALIDO, tentativa = 1, ganhou = 0, jogarNovamente = 0;
    geraCabecalho(nivel, senha, maxTentativas);

    do {
        sairDoJogo = VALIDO;
        printf("%d - ", tentativa);
        ganhou = tentativaSenha(nivel, numDigitos, senha, &sairDoJogo, jogador, tentativa);
        printf("\n");
        tentativa++;
    } while(sairDoJogo == 0 && ganhou == 0 && (tentativa <= maxTentativas || maxTentativas == 0));



    if(ganhou == VALIDO) {
        printf("Parabéns!!! Você venceu com %d tentativas. A senha é: ", (tentativa - 1));
        for(int i = 0; i < 4; i++) {
            printf("%d", senha[i]);
        }
        do{
            printf("\nDigite 0 Para Sair ou 1 Para Jogar Novamente: ");
            scanf("%d", &jogarNovamente);
            if(jogarNovamente != 0 && jogarNovamente != 1) printf("Opção Inválida. Tente novamente.");
        }while(jogarNovamente  != 0 && jogarNovamente != 1);
        return jogarNovamente;
    }
    else if(tentativa >= maxTentativas && maxTentativas != 0) {
        printf("Suas tentativas se esgorataram. A senha é: ", (tentativa - 1));
        for(int i = 0; i < 4; i++) {
            printf("%d", senha[i]);
        }
        do{
            printf("\nDigite 0 Para Sair ou 1 Para Jogar Novamente: ");
            scanf("%d", &jogarNovamente);
            if(jogarNovamente != 0 && jogarNovamente != 1) printf("Opção Inválida. Tente novamente.");
        }while(jogarNovamente  != 0 && jogarNovamente != 1);
        return jogarNovamente;
    }
    else {
        printf("Obrigado por jogar. Volte sempre!!!");
        return 0;
    }
}
