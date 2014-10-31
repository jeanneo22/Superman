#include "Superman.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ostream;

int Superman::contSuperman = 0;
const float Superman::forcaMaxima = 200;
// Sobecarga do operador << para imprimir um objeto da classe Superman
ostream& operator<<( ostream& output,const Superman & superman)
{
	output << "\nHeroi: Superman" << "\nNome: " << superman.nome << "\nIdade: " << superman.idade 
	<< "\nAltura: " << superman.altura <<  "\nResistencia Atual: " << superman.resistenciaAtual << "\nNivel da visao de calor: " << superman.nivelVisaoCalor 
	<< "\nVisao de raioX : " << superman.visaoRaioX << "\nSuper Forca: " << superman.superForca << endl;
	return output;
}
// Sobrecarga do operador de atribução para a classe Superman
Superman &Superman::operator=( const Superman &supermanDireita) 
{	
	nome = supermanDireita.nome;
	idade = supermanDireita.idade;
	altura = supermanDireita.altura;
	fraqueza = supermanDireita.fraqueza;
	resistenciaAtual = supermanDireita.resistenciaAtual;
	nivelVisaoCalor = supermanDireita.nivelVisaoCalor;
	visaoRaioX = supermanDireita.visaoRaioX;
	superForca = supermanDireita.superForca;
	itemForca = new int[5];
	for(int i = 0; i < 5; i++)
	   itemForca[i] = supermanDireita.itemForca[i];
	return *this;
}
// Construtor da classe Superman
Superman::Superman(const string &fraqueza,const string &nome,const int &idade,const float &altura,
					const int &diaNascimento,const int &mesNascimento,const int &anoNascimento,
					const int &resistenciaAtual,const int &nivelVisaoCalor,const float &superForca) : 
			Hero(fraqueza,nome,idade,altura)
{
	setResistenciaAtual(resistenciaAtual);
	setNivelVisaoCalor(nivelVisaoCalor);
	setVisaoRaioX(0);
	setSuperForca(superForca);
	alocarItemForca();
	contSuperman++;
	visitarPlaneta();
}
// Construtor de cópia da classe Superman
Superman::Superman(const Superman &supermanOriginal) : Hero(supermanOriginal)
{	
	this->resistenciaAtual = supermanOriginal.resistenciaAtual;
	this->nivelVisaoCalor = supermanOriginal.nivelVisaoCalor;
	this->visaoRaioX = supermanOriginal.visaoRaioX;
	this->superForca = supermanOriginal.superForca;
	alocarItemForca();
	this->copiarItemForca(supermanOriginal.itemForca);
	this->planetasVisitados = supermanOriginal.planetasVisitados;
	contSuperman++;
}
// Construtor que apenas seta o nível da visão de calor do Superman
Superman::Superman(const int &nivelVisaoCalor)
{
	setNivelVisaoCalor(nivelVisaoCalor);
	contSuperman++;
}
// Destrutor
Superman::~Superman()
{
	delete []itemForca;
}
void Superman::setResistenciaAtual(const int &resistenciaAtual)
{
	this->resistenciaAtual = (resistenciaAtual>=0)? resistenciaAtual:0;
}
void Superman::setNivelVisaoCalor(const int &nivelVisaoCalor)
{
	this->nivelVisaoCalor = (nivelVisaoCalor>=0 && nivelVisaoCalor<=5)? nivelVisaoCalor:0;
}
void Superman::setVisaoRaioX(const int &visaoRaioX)
{
	this->visaoRaioX = (visaoRaioX == 1 || visaoRaioX == 0) ? visaoRaioX:0;
}
void Superman::setSuperForca(const float &superForca)
{
	this->superForca = (superForca >=0 && superForca <= forcaMaxima) ? superForca:0;
}
/* Método para alocar so items de forca que o Superman terá
   inicialmente ele tem 3 itens de força e no máximo 5 itens de força 
  */
void Superman::alocarItemForca()
{
	this->itemForca = new int[5];
	for(int i = 0; i < 3; i++)
		itemForca[i] = 1;
}
// Método para copiar os itens de forca
void Superman::copiarItemForca(int *itemForcaOriginal)
{
	for(int i = 0; i < 5; i++)
	   this->itemForca[i] = itemForcaOriginal[i];
}
int Superman::getResistenciaAtual() { return (this->resistenciaAtual); }
int Superman::getNivelVisaoCalor() { return (this->nivelVisaoCalor); }
int Superman::getVisaoRaioX() { return (this->visaoRaioX); }
float Superman::getSuperForca() { return (this->superForca); }
// Método usado quando o Superman está lutando
void Superman::lutar()
{
	if(visaoCalor()) cout << "Usando a visao de calor: " << nivelVisaoCalor << endl;
	voar(30.0);
	resistenciaAtual -= 10;
}
// Verifica se a visão de calor está ativada em em que nível
int Superman::visaoCalor() const
{
	return(nivelVisaoCalor > 0);
}
// Coleta um item de força
void Superman::coletarItem(const int &i)
{
	if(i >= 0 && i < 5) itemForca[i] = 1;
}
// Usa um item de força
void Superman::usarItem(const int &i)
{	
	if(i >= 0 && i < 5 && itemForca[i])
		switch (i) {
			case 0:
				aumentaResistencia(10);
				itemForca[i] = 0;
				break;
			case 1:
				aumentaNivelVisaoCalor(1);
				itemForca[i] = 0;
				break;
			case 2:
				aumentaSuperForca(50);
				itemForca[i] = 0;
				break;
			case 3:
				setVisaoRaioX(true);
				itemForca[i] = 0;
				break;
			case 4:
				 afetadoKryptonita(0);
				 itemForca[i] = 0;
				 break;
				
		}
	else cout << "Item nao encontrado " << endl;
}
void Superman::aumentaResistencia(const int &aumento) 
{
	this->resistenciaAtual += (aumento >= 0)? aumento:0;
}
void Superman::aumentaNivelVisaoCalor(const int &aumento)
{
	nivelVisaoCalor += (nivelVisaoCalor < 5 && aumento >= 0)? aumento:0;
}
void Superman::aumentaSuperForca(const int &aumento)
{
	superForca += (superForca < forcaMaxima && aumento >= 0)? aumento:0;
}
void Superman::voar(const float &alturaVoo) const
{
	if(alturaVoo > 0)
		cout << "Voando com a altura: " << alturaVoo << " m." << endl;
	else cout << "Nao esta voando\n";
}
// Mostra todos os planetas
void Superman::mostrarPlanetas()
{
	for(int i = 0; i < 5; i++)
	   cout << "Planeta " << (i+1) << endl;
}
// Imprime os planetas visitados pelo Superman
void Superman::imprimePlanetasVisitados()
{
	cout << "Planetas visitados:\n";
	for(unsigned int i = 0; i < this->planetasVisitados.size(); i++)
		cout << "Planeta " << this->planetasVisitados.at(i) << endl;
}	  
// Método usado para o Superman visitar um planeta
void Superman::visitarPlaneta()
{
	string planeta;
	cout << "Escolha qual planeta quer visitar:\n";
	mostrarPlanetas();
	cin >> planeta;
	atualizarPlanetasVisitados(planeta);
}
// Atualiza os planetas que o Superman já visitou 
void Superman::atualizarPlanetasVisitados(const string &planeta)
{
	this->planetasVisitados.push_back(planeta);
}
// Imprime dados do Superman
void Superman::imprime()
{
	this->Hero::imprime();
	cout << "Resistencia atual: " << this->resistenciaAtual << endl;
	cout << "Nivel da visaode calor: " << this->nivelVisaoCalor << endl;
	if(visaoRaioX) cout << "Visao de raioX ativa\n";
	cout << "SuperForca: " << this->superForca << " quintilhoes de toneladas\n";
	cout << "Itens de forca: " << endl;
	for(int i = 0; i < 5; i++)
		if(itemForca[i])
			switch (i) {
				case 0:
					cout << (i+1) << " Aumenta a resistencia atual em 10\n";
					break;
				case 1:
					cout << (i+1) << " Aumenta a visao de calor em 1\n";
					break;
				case 2:
					cout << (i+1) << " Aumenta a super forca em 50 quintilhoes de toneladas\n";
					break;
				case 3:
					cout << (i+1) <<" Ativa a visao de raioX\n";
					break;
				case 4:
					cout << (i+1) << " Desativa a kryptoniya\n";
					break;
		}
		imprimePlanetasVisitados();
}
float Superman::getForcaMaxima(){ return forcaMaxima; }