#include <iostream>
#include <vector>
#include <cstring>
#include "rua.h"
using namespace std;

void rua::adicionaCasa(casa &c, string lado){
	switch(toupper(lado[0])){
		case 'A': 
			c.setNumero(lado_a.size()*2);
			lado_a.push_back(c);
		break;

		case 'B':
			if(lado_b.size() == 0){										c.setNumero(1);
				lado_b.push_back(c);
			}else{
				c.setNumero(1+lado_b.size()*2);
				lado_b.push_back(c);
				}
		break;

		default: break;
	}
}

//Percorre todo o lado a procurando a casa com o dono igual ao nome inserido pelo usuário
pair <casa,casa> rua::vizinhos(string nome_dono){
	casa vizinhoCasoErro(" ");
	for(int i = 0; i < lado_a.size(); i++){
		casa casaAtual = lado_a.at(i);
		
		if(casaAtual.getDono().compare(nome_dono) == 0 && i == 0){
			casa vizinhoAnterior = vizinhoCasoErro;
			casa vizinhoPosterior = lado_a.at(i+1);
			std::pair <casa,casa> vizinhos = 		make_pair(vizinhoAnterior,vizinhoPosterior);
			return vizinhos;
		}
			
		else if(casaAtual.getDono().compare(nome_dono) == 0 && i == lado_a.size()-1 && i != 0){
			casa vizinhoAnterior = lado_a.at(i-1);
			casa vizinhoPosterior = vizinhoCasoErro;
			std::pair <casa,casa> vizinhos = 		make_pair(vizinhoAnterior,vizinhoPosterior);
			return vizinhos;
		}else if(casaAtual.getDono().compare(nome_dono) == 0){
			casa vizinhoAnterior = lado_a.at(i-1);
			casa vizinhoPosterior = lado_a.at(i+1);
			std::pair <casa,casa> vizinhos = 		make_pair(vizinhoAnterior,vizinhoPosterior);
			return vizinhos;
		}	
	}
	
//Percorre todo o lado b procurando a casa com o dono igual ao nome inserido pelo usuário
		for(int i = 0; i < lado_a.size(); i++){
		casa casaAtual = lado_b.at(i);
		
		if(casaAtual.getDono().compare(nome_dono) == 0 && i == 0){
			casa vizinhoAnterior = vizinhoCasoErro;
			casa vizinhoPosterior = lado_b.at(i+1);
			std::pair <casa,casa> vizinhos = 		make_pair(vizinhoAnterior,vizinhoPosterior);
			return vizinhos;
		}
			
		else if(casaAtual.getDono().compare(nome_dono) == 0 && i == lado_b.size()-1 && i != 0){
			casa vizinhoAnterior = lado_b.at(i-1);
			casa vizinhoPosterior = vizinhoCasoErro;
			std::pair <casa,casa> vizinhos = 		make_pair(vizinhoAnterior,vizinhoPosterior);
			return vizinhos;
		}else if(casaAtual.getDono().compare(nome_dono) == 0){
			casa vizinhoAnterior = lado_b.at(i-1);
			casa vizinhoPosterior = lado_b.at(i+1);
			std::pair <casa,casa> vizinhos = 		make_pair(vizinhoAnterior,vizinhoPosterior);
			return vizinhos;
		}	
	}
	
}

//Percorre todo o lado_a e se o nome do dono da casa atual for igual ao inserido pelo usuário adiciona a um vetor de casas pertecente ao propietário.
vector<casa> rua::casas(string nome_dono){
	vector <casa> casasDessaPessoa;
	
	for(int i = 0; i < lado_a.size(); i++){
		casa casaAtual = lado_a[i];
		if(casaAtual.getDono().compare(nome_dono) == 0){
			vector <casa> casasDessaPessoa;
			
		}
	}

//lado_b
	for(int i = 0; i < lado_a.size(); i++){
		casa casaAtual = lado_a[i];
		if(casaAtual.getDono().compare(nome_dono) == 0){
			casasDessaPessoa.push_back(casaAtual);
		}
	}
	return casasDessaPessoa;
}

string rua::endereco(string nome_dono, string nomeRua, string cep){
	rua ruaAtual(nomeRua,cep);
	for(int i = 0; i < lado_a.size(); i++){
		casa casaAtual = lado_a.at(i);
		if(casaAtual.getDono().compare(nome_dono) == 0){
			string endereco = casaAtual.getDono()+" - Rua " + ruaAtual.nome;
			endereco += ", "+ to_string(casaAtual.getNumero())+", CEP "+ruaAtual.cep;
			return endereco;
		}
	}
	
	for(int i = 0; i < lado_b.size(); i++){
		casa casaAtual = lado_b.at(i);
		if(casaAtual.getDono().compare(nome_dono) == 0){
			string endereco = casaAtual.getDono()+" - Rua " + ruaAtual.nome;
			endereco += ", "+ to_string(casaAtual.getNumero())+", CEP "+ruaAtual.cep;
			return endereco;
		}
	}
	
}
