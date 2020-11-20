#pragma once

#include "pessoa.hpp"

using std::string;

class Veterinario : public Pessoa {
    public:
        Veterinario(string nome, string telefone, string email,
                string CRMV);

        ~Veterinario();
        string getCRMV() const;

    private:
        string CRMV;

};