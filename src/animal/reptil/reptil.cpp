#include "reptil.hpp"

Reptil::Reptil(Pele pele):
                pele(pele){}

Reptil::~Reptil(){}

Pele Reptil::getPele() const {
    return this->pele;
}