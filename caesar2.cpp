/** 
  * Fichier:  caesar2.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Définition de la classe Caesar2
  */

#include "caesar2.h"

Caesar2::Caesar2() : Encrypt() {
}

Caesar2::Caesar2(string message) : Encrypt(message) {
}

string Caesar2::encode(int decal) {
    int car = 0;
    this->m_cipher = "";
    for (int i = 0; i < this->m_plain.size(); i++) {
        car = (int)this->m_plain.at(i);
        if ((car>31) && (car<127)) {
            car = (car-32+decal)%95+32;
        }
        this->m_cipher += (char)car;
    }
    return this->m_cipher;
}

string Caesar2::decode(int decal) {
    int car = 0;
    this->m_plain = "";
    for (int i = 0; i < this->m_cipher.size(); i++) {
        car = (int)this->m_cipher.at(i);
        if ((car>31) && (car<127)) {
            car = (car-32-decal+95)%95+32;
        }
        this->m_plain += (char)car;
    }
    return this->m_plain;
}