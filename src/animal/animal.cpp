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
#include <vector>

using std::setfill;
using std::setw;
using std::right;
using std::vector;
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

void Animal::setNome(string s) {
    this->nome = s;
}

bool Animal::setNome() {
    string s;
    cout << endl << "Nome: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->nome = s;
    
    return true;
}

string Animal::getEspecie() const {
    return this->especie;
}

bool Animal::setEspecie() {
    string s;
    cout << endl << "Espécie: " << endl;
    getline(cin, s);
    
    if(s.size() == 0)
        return false;
    else
        this->especie = s;
    
    return true;
}

void Animal::setEspecie(string s) {
    this->especie = s;
}

string Animal::getAmeacadoPor() const {
    return this->ameacadoPor;
}

bool Animal::setAmeacadoPor() {
    string s;
    cout << endl << "Animal ameaçado de extinção por?: " << endl;
    getline(cin, s);
    
    if(s.size() == 0)
        return false;
    else
        this->ameacadoPor = s;
    
    return true;
}

void Animal::setAmeacadoPor(string s) {
    this->ameacadoPor = s;
}

Veterinario Animal::getVeterinario() const {
    return this->veterinario;
}

void Animal::setVeterinario(Veterinario vet) {
    this->veterinario = vet;
}

Tratador Animal::getTratador() const {
    return this->tratador;
}

void Animal::setTratador(Tratador trt) {
    this->tratador = trt;
}

bool Animal::getPerigoso() const {
    return this->perigoso;
}

bool Animal::setPerigoso() {
    string s;
    cout << endl << "É perigoso? (S/N): ";
    getline(cin, s);
    
    if(toupper(s[0]) == 'S')
        this->perigoso = true;
    else if(toupper(s[0]) == 'N')
        this->perigoso = false;
    else
        return false;

    return true;
}

void Animal::setPerigoso(bool b) {
    this->perigoso = b;
}

string Animal::getClassificacao(shared_ptr<Animal> animal) const {
    if(shared_ptr<Exotico> teste = dynamic_pointer_cast< Exotico >(animal)) {
        return "Silvestre Exótico";
    } if(shared_ptr<Nativo> teste = dynamic_pointer_cast< Nativo >(animal)) {
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
    // {} é mais rápido que "", já que não chama o construtor de std::string
}

string Animal::getClasse(shared_ptr<Animal> animal) const {
    if(shared_ptr<Ave> teste = dynamic_pointer_cast< Ave >(animal)) {
        return "Ave";
    } if(shared_ptr<Anfibio> teste = dynamic_pointer_cast< Anfibio >(animal)) {
        return "Anfíbio";
    } if(shared_ptr<Reptil> teste = dynamic_pointer_cast< Reptil >(animal)) {
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
    // {} é mais rápido que "", já que não chama o construtor de std::string
}

ostream& Animal::printOutDados(ostream& o, shared_ptr<Animal> animal) const {
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
ostream& operator<< (ostream& o, shared_ptr<Animal> animal) {
    return animal->printOutDados(o, animal);
}