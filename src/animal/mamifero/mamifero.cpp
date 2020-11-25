#include "mamifero.hpp"

Mamifero::Mamifero(bool gestacao):
                gestacao(gestacao){}

Mamifero::~Mamifero(){}

bool Mamifero::getGestacao() const {
    return this->gestacao;
}