#define VALIDO   1
#define INVALIDO 0

#include "senha.h"
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

void geraSenha(int numDigitos, int maxNumber, int* senha, char repete) {
    int numRandom = 0;
    // Gera senha com numeros que podem ser repetidos
    if(repete == 'S') {
        // Inicializa gerador de n�meros aleatorios
        srand(time(NULL));
        for(int i = 0; i <= numDigitos; i++) {
            // Gera n�mero aleat�rio
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
