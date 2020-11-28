#include "mamifero.hpp"

using std::cout;
using std::cin;

Mamifero::Mamifero(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                bool gestacao):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                gestacao(gestacao){}

Mamifero::~Mamifero(){}

bool Mamifero::getGestacao() const {
    return this->gestacao;
}

bool Mamifero::setGestacao() {
    string s;
    cout << endl << "Mamífero possui gestação? (S/N): " << endl;
    getline(cin, s);

    if(toupper(s[0]) == 'S')
        this->gestacao = true;
    else if(toupper(s[0]) == 'N')
        this->gestacao = false;
    else
        return false;

    return true;
}

void Mamifero::setGestacao(bool b) {
    this->gestacao = b;
}