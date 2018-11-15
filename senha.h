#include <stdio.h>
#include <stdlib.h>

#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

// Obtem a senha de acordo com os parametros informados
int obterSenha(int numDigitos, int maxNumber, int* senha, char repete, int nivel);

// Gera uma senha aleatória quando selecionado pelo usuario
void geraSenhaAleatoria(int numDigitos, int maxNumber, int* senha, char repete);

// Solicita que o usuario digite a senha a ser descoberta
void digitarSenha(int numDigitos, int maxNumber, int* senha, char repete);

// Exibe as regras para a senha a ser digitada
void regrasSenha(nivel);

// Valida o numero esta de acordo com as regras da senha digitada
int validaNumeroSenha(int nivel, int num, int* senha, int numDigitos);

#endif // SENHA_H_INCLUDED
