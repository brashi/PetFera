#include "pessoa.hpp"

using std::cout;
using std::cin;

Pessoa::Pessoa(string nome, string telefone, string email):
                nome(nome), telefone(telefone),
                email(email){}

Pessoa::~Pessoa(){}

string Pessoa::getNome() const {
    return this->nome;
}

bool Pessoa::setNome() {
    string s;
    cout << endl << "Nome: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->nome = s;
    
    return true;
}

void Pessoa::setNome(string s) {
    this->nome = s;
}

string Pessoa::getTelefone() const {
    return this->telefone;
}

bool Pessoa::setTelefone() {
    string s;
    cout << endl << "Telefone: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->telefone = s;
    
    return true;
}

void Pessoa::setTelefone(string s) {
    this->telefone = s;
}

string Pessoa::getEmail() const {
    return this->email;
}

bool Pessoa::setEmail() {
    string s;
    cout << endl << "E-mail: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        this->email = s;
    
    return true;
}

void Pessoa::setEmail(string s) {
    this->email = s;
}

bool Pessoa::operator==(const Pessoa& outro) const {
	return ( this->nome == outro.getNome() );
}

ostream& operator<< (ostream& o, Pessoa& pessoa) {
    return pessoa.printOutDados(o);
}