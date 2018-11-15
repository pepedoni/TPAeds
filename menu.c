#include <stdio.h>
#include "menu.h"

#define VALIDO   1
#define INVALIDO 0

void menu(int* numDigitos, int* nivel, int* maxNumber, char* repete) {
    int valido = VALIDO;
	do {
        if(*nivel == 0) {
            printf("Digite o nivel desejado\n");
            printf("1 - Fácil \n");
            printf("2 - Médio \n");
            printf("3 - Difícil \n");
            printf("4 - Teste \n");
            scanf("%d", nivel);
        }
		switch(*nivel) {
			case 1:
			    *numDigitos = 3;
			    *maxNumber  = 5;
			    *repete     = 'N';
				valido = VALIDO;
				break;
			case 2:
			    *numDigitos = 4;
			    *maxNumber  = 6;
				valido = VALIDO;
				break;
			case 3:
			    *numDigitos = 4;
				*maxNumber  = 10;
				valido = VALIDO;
				break;
			case 4:
			    *numDigitos = 4;
				*maxNumber  = 10;
				valido = VALIDO;
				break;
			default:
				printf("Valor invalido! Tente novamente");
				valido = INVALIDO;

		}
	}
	while(valido != VALIDO);
}
