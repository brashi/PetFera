#pragma once

#include "ave.hpp"
#include "../nativo.hpp"

#include <string>
#include <iostream>

using std::string;

class AveNativa : public Ave, public Nativo {
    public:
        AveNativa(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string regiao, bool voa);

        ~AveNativa();
};