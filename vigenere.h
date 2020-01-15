/** 
  * Fichier:  vigenere.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Déclaration de la classe Vigenere
  */

#ifndef VIGENERE_H
#define VIGENERE_H

#include "encrypt.h"
#include <string>
using namespace std; 

class Vigenere : public Encrypt {

private:
    string m_key;

public:
    Vigenere();
    Vigenere(string key);
    string encode();
    string decode();
};

#endif

