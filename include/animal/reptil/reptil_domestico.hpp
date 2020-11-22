#pragma once

#include "reptil.hpp"
#include "../domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class ReptilDomestico : public Reptil, public Domestico {
    public:
        ReptilDomestico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado, Pele pele);

        ~ReptilDomestico();

        ostream& printOutDados(ostream& o) const;
};