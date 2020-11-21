#pragma once

#include <string>
#include <iostream>

using std::string;

class Pessoa {
    public:
        Pessoa(string nome, string telefone, string email);
        virtual ~Pessoa();

        string getNome() const;
        string getTelefone() const;
        string getEmail() const;

    protected:
        string nome;
        string telefone;
        string email;
};