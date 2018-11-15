#include <stdio.h>
#include <stdlib.h>
#include "senha.h"
#include "menu.h"
#include "jogo.h"

int main(int argc, char** argv) {

	int nivel, maxNumber;
	int senha[4];
	int numDigitos = 0;
	char repete = 'S';

	menu(&numDigitos, &nivel, &maxNumber, &repete);
    geraSenha(numDigitos, maxNumber, senha, repete);

	geraJogo(nivel, numDigitos, senha);

	return 0;
}
