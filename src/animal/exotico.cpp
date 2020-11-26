#include "exotico.hpp"

Exotico::Exotico(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                local(local){}

Exotico::~Exotico(){}

string Exotico::getLocal() const {
    return this->local;
}