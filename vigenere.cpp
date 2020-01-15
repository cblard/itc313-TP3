/** 
  * Fichier:  vigenere.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Déclaration de la classe Vigenere
  */

#include "vigenere.h"
#include <iostream>
using namespace std;

Vigenere::Vigenere() : Encrypt() {
    this->m_key = "";
}

Vigenere::Vigenere(string key) : Encrypt() {
    this->m_key = key;
}

string Vigenere::encode() {
    int car=0, decal;
    this->m_cipher = "";
    for (int i = 0; i < this->m_plain.size(); i++) {
        if ((this->m_plain.at(i) >= 'A') && (this->m_plain.at(i) <= 'Z')) {
            decal = (int)(this->m_key.at(i % this->m_key.size()))-65;
            car= ((int)(this->m_plain.at(i)) - 65 + decal) % 26 + 65;
            this->m_cipher += (char)car;
        }
        else {
            this->m_cipher += this->m_plain.at(i);
        }
    }
    return this->m_cipher;
}

string Vigenere::decode() {
    int car = 0, decal;
    this->m_plain = "";
    for (int i = 0; i < this->m_cipher.size(); i++) {
        if ((this->m_cipher.at(i) >= 'A') && (this->m_cipher.at(i) <= 'Z')) {
            decal = (int)(this->m_key.at(i % this->m_key.size())) - 65;
            car = ((int)this->m_cipher.at(i) - 65 - decal) % 26 + 65;
            this->m_plain += (char)car;
        }
        else {
            this->m_plain += this->m_cipher.at(i);
        }
    }
    return this->m_plain;
}