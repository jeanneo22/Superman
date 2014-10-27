#include "Superman.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

int Superman::contSuperman = 0;
const float Superman::forcaMaxima = 200;
// Sobecarga do operador << para imprimir um objeto da classe Superman
ostream &operator<<( ostream &output,const Superman &superman)
{
	output << "\nHeroi: Superman" << "\nNome: " << superman.nome
	<<  "\nResistencia Atual: " << superman.resistenciaAtual << "\nNivel da visao de calor: " << superman.nivelVisaoCalor 
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
	visaoRaioX = supermanDireita.visaoRaioX
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
	setVisaoRaioX(false);
	setSuperForca(superForca);
	alocarItemForca();
	contSuperman++:
	visitarPlaneta();
}
// Construtor de cópia da classe Superman
Superman::Superman(const Superman &supermanOriginal) : Hero(supermanOriginal)
{	
	this->resistenciaAtual = supermanOriginal.resistenciaAtual;
	this->nivelVisaoCalor = supermanOriginal.nivelVisaoCalor;
	this->visaoRaioX = supermanOriginal.visaoRaioX;
	this->superForca = supermanOriginal.superForca;
	this->itemForca.copiarItemForca(supermanOriginal.itemForca);
	this->planetasVisitados(supermanOriginal.planetasVisitados);
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
Superman::void setResistenciaAtual(const int &resistenciaAtual)
{
	this->resistenciaAtual = (resistenciaAtual>=0)? resistenciaAtual:0;
}
Superman::void setNivelVisaoCalor(const int &nivelVisaoCalor)
{
	this->nivelVisaoCalor = (nivelVisaoCalor>=0 && nivelVisaoCalor<=5)? nivelVisaoCalor:0;
}
Superman::void setVisaoRaioX(int visaoRaioX)
{
	this->visaoRaioX = (visaoRaioX == 1 || visaoRaioX == 0) ? visaoRaioX:0;
}
Superman::void setSuperForca(const float &superForca)
{
	this->superForca = (superForca >=0 && superForca <= forcaMaxima) ? superForca:0;
}
/* Método para alocar so items de forca que o Superman terá
   inicialmente ele tem 3 itens de força e no máximo 5 itens de força 
  */
Superman::void alocarItemForca()
{
	this->itemForca = new int[5];
	for(int i = 0; i < 3; i++)
		itemForca[i] = 1;
}
// Método para copiar os itens de forca
Superman::void copiarItemForca(const int *itemForcaOriginal)
{
	for(int i = 0; i < 5; i++)
	   this->itemForca[i] = itemForcaOriginal[i];
}
Superman::int getResistenciaAtual() { return (this->resistenciaAtual); }
Superman::int getNivelVisaoCalor() { return (this->nivelVisaoCalor); }
Superman::int getVisaoRaioX() { return (this->visaoRaioX); }
Superman:: float getSuperForca() { return (this->superForca); }
// Método usado quando o Superman está lutando
Superman::void lutar()
{
	if(visaoCalor()) cout << "Usando a visao de calor: " << nivelVisaoCalor << endl;
	voar(30.0);
	resistenciaAtual -= 10;
}
// Verifica se a visão de calor está ativada em em que nível
Superman::int visaoCalor() const
{
	return(nivelVisaoCalor > 0);
}
// Coleta um item de força
Superman::void coletarItem(const int i)
{
	if(i >= 0 && i < 5) itemForca[i] = 1;
}
// Usa um item de força
Superman::void usarItem(const int i)
{	
	if(itemForca[i])
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
Superman::void aumentaResistencia(const int &aumento) 
{
	this->resistenciaAtual += (aumento >= 0)? aumento:0;
}
Superman::void aumentaNivelVisaoCalor(const int &aumento)
{
	nivelVisaoCalor += (nivelVisaoCalor < 5 && aumento >= 0)? aumento:0;
}
Superman::void aumentaSuperForca(const int &aumento)
{
	superForca += (superForca < forcaMaxima && aumento >= 0)? aumento:0;
}
Superman::void voar(const float &alturaVoo) const
{
	if(alturaVoo > 0)
		cout << "Voando coma altura: " << alturaVoo << endl;
	else cout << "Nao esta voando\n";
}
// Mostra todos os planetas
Superman::void mostrarPlanetas()
{
	for(int i = 0; i < 5; i++)
	   cout << "Planeta " << (i+1) << endl;
}
// Imprime os planetas visitados pelo Superman
Superman::::void imprimePlanetasVisitados()
{
	for(int i = 0; i < this->planetasVisitados.size; i++)
		cout << this->planetasVisitados.at(i);
}	  
// Método usado para o Superman visitar um planeta
Superman::void visitarPlaneta()
{
	string planeta;
	cout << "Escolha qual planeta quer visitar:\n";
	mostrarPlanetas();
	cin >> planeta;
	atualizarPlanetasVisitados(planeta);
}
// Atualiza os planetas que o Superman já visitou 
Supermna::void atualizarPlanetasVisitados(string planeta)
{
	this->planetasVisitados.push_back(planeta);
}
// Imprime dados do Superman
Superman::Superman void imprime()
{
	this->Hero::imprime();
	cout << " Resistencia atual: " << this->resistenciaAtual;
	cout << " Nivel da visaode calor: " << this->nivelVisaoCalor;
	if(visaoRaioX) cout << "Visao de raioX ativa\n";
	cout << "SuperForca: " << this->superForca;
	cout << "Itens de forca: " << endl;
	for(int i = 0; i < 5; i++)
		if(itemForca[i])
			switch (i) {
				case 0:
					cout << "Aumenta a resistencia atual em 10\n";
					break;
				case 1:
					cout << "Aumenta a visao de calor em 1\n";
					break;
				case 2:
					cout << "Aumenta a super forca em 50 quintilhões de toneladas\n";
					break;
				case 3:
					cout << "Ativa a visao de raioX\n";
					break;
				case 4:
					cout << "Desativa a kryptoniya\n";
					break;
		}
		imprimePlanetasVisitados();
	
}