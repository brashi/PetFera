#include "veterinario.hpp"

Veterinario::Veterinario(string nome, string telefone, string email,
                    string CRMV):
                    Pessoa(nome, telefone, email),
                    CRMV(CRMV){}

Veterinario::~Veterinario(){}

string Veterinario::getCRMV() const {
    return this->CRMV;
}