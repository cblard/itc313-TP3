/** 
  * Fichier:  encrypt.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Définition de la classe Encrypt
  */

#include "encrypt.h"
#include <fstream>
#include <iostream>

using namespace std; 

Encrypt::Encrypt(){

}

Encrypt::Encrypt(string plain){
	m_plain = plain;
}

string Encrypt::getPlain(){
	return m_plain;
}

string Encrypt::getCipher(){
	return m_cipher;
}

void Encrypt::setCipher(string cipher){
	m_cipher=cipher;
}
bool Encrypt::read(bool isPlain, string filename){
	ifstream flux(filename);
	if(flux){
		string message;
		while (getline(flux, message)){
			cout << "Contenu du fichier : " << message << endl;
			if(isPlain==true){
				m_plain = message;
			}
			else{
				m_cipher = message;
			}
		}
	}
	else {
		cout << "Erreur : le fichier ne peut pas être ouvert." << endl;
		return false;
	}
	return true;
}

bool Encrypt::write(bool isPlain, string filename){
	ofstream flux(filename);
	if(flux){
		if(isPlain==true){
			flux << m_plain;
		}
		else{
			flux << m_cipher; 
		}
	}
	else {
		cout << "Erreur : le fichier ne peut pas être ouvert." << endl;
		return false ;
	}
	return true;
}

string Encrypt::encode(){
	m_cipher=m_plain;
	return m_cipher; 
}
    
string Encrypt::decode(){
	m_plain=m_cipher;
	return m_plain; 
}
