#ifndef BATMAN_H
#define BATMAN_H

class Batman
{
friend ostream& operator<<( ostream &,const Batman &);
public:
	enum nivelHabilidade = {alfa,beta,gama,delta};
private:
	nivelHabilidade nivelOfuscacao;
	nivelHabilidade nivelSuperAgilidade;
	nivelHabilidade nivelSuperInteligencia;
	bool visaoTrigonometrica;
	string *Armas;
	int *itemForca;
public:
	Batman &operator=( const batmanDireita &);
	Batman(const nivelHabilidade &,const nivelHabilidade &,const nivelHabilidade &,const bool &);
	Batman(const Batman &);
	Batman();
	~Batman();
	void setNivelOfuscacao();
	void setSuperAgilidade();
	void setSuperAgilidade();
	void setSuperInteligencia();
	void setVisaoTrigonometrica();
	void alocarArmas();
	void alocarItemForca();
	void copiarItemForca(int *);
	void coletarItem(const int &);
	void usarItem(const int &);
	nivelHabilidade getNivelOfuscacao();
	nivelHabilidade getNivelSuperAgilidade();
	nivelHabilidade getNivelSuperInteligencia();
	void voar(const float &) const;
	void imprime();
};

#endif // BATMAN_H
