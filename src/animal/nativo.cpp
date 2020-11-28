#include "nativo.hpp"

using std::cout;
using std::cin;

Nativo::Nativo(string regiao, string licenca):
                regiao(regiao), licenca(licenca){}

Nativo::~Nativo(){}

string Nativo::getLicenca() const {
    return this->licenca;
}

string Nativo::setLicenca() {
    string s;
    cout << endl << "Licença de transporte IBAMA: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        licenca = s;
    
    return true;
}

string Nativo::getRegiao() const {
    return this->regiao;
}

bool Nativo::setRegiao() {
    string s;
    cout << endl << "Região do animal: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        regiao = s;
    
    return true;
}