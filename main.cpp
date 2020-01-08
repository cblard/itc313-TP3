/** 
  * Fichier:  main.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Fichier utilisé pour les tests des différentes classes
  */

#include "encrypt.h"
#include <iostream>
#include <string>
using namespace std; 

int main(){
	string test="Bonjour";
	Encrypt message(test);
	message.write(true, "fichier");
	return 0;
}