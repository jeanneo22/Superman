#include "Superman.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
int main (void) 
{
	Character *personagem = new Superman("Charles",30);
	Hero *heroi = new Superman("Criptonita","C.Kent",33);
	Superman *superman1 = new Superman("Criptonita","Vinicius Sousa",18,1.80,100,4,28,07,1996);
	Superman *superman2 = new Superman(*superman1);
	personagem->imprime();
	heroi->imprime();
	superman1->imprime();
	if(superman1->afetadoKryptonita(3)) cout << "Afetado por kriptonita\n";
	else cout << "Nao e afetado\n";
	superman1->setVisaoRaioX(1);
	superman1->coletarItem(3);
	superman1->usarItem(3);
	superman1->voar(30.0);
	superman1->lutar();
	cout << "Forca Maxima: " << superman1->getForcaMaxima();
	delete personagem;
	delete heroi;
	delete superman1;
	delete superman2;
}