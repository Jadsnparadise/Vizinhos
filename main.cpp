#include <iostream>
#include <vector>
#include <string>
#include "rua.h"
using namespace std;


int main() {
	int qtdCasas;
	string nomeRua, cepRua;
	vector <casa> todasCasas;
	
	cout<< "Defina a quantidade de casas da rua: ";
	cin >> qtdCasas;
	cin.ignore(1000,'\n');
	
	cout<< endl<< "nome da rua: ";
	getline(cin, nomeRua);
	
	cout<< endl<< "cep da rua: ";
	getline(cin, cepRua);
	
	rua ruaTeste(nomeRua,cepRua);
	
	for(int i = 0; i < qtdCasas; i++){
		string lado,nomeDoDono;
		cout<< endl<< "Nome do dono da casa: ";	
		getline(cin, nomeDoDono);
		cout << endl << "lado da casa: ";
		getline(cin, lado);
		casa casaAtual(nomeDoDono);
		todasCasas.push_back(casaAtual);
		ruaTeste.adicionaCasa(casaAtual,lado);
	}

	for(int i = 0; i < qtdCasas; i++){
		casa casaAtual = todasCasas[i];
		cout << ruaTeste.endereco(casaAtual.getDono(),nomeRua,cepRua) << endl;
		cout << "Vizinhos" << endl;
		std::pair <casa,casa> vizinhos = ruaTeste.vizinhos(casaAtual.getDono());
		cout << vizinhos.first.getDono() << " " << vizinhos.second.getDono() << endl;
	}
}