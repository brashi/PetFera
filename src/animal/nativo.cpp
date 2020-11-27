#include "nativo.hpp"

Nativo::Nativo(string regiao, string licenca):
                regiao(regiao), licenca(licenca){}

Nativo::~Nativo(){}

string Nativo::getLicenca() const {
    return this->licenca;
}

string Nativo::setLicenca() {}

string Nativo::getRegiao() const {
    return this->regiao;
}

string Nativo::setRegiao() {}