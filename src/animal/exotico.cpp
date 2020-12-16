#include "exotico.hpp"

using std::endl;
using std::cout;
using std::cin;

Exotico::Exotico(string local):
                local(local){}

Exotico::~Exotico(){}

string Exotico::getLocal() const {
    return this->local;
}

bool Exotico::setLocal() {
    string s;
    cout << endl << "Habitat do animal: " << endl;
    getline(cin, s);

    if(s.find(';') != std::string::npos)
        throw "O caractere (Ponto e vírgula) é proibido.";
    if(s.size() == 0)
        return false;
    else
        this->local = s;
    
    return true;
}

void Exotico::setLocal(string s) {
    this->local = s;
}