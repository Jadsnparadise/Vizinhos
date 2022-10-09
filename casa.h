#include <iostream>
using namespace std;

class casa{
	public: int numero;
	string dono;

	casa(string c_casa){
		dono = c_casa;
		numero = -1;
	}

	public:
	int getNumero();
	void setNumero(int c_numero);
	string getDono();
	void setDono(string c_dono);
	
};