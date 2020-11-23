#pragma once

#include "ave.hpp"
#include "domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class AveDomestica : public Ave, public Domestico {
    public:
        AveDomestica() {};
        AveDomestica(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado, bool voa);

        ~AveDomestica();
};