#include "exotico.hpp"

Exotico::Exotico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string local):
                Animal(nome, especie, veterinario, tratador, perigoso),
                local(local){}

Exotico::~Exotico(){}

string Exotico::getLocal() const {
    return this->local;
}