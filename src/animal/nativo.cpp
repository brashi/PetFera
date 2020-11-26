#include "nativo.hpp"

Nativo::Nativo(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso, string regiao, string licenca):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                regiao(regiao), licenca(licenca){}

Nativo::~Nativo(){}

string Nativo::getLicenca() const {
    return this->licenca;
}

string Nativo::getRegiao() const {
    return this->regiao;
}