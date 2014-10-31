#include "Character.h"
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::endl;
using std::cout;
using std::cin;

const float Character::alturaMaxima = 2.30;
// Sobrecarga do operador << para a classe Character
ostream &operator<<( ostream &output,const Character &character)
{
	output << "\nNome: " << character.nome << "\nIdade: " << character.idade
	<< "\nAltura: " << character.altura << endl;
	
	return output;
}
// Sobrecarga do operador de atribuição para a classe Character
Character &Character::operator=( const Character & characterDireita) 
{	
	nome = characterDireita.nome;
	idade = characterDireita.idade;
	altura = characterDireita.altura;
	for(int i = 0; i < 10; i++)
		roupas[i] = characterDireita.roupas[i];
	
	return *this;
}
// Construtor da classe Character
Character::Character(const string &nome,const int &idade,const float &altura,const int &diaNascimento,const int &mesNascimento,const int &anoNascimento)
{
	setNome(nome);
	setIdade(idade);
	setAltura(altura);
	Data(diaNascimento,mesNascimento,anoNascimento);
	alocarRoupas();
	leRoupas();
}
// Construtor de cópia da classe Character
Character::Character(const Character &character)
{
	this->nome = character.nome;
	this->idade = character.idade;
	this->altura = character.altura;
	alocarRoupas();
	copiarRoupas(character.roupas);
}
// Destrutor
Character::~Character() 
{
	delete []roupas;
}
void Character::setNome(const string &nome)
{
	this->nome = nome;
}
void Character::setIdade(const int &idade)
{
	this->idade = (idade>=0)? idade:0;
}
void Character::setAltura(const float &altura)
{
	this->altura = (altura>=0 && altura<=alturaMaxima)? altura:0;
}
string Character::getNome() { return (this->nome); }
int Character::getIdade() { return (this->idade); }
float Character::getAltura() { return (this->altura); }
/* Aloca um vetor de roupas para Character
 * um Character pode ter no máximo 10 roupas
 * e já começa com 1 camisa, 1 calça e 1 sapato*/
void Character::alocarRoupas()
{
	this->roupas = new string[10];
	this->roupas[0] = "camisa";
	this->roupas[1] = "calca";
	this->roupas[2] = "sapato";
}
// Coloca mais roupas no vetor de roupas
void Character::leRoupas()
{
	int i = 3;
	do
	{
		int opcao;
		cout << "Selecione as roupas:\n";
		cout << "1. capa \n";
		cout << "2. camisa \n";
		cout << "3. calca \n";
		cout << "4. sapato \n";
		cin >> opcao;
		switch (opcao) {
			case 1:
				this->roupas[i] = "capa";
				i++;
				break;
			case 2:
				this->roupas[i] = "camisa";
				i++;
				break;
			case 3:
				this->roupas[i] = "calca";
				i++;
				break;
			case 4:
				this->roupas[i] = "sapato";
				i++;
				break;
			default:
				cout << "Voce nao digitou opcao valida\n";
				break;
		}
	}while(i < 10);
}
// Método para copias o vetor de roupas 
void Character::copiarRoupas(const string *roupasOriginal)
{
	for(int i = 0; i < 10; i++)
	   this->roupas[i] = roupasOriginal[i];
}
// Imprime as roupas do Character
void Character::imprimeRoupas()
{
	for(int i = 0; i < 10; i++)
	   cout << "Roupa: " << roupas[i] << endl;
}
// imprimr dados do Character, função que será sobrescrita pela classe Hero
void Character::imprime()
{
	cout << "Nome: " << this->nome << endl;
	cout << "Idade: " << this->idade << endl;
	cout << "Altura: " << this->altura << endl;
	imprimeRoupas();
}
