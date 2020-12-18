#include "ave.hpp"

using std::cout;
using std::cin;

Ave::Ave(string nome, string especie, string ameacadoPor, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador, bool perigoso,
                bool voa):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                voa(voa){}

Ave::~Ave(){}

bool Ave::getVoa() const {
    return this->voa;
}

bool Ave::setVoa() {
    string s;
    cout << endl << "Ave voa? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        this->voa = true;
    else if(toupper(s[0]) == 'N')
        this->voa = false;
    else
        return false;

    return true;
}

void Ave::setVoa(bool b) {
    this->voa = b;
}