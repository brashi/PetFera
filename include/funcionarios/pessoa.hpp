#pragma once

#include <string>
#include <iostream>

using namespace std;

class Pessoa {
    public:
        Pessoa();
        Pessoa(string nome, string telefone, string email);
        virtual ~Pessoa();

        int getNome()   const;
        int getTelefone()   const;
        int getEmail()  const;

    protected:
        string nome;
        string telefone;
        string email;
};