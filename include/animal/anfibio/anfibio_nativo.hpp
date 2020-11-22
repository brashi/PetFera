#pragma once

#include "anfibio.hpp"
#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class AnfibioNativo : public Anfibio, public Nativo {
    public:
        AnfibioNativo(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, bool cauda, bool pata);

        ~AnfibioNativo();
};