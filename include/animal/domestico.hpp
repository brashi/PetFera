#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

class Domestico : public Animal {
    public:
        Domestico() {};
        Domestico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, bool adestrado);
        virtual ~Domestico();

        bool getAdestrado() const;
    protected:
        bool adestrado;
};