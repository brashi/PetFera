#include "domestico.hpp"

Domestico::Domestico(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso, bool adestrado):
                Animal(nome, especie, veterinario, tratador, perigoso),
                adestrado(adestrado){}

Domestico::~Domestico(){}

bool Domestico::getAdestrado() const {
    return this->adestrado;
}

ostream& Domestico::printOutDados(ostream& o) const {
    o << "Teste de animal DOMESTICO de base" << endl;
    o << this->getNome() << " " << this->getEspecie() << endl;

    return o;
}