#pragma once

#include "reptil.hpp"
#include "../exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class ReptilExotico : public Reptil, public Exotico {
    public:
        ReptilExotico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local, Pele pele);

        ~ReptilExotico();

        ostream& printOutDados(ostream& o) const;
};