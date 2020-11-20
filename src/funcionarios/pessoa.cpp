#include "pessoa.hpp"

Pessoa::Pessoa(){}

Pessoa::Pessoa(string nome, string telefone, string email):
                nome(nome), telefone(telefone),
                email(email){}

Pessoa::~Pessoa(){}

string Pessoa::getNome() const {
    return this->nome;
}

string Pessoa::getTelefone() const {
    return this->telefone;
}

string Pessoa::getEmail() const {
    return this->email;
}