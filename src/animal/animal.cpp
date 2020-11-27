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
using std::right;
using std::cout;
using std::cin;

Animal::Animal(string nome, string especie, string ameacadoPor, Veterinario veterinario, Tratador tratador,
                bool perigoso):
                nome(nome), especie(especie), ameacadoPor(ameacadoPor), veterinario(veterinario), tratador(tratador),
                perigoso(perigoso){}

Animal::~Animal(){}

string Animal::getNome() const {
    return this->nome;
}

void Animal::setNome() {}

string Animal::getEspecie() const {
    return this->especie;
}

void Animal::setEspecie() {}

string Animal::getAmeacadoPor() const {
    return this->ameacadoPor;
}

void Animal::setAmeacadoPor() {}

Veterinario Animal::getVeterinario() const {
    return this->veterinario;
}

void Animal::setVeterinario() {}

Tratador Animal::getTratador() const {
    return this->tratador;
}

void Animal::setTratador() {}

bool Animal::getPerigoso() const {
    return this->perigoso;
}

void Animal::setPerigoso() {}

string Animal::getClassificacao(Animal* animal) const {
    if(Exotico* teste = dynamic_cast< Exotico* >(animal)) {
        return "Silvestre Exótico";
    } if(Nativo* teste = dynamic_cast< Nativo* >(animal)) {
        return "Silvestre Nativo";
    } else {
        return "Doméstico";
    }
}

string Animal::setClassificacao() {
    string s;
    cout << endl << "A que categoria o animal pertence?..." << endl;
    cout <<         "D - doméstico" << endl;
    cout <<         "E - exótico"   << endl;
    cout <<         "N - nativo"    << endl;
    getline(cin, s);

    if(s.size() == 0)
        return {};
    else
        switch(toupper(s[0])) {
            case 'D':
                return "D";
                break;
            case 'E':
                return "E";
                break;
            case 'N':
                return "N";
                break;
        }

    return {}; // Não retornou nada (falhou), retorne vazio
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

string Animal::setClasse() {
    string s;
    cout << endl << "O animal pertence a que classe?..." << endl;
    cout <<         "A - ave"       << endl;
    cout <<         "F - anfíbio"   << endl;
    cout <<         "R - réptil"    << endl;
    cout <<         "M - mamífero"  << endl;
    getline(cin, s);

    if(s.size() == 0)
        return {};
    else
        switch(toupper(s[0])) {
            case 'A':
                return "ave";
                break;
            case 'F':
                return "anf";
                break;
            case 'R':
                return "rep";
                break;
            case 'M':
                return "mam";
                break;
        }

    return {}; // Não retornou nada (falhou), retorne vazio
}

ostream& Animal::printOutDados(ostream& o, Animal* animal) const {
    int tamanhoColuna = 20;
    int espacamento = 3;
    int tamanhoTruncado = tamanhoColuna - 3 - espacamento;

    o  << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getNome().length() > tamanhoTruncado) ? (this->getNome().substr(0, tamanhoTruncado) + "...") : this->getNome())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getEspecie().length() > tamanhoTruncado) ? (this->getEspecie().substr(0, tamanhoTruncado) + "...") : this->getEspecie())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << ((this->getAmeacadoPor().length() > tamanhoTruncado) ? (this->getAmeacadoPor().substr(0, tamanhoTruncado) + "...") : this->getAmeacadoPor())
    << setfill(' ') << setw(tamanhoColuna + espacamento) << (this->getPerigoso()? "Sim" : "Não")
    << setfill(' ') << setw(tamanhoColuna + espacamento) << this->getClassificacao(animal)
    << setfill(' ') << setw(tamanhoColuna + espacamento) << this->getClasse(animal)
    << right << endl;

    return o;
}

bool Animal::operator==(const Animal& outro) const {
	return (this->nome == outro.getNome() &&
            this->especie == outro.getEspecie());
}
ostream& operator<< (ostream& o, Animal& animal) {
    return animal.printOutDados(o, &animal);
}