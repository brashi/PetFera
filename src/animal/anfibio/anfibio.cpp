#include "anfibio.hpp"

Anfibio::Anfibio(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador, bool perigoso,
                bool cauda, bool pata):
                Animal(nome, especie, ameacadoPor, veterinario, tratador, perigoso),
                cauda(cauda), pata(pata){}

Anfibio::~Anfibio(){}

bool Anfibio::getCauda() const {
    return this->cauda;
}

int Anfibio::setCauda() {}

bool Anfibio::getPata() const {
    return this->pata;
}

int Anfibio::setPata() {}