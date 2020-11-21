#include "nativo.hpp"

Nativo::Nativo(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao):
                Animal(nome, especie, veterinario, tratador, perigoso),
                regiao(regiao){}

Nativo::~Nativo(){}

string Nativo::getRegiao() const {
    return this->regiao;
}