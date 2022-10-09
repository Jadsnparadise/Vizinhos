#include <iostream>
#include "casa.h"
using namespace std;

int casa::getNumero(){
	return numero;
}

void casa::setNumero(int c_numero){
	numero = c_numero;
}

string casa::getDono(){
	return dono;
}

void casa::setDono(string c_dono){
	dono = c_dono;
}