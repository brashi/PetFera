#include "domestico.hpp"

using std::endl;
using std::cout;
using std::cin;

Domestico::Domestico(bool adestrado):
                adestrado(adestrado){}

Domestico::~Domestico(){}

bool Domestico::getAdestrado() const {
    return this->adestrado;
}

bool Domestico::setAdestrado() {
    string s;
    cout << endl << "Animal é adestrado? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        this->adestrado = true;
    else if(toupper(s[0]) == 'N')
        this->adestrado = false;
    else
        return false;

    return true;
}

void Domestico::setAdestrado(bool b) {
    this->adestrado = b;
}