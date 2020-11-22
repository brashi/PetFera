#pragma once

#include <string>
#include <iostream>

using std::string; //Para declarar Strings.
using std::ostream; //Para os tipos de saida.
using std::endl;

class Pessoa {
    public:
        Pessoa() {};
        Pessoa(string nome, string telefone, string email);
        virtual ~Pessoa();

        string getNome() const;
        string getTelefone() const;
        string getEmail() const;
        //Método "Virtual Puro" determinando a classe.
        virtual ostream& printOutDados(ostream& o) const = 0;
        bool operator==(const Pessoa& outro) const;

        friend ostream& operator<< (ostream& o, Pessoa& pessoa);

    protected:
        string nome;
        string telefone;
        string email;
};