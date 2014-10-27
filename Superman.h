// força máxima do Superman,resistencia atual, afetado por kryptonita,visão de calor ativada e em que nível
// 4 atributos,4 funções membros sem incluir get e set - ok
// Todos os atributos devem ser inicializados - ok
// 3 construtores, incluindo um construtor de cópia e um construtor com parâmetros defaults - ok
// 1 atributo string, 1 atributo static, 1 atributo const static  - ok
// 2 métodos constantes - ok
// 1 array - ok
// Uma função inline - ok
// método com passagem de referencia usando ponteiro - ok
// método static - ok
// Composição com a classe Data - ok
// Operator = - ok
// Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada - ok
// Usar o destrutor -ok
// Operator << friend - ok
// vector push_back - ok
/*Requisitos para quarta tarefa: 
Diagrama de classes (obrigatório salvar também o png do diagrama no gitHub)
Herança pública - ok
Construtor de cópia, e sobrecargas dos operadores de atribuição (=) e << (cout << base) para a classe base e derivada - ok
Usar Protected acessando diretamente os atributos na classe derivada - ok
Alocação dinâmica de memória na classe base e derivada  - ok
Sobrescrita de método: chamar dentro do método da classe derivada o método correspondente da classe base usando :: -ok
No main: criar um ponteiro da classe base para alocar memória para a classe derivada e chamar os vários métodos implementados - ok*/

/* O projeto é similar a um jogo onde o Superman tem poderes como visão de calor, superForca, visao de Raio X entre outros
 * coleta itens de força,luta e visita planetas
 */
 
 
 
#include <string>
#include <vector>
using std::string;
using std::ostream;

#ifndef SUPERMAN_H
#define SUPERMAN_H

class Superman : public Hero
{
	friend ostream &operator<<( ostream &,const Superman &);
private:
	int resistenciaAtual; // resistencia Atual do Superman
	int nivelVisaoCalor; // Nivel da visão de calor
	int visaoRaioX; // Visaõ de RaioX 1-ativada 0-desativada
	float superForca; // superForca do Superman
	int *itemForca; // vetor de itens de força 
	vector <string> planetasVisitados; // guarda planetas visitados pleo Superman
	
	static int contSuperman;
	const static float forcaMaxima; // força maxima do superman em quintilhões de toneladas
public:
	Superman &operator=( const Superman & );
	Superman(const string & = "nenhuma",const string & = "sem nome",const int & = 0,const float & = 0.00,const int & = 1,const int = 1, const int & = 1900,const int & = 0,const int & = 0,cons float 0.0);
	Superman(const Superman &);
	Superman(const int &);
	~Superman();
	void setResistenciaAtual(const int &);
	void setNivelVisaoCalor(const int &);
	void setVisaoRaioX(const int &);
	void setSuperForca(const float &);
	int getResistenciaAtual();
	int getNivelVisaoCalor();
	int getVisaoRaioX();
	float getSuperForca();
	void alocarItemForca();
	void copiarItemForca(const int *);
	void lutar();
	void coletarItem(const int &);
	void usarItem(const int &);
	void aumentaResistencia(const int &);
	void aumentaNivelVisaoCalor(const int &);
	void aumentaSuperForca(const int&);
	int visaoCalor() const;
	void voar(const float &) const;
	inline int afetadoKryptonita(const int &Krypt) { return (Krypt == 1); }
	void mostrarPlanetas();
	void imprimePlanetasVisitados();
	void visitarPlaneta();
	void atualizarPlanetasVisitados();
	void imprime();
	static float getForcaMaxima();
};

#endif // SUPERMAN_H