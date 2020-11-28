#include "nativo.hpp"

using std::endl;
using std::cout;
using std::cin;

Nativo::Nativo(string regiao, string licenca):
                regiao(regiao), licenca(licenca){}

Nativo::~Nativo(){}

string Nativo::getLicenca() const {
    return this->licenca;
}

void Nativo::setLicenca(string s) {
    this->licenca = s;
}

bool Nativo::setLicenca() {
    string s;
    cout << endl << "Licença de transporte IBAMA: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->licenca = s;
    
    return true;
}

string Nativo::getRegiao() const {
    return this->regiao;
}

void Nativo::setRegiao(string s) {
    this->regiao = s;
}

bool Nativo::setRegiao() {
    string s;
    cout << endl << "Região do animal: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->regiao = s;
    
    return true;
}