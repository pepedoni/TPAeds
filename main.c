#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "senha.h"
#include "menu.h"
#include "jogo.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");

	int nivel = 0, maxNumber;
	int senha[4];
	int numDigitos = 0;
	int jogarNovamente = 0;
	char repete = 'S';

	// Recebe o nível como argumento
	if(argc == 2) nivel       = atoi(argv[1]);
	//if(argc == 3) tentatinvas = atoi(argv[3]);

	do{
        system("cls");
        menu(&numDigitos, &nivel, &maxNumber, &repete);

        geraSenha(numDigitos, maxNumber, senha, repete);
        jogarNovamente = geraJogo(nivel, numDigitos, senha);
        nivel = 0;
	}
    while(jogarNovamente != 0);
    printf("\n");
    system("PAUSE");

	return 0;
}
