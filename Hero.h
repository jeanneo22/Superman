#include <string>
using std::string;
using std::ostream;

#ifndef HERO_H
#define HERO_H

class Hero : public Character
{
	friend ostream &operator<<( ostream &,const Hero &);
protected:
	string fraqueza; // A fraqueza do herói
	string *pessoasSalvas; // Guarda as pessoas salvas por Hero
	int numeroPessoasSalvas; // numero de Pessoas Salvas por Hero
public:
	Hero &operator=( const Hero & );
	Hero(const string & = "nenhuma",const string & = "sem nome",const int& = 0,const float & = 0.00,const int & = 1,const int = 1, const int & = 1900);
	Hero(const Hero &);
	virtual ~Hero();
	void setFraqueza(const string &);
	void setNumeroPessoasSalvas(const int &numeroPessoasSalvas)
	void alocarPessoasSalvas();
	void copiarPessoasSalvas(const string *);
	void salvar();
	virtual void imprime();
};
#endif // HERO_H