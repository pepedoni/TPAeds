#define VALIDO   1
#define INVALIDO 0

#define FACIL       1
#define MEDIO       2
#define DIFICIL     3
#define TESTE       4

#include "senha.h"
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void geraSenhaAleatoria(int numDigitos, int maxNumber, int* senha, char repete) {
    int numRandom = 0;
    // Gera senha com numeros que podem ser repetidos
    if(repete == 'S') {
        // Inicializa gerador de n�meros aleatorios
        srand(clock());
        for(int i = 0; i <= numDigitos; i++) {
            // Gera Número Aleatório
            numRandom = rand() % maxNumber;
            // Coloca o numero aleatorio no vetor
            senha[i] = numRandom;
        }
    }
    else {
        int i, j, status, numRandom = 0;
        // Inicializa gerador de n�meros aleatorios
        srand(time(NULL));

        for (i = 0; i < numDigitos; ++i) {
           // Gera numero aleatorio enquanto ele for repetido
           do {
              numRandom = rand() % maxNumber;
              senha[i] = numRandom;
              status = VALIDO;
              for (j = 0; j < i; ++j)
                 if (senha[i] == senha[j])
                    status = INVALIDO;
           } while (status == INVALIDO);
        }
    }
}

int validaNumeroSenha(int nivel, int num, int* senha, int numDigitos) {
    if(nivel == FACIL) {
        if(num < 0 || num > 4) return INVALIDO;
        else {
            for(int i = 0; i < numDigitos; i++) {
                if(senha[i] == num) return INVALIDO;
            }
        }
    }
    else if(nivel == MEDIO && (num < 0 || num > 5)) return INVALIDO;
    else if((nivel == DIFICIL || nivel == TESTE) && (num < 0 || num > 9)) return INVALIDO;
    return VALIDO;
}

void regrasSenha(nivel) {
    switch(nivel) {
        case FACIL:
            printf("Nivel Escolhido: Facil\n");
            printf("Numero de Digitos: 3\b");
            printf("Algarismos de 0 a 4 que não se repetem!!!");
            break;
        case MEDIO:
            printf("Nivel Escolhido: Medio\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 5 que podem repetir!!!");
            break;
        case DIFICIL:
            printf("Nivel Escolhido: Dificil\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 9 que podem repetir!!!");
            break;
        case TESTE:
            printf("Nivel Escolhido: Teste\n");
            printf("Numero de Digitos: 4\n");
            printf("Algarismos de 0 a 9 que podem repetir!!!");
            break;
    }
}

void digitaSenha(int numDigitos, int maxNumber, int* senha, char repete, int nivel) {
    system("cls");
    int tentativaInvalida = VALIDO, num;
    regrasSenha(nivel);
    printf("\nDigite a senha: ");
    do {
        tentativaInvalida = VALIDO;
        for(int j = 0; j < numDigitos; j++) {
            num = (int) getch() - 48;
            printf("*");
            if(validaNumeroSenha(nivel, num, senha, numDigitos) == 0) tentativaInvalida = INVALIDO;
            senha[j] = num;
        }
        if(tentativaInvalida == INVALIDO) printf("\nSenha Invalida. Tente novamente: ");
    }while(tentativaInvalida != VALIDO);
}

int obterSenha(int numDigitos, int maxNumber, int* senha, char repete, int nivel) {
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;
    int digitada = 0;
    system("cls");
    do{
        printf("Voce deseja \n");
        printf("1 - Gerar Senha Aleatoria \n");
        printf("2 - Digitar Senha Para um Desafiante \n");
        scanf("%d", &opcao);
        if(opcao != 1 && opcao != 2) printf("Opcaoo inválida! Tente Novamente!\n");
    }while(opcao != 1 && opcao != 2);
    if(opcao == 1) geraSenhaAleatoria(numDigitos, maxNumber, senha, repete);
    else {
        digitaSenha(numDigitos, maxNumber, senha, repete, nivel);
        digitada = 1;
    }
    return digitada;

}
