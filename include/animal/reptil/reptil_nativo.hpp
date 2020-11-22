#pragma once

#include "reptil.hpp"
#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class ReptilNativo : public Reptil, public Nativo {
    public:
        ReptilNativo(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, Pele pele);

        ~ReptilNativo();
};