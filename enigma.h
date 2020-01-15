#ifndef ENIGMA_H
#define ENIGMA_H

#include "encrypt.h"

class Enigma : public Encrypt {

private:
    string m_key1;
    string m_key2;
    int m_posKey1;
    int m_posKey2;

public:
    Enigma();
    Enigma(string key1, int posKey1);
    Enigma(string key1, int posKey1, string key2, int posKey2);

public:
    string encode();
    string decode();
};

#endif