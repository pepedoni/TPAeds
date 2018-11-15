void geraSenha(int nivel, int numDigitos, int* senha, char repete) {
    srand(time(NULL));
    int numRandom = 0;
	for(int i = 0; i < nivel; i++) {
        if(repete == 'S') {
            senha[i] = rand() % numDigitos;
        }
        else {
            senha[i] = geraNovoNumero(senha, i);
        }
	}

}

void geraNovoNumero(int* senha, int index) {
    int numRandom, existe = 0;
    numRandom = rand() % numDigitos;
    for(int j = 0; j < i; j++) {
        if(senha[j] == numRandom) {
            existe = 1;
            break;
        }
    }
    if(existe == 1) return geraNovoNumero(senha, index);
    else return numRandom;
}
