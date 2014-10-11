#include "Superman.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

	int Superman::idade = 33;
	const float Superman::altSuperman = 1.90;
	void Superman::setNiveisVisaoCalor() 
	{
		int i;
		for(i=0; i < 6; i++)
			niveisVisaoCalor.push_back(i);
	}
	ostream &operator<<( ostream &output,const Superman &s)
	{
		output << "Heroi: Superman\n" << "Nome terrestre: " << s.nome << "Nome kryptoniano: Kal-el\n"
		<< "Forca Maxima: " << s.forcaMaxima << "Resistencia Atual: " << s.resistenciaAtual << 
		"Nivel da visao de calor " << s.nivelVisaoCalor;
		return output;
	}
	Superman &Superman::operator=( const Superman & s) 
	{
		forcaMaxima = s.forcaMaxima;
		resistenciaAtual = s.resistenciaAtual;
		nivelVisaoCalor = s.nivelVisaoCalor;
		nome = s.nome;
		
		return *this;
	}
	Superman::Superman(const Superman &s) 
	{
		forcaMaxima = s.forcaMaxima;
		resistenciaAtual = s.resistenciaAtual;
		nivelVisaoCalor = s.nivelVisaoCalor;
		nome = s.nome;
	}
	Superman::Superman(double forcaMaxima)
	{
		setForcaMaxima(forcaMaxima);
		setResistenciaAtual(100);
		setNivelVisaoCalor(4);
		setNome("Clark Kent");
	}
	Superman::~Superman()
	{
		//delete ;
	}
	void Superman::setForcaMaxima(double FM)
	{
		if(FM >= 0 && FM <= 200) forcaMaxima = FM;
		else cout << "Erro: forca invalida\n";
	}
	void Superman::setResistenciaAtual(int RA)
	{
		if(RA >= 0) resistenciaAtual = RA;
		else cout << "Erro: resistencia invalida\n";
	}
	void Superman::setNivelVisaoCalor(int NVC)
	{
		if(NVC >= niveisVisaoCalor[0] && NVC <= niveisVisaoCalor[6]) nivelVisaoCalor = NVC;
		else cout << "Erro: nivel da visao de calor invalido\n";
	}
	void Superman::setNome(string nome)
	{
		if(nome == "Clark Kent") this->nome = nome;
		else cout << "Erro: nome invalido\n";
	}
	void Superman::lutar()
	{
		cout << "Usando a forca Maxima: " << forcaMaxima << endl;
		if(visaoCalor()) cout << "Usando a visao de calor: " << nivelVisaoCalor << endl;
		voar(30.0);
		resistenciaAtual -= 10;
	}
	
	int Superman::visaoCalor() const 
	{
		if(nivelVisaoCalor > 0) {
			cout << "Nivel da visao de calor: " << nivelVisaoCalor << endl;
			return 1;
		}else{
			cout << "Visao de calor nao ativa\n";
			return 0;
		}
	}
	void Superman::voar(float alturaVoo) const 
	{
		if(alturaVoo > 0)
			cout << "Voando coma altura: " << alturaVoo << endl;
		else cout << "Nao esta voando\n";
	}
	void Superman::mostrarInfo()
	{
		cout << "Heroi: Superman\n";
		cout << "Nome terrestre: Clark Kent\n";
		cout << "Nome kryptoniano: Kal-el\n";
		cout << "Idade: " << idade << endl;
		cout << "Altura: " << altSuperman << endl;
		
	}

