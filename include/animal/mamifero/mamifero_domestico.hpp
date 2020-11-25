#pragma once

#include "mamifero.hpp"
#include "domestico.hpp"

#include <string>
#include <iostream>

using std::string;

class MamiferoDomestico : public Mamifero, public Domestico {
    public:
        MamiferoDomestico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado, bool gestacao);

        ~MamiferoDomestico();
};