#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <maquina.h>
#include "senha.h"
#include "menu.h"
#include "jogo.h"
#include "maquina.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");

	int nivel = 0, maxNumber;
	int senha[4];
	int numDigitos = 0;
	int jogarNovamente = 0;
	int tentativas = 0;
	int jogador  = 1;
	int digitada = 0;
	char repete = 'S';

	// Recebe como argumento o nivel e o numero de tentantivas
	if(argc >= 2) nivel       = atoi(argv[1]);
	if(argc >= 3) tentativas = atoi(argv[2]);
	printf("%d %d", nivel, tentativas);

	do{
        system("cls");
        menu(&numDigitos, &nivel, &maxNumber, &repete);

        digitada = obterSenha(numDigitos, maxNumber, senha, repete, nivel);
        if(digitada == 1) jogador = escolheJogador();
        jogarNovamente = geraJogo(nivel, numDigitos, senha, tentativas, jogador);
        nivel = 0;
	}
    while(jogarNovamente != 0);
    printf("\n");
    system("PAUSE");
	return 0;
}
