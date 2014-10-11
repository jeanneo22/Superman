#include <iostream>
#include <string>
#include "Superman.h"
#include "Data.h"
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	Data dataAtual(06,10,2014);
	dataAtual.print();
	Superman *s1ptr,*s2ptr;
	s1ptr = new Superman;
	Superman::mostrarInfo();
	s1ptr->lutar();
	if (s1ptr->afetadoKryptonita(3)) cout << "Afetado por kryptonita\n";
	else cout << "Nao esta sendo afetado por kryptonita\n";
	cout << s1ptr << endl;
	s1ptr = s2ptr;
	s1ptr->voar(20.0);
	delete s1ptr;
	return 0;
}
