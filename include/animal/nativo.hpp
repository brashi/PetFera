#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

class Nativo : public Animal {
    public:
        Nativo(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao);
        virtual ~Nativo();

        string getRegiao() const;

    protected:
        string regiao;
};