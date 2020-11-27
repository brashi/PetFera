#include "domestico.hpp"

Domestico::Domestico(bool adestrado):
                adestrado(adestrado){}

Domestico::~Domestico(){}

bool Domestico::getAdestrado() const {
    return this->adestrado;
}

int Domestico::setAdestrado() {}