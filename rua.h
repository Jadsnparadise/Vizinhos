#include <iostream>
#include <vector>
#include "casa.h"
using namespace std;

class rua{
	public: string cep;
	public: string nome;
	public: vector<casa>lado_a;
	public: vector<casa>lado_b;

	rua(string r_nome, string r_cep){
		nome = r_nome;
		cep = r_cep;
	}

	void adicionaCasa(casa &c, string lado);
	pair <casa,casa> vizinhos(string nome_dono);
	vector<casa> casas(string nome_dono);
	string endereco(string nome_dono, string nomeRua, string cep);
	
};