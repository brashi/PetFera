#include "ave.hpp"

Ave::Ave(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                bool voa):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                voa(voa){}

Ave::~Ave(){}

bool Ave::getVoa() const {
    return this->voa;
}

int Ave::setVoa() {}