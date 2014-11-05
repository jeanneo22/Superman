#include "GreenArrow.h"
#include <iostream>
#include <string>
using std::string
using std::cout;
using std::endl;
using std::ostream;
// sobrecarga do operador cout para a classe GreenArrow
ostream& operator<<( ostream &output,const GreenArrow &arqueiro) 
{
	output << "\nHeroi: Green Arrow" << "\nNome: " << arqueiro.nome << "\nIdade: " << arqueiro.idade <<
	"\nAltura: " << arqueiro.altura << "\nFraqueza: " << arqueiro.fraqueza << "\n nivel de acrobacia: " << arqueiro.nivelAcrobacia
	<< "\nNivel de destreza: " << arqueiro.nivelDestreza << endl;
	return output;
}
// Sobrecarga do operador de atrbuição para a classe GreenArrow
GreenArrow& GreenArrow::operator=( const GreenArrow &arqueiroDireita)
{
	nivelDestreza = arqueiroDireita.nivelDestreza;
	nivelAcrobacia = arqueiroDireita.nivelAcrobacia;
	alocarFlechas();
	for(int i = 0; i < 6; i++)
		flechas[i] = arqueiroDireita.flechas[i];
	return *this;
}
// Construtor com parâmetros defaults para a classe GreenArrow
GreenArrow::GreenArrow(const string &fraqueza,const string &nome,const int &idade,const float &altura,
			 const int &diaNascimento,const int &mesNascimento,const int &anoNascimento,
			 const int &nivelDestreza,const int &nivelAcrobacia) : Hero(fraqueza,nome,idade,altura,diaNascimento,mesNascimento,anoNascimento)
{
	setNivelDestreza(nivelDestreza);
    setNivelAcrobacia(nivelAcrobacia);
}
// Construtor de cópia para a classe GreenArrow
GreenArrow::GreenArrow(const GreenArrow &arqueiroOriginal)
{
	nivelDestreza = arqueiroOriginal.nivelDestreza;
	nivelAcrobacia = arqueiroOriginal.nivelAcrobacia;
	copiarFlechas(arqueiroOriginal.flechas);
}
// Constutor vazio para a classe GreenArrow
GreenArrow::GreenArrow()
{
	this->nivelDestreza = 0;
	this->nivelAcrobacia = 0;
	alocarFlechas();
}
// Destrutor
GreenArrow::~GreenArrow()
{
	delete []flechas;
	flechas = 0;
}
//-------------------------------------------
//											  setters and getters
void GreenArrow::setNivelDestreza(const int &nivelDestreza)
{
	this->nivelDestreza = nivelDestreza;
}
void GreenArrow::setNivelAcrobacia(const int &nivelAcrobacia)
{
	this->nivelAcrobacia = nivelAcrobacia;
}
int GreenArrow::getNivelDestreza() { return this->nivelDestreza; }
int GreenArrow::getNivelAcrobacia(){ return this->nivelAcrobacia; }
//------------------------------------------
/* Aloca o vetor de flechas usado por GreenArrow
 * inicialmente GreenArrow tem 3 tipos de flechas por default*/
void GreenArrow::alocarFlechas()
{
	this->flechas = new string[6];
	flecha[0] = "flechaComum";
	flecha[1] = "flechaAcida";
	flecha[2] = "flechaAlgemas";
	for(int i = 3; i < 6; i++)
		this->flechas[i] = "";
}
// Método para copiar o vetor de flechas
void GreenArrow::copiarFlechas(string *flechasOriginal)
{
	for(int i =0; i < 6; i++) 
		this->flechas[i] = flechasOriginal[i];
}
// Coleta um tipo de flecha
void GreenArrow::coletarFlecha(const int & i)
{
	if(i >= 3 && i < 6)
		switch (i) 
		{
			case 3:
				this->flechas[i] = "flechaExplosiva";
				break;
			case 4:
				this->flechas[i] = "flechaLuvaBoxe";
				break;
			case 5:
				this->flechas[i] = "flechaSonica";
				break;
		}
	else cout << "Flecha nao encontrada " << endl;
}
// Atira uma flecha
void GreenArrow::atirarFlecha(const int & i)
{
	if(i >= 0 && i < 6)
		cout << "Atirar " << this->flechas[i] << endl;
	else cout << "Flecha nao encontrada\n";
}
// Mira uma alvo com coordenadas espaciasi x,y e z
void GreenArrow::mirarAlvo(const int &x,const int &y, const int &z)
{
	cout << "Coordenada x do alvo: " << x << endl;
	cout << "Coordenada y do alvo: " << y << endl;
	cout << "Coordenada z do alvo: " << z << endl;
}
// implementação do metodo virtual puro da classe abstrata Hero e Character
void GreenArrow::atacar()
{
	mirarAlvo(1,1,1);
	atirarFlecha(3);
}
// imprime dados do GreenArrow
void GreenArrow::imprime()
{
	this->Hero::imprime();
	cout << "\nNivel de destreza: " << this->nivelAcrobacia << endl;
	cout << "\nNivel da acrobacia: " << this->nivelDestreza << endl;
	for(int i = 0; i < 6; i++)
		if(flechas[i] != "")
		   cout << flechas[i] << endl;
}