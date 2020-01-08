/** 
  * Fichier:  main.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Fichier utilisé pour les tests des différentes classes
  */

#include "encrypt.h"
#include "caesar.h"
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
	string code = Cesar.encode(3);
	cout << "Message codé : " << code << endl;


	string messageCesar2= "dohd mdfwd hvw";
	Caesar Cesar2(messageCesar2);
	Cesar2.setCipher(messageCesar2);
	string decode = Cesar2.decode(3);
	cout << "Message décodé : " << decode << endl;

	return 0;
}