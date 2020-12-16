#include "animal.hpp"

// Classes de animais
#include "ave.hpp"
#include "anfibio.hpp"
#include "reptil.hpp"
#include "mamifero.hpp"

// Classificacao
#include "exotico.hpp"
#include "nativo.hpp"
#include "domestico.hpp"

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

    if(s.find(';') != std::string::npos)
        throw "O caractere (Ponto e vírgula) é proibido.";
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
    
    if(s.find(';') != std::string::npos)
        throw "O caractere (Ponto e vírgula) é proibido.";
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
    
    if(s.find(';') != std::string::npos)
        throw "O caractere (Ponto e vírgula) é proibido.";
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

string Animal::getClassificacao(shared_ptr<Animal> animal, bool simplificado) {
    if(shared_ptr<Exotico> teste = dynamic_pointer_cast< Exotico >(animal)) {
        if(simplificado)
            return "E";
        else
            return "Silvestre Exótico";
    } if(shared_ptr<Nativo> teste = dynamic_pointer_cast< Nativo >(animal)) {
        if(simplificado)
            return "N";
        else
            return "Silvestre Nativo";
    } else {
        if(simplificado)
            return "D";
        else
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

string Animal::getClasse(shared_ptr<Animal> animal, bool simplificado) {
    if(shared_ptr<Ave> teste = dynamic_pointer_cast< Ave >(animal)) {
        if(simplificado)
            return "ave";
        else
            return "Ave";
    } if(shared_ptr<Anfibio> teste = dynamic_pointer_cast< Anfibio >(animal)) {
        if(simplificado)
            return "anf";
        else
            return "Anfíbio";
    } if(shared_ptr<Reptil> teste = dynamic_pointer_cast< Reptil >(animal)) {
        if(simplificado)
            return "rep";
        else
            return "Réptil";
    } else {
        if(simplificado)
            return "mam";
        else
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

void Animal::printOutDetails(shared_ptr<Animal> animal) {
    Veterinario vet = animal->getVeterinario();
    Tratador trt = animal->getTratador();
    string classe = Animal::getClasse(animal);
    string classificacao = Animal::getClassificacao(animal);

    cout << endl << "=-=-=-=-=- Visualização de animal -=-=-=-=-=-" << endl;
    cout << "Nome: " << animal->nome << endl;
    cout << "Espécie: " << animal->getEspecie() << endl;
    cout << "Perigoso: " << (animal->getPerigoso() ? "Sim" : "Não") << endl;
    cout << "Ameaçado por: " << animal->getAmeacadoPor() << endl;
    cout << "Veterinário: " << vet.getNome() << endl;
    cout << "  └ CRMV: " << vet.getCRMV() << endl;
    cout << "Tratador: " << trt.getNome() << endl;
    int un = trt.getUniforme();
    cout << "  └ N. Segurança: " << (un == 0? "Verde" : (un == 1 ? "Azul" : "Vermelho")) << endl;
    cout << "Categoria: " << classificacao << endl;
    if(classificacao == "Silvestre Exótico")
        cout << "  └ Habitat: " << dynamic_pointer_cast<Exotico>(animal)->getLocal() << endl;
    else if(classificacao == "Silvestre Nativo") {
        shared_ptr<Nativo> classificacao = dynamic_pointer_cast<Nativo>(animal);
        cout << "  ├ Lic. Transporte IBAMA: " << classificacao->getLicenca() << endl;
        cout << "  └ Região: " << classificacao->getRegiao() << endl;
    } else 
        cout << "  └ Adestrado: " << (dynamic_pointer_cast<Domestico>(animal)->getAdestrado() ? "Sim" : "Não") << endl;
    cout << "Classe: " << classe << endl;
    if(classe == "Ave")
        cout << "  └ Voa: " << (dynamic_pointer_cast<Ave>(animal)->getVoa() ? "Sim" : "Não") << endl;
    else if(classe == "Anfíbio") {
        shared_ptr<Anfibio> classe = dynamic_pointer_cast<Anfibio>(animal);
        cout << "  ├ Cauda: " << (classe->getCauda() ? "Sim" : "Não") << endl;
        cout << "  └ Pata: " << (classe->getPata() ? "Sim" : "Não") << endl;
    } else if(classe == "Réptil") {
        int pele = dynamic_pointer_cast<Reptil>(animal)->getPele();
        cout << "  └ Pele: " << (pele == 0? "Escama" : (pele == 1 ? "Placa" : "Carapaça")) << endl;
    } else
        cout << "  └ Gestação: " << (dynamic_pointer_cast<Mamifero>(animal)->getGestacao() ? "Sim" : "Não") << endl;
    cout << endl << "-=-=-=-=-=-=-=-=-=-= Fim =-=-=-=-=-=-=-=-=-=-" << endl << endl;
}

ostream& Animal::printOutDados(ostream& o, shared_ptr<Animal> animal) const {

    o  << right
    << setfill(' ') << setw(23) << ((this->nome.length() > 17) ? (this->nome.substr(0, 17) + "...") : this->nome)
    << setfill(' ') << setw(23) << ((this->especie.length() > 17) ? (this->especie.substr(0, 17) + "...") : this->especie)
    << setfill(' ') << setw(23) << ((this->ameacadoPor.length() > 17) ? (this->ameacadoPor.substr(0, 17) + "...") : this->ameacadoPor)
    << setfill(' ') << setw(23) << (this->perigoso? "Sim" : "Não")
    << endl;

    return o;
}

bool Animal::operator==(const shared_ptr<Animal> outro) const {
	return (this->nome == outro->getNome() &&
            this->especie == outro->getEspecie());
}
ostream& operator<< (ostream& o, shared_ptr<Animal> animal) {
    return animal->printOutDados(o, animal);
}