#pragma once

#include "mamifero.hpp"
#include "nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class MamiferoNativo : public Mamifero, public Nativo {
    public:
        MamiferoNativo(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, string gestacao);

        ~MamiferoNativo();
};