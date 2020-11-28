#include "anfibio.hpp"

using std::cout;
using std::cin;

Anfibio::Anfibio(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                bool cauda, bool pata):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                cauda(cauda), pata(pata){}

Anfibio::~Anfibio(){}

bool Anfibio::getCauda() const {
    return this->cauda;
}

bool Anfibio::setCauda() {
    string s;
    cout << endl << "Anfíbio possui cauda? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        cauda = true;
    else if(toupper(s[0]) == 'N')
        cauda = false;
    else
        return false;

    return true;
}

bool Anfibio::getPata() const {
    return this->pata;
}

bool Anfibio::setPata() {
    string s;
    cout << endl << "Anfíbio possui pata? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        pata = true;
    else if(toupper(s[0]) == 'N')
        pata = false;
    else
        return false;

    return true;
}