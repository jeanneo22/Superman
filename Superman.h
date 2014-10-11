#include <string>
using std::string;
using std::ostream;

#ifndef SUPERMAN_H
#define SUPERMAN_H

class Superman
{
	friend ostream &operator<<( ostream &,const Superman &);
private:
	double forcaMaxima; // força do superman em quintilhões de toneladas
	int resistenciaAtual;
	int nivelVisaoCalor;
	string nome; // nome terrestre do superman
	
	static int idade;
	static int niveisVisaoCalor[6];
	const static float altSuperman;
public:
	Superman &operator=( const Superman & );
	Superman(const Superman &);
	Superman(double = 200,int = 100, int = 4, string = "Clark Kent");
	Superman(double forcaMaxima);
	~Superman();
	void setForcaMaxima(double);
	void setResistenciaAtual(int);
	void setNivelVisaoCalor(int);
	void setNome(string);
	void lutar();
	inline int afetadoKryptonita(const int &nivelKrypt) { return (nivelKrypt > 0); }
	int visaoCalor() const;
	void voar(float) const;
	static void setNiveisVisaoCalor();
	static void mostrarInfo();
};

#endif // SUPERMAN_H
