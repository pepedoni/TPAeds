#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>
void computaTentativa(int* posicaoCerta, int* posicaoErrada, int* tentativa, int* senha, int numDigitos);
int validaNumero(int nivel, int num);
int tentativaSenha(int nivel, int numDigitos, int* senha, int* sairJogo);
void geraCabecalho(int nivel, int* senha);
int geraJogo(int nivel, int numDigitos, int* senha);
#endif // JOGO_H_INCLUDED
