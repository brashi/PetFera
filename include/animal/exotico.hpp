#pragma once

#include "animal.hpp"

#include <string>
#include <iostream>

using std::string;

class Exotico : public Animal {
    public:
        Exotico(string nome, string especie, Veterinario veterinario,
                Tratador tratador, bool perigoso, string local);
        virtual ~Exotico();

        string getLocal() const;

    protected:
        string local;
};