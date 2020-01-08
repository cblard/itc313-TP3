/** 
  * Fichier:  main.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Fichier utilisé pour les tests des différentes classes
  */

#include "encrypt.h"
#include "caesar.h"
#include "caesar2.h"
#include <iostream>
#include <string>
using namespace std; 

int main(){
	// Test de la classe Encrypt
	string test="Bonjour";
	Encrypt message(test);
	message.write(true, "fichier");

	// Test de la classe Caesar
	string messageCesar="alea jacta est";
	Caesar Cesar(messageCesar);
	Cesar.write(true, "MessageDeCesar");
	string code = Cesar.encode(3);
	cout << "Message codé : " << code << "\n";

	Caesar Cesar2("");
	Cesar2.read(false, "MessageDeCesarCode");
	string decode = Cesar2.decode(3);
	cout << "Message décodé : " << decode << "\n";

	// Test de la classe Caesar2
	string sanglots="Les sanglots longs Des violons De l'automne Blessent mon coeur D'une langueur Monotone.";
	Caesar2 Poeme(sanglots);
	Poeme.write(true, "Poeme");
	code = Poeme.encode(3);
	cout << "Message codé : "<< code << "\n";

	Caesar2 Poeme2("");
	Poeme2.read(false, "PoemeCode");
	decode = Poeme2.decode(3);
	cout << "Message décodé : "<<decode<<"\n";
	return 0;
}