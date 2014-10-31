#include "Character.h"
#include "Hero.h"
#include "Superman.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
int main (void) 
{
	Character *personagem = new Superman("Criptonita","Charles",30);
	Hero *heroi = new Superman("Criptonita","C.Kent",33);
	Superman *superman1 = new Superman("Criptonita","Vinicius Sousa",18,1.80,28,07,1996,100,4,50);
	Superman *superman2 = new Superman(*superman1);
	personagem->imprime();
	heroi->imprime();
	superman1->imprime();
	if(superman1->afetadoKryptonita(3)) cout << "Afetado por kriptonita\n";
	else cout << "Nao e afetado por kryptonita\n";
	superman1->setVisaoRaioX(1);
	superman1->coletarItem(4);
	superman1->usarItem(4);
	superman1->voar(30.0);
	superman1->lutar();
	cout << (*personagem);
	cout << (*heroi);
	cout << (*superman2);
	cout << "Forca Maxima: " << Superman::getForcaMaxima();
	delete personagem;
	delete heroi;
	delete superman1;
	delete superman2;
}