/** 
  * Fichier:  caesar.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Définition de la classe Caesar
  */

#include "caesar.h"
#include <iostream>

Caesar::Caesar(string message) : Encrypt(message){

}

string Caesar::encode(int decal){
	int car=0;
	this->m_cipher="";
	for(int i=0; i<this->m_plain.size(); i++){
		car= (int)this->m_plain.at(i);
		if((car>96)&&(car<123)){
			car=(car-97+decal)%26 + 97;
		}
		this->m_cipher += (char)car;
	}
	return this->m_cipher;
}

string Caesar::decode(int decal){
	int car=0;
	this->m_plain="";
	for(int i=0; i<this->m_cipher.size(); i++){
		car=(int)this->m_cipher.at(i);
		if((car>96)&&(car<123)){
			car=(car-97-decal)%26 + 97;
		}
		this->m_plain += (char)car;
	}
	return this->m_plain;
}