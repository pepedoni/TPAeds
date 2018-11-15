#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

#define VALIDO   1
#define INVALIDO 0

void geraSenha(int numDigitos, int maxNumber, int* senha, char repete) {
    int numRandom = 0;
    // Gera senha com numeros que podem ser repetidos
    if(repete == 'S') {
        // Inicializa gerador de números aleatorios
        srand(time(NULL));
        for(int i = 0; i <= numDigitos; i++) {
            // Gera número aleatório
            numRandom = rand() % maxNumber;
            // Coloca o numero aleatorio no vetor
            senha[i] = numRandom;
        }
    }
    else {
        int i, j, status;
        // Inicializa gerador de números aleatorios
        srand(time(NULL));

        for (i = 0; i < numDigitos; ++i) {
           // Gera numero aleatorio enquanto ele for repetido
           do {
              senha[i] = rand() % maxNumber;
              status = VALIDO;
              for (j = 0; j < i; ++j)
                 if (senha[i] == senha[j])
                    status = INVALIDO;
           } while (status == INVALIDO);
        }
    }
}

#endif // SENHA_H_INCLUDED
