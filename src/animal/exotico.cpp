#include "exotico.hpp"

Exotico::Exotico(string local):
                local(local){}

Exotico::~Exotico(){}

string Exotico::getLocal() const {
    return this->local;
}