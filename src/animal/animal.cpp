#include "animal.hpp"

Animal::Animal(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso):
                nome(nome), especie(especie), veterinario(veterinario), tratador(tratador),
                perigoso(perigoso){}

Animal::~Animal(){}

string Animal::getNome() const {
    return this->nome;
}

string Animal::getEspecie() const {
    return this->especie;
}

Veterinario Animal::getVeterinario() const {
    return this->veterinario;
}

Tratador Animal::getTratador() const {
    return this->tratador;
}

bool Animal::getPerigoso() const {
    return this->perigoso;
}