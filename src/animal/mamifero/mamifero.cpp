#include "mamifero.hpp"

Mamifero::Mamifero(string gestacao):
                gestacao(gestacao){}

Mamifero::~Mamifero(){}

string Mamifero::getGestacao() const {
    return this->gestacao;
}