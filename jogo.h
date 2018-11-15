#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>
// Faz os calculos das posicoes certas e erradas da tentativa
void computaTentativa(int* posicaoCerta, int* posicaoErrada, int* tentativa, int* senha, int numDigitos);
// Valida o numero digitado durante a tentativa
int validaNumero(int nivel, int num);
// Realiza a tentativa da senha
int tentativaSenha(int nivel, int numDigitos, int* senha, int* sairJogo, int jogador, int numTentativa);
// Gera o cabecalho do jogo
void geraCabecalho(int nivel, int* senha, int maxTentativas);
// Controla o funcionamento do jogo de acordo com os parametros recebidos
int geraJogo(int nivel, int numDigitos, int* senha, int maxTentativas, int jogador);
#endif // JOGO_H_INCLUDED
