#include "Hero.h"
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::endl;
using std::cout;

// Sobrecarga do operador << para a classe Hero
ostream &operator<<( ostream &output,const Hero &hero)
{
	output << "Nome: " << hero.nome << "Idade: " << hero.idade
	<< "Altura: " << hero.altura << endl << "Fraqueza: " << hero.fraqueza << endl;
	
	return output;
}
// Sobrecarga do operador de atribução para a classe Hero
Hero &Hero::operator=( const Hero &heroDireita) 
{	
	nome = heroDireita.nome;
	idade = heroDireita.idade;
	altura = heroDireita.altura;
	fraqueza = heroDireita.fraqueza;
	numeroPessoasSalvas = heroDireita.numeroPessoasSalvas;
	
	return *this;
}
// Construtor para a classe Hero
Hero::Hero(const string &fraqueza,const string &nome,const int &idade,const float &altura,const int &diaNascimento,const int &mesNascimento,const int &anoNascimento) : 
		Character(nome,idade,altura)
{
	setFraqueza(fraqueza);
	setNumeroPessoasSalvas(0);
	alocarPessoasSalvas();
}
// Construtor de cópia para a classe Hero
Hero::Hero(const Hero &heroOriginal) : Character(heroOriginal.nome,heroOriginal.idade,heroOriginal.altura)
{
	this->fraqueza = heroOriginal.fraqueza;
	this->numeroPessoasSalvas = heroOriginal.numeroPessoasSalvas;
	copiarPessoasSalvas(heroOriginal.pessoasSalvas);
}
// Destrutor
Hero::virtual ~Hero() 
{
	delete []pessoasSalvas;
}
Hero::setFraqueza(const string &fraqueza)
{
	this->fraqueza = fraqueza;
}
Hero::void setNumeroPessoasSalvas(const int &numeroPessoasSalvas)
{
	this->numeroPessoasSalvas = (numeroPessoasSalvas >= 0)? numeroPessoasSalvas:0;

}
/* Aloca um vetor que guarda o nome das pessoas salvas
 * por Hero, o número máximo de pessoas salvas é 50 */
Hero::void alocarPessoasSalvas()
{
	this->pessoasSalvas[] = new string[50];
	for(int i = 0; i < 50; i++)
	    this->pessoasSalvas[i] = "nenhuma";
}
// Método para copiar o vetor de pessoas salvas
Hero::void copiarPessoasSalvas(const string *pessoaSalvasOriginal)
{
	for(int i = 0; i < 50; i++)
	   this->pessoasSalvas[i] = pessoaSalvasOriginal[i];
	   
}
// Método usado para salvar uma pessoa
Hero::void salvar()
{
		string pessoa;
		cout << "Pessoa para salvar\n";
		cin >> pessoa;
		this->numeroPessoasSalvas++
		pessoasSalvas[this->numeroPessoasSalvas] = pessoa; 
}
// Imprime dados de Hero, função sobrescrita pela classe Superman
Hero:: virtual void imprime()
{
	this->Character::imprime();
	cout << "Fraqueza: " << this->fraqueza << endl;
}

	
