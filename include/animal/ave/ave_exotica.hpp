#pragma once

#include "ave.hpp"
#include "exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class AveExotica : public Ave, public Exotico {
    public:
        AveExotica(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local, bool voa);

        ~AveExotica();
};