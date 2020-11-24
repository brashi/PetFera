#pragma once

#include "mamifero.hpp"
#include "exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class MamiferoExotico : public Mamifero, public Exotico {
    public:
        MamiferoExotico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local, string gestacao);

        ~MamiferoExotico();
};