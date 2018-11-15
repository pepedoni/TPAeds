#include <stdio.h>
#include <stdlib.h>
#include "senha.h"
#include "menu.h"

void menu(int* numDigitos, int* nivel, int* maxNumber, int* repete);
void geraSenha(int numDigitos, int maxNumber, int* senha, char repete);

int main(int argc, char** argv) {

	int nivel, maxNumber;
	int senha[4];
	int numDigitos = 0;
	char repete = 'S';

	menu(&numDigitos, &maxNumber, &nivel, &repete);
    geraSenha(numDigitos, maxNumber, senha, repete);

	for(int i = 0; i < 4; i++) {
		printf("%d", senha[i]);
	}

	//geraJogo(nivel, numDigitos, senha);

	return 0;
}
