#include "../../../include/animal/anfibio/anfibio.hpp"

Anfibio::Anfibio(bool cauda, bool pata):
                cauda(cauda), pata(pata){}

Anfibio::~Anfibio(){}

bool Anfibio::getCauda() const {
    return this->cauda;
}

bool Anfibio::getPata() const {
    return this->pata;
}