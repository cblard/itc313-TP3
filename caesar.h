/** 
  * Fichier:  caesar.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Déclaration de la classe Caesar
  */
#ifndef CAESAR_H
#define CAESAR_H

#include "encrypt.h"
#include <string>
using namespace std; 


class Caesar: public Encrypt{
public:
    Caesar(string message);
    string encode(int decal);
    string decode(int decal);

};

#endif