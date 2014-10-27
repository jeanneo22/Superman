#include "Character.h"
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::endl;
using std::cout;

const float Character::alturaMaxima = 2.30;
// Sobrecarga do operador << para a classe Character
ostream &operator<<( ostream &output,const Character &character)
{
	output << "Nome: " << character.nome << "Idade: " << character.idade
	<< "Altura: " << character.altura << endl;
	
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
	copiarRoupas(character.roupas);
}
// Destrutor
Character::virtual ~Character() 
{
	delete []roupas;
}
Character::void setNome(const string &nome)
{
	this->nome = nome;
}
Character::void setIdade(const int &idade)
{
	this->idade = (idade>=0)? idade:0;
}
Character::void setAltura(const float &altura)
{
	this->altura = (altura>=0 && altura<=alturaMaxima)? altura:0;
}
Character::string getNome() { return (this->nome); }
Character::int getIdade() { return (this->idade); }
Character::float getAltura() { return (this->altura); }
/* Aloca um vetor de roupas para Character
 * um Character pode ter no máximo 10 roupas
 * e já começa com 1 camisa, 1 calça e 1 sapato*/
Character::void alocarRoupas()
{
	this->roupas[] = new int[10];
	roupa[0] = "camisa";
	roupa[1] = "calça";
	roupa[2] = "sapato";
}
// Coloca mais roupas no vetor de roupas
Character::void leRoupas()
{
	int i = 3;
	do
	{
		int opcao
		cout << "Selecione as roupas:\n":
		cout << "1. capa \n";
		cout << "2. camisa \n";
		cout << "3. calça \n";
		cout << "4. sapato \n";
		cin >> opcao;
		switch (opcao) {
			case 1:
				this->roupa[i] = "capa";
				i++
				break;
			case 2:
				this->roupa[i] = "camisa";
				i++
				break;
			case 3:
				this->roupa[i] = "calça";
				i++
				break;
			case 4:
				this->roupa[i] = "sapato";
				i++
				break;
			default:
				cout << "Voce nao digitou opcao valida\n";
		}while(i < 10);
	}
}
// Método para copias o vetor de roupas 
Character::void copiarRoupas(const int *roupasOriginal)
{
	for(int i = 0; i < 10; i++)
	   this->roupas[i] = roupasOriginal[i];
}
// Imprime as roupas do Character
Character::void imprimeRoupas()
{
	for(int i = 0; i < 10; i++)
	   cout << "Roupa: " << roupa[i] << endl;
}
// imprimr dados do Character, função que será sobrescrita pela classe Hero
Character::virtual void imprime()
{
	cout << "Nome: " << this->nome;
	cout << "Idade: " << this->idade;
	cout << "Altura: " << this->altura << endl;
	imprimeRoupas();
}
