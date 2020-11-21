#include "veterinario.hpp"

Veterinario::Veterinario(string nome, string telefone, string email,
                    string CRMV):
                    Pessoa(nome, telefone, email),
                    CRMV(CRMV){}

Veterinario::~Veterinario(){}

string Veterinario::getCRMV() const {
    return this->CRMV;
}

ostream& Veterinario::printOutDados(ostream& o) const {
    o << "Nome: " << this->getNome() << endl
    << "Email: " << this->getEmail() << endl
    << "Telefone: " << this->getTelefone() << endl
    << "CRMV: " << this->getCRMV() << endl;

    return o;
}