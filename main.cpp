#include "Character.h"
#include "Hero.h"
#include "Superman.h"
#include "Batman.h"
#include "GreenArrow.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
void imprimeDados(const Character *personagem)
{
	personagem->imprime();
}
int main (void) 
{
	Character *personagem = new Superman("Criptonita","Charles",30);
	Hero *heroi1 = new Superman("Criptonita","C.Kent",33);
	Superman *superman1  = new Superman("Criptonita","Vinicius Sousa",18,1.80,28,07,1996,100,4,50);
	Superman *superman2 = new Superman(*superman1);
	Hero *heroi2 = static_cast<Hero*>(superman1); // Upcasting
	personagem->imprime();
	heroi1->imprime();
	heroi2->imprime();
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
	cout << "Forca Maxima: " << Superman::getForcaMaxima();*/
	delete personagem;
	delete heroi1;
	delete heroi2;
	delete superman1;
	delete superman2;
	Superman *superman1  = new Superman("Criptonita","Vinicius Sousa",18,1.80,28,07,1996,100,4,50);
	Superman *superman2 = new Superman("Criptonita","C. Kent",33);
	Batman *batman1 = new Batman("Fraqueza Humana","B. Wayne",25);
	GreenArrow *arqueiro1 = new GreenArrow("Fraqueza Humana","O. Queen",25);
	imprimeDados(superman1);
	imprimeDados(batman1);
	imprimeDados(arqueiro1);
	vector<Character*> personagens;
	personagens.push_back(superman1);
	personagens.push_back(superman2);
	personagens.push_back(batman1);
	personagens.push_back(arqueiro1);
	for(size_t i = 0; i < personagens.size(); i++) 
	{
		Superman *derivedPtr = dynamic_cast<Superman*>personagens[i];
		if(derivedPtr != 0)
		  derivedPtr.afetadoKryptonita(3);
		  cout << "Afetado por kryptonita\n";
	}
	for ( size_t j = 0; j < personagens.size(); j++ ) 
	{
                  cout << "deletando objeto" 
                          << typeid( *personagens[ j ] ).nome() 
                         << endl; 
                  delete personagens[ j ]; 
	}
	delete superman1;
	delete superman2;
	delete batman1;
	delete arqueiro1;
}