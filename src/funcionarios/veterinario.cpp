#include "veterinario.hpp"

#include <iomanip>
#include <iostream>

using std::setfill;
using std::setw;
using std::right;
using std::cout;
using std::cin;

Veterinario::Veterinario(string nome, string telefone, string email,
                    string CRMV):
                    Pessoa(nome, telefone, email),
                    CRMV(CRMV){}

Veterinario::~Veterinario(){}

string Veterinario::getCRMV() const {
    return this->CRMV;
}

bool Veterinario::setCRMV() {
    string s;
    cout << endl << "CRMV: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->CRMV = s;
    
    return true;
}

void Veterinario::setCRMV(string s) {
    this->CRMV = s;
}

ostream& Veterinario::printOutDados(ostream& o) const {
    int tamanhoColuna = 20;
    int espacamento = 3;
    long unsigned int tamanhoTruncado = tamanhoColuna - 3 - espacamento;

    o << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getNome().length() > tamanhoTruncado) ? (this->getNome().substr(0, tamanhoTruncado) + "...") : this->getNome())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getEmail().length() > tamanhoTruncado) ? (this->getEmail().substr(0, tamanhoTruncado) + "...") : this->getEmail())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getTelefone().length() > tamanhoTruncado) ? (this->getTelefone().substr(0, tamanhoTruncado) + "...") : this->getTelefone())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getCRMV().length() > tamanhoTruncado) ? (this->getCRMV().substr(0, tamanhoTruncado) + "...") : this->getCRMV())
    << endl;

    return o;
}