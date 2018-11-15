#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>

void geraJogo(int nivel, int numDigitos, int senha);
void geraCabecalho(int nivel, int* senha);
void computaTentativa(int* posicaoCerta, int* posicaoErrada, int* tentativa, int* senha);

#endif // JOGO_H_INCLUDED
