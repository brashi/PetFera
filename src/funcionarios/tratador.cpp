#include "tratador.hpp"

#include <iomanip>
#include <iostream>

using std::setfill;
using std::setw;
using std::right;
using std::cout;
using std::cin;

Tratador::Tratador(string nome, string telefone, string email,
                    Uniforme uniforme):
                    Pessoa(nome, telefone, email),
                    uniforme(uniforme){}

Tratador::~Tratador(){}

Uniforme Tratador::getUniforme() const {
    return this->uniforme;
}

bool Tratador::setUniforme() {
    string s;
    cout << endl << "Nível de segurança do tratador: " << endl;
    cout << "V - verde" << endl;
    cout << "A - azul" << endl;
    cout << "M - vermelho" << endl;
    getline(cin, s);

    switch(toupper(s[0])) {
        case 'V':
            this->uniforme = Verde;
            break;
        case 'A':
            this->uniforme = Azul;
            break;
        case 'M':
            this->uniforme = Vermelho;
            break;
        default:
            return false;
            break;
    }

    return true;
}

void Tratador::setUniforme(Uniforme u) {
    this->uniforme = u;
}

ostream& Tratador::printOutDados(ostream& o) const {
    int tamanhoColuna = 20, espacamento = 3;
    int tamanhoTruncado = tamanhoColuna - 3 - espacamento;

    o << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getNome().length() > tamanhoTruncado) ? (this->getNome().substr(0, tamanhoTruncado) + "...") : this->getNome())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getEmail().length() > tamanhoTruncado) ? (this->getEmail().substr(0, tamanhoTruncado) + "...") : this->getEmail())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getTelefone().length() > tamanhoTruncado) ? (this->getTelefone().substr(0, tamanhoTruncado) + "...") : this->getTelefone())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << (this->getUniforme()==Verde ? "Verde" : this->getUniforme()==Azul ? "Azul" : "Vermelho")
    << endl;

    return o;
}