#include <iostream>
#include <string>
using std::ostream;
using std::string;
#ifndef BATMAN_H
#define BATMAN_H

class Batman : public Hero
{
friend ostream& operator<<( ostream &,const Batman &);
public:
	enum NivelHabilidade = {ALFA,BETA,GAMA,DELTA}; // Tipo enumerado que define o nivel das habilidades
private:
	NivelHabilidade nivelOfuscacao; // nivel de ofuscacao do batman
	NivelHabilidade nivelSuperAgilidade; // nivel da super agilidade do batman
	NivelHabilidade nivelSuperInteligencia;// nivel da super inteligencia
	bool visaoTrigonometrica; // verifica se a visao trigonometrica do batman esta ativa
	string *armas;
public:
	Batman &operator=( const Batman batmanDireita &);
	Batman(const string & = "nenhuma fraqueza",const string & = "nenhum",const int & = 0,const float & = 0.00,
			 const int &,const int &,const int &,
			 const NivelHabilidade & = ALFA,const NivelHabilidade &  = ALFA,const NivelHabilidade & = ALFA,const bool & = false);
	Batman(const Batman &);
	Batman();
	~Batman();
	void setNivelOfuscacao(const nivelHabilidade &);
	void setSuperAgilidade(const nivelHabilidade &);
	void setSuperInteligencia(const nivelHabilidde &);
	void setVisaoTrigonometrica(const bool &);
	nivelHabilidade getNivelOfuscacao();
	nivelHabilidade getNivelSuperAgilidade();
	nivelHabilidade getNivelSuperInteligencia();
	void alocarArmas();
	void copiarArmas(const string *);
	void coletarArma(const int &);
	void usarArma(const int&);
	void voar(const float &) const;
	void atacar();
	void imprime();
};

#endif // BATMAN_H
