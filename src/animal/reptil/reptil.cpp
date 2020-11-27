#include "reptil.hpp"

Reptil::Reptil(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                Pele pele):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                pele(pele){}

Reptil::~Reptil(){}

Pele Reptil::getPele() const {
    return this->pele;
}