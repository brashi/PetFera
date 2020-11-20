#include "nativo.hpp"

Nativo::Nativo(string regiao):
                regiao(regiao){}

Nativo::~Nativo(){}

string Nativo::getRegiao() const {
    return this->regiao;
}