#include <string>
#include "Data.h"
using std::string;
using std::ostream;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
	friend ostream &operator<<( ostream &,const Character &);
protected:
	string nome;
	int idade;
	float altura;
	string *roupas; // vetor que guarda as roupas do Character
	Data dataNascimento;
	const static float alturaMaxima;
public:
	Character &operator=( const Character & );
	Character(const string & = "sem nome",const int & = 0,const float & = 0.00,const int & = 1,const int = 1, const int & = 1900);
	Character(const Character &);
	virtual ~Character();
	void setNome(const string &);
	void setIdade(const int &);
	void setAltura(const float &);
	string getNome();
	int getIdade();
	float getAltura();
	void alocarRoupas();
	void leRoupas();
	void copiarRoupas(const int *);
	void imprimeRoupas();
	virtual void imprime();
}
#endif // CHARACTER_H