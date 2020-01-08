/** 
  * Fichier:  caesar2.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Déclaration de la classe Caesar2
  */

#ifndef CAESAR2_H
#define CAESAR2_H

#include "encrypt.h"
#include <string>
using namespace std; 

class Caesar2 : public Encrypt {
public:
    Caesar2();
    Caesar2(string message);
    string encode(int decal);
    string decode(int decal);
};

#endif