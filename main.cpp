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
#include "vigenere.h"
#include "enigma.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <time.h>
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
	cout << "Message codé (Caesar) : " << code << "\n";

	Caesar Cesar2("");
	Cesar2.read(false, "MessageDeCesarCode");
	string decode = Cesar2.decode(3);
	cout << "Message décodé (Caesar) : " << decode << "\n";

	// Test de la classe Caesar2
	string sanglots="Les sanglots longs Des violons De l'automne Blessent mon coeur D'une langueur Monotone.";
	Caesar2 Poeme(sanglots);
	Poeme.write(true, "Poeme");
	code = Poeme.encode(3);
	cout << "Message codé (Caesar2) : "<< code << "\n";

	Caesar2 Poeme2("");
	Poeme2.read(false, "PoemeCode");
	decode = Poeme2.decode(3);
	cout << "Message décodé (Caesar2) : "<<decode<<"\n";

	// Test de la classe Vigenere 
	Vigenere Vig("TEST");
	Vig.setPlain("ETRE OU NE PAS ETRE TELLE EST LA QUESTION");
	code = Vig.encode();
	cout << "\nMessage codé (Vigenere) : "<<code; 
	Vigenere Vig2("TEST");
	Vig2.setCipher("XXJX SM GI ITW XMVW MIDEX WLM DT UMXLXAHG");
	decode = Vig2.decode();
	//cout << "\nMessage décodé (Vigenere) : "<<decode; 	// DÉCODAGE VALABLE POUR LA MOITIÉ DES CARACTÈRES ?? 
														// À CORRIGER !!!

	// Test de la classe Enigma
	
    Enigma Enigm("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 120, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 120);
    Enigm.setPlain("TEST");
    cout<<"\nMessage à coder : "<<Enigm.getPlain();
    code= Enigm.encode();
    cout<<"\nMessage codé (Enigma) : "<<code;
    Enigm.setCipher("ZLAC");
    decode= Enigm.decode();
    cout<<"\nMessage décodé (Enigma) : "<<decode;   // DÉCODAGE NON FONCTIONNEL ? 
    												// À CORRIGER


    
	return 0;
}