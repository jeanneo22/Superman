#include "Batman.h"
#include <iostream>
#include <string>
using std::string
using std::cout;
using std::endl;
using std::ostream;
// sobrecarga do operadode friend << para a classe Batman
ostream& operator<<( ostream &output,const Batman &batman) 
{
	output << "\nHeroi: Batman" << "\nNome: " << batman.nome << "\nIdade: " << batman.idade <<
	"\nAltura: " << batman.altura << "\nFraqueza: " << batman.fraqueza << "\n nivel de ofuscacao: " << batman.nivelOfuscacao
	<< "\nNivel da super agilidade: " << batman.nivelSuperAgilidade << "\n nivel da super inteligencia: "<< batman.nivelSuperInteligencia << endl;
	return output;
}
// sobrecarga do operador de atribuição para a classe Batman
Batman::Batman &operator=( const Batman &batmanDireita) 
{
	nivelOfuscacao = batmanDireita.nivelOfuscacao;
	nivelSuperAgilidade = batmanDireita.nivelSuperAgilidade;
	nivelSuperInteligencia = batmanDireita.nivelSuperInteligencia;
	visaoTrigonometrica = batmanDireita.visaoTrigonometrica;
	alocarArmas();
	for(int i = 0; i < 8; i++)
		armas[i] = batmanDireita.armas[i];
	return *this;
}
// Construtor com parametros default para a classe Batman
Batman::Batman(const string &fraqueza,const string &nome,const int &idade,const float &altura,
			 const int &diaNascimento,const int &mesNascimento,const int &anoNascimento,
			 const NivelHabilidade &nivelOfuscacao,const NivelHabilidade &nivelSuperAgilidade,
			 const NivelHabilidade &nivelSuperInteligencia,const bool &visaoTrigonometrica) : Hero(fraqueza,nome,idade,altura,diaNascimento,mesNascimento,anoNascimento) 
{
	setNivelOfuscacao(nivelOfuscacao);
	setSuperAgilidade(nivelSuperAglidade);
	setSuperInteligencia(nivelSuperInteligencia);
	setVisaoTrigonometrica(visaoTrigometrica);
	
}
// Construtor de copia para a classe Batman
Batman::Batman(const Batman &batmanOriginal) 
{
	nivelOfuscacao = batmnaOriginal.nivelOfuscacao;
	nivelSuperAgilidade = batmanOriginal.nivelSuperAgilidade;
	nivelSuperInteligencia = batmanOriginal.nivelSuperInteligencia;
	alocarArmas();
	copiarArmas(batmanOriginal.armas);
}
// Construtor vazio para a classe Batman
Batman::Batman()
{
	nivelOfuscacao = ALFA;
	nivelSuperAgilidade = ALFA;
	nivelSuperInteligencia = ALFA;
	alocarArmas();
}
// Destrutor
Batman::~Batman()
{
	delete []armas;
	armas = 0;
}
//---------------------------------------------
//    											setters and getters
void Batman::setNivelOfuscacao(const NivelHabilidade &nivelOfuscacao) 
{
	this->nivelOfuscacao = (nivelOfuscacao >= ALFA && nivelOfuscacao <= DELTA)?nivelOfuscacao:ALFA;
}
void Batman::setSuperAgilidade(const NivelHabilidade &nivelSuperAgilidade)
{
	this->nivelSuperAgilidade = (nivelSuperAgilidade >= ALFA && nivelSuperAgilidade <= DELTA)?nivelSuperAgilidade:ALFA;
}
	
}
void Batman::setSuperInteligencia(const NivelHabilidde &nivelSuperInteligencia) 
{
	this->nivelSuperInteligencia = (nivelSuperInteligencia >= ALFA && nivelSuperInteligencia <= DELTA)?nivelSuperInteligencia:ALFA;
}
void Batman::setVisaoTrigonometrica(const bool &visaoTrigonometrica)
{
	this->visaoTrigonometrica = (nivelSuperAgilidade == true || nivelSuperAgilidade == false)?visaoTrigonometrica:false;
}
nivelHabilidade Batman::getNivelOfuscacao() { return this->nivelOfuscacao; }
nivelHabilidade Batman::getNivelSuperAgilidade() { return this->nivelSuperAgilidade; }
nivelHabilidade Batman::getNivelSuperInteligencia() { return this->nivelSuperInteligencia; }
//------------------------------------------------------------
/* Aloca vetor de armas do Batman 
 * inicialmente o Batman tem 3 armas por default*/
void Batman::alocarArmas()
{
	this->armas = new string[8];
	armas[0] = "laser";
	armas[1] = "capsulaGas";
	armas[2] = "batRang";
	for(int i = 3; i < 8; i++)
		armas[i] = "";
}
// Método para copiar armas
void Batman::copiarArmas(const string *armasOringinal)
{
	for(int i =0; i < 8; i++)
		this->armas[i] = armasOriginal[i];
}
// Coleta uma arma
void Batman::coletarArma(const int &i)
{
	if(i >= 3 && i < 8)
		switch (i) {
			case 3:
				this->armas[i] = "bombaGas";
				break;
			case 4:
				this->armas[i] = "batCorda";
				break;
			case 5:
				this->armas[i] = "batRangSonico";
				break;
			case 6:
				this->armas[i] = "batRangControle";
				break;
			case 7:
				 this->armas[i] = "granadaCongelante";
				 break;
				
		}
	else cout << "Arma nao encontrada " << endl;
}
// Usa uma arma
void Batman::usarArma(const int &i)
{
	if(i >= 0 && i < 8 && this->armas[i] != "") 
		cout << "Usando " << this->armas[i] << endl;
	else cout << "Arma nao encontrada\n";
}
// Faz o Batman voar
void Batman::voar(const float &alturaVoo) const
{
	if(alturaVoo > 0)
		cout << "Voando com a altura: " << alturaVoo << " m." << endl;
	else cout << "Nao esta voando\n";
}
void Batman::atacar()
{
	voar(30.0);
	usarArma(0);
	usarArma(2);
}
// Imprime dados do Batman
void Batman::imprime()
{
	this->Hero::imprime();
	cout << "Nivel de ofuscacao: " << this->nivelOfuscacao << endl;
	cout << "Nivel da super agilidade " << this->nivelSuperAgilidade << endl;
	cout << "Nivel da super intelgiencia " << this->nivelSuperInteligencia << endl;
	cout << "Armas:\n";
	for(int i = 0; i < 8; i++)
		if(this->armas[i] != "")
		   cout << this->armas[i] << endl;
}