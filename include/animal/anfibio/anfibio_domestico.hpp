#pragma once

#include "anfibio.hpp"
#include "domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class AnfibioDomestico : public Anfibio, public Domestico {
    public:
        AnfibioDomestico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado, bool cauda, bool pata);

        ~AnfibioDomestico();
};