#include "tratador.hpp"

Tratador::Tratador(string nome, string telefone, string email,
                    Uniforme uniforme):
                    Pessoa(nome, telefone, email),
                    uniforme(uniforme){}

Tratador::~Tratador(){}

Uniforme Tratador::getUniforme() const {
    return this->uniforme;
}

ostream& Tratador::printOutDados(ostream& o) const {
    o << "Nome: " << this->getNome() << endl
    << "Email: " << this->getEmail() << endl
    << "Telefone: " << this->getTelefone() << endl
    << "Uniforme: " 
    << (this->getUniforme()==Verde ? "Verde" : this->getUniforme()==Azul ? "Azul" : "Vermelho") << endl;

    return o;
}