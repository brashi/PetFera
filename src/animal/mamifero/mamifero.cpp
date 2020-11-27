#include "mamifero.hpp"

Mamifero::Mamifero(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                bool gestacao):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                gestacao(gestacao){}

Mamifero::~Mamifero(){}

bool Mamifero::getGestacao() const {
    return this->gestacao;
}

int Mamifero::setGestacao() {}