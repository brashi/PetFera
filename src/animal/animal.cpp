#include "animal.hpp"

// Classes de animais
#include "ave.hpp"
#include "anfibio.hpp"
#include "reptil.hpp"

// Classificacao
#include "exotico.hpp"
#include "nativo.hpp"

#include <iomanip>
#include <iostream>

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::cout;
using std::endl;

Animal::Animal(string nome, string especie, Veterinario veterinario, Tratador tratador,
                bool perigoso):
                nome(nome), especie(especie), veterinario(veterinario), tratador(tratador),
                perigoso(perigoso){}

Animal::~Animal(){}

string Animal::getNome() const {
    return this->nome;
}

string Animal::getEspecie() const {
    return this->especie;
}

Veterinario Animal::getVeterinario() const {
    return this->veterinario;
}

Tratador Animal::getTratador() const {
    return this->tratador;
}

bool Animal::getPerigoso() const {
    return this->perigoso;
}

string Animal::getClassificacao(Animal* animal) const {
    if(Exotico* teste = dynamic_cast< Exotico* >(animal)) {
        return "Silvestre Exótico";
    } if(Nativo* teste = dynamic_cast< Nativo* >(animal)) {
        return "Silvestre Nativo";
    } else {
        return "Doméstico";
    }
}

string Animal::getClasse(Animal* animal) const {
    if(Ave* teste = dynamic_cast< Ave* >(animal)) {
        return "Ave";
    } if(Anfibio* teste = dynamic_cast< Anfibio* >(animal)) {
        return "Anfíbio";
    } if(Reptil* teste = dynamic_cast< Reptil* >(animal)) {
        return "Réptil";
    } else {
        return "Mamífero";
    }
}

ostream& Animal::printOutDados(ostream& o, Animal* animal) const {
    int tamanhoColuna = 16;
    int espacamento = 3;
    int tamanhoTruncado = tamanhoColuna - 3 - espacamento;

    o << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getNome().length() > tamanhoTruncado) ? (this->getNome().substr(0, tamanhoTruncado) + "...") : this->getNome())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getEspecie().length() > tamanhoTruncado) ? (this->getEspecie().substr(0, tamanhoTruncado) + "...") : this->getEspecie())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getVeterinario().getNome().length() > tamanhoTruncado) ? (this->getVeterinario().getNome().substr(0, tamanhoTruncado) + "...") : this->getVeterinario().getNome())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getTratador().getNome().length() > tamanhoTruncado) ? (this->getTratador().getNome().substr(0, tamanhoTruncado) + "...") : this->getTratador().getNome())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << (this->getPerigoso()? "Sim" : "Não")
    << setfill(' ') << setw(tamanhoColuna + espacamento) << this->getClassificacao(animal)
    << setfill(' ') << setw(tamanhoColuna + espacamento) << this->getClasse(animal)
    << endl;

    return o;
}

ostream& operator<< (ostream& o, Animal& animal) {
    return animal.printOutDados(o, &animal);
}