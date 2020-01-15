/** 
  * Fichier:  encrypt.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Janvier 2020
  * Cours:    TP3 C++ 
  * Résumé:   Déclaration de la classe Encrypt
  */
#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>
using namespace std; 

class Encrypt {
public:
    Encrypt();
    Encrypt(string plain);
    string getPlain();
    string getCipher();
    void setPlain(string plain);
    void setCipher(string cipher);
    bool read(bool isPlain, string filename);
    bool write(bool isPlain, string filename);
    string encode();
    string decode();

protected:
    string m_plain;
    string m_cipher;
};

#endif