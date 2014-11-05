#include <iostream>
#include <string>
using std::ostream;
using std::string;
#ifndef GREENARROW_H
#define GREENARROW_H

class GreenArrow : public Hero
{
friend ostream& operator<<( ostream &,const GreenArrow &);
private:
	int nivelDestreza; // nivel de destreza do GreenArrow
	int nivelAcrobacia; // nivel de acrobacia do GreenArrow
	string *flechas; // vetor que guarda o tió de flechas do Green Arrow
public:
	GreenArrow &operator=( const GreenArrow arqueiroDireita &);
	GreenArrow(const string & = "nenhuma fraqueza",const string & = "nenhum",const int & = 0,const float & = 0.00,
			 const int &,const int &,const int &,
			 const int &,const int &);
	GreenArrow(const GreenArrow &);
	GreenArrow();
	~GreenArrow();
	void setNivelDestreza(const int &);
	void setNivelAcrobacia(const int &);
	int getNivelDestreza();
	int getNivelAcrobacia();
	void alocarFlechas();
	void copiarFlechas(string *);
	void coletarFlecha(const int &);
	void atirarFlecha(const int &);
	void mirarAlvo(const int &,const int &,const int &);
	void atacar();
	void imprime();
};

#endif // GREENARROW_H
