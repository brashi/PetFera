#pragma once

#include "anfibio.hpp"
#include "../exotico.hpp"

#include <string>
#include <iostream>

using std::string;

class AnfibioExotico : public Anfibio, public Exotico {
    public:
        AnfibioExotico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local, bool cauda, bool pata);

        ~AnfibioExotico();

        ostream& printOutDados(ostream& o) const;
};