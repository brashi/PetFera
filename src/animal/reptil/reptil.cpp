#include "reptil.hpp"

using std::cout;
using std::cin;

Reptil::Reptil(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                Pele pele):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                pele(pele){}

Reptil::~Reptil(){}

Pele Reptil::getPele() const {
    return this->pele;
}

bool Reptil::setPele() {
    string s;
    cout << endl << "Qual o tipo de pele do réptil? (S/N): " << endl;
    cout << "C - carapaça" << endl;
    cout << "E - escama" << endl;
    cout << "P - placa" << endl;
    getline(cin, s);

    switch(toupper(s[0])) {
        case 'C':
            this->pele = Carapaca;
            break;
        case 'E':
            this->pele = Escama;
            break;
        case 'P':
            this->pele = Placa;
            break;
        default:
            return false;
            break;
    }

    return true;
}

void Reptil::setPele(Pele p) {
    this->pele = p;
}