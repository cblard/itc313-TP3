#include "enigma.h"
#include <iostream>

Enigma::Enigma(string cleEnigma1, int posKey1, string cleEnigma2, int posKey2) : Encrypt() {
    this->m_key1 = cleEnigma1;
    this->m_key2 = cleEnigma2;
    this->m_posKey1 = posKey1;
    this->m_posKey2 = posKey2;
    // On rétablit les positions si la valeur est supérieur à la taille de l'alhapabet.
    if (this->m_posKey1 < 0) {
        this->m_posKey1 = 26 - (-this->m_posKey1 % 26);
    }
    else {
        this->m_posKey1 %= 26;
    }
    if (this->m_posKey2 < 0) {
        this->m_posKey2 = 26 - (-this->m_posKey2 % 26);
    }
    else {
        this->m_posKey2 %= 26;
    }
}

string Enigma::encode() {
    int charPlain = 0;
    int charCipher = 0;
    this->m_cipher = "";
    int size = 0;

    for (int j = 0; j <= (int)this->m_plain.size()-1; j++) {
        if ((this->m_plain.at(j) >= 'A') && (this->m_plain.at(j) <= 'Z')) {
            size++;
            charPlain = (int)this->m_plain.at(j) - 65;
            charCipher = this->m_key1.at((charPlain + this->m_posKey1) % 26);

            charPlain = charCipher - 65;
            charCipher = this->m_key2.at((charPlain + this->m_posKey2) % 26);

            if (this->m_posKey1 == 25) {
                this->m_posKey1 = 1;
            }
            else {
                this->m_posKey1++;
            }
            if ((size % 26 == 0) && (size != 0)) {
                if (this->m_posKey2 == 25) {
                    this->m_posKey2 = 1;
                }
                else {
                    this->m_posKey2++;
                }
            }

            this->m_cipher += (char)charCipher;
        }
        else {
            this->m_cipher += this->m_plain.at(j);
        }
    }
    return this->m_cipher;
}

string Enigma::decode() {
    int charPlain = 0;
    int charCipher = 0;
    this->m_plain = "";
    int size = 0;
    for (int i = 0; i < this->m_cipher.size(); i++) {
        if ((this->m_cipher.at(i) >= 'A') && (this->m_cipher.at(i) <= 'Z')) {
            size++;
            charCipher = (int)this->m_cipher.at(i) - 65;
            charPlain = this->m_key2.find((char)charCipher + 65);

            charCipher = (charPlain - this->m_posKey2 + 26) % 26 + 65;
            charPlain = (this->m_key1.find((char)charCipher) - this->m_posKey1 + 26) % 26 + 65;

            if ((size % 26 == 0) && (size != 0)) {
                if (this->m_posKey2 == 25) {
                    this->m_posKey2 = 1;
                }
                else {
                    this->m_posKey2++;
                }
            }
            if (this->m_posKey1 == 25) {
                this->m_posKey1 = 1;
            }
            else {
                this->m_posKey1++;
            }

            this->m_plain += (char)charPlain;
        }
        else {
            this->m_plain += this->m_cipher.at(i);
        }
    }
    return this->m_plain;
}